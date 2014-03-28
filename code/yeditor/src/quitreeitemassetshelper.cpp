#include "quitreeitemassetshelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QPushButton>

#include "quiitem.h"
#include "quitreeitemassethelper.h"

YCQUiTreeItemAssetsHelper::YCQUiTreeItemAssetsHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName /*= "assets"*/)
    : m_pTreeRoot(pTreeRoot)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    m_pTreeItemMain = new QTreeWidgetItem;
    m_pTreeItemMain->setText(0, sName);
    pTreeItem->addChild(m_pTreeItemMain);

    /// a button to add and config new asset
    {
        QPushButton* ppbAddButton = new QPushButton;
        ppbAddButton->setText("add");
        connect(ppbAddButton, SIGNAL(clicked()), this, SLOT(onClickedAdd()));
        pTreeRoot->setItemWidget(m_pTreeItemMain, 1, ppbAddButton);
    }
}

YCQUiTreeItemAssetsHelper::~YCQUiTreeItemAssetsHelper()
{
    VAssetHelper::iterator it = m_vpAssetHelper.begin();
    VAssetHelper::iterator itEnd = m_vpAssetHelper.end();
    for (; it != itEnd; ++it)
    {
        YEDITOR_DELETE(*it);
    }
}

void YCQUiTreeItemAssetsHelper::onClickedAdd()
{
    toAddAssetHelper();

    /// tell the listener to add a new asset
    onChanged();
}

void YCQUiTreeItemAssetsHelper::onChangedAsset(const int& riIndex, const SConfigAsset& rstAsset)
{
    /// tell the listener to update an asset
    onChanged(riIndex, rstAsset);
}

void YCQUiTreeItemAssetsHelper::onChangedAsset(const int& riIndex)
{
    /// tell the listener to delete an asset by index
    onChanged(riIndex);
}

YCQUiTreeItemAssetHelper* YCQUiTreeItemAssetsHelper::toAddAssetHelper()
{
    QString name;
    YCQUiTreeItemAssetHelper* pAssetHelper = new YCQUiTreeItemAssetHelper(this, m_pTreeRoot, m_pTreeItemMain, (int)m_vpAssetHelper.size(), name.sprintf("%d", (int)m_vpAssetHelper.size()));
    connect(pAssetHelper, SIGNAL(onChanged(const int&, const SConfigAsset&)), this, SLOT(onChangedAsset(const int&, const SConfigAsset&)));
    connect(pAssetHelper, SIGNAL(onChanged(const int&)), this, SLOT(onChangedAsset(const int&)));
    m_vpAssetHelper.push_back(pAssetHelper);
    return pAssetHelper;
}

void YCQUiTreeItemAssetsHelper::toDeleteAssetHelper(YCQUiTreeItemAssetHelper* pAssetHelper)
{
    VAssetHelper::iterator it = m_vpAssetHelper.begin();
    VAssetHelper::iterator itEnd = m_vpAssetHelper.end();
    for (; it != itEnd; ++it)
    {
        if ((*it) !=  pAssetHelper)
        {
            continue;
        }
        QTreeWidgetItem* pTreeWidgetItem = (*it)->getTreeWidgetItem();
        m_pTreeItemMain->removeChild(pTreeWidgetItem);
        /// we must handle to free the memory of QTreeWidgetItem.
        /// because the item already was removed from Qt, Qt will don't delete it.
        YEDITOR_DELETE(pTreeWidgetItem);
        YEDITOR_DELETE(*it);
        m_vpAssetHelper.erase(it);
        break;
    }

    for (size_t i = 0; i < m_vpAssetHelper.size(); ++i)
    {
        m_vpAssetHelper[i]->setIndex((int)i);
    }
}

void YCQUiTreeItemAssetsHelper::toClearAssetHelper()
{
    while (0 < m_vpAssetHelper.size())
    {
        toDeleteAssetHelper(m_vpAssetHelper[m_vpAssetHelper.size() - 1]);
    }
}

void YCQUiTreeItemAssetsHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    const SConfigScene& stConfig = rpUiItem->getConfigScene();
    yvconfigasset::const_iterator it = stConfig._vAssets.begin();
    yvconfigasset::const_iterator itEnd = stConfig._vAssets.end();
    for (; it != itEnd; ++it)
    {
        const SConfigAsset& rstAsset = (*it);
        YCQUiTreeItemAssetHelper* pAssetHelper = toAddAssetHelper();
        pAssetHelper->setFile(rstAsset._sFile);
        pAssetHelper->setName(rstAsset._sName);
        pAssetHelper->setType(rstAsset._sType);
    }
}
