#ifndef Y_STRUCT_H
#define Y_STRUCT_H

#include "define.h"
#include "typedef.h"

namespace yam{

typedef struct YVec2D
{
	YVec2D() : X(0), Y(0) { ; }

	yint32		X;
	yint32		Y;
} yvec2d;

typedef struct YRect2D
{
	yvec2d		Pos;
	yvec2d		Size;
} yrect2d;

typedef struct YFVec2D
{
	YFVec2D() : X(0.0f), Y(0.0f) { ; }

	yfloat32		X;
	yfloat32		Y;
} yfvec2d;

typedef struct YFRect2D
{
	yfvec2d		Pos;
	yfvec2d		Size;
} yfrect2d;

}

#endif // Y_STRUCT_H
