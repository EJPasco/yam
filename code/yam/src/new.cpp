#include "new.h"

#include "buffer.h"
#include "format.h"
#include "widget.h"

namespace yam{

YIObject* NewObject(const ystring& rsClass)
{
	{
		YIObject* pNewObj = New<base::YCBuffer>(rsClass);
		if (YNULL != pNewObj)
		{
			return pNewObj;
		}
	}
	{
		YIObject* pNewObj = New<base::YCFormat>(rsClass);
		if (YNULL != pNewObj)
		{
			return pNewObj;
		}
	}
	{
		YIObject* pNewObj = New<base::YCWidget>(rsClass);
		if (YNULL != pNewObj)
		{
			return pNewObj;
		}
	}
	return YNULL;
}

}
