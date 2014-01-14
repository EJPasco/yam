#ifndef Y_TREE_H
#define Y_TREE_H

#include "common.h"

#include "object.h"
#include "buffer.h"

#include "new.h"

namespace yam{ namespace base{

class YITree : public YIObject
{
public:
	virtual ~YITree() { ; }

public:
	virtual GET_DECL(YITree*&, GetParent) = 0;
	virtual GET_DECL_CONST(YITree*, GetParent) = 0;
	virtual GET_DECL(YITree*&, GetNext) = 0;
	virtual GET_DECL_CONST(YITree*, GetNext) = 0;
	virtual GET_DECL(YITree*&, GetChildren) = 0;
	virtual GET_DECL_CONST(YITree*, GetChildren) = 0;

public:
	virtual void AddNext(YITree* pChild) = 0;
	virtual void AddChild(YITree* pChild) = 0;
	virtual const yint32 &GetCountOfChildren() const = 0;
};

template<typename TNBase, typename TNReal>
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
	virtual ybool operator>>(YCBuffer& rBuffer) const
	{
		const ybool bHasNext = YNULL != m_pNext;
		rBuffer.In(bHasNext);
		if (bHasNext)
		{
			rBuffer.In(m_pNext->GetId());
			rBuffer.In(m_pNext->GetClassName());
			*m_pNext >> rBuffer;
		}
		const ybool bHasChildren = YNULL != m_pChildren;
		rBuffer.In(bHasChildren);
		if (bHasChildren)
		{
			rBuffer.In(m_pChildren->GetId());
			rBuffer.In(m_pChildren->GetClassName());
			*m_pChildren >> rBuffer;
		}
		return YTRUE;
	}

	virtual ybool operator<<(YCBuffer& rBuffer)
	{
		ybool bHasNext = YFALSE;
		rBuffer.Out(bHasNext);
		if (bHasNext)
		{
			ystring sId = "";
			rBuffer.Out(sId);
			ystring sClassName = "";
			rBuffer.Out(sClassName);
			m_pNext = NewTree(sClassName);
			if (YNULL != m_pNext)
			{
				*m_pNext << rBuffer;
			}
		}
		ybool bHasChildren = YFALSE;
		rBuffer.Out(bHasChildren);
		if (bHasChildren)
		{
			ystring sId = "";
			rBuffer.Out(sId);
			ystring sClassName = "";
			rBuffer.Out(sClassName);
			m_pChildren = NewTree(sClassName);
			if (YNULL != m_pChildren)
			{
				*m_pChildren << rBuffer;
			}
		}
		return YTRUE;
	}

public:
	virtual GET_FUNC(YITree*&, GetParent, m_pParent);
	virtual GET_FUNC_CONST(YITree*, GetParent, m_pParent);
	virtual GET_FUNC(YITree*&, GetNext, m_pNext);
	virtual GET_FUNC_CONST(YITree*, GetNext, m_pNext);
	virtual GET_FUNC(YITree*&, GetChildren, m_pChildren);
	virtual GET_FUNC_CONST(YITree*, GetChildren, m_pChildren);

public:
	virtual void AddNext(YITree* pNext)
	{
		assert(YNULL != pNext);

		pNext->GetParent() = GetParent();

		if (YNULL == m_pNext)
		{
			m_pNext = pNext;
		}
		else
		{
			YITree* pNextTemp = m_pNext;
			while (YNULL != pNextTemp->GetNext())
			{
				pNext = pNextTemp->GetNext();
			}
			pNextTemp->GetNext() = pNext;
		}
	}

	virtual void AddChild(YITree* pChild)
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
	YITree*		m_pParent;
	YITree*		m_pNext;
	YITree*		m_pChildren;
	yint32		m_iCountOfChildren;
};

}}

#endif // Y_TREE_H
