#ifndef __DEFINE_H__
#define __DEFINE_H__

#ifdef C4G_EXPORTS_API
#	define YAM_API    __declspec(dllexport)
#else
#	define YAM_API
#endif // C4G_EXPORTS_API

#define GET_DECL(type, name)				type name()
#define GET_FUNC(type, name, var)			GET_DECL(type, name) { return var; }

#define GET_DECL_CONST(type, name)			const type name() const
#define GET_FUNC_CONST(type, name, var)		GET_DECL_CONST(type, name) { return var; }

#endif // __DEFINE_H__
