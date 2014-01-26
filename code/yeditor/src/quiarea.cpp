#include "quiarea.h"

#include "yrectpacker.h"
#include "yconverter.h"

#include <QtWidgets/QPushButton>
#include <QtGui/QtEvents>
#include <QtCore/QTime>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLayoutItem>
#include <QtGui/QPainter>

YCQUiArea::YCQUiArea(QWidget* parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
	: QFrame(parent, f)
	, m_bPressed(false)
	, m_bGrabable(true)
{
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

void YCQUiArea::onClickedReset()
{
	MoveChildItem(QPointF() - m_oPosOffset);

	// all items were moved
	m_oPosOffset *= 0.0f;
}

void YCQUiArea::showEvent(QShowEvent* pEvent)
{
	__super::showEvent(pEvent);
	visibilityChanged(isVisible());
}

void YCQUiArea::hideEvent(QHideEvent* pEvent)
{
	__super::hideEvent(pEvent);
	visibilityChanged(isVisible());
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

void YCQUiArea::mouseMoveEvent(QMouseEvent* pEvent)
{
	if (!m_bPressed)
	{
		return;
	}
	QPointF oOffset = pEvent->screenPos() - m_oPosMousePressStart;
	m_oPosMousePressStart = pEvent->screenPos();

	MoveChildItem(oOffset);
	m_oPosOffset += oOffset;
}

void YCQUiArea::setGrabable(const bool& rbGrabable)
{
	m_bGrabable = rbGrabable;
}

void YCQUiArea::setSelected(const YCQUiItem* const& rpSelectedItem)
{
	yvuiitemptr::iterator it = m_vItemPtr.begin();
	yvuiitemptr::iterator itEnd = m_vItemPtr.end();
	for (; it != itEnd; ++it)
	{
		YCQUiItem*& rpItem = *it;
		if (NULL == rpItem)
		{
			continue;
		}
		if (rpItem == rpSelectedItem)
		{
			rpItem->setSelected(true);
			rpItem->raise();
		}
		else
		{
			rpItem->setSelected(false);
		}
	}
}

YCQUiItem* YCQUiArea::addChildItem(const yam::base::YIFormat* pFormat)
{
	if (YNULL == pFormat->GetColorData())
	{
		return NULL;
	}
	YCQUiItem* pNewItem = new YCQUiItem(this);
	pNewItem->setGrabable(m_bGrabable);
	pNewItem->setFormat(pFormat);
	pNewItem->show();

	m_vItemPtr.push_back(pNewItem);

	return pNewItem;
}

YCQUiItem* YCQUiArea::addChildItem(const yam::base::YIWidget* pWidget)
{
	YCQUiItem* pNewItem = new YCQUiItem(this);
	pNewItem->setGrabable(m_bGrabable);
	pNewItem->setWidget(pWidget);
	pNewItem->show();

	m_vItemPtr.push_back(pNewItem);
	return pNewItem;
}

void YCQUiArea::clearChildrenItem()
{
	yvuiitemptr::iterator it = m_vItemPtr.begin();
	yvuiitemptr::iterator itEnd = m_vItemPtr.end();
	for (; it != itEnd; ++it)
	{
		delete *it;
	}
	m_vItemPtr.clear();
}

void YCQUiArea::toTiled()
{
	yam::yvvec2d vSize;
	yam::YVec2D stSize;
	yam::yvrect vRect;

	yvuiitemptr::iterator it = m_vItemPtr.begin();
	yvuiitemptr::iterator itEnd = m_vItemPtr.end();
	for (; it != itEnd; ++it)
	{
		YCQUiItem*& rpUiItem = *it;
		vSize.push_back(YCConverter::Instance().Convert(rpUiItem->size()));
	}

	stSize.X = 0;
	stSize.Y = 0;
	YCRectPacker::Instance().Do(vSize, stSize, vRect);
	yam::YRect2D stBound = YCConverter::Instance().Merge(vRect);

	if (vRect.size() != m_vItemPtr.size())
	{
		return;
	}

	for (size_t i = 0; i < m_vItemPtr.size(); ++i)
	{
		YCQUiItem*& rpUiItem = m_vItemPtr[i];
		yam::YRect2D stRect2D;
		if (!FindAndDelete(vRect, YCConverter::Instance().Convert(rpUiItem->size()), stRect2D))
		{
			continue;
		}
		rpUiItem->move(stRect2D.Pos.X, stRect2D.Pos.Y);
	}
	vRect.clear();

	// all items were moved
	m_oPosOffset *= 0.0f;
}

bool YCQUiArea::FindAndDelete(yam::yvrect& rvRect2D, const yam::YVec2D& rstVec2D, yam::YRect2D& rstRect2D) const
{
	yam::yvrect::iterator it = rvRect2D.begin();
	yam::yvrect::iterator itEnd = rvRect2D.end();
	for (; it != itEnd; ++it)
	{
		rstRect2D = *it;
		if (rstRect2D.Size.X != rstVec2D.X || rstRect2D.Size.Y != rstVec2D.Y)
		{
			continue;
		}
		rvRect2D.erase(it);
		return true;
	}
	return false;
}

void YCQUiArea::MoveChildItem(const QPointF& rOffsetF)
{
	yvuiitemptr::iterator it = m_vItemPtr.begin();
	yvuiitemptr::iterator itEnd = m_vItemPtr.end();
	for (; it != itEnd; ++it)
	{
		YCQUiItem*& rpItem = *it;
		if (NULL == rpItem)
		{
			continue;
		}
		rpItem->move(rpItem->pos() + rOffsetF.toPoint());
	}
}
