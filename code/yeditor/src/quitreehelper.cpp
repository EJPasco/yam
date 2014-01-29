#include "quitreehelper.h"

#include <QtWidgets/QSpinBox>

YCQUiTreeHelper::YCQUiTreeHelper(QTreeWidget* pTreeRoot)
    : m_pTreeRoot(pTreeRoot)
{
    connect(m_pTreeRoot, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(onItemChanged(QTreeWidgetItem*,int)));
}

YCQUiTreeHelper::~YCQUiTreeHelper()
{
    //
}

void YCQUiTreeHelper::onItemChanged(QTreeWidgetItem* pItem, int iColume)
{
    if (NULL == m_pUiItem)
    {
        return;
    }

    if (pItem->text(0) == tr("Visible"))
    {
        m_pUiItem->setVisible((pItem->checkState(1) == Qt::Checked) ? true : false);
    }
    //
}

void YCQUiTreeHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    m_pUiItem = rpUiItem;
    if (NULL == rpUiItem)
    {
        return;
    }

    QTreeWidgetItem* pTreeCommon = new QTreeWidgetItem;
    pTreeCommon->setText(0, tr("Common"));
    m_pTreeRoot->insertTopLevelItem(m_pTreeRoot->topLevelItemCount(), pTreeCommon);

    {
        QTreeWidgetItem* pTreeVisible = new QTreeWidgetItem;
        pTreeVisible->setText(0, tr("Visible"));
        pTreeVisible->setCheckState(1, (rpUiItem->isVisible() ? Qt::Checked : Qt::Unchecked));
        pTreeCommon->addChild(pTreeVisible);
    }
    //
}
