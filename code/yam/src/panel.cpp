#include "panel.h"

namespace yam{ namespace base{

SINGLETON_IMPL(CYPanel);

CYPanel::CYPanel()
	: TYPanel(FILE_KEY_WIDGET_PANEL)
{
	//
}

CYPanel::~CYPanel()
{
	//
}

}}
