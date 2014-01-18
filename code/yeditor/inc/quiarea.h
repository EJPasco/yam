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
	virtual void mousePressEvent(QMouseEvent* pEvent);
	virtual void mouseReleaseEvent(QMouseEvent* pEvent);
	virtual void mouseDoubleClickEvent(QMouseEvent* pEvent);
	virtual void mouseMoveEvent(QMouseEvent* pEvent);

public:
	void setSelected(const YCQUiItem* const& rpItem);
	void addChildItem(const yam::base::YIFormat*& rpFormat);
	void clearChildrenItem();

private:
	bool			m_bPressed;
	QPointF			m_oPosMousePressStart;
	yvuiitemptr		m_vItemPtr;
};

#endif // Y_QUIAREA_H
