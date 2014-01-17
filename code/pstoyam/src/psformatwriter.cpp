#include "psformatwriter.h"

namespace yam{ namespace external{

YCPsFormatWriter::YCPsFormatWriter()
{
	//
}

YCPsFormatWriter::~YCPsFormatWriter()
{
	//
}

void YCPsFormatWriter::Do(FormatRecordPtr& rpRecord)
{
	m_ChannelProc = rpRecord;

	base::YCTree oTreeData;

	// preload
	{
		ystring sFilePathName = "";
		ysize iLen = 0;
		while (0x0000 != *(rpRecord->finalSpec + iLen))
		{
			sFilePathName += static_cast<char>(*(rpRecord->finalSpec + iLen));
			++iLen;
		}

		storage::YCFileReader oFileReader;
		oFileReader.Open(sFilePathName);
		base::YCBuffer buffer;
		oFileReader >> buffer;
		oFileReader.Close();
		oTreeData << buffer;
	}

	// keep other data
	base::YIFormat* pFormat = YNULL;
	{
		base::YITree* pTreePsFormat = oTreeData.FindChild("psformat");
		if (YNULL != pTreePsFormat && YOBJECT_GETCLASSNAME(base::YCFormat) == pTreePsFormat->GetClassName())
		{
			pFormat = (base::YIFormat*)pTreePsFormat;
		}
	}
	if (YNULL == pFormat)
	{
		pFormat = oTreeData.NewChild<base::YCFormat>();
		pFormat->GetId() = "psformat";
	}
	else
	{
		pFormat->Clear();
	}

	// parse the layer
	Do(rpRecord->documentInfo->layersDescriptor, rpRecord->documentInfo->bounds, pFormat);

	// prune invisible pixels bound
	pFormat->Refine();

	base::YCBuffer oBuffer;
	oBuffer.Begin();
	oTreeData >> oBuffer;
	oBuffer.End();

	int32 iSize = oBuffer.GetSize();
	/*int32 iSizeOfSize = sizeof(yint32);
	FSWrite(rpRecord->dataFork, &iSizeOfSize, &iSize);*/

	void* pBuffer = oBuffer.GetData();
	FSWrite(rpRecord->dataFork, &iSize, pBuffer);
}

void YCPsFormatWriter::Do(ReadLayerDesc*& rpLayerDesc, const VRect& rstBox, base::YIFormat*& rpFormatParent)
{
	if (NULL == rpLayerDesc)
	{
		return;
	}
	if (YPSBLENDMODE_LAYERGROUP == rpLayerDesc->blendMode)
	{
		ystring sLayerName = rpLayerDesc->name;
		if (0 >= sLayerName.size())
		{
			base::YIFormat* pFormat = new base::YCFormat;
			rpFormatParent->AddChild(pFormat);

			rpLayerDesc = rpLayerDesc->next;
			Do(rpLayerDesc, rstBox, pFormat);
		}
		else
		{
			rpFormatParent->GetId() = rpLayerDesc->name;

			rpLayerDesc = rpLayerDesc->next;
			Do(rpLayerDesc, rstBox, rpFormatParent);
		}
	}
	else
	{
		base::YIFormat* pFormat = new base::YCFormat;
		rpFormatParent->AddChild(pFormat);

		pFormat->GetId() = rpLayerDesc->name;

		YRect2D stBound = Convert(rstBox);
		ysize iSize = stBound.Size.X * stBound.Size.Y;
		ycolorptr pColorData = new ycolor[iSize];
		ycolor iColorDefault = 0x00000000;
		MemSet((ybuffptr)pColorData, sizeof(ycolor) * iSize, (ybuffptr)&iColorDefault, sizeof(ycolor));
		pFormat->SetBoundAndColorData(stBound, pColorData);
		if (YNULL != pColorData)
		{
			delete[] pColorData;
			pColorData = YNULL;
		}

		ReadChannelDesc* apChannelDesc[EColor_Max] = {NULL, NULL, NULL, NULL};
		ReadChannelDesc* pChannelDesc = rpLayerDesc->compositeChannelsList;
		while (NULL != pChannelDesc)
		{
			if (ctRed == pChannelDesc->channelType)
			{
				apChannelDesc[EColor_Red] = pChannelDesc;
			}
			else if (ctGreen == pChannelDesc->channelType)
			{
				apChannelDesc[EColor_Green] = pChannelDesc;
			}
			else if (ctBlue == pChannelDesc->channelType)
			{
				apChannelDesc[EColor_Blue] = pChannelDesc;
			}
			pChannelDesc = pChannelDesc->next;
		}
		apChannelDesc[EColor_Alpah] = rpLayerDesc->transparency;

		for (yint32 i = 0; i < EColor_Max; ++i)
		{
			Do(apChannelDesc[i], rstBox, pFormat, i * YBITCOUNT_INT8);
		}

		rpLayerDesc = rpLayerDesc->next;
		Do(rpLayerDesc, rstBox, rpFormatParent);
	}
}

void YCPsFormatWriter::Do(ReadChannelDesc*& rpChannelDesc, const VRect& rstBox, base::YIFormat*& rpFormat, const int32& riOffset)
{
	assert(YNULL != rpFormat);

	YRect2D stBound = rpFormat->GetBound();

	base::YCBuffer oPixelBuffer;
	m_ChannelProc.ReadPixel(rpChannelDesc, rstBox, oPixelBuffer);
	if (oPixelBuffer.GetSize() != (stBound.Size.X * stBound.Size.Y))
	{
		return;
	}

	const ycolorptr& rpColorData = rpFormat->GetColorData();
	const ybuffptr& rpColorElem = oPixelBuffer.GetData();
	for (yint32 i = 0; i < oPixelBuffer.GetSize(); ++i)
	{
		ycolor& riColorData = *(rpColorData + i);
		ybuff& rColorElem = *(rpColorElem + i);
		*((ybuff*)&riColorData + (riOffset / (sizeof(ybuff) * YBITCOUNT_INT8))) = rColorElem;
	}
}

YRect2D YCPsFormatWriter::Convert(const VRect& rstBox)
{
	YRect2D stBox;
	stBox.Pos.X = rstBox.left;
	stBox.Pos.Y = rstBox.top;
	stBox.Size.X = rstBox.right - rstBox.left;
	stBox.Size.Y = rstBox.bottom - rstBox.top;
	return stBox;
}

}}
