#ifndef Y_PANEL_H
#define Y_PANEL_H

#include "common.h"

#include "widget.h"

namespace yam{ namespace base{

class IYPanel : public IYWidget
{
public:
	virtual ~IYPanel() { ; }
};

template<typename TNBase>
class TYPanel : public TYWidget<TNBase>
{
public:
	TYPanel() { ; }
	virtual ~TYPanel() { ; }

public:
};

class CYPanel : public TYPanel<IYPanel>
{
public:
	CYPanel();
	virtual ~CYPanel();

public:
	void test()
	{
		//this->GetChildren()
	}
};

}}

#endif // Y_PANEL_H