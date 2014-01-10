#ifndef Y_BUFFER_H
#define Y_BUFFER_H

#include "common.h"

#include "tree.h"

namespace yam{ namespace base{

class YIBuffer : public YITree<YIBuffer>
{
public:
	virtual ~YIBuffer() { ; }

public:
	virtual GET_DECL_CONST(ybuffsize&, GetSize) = 0;
	virtual GET_DECL_CONST(ybuffptr&, GetData) = 0;

public:
	virtual void New(const ybuffsize& riSize) = 0;
	virtual YIBuffer& Begin() = 0;
	virtual YIBuffer& Jump(const ybuffpos& riOffset) = 0;
	virtual void End() = 0;
	virtual bool Write(const ybuffsize& riSize, const ybuffptr& rpSrc) = 0;
	virtual bool Read(const ybuffsize& riSize, const ybuffptr& rpDst) = 0;
	virtual bool WriteHead(const ystring& rsId, const ystring& rsClass, const ybuffsize& riSize) = 0;
	virtual bool ReadHead(ystring& rsId, ystring& rsClass, ybuffsize& riSize) = 0;
	virtual YIBuffer& Clear() = 0;

public:
	virtual YIBuffer& operator<<(const YIBuffer* const& rpData) = 0;
	virtual YIBuffer& operator>>(YIBuffer*& rpData) = 0;
};

template<typename TNBase, typename TNReal>
class YTBuffer : public YTTree<TNBase, YIBuffer, TNReal>
{
public:
	YTBuffer() : m_iSize(0), m_pData(YNULL) { ; }
	virtual ~YTBuffer() { ; }

public:
	virtual GET_FUNC_CONST(ybuffsize&, GetSize, m_iSize);

public:

protected:
	ybuffsize		m_iSize;
	ybuffptr		m_pData;
};

class YCBuffer : public YTBuffer<YIBuffer, YCBuffer>
{
	YOBJECT_DECL(YCBuffer);

public:
	YCBuffer();
	virtual ~YCBuffer();

public:
	template<typename TNType>
	YIBuffer& operator<<(const TNType& rData)
	{
		Write(sizeof(TNType), (ybuffptr)&rData);
		return *this;
	}

	template<typename TNType>
	YIBuffer& operator>>(TNType& rData)
	{
		if (0 >= m_iSize || m_iSize <= m_iPosCurrent)
		{
			return *this;
		}
		Read(sizeof(TNType), (ybuffptr)&rData);
		return *this;
	}

	YIBuffer& operator<<(const ystring& rData);
	YIBuffer& operator>>(ystring& rData);

public:
	virtual GET_DECL_CONST(ybuffptr&, GetData);

public:
	virtual void New(const ybuffsize& riSize);
	virtual YIBuffer& Begin();
	virtual YIBuffer& Jump(const ybuffpos& riOffset);
	virtual void End();
	virtual bool Write(const ybuffsize& riSize, const ybuffptr& rpSrc);
	virtual bool Read(const ybuffsize& riSize, const ybuffptr& rpDst);
	virtual bool WriteHead(const ystring& rsId, const ystring& rsClass, const ybuffsize& riSize);
	virtual bool ReadHead(ystring& rsId, ystring& rsClass, ybuffsize& riSize);
	virtual YIBuffer& Clear();

protected:
	void Merge();

public:
	virtual YIBuffer& operator<<(const YIBuffer* const& rpData);
	virtual YIBuffer& operator>>(YIBuffer*& rpData);

protected:
	template<typename TNItem>
	YIBuffer& operator<<(const base::YITree<TNItem>* const& rpData)
	{
		// write the next
		const TNItem* pNext = rpData->GetNext();
		ybool bHasNext = YNULL != pNext;
		*this << bHasNext;
		if (bHasNext)
		{
			*this << pNext;
		}

		// write the children
		const TNItem* pChildren = rpData->GetChildren();
		ybool bHasChildren = YNULL != pChildren;
		*this << bHasChildren;
		if (bHasChildren)
		{
			*this << pChildren;
		}
		return *this;
	}

	template<typename TNItem>
	YIBuffer& operator>>(base::YITree<TNItem>*& rpData)
	{
		assert(YNULL != rpData);
		if (0 >= m_iSize || m_iSize <= m_iPosCurrent)
		{
			return *this;
		}
		ybool bHasNext = false;
		*this >> bHasNext;
		if (bHasNext)
		{
			TNItem* pNext = YNULL;
			*this >> pNext;
			rpData->AddNext(pNext);
		}

		ybool bHasChildren = false;
		*this >> bHasChildren;
		if (bHasChildren)
		{
			TNItem* pChildren = YNULL;
			*this >> pChildren;
			rpData->AddChild(pChildren);
		}
		return *this;
	}

private:
	yvbuffer		m_vBufferSeg;
	ybuffpos		m_iPosCurrent;
};

}}

#endif // Y_BUFFER_H
