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
    buf.In(GetValue().GetSize());
    buf.Write(GetValue().GetSize(), GetValue().GetData());
    //buf.In(GetValue());
    buf.End();
    buf >> rBuffer;

    return super::operator >>(rBuffer);
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
    ybuffsize iSize = 0;
    buf.Out(iSize);
    GetValue().New(iSize);
    buf.Read(iSize, GetValue().GetData());
    //buf.Out(GetValue());

    return super::operator <<(rBuffer);
}

ybool YCProperty::FromString(const ystring& rsValue)
{
    GetValue().Clear();
    GetValue().Begin();
    GetValue().Write(sizeof(yint8) * rsValue.size(), (ybuffptr)rsValue.c_str());
    GetValue().End();
    return YTRUE;
}

ybool YCProperty::ToString(ystring& rsValue) const
{
    rsValue.clear();

    ybuffsize iSize = GetValue().GetSize();
    if (0 < iSize)
    {
        yint8* pStr = new yint8[iSize + 1];
        ::memcpy(pStr, GetValue().GetData(), sizeof(yint8) * iSize);
        pStr[iSize] = '\0';
        rsValue.append(pStr);
        delete[] pStr;
    }
    return YTRUE;
}

ybool YCProperty::FromInt32(const yint32& riValue)
{
    yint8* pStr = new yint8[YSTRINGLEN_INT32_MAX];
    {
        ybuff iZero = 0;
        MemSet(pStr, sizeof(yint8) * YSTRINGLEN_INT32_MAX, &iZero, sizeof(ybuff));
    }
#if defined(MSVC)
    ::sprintf_s(pStr, YSTRINGLEN_INT32_MAX, "%d", riValue);
#elif defined(GNUC)
    ::sprintf(pStr, "%d", riValue);
#else
#pragma YCOMPILE_MESSAGE_ERR("can't find the compiler type")
#endif
    ystring sStr = "";
    sStr.append(pStr);
    delete[] pStr;

    return FromString(sStr);
}

ybool YCProperty::ToInt32(yint32& riValue) const
{
    ystring sStr;
    if (!ToString(sStr))
    {
        return YFALSE;
    }

    yint32 iValue = 0;
#if defined(MSVC)
    if (EOF == ::sscanf_s(sStr.c_str(), "%d", &iValue))
#elif defined(GNUC)
    if (EOF == ::sscanf(sStr.c_str(), "%d", &iValue))
#else
#pragma YCOMPILE_MESSAGE_ERR("can't find the compiler type")
#endif
    {
        return YFALSE;
    }
    riValue = iValue;
    return YTRUE;
}

ybool YCProperty::FromFloat32(const yfloat32& rfValue)
{
    yint8* pStr = new yint8[YSTRINGLEN_FLOAT32_MAX];
    {
        ybuff iZero = 0;
        MemSet(pStr, sizeof(yint8) * YSTRINGLEN_FLOAT32_MAX, &iZero, sizeof(ybuff));
    }
#if defined(MSVC)
    ::sprintf_s(pStr, YSTRINGLEN_FLOAT32_MAX, "%f", rfValue);
#elif defined(GNUC)
    ::sprintf(pStr, "%f", rfValue);
#else
#pragma YCOMPILE_MESSAGE_ERR("can't find the compiler type")
#endif
    ystring sStr = "";
    sStr.append(pStr);
    delete[] pStr;
    return FromString(sStr);
}

ybool YCProperty::ToFloat32(yfloat32& rfValue) const
{
    ystring sStr;
    if (!ToString(sStr))
    {
        return YFALSE;
    }

    yfloat32 fValue = 0;
#if defined(MSVC)
    if (EOF == ::sscanf_s(sStr.c_str(), "%f", &fValue))
#elif defined(GNUC)
    if (EOF == ::sscanf(sStr.c_str(), "%f", &fValue))
#else
#pragma YCOMPILE_MESSAGE_ERR("can't find the compiler type")
#endif
    {
        return YFALSE;
    }
    rfValue = fValue;
    return YTRUE;
}

