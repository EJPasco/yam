#ifndef Y_EXPORT_H
#define Y_EXPORT_H

#include "yeditorcommon.h"

namespace yam{ namespace io{

class YIExport
{
public:
    virtual ~YIExport() { ; }

public:
    virtual GET_DECL(yam::base::YCProperty&, GetProperty) = 0;
    virtual GET_DECL_CONST(yam::base::YCProperty&, GetProperty) = 0;

public:
    virtual void Save(const yam::base::YCTree* pTree) const = 0;
};

template<typename TNBase>
class YTExport : public TNBase
{
public:
    YTExport() { ; }
    virtual ~YTExport() { ; }

public:
    virtual GET_FUNC(yam::base::YCProperty&, GetProperty, m_oProperty);
    virtual GET_FUNC_CONST(yam::base::YCProperty&, GetProperty, m_oProperty);

protected:
    yam::base::YCProperty              m_oProperty;
};

class YCExport : public YTExport<YIExport>
{
public:
    YCExport();
    virtual ~YCExport();

public:
    virtual void Save(const yam::base::YCTree* pTree) const;
};

}}

#endif // Y_EXPORT_H
