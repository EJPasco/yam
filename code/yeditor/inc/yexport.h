#ifndef Y_EXPORT_H
#define Y_EXPORT_H

#include <yam.h>

namespace yam{ namespace output{

class YIExport
{
public:
    virtual ~YIExport() { ; }

public:
};

template<typename TNBase>
class YTExport : public TNBase
{
public:
    YTExport() { ; }
    virtual ~YTExport() { ; }

public:
};

class YCExport : public YTExport<YIExport>
{
public:
    YCExport();
    virtual ~YCExport();

public:
};

}}

#endif // Y_EXPORT_H
