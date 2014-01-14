#ifndef Y_WIDGET_H
#define Y_WIDGET_H

#include "common.h"

#include "tree.h"

#include "property.h"

namespace yam{ namespace base{

class YIWidget : public YITree
{
public:
	virtual ~YIWidget() { ; }

public:
	virtual GET_DECL(YRect2D&, GetBound) = 0;
	virtual GET_DECL_CONST(YRect2D&, GetBound) = 0;
	virtual GET_DECL(ylayerweight&, GetLayerWeight) = 0;
	virtual GET_DECL_CONST(ylayerweight&, GetLayerWeight) = 0;

public:
	virtual ybool operator>>(YCProperty& rProperty) const = 0;
	virtual ybool operator<<(YCProperty& rProperty) = 0;
};

template<typename TNBase, typename TNReal>
class YTWidget : public YTTree<TNBase, TNReal>
{
public:
	YTWidget() : m_iLayerWeight(0) { ; }
	virtual ~YTWidget() { ; }

public:
	virtual GET_FUNC(YRect2D&, GetBound, m_stBound);
	virtual GET_FUNC_CONST(YRect2D&, GetBound, m_stBound);
	virtual GET_FUNC(ylayerweight&, GetLayerWeight, m_iLayerWeight);
	virtual GET_FUNC_CONST(ylayerweight&, GetLayerWeight, m_iLayerWeight);

protected:
	YRect2D				m_stBound;
	ylayerweight		m_iLayerWeight;
};

class YCWidget : public YTWidget<YIWidget, YCWidget>
{
	YOBJECT_DECL(YCWidget);

public:
	YCWidget();
	virtual ~YCWidget();

public:
	virtual ybool operator>>(YCBuffer& rProperty) const;
	virtual ybool operator<<(YCBuffer& rProperty);

public:
	virtual ybool operator>>(YCProperty& rProperty) const;
	virtual ybool operator<<(YCProperty& rProperty);
};

}}

#endif // Y_WIDGET_H