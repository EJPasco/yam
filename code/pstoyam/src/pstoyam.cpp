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
		break;

	case formatSelectorEstimateStart:
		break;

	case formatSelectorEstimateContinue:
		break;

	case formatSelectorEstimateFinish:
		break;

	case formatSelectorReadPrepare:
		break;

	case formatSelectorReadStart:
		break;

	case formatSelectorReadContinue:
		break;

	case formatSelectorReadFinish:
		break;

	case formatSelectorWritePrepare:
		break;

	case formatSelectorWriteStart:
		{
			//yam::external::photoshop::plugin::CYFormat format;
			//format.Save(formatParamBlock, "aa", "yam");
		}
		break;

	case formatSelectorWriteContinue:
		break;

	case formatSelectorWriteFinish:
		break;

	default:
		break;
	}
}

