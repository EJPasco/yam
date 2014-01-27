#ifndef Y_PROPERTY_H
#define Y_PROPERTY_H

#include "common.h"

#include "object.h"
#include "tree.h"
#include "buffer.h"

namespace yam{ namespace base{

class YIProperty : public YITree
{
public:
	virtual ~YIProperty() { ; }

public:
	virtual GET_DECL(YCBuffer&, GetValue) = 0;
	virtual GET_DECL_CONST(YCBuffer&, GetValue) = 0;

public:
	virtual ybool FromString(const ystring& rsValue) = 0;
	virtual ybool ToString(ystring& rsValue) const = 0;
	virtual ybool FromInt32(const yint32& rfValue) = 0;
	virtual ybool ToInt32(yint32& rfValue) const = 0;
	virtual ybool FromFloat32(const yfloat32& rfValue) = 0;
	virtual ybool ToFloat32(yfloat32& rfValue) const = 0;
	virtual ybool FromRect2D(const YRect2D& rstValue) = 0;
	virtual ybool ToRect2D(YRect2D& rstValue) const = 0;
	virtual ybool FromBuffer(const YCBuffer& roValue) = 0;
	virtual ybool ToBuffer(YCBuffer& roValue) const = 0;
};

template<typename TNBase, typename TNReal>
class YTProperty : public YTTree<TNBase, TNReal>
{
public:
	YTProperty() { ; }
	virtual ~YTProperty() { ; }

public:
	virtual GET_FUNC(YCBuffer&, GetValue, m_oValue);
	virtual GET_FUNC_CONST(YCBuffer&, GetValue, m_oValue);

private:
	YCBuffer	m_oValue;
};

class YCProperty : public YTProperty<YIProperty, YCProperty>
{
	typedef YTProperty<YIProperty, YCProperty>		super;

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
	virtual ybool FromBuffer(const YCBuffer& roValue);
	virtual ybool ToBuffer(YCBuffer& roValue) const;
};

}}

#endif // Y_PROPERTY_H
