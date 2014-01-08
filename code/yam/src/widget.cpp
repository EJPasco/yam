#include "widget.h"

namespace yam{ namespace base{

SINGLETON_IMPL(CYWidget);

CYWidget::CYWidget()
	: TYWidget(FILE_KEY_WIDGET_BASE)
{
	//
}

CYWidget::~CYWidget()
{
	//
}

}}
