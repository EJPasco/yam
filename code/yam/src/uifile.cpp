#include "uifile.h"

#include "buffer.h"

namespace yam{ namespace file{

YCUIFileWriter::YCUIFileWriter()
	: mbOpened(false)
{
	//
}

YCUIFileWriter::~YCUIFileWriter()
{
	Close();
}

void YCUIFileWriter::Close()
{
	if (!mbOpened)
	{
		return;
	}
	mFileStream.close();
	mbOpened = false;
}

YIUIFileWriter& YCUIFileWriter::Save(const ystring& rsFileName)
{
	Close();

	mFileStream.open(rsFileName, std::ios::out | std::ios::binary);
	mbOpened = true;
	return *this;
}

YIUIFileWriter& YCUIFileWriter::operator<<(const ystring& rData)
{
	yint32 iLen = rData.size();
	*this << iLen;
	Write(iLen, (ybuffptr)rData.c_str());
	return *this;
}

YIUIFileWriter& YCUIFileWriter::operator<<(const base::YIBuffer* const& rpBuffer)
{
	assert(YNULL != rpBuffer);
	if (!mbOpened)
	{
		return *this;
	}
	*this << rpBuffer->GetId();
	*this << rpBuffer->GetSize();
	Write(rpBuffer->GetSize(), rpBuffer->GetData());

	const base::YITree<base::YIBuffer>* pTree = rpBuffer;
	*this << pTree;
	return *this;
}

void YCUIFileWriter::Write(const ybuffsize& riSize, const ybuffptr& rpBuff)
{
	if (!mbOpened || 0 >= riSize || YNULL == rpBuff)
	{
		return;
	}
	mFileStream.write(rpBuff, riSize);
}

YCUIFileReader::YCUIFileReader()
	: mbOpened(false)
{
	//
}

YCUIFileReader::~YCUIFileReader()
{
	Close();
}

void YCUIFileReader::Close()
{
	if (!mbOpened)
	{
		return;
	}
	mFileStream.close();
	mbOpened = false;
}

YIUIFileReader& YCUIFileReader::Open(const ystring& rsFileName)
{
	Close();

	mFileStream.open(rsFileName, std::ios::in | std::ios::binary);
	mbOpened = true;
	return *this;
}

YIUIFileReader& YCUIFileReader::operator>>(ystring& rData)
{
	if (!mbOpened)
	{
		return *this;
	}

	yint32 iLen = 0;
	*this >> iLen;
	ybuffptr pBuff = new ybuff[iLen + 1];
	Read(iLen, pBuff);
	pBuff[iLen] = '\0';
	rData.append(pBuff);
	delete pBuff; pBuff = YNULL;
	return *this;
}

YIUIFileReader& YCUIFileReader::operator>>(base::YIBuffer*& rpBuffer)
{
	assert(YNULL == rpBuffer);
	if (!mbOpened)
	{
		return *this;
	}

	rpBuffer = new base::YCBuffer;
	*this >> rpBuffer->GetId();
	ybuffsize iSize = 0;
	*this >> iSize;
	rpBuffer->New(iSize);
	Read(rpBuffer->GetSize(), rpBuffer->GetData());

	base::YITree<base::YIBuffer>* pTree = rpBuffer;
	*this >> pTree;
	return *this;
}

void YCUIFileReader::Read(const ybuffsize& riSize, const ybuffptr& rpBuff)
{
	if (!mbOpened || 0 >= riSize || YNULL == rpBuff)
	{
		return;
	}
	mFileStream.read(rpBuff, riSize);
}

}}
