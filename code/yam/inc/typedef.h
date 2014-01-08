#ifndef Y_TYPEDEF_H
#define Y_TYPEDEF_H

#include <string>
#include <fstream>

namespace yam{

typedef void*					yptr;
typedef bool					ybool;
typedef char					yint8;
typedef unsigned char			yuint8;
typedef int						yint32;
typedef unsigned int			yuint32;
typedef float					yfloat32;
typedef std::string				ystring;
typedef std::ifstream			yifstream;
typedef std::ofstream			yofstream;

typedef yint8					ybuff;
typedef ybuff*					ybuffptr;
typedef yint32					ybuffsize;

typedef yint32					ycolor;
typedef yint32*					ycolorptr;

typedef yint32					ylayerweight;

}

#endif // Y_TYPEDEF_H
