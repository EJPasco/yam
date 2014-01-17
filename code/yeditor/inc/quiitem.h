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

public:
	void setGrabed(const bool& rbGrabed);
	void setSelected(const bool& rbSelected);
	void setFormat(const yam::base::YIFormat*& rpFormat);
	void setFormat(const yam::YRect2D& rstRect, const yam::ycolorptr& rpColorData);
	void setColor(const QColor& rColor);

private:
	YCQUiArea*		m_pUiArea;
	QImage*			m_pImage;
	bool			m_bPressed;
	QPointF			m_oPosMousePressStart;
	bool			m_bGrabed;
	bool			m_bSelected;
};


#endif // Y_QUIITEM_H
