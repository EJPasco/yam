#ifndef Y_NEW_H
#define Y_NEW_H

#include "common.h"

#include "object.h"

namespace yam{

template<typename TNClass>
TNClass* New(const ystring& rsClass)
{
	if (YOBJECT_GETCLASSNAME(TNClass) == rsClass)
	{
		return new TNClass;
	}
	return YNULL;
}

YIObject* NewObject(const ystring& rsClass);

}

#endif // Y_NEW_H
