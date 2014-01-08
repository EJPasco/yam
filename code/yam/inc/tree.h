#ifndef Y_TREE_H
#define Y_TREE_H

#include "common.h"

namespace yam{ namespace base{

template<typename TNItem>
class IYTree
{
public:
	virtual ~IYTree() { ; }

public:
	virtual GET_DECL(TNItem*&, GetParent) = 0;
	virtual GET_DECL_CONST(TNItem*, GetParent) = 0;
	virtual GET_DECL(TNItem*&, GetNext) = 0;
	virtual GET_DECL_CONST(TNItem*, GetNext) = 0;
	virtual GET_DECL(TNItem*&, GetChildren) = 0;
	virtual GET_DECL_CONST(TNItem*, GetChildren) = 0;

public:
	virtual void SetParent(TNItem* pParent) = 0;
	virtual void SetNext(TNItem* pNext) = 0;
	virtual void AddNext(TNItem* pChild) = 0;
	virtual void AddChild(TNItem* pChild) = 0;
	virtual const yint32 &GetCountOfChildren() const = 0;
};

template<typename TNBase, typename TNItem>
class TYTree : public TNBase
{
public:
	TYTree() :m_pParent(YNULL), m_pNext(YNULL), m_pChildren(YNULL), m_iCountOfChildren(0) { ; }
	virtual ~TYTree()
	{
		m_pParent = YNULL;
		if (YNULL != m_pChildren)
		{
			delete m_pChildren;
			m_pChildren = YNULL;
		}
		TNItem* pTree = m_pNext;
		while (YNULL != pTree)
		{
			TNItem* pTreeNext = pTree->GetNext();
			delete pTree;
			pTree = pTreeNext;
		}
	}

public:
	virtual GET_FUNC(TNItem*&, GetParent, m_pParent);
	virtual GET_FUNC_CONST(TNItem*, GetParent, m_pParent);
	virtual GET_FUNC(TNItem*&, GetNext, m_pNext);
	virtual GET_FUNC_CONST(TNItem*, GetNext, m_pNext);
	virtual GET_FUNC(TNItem*&, GetChildren, m_pChildren);
	virtual GET_FUNC_CONST(TNItem*, GetChildren, m_pChildren);

public:
	virtual void SetParent(TNItem* pParent)
	{
		m_pParent = pParent;
	}

	virtual void SetNext(TNItem* pNext)
	{
		m_pNext = pNext;
	}

	virtual void AddNext(TNItem* pNext)
	{
		assert(YNULL != pNext);

		pNext->SetParent(GetParent());

		if (YNULL == m_pNext)
		{
			m_pNext = pNext;
		}
		else
		{
			TNItem* pNextTemp = m_pNext;
			while (YNULL != pNextTemp->GetNext())
			{
				pNext = pNextTemp->GetNext();
			}
			pNextTemp->SetNext(pNext);
		}
	}

	virtual void AddChild(TNItem* pChild)
	{
		assert(YNULL != pChild);
		if (YNULL == m_pChildren)
		{
			pChild->SetParent(this);
			m_pChildren = pChild;
		}
		else
		{
			m_pChildren->AddNext(pChild);
		}
		++m_iCountOfChildren;
	}

	virtual const yint32 &GetCountOfChildren() const
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
	TNItem*		m_pParent;
	TNItem*		m_pNext;
	TNItem*		m_pChildren;
	yint32		m_iCountOfChildren;
};

}}

#endif // Y_TREE_H
