#include "quiitem.h"

#include "quiarea.h"
#include <QtGui/QtEvents>
#include <QtGui/QPainter>
#include <QtWidgets/QPushButton>

YCQUiItem::YCQUiItem(YCQUiArea* parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
	: QWidget(parent, f)
	, m_pUiArea(parent)
	, m_bPressed(false)
{
	move(0, 0);
	setFixedSize(100, 100);

	m_pPixmap = new QPixmap(size());
	m_pPixmap->fill(Qt::yellow);
	//
}

YCQUiItem::~YCQUiItem()
{
	if (NULL != m_pPixmap)
	{
		delete m_pPixmap;
		m_pPixmap = NULL;
	}
	//
}

void YCQUiItem::mousePressEvent(QMouseEvent* pEvent)
{
	qDebug("YCQUiItem::mousePressEvent");

	m_bPressed = true;
	m_oPosMousePressStart = pEvent->screenPos();
}

void YCQUiItem::mouseReleaseEvent(QMouseEvent* pEvent)
{
	//
	m_bPressed = false;
}

void YCQUiItem::mouseDoubleClickEvent(QMouseEvent* pEvent)
{
	//
	m_bPressed = false;
}

void YCQUiItem::mouseMoveEvent(QMouseEvent* pEvent)
{
	if (!m_bPressed)
	{
		return;
	}
	QPointF oOffset = pEvent->screenPos() - m_oPosMousePressStart;
	move(pos() + oOffset.toPoint());
	m_oPosMousePressStart = pEvent->screenPos();
	//
}

void YCQUiItem::paintEvent(QPaintEvent* pEvent)
{
	qDebug("YCQUiItem::paintEvent");

	QPainter oPainter(this);
	oPainter.drawPixmap(0, 0, *m_pPixmap);
	//
}
