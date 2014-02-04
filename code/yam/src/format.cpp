#include "format.h"

#include "buffer.h"

namespace yam{ namespace base{

YOBJECT_IMPL(YCFormat);

YCFormat::YCFormat()
{
    //
}

YCFormat::~YCFormat()
{
    if (YNULL != m_pColorData)
    {
        delete[] m_pColorData;
        m_pColorData = YNULL;
    }
}

bool YCFormat::operator>>(YCBuffer& rBuffer) const
{
    YCBuffer buf;
    buf.GetId() = GetId();
    buf.GetClassName() = GetClassName();
    buf.Begin();
    const YRect2D& stBound = GetBound();
    buf.In(stBound);
    buf.Write(sizeof(ycolor) * stBound.Size.X * stBound.Size.Y, (const ybuffptr)GetColorData());
    buf.End();
    buf >> rBuffer;

    return super::operator >>(rBuffer);
}

bool YCFormat::operator<<(YCBuffer& rBuffer)
{
    YCBuffer buf;
    buf << rBuffer;

    if (buf.GetClassName() != GetClassName())
    {
        assert(false);
        return false;
    }
    GetId() = buf.GetId();
    YRect2D stBound;
    buf.Out(stBound);
    ysize iSize = stBound.Size.X * stBound.Size.Y;
    ycolorptr pColorData = YNULL;
    if (0 < iSize)
    {
        pColorData = new ycolor[iSize];
    }
    
    buf.Read(sizeof(ycolor) * iSize, (const ybuffptr)pColorData);
    SetBoundAndColorData(stBound, pColorData);
    if (YNULL != pColorData)
    {
        delete[] pColorData;
    }

    return super::operator <<(rBuffer);
}

void YCFormat::SetBoundAndColorData(const YRect2D& rstBound, ycolorptr pColorData)
{
    m_stBound = rstBound;
    yint32 iSize = rstBound.Size.X * rstBound.Size.Y;
    SetColorData(iSize, pColorData);
}

// void YCFormat::Refine()
// {
//     Crop(CalculateSmallestBound());
// 
//     YITree* pNext = GetNext();
//     while (YNULL != pNext)
//     {
//         if (YOBJECT_GETCLASSNAME(YCFormat) == pNext->GetClassName())
//         {
//             YCFormat* pFormat = (YCFormat*)pNext;
//             pFormat->Refine();
//         }
//         pNext = pNext->GetNext();
//     }
// 
//     YITree* pChildren = GetChildren();
//     while (YNULL != pChildren)
//     {
//         if (YOBJECT_GETCLASSNAME(YCFormat) == pChildren->GetClassName())
//         {
//             YCFormat* pFormat = (YCFormat*)pChildren;
//             pFormat->Refine();
//         }
//         pChildren = pChildren->GetChildren();
//     }
//     
// }

void YCFormat::SetColorData(const yint32& riSize, const ycolorptr& rpColorData)
{
    if (YNULL != m_pColorData)
    {
        delete[] m_pColorData;
        m_pColorData = YNULL;
    }

    if (0 < riSize && YNULL != rpColorData)
    {
        m_pColorData = new ycolor[riSize];
        ::memcpy(m_pColorData, rpColorData, sizeof(ycolor) * riSize);
    }
}

// YRect2D YCFormat::CalculateSmallestBound() const
// {
//     YRect2D stBound;
//     if (YNULL == m_pColorData)
//     {
//         stBound.Size.X = 0;
//         stBound.Size.Y = 0;
//     }
//     else
//     {
//         yint32 iMinX = -1;
//         yint32 iMaxX = -1;
//         yint32 iMinY = -1;
//         yint32 iMaxY = -1;
// 
//         ysize iSize = stBound.Size.X * stBound.Size.Y;
//         bool bAllInvisible = true;
//         for (yint32 y = 0; y < m_stBound.Size.Y; ++y)
//         {
//             for (yint32 x = 0; x < m_stBound.Size.X; ++x)
//             {
//                 const ycolor& iColor = m_pColorData[x + y * m_stBound.Size.X];
//                 if (0 == YGETCOLORBIT(iColor, YBITOFFSET_ALPHA))
//                 {
//                     continue;
//                 }
//                 if (-1 == iMinX || x < iMinX)
//                 {
//                     iMinX = x;
//                 }
//                 if (x > iMaxX)
//                 {
//                     iMaxX = x;
//                 }
//                 if (-1 == iMinY || y < iMinY)
//                 {
//                     iMinY = y;
//                 }
//                 if (y > iMaxY)
//                 {
//                     iMaxY = y;
//                 }
//                 bAllInvisible = false;
//             }
//         }
//         if (bAllInvisible)
//         {
//             stBound.Size.X = 0;
//             stBound.Size.Y = 0;
//         }
//         else
//         {
//             stBound.Pos.X = iMinX;
//             stBound.Pos.Y = iMinY;
//             stBound.Size.X = iMaxX - iMinX + 1;// +1 for inner
//             stBound.Size.Y = iMaxY - iMinY + 1;
//         }
//     }
//     return stBound;
// }

// void YCFormat::Crop(YRect2D stBound)
// {
//     stBound.Pos.X += m_stBound.Pos.X;
//     stBound.Pos.Y += m_stBound.Pos.Y;
//     ysize iSize = stBound.Size.X * stBound.Size.Y;
//     ycolorptr pNewData = YNULL;
//     if (0 < iSize && YNULL != m_pColorData)
//     {
//         pNewData = new ycolor[iSize];
//         for (yint32 y = 0; y < stBound.Size.Y; ++y)
//         {
//             for (yint32 x = 0; x < stBound.Size.X; ++x)
//             {
//#error has a bug
//                 pNewData[x + y * stBound.Size.X] = m_pColorData[x + stBound.Pos.X + (y + stBound.Pos.Y) * m_stBound.Size.X];
//             }
//         }
//     }
//     SetBoundAndColorData(stBound, pNewData);
//     if (YNULL != pNewData)
//     {
//         delete[] pNewData;
//         pNewData = YNULL;
//     }
// }

}}
