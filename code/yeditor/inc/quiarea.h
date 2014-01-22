#ifndef Y_QUIAREA_H
#define Y_QUIAREA_H

#include "quiitem.h"

#include <QtWidgets/QFrame>

class YCQUiItem;

class YCQUiArea : public QFrame
{
	typedef std::vector<YCQUiItem*>			yvuiitemptr;

	Q_OBJECT

public:
	YCQUiArea(QWidget* parent = 0, Qt::WindowFlags f = 0);
	YCQUiArea(QFramePrivate &dd, QWidget* parent = 0, Qt::WindowFlags f = 0);
	virtual ~YCQUiArea();

protected:
	/*virtual void paintEvent(QPaintEvent* pEvent);*/

protected:
	virtual void mousePressEvent(QMouseEvent* pEvent);
	virtual void mouseReleaseEvent(QMouseEvent* pEvent);
	virtual void mouseMoveEvent(QMouseEvent* pEvent);
#ifndef QT_NO_WHEELEVENT
	virtual void wheelEvent(QWheelEvent* pEvent);
#endif

public:
	void setSelected(const YCQUiItem* const& rpSelectedItem);
	void setScale(const qreal& rfScale);
	YCQUiItem* addChildItem(const yam::base::YIFormat*& rpFormat);
	void clearChildrenItem();

private:
	bool			m_bPressed;
	QPointF			m_oPosMousePressStart;
	yvuiitemptr		m_vItemPtr;
	qreal			m_fScale;
};

#endif // Y_QUIAREA_H
