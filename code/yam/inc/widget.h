#ifndef Y_WIDGET_H
#define Y_WIDGET_H

#include "common.h"

#include "tree.h"

namespace yam{ namespace base{

class YIWidget : public YITree<YIWidget>
{
public:
	virtual ~YIWidget() { ; }

public:
	virtual GET_DECL(YRect2D&, GetBound) = 0;
	virtual GET_DECL_CONST(YRect2D&, GetBound) = 0;
	virtual GET_DECL(ylayerweight&, GetLayerWeight) = 0;
	virtual GET_DECL_CONST(ylayerweight&, GetLayerWeight) = 0;
};

template<typename TNBase, typename TNReal>
class YTWidget : public YTTree<TNBase, YIWidget, TNReal>
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

private:
};

}}

#endif // Y_WIDGET_H