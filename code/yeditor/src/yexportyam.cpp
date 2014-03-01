#include "yexportyam.h"

namespace yam{ namespace io{

YCExportYam::YCExportYam()
{
    //
}

YCExportYam::~YCExportYam()
{
    //
}

void YCExportYam::Save(const yam::base::YCTree& rTree) const
{
    yam::base::YCProperty* pFile = GetProperty().Find<yam::base::YCProperty>("file");
    yam::base::YCProperty* pData = GetProperty().Find<yam::base::YCProperty>("data");
    yam::ystring sDirectory;
    yam::ystring sFileName;
    yam::ystring sLogicName;
    if (YNULL != pFile)
    {
        yam::base::YCProperty* pFileDirectory = pFile->Find<yam::base::YCProperty>("directory");
        if (YNULL != pFileDirectory)
        {
            pFileDirectory->ToString(sDirectory);
        }
        yam::base::YCProperty* pFileName = pFile->Find<yam::base::YCProperty>("name");
        if (YNULL != pFileName)
        {
            pFileName->ToString(sFileName);
        }
    }
    if (YNULL != pData)
    {
        yam::base::YCProperty* pDataLogic = pData->Find<yam::base::YCProperty>("logic");
        if (YNULL != pDataLogic)
        {
            pDataLogic->ToString(sLogicName);
        }
    }
    sFileName = "";
    //
}

}}
