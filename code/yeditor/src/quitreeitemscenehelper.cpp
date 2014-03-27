#include "quitreeitemscenehelper.h"

#include "yconverter.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QLineEdit>
#include "quiitem.h"
#include "quitreeitemsizehelper.h"
#include "quitreeitemassertshelper.h"

YCQUiTreeItemSceneHelper::YCQUiTreeItemSceneHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName /*= "scene"*/)
    : m_pleLogic(NULL)
    , m_pTreeItemSizeHelper(NULL)
    , m_pTreeItemAssertsHelper(NULL)
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
        m_pTreeItemAssertsHelper = new YCQUiTreeItemAssertsHelper(pTreeRoot, pTreeItemMain);
        connect(m_pTreeItemAssertsHelper, SIGNAL(onChanged(const int&, const SConfigAssert&)), this, SLOT(onChangedAsserts(const int&, const SConfigAssert&)));
        connect(m_pTreeItemAssertsHelper, SIGNAL(onChanged()), this, SLOT(onChangedAsserts()));
        connect(m_pTreeItemAssertsHelper, SIGNAL(onChanged(const int&)), this, SLOT(onChangedAsserts(const int&)));
    }
}

YCQUiTreeItemSceneHelper::~YCQUiTreeItemSceneHelper()
{
    YEDITOR_DELETE(m_pTreeItemSizeHelper);
    YEDITOR_DELETE(m_pTreeItemAssertsHelper);
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

void YCQUiTreeItemSceneHelper::onChangedAsserts(const int& riIndex, const SConfigAssert& rstAssert)
{
    while (riIndex >= (int)m_stConfig._vAsserts.size())
    {
        SConfigAssert stAssert;
        m_stConfig._vAsserts.push_back(stAssert);
    }
    m_stConfig._vAsserts[riIndex] = rstAssert;
    onChanged(m_stConfig);
}

void YCQUiTreeItemSceneHelper::onChangedAsserts()
{
    SConfigAssert stAssert;
    m_stConfig._vAsserts.push_back(stAssert);
    onChanged(m_stConfig);
}

void YCQUiTreeItemSceneHelper::onChangedAsserts(const int& riIndex)
{
    if (riIndex < 0 || riIndex >= (int)m_stConfig._vAsserts.size())
    {
        return;
    }
    m_stConfig._vAsserts.erase(m_stConfig._vAsserts.begin() + riIndex);
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

    if (NULL != m_pTreeItemAssertsHelper)
    {
        m_pTreeItemAssertsHelper->setUiItem(rpUiItem);
    }
}
