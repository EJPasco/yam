#ifndef Y_DEFINE_H
#define Y_DEFINE_H

#ifdef C4G_EXPORTS_API
#	define YAM_API    __declspec(dllexport)
#else
#	define YAM_API
#endif // C4G_EXPORTS_API

#ifndef YNULL
#define YNULL			0
#endif

#define GET_DECL(type, name)				type name()
#define GET_FUNC(type, name, var)			GET_DECL(type, name) { return var; }

#define GET_DECL_CONST(type, name)			const type name() const
#define GET_FUNC_CONST(type, name, var)		GET_DECL_CONST(type, name) { return var; }

#define SINGLETON_DECL(_Class)		static _Class& Instance();
#define SINGLETON_IMPL(_Class)		_Class& _Class::Instance()\
	{ static _Class gs_##_Class##Instance; return gs_##_Class##Instance; }

#define __INTTOSTRING1__(num)				#num
#define __INTTOSTRING__(num)				__INTTOSTRING1__(num)
#define __SLINE__							__INTTOSTRING__(__LINE__)
#define __FUNCTIONNAMEWITHLINE__			__FUNCTION__"("__SLINE__")"
#define __TITLE_FUNCTIONNAMEWITHLINE__		"["__FUNCTION__"("__SLINE__")]"
#define COMPILE_MESSAGE_TODO(msg)			message(__TITLE_FUNCTIONNAMEWITHLINE__" to do: "msg)
// usage:
// #pragma COMPILE_MESSAGE_TODO("write message in here")
// 

#define FILEKEY_GET(_Class)				_Class::Instance().GetType()

#define FILE_KEY_FORMAT				"format"
#define FILE_KEY_WIDGET				"widget"

#define FILE_KEY_WIDGET_BASE		"base"
#define FILE_KEY_WIDGET_PANEL		"panel"

#endif // Y_DEFINE_H
