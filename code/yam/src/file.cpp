#include "file.h"

#include "widget.h"
#include "panel.h"
#include "format.h"

namespace yam{ namespace file{

SINGLETON_IMPL(CYFile);

CYFile::CYFile()
{
	//
}

CYFile::~CYFile()
{
	//
}

void CYFile::Load(const ystring& rsFileName, base::IYWidget*& rpWidget) const
{
	assert(YNULL == rpWidget);

	yifstream fsFile;
	fsFile.open(rsFileName.c_str(), std::ios::in | std::ios::binary);

	while (!fsFile.eof())
	{
		ystring sKeyOfData = "";
		ybuffsize iSizeOfData = 0;
		ybuffptr pBufferOfData = YNULL;

		Read(fsFile, sKeyOfData);

		if (sKeyOfData == FILE_KEY_WIDGET)
		{
			Read(fsFile, iSizeOfData);
			Read(fsFile, rpWidget);
		}
		else
		{
			Read(fsFile, iSizeOfData);
			if (0 < iSizeOfData)
			{
				Read(fsFile, iSizeOfData, pBufferOfData);
			}
		}
	}
	fsFile.close();
}

void CYFile::Save(const ystring& rsFileName, const base::IYWidget* pWidget) const
{
	assert(YNULL != pWidget);

	// read the format data
	ybuffsize iSizeOfFormatData = 0;
	ybuffptr pBufferOfFormatData = YNULL;
	{
		yifstream fsReadFile;
		fsReadFile.open(rsFileName.c_str(), std::ios::in | std::ios::binary);
		if (!fsReadFile.eof())
		{
			ystring sFormatKey = "";
			Read(fsReadFile, sFormatKey);
			Read(fsReadFile, iSizeOfFormatData);
			if (0 < iSizeOfFormatData)
			{
				pBufferOfFormatData = new ybuff[iSizeOfFormatData];
				Read(fsReadFile, iSizeOfFormatData, pBufferOfFormatData);
			}
		}
		fsReadFile.close();
	}

	yofstream fsFile;
	fsFile.open(rsFileName.c_str(), std::ios::out | std::ios::binary);

	// rewrite the format data
	{
		ystring sKey = FILE_KEY_FORMAT;
		Write(fsFile, sKey);
		Write(fsFile, iSizeOfFormatData);
		if (YNULL != pBufferOfFormatData)
		{
			Write(fsFile, iSizeOfFormatData, pBufferOfFormatData);
			delete pBufferOfFormatData; pBufferOfFormatData = YNULL;
		}
	}

	{
		// write the widget data
		ystring sKey = FILE_KEY_WIDGET;
		Write(fsFile, sKey);
		ybuffsize iSize = pWidget->SizeOfData();
		Write(fsFile, iSize);
		Write(fsFile, pWidget);
	}
	fsFile.close();
}

void CYFile::Read(yifstream& rStream, const ybuffsize& rSize, ybuffptr pBuffer) const
{
	assert(YNULL != pBuffer);
	if (rStream.eof())
	{
		return;
	}
	rStream.read(pBuffer, rSize);
}

void CYFile::Write(yofstream& rStream, const ybuffsize& rSize, const ybuffptr& rpBuffer) const
{
	assert(YNULL != rpBuffer);
	rStream.write(rpBuffer, rSize);
}

void CYFile::Read(yifstream& rStream, ystring& rRes) const
{
	if (rStream.eof())
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

void CYFile::Write(yofstream& rStream, const ystring& rData) const
{
	yint32 iLen = rData.size();
	Write(rStream, sizeof(yint32), (ybuffptr)&iLen);
	Write(rStream, sizeof(yint8) * iLen, (ybuffptr)rData.c_str());
}

void CYFile::Read(yifstream& rStream, ybool& rRes) const
{
	Read(rStream, sizeof(ybool), (ybuffptr)&rRes);
}

void CYFile::Write(yofstream& rStream, const ybool& rData) const
{
	Write(rStream, sizeof(ybool), (ybuffptr)&rData);
}

void CYFile::Read(yifstream& rStream, yint32& rRes) const
{
	Read(rStream, sizeof(yint32), (ybuffptr)&rRes);
}

void CYFile::Write(yofstream& rStream, const yint32& rData) const
{
	Write(rStream, sizeof(yint32), (ybuffptr)&rData);
}

void CYFile::Read(yifstream& rStream, yvec2d& rRes) const
{
	Read(rStream, sizeof(yvec2d), (ybuffptr)&rRes);
}

void CYFile::Write(yofstream& rStream, const yvec2d& rData) const
{
	Write(rStream, sizeof(yvec2d), (ybuffptr)&rData);
}

void CYFile::Read(yifstream& rStream, yrect2d& rRes) const
{
	Read(rStream, sizeof(yrect2d), (ybuffptr)&rRes);
}

void CYFile::Write(yofstream& rStream, const yrect2d& rData) const
{
	Write(rStream, sizeof(yrect2d), (ybuffptr)&rData);
}

void CYFile::Read(yifstream& rStream, base::IYWidget*& rpData) const
{
	assert(YNULL == rpData);

	ystring sType = "";
	Read(rStream, sType);
	rpData = NewWidget(sType);

	ystring sId = "";
	Read(rStream, sId);
	rpData->GetId() = sId;

	yrect2d stBound;
	Read(rStream, stBound);
	rpData->GetBound() = stBound;

	ylayerweight iLayerWeight = 0;
	Read(rStream, iLayerWeight);
	rpData->GetLayerWeight() = iLayerWeight;

	ybool bHasNext = false;
	Read(rStream, bHasNext);
	if (bHasNext)
	{
		base::IYWidget* pNext = YNULL;
		Read(rStream, pNext);
		rpData->AddNext(pNext);
	}

	ybool bHasChildren = false;
	Read(rStream, bHasChildren);
	if (bHasChildren)
	{
		base::IYWidget* pChildren = YNULL;
		Read(rStream, pChildren);
		rpData->AddChild(pChildren);
	}
}

void CYFile::Write(yofstream& rStream, const base::IYWidget*& rpData) const
{
	assert(YNULL != rpData);

	Write(rStream, rpData->GetType());
	Write(rStream, rpData->GetId());
	Write(rStream, rpData->GetBound());
	Write(rStream, rpData->GetLayerWeight());

	// write the next
	const base::IYWidget* pNext = rpData->GetNext();
	ybool bHasNext = YNULL != pNext;
	Write(rStream, bHasNext);
	if (bHasNext)
	{
		Write(rStream, pNext);
	}

	// write the children
	const base::IYWidget* pChildren = rpData->GetChildren();
	ybool bHasChildren = YNULL != pChildren;
	Write(rStream, bHasChildren);
	if (bHasChildren)
	{
		Write(rStream, pChildren);
	}
}

void CYFile::Read(yifstream& rStream, base::IYFormat*& rpData) const
{
	//
}

void CYFile::Write(yofstream& rStream, const base::IYFormat*& rpData) const
{
	//
}

base::IYWidget* CYFile::NewWidget(const ystring& rsType) const
{
	if (FILEKEY_GET(base::CYPanel) == rsType)
	{
		return new base::CYPanel;
	}
	else if (FILEKEY_GET(base::CYWidget) == rsType)
	{
		return new base::CYWidget;
	}
	return YNULL;
}

}}
