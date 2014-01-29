#ifndef Y_STRUCT_H
#define Y_STRUCT_H

#include "define.h"
#include "typedef.h"
#include "enum.h"

#include <vector>

namespace yam{

struct YVec2D
{
    YVec2D() : X(0), Y(0) { ; }
    YVec2D(const yint32& rX, const yint32& rY) : X(rX), Y(rY) { ; }

    yint32        X;
    yint32        Y;

    static const YVec2D None;
};
typedef std::vector<YVec2D>            yvvec2d;

struct YRect2D
{
    YRect2D() : Pos(YVec2D::None), Size(YVec2D::None) { ; }
    YRect2D(const YVec2D& rstPos, const YVec2D& rstSize) : Pos(rstPos), Size(rstSize) { ; }

    YVec2D        Pos;
    YVec2D        Size;

    static const YRect2D None;
};
typedef std::vector<YRect2D>        yvrect;

struct YFVec2D
{
    YFVec2D() : X(0.0f), Y(0.0f) { ; }
    YFVec2D(const yfloat32& rX, const yfloat32& rY) : X(rX), Y(rY) { ; }

    yfloat32        X;
    yfloat32        Y;

    static const YFVec2D None;
};

struct YFRect2D
{
    YFVec2D        Pos;
    YFVec2D        Size;

    static const YFRect2D None;
};

struct YBuffer
{
    YBuffer() : Size(0), Data(YNULL) { ; }

    ybuffsize    Size;
    ybuffptr    Data;
};
typedef std::vector<YBuffer>        yvbuffer;

}

#endif // Y_STRUCT_H
