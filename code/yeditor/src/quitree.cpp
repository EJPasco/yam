#include "quitree.h"

#include "quitreeitembound.h"

YCQUiTree::YCQUiTree(QWidget *parent /* = 0 */)
	: QTreeWidget(parent)
{
	//
}

YCQUiTree::~YCQUiTree()
{
	//
}

void YCQUiTree::onItemChanged(QTreeWidgetItem* pItem, int iColume)
{
	onChanged(this);
	//
}

void YCQUiTree::setFormat(YCQUiItem* pFormat)
{
	clear();

	if (NULL == pFormat)
	{
		return;
	}

	QTreeWidgetItem* pTreeBasic = new QTreeWidgetItem;
	pTreeBasic->setText(0, tr("Basic"));
	insertTopLevelItem(0, pTreeBasic);
	//
}

void YCQUiTree::setWidget(YCQUiItem* pWidget)
{
	clear();
	//
}
