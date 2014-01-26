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
	YCProperty oProperty;
	*this >> oProperty;
	oProperty >> buf;
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
	YCProperty oProperty;
	oProperty << buf;
	*this << oProperty;

	return __super::operator <<(rBuffer);
}

void YCWidget::operator>>(YCProperty& rProperty) const
{
	rProperty.Clear();

	{
		// bound
		YCProperty* pProperty = rProperty.NewNext<YCProperty>();
		pProperty->GetId() = "bound";
		pProperty->FromRect2D(GetBound());
	}
	{
		// layer weight
		YCProperty* pProperty = rProperty.NewNext<YCProperty>();
		pProperty->GetId() = "layerweight";
		pProperty->FromInt32(GetLayerWeight());
	}
}

void YCWidget::operator<<(YCProperty& rProperty)
{
	{
		// bound
		YITree* pProperty = rProperty.FindNext("bound");
		if (YNULL != pProperty && YOBJECT_GETCLASSNAME(YCProperty) == pProperty->GetClassName())
		{
			((YCProperty*)pProperty)->ToRect2D(GetBound());
		}
	}
	{
		// layer weight
		YITree* pProperty = rProperty.FindNext("layerweight");
		if (YNULL != pProperty && YOBJECT_GETCLASSNAME(YCProperty) == pProperty->GetClassName())
		{
			((YCProperty*)pProperty)->ToInt32(GetLayerWeight());
		}
	}
}

}}
