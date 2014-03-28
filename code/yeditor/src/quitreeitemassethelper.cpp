#include "quitreeitemassethelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include "quiitem.h"

#include "quitreeitemassetshelper.h"

YCQUiTreeItemAssetHelper::YCQUiTreeItemAssetHelper(YCQUiTreeItemAssetsHelper* pAssetsHelper, QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const int& riIndex, const QString sName /*= "scene"*/)
    : m_pAssetsHelper(pAssetsHelper)
    , m_pleFile(NULL)
    , m_pleName(NULL)
    , m_pleType(NULL)
    , m_iAssetIndex(riIndex)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    m_pTreeItemMain = new QTreeWidgetItem;
    m_pTreeItemMain->setText(0, sName);
    pTreeItem->addChild(m_pTreeItemMain);

    {
        QPushButton* ppbDelButton = new QPushButton;
        ppbDelButton->setText("delete");
        connect(ppbDelButton, SIGNAL(clicked()), this, SLOT(onClickedDelete()));
        pTreeRoot->setItemWidget(m_pTreeItemMain, 1, ppbDelButton);
    }

    {
        m_pleFile = new QLineEdit;
        m_pleFile->setText(m_stAsset._sFile.c_str());
        connect(m_pleFile, SIGNAL(textChanged(const QString&)), this, SLOT(onChangedFile(const QString&)));
        QTreeWidgetItem* pTreeItemFile = new QTreeWidgetItem;
        pTreeItemFile->setText(0, tr("file"));
        m_pTreeItemMain->addChild(pTreeItemFile);
        pTreeRoot->setItemWidget(pTreeItemFile, 1, m_pleFile);
    }

    {
        m_pleName = new QLineEdit;
        m_pleName->setText(m_stAsset._sName.c_str());
        connect(m_pleName, SIGNAL(textChanged(const QString&)), this, SLOT(onChangedName(const QString&)));
        QTreeWidgetItem* pTreeItemName = new QTreeWidgetItem;
        pTreeItemName->setText(0, tr("name"));
        m_pTreeItemMain->addChild(pTreeItemName);
        pTreeRoot->setItemWidget(pTreeItemName, 1, m_pleName);
    }

    {
        m_pleType = new QLineEdit;
        m_pleType->setText(m_stAsset._sType.c_str());
        connect(m_pleType, SIGNAL(textChanged(const QString&)), this, SLOT(onChangedType(const QString&)));
        QTreeWidgetItem* pTreeItemType = new QTreeWidgetItem;
        pTreeItemType->setText(0, tr("type"));
        m_pTreeItemMain->addChild(pTreeItemType);
        pTreeRoot->setItemWidget(pTreeItemType, 1, m_pleType);
    }
}

YCQUiTreeItemAssetHelper::~YCQUiTreeItemAssetHelper()
{
    //
}

void YCQUiTreeItemAssetHelper::onClickedDelete()
{
    onChanged(m_iAssetIndex);
    m_pAssetsHelper->toDeleteAssetHelper(this);
    //WARNING don't do anything after toDeleteAssetHelper
}

void YCQUiTreeItemAssetHelper::onChangedFile(const QString& rsFile)
{
    m_stAsset._sFile = rsFile.toLocal8Bit().data();
    onChanged(m_iAssetIndex, m_stAsset);
}

void YCQUiTreeItemAssetHelper::onChangedName(const QString& rsName)
{
    m_stAsset._sName = rsName.toLocal8Bit().data();
    onChanged(m_iAssetIndex, m_stAsset);
}

void YCQUiTreeItemAssetHelper::onChangedType(const QString& rsType)
{
    m_stAsset._sType = rsType.toLocal8Bit().data();
    onChanged(m_iAssetIndex, m_stAsset);
}

void YCQUiTreeItemAssetHelper::setFile(const yam::ystring& rsFile)
{
    m_stAsset._sFile = rsFile;
    if (NULL != m_pleFile)
    {
        m_pleFile->setText(rsFile.c_str());
    }
}

void YCQUiTreeItemAssetHelper::setName(const yam::ystring& rsName)
{
    m_stAsset._sName = rsName;
    if (NULL != m_pleName)
    {
        m_pleName->setText(rsName.c_str());
    }
}

void YCQUiTreeItemAssetHelper::setType(const yam::ystring& rsType)
{
    m_stAsset._sType = rsType;
    if (NULL != m_pleType)
    {
        m_pleType->setText(rsType.c_str());
    }
}

void YCQUiTreeItemAssetHelper::setIndex(const int& riIndex)
{
    m_iAssetIndex = riIndex;

    m_pTreeItemMain->setText(0, QString().sprintf("%d", riIndex));
}

QTreeWidgetItem* YCQUiTreeItemAssetHelper::getTreeWidgetItem()
{
    return m_pTreeItemMain;
}
