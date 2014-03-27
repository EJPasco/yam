#include "quitreeitempanelhelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QComboBox>
#include "quiitem.h"

YCQUiTreeItemPanelHelper::YCQUiTreeItemPanelHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName /*= "panel"*/)
    : m_pcbNoInput(NULL)
    , m_bNoInput(true)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    QTreeWidgetItem* pTreeItemMain = new QTreeWidgetItem;
    pTreeItemMain->setText(0, sName);
    pTreeItem->addChild(pTreeItemMain);

    {
        m_pcbNoInput = new QComboBox;
        m_pcbNoInput->addItem(tr("false"));
        m_pcbNoInput->addItem(tr("true"));
        m_pcbNoInput->setCurrentIndex(m_bNoInput ? 1 : 0);
        connect(m_pcbNoInput, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(onChangedNoInput(const QString&)));
        QTreeWidgetItem* ptwiImageType = new QTreeWidgetItem;
        ptwiImageType->setText(0, tr("noinput"));
        pTreeItemMain->addChild(ptwiImageType);
        pTreeRoot->setItemWidget(ptwiImageType, 1, m_pcbNoInput);
    }
}

YCQUiTreeItemPanelHelper::~YCQUiTreeItemPanelHelper()
{
    //
}

void YCQUiTreeItemPanelHelper::onChangedNoInput(const QString& rsNoInput)
{
    m_bNoInput = (rsNoInput == "false") ? 0 : 1;
    onChanged(m_bNoInput);
}

void YCQUiTreeItemPanelHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    if (NULL != m_pcbNoInput)
    {
        m_bNoInput = rpUiItem->getNoInput();
        m_pcbNoInput->setCurrentIndex(m_bNoInput ? 1 : 0);
    }
}
