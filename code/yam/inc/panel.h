#ifndef Y_PANEL_H
#define Y_PANEL_H

#include "common.h"

#include "widget.h"

namespace yam{ namespace base{

class IYPanel : public IYWidget
{
public:
	virtual ~IYPanel() = 0;
};

class CYPanel : public TYWidget<IYPanel>
{
public:
	CYPanel();
	virtual ~CYPanel();

public:
};

}}

#endif // Y_PANEL_H