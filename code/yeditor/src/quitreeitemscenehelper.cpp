#include "quitreeitemscenehelper.h"

#include "yconverter.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QLineEdit>
#include "quiitem.h"
#include "quitreeitemsizehelper.h"
#include "quitreeitemassetshelper.h"

YCQUiTreeItemSceneHelper::YCQUiTreeItemSceneHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName /*= "scene"*/)
    : m_pleLogic(NULL)
    , m_pTreeItemSizeHelper(NULL)
    , m_pTreeItemAssetsHelper(NULL)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    QTreeWidgetItem* pTreeItemMain = new QTreeWidgetItem;
    pTreeItemMain->setText(0, sName);
    pTreeItem->addChild(pTreeItemMain);

    {
        m_pleLogic = new QLineEdit;
        m_pleLogic->setText(m_stConfig._sLogic.c_str());
        connect(m_pleLogic, SIGNAL(textChanged(const QString&)), this, SLOT(onChangedLogic(const QString&)));
        QTreeWidgetItem* pTreeItemLogic = new QTreeWidgetItem;
        pTreeItemLogic->setText(0, tr("logic"));
        pTreeItemMain->addChild(pTreeItemLogic);
        pTreeRoot->setItemWidget(pTreeItemLogic, 1, m_pleLogic);
    }

    {
        m_pTreeItemSizeHelper = new YCQUiTreeItemSizeHelper(pTreeRoot, pTreeItemMain);
        connect(m_pTreeItemSizeHelper, SIGNAL(onChanged(const QSize&)), this, SLOT(onChangedSize(const QSize&)));
    }

    {
        m_pTreeItemAssetsHelper = new YCQUiTreeItemAssetsHelper(pTreeRoot, pTreeItemMain);
        connect(m_pTreeItemAssetsHelper, SIGNAL(onChanged(const int&, const SConfigAsset&)), this, SLOT(onChangedAssets(const int&, const SConfigAsset&)));
        connect(m_pTreeItemAssetsHelper, SIGNAL(onChanged()), this, SLOT(onChangedAssets()));
        connect(m_pTreeItemAssetsHelper, SIGNAL(onChanged(const int&)), this, SLOT(onChangedAssets(const int&)));
    }
}

YCQUiTreeItemSceneHelper::~YCQUiTreeItemSceneHelper()
{
    YEDITOR_DELETE(m_pTreeItemSizeHelper);
    YEDITOR_DELETE(m_pTreeItemAssetsHelper);
}

void YCQUiTreeItemSceneHelper::onChangedLogic(const QString& roLogic)
{
    m_stConfig._sLogic = roLogic.toLocal8Bit().data();
    onChanged(m_stConfig);
}

void YCQUiTreeItemSceneHelper::onChangedSize(const QSize& roSize)
{
    m_stConfig._stSize = YCConverter::Instance().Convert(roSize);
    onChanged(m_stConfig);
}

void YCQUiTreeItemSceneHelper::onChangedAssets(const int& riIndex, const SConfigAsset& rstAsset)
{
    while (riIndex >= (int)m_stConfig._vAssets.size())
    {
        SConfigAsset stAsset;
        m_stConfig._vAssets.push_back(stAsset);
    }
    m_stConfig._vAssets[riIndex] = rstAsset;
    onChanged(m_stConfig);
}

void YCQUiTreeItemSceneHelper::onChangedAssets()
{
    SConfigAsset stAsset;
    m_stConfig._vAssets.push_back(stAsset);
    onChanged(m_stConfig);
}

void YCQUiTreeItemSceneHelper::onChangedAssets(const int& riIndex)
{
    if (riIndex < 0 || riIndex >= (int)m_stConfig._vAssets.size())
    {
        return;
    }
    m_stConfig._vAssets.erase(m_stConfig._vAssets.begin() + riIndex);
    onChanged(m_stConfig);
}

void YCQUiTreeItemSceneHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    if (NULL != m_pleLogic)
    {
        m_pleLogic->setText(rpUiItem->getConfigScene()._sLogic.c_str());
    }

    if (NULL != m_pTreeItemSizeHelper)
    {
        m_stConfig._stSize = YCConverter::Instance().Convert(rpUiItem->size());
        m_pTreeItemSizeHelper->setSize(rpUiItem->size());
    }

    if (NULL != m_pTreeItemAssetsHelper)
    {
        m_pTreeItemAssetsHelper->setUiItem(rpUiItem);
    }
}
