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
        base::YITree* pTreePsFormat = oTreeData.FindChild(YFILE_KEY_RESOURCE);
        if (YNULL != pTreePsFormat && YOBJECT_GETCLASSNAME(base::YCFormat) == pTreePsFormat->GetClassName())
        {
            pFormat = (base::YIFormat*)pTreePsFormat;
        }
    }
    if (YNULL == pFormat)
    {
        pFormat = oTreeData.NewChild<base::YCFormat>();
        pFormat->GetId() = YFILE_KEY_RESOURCE;
    }
    else
    {
        pFormat->Clear();
    }

    // parse the layer
    Do(rpRecord->documentInfo->layersDescriptor, pFormat);

    base::YCBuffer oBuffer;
    oBuffer.Begin();
    oTreeData >> oBuffer;
    oBuffer.End();

    int32 iSize = oBuffer.GetSize();
    void* pBuffer = oBuffer.GetData();
    FSWrite(rpRecord->dataFork, &iSize, pBuffer);
}

void YCPsFormatWriter::Do(const ReadLayerDesc* const& rpLayerDesc, base::YIFormat* pFormatParent)
{
    if (NULL == rpLayerDesc || NULL == rpLayerDesc->transparency || NULL == pFormatParent)
    {
        return;
    }
    VRect stBox = rpLayerDesc->transparency->limitBounds;
    if (FALSE == rpLayerDesc->isPixelBased)
    //if (YPSBLENDMODE_LAYERGROUP == rpLayerDesc->blendMode)
    {
        ystring sLayerName = rpLayerDesc->name;
        if (0 >= sLayerName.size())
        {
            base::YIFormat* pFormat = new base::YCFormat;
            pFormatParent->AddChild(pFormat);

            Do(rpLayerDesc->next, pFormat);
        }
        else
        {
            pFormatParent->GetId() = rpLayerDesc->name;

            base::YITree* pTreeParent = pFormatParent->GetParent();
            if (YNULL != pTreeParent && YOBJECT_GETCLASSNAME(base::YCFormat) == pTreeParent->GetClassName())
            {
                Do(rpLayerDesc->next, (base::YIFormat*)pTreeParent);
            }
            else
            {
                Do(rpLayerDesc->next, pFormatParent);
            }
        }
    }
    else
    {
        base::YIFormat* pFormat = new base::YCFormat;
        pFormatParent->AddChild(pFormat);

        pFormat->GetId() = rpLayerDesc->name;

        YRect2D stBound = Convert(stBox);
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

        ReadChannelDesc* apChannelDesc[eColorChannel_Max] = {NULL, NULL, NULL, NULL};
        ReadChannelDesc* pChannelDesc = rpLayerDesc->compositeChannelsList;
        while (NULL != pChannelDesc)
        {
            if (ctRed == pChannelDesc->channelType)
            {
                apChannelDesc[eColorChannel_Red] = pChannelDesc;
            }
            else if (ctGreen == pChannelDesc->channelType)
            {
                apChannelDesc[eColorChannel_Green] = pChannelDesc;
            }
            else if (ctBlue == pChannelDesc->channelType)
            {
                apChannelDesc[eColorChannel_Blue] = pChannelDesc;
            }
            pChannelDesc = pChannelDesc->next;
        }
        apChannelDesc[eColorChannel_Alpah] = rpLayerDesc->transparency;

        for (yint32 i = 0; i < eColorChannel_Max; ++i)
        {
            if (eColorChannel_Red == i)
            {
                Do(apChannelDesc[i], stBox, pFormat, YBITOFFSET_RED);
            }
            else if (eColorChannel_Green == i)
            {
                Do(apChannelDesc[i], stBox, pFormat, YBITOFFSET_GREEN);
            }
            else if (eColorChannel_Blue == i)
            {
                Do(apChannelDesc[i], stBox, pFormat, YBITOFFSET_BLUE);
            }
            else if (eColorChannel_Alpah == i)
            {
                Do(apChannelDesc[i], stBox, pFormat, YBITOFFSET_ALPHA);
            }
        }

        Do(rpLayerDesc->next, pFormatParent);
    }
}

void YCPsFormatWriter::Do(const ReadChannelDesc* const& rpChannelDesc, const VRect& rstBox, base::YIFormat*& rpFormat, const yuint32& riOffset)
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
        YSETCOLORBIT(riColorData, rColorElem, riOffset);
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
