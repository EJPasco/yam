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
	virtual GET_DECL(yrect2d&, GetBound) = 0;
	virtual GET_DECL_CONST(yrect2d&, GetBound) = 0;
	virtual GET_DECL(ycolorptr&, GetColorData) = 0;
	virtual GET_DECL_CONST(ycolorptr&, GetColorData) = 0;
};

template<typename TNBase>
class TYFormat : public TYTree<TNBase, IYFormat>
{
public:
	TYFormat() : m_sId(""), m_pColor(YNULL) { ; }
	virtual ~TYFormat() { ; }

public:
	virtual GET_FUNC(ystring&, GetId, m_sId);
	virtual GET_FUNC_CONST(ystring&, GetId, m_sId);
	virtual GET_FUNC(yrect2d&, GetBound, m_stBound);
	virtual GET_FUNC_CONST(yrect2d&, GetBound, m_stBound);
	virtual GET_FUNC(ycolorptr&, GetColorData, m_pColorData);
	virtual GET_FUNC_CONST(ycolorptr&, GetColorData, m_pColorData);

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
