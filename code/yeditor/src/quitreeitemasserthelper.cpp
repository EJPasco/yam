#include "quitreeitemasserthelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include "quiitem.h"

#include "quitreeitemassertshelper.h"

YCQUiTreeItemAssertHelper::YCQUiTreeItemAssertHelper(YCQUiTreeItemAssertsHelper* pAssertsHelper, QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const int& riIndex, const QString sName /*= "scene"*/)
    : m_pAssertsHelper(pAssertsHelper)
    , m_pleFile(NULL)
    , m_pleName(NULL)
    , m_pleType(NULL)
    , m_iAssertIndex(riIndex)
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
        m_pleFile->setText(m_stAssert._sFile.c_str());
        connect(m_pleFile, SIGNAL(textChanged(const QString&)), this, SLOT(onChangedFile(const QString&)));
        QTreeWidgetItem* pTreeItemFile = new QTreeWidgetItem;
        pTreeItemFile->setText(0, tr("file"));
        m_pTreeItemMain->addChild(pTreeItemFile);
        pTreeRoot->setItemWidget(pTreeItemFile, 1, m_pleFile);
    }

    {
        m_pleName = new QLineEdit;
        m_pleName->setText(m_stAssert._sName.c_str());
        connect(m_pleName, SIGNAL(textChanged(const QString&)), this, SLOT(onChangedName(const QString&)));
        QTreeWidgetItem* pTreeItemName = new QTreeWidgetItem;
        pTreeItemName->setText(0, tr("name"));
        m_pTreeItemMain->addChild(pTreeItemName);
        pTreeRoot->setItemWidget(pTreeItemName, 1, m_pleName);
    }

    {
        m_pleType = new QLineEdit;
        m_pleType->setText(m_stAssert._sType.c_str());
        connect(m_pleType, SIGNAL(textChanged(const QString&)), this, SLOT(onChangedType(const QString&)));
        QTreeWidgetItem* pTreeItemType = new QTreeWidgetItem;
        pTreeItemType->setText(0, tr("type"));
        m_pTreeItemMain->addChild(pTreeItemType);
        pTreeRoot->setItemWidget(pTreeItemType, 1, m_pleType);
    }
}

YCQUiTreeItemAssertHelper::~YCQUiTreeItemAssertHelper()
{
    //
}

void YCQUiTreeItemAssertHelper::onClickedDelete()
{
    onChanged(m_iAssertIndex);
    m_pAssertsHelper->toDeleteAssertHelper(this);
    //WARNING don't do anything after toDeleteAssertHelper
}

void YCQUiTreeItemAssertHelper::onChangedFile(const QString& rsFile)
{
    m_stAssert._sFile = rsFile.toLocal8Bit().data();
    onChanged(m_iAssertIndex, m_stAssert);
}

void YCQUiTreeItemAssertHelper::onChangedName(const QString& rsName)
{
    m_stAssert._sName = rsName.toLocal8Bit().data();
    onChanged(m_iAssertIndex, m_stAssert);
}

void YCQUiTreeItemAssertHelper::onChangedType(const QString& rsType)
{
    m_stAssert._sType = rsType.toLocal8Bit().data();
    onChanged(m_iAssertIndex, m_stAssert);
}

void YCQUiTreeItemAssertHelper::setFile(const yam::ystring& rsFile)
{
    m_stAssert._sFile = rsFile;
    if (NULL != m_pleFile)
    {
        m_pleFile->setText(rsFile.c_str());
    }
}

void YCQUiTreeItemAssertHelper::setName(const yam::ystring& rsName)
{
    m_stAssert._sName = rsName;
    if (NULL != m_pleName)
    {
        m_pleName->setText(rsName.c_str());
    }
}

void YCQUiTreeItemAssertHelper::setType(const yam::ystring& rsType)
{
    m_stAssert._sType = rsType;
    if (NULL != m_pleType)
    {
        m_pleType->setText(rsType.c_str());
    }
}

void YCQUiTreeItemAssertHelper::setIndex(const int& riIndex)
{
    m_iAssertIndex = riIndex;

    m_pTreeItemMain->setText(0, QString().sprintf("%d", riIndex));
}

QTreeWidgetItem* YCQUiTreeItemAssertHelper::getTreeWidgetItem()
{
    return m_pTreeItemMain;
}
