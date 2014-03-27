// The MIT License (MIT) Copyright (c) 2014 Code 4 Game
/*!
  \file pstoyam.cpp
  \author Alex Chi
  \brief implement some apis for ps plugin

 */
#include "pstoyam.h"

DLLExport MACPASCAL void PluginMain (const int16 iSelector,
                                     FormatRecordPtr pRecord,
                                     intptr_t* ppData,
                                     int16* pResult)
{
    if (NULL == pRecord)
    {
        return;
    }

    switch (iSelector)
    {
    case formatSelectorAbout:
        break;

    case formatSelectorEstimatePrepare:
        //pRecord->maxData = 0;
        break;

    case formatSelectorEstimateStart:
        pRecord->minDataBytes = 0;//sizeof(yam::ycolor) * pRecord->imageSize.v * pRecord->imageSize.h;
        pRecord->maxDataBytes = pRecord->maxData;
        pRecord->data = NULL;
        break;

    case formatSelectorEstimateContinue:
        break;

    case formatSelectorEstimateFinish:
        break;

    case formatSelectorReadPrepare:
        break;

    case formatSelectorReadStart:
        {
            yam::external::YCPsFormatReader reader;
            reader.Do(pRecord);
        } break;

    case formatSelectorReadContinue:
        break;

    case formatSelectorReadFinish:
        break;

    case formatSelectorWritePrepare:
        pRecord->maxData = 0;
        break;

    case formatSelectorWriteStart:
        {
            yam::external::YCPsFormatWriter writer;
            writer.Do(pRecord);
        } break;

    case formatSelectorWriteContinue:
        break;

    case formatSelectorWriteFinish:
        break;

    default:
        break;
    }
}

OSErr FSWrite(int32 refNum, int32* count, void* buffPtr)
{
    int32 bytes = *count;

    if (!WriteFile((HANDLE)refNum, buffPtr, bytes, (unsigned long *)count, NULL))
    {
        return writErr;
    }

    if (bytes != *count)
    {
        return writErr;
    }

    return noErr;
}

/*!
  \page pstoyam

  A photoshop plugin to export the psd to yui.
 */
