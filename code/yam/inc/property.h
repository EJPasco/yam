#ifndef Y_PROPERTY_H
#define Y_PROPERTY_H

#include "common.h"

#include "object.h"
#include "tree.h"

namespace yam{ namespace base{

class YIProperty : public YITree
{
public:
	virtual ~YIProperty() { ; }

public:
	virtual GET_DECL(ystring&, GetValue) = 0;
	virtual GET_DECL_CONST(ystring&, GetValue) = 0;

public:
	virtual ybool FromString(const ystring& rsValue) = 0;
	virtual ybool ToString(ystring& rsValue) const = 0;
	virtual ybool FromInt32(const yint32& rfValue) = 0;
	virtual ybool ToInt32(yint32& rfValue) const = 0;
	virtual ybool FromFloat32(const yfloat32& rfValue) = 0;
	virtual ybool ToFloat32(yfloat32& rfValue) const = 0;
	virtual ybool FromRect2D(const YRect2D& rstValue) = 0;
	virtual ybool ToRect2D(YRect2D& rstValue) const = 0;
};

template<typename TNBase, typename TNReal>
class YTProperty : public YTTree<TNBase, TNReal>
{
public:
	YTProperty() : m_sValue("") { ; }
	virtual ~YTProperty() { ; }

public:
	virtual GET_FUNC(ystring&, GetValue, m_sValue);
	virtual GET_FUNC_CONST(ystring&, GetValue, m_sValue);

private:
	ystring		m_sValue;
};

class YCProperty : public YTProperty<YIProperty, YCProperty>
{
	YOBJECT_DECL(YCProperty);

public:
	YCProperty();
	virtual ~YCProperty();

public:
	virtual ybool operator>>(YCBuffer& rBuffer) const;
	virtual ybool operator<<(YCBuffer& rBuffer);

public:
	virtual ybool FromString(const ystring& rsValue);
	virtual ybool ToString(ystring& rsValue) const;
	virtual ybool FromInt32(const yint32& rfValue);
	virtual ybool ToInt32(yint32& rfValue) const;
	virtual ybool FromFloat32(const yfloat32& rfValue);
	virtual ybool ToFloat32(yfloat32& rfValue) const;
	virtual ybool FromRect2D(const YRect2D& rstValue);
	virtual ybool ToRect2D(YRect2D& rstValue) const;
};

}}

#endif // Y_PROPERTY_H