ybool YCProperty::FromRect2D(const YRect2D& rstValue)
{
    yint8* pStr = new yint8[YSTRINGLEN_RECT2D32_MAX];
    {
        ybuff iZero = 0;
        MemSet(pStr, sizeof(yint8) * YSTRINGLEN_RECT2D32_MAX, &iZero, sizeof(ybuff));
    }
#if defined(MSVC)
    ::sprintf_s(pStr, YSTRINGLEN_RECT2D32_MAX, "%d,%d,%d,%d", rstValue.Pos.X, rstValue.Pos.Y, rstValue.Size.X, rstValue.Size.Y);
#elif defined(GNUC)
    ::sprintf(pStr, "%d,%d,%d,%d", rstValue.Pos.X, rstValue.Pos.Y, rstValue.Size.X, rstValue.Size.Y);
#else
#pragma YCOMPILE_MESSAGE_ERR("can't find the compiler type")
#endif
    ystring sStr = "";
    sStr.append(pStr);
    delete[] pStr;
    return FromString(sStr);
}

ybool YCProperty::ToRect2D(YRect2D& rstValue) const
{
    ystring sStr;
    if (!ToString(sStr))
    {
        return YFALSE;
    }

    YRect2D stValue;
#if defined(MSVC)
    if (EOF == ::sscanf_s(sStr.c_str(), "%d,%d,%d,%d", &stValue.Pos.X, &stValue.Pos.Y, &stValue.Size.X, &stValue.Size.Y))
#elif defined(GNUC)
    if (EOF == ::sscanf(sStr.c_str(), "%d,%d,%d,%d", &stValue.Pos.X, &stValue.Pos.Y, &stValue.Size.X, &stValue.Size.Y))
#else
#pragma YCOMPILE_MESSAGE_ERR("can't find the compiler type")
#endif
    {
        return YFALSE;
    }
    rstValue = stValue;
    return YTRUE;
}

ybool YCProperty::FromVec2D(const YVec2D& rstValue)
{
    yint8* pStr = new yint8[YSTRINGLEN_RECT2D32_MAX];
    {
        ybuff iZero = 0;
        MemSet(pStr, sizeof(yint8) * YSTRINGLEN_RECT2D32_MAX, &iZero, sizeof(ybuff));
    }
#if defined(MSVC)
    ::sprintf_s(pStr, YSTRINGLEN_RECT2D32_MAX, "%d,%d", rstValue.X, rstValue.Y);
#elif defined(GNUC)
    ::sprintf(pStr, "%d,%d", rstValue.X, rstValue.Y);
#else
#pragma YCOMPILE_MESSAGE_ERR("can't find the compiler type")
#endif
    ystring sStr = "";
    sStr.append(pStr);
    delete[] pStr;
    return FromString(sStr);
}

ybool YCProperty::ToVec2D(YVec2D& rstValue) const
{
    ystring sStr;
    if (!ToString(sStr))
    {
        return YFALSE;
    }

    YVec2D stValue;
#if defined(MSVC)
    if (EOF == ::sscanf_s(sStr.c_str(), "%d,%d", &stValue.X, &stValue.Y))
#elif defined(GNUC)
    if (EOF == ::sscanf(sStr.c_str(), "%d,%d", &stValue.X, &stValue.Y))
#else
#pragma YCOMPILE_MESSAGE_ERR("can't find the compiler type")
#endif
    {
        return YFALSE;
    }
    rstValue = stValue;
    return YTRUE;
}

ybool YCProperty::FromBuffer(const YCBuffer& roValue)
{
    GetValue().Begin();
    GetValue().Write(roValue.GetSize(), roValue.GetData());
    GetValue().End();
    return YTRUE;
}

ybool YCProperty::ToBuffer(YCBuffer& roValue) const
{
    roValue.Clear();
    roValue.Begin();
    roValue.Write(GetValue().GetSize(), GetValue().GetData());
    roValue.End();
    return YTRUE;
}

YCProperty* YCProperty::AddChild(const yam::ystring& rsId)
{
    // no same id objects
    YITree* pProperty = Find(rsId);
    if (YNULL != pProperty && YOBJECT_GETCLASSNAME(yam::base::YCProperty) == pProperty->GetClassName())
    {
        return (YCProperty*)pProperty;
    }
    YCProperty* pNew = new YCProperty();
    pNew->GetId() = rsId;
    super::AddChild((yam::base::YITree*)pNew);
    return pNew;
}

}}
