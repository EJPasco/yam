#include "property.h"

namespace yam{ namespace base{

YOBJECT_IMPL(YCProperty);

YCProperty::YCProperty()
{
	//
}

YCProperty::~YCProperty()
{
	//
}

ybool YCProperty::operator>>(YCBuffer& rBuffer) const
{
	YCBuffer buf;
	buf.GetId() = GetId();
	buf.GetClassName() = GetClassName();
	buf.Begin();
	buf.In(GetValue());
	buf.End();
	buf >> rBuffer;

	return __super::operator >>(rBuffer);
}

ybool YCProperty::operator<<(YCBuffer& rBuffer)
{
	YCBuffer buf;
	buf << rBuffer;

	if (buf.GetClassName() != GetClassName())
	{
		assert(false);
		return YFALSE;
	}
	GetId() = buf.GetId();
	buf.Out(GetValue());

	return __super::operator <<(rBuffer);
}

ybool YCProperty::FromString(const ystring& rsValue)
{
	GetValue() = rsValue;
	return YTRUE;
}

ybool YCProperty::ToString(ystring& rsValue) const
{
	rsValue = GetValue();
	return YTRUE;
}

ybool YCProperty::FromInt32(const yint32& riValue)
{
	yint8* pStr = new yint8[YSTRINGLEN_INT32_MAX];
	::sprintf_s(pStr, YSTRINGLEN_INT32_MAX, "%d", riValue);
	GetValue().clear();
	GetValue().append(pStr);
	delete[] pStr;
	return YTRUE;
}

ybool YCProperty::ToInt32(yint32& riValue) const
{
	yint32 iValue = 0;
	if (EOF == ::sscanf_s(GetValue().c_str(), "%d", iValue))
	{
		return YFALSE;
	}
	riValue = iValue;
	return YTRUE;
}

ybool YCProperty::FromFloat32(const yfloat32& rfValue)
{
	yint8* pStr = new yint8[YSTRINGLEN_FLOAT32_MAX];
	::sprintf_s(pStr, YSTRINGLEN_FLOAT32_MAX, "%f", rfValue);
	GetValue().clear();
	GetValue().append(pStr);
	delete[] pStr;
	return YTRUE;
}

ybool YCProperty::ToFloat32(yfloat32& rfValue) const
{
	yfloat32 fValue = 0;
	if (EOF == ::sscanf_s(GetValue().c_str(), "%f", fValue))
	{
		return YFALSE;
	}
	rfValue = fValue;
	return YTRUE;
}

ybool YCProperty::FromRect2D(const YRect2D& rstValue)
{
	yint8* pStr = new yint8[YSTRINGLEN_RECT2D32_MAX];
	::sprintf_s(pStr, YSTRINGLEN_RECT2D32_MAX, "%d,%d,%d,%d", rstValue.Pos.X, rstValue.Pos.Y, rstValue.Size.X, rstValue.Size.Y);
	GetValue().clear();
	GetValue().append(pStr);
	delete[] pStr;
	return YTRUE;
}

ybool YCProperty::ToRect2D(YRect2D& rstValue) const
{
	YRect2D stValue;
	if (EOF == ::sscanf_s(GetValue().c_str(), "%d,%d,%d,%d", &stValue.Pos.X, &stValue.Pos.Y, &stValue.Size.X, &stValue.Size.Y))
	{
		return YFALSE;
	}
	rstValue = stValue;
	return YTRUE;
}

}}
