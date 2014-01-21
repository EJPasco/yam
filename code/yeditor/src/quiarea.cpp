#include "quiarea.h"

#include <QtWidgets/QPushButton>
#include <QtGui/QtEvents>
#include <QtCore/QTime>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLayoutItem>

YCQUiArea::YCQUiArea(QWidget* parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
	: QFrame(parent, f)
	, m_bPressed(false)
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
		if (NULL == pItem)
		{
			continue;
		}
		if (rpItem == pItem)
		{
			pItem->setSelected(true);
		}
		else
		{
			pItem->setSelected(false);
		}
	}
}

YCQUiItem* YCQUiArea::addChildItem(const yam::base::YIFormat*& rpFormat)
{
	if (YNULL == rpFormat->GetColorData())
	{
		return NULL;
	}
	YCQUiItem* pNewItem = new YCQUiItem(this);
	pNewItem->setFormat(rpFormat);
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
