#include "quiarea.h"

#include <QtWidgets/QPushButton>
#include <QtGui/QtEvents>
#include <QtCore/QTime>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLayoutItem>
#include <QtGui/QPainter>

YCQUiArea::YCQUiArea(QWidget* parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
	: QFrame(parent, f)
	, m_bPressed(false)
	, m_fScale(1.0f)
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

/*void YCQUiArea::paintEvent(QPaintEvent* pEvent)
{
	qDebug("paintEvent %f", m_fScale);
	QPainter oPainter(this);
	oPainter.scale(m_fScale, m_fScale);
	//
}*/

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
	yvuiitemptr::iterator it = m_vItemPtr.begin();
	yvuiitemptr::iterator itEnd = m_vItemPtr.end();
	for (; it != itEnd; ++it)
	{
		YCQUiItem*& rpItem = *it;
		if (NULL == rpItem)
		{
			continue;
		}
		rpItem->move(rpItem->pos() + oOffset.toPoint());
	}
	m_oPosMousePressStart = pEvent->screenPos();
}

#ifndef QT_NO_WHEELEVENT
void YCQUiArea::wheelEvent(QWheelEvent* pEvent)
{
	qDebug("wheelevent %d", pEvent->delta());

	//TODO: too many magic number
	qreal fScale = m_fScale;
	if (0 > pEvent->delta())
	{
		fScale -= 0.05f;
	}
	else
	{
		fScale += 0.05f;
	}
	if (0.1 > fScale || 20.0f < fScale)
	{
		return;
	}
	m_fScale = fScale;

	/*yvuiitemptr::iterator it = m_vItemPtr.begin();
	yvuiitemptr::iterator itEnd = m_vItemPtr.end();
	for (; it != itEnd; ++it)
	{
		YCQUiItem*& rpItem = *it;
		//QPoint rpItem->pos();
		if (NULL == rpItem)
		{
			continue;
		}
		QSize ss = rpItem->size() * m_fScale;
		rpItem->resize(ss);
		rpItem->setScale(m_fScale);
		rpItem->repaint();
	}*/
	//
}
#endif

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

void YCQUiArea::setScale(const qreal& rfScale)
{
	m_fScale = rfScale;
}

YCQUiItem* YCQUiArea::addChildItem(const yam::base::YIFormat*& rpFormat)
{
	if (YNULL == rpFormat->GetColorData())
	{
		return NULL;
	}
	YCQUiItem* pNewItem = new YCQUiItem(this);
	pNewItem->setFormat(rpFormat);
	pNewItem->setScale(m_fScale);
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
