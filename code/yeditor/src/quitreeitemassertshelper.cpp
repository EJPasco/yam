#include "quitreeitemassertshelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QPushButton>

#include "quiitem.h"
#include "quitreeitemasserthelper.h"

YCQUiTreeItemAssertsHelper::YCQUiTreeItemAssertsHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName /*= "asserts"*/)
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

YCQUiTreeItemAssertsHelper::~YCQUiTreeItemAssertsHelper()
{
    VAssertHelper::iterator it = m_vpAssertHelper.begin();
    VAssertHelper::iterator itEnd = m_vpAssertHelper.end();
    for (; it != itEnd; ++it)
    {
        YEDITOR_DELETE(*it);
    }
}

void YCQUiTreeItemAssertsHelper::onClickedAdd()
{
    toAddAssertHelper();

    /// tell the listener to add a new assert
    onChanged();
}

void YCQUiTreeItemAssertsHelper::onChangedAssert(const int& riIndex, const SConfigAssert& rstAssert)
{
    /// tell the listener to update an assert
    onChanged(riIndex, rstAssert);
}

void YCQUiTreeItemAssertsHelper::onChangedAssert(const int& riIndex)
{
    /// tell the listener to delete an assert by index
    onChanged(riIndex);
}

YCQUiTreeItemAssertHelper* YCQUiTreeItemAssertsHelper::toAddAssertHelper()
{
    QString name;
    YCQUiTreeItemAssertHelper* pAssertHelper = new YCQUiTreeItemAssertHelper(this, m_pTreeRoot, m_pTreeItemMain, (int)m_vpAssertHelper.size(), name.sprintf("%d", m_vpAssertHelper.size()));
    connect(pAssertHelper, SIGNAL(onChanged(const int&, const SConfigAssert&)), this, SLOT(onChangedAssert(const int&, const SConfigAssert&)));
    connect(pAssertHelper, SIGNAL(onChanged(const int&)), this, SLOT(onChangedAssert(const int&)));
    m_vpAssertHelper.push_back(pAssertHelper);
    return pAssertHelper;
}

void YCQUiTreeItemAssertsHelper::toDeleteAssertHelper(YCQUiTreeItemAssertHelper* pAssertHelper)
{
    VAssertHelper::iterator it = m_vpAssertHelper.begin();
    VAssertHelper::iterator itEnd = m_vpAssertHelper.end();
    for (; it != itEnd; ++it)
    {
        if ((*it) !=  pAssertHelper)
        {
            continue;
        }
        QTreeWidgetItem* pTreeWidgetItem = (*it)->getTreeWidgetItem();
        m_pTreeItemMain->removeChild(pTreeWidgetItem);
        /// we must handle to free the memory of QTreeWidgetItem.
        /// because the item already was removed from Qt, Qt will don't delete it.
        YEDITOR_DELETE(pTreeWidgetItem);
        YEDITOR_DELETE(*it);
        m_vpAssertHelper.erase(it);
        break;
    }

    for (size_t i = 0; i < m_vpAssertHelper.size(); ++i)
    {
        m_vpAssertHelper[i]->setIndex((int)i);
    }
}

void YCQUiTreeItemAssertsHelper::toClearAssertHelper()
{
    while (0 < m_vpAssertHelper.size())
    {
        toDeleteAssertHelper(m_vpAssertHelper[m_vpAssertHelper.size() - 1]);
    }
}

void YCQUiTreeItemAssertsHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    const SConfigScene& stConfig = rpUiItem->getConfigScene();
    yvconfigassert::const_iterator it = stConfig._vAsserts.begin();
    yvconfigassert::const_iterator itEnd = stConfig._vAsserts.end();
    for (; it != itEnd; ++it)
    {
        const SConfigAssert& rstAssert = (*it);
        YCQUiTreeItemAssertHelper* pAssertHelper = toAddAssertHelper();
        pAssertHelper->setFile(rstAssert._sFile);
        pAssertHelper->setName(rstAssert._sName);
        pAssertHelper->setType(rstAssert._sType);
    }
}
