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
    virtual YITree* AddNext(YITree* pChild) = 0;
    // caution: don't call this directly
    virtual YITree* AddChild(YITree* pChild) = 0;
    virtual void Clear() = 0;
    virtual yint32 GetCountOfNext() const = 0;
    virtual yint32 GetCountOfChildren() const = 0;
    virtual YITree* Find(const ystring& rsId) const = 0;
    virtual YITree* Find(const std::vector<ystring>& rvsId) const = 0;
    virtual YITree* FindNext(const ystring& rsId) const = 0;
    virtual YITree* FindChild(const ystring& rsId) const = 0;
};

template<typename TNBase, typename TNReal>
class YTTree : public YTObject<TNBase, TNReal>
{
public:
    YTTree() :m_pParent(YNULL), m_pNext(YNULL), m_pChildren(YNULL) { ; }
    virtual ~YTTree()
    {
        m_pParent = YNULL;
        Clear();
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
        while (YNULL != pNext)
        {
            pNext->GetParent() = rpParent;
            pNext = pNext->GetNext();
        }
    }

    virtual YITree* AddNext(YITree* pNext)
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
        return pNext;
    }

    virtual YITree* AddChild(YITree* pChild)
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
        return pChild;
    }

    virtual void Clear()
    {
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

    virtual yint32 GetCountOfNext() const
    {
        yint32 iCount = 0;
        const YITree* pTree = m_pNext;
        while (YNULL != pTree)
        {
            ++iCount;
            pTree = pTree->GetNext();
        }
        return iCount;
    }

    virtual yint32 GetCountOfChildren() const
    {
        return (YNULL == m_pChildren) ? 0 : (1 + m_pChildren->GetCountOfNext());
    }

    virtual YITree* Find(const ystring& rsId) const
    {
        if (YNULL != m_pNext)
        {
            if (rsId == m_pNext->GetId())
            {
                return m_pNext;
            }
            else
            {
                YITree* pFind = m_pNext->Find(rsId);
                if (YNULL != pFind)
                {
                    return pFind;
                }
            }
        }
        if (YNULL != m_pChildren)
        {
            if (rsId == m_pChildren->GetId())
            {
                return m_pChildren;
            }
            else
            {
                YITree* pFind = m_pChildren->Find(rsId);
                if (YNULL != pFind)
                {
                    return pFind;
                }
            }
        }
        return YNULL;
    }

    template<typename TNOutput>
    TNOutput* Find(const ystring& rsId) const
    {
        YITree* pFind = Find(rsId);
        if (YNULL == pFind || YOBJECT_GETCLASSNAME(TNOutput) != pFind->GetClassName())
        {
            return NULL;
        }
        return (TNOutput*)pFind;
    }

    virtual YITree* Find(const std::vector<ystring>& rvsId) const
    {
        YITree* pFind = YNULL;
        std::vector<ystring>::const_iterator cit = rvsId.begin();
        std::vector<ystring>::const_iterator citEnd = rvsId.end();
        for (; cit != citEnd; ++cit)
        {
            if (YNULL == pFind)
            {
                pFind = FindChild(*cit);
            }
            else
            {
                pFind = pFind->FindChild(*cit);
            }
            if (YNULL == pFind)
            {
                break;
            }
            
        }
        return pFind;
    }

    template<typename TNOutput>
    TNOutput* Find(const std::vector<ystring>& rvsId) const
    {
        YITree* pFind = Find(rvsId);
        if (YNULL == pFind || YOBJECT_GETCLASSNAME(TNOutput) != pFind->GetClassName())
        {
            return NULL;
        }
        return (TNOutput*)pFind;
    }

    virtual YITree* FindNext(const ystring& rsId) const
    {
        if (NULL == m_pNext)
        {
            return YNULL;
        }
        if (rsId == m_pNext->GetId())
        {
            return m_pNext;
        }
        return m_pNext->FindNext(rsId);
    }

    template<typename TNOutput>
    TNOutput* FindNext(const ystring& rsId) const
    {
        YITree* pFind = FindNext(rsId);
        if (YNULL == pFind || YOBJECT_GETCLASSNAME(TNOutput) != pFind->GetClassName())
        {
            return NULL;
        }
        return (TNOutput*)pFind;
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
        else
        {
            return m_pChildren->FindNext(rsId);
        }
        return YNULL;
    }

    template<typename TNOutput>
    TNOutput* FindChild(const ystring& rsId) const
    {
        YITree* pFind = FindChild(rsId);
        if (YNULL == pFind || YOBJECT_GETCLASSNAME(TNOutput) != pFind->GetClassName())
        {
            return NULL;
        }
        return (TNOutput*)pFind;
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
    YITree*        m_pParent;
    YITree*        m_pNext;
    YITree*        m_pChildren;
};

class YCTree : public YTTree<YITree, YCTree>
{
    typedef YTTree<YITree, YCTree>        super;
    YOBJECT_DECL(YCTree);

public:
    YCTree();
    virtual ~YCTree();

public:
    //
};

}}

#endif // Y_TREE_H
