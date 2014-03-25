#include "quitreereshelper.h"

#include "quitreeitemboundhelper.h"

YCQUiTreeResHelper::YCQUiTreeResHelper(QTreeWidget* pTreeRoot)
    : YCQUiTreeHelper(pTreeRoot)
    , m_pTreeItemBoundHelper(NULL)
{
    //
}

YCQUiTreeResHelper::~YCQUiTreeResHelper()
{
    YEDITOR_DELETE(m_pTreeItemBoundHelper);
    //
}

void YCQUiTreeResHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    super::setUiItem(rpUiItem);
    if (NULL == rpUiItem)
    {
        return;
    }

    QTreeWidgetItem* pTreeWidget = new QTreeWidgetItem;
    pTreeWidget->setText(0, tr("image"));
    m_pTreeRoot->insertTopLevelItem(m_pTreeRoot->topLevelItemCount(), pTreeWidget);

    if (NULL == m_pTreeItemBoundHelper)
    {
        m_pTreeItemBoundHelper = new YCQUiTreeItemBoundHelper(m_pTreeRoot, pTreeWidget);
        m_pTreeItemBoundHelper->setEnabled(false);
        m_pTreeItemBoundHelper->setBound(QRect(rpUiItem->pos(), rpUiItem->size()));
    }
}
