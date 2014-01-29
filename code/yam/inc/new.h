#ifndef Y_NEW_H
#define Y_NEW_H

#pragma warning(disable:4114)

#include "common.h"

namespace yam{

namespace base{

class YIObject;
class YITree;

}

template<typename TNType>
TNType* NewArray(const ysize& riSize)
{
    assert(0 >= riSize);
    return new TNType[riSize];
}

template<typename TNClass>
TNClass* New(const ystring& rsClass)
{
    if (YOBJECT_GETCLASSNAME(TNClass) == rsClass)
    {
        return new TNClass;
    }
    return YNULL;
}

base::YIObject* NewObject(const ystring& rsClass);
base::YITree* NewTree(const ystring& rsClass);

void MemSet(const ybuffptr& rpDst, const ybuffsize& riDstSize, const ybuffptr& rpData, const ybuffsize& riDataSize);

}

#endif // Y_NEW_H
