#ifndef Y_QUIITEM_H
#define Y_QUIITEM_H

#include "yam.h"

#include <QtWidgets/QWidget>

class YCQUiArea;

class YCQUiItem : public QWidget
{
	Q_OBJECT

public:
	explicit YCQUiItem(YCQUiArea* parent = 0, Qt::WindowFlags f = 0);
	virtual ~YCQUiItem();

protected:
	virtual void mousePressEvent(QMouseEvent* pEvent);
	virtual void mouseReleaseEvent(QMouseEvent* pEvent);
	virtual void mouseDoubleClickEvent(QMouseEvent* pEvent);
	virtual void mouseMoveEvent(QMouseEvent* pEvent);
	virtual void paintEvent(QPaintEvent* pEvent);

private:
	YCQUiArea*		m_pUiArea;
	bool			m_bPressed;
	QPointF			m_oPosMousePressStart;
	QImage*			m_pImage;
	QPixmap*		m_pPixmap;
};


#endif // Y_QUIITEM_H
