#ifndef __DEFINE_H__
#define __DEFINE_H__

#ifdef C4G_EXPORTS_API
#	define YAM_API    __declspec(dllexport)
#else
#	define YAM_API
#endif // C4G_EXPORTS_API

#endif // __DEFINE_H__
