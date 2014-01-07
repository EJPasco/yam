#ifndef Y_WIDGET_H
#define Y_WIDGET_H

#include "common.h"

namespace yam{ namespace base{

typedef int			pint32;

template<typename TNTree>
class IYTree
{
public:
	virtual ~IYTree() { ; }

public:
	virtual GET_DECL(TNTree*&, GetParent) = 0;
	virtual GET_DECL_CONST(TNTree*, GetParent) = 0;
	virtual GET_DECL(TNTree*&, GetNext) = 0;
	virtual GET_DECL_CONST(TNTree*, GetNext) = 0;
	virtual GET_DECL(TNTree*&, GetChildren) = 0;
	virtual GET_DECL_CONST(TNTree*, GetChildren) = 0;

public:
	virtual void SetParent(TNTree* pParent) = 0;
	virtual void SetNext(TNTree* pNext) = 0;
	virtual void AddChild(TNTree* pChild) = 0;
	virtual const pint32 &GetCountOfChildren() const = 0;
};

template<typename TNBase, typename TNTree>
class TYTree : public TNBase
{
public:
	TYTree() :m_pParent(NULL), m_pNext(NULL), m_pChildren(NULL), m_iCountOfChildren(0) { ; }
	virtual ~TYTree()
	{
		m_pParent = NULL;
		if (NULL != m_pChildren)
		{
			delete m_pChildren;
			m_pChildren = NULL;
		}
		TNTree* pTree = m_pNext;
		while (NULL != pTree)
		{
			TNTree* pTreeNext = pTree->GetNext();
			delete pTree;
			pTree = pTreeNext;
		}
	}

public:
	virtual GET_FUNC(TNTree*&, GetParent, m_pParent);
	virtual GET_FUNC_CONST(TNTree*, GetParent, m_pParent);
	virtual GET_FUNC(TNTree*&, GetNext, m_pNext);
	virtual GET_FUNC_CONST(TNTree*, GetNext, m_pNext);
	virtual GET_FUNC(TNTree*&, GetChildren, m_pChildren);
	virtual GET_FUNC_CONST(TNTree*, GetChildren, m_pChildren);

public:
	virtual void SetParent(TNTree* pParent)
	{
		m_pParent = pParent;
	}

	virtual void SetNext(TNTree* pNext)
	{
		m_pNext = pNext;;
	}

	virtual void AddChild(TNTree* pChild)
	{
		assert(NULL != pChild);
		if (NULL == m_pChildren)
		{
			m_pChildren = pChild;
		}
		else
		{
			TNTree* pNext = m_pChildren;
			while (NULL != pNext->GetNext())
			{
				pNext = pNext->GetNext();
			}
			pNext->SetNext(pChild);
		}
		++m_iCountOfChildren;
	}

	virtual const pint32 &GetCountOfChildren() const
	{
		return m_iCountOfChildren;
	}

public:
	template<typename TName>
	TName* NewChild()
	{
		TName* pChild = new TName;
		pChild->SetParent(this);
		AddChild(pChild);
		return pChild;
	}

private:
	TNTree*		m_pParent;
	TNTree*		m_pNext;
	TNTree*		m_pChildren;
	pint32		m_iCountOfChildren;
};

class IYWidget : public IYTree<IYWidget>
{
public:
	virtual ~IYWidget() { ; }

public:
};

template<typename TNBase>
class TYWidget : public TYTree<TNBase, IYWidget>
{
public:
	TYWidget() { ; }
	virtual ~TYWidget() { ; }

public:

private:
};

class CYWidget : public TYWidget<IYWidget>
{
public:
	CYWidget();
	virtual ~CYWidget();

public:
};

}}

#endif // Y_WIDGET_H