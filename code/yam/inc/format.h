#ifndef Y_FORMAT_H
#define Y_FORMAT_H

#include "common.h"

#include "tree.h"

namespace yam{ namespace base{

class YIFormat : public YITree
{
public:
    virtual ~YIFormat() { ; }

public:
    virtual GET_DECL_CONST(YRect2D&, GetBound) = 0;
    virtual GET_DECL_CONST(ycolorptr&, GetColorData) = 0;

public:
    virtual void SetBoundAndColorData(const YRect2D& rstBound, ycolorptr pColorData) = 0;
//     virtual void Refine() = 0;
};

template<typename TNBase, typename TNReal>
class YTFormat : public YTTree<TNBase, TNReal>
{
public:
    YTFormat() : m_pColorData(YNULL) { ; }
    virtual ~YTFormat() { ; }

public:
    virtual GET_FUNC_CONST(YRect2D&, GetBound, m_stBound);
    virtual GET_FUNC_CONST(ycolorptr&, GetColorData, m_pColorData);

protected:
    YRect2D        m_stBound;
    ycolorptr    m_pColorData;
};

class YCFormat : public YTFormat<YIFormat, YCFormat>
{
    typedef YTFormat<YIFormat, YCFormat>        super;
    YOBJECT_DECL(YCFormat);

public:
    YCFormat();
    virtual ~YCFormat();

public:
    virtual bool operator>>(YCBuffer& rBuffer) const;
    virtual bool operator<<(YCBuffer& rBuffer);

public:
    virtual void SetBoundAndColorData(const YRect2D& rstBound, ycolorptr pColorData);
//    virtual void Refine();

private:
    void SetColorData(const yint32& riSize, const ycolorptr& rpColorData);
//    YRect2D CalculateSmallestBound() const;
//    void Crop(YRect2D rstBound);
};

#define YGETCOLORBIT(_Color, _Offset) (*((ycolorbitptr)&_Color + _Offset / (sizeof(ycolorbit) * YBITCOUNT_INT8)))
#define YSETCOLORBIT(_Color, _Value, _Offset) (*((ycolorbitptr)&_Color + _Offset / (sizeof(ycolorbit) * YBITCOUNT_INT8))) = _Value

}}

#endif // Y_FORMAT_H
