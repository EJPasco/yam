#include "quiarea.h"

#include <QtWidgets/QPushButton>
#include <QtGui/QtEvents>
#include <QtCore/QTime>

#include "GuillotineBinPack.h"
#include "MaxRectsBinPack.h"

YCQUiArea::YCQUiArea(QWidget* parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
	: QFrame(parent, f)
	, m_bPressed(false)
{
	qsrand(QTime::currentTime().msec());

	// for test
	rbp::GuillotineBinPack binPack(1024, 1024);
	std::vector<rbp::RectSize> vRectList;
	rbp::RectSize stSize;
	int iMax = qrand() % 50 + 1;
	int iMaxS = 1024 / iMax;
	for (int i = 0; i < iMax; ++i)
	{
		stSize.width = qrand() % iMaxS; stSize.height = qrand() % iMaxS; vRectList.push_back(stSize);
	}

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
		int iColor = 0xff000000 | qrand();
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
