#include "quiarea.h"

#include <QtWidgets/QPushButton>
#include <QtGui/QtEvents>

#include "GuillotineBinPack.h"
#include "MaxRectsBinPack.h"

YCQUiArea::YCQUiArea(QWidget* parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
	: QFrame(parent, f)
	, m_bPressed(false)
{
	// for test
	rbp::GuillotineBinPack binPack(1024, 1024);
	std::vector<rbp::RectSize> vRectList;
	rbp::RectSize stSize;
	stSize.width = 100; stSize.height = 200; vRectList.push_back(stSize);
	stSize.width = 700; stSize.height = 500; vRectList.push_back(stSize);
	stSize.width = 50; stSize.height = 300; vRectList.push_back(stSize);
	stSize.width = 88; stSize.height = 320; vRectList.push_back(stSize);
	stSize.width = 30; stSize.height = 400; vRectList.push_back(stSize);
	stSize.width = 156; stSize.height = 22; vRectList.push_back(stSize);

	binPack.Insert(vRectList, false, rbp::GuillotineBinPack::RectBestShortSideFit, rbp::GuillotineBinPack::SplitMinimizeArea);
	std::vector<rbp::Rect> vstBound = binPack.GetUsedRectangles();

	std::vector<rbp::Rect>::const_iterator cit = vstBound.begin();
	std::vector<rbp::Rect>::const_iterator citEnd = vstBound.end();
	for (; cit != citEnd; ++cit)
	{
		const rbp::Rect& rstBound = *cit;
		YCQUiItem* pItem = new YCQUiItem(this);
		pItem->move(rstBound.x, rstBound.y);
		pItem->resize(rstBound.width, rstBound.height);
		int iColor = 0xff000000 | std::rand();
		pItem->setColor(iColor);
	}
	//
}

YCQUiArea::YCQUiArea(QFramePrivate &dd, QWidget* parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
	: QFrame(dd, parent, f)
{
	// for test
	//
}

YCQUiArea::~YCQUiArea()
{
	//
}

void YCQUiArea::mousePressEvent(QMouseEvent* pEvent)
{
	m_bPressed = true;
	m_oPosMousePressStart = pEvent->screenPos();
	//
}

void YCQUiArea::mouseReleaseEvent(QMouseEvent* pEvent)
{
	m_bPressed = false;
	//
}

void YCQUiArea::mouseDoubleClickEvent(QMouseEvent* pEvent)
{
	m_bPressed = false;

	const QObjectList& lChildren = this->children();
	QObjectList::const_iterator cit = lChildren.begin();
	QObjectList::const_iterator citEnd = lChildren.end();
	for (; cit != citEnd; ++cit)
	{
		YCQUiItem* pItem = (YCQUiItem*)(*cit);
		pItem->setSelected(false);
	}
}

void YCQUiArea::mouseMoveEvent(QMouseEvent* pEvent)
{
	if (!m_bPressed)
	{
		return;
	}
	QPointF oOffset = pEvent->screenPos() - m_oPosMousePressStart;
	const QObjectList& lChildren = this->children();
	QObjectList::const_iterator cit = lChildren.begin();
	QObjectList::const_iterator citEnd = lChildren.end();
	for (; cit != citEnd; ++cit)
	{
		YCQUiItem* pItem = (YCQUiItem*)(*cit);
		pItem->move(pItem->pos() + oOffset.toPoint());
	}
	m_oPosMousePressStart = pEvent->screenPos();
}

void YCQUiArea::setSelected(const YCQUiItem* const& rpItem)
{
	const QObjectList& lChildren = this->children();
	QObjectList::const_iterator cit = lChildren.begin();
	QObjectList::const_iterator citEnd = lChildren.end();
	for (; cit != citEnd; ++cit)
	{
		YCQUiItem* pItem = (YCQUiItem*)(*cit);
		if (rpItem == pItem)
		{
			continue;
		}
		pItem->setSelected(false);
	}
}
