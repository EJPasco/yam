#include "new.h"

#include "buffer.h"
#include "format.h"
#include "widget.h"

namespace yam{

base::YIObject* NewObject(const ystring& rsClass)
{
	{
		base::YIObject* pNewObj = New<base::YCBuffer>(rsClass);
		if (YNULL != pNewObj)
		{
			return pNewObj;
		}
	}
	{
		base::YIObject* pNewObj = New<base::YCFormat>(rsClass);
		if (YNULL != pNewObj)
		{
			return pNewObj;
		}
	}
	{
		base::YIObject* pNewObj = New<base::YCWidget>(rsClass);
		if (YNULL != pNewObj)
		{
			return pNewObj;
		}
	}
	return YNULL;
}

base::YITree* NewTree(const ystring& rsClass)
{
	{
		base::YITree* pNewTree = New<base::YCFormat>(rsClass);
		if (YNULL != pNewTree)
		{
			return pNewTree;
		}
	}
	{
		base::YITree* pNewTree = New<base::YCWidget>(rsClass);
		if (YNULL != pNewTree)
		{
			return pNewTree;
		}
	}
	return YNULL;
}

void MemSet(const ybuffptr& rpDst, const ybuffsize& riDstSize, const ybuffptr const& rpData, const ybuffsize& riDataSize)
{
	assert(YNULL != rpDst && YNULL != rpData && 0 < riDstSize && 0 < riDataSize && 0 == (riDstSize % riDataSize));
	ysize iCount = riDstSize / riDataSize;
	for (yint32 i = 0; i < iCount; ++i)
	{
		::memcpy(rpDst + riDataSize * i, rpData, riDataSize);
	}
}

}
