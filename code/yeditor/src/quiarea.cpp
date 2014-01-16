#include "quiarea.h"

#include <QtWidgets/QPushButton>
#include <QtGui/QtEvents>

YCQUiArea::YCQUiArea(QWidget* parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
	: QFrame(parent, f)
	, m_bPressed(false)
{
	// for test
	new YCQUiItem(this);
	//
}

YCQUiArea::YCQUiArea(QFramePrivate &dd, QWidget* parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
	: QFrame(dd, parent, f)
{
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
	//
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
