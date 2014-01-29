#ifndef Y_PANEL_H
#define Y_PANEL_H

#include "common.h"

#include "widget.h"

namespace yam{ namespace base{

class YIPanel : public YIWidget
{
public:
    virtual ~YIPanel() { ; }
};

template<typename TNBase, typename TNReal>
class YTPanel : public YTWidget<TNBase, TNReal>
{
public:
    YTPanel() { ; }
    virtual ~YTPanel() { ; }

public:
};

class YCPanel : public YTPanel<YIPanel, YCPanel>
{
    typedef YTPanel<YIPanel, YCPanel>        super;
    YOBJECT_DECL(YCPanel);

public:
    YCPanel();
    virtual ~YCPanel();

public:

private:
};

}}

#endif // Y_PANEL_H