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
	virtual void SetParent(YITree* const& rpParent) = 0;
	// caution: don't call this directly
	virtual void AddNext(YITree* pChild) = 0;
	// caution: don't call this directly
	virtual void AddChild(YITree* pChild) = 0;
	virtual const yint32 &GetCountOfChildren() const = 0;
	virtual YITree* FindNext(const ystring& rsId) const = 0;
	virtual YITree* FindChild(const ystring& rsId) const = 0;
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
			rBuffer.In(m_pNext->GetClassName());
			*m_pNext >> rBuffer;
		}

		const ybool bHasChildren = YNULL != m_pChildren;
		rBuffer.In(bHasChildren);
		if (bHasChildren)
		{
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
			ystring sClassName = "";
			rBuffer.Out(sClassName);
			YITree* pNext = NewTree(sClassName);
			if (YNULL != pNext)
			{
				*pNext << rBuffer;
				AddNext(pNext);
			}
		}

		ybool bHasChildren = YFALSE;
		rBuffer.Out(bHasChildren);
		if (bHasChildren)
		{
			ystring sClassName = "";
			rBuffer.Out(sClassName);
			YITree* pChildren = NewTree(sClassName);
			if (YNULL != pChildren)
			{
				*pChildren << rBuffer;
				AddChild(pChildren);
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
	virtual void SetParent(YITree* const& rpParent)
	{
		YITree* pNext = this;
		while (YNULL != pNext->GetNext())
		{
			pNext->GetParent() = rpParent;
			pNext = pNext->GetNext();
		}
	}

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
				pNextTemp = pNextTemp->GetNext();
			}
			pNextTemp->GetNext() = pNext;
		}
	}

	virtual void AddChild(YITree* pChild)
	{
		assert(YNULL != pChild);

		pChild->SetParent(this);

		if (YNULL == m_pChildren)
		{
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

	virtual YITree* FindNext(const ystring& rsId) const
	{
		YITree* pNext = m_pNext;
		while (YNULL != pNext)
		{
			if (rsId == pNext->GetId())
			{
				return pNext;
			}
			pNext = pNext->GetNext();
		}
		return pNext;
	}

	virtual YITree* FindChild(const ystring& rsId) const 
	{
		if (YNULL == m_pChildren)
		{
			return YNULL;
		}
		if (rsId == m_pChildren->GetId())
		{
			return m_pChildren;
		}
		return m_pChildren->FindNext(rsId);
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

class YCTree : public YTTree<YITree, YCTree>
{
	YOBJECT_DECL(YCTree);

public:
	YCTree();
	virtual ~YCTree();

public:
	//
};

}}

#endif // Y_TREE_H
