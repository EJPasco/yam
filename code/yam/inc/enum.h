// The MIT License (MIT) Copyright (c) 2014 Code 4 Game
/*!
  \file enum.h
  \author Alex Chi
  \brief typedef some enums for the project

 */
#ifndef Y_ENUM_H
#define Y_ENUM_H

namespace yam{

/// list of color channel
enum EColorChannel
{
    eColorChannel_Red,
    eColorChannel_Green,
    eColorChannel_Blue,
    eColorChannel_Alpah,
    eColorChannel_Max,
};

/// list of widget type
enum EWidgetType
{
    eWidgetType_None,
    eWidgetType_Scene,
    eWidgetType_Panel,
    eWidgetType_Image,
    eWidgetType_Button,
    eWidgetType_Text,
    eWidgetType_Max,
};

/// list of align
enum EAlignType
{
    eAlignType_Left,
    eAlignType_Right,
    eAlignType_Top,
    eAlignType_Bottom,
    eAlignType_Center,
    eAlignType_Max,
};

}

#endif // Y_ENUM_H
