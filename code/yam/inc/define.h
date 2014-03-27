// The MIT License (MIT) Copyright (c) 2014 Code 4 Game
/*!
  \file define.h
  \author Alex Chi
  \brief some macros

 */
#ifndef Y_DEFINE_H
#define Y_DEFINE_H

#ifdef C4G_EXPORTS_API
#    define YAM_API    __declspec(dllexport)
#else
#    define YAM_API
#endif // C4G_EXPORTS_API

#ifndef YNULL
#define YNULL            0
#endif

/// used in the member function of the class
#define GET_DECL(type, name)                type name()
#define GET_FUNC(type, name, var)           GET_DECL(type, name) { return var; }
#define GET_FUNC_CUSTOM(type, name)         GET_DECL(type, name)

#define GET_DECL_CONST(type, name)          const type name() const
#define GET_FUNC_CONST(type, name, var)     GET_DECL_CONST(type, name) { return var; }
#define GET_FUNC_CONST_CUSTOM(type, name)   GET_DECL_CONST(type, name)

#define GET_CONST_DECL(type, name)          const type name()
#define GET_CONST_DECL_CUSTOM(type, name)   GET_CONST_DECL(type, name)

/// be used in the singleton class
#define SINGLETON_DECL(_Class)                                      \
    public:                                                         \
        static _Class& Instance();
#define SINGLETON_IMPL(_Class)                                      \
    _Class& _Class::Instance()                                      \
    {                                                               \
        static _Class gs_##_Class##Instance;                        \
        return gs_##_Class##Instance;                               \
    }

/// be used to generate the compiler error or message
#define __TOSTRING1__(num)                  #num
#define YTOSTRING(num)                      __TOSTRING1__(num)
#define YSLINE                              YTOSTRING(__LINE__)
#define YFUNCTIONNAMEWITHLINE               __FUNCTION__ + "(" + YSLINE + ")"
#define YTITLE_FUNCTIONNAMEWITHLINE         "[" + __FUNCTION__ + "(" + YSLINE + ")]"
/// usage: #pragma YCOMPILE_MESSAGE_TODO("write message in here")
#define YCOMPILE_MESSAGE_TODO(msg)          message(YTITLE_FUNCTIONNAMEWITHLINE + " to do: " + msg)
#define YCOMPILE_MESSAGE_ERR(msg)           message(YTITLE_FUNCTIONNAMEWITHLINE + " error: " + msg)

#define YFILE_KEY_RESOURCE                  "res"
#define YFILE_KEY_UI                        "ui"

/// be used to delcare the object of yam
// todo: try to use the static function to initialize the static variable for gcc in linux
#define YOBJECT_DECL(_Class)                                        \
    public:                                                         \
    static const ystring ClassName();
#define YOBJECT_IMPL(_Class)                                        \
    const ystring _Class::ClassName()                               \
    {                                                               \
        static const ystring ssClassName = YTOSTRING(_Class);       \
        return ssClassName;                                         \
    }
#define YOBJECT_GETCLASSNAME(_Class)        _Class::ClassName()

/// some const number
#define YTRUE                               1
#define YFALSE                              0

#define YBITCOUNT_INT8                      8

#define YBITOFFSET_RED                      24
#define YBITOFFSET_GREEN                    16
#define YBITOFFSET_BLUE                     8
#define YBITOFFSET_ALPHA                    0

#define YSTRINGLEN_INT32_MAX                64
#define YSTRINGLEN_FLOAT32_MAX              64
#define YSTRINGLEN_VEC2D32_MAX              128
#define YSTRINGLEN_RECT2D32_MAX             256

#endif // Y_DEFINE_H
