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

Q_SIGNALS:
	void visibilityChanged(bool bVisible);

protected:
	virtual void showEvent(QShowEvent* pEvent);
	virtual void hideEvent(QHideEvent* pEvent);
	virtual void mousePressEvent(QMouseEvent* pEvent);
	virtual void mouseReleaseEvent(QMouseEvent* pEvent);
	virtual void mouseMoveEvent(QMouseEvent* pEvent);

public:
	void setSelected(const YCQUiItem* const& rpSelectedItem);
	YCQUiItem* addChildItem(const yam::base::YIFormat*& rpFormat);
	void clearChildrenItem();
	void toTiled();

private:
	bool FindAndDelete(yam::yvrect& rvRect2D, const yam::YVec2D& rstVec2D, yam::YRect2D& rstRect2D) const;

private:
	bool			m_bPressed;
	QPointF			m_oPosMousePressStart;
	yvuiitemptr		m_vItemPtr;
};

#endif // Y_QUIAREA_H
