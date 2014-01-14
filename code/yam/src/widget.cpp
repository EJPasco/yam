#include "widget.h"

namespace yam{ namespace base{

YOBJECT_IMPL(YCWidget);

YCWidget::YCWidget()
{
	//
}

YCWidget::~YCWidget()
{
	//
}

ybool YCWidget::operator>>(YCBuffer& rBuffer) const
{
	YCBuffer buf;
	buf.GetId() = GetId();
	buf.GetClassName() = GetClassName();
	buf.Begin();
	YCProperty property;
	*this >> property;
	property >> buf;
	buf.End();
	buf >> rBuffer;

	return __super::operator >>(rBuffer);
}

ybool YCWidget::operator<<(YCBuffer& rBuffer)
{
	YCBuffer buf;
	buf << rBuffer;

	if (buf.GetClassName() != GetClassName())
	{
		assert(false);
		return YFALSE;
	}
	GetId() = buf.GetId();
	YCProperty property;
	property << buf;
	*this << property;

	return __super::operator <<(rBuffer);
}

ybool YCWidget::operator>>(YCProperty& rProperty) const
{
	YCProperty* pPropertyBound = rProperty.NewNext<YCProperty>();
	pPropertyBound->GetId() = "bound";
	pPropertyBound->FromRect2D(GetBound());
	return YTRUE;
}

ybool YCWidget::operator<<(YCProperty& rProperty)
{
	YITree* pTreeBound = rProperty.FindNext("bound");
	if (YNULL == pTreeBound || YOBJECT_GETCLASSNAME(YCProperty) != pTreeBound->GetClassName())
	{
		return YFALSE;
	}
	return ((YCProperty*)pTreeBound)->ToRect2D(GetBound());
}

}}
