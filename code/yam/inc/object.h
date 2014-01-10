#ifndef Y_OBJECT_H
#define Y_OBJECT_H

#include "common.h"

namespace yam{

namespace base{

class YCBuffer;

}

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
	virtual bool operator>>(base::YCBuffer& rBuffer) const = 0;
	virtual bool operator<<(base::YCBuffer& rBuffer) = 0;
};

template<typename TNBase, typename TNReal>
class YTObject : public TNBase
{
public:
	YTObject() : m_sId(""), m_sClassName(YOBJECT_GETCLASSNAME(TNReal)) { ; }
	virtual ~YTObject() { ; }

public:
	virtual GET_FUNC(ystring&, GetId, m_sId);
	virtual GET_FUNC_CONST(ystring&, GetId, m_sId);
	virtual GET_FUNC(ystring&, GetClassName, m_sClassName);
	virtual GET_FUNC_CONST(ystring&, GetClassName, m_sClassName);

public:
	virtual bool operator>>(base::YCBuffer& rBuffer) const
	{
		//
		return false;
	}

	virtual bool operator<<(base::YCBuffer& rBuffer)
	{
		//
		return false;
	}

private:
	ystring		m_sId;
	ystring		m_sClassName;
};

}

#endif // Y_OBJECT_H
