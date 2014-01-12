#include "ydragdroparea.h"

#include <QtCore/QMimeData>
#include <QtGui/QDrag>
#include <QtGui/QtEvents>
#include <QtWidgets/QLabel>

YCDragDropArea::YCDragDropArea(QWidget* pParent /* = NULL */)
	: QScrollArea(pParent)
{
	setAcceptDrops(true);
}

YCDragDropArea::~YCDragDropArea()
{
	//
}

void YCDragDropArea::mousePressEvent(QMouseEvent* pEvent)
{
	QWidget *pObject = childAt(pEvent->pos());
	if (!pObject)
	{
		return;
	}
	pObject = findChild<QLabel*>(pObject->objectName());
	if (!pObject)
	{
		return;
	}

	QPoint hotSpot = pEvent->pos() - pObject->pos();

	QMimeData* pMimeData = new QMimeData;
	WId id = pObject->effectiveWinId();
	pMimeData->setText(pObject->objectName());
	pMimeData->setData("application/x-hotspot", QByteArray::number(hotSpot.x()) + " " + QByteArray::number(hotSpot.y()));

	QPixmap pixmap(pObject->size());
	pObject->render(&pixmap);

	QDrag* drag = new QDrag(this);
	drag->setMimeData(pMimeData);
	drag->setPixmap(pixmap);

	if (Qt::MoveAction == drag->exec(Qt::MoveAction))
	{
		pObject->close();
	}
}


void YCDragDropArea::dragEnterEvent(QDragEnterEvent *pEvent)
{
	if (!pEvent->mimeData()->hasText())
	{
		pEvent->ignore();
		return;
	}
	if (pEvent->source() != this)
	{
		pEvent->acceptProposedAction();
		return;
	}
	pEvent->setDropAction(Qt::MoveAction);
	pEvent->accept();
}

void YCDragDropArea::dropEvent(QDropEvent *pEvent)
{
	if (!pEvent->mimeData()->hasText())
	{
		pEvent->ignore();
		return;
	}
	if (pEvent->source() != this)
	{
		pEvent->acceptProposedAction();
		return;
	}
	const QMimeData* mime = pEvent->mimeData();
	QLabel* pObject = findChild<QLabel*>(mime->text());
	if (!pObject)
	{
		return;
	}

	QPoint position = pEvent->pos();
	QPoint hotSpot;

	QList<QByteArray> hotSpotPos = mime->data("application/x-hotspot").split(' ');
	if (hotSpotPos.size() == 2)
	{
		hotSpot.setX(hotSpotPos.first().toInt());
		hotSpot.setY(hotSpotPos.last().toInt());
	}

	pObject->move(position - hotSpot);
}