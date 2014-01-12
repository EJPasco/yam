#ifndef Y_DRAGDROPAREA_H
#define Y_DRAGDROPAREA_H

#include <QtWidgets/QScrollArea>

class YCDragDropArea : public QScrollArea
{
	Q_OBJECT

public:
	YCDragDropArea(QWidget* pParent = NULL);
	virtual ~YCDragDropArea();

protected:
	void mousePressEvent(QMouseEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *de);
};

#endif // Y_DRAGDROPAREA_H