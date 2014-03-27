// The MIT License (MIT) Copyright (c) 2014 Code 4 Game
/*!
  \file typedef.h
  \author Alex Chi
  \brief some type definitions for the project

 */
#ifndef Y_TYPEDEF_H
#define Y_TYPEDEF_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#if defined(GNUC)
#include <cstring>
#endif

namespace yam{

/*!
  \var typedef void* yptr;
  \brief a type definition for the pointer
 */
typedef void*                       yptr;
typedef bool                        ybool;
typedef char                        yint8;
typedef unsigned char               yuint8;
typedef int                         yint32;
typedef unsigned int                yuint32;
typedef float                       yfloat32;

typedef std::string                 ystring;
typedef std::istream                yistream;
typedef std::ostream                yostream;
typedef std::iostream               yiostream;
typedef std::fstream                yfstream;
typedef std::ifstream               yifstream;
typedef std::ofstream               yofstream;
typedef std::streambuf              ystreambuff;

typedef yint8                       ybuff;
typedef ybuff*                      ybuffptr;
typedef yint32                      ybuffsize;
typedef yint32                      ybuffpos;

typedef yuint8                      ycolorbit;
typedef ycolorbit*                  ycolorbitptr;
typedef yuint32                     ycolor;
typedef ycolor*                     ycolorptr;

typedef yint32                      ylayerweight;

typedef yint32                      ysize;

}

#endif // Y_TYPEDEF_H
