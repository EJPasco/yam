#ifndef Y_QUITREE_H
#define Y_QUITREE_H

#include "quiitem.h"

#include <QtWidgets/QTreeWidget>

class YCQUiTree : public QTreeWidget
{
	Q_OBJECT

public:
	explicit YCQUiTree(QWidget *parent = 0);
	virtual ~YCQUiTree();

Q_SIGNALS:
	void onChanged(YCQUiTree* pSelf);

public Q_SLOTS:
	void onItemChanged(QTreeWidgetItem* pItem, int iColume);

public:
	void setFormat(YCQUiItem* pFormat);
	void setWidget(YCQUiItem* pWidget);
};

#endif // Y_QUITREE_H
