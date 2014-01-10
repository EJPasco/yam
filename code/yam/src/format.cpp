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

bool YCFormat::operator>>(base::YCBuffer& rBuffer) const
{
	YCBuffer oDataBuffer;
	oDataBuffer.Begin();
	oDataBuffer.GetId() = GetId();
	oDataBuffer.GetClassName() = GetClassName();

	oDataBuffer << GetBound();
	oDataBuffer.Write(sizeof(ycolor) * GetBound().Size.X * GetBound().Size.Y, (ybuffptr)GetColorData());
	oDataBuffer.End();

	rBuffer << (const YIBuffer*)&oDataBuffer;
	return true;
}

bool YCFormat::operator<<(base::YCBuffer& rBuffer)
{
	rBuffer.Begin();

	ystring sId = "";
	ystring sClass = "";
	ybuffsize iBufferSize = 0;
	rBuffer.ReadHead(sId, sClass, iBufferSize);
	if (YOBJECT_GETCLASSNAME(YCFormat) != sClass)
	{
		return false;
	}

	GetId() = sId;

	YRect2D stBound;
	rBuffer >> stBound;

	yint32 iSize = stBound.Size.X * stBound.Size.Y;
	ycolorptr pColorData = YNULL;
	if (0 < iSize)
	{
		pColorData = new ycolor[iSize];
		rBuffer.Read(sizeof(ycolor) * iSize, (ybuffptr)pColorData);
	}
	SetBoundAndColorData(stBound, pColorData);
	if (YNULL != pColorData)
	{
		delete[] pColorData;
		pColorData = YNULL;
	}
	return true;
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

	if (0 < riSize)
	{
		m_pColorData = new ycolor[riSize];
		::memcpy(m_pColorData, rpColorData, sizeof(ycolor) * riSize);
	}
}

}}
