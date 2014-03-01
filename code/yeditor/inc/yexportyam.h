#ifndef Y_EXPORTYAM_H
#define Y_EXPORTYAM_H

#include "yexport.h"

namespace yam{ namespace io{

class YCExportYam : public YTExport<YIExport>
{
public:
    YCExportYam();
    virtual ~YCExportYam();

public:
    virtual void Save(const yam::base::YCTree& rTree) const;

private:
    //void 
};

}}

#endif // Y_EXPORTYAM_H
