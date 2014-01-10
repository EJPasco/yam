#ifndef Y_TREE_H
#define Y_TREE_H

#include "common.h"

#include "object.h"

namespace yam{ namespace base{

template<typename TNItem>
class YITree : public YIObject<TNItem>
{
public:
	virtual ~YITree() { ; }

public:
	virtual GET_DECL(TNItem*&, GetParent) = 0;
	virtual GET_DECL_CONST(TNItem*, GetParent) = 0;
	virtual GET_DECL(TNItem*&, GetNext) = 0;
	virtual GET_DECL_CONST(TNItem*, GetNext) = 0;
	virtual GET_DECL(TNItem*&, GetChildren) = 0;
	virtual GET_DECL_CONST(TNItem*, GetChildren) = 0;

public:
	virtual void AddNext(TNItem* pChild) = 0;
	virtual void AddChild(TNItem* pChild) = 0;
	virtual const yint32 &GetCountOfChildren() const = 0;
};

template<typename TNBase, typename TNItem, typename TNReal>
class YTTree : public YTObject<TNBase, TNReal>
{
public:
	YTTree() :m_pParent(YNULL), m_pNext(YNULL), m_pChildren(YNULL), m_iCountOfChildren(0) { ; }
	virtual ~YTTree()
	{
		m_pParent = YNULL;
		if (YNULL != m_pChildren)
		{
			delete m_pChildren;
			m_pChildren = YNULL;
		}
		if (YNULL != m_pNext)
		{
			delete m_pNext;
			m_pNext = YNULL;
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
	virtual void AddNext(TNItem* pNext)
	{
		assert(YNULL != pNext);

		pNext->GetParent() = GetParent();

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
			pNextTemp->GetNext() = pNext;
		}
	}

	virtual void AddChild(TNItem* pChild)
	{
		assert(YNULL != pChild);
		if (YNULL == m_pChildren)
		{
			pChild->GetParent() = this;
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
	TName* NewNext()
	{
		TName* pChild = new TName;
		AddNext(pChild);
		return pChild;
	}

	template<typename TName>
	TName* NewChild()
	{
		TName* pChild = new TName;
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
