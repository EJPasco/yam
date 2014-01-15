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

	yint32		X;
	yint32		Y;
};

struct YRect2D
{
	YVec2D		Pos;
	YVec2D		Size;
};

struct YFVec2D
{
	YFVec2D() : X(0.0f), Y(0.0f) { ; }

	yfloat32		X;
	yfloat32		Y;
};

struct YFRect2D
{
	YFVec2D		Pos;
	YFVec2D		Size;
};

struct YBuffer
{
	YBuffer() : Size(0), Data(YNULL) { ; }

	ybuffsize	Size;
	ybuffptr	Data;
};
typedef std::vector<YBuffer>		yvbuffer;

}

#endif // Y_STRUCT_H
