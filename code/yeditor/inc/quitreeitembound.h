#ifndef Y_QUITREEITEMBOUND_H
#define Y_QUITREEITEMBOUND_H

#include "quitree.h"

#include <QtWidgets/QTreeWidgetItem>

class YCQUiTreeItemBound : public QTreeWidgetItem
{
	//Q_OBJECT

public:
	explicit YCQUiTreeItemBound(YCQUiTree* parent = 0);
	virtual ~YCQUiTreeItemBound();

public:
};

#endif // Y_QUITREEITEMBOUND_H
