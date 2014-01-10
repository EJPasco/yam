#include "buffer.h"

namespace yam{ namespace base{

YOBJECT_IMPL(YCBuffer);

YCBuffer::YCBuffer()
	: m_iPosCurrent(0)
{
	//
}

YCBuffer::~YCBuffer()
{
	Merge();

	m_iSize = 0;
	if (YNULL != m_pData)
	{
		delete[] m_pData;
		m_pData = YNULL;
	}
}

YIBuffer& YCBuffer::operator<<(const ystring& rData)
{
	yint32 iLen = rData.size();
	Write(sizeof(yint32), (ybuffptr)&iLen);
	Write(sizeof(char) * iLen, (ybuffptr)rData.c_str());
	return *this;
}

YIBuffer& YCBuffer::operator>>(ystring& rData)
{
	rData.clear();

	yint32 iLen = 0;
	Read(sizeof(yint32), (ybuffptr)&iLen);
	ybuffptr pData = new ybuff[iLen + 1];
	Read(sizeof(char) * iLen, pData);
	pData[iLen] = '\0';
	rData.append(pData);
	delete[] pData; pData = YNULL;
	return *this;
}

bool YCBuffer::operator>>(base::YCBuffer& rBuffer) const
{
	assert(&rBuffer != this);
	rBuffer << (const YIBuffer*)this;
	return true;
}

bool YCBuffer::operator<<(base::YCBuffer& rBuffer)
{
	assert(&rBuffer != this);
	rBuffer.Begin();

	ystring sId = "";
	ystring sClass = "";
	ybuffsize iBufferSize = 0;
	rBuffer.ReadHead(sId, sClass, iBufferSize);
	if (YOBJECT_GETCLASSNAME(YCBuffer) != sClass)
	{
		return false;
	}

	GetId() = sId;

	this->New(iBufferSize);
	rBuffer.Read(iBufferSize, GetData());
	return true;
}

GET_FUNC_CONST_CUSTOM(ybuffptr&, YCBuffer::GetData)
{
	assert(0 >= m_vBufferSeg.size());
	return m_pData;
}

void YCBuffer::New(const ybuffsize& riSize)
{
	if (YNULL != m_pData)
	{
		delete[] m_pData;
		m_pData = YNULL;
	}

	m_iSize = riSize;
	if (0 < m_iSize)
	{
		m_pData = new ybuff[m_iSize];
	}
}

YIBuffer& YCBuffer::Begin()
{
	m_iPosCurrent = 0;
	return *this;
}

YIBuffer& YCBuffer::Jump(const ybuffpos& riOffset)
{
	m_iPosCurrent += riOffset;
	return *this;
}

void YCBuffer::End()
{
	Merge();
}

bool YCBuffer::Write(const ybuffsize& riSize, const ybuffptr& rpSrc)
{
	YBuffer stBuffer;
	stBuffer.Size = riSize;
	if (0 < stBuffer.Size)
	{
		stBuffer.Data = new ybuff[stBuffer.Size];
		::memcpy(stBuffer.Data, rpSrc, sizeof(ybuff) * stBuffer.Size);
	}
	m_vBufferSeg.push_back(stBuffer);
	return true;
}

bool YCBuffer::Read(const ybuffsize& riSize, const ybuffptr& rpDst)
{
	assert(YNULL != rpDst);
	if (0 >= m_iSize || m_iSize < (m_iPosCurrent + riSize))
	{
		return false;
	}
	::memcpy(rpDst, m_pData + m_iPosCurrent, riSize);
	m_iPosCurrent += riSize;
	return true;
}

bool YCBuffer::WriteHead(const ystring& rsId, const ystring& rsClass, const ybuffsize& riSize)
{
	Begin();
	*this << rsId;
	*this << rsClass;
	*this << riSize;
	End();
	return true;
}

bool YCBuffer::ReadHead(ystring& rsId, ystring& rsClass, ybuffsize& riSize)
{
	*this >> rsId;
	*this >> rsClass;
	*this >> riSize;
	return true;
}

YIBuffer& YCBuffer::Clear()
{
	m_iSize = 0;
	if (YNULL != m_pData)
	{
		delete[] m_pData;
		m_pData = YNULL;
	}
	m_iPosCurrent = 0;
	return *this;
}

void YCBuffer::Merge()
{
	if (0 >= m_vBufferSeg.size())
	{
		return;
	}

	ybuffsize iSize = m_iSize;
	ybuffptr pData = YNULL;
	{
		yvbuffer::iterator itBuffer = m_vBufferSeg.begin();
		yvbuffer::iterator itBufferEnd = m_vBufferSeg.end();
		for (; itBuffer != itBufferEnd; ++itBuffer)
		{
			iSize += itBuffer->Size;
		}
	}

	if (0 >= iSize || iSize == m_iSize)
	{
		return;
	}

	ybuffpos iPos = 0;
	pData = new ybuff[iSize];

	if (0 < m_iSize)
	{
		::memcpy((void*)(pData + iPos), m_pData, m_iSize);
		iPos += m_iSize;
	}

	{
		yvbuffer::iterator itBuffer = m_vBufferSeg.begin();
		yvbuffer::iterator itBufferEnd = m_vBufferSeg.end();
		for (; itBuffer != itBufferEnd; ++itBuffer)
		{
			if (0 >= itBuffer->Size)
			{
				continue;
			}
			::memcpy((void*)(pData + iPos), itBuffer->Data, itBuffer->Size);
			iPos += itBuffer->Size;
			delete[] itBuffer->Data;
		}
		m_vBufferSeg.clear();
	}

	m_iSize = iSize;
	if (YNULL != m_pData)
	{
		delete[] m_pData;
	}
	m_pData = pData;
}

YIBuffer& YCBuffer::operator<<(const YIBuffer* const& rpData)
{
	assert(YNULL != rpData);
	assert(rpData != this);

	WriteHead(rpData->GetId(), rpData->GetClassName(), rpData->GetSize());
	Write(rpData->GetSize(), rpData->GetData());

	const base::YITree<YIBuffer>* const& rpTree = rpData;
	operator<<<YIBuffer, YCBuffer>(rpTree);
	return *this;
}

YIBuffer& YCBuffer::operator>>(YIBuffer*& rpData)
{
	assert(YNULL == rpData);
	assert(rpData != this);

	ystring sId = "";
	ystring sClass = "";
	ybuffsize iSize = 0;
	ReadHead(sId, sClass, iSize);

	rpData = new YCBuffer;
	rpData->GetId() = sId;
	rpData->GetClassName() = sClass;
	if (0 < iSize)
	{
		ybuffptr pData = new ybuff[iSize];
		Read(iSize, pData);
		rpData->Write(iSize, pData);
		delete pData; pData = YNULL;
	}

	base::YITree<YIBuffer>* pTree = rpData;
	operator>><YIBuffer, YCBuffer>(pTree);
	return *this;
}

}}
