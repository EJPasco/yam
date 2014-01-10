#ifndef Y_OBJECT_H
#define Y_OBJECT_H

#include "common.h"

namespace yam{

namespace base{

class YCBuffer;

}

template<typename TNReal>
class YIObject
{
public:
	virtual ~YIObject() { ; }

public:
	virtual GET_DECL(ystring&, GetId) = 0;
	virtual GET_DECL_CONST(ystring&, GetId) = 0;
	virtual GET_DECL(ystring&, GetClassName) = 0;
	virtual GET_DECL_CONST(ystring&, GetClassName) = 0;

public:
	virtual void operator>>(base::YCBuffer& rBuffer) const = 0;
	virtual void operator<<(base::YCBuffer& rBuffer) = 0;
};

template<typename TNBase, typename TNReal>
class YTObject : public TNBase
{
public:
	YTObject() : m_sId("") { ; }
	virtual ~YTObject() { ; }

public:
	virtual GET_FUNC(ystring&, GetId, m_sId);
	virtual GET_FUNC_CONST(ystring&, GetId, m_sId);
	virtual GET_FUNC(ystring&, GetClassName, TNReal::sClassName);
	virtual GET_FUNC_CONST(ystring&, GetClassName, TNReal::sClassName);

public:
	virtual void operator>>(base::YCBuffer& rBuffer) const
	{
		//
	}

	virtual void operator<<(base::YCBuffer& rBuffer)
	{
		//
	}

private:
	ystring		m_sId;
};

#define YOBJECT_DECL(_Class)		\
	public:\
		static ystring		sClassName;
#define YOBJECT_IMPL(_Class)		ystring _Class::sClassName = YTOSTRING(_Class);
#define YOBJECT_GETCLASSNAME(_Class)		_Class::sClassName


template<typename TNClass>
TNClass* New(const ystring& rsClass)
{
	if (YOBJECT_GETCLASSNAME(TNClass) == rsClass)
	{
		return new TNClass;
	}
	return YNULL;
}

}

#endif // Y_OBJECT_H
