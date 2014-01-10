#include "file.h"

#include "buffer.h"
#include "format.h"
#include "widget.h"
#include "panel.h"

namespace yam{ namespace file{

SINGLETON_IMPL(YCFile);

YCFile::YCFile()
{
	//
}

YCFile::~YCFile()
{
	//
}

void YCFile::Load(const ystring& rsFileName, base::YIFormat*& rpFormat) const
{
	assert(YNULL == rpFormat);

	tmbuffer vBuffer;

	{
		yifstream fsFile;
		fsFile.open(rsFileName.c_str(), std::ios::in | std::ios::binary);
		ReadMapPtr(fsFile, vBuffer);
		fsFile.close();
	}

	tmbuffer::const_iterator citBuffer = vBuffer.begin();
	tmbuffer::const_iterator citBufferEnd = vBuffer.end();
	for (; citBuffer != citBufferEnd; ++citBuffer)
	{
		if (FILE_KEY_FORMAT != citBuffer->first)
		{
			continue;
		}
		std::stringstream ss;
		ss.write(citBuffer->second->GetData(), citBuffer->second->GetSize());
		yistream buffer_stream(ss.rdbuf());
		Read(buffer_stream, rpFormat);
		break;
	}
	DeleteMapPtr(vBuffer);
}

void YCFile::Save(const ystring& rsFileName, const base::YIFormat* pFormat) const
{
	assert(YNULL != pFormat);

	tmbuffer vBuffer;

	{
		yifstream fsFile;
		fsFile.open(rsFileName.c_str(), std::ios::in | std::ios::binary);
		ReadMapPtr(fsFile, vBuffer);
		fsFile.close();
	}

	yofstream fsFile;
	fsFile.open(rsFileName.c_str(), std::ios::out | std::ios::binary);

	const ystring sKey = FILE_KEY_FORMAT;
	Write(fsFile, sKey);
	//Write(fsFile, pFormat->SizeOfData());
	Write(fsFile, pFormat);

	tmbuffer::const_iterator citBuffer = vBuffer.begin();
	tmbuffer::const_iterator citBufferEnd = vBuffer.end();
	for (; citBuffer != citBufferEnd; ++citBuffer)
	{
		if (sKey == citBuffer->first)
		{
			continue;
		}
		Write(fsFile, citBuffer->first);
		const base::YIBuffer* pBuffer = citBuffer->second;
		Write(fsFile, pBuffer);
	}
	DeleteMapPtr(vBuffer);

	fsFile.close();
}

void YCFile::Load(const ystring& rsFileName, base::YIWidget*& rpWidget) const
{
	assert(YNULL == rpWidget);

	tmbuffer vBuffer;

	{
		yifstream fsFile;
		fsFile.open(rsFileName.c_str(), std::ios::in | std::ios::binary);
		ReadMapPtr(fsFile, vBuffer);
		fsFile.close();
	}

	tmbuffer::const_iterator citBuffer = vBuffer.begin();
	tmbuffer::const_iterator citBufferEnd = vBuffer.end();
	for (; citBuffer != citBufferEnd; ++citBuffer)
	{
		if (FILE_KEY_WIDGET != citBuffer->first)
		{
			continue;
		}
		std::stringstream ss;
		ss.write(citBuffer->second->GetData(), citBuffer->second->GetSize());
		yistream buffer_stream(ss.rdbuf());
		Read(buffer_stream, rpWidget);
		break;
	}
	DeleteMapPtr(vBuffer);
}

void YCFile::Save(const ystring& rsFileName, const base::YIWidget* pWidget) const
{
	assert(YNULL != pWidget);

	tmbuffer vBuffer;

	{
		yifstream fsFile;
		fsFile.open(rsFileName.c_str(), std::ios::in | std::ios::binary);
		ReadMapPtr(fsFile, vBuffer);
		fsFile.close();
	}

	yofstream fsFile;
	fsFile.open(rsFileName.c_str(), std::ios::out | std::ios::binary);

	const ystring sKey = FILE_KEY_WIDGET;
	Write(fsFile, sKey);

	{
		std::stringstream ss;
		yostream iost(ss.rdbuf());
		Write(iost, pWidget);
		Write(fsFile, iost);
	}

	tmbuffer::const_iterator citBuffer = vBuffer.begin();
	tmbuffer::const_iterator citBufferEnd = vBuffer.end();
	for (; citBuffer != citBufferEnd; ++citBuffer)
	{
		if (sKey == citBuffer->first)
		{
			continue;
		}
		Write(fsFile, citBuffer->first);
		const base::YIBuffer* pBuffer = citBuffer->second;
		Write(fsFile, pBuffer);
	}
	DeleteMapPtr(vBuffer);

	fsFile.close();
}

void YCFile::Read(yistream& rStream, const ybuffsize& rSize, ybuffptr pBuffer) const
{
	assert(YNULL != pBuffer);
	if (!rStream.good() || rStream.eof())
	{
		return;
	}
	if (0 >= rSize)
	{
		return;
	}
	rStream.read(pBuffer, rSize);
}

void YCFile::Write(yostream& rStream, const ybuffsize& rSize, const ybuffptr& rpBuffer) const
{
	assert(YNULL != rpBuffer);
	if (0 >= rSize)
	{
		return;
	}
	rStream.write(rpBuffer, rSize);
}

void YCFile::Read(yistream& rStream, ystreambuff& rData) const
{
	rStream >> &rData;
}

void YCFile::Write(yostream& rStream, const ystreambuff& rData) const
{
	//rData.pubseekpos(0, std::ios::end);
	rStream << &rData;
}

void YCFile::Read(yistream& rStream, yistream& rData) const
{
	Read(rStream, *rData.rdbuf());
}

void YCFile::Write(yostream& rStream, const yostream& rData) const
{
	Write(rStream, *rData.rdbuf());
}

void YCFile::Read(yistream& rStream, ystring& rRes) const
{
	if (!rStream.good() || rStream.eof())
	{
		return;
	}
	rRes.clear();

	yint32 iLen = 0;
	Read(rStream, iLen);
	yint8* pBuffer = new yint8[iLen + 1];
	Read(rStream, sizeof(yint8) * iLen, pBuffer);
	pBuffer[iLen] = '\0';
	rRes.append(pBuffer);
	delete[] pBuffer; pBuffer = YNULL;
}

void YCFile::Write(yostream& rStream, const ystring& rData) const
{
	yint32 iLen = rData.size();
	Write(rStream, sizeof(yint32), (ybuffptr)&iLen);
	Write(rStream, sizeof(ybuff) * iLen, (ybuffptr)rData.c_str());
}

void YCFile::Read(yistream& rStream, ybool& rRes) const
{
	Read(rStream, sizeof(ybool), (ybuffptr)&rRes);
}

void YCFile::Write(yostream& rStream, const ybool& rData) const
{
	Write(rStream, sizeof(ybool), (ybuffptr)&rData);
}

void YCFile::Read(yistream& rStream, yint32& rRes) const
{
	Read(rStream, sizeof(yint32), (ybuffptr)&rRes);
}

void YCFile::Write(yostream& rStream, const yint32& rData) const
{
	Write(rStream, sizeof(yint32), (ybuffptr)&rData);
}

void YCFile::Read(yistream& rStream, YVec2D& rRes) const
{
	Read(rStream, sizeof(YVec2D), (ybuffptr)&rRes);
}

void YCFile::Write(yostream& rStream, const YVec2D& rData) const
{
	Write(rStream, sizeof(YVec2D), (ybuffptr)&rData);
}

void YCFile::Read(yistream& rStream, YRect2D& rRes) const
{
	Read(rStream, sizeof(YRect2D), (ybuffptr)&rRes);
}

void YCFile::Write(yostream& rStream, const YRect2D& rData) const
{
	Write(rStream, sizeof(YRect2D), (ybuffptr)&rData);
}

void YCFile::Read(yistream& rStream, base::YIBuffer*& rpData) const
{
	assert(YNULL == rpData);

	New(rpData);

	ybuffsize iSize = 0;
	Read(rStream, iSize);
	rpData->New(iSize);
	if (0 >= iSize)
	{
		return;
	}
	Read(rStream, rpData->GetSize(), rpData->GetData());
}

void YCFile::Write(yostream& rStream, const base::YIBuffer*& rpData) const
{
	assert(YNULL != rpData);

	ybuffsize iSize = rpData->GetSize();
	Write(rStream, iSize);
	if (0 >= iSize)
	{
		return;
	}
	Write(rStream, rpData->GetSize(), rpData->GetData());
}

void YCFile::Read(yistream& rStream, base::YIFormat*& rpData) const
{
	assert(YNULL == rpData);

	New(rpData);

	ystring sId = "";
	Read(rStream, sId);
	rpData->GetId() = sId;

	YRect2D stBound;
	ycolorptr pColorData = YNULL;
	Read(rStream, stBound);

	ybool bHasColorData = false;
	Read(rStream, bHasColorData);
	if (bHasColorData)
	{
		pColorData = new ycolor[stBound.Size.X * stBound.Size.Y];
		Read(rStream, sizeof(ycolor) * stBound.Size.X * stBound.Size.Y, (ybuffptr)pColorData);
	}
	rpData->SetBoundAndColorData(stBound, pColorData);

	ReadTree(rStream, rpData);
}

void YCFile::Write(yostream& rStream, const base::YIFormat*& rpData) const
{
	assert(YNULL != rpData);

	Write(rStream, rpData->GetId());
	Write(rStream, rpData->GetBound());
	ybool bHasColorData = YNULL != rpData->GetColorData();
	Write(rStream, bHasColorData);
	if (bHasColorData)
	{
		Write(rStream, sizeof(ycolor) * rpData->GetBound().Size.X * rpData->GetBound().Size.Y, (ybuffptr)rpData->GetColorData());
	}

	WriteTree(rStream, rpData);
}

void YCFile::Read(yistream& rStream, base::YIWidget*& rpData) const
{
	assert(YNULL == rpData);

	ystring sType = "";
	Read(rStream, sType);
	New(rpData, sType);

	ystring sId = "";
	Read(rStream, sId);
	rpData->GetId() = sId;

	YRect2D stBound;
	Read(rStream, stBound);
	rpData->GetBound() = stBound;

	ylayerweight iLayerWeight = 0;
	Read(rStream, iLayerWeight);
	rpData->GetLayerWeight() = iLayerWeight;

	ReadTree(rStream, rpData);
}

void YCFile::Write(yostream& rStream, const base::YIWidget*& rpData) const
{
	assert(YNULL != rpData);

	Write(rStream, rpData->GetClassName());
	Write(rStream, rpData->GetId());
	Write(rStream, rpData->GetBound());
	Write(rStream, rpData->GetLayerWeight());

	WriteTree(rStream, rpData);
}

void YCFile::New(base::YIBuffer*& rpNew) const
{
	rpNew = new base::YCBuffer;
}

void YCFile::Delete(base::YIBuffer*& rpDelete) const
{
	if (YNULL == rpDelete)
	{
		return;
	}
	delete rpDelete;
	rpDelete = YNULL;
}

void YCFile::New(base::YIFormat*& rpNew) const
{
	rpNew = new base::YCFormat;
}

void YCFile::New(base::YIWidget*& rpNew, const ystring& rsClass) const
{
	if (YOBJECT_GETCLASSNAME(base::YCPanel) == rsClass)
	{
		rpNew = new base::YCPanel;
	}
	else if (YOBJECT_GETCLASSNAME(base::YCWidget) == rsClass)
	{
		rpNew = new base::YCWidget;
	}
}

}}
