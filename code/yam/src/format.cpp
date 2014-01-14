#include "format.h"

#include "buffer.h"

namespace yam{ namespace base{

YOBJECT_IMPL(YCFormat);

YCFormat::YCFormat()
{
	//
}

YCFormat::~YCFormat()
{
	if (YNULL != m_pColorData)
	{
		delete[] m_pColorData;
		m_pColorData = YNULL;
	}
}

bool YCFormat::operator>>(YCBuffer& rBuffer) const
{
	YCBuffer buf;
	buf.GetId() = GetId();
	buf.GetClassName() = GetClassName();
	buf.Begin();
	const YRect2D& stBound = GetBound();
	buf.In(stBound);
	buf.Write(sizeof(ycolor) * stBound.Size.X * stBound.Size.Y, (const ybuffptr)GetColorData());
	buf.End();
	buf >> rBuffer;

	return __super::operator >>(rBuffer);
}

bool YCFormat::operator<<(YCBuffer& rBuffer)
{
	YCBuffer buf;
	buf << rBuffer;

	if (buf.GetClassName() != GetClassName())
	{
		return false;
	}
	GetId() = buf.GetId();
	YRect2D stBound;
	buf.Out(stBound);
	ysize iSize = stBound.Size.X * stBound.Size.Y;
	ycolorptr pColorData = YNULL;
	if (0 < iSize)
	{
		pColorData = new ycolor[iSize];
	}
	
	buf.Read(sizeof(ycolor) * iSize, (const ybuffptr)pColorData);
	SetBoundAndColorData(stBound, pColorData);
	if (YNULL != pColorData)
	{
		delete[] pColorData;
	}

	return __super::operator <<(rBuffer);
}

void YCFormat::SetBoundAndColorData(const YRect2D& rstBound, ycolorptr pColorData)
{
	m_stBound = rstBound;
	yint32 iSize = rstBound.Size.X * rstBound.Size.Y;
	SetColorData(iSize, pColorData);
}

void YCFormat::SetColorData(const yint32& riSize, const ycolorptr& rpColorData)
{
	if (YNULL != m_pColorData)
	{
		delete[] m_pColorData;
		m_pColorData = YNULL;
	}

	if (0 < riSize && YNULL != rpColorData)
	{
		m_pColorData = new ycolor[riSize];
		::memcpy(m_pColorData, rpColorData, sizeof(ycolor) * riSize);
	}
}

}}
