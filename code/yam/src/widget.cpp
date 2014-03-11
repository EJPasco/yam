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

    return super::operator >>(rBuffer);
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

    return super::operator <<(rBuffer);
}

void YCWidget::operator>>(YCProperty& rProperty) const
{
    rProperty.Clear();

    {
        // widget type
        YCProperty* pProperty = rProperty.NewNext<YCProperty>();
        pProperty->GetId() = "type";
        pProperty->FromInt32(GetType());
    }
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
    {
        // external property
        YCBuffer oBuffer;
        oBuffer.Begin();
        m_oExternalProperty >> oBuffer;
        oBuffer.End();

        if (0 < oBuffer.GetSize())
        {
            YCProperty* pProperty = rProperty.NewNext<YCProperty>();
            (*pProperty) << oBuffer;
            pProperty->GetId() = "external";
        }
    }
}

void YCWidget::operator<<(YCProperty& rProperty)
{
    {
        // widget type
        YITree* pProperty = rProperty.FindNext("type");
        if (YNULL != pProperty && YOBJECT_GETCLASSNAME(YCProperty) == pProperty->GetClassName())
        {
            yint32 iType = eWidgetType_None;
            ((YCProperty*)pProperty)->ToInt32(iType);
            if (eWidgetType_None < iType && eWidgetType_Max > iType)
            {
                GetType() = (EWidgetType)iType;
            }
        }
    }
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
    {
        // external property
        YCBuffer oBuffer;

        YITree* pProperty = rProperty.FindNext("external");
        if (YNULL != pProperty && YOBJECT_GETCLASSNAME(YCProperty) == pProperty->GetClassName())
        {
            oBuffer.Begin();
            (*((YCProperty*)pProperty)) >> oBuffer;
            oBuffer.End();
        }
        m_oExternalProperty.Clear();
        if (0 < oBuffer.GetSize())
        {
            m_oExternalProperty << oBuffer;
        }
    }
}

}}
