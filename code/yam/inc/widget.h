#ifndef Y_WIDGET_H
#define Y_WIDGET_H

#include "common.h"
#include "tree.h"

namespace yam{ namespace base{

class IYWidget : public IYTree<IYWidget>
{
public:
	virtual ~IYWidget() { ; }

public:
	virtual ybuffsize SizeOfData() const = 0;

public:
	virtual GET_DECL_CONST(ystring&, GetType) = 0;
	virtual GET_DECL(ystring&, GetId) = 0;
	virtual GET_DECL_CONST(ystring&, GetId) = 0;
	virtual GET_DECL(yrect2d&, GetBound) = 0;
	virtual GET_DECL_CONST(yrect2d&, GetBound) = 0;
	virtual GET_DECL(ylayerweight&, GetLayerWeight) = 0;
	virtual GET_DECL_CONST(ylayerweight&, GetLayerWeight) = 0;
};

template<typename TNBase>
class TYWidget : public TYTree<TNBase, IYWidget>
{
public:
	explicit TYWidget(const ystring& rsType) : m_sType(rsType), m_sId(""), m_iLayerWeight(0) { ; }
	virtual ~TYWidget() { ; }

public:
	virtual ybuffsize SizeOfData() const
	{
		ybuffsize iRes = 0;

		// calculate the size of real data
		iRes += sizeof(yint32);
		iRes += sizeof(yint8) * m_sType.size();
		iRes += sizeof(yint32);
		iRes += sizeof(yint8) * m_sId.size();
		iRes += sizeof(yrect2d);
		iRes += sizeof(ylayerweight);

		// calculate the size of next
		const IYWidget* pNext = GetNext();
		while (YNULL != pNext)
		{
			iRes += pNext->SizeOfData();
			pNext = pNext->GetNext();
		}

		// calculate the size of children
		const IYWidget* pChildren = GetChildren();
		if (YNULL != pChildren)
		{
			iRes += pChildren->SizeOfData();
		}
		return iRes;
	}

public:
	virtual GET_FUNC_CONST(ystring&, GetType, m_sType);
	virtual GET_FUNC(ystring&, GetId, m_sId);
	virtual GET_FUNC_CONST(ystring&, GetId, m_sId);
	virtual GET_FUNC(yrect2d&, GetBound, m_stBound);
	virtual GET_FUNC_CONST(yrect2d&, GetBound, m_stBound);
	virtual GET_FUNC(ylayerweight&, GetLayerWeight, m_iLayerWeight);
	virtual GET_FUNC_CONST(ylayerweight&, GetLayerWeight, m_iLayerWeight);

protected:
	ystring				m_sType;
	ystring				m_sId;
	yrect2d				m_stBound;
	ylayerweight		m_iLayerWeight;
};

class CYWidget : public TYWidget<IYWidget>
{
public:
	SINGLETON_DECL(CYWidget);

public:
	CYWidget();
	virtual ~CYWidget();

public:

private:
};

}}

#endif // Y_WIDGET_H