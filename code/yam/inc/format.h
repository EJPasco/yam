#ifndef Y_FORMAT_H
#define Y_FORMAT_H

#include "common.h"

#include "tree.h"

namespace yam{ namespace base{

class IYFormat : public IYTree<IYFormat>
{
public:
	virtual ~IYFormat() { ; }

public:
	virtual GET_DECL(ystring&, GetId) = 0;
	virtual GET_DECL_CONST(ystring&, GetId) = 0;
	virtual GET_DECL_CONST(yrect2d&, GetBound) = 0;
	virtual GET_DECL_CONST(ycolorptr&, GetColorData) = 0;
	virtual void SetBoundAndColorData(yrect2d stBound, ycolorptr pColorData) = 0;
};

template<typename TNBase>
class TYFormat : public TYTree<TNBase, IYFormat>
{
public:
	TYFormat() : m_sId(""), m_pColorData(YNULL) { ; }
	virtual ~TYFormat() { ; }

public:
	virtual ybuffsize SizeOfData() const
	{
		ybuffsize iRes = 0;
		iRes += sizeof(yint32);
		iRes += sizeof(yint8) * m_sId.size();
		iRes += sizeof(yrect2d);

		iRes += sizeof(ybool);
		ybool bHasColorData = YNULL == m_pColorData;
		if (bHasColorData)
		{
			iRes += sizeof(ycolorptr) * m_stBound.Size.X * m_stBound.Size.Y;
		}

		iRes += TYTree::SizeOfData();
		return iRes;
	}

public:
	virtual GET_FUNC(ystring&, GetId, m_sId);
	virtual GET_FUNC_CONST(ystring&, GetId, m_sId);
	virtual GET_FUNC_CONST(yrect2d&, GetBound, m_stBound);
	virtual GET_FUNC_CONST(ycolorptr&, GetColorData, m_pColorData);
	virtual void SetBoundAndColorData(yrect2d stBound, ycolorptr pColorData)
	{
		m_stBound = stBound;
		m_pColorData = pColorData;
	}

protected:
	ystring		m_sId;
	yrect2d		m_stBound;
	ycolorptr	m_pColorData;
};

class CYFormat : public IYFormat
{
public:
	CYFormat();
	virtual ~CYFormat();

public:
};

}}

#endif // Y_FORMAT_H
