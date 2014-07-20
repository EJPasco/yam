#include "quitreeitemlayouthelper.h"

#include "yconverter.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QLineEdit>
#include "quiitem.h"

#include "quitreeitemsizehelper.h"

YCQUiTreeItemLayoutHelper::YCQUiTreeItemLayoutHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName /*= "layout"*/)
    : m_pleType(NULL)
    , m_pleValue(NULL)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    m_stConfig._sType = "";
    m_stConfig._sValue = "";

    QTreeWidgetItem* pTreeItemMain = new QTreeWidgetItem;
    pTreeItemMain->setText(0, sName);
    pTreeItem->addChild(pTreeItemMain);

    {
        m_pleType = new QLineEdit;
        m_pleType->setText(m_stConfig._sType.c_str());
        connect(m_pleType, SIGNAL(textChanged(const QString&)), this, SLOT(onChangedType(const QString&)));
        QTreeWidgetItem* pTreeItemType = new QTreeWidgetItem;
        pTreeItemType->setText(0, tr("type"));
        pTreeItemMain->addChild(pTreeItemType);
        pTreeRoot->setItemWidget(pTreeItemType, 1, m_pleType);
    }

    {
        m_pleValue = new QLineEdit;
        m_pleValue->setText(m_stConfig._sType.c_str());
        connect(m_pleValue, SIGNAL(textChanged(const QString&)), this, SLOT(onChangedValue(const QString&)));
        QTreeWidgetItem* pTreeItemValue = new QTreeWidgetItem;
        pTreeItemValue->setText(0, tr("value"));
        pTreeItemMain->addChild(pTreeItemValue);
        pTreeRoot->setItemWidget(pTreeItemValue, 1, m_pleValue);
    }
}

YCQUiTreeItemLayoutHelper::~YCQUiTreeItemLayoutHelper()
{
    //
}

void YCQUiTreeItemLayoutHelper::onChangedType(const QString& rsType)
{
    m_stConfig._sType = rsType.toLocal8Bit().data();

    onChanged(m_stConfig);
}

void YCQUiTreeItemLayoutHelper::onChangedValue(const QString& rsValue)
{
    m_stConfig._sValue = rsValue.toLocal8Bit().data();

    onChanged(m_stConfig);
}

void YCQUiTreeItemLayoutHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    if (NULL != m_pleType)
    {
        m_pleType->setText(rpUiItem->getConfigLayout()._sType.c_str());
    }

    if (NULL != m_pleValue)
    {
        m_pleValue->setText(rpUiItem->getConfigLayout()._sValue.c_str());
    }
}
