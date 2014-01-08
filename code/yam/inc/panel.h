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
	explicit TYPanel(const ystring& rsType) : TYWidget(rsType) { ; }
	virtual ~TYPanel() { ; }

public:
};

class CYPanel : public TYPanel<IYPanel>
{
public:
	SINGLETON_DECL(CYPanel);

public:
	CYPanel();
	virtual ~CYPanel();

public:

private:
};

}}

#endif // Y_PANEL_H