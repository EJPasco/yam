#ifndef Y_WIDGET_H
#define Y_WIDGET_H

#include "common.h"

#include <vector>

namespace yam{ namespace base{

class IYWidget
{
public:
	virtual ~IYWidget() = 0;

public:
};

typedef std::vector<IYWidget*>		VYWidgetPtr;

template<typename TNBase>
class TYWidget : public TNBase
{
public:
	TYWidget() { ; }
	virtual ~TYWidget() { ; }

public:

private:
	IYWidget*		m_pParent;
	VYWidgetPtr		m_vpChild;
};

class CYWidget : public TYWidget<IYWidget>
{
public:
	CYWidget();
	virtual ~CYWidget();

public:
};

}}

#endif // Y_WIDGET_H