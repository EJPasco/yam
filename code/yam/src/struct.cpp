// The MIT License (MIT) Copyright (c) 2014 Code 4 Game
/*!
  \file struct.cpp
  \author Alex Chi
  \brief implement of struct.h

 */
#include "struct.h"

namespace yam{

/*!
  \var YVec2D YVec2D::None
  \brief a static const vec2d, it is none of vec2d
 */
const YVec2D YVec2D::None = YVec2D();

const YRect2D YRect2D::None = YRect2D();

const YFVec2D YFVec2D::None = YFVec2D();

const YFRect2D YFRect2D::None = YFRect2D();

/*!
  \fn YVec2D operator+(const YVec2D& rstVec2DA, const YVec2D& rstVec2DB)
  \brief a function to calculate a value, is sum of two vec2ds
  \param rstVec2DA a vec2d ready to add
  \param rstVec2DB another vec2d ready to add
  \return a new vec2d
 */
YVec2D operator+(const YVec2D& rstVec2DA, const YVec2D& rstVec2DB)
{
    YVec2D stNew;
    stNew.X = rstVec2DA.X + rstVec2DB.X;
    stNew.Y = rstVec2DA.X + rstVec2DB.X;
    return stNew;
}

YVec2D operator-(const YVec2D& rstVec2DA, const YVec2D& rstVec2DB)
{
    YVec2D stNew;
    stNew.X = rstVec2DA.X - rstVec2DB.X;
    stNew.Y = rstVec2DA.X - rstVec2DB.X;
    return stNew;
}

YVec2D operator*(const YVec2D& rstVec2DA, const YVec2D& rstVec2DB)
{
    YVec2D stNew;
    stNew.X = rstVec2DA.X * rstVec2DB.X;
    stNew.Y = rstVec2DA.X * rstVec2DB.X;
    return stNew;
}

}
