#include "quitreeitemtexthelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QLineEdit>
#include "quiitem.h"

YCQUiTreeItemTextHelper::YCQUiTreeItemTextHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName /*= "text"*/)
    : m_pleFontName(NULL)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    QTreeWidgetItem* pTreeItemMain = new QTreeWidgetItem;
    pTreeItemMain->setText(0, sName);
    pTreeItem->addChild(pTreeItemMain);

    {
        m_pleFontName = new QLineEdit;
        connect(m_pleFontName, SIGNAL(textChanged(const QString&)), this, SLOT(onChangedFontName(const QString&)));
        QTreeWidgetItem* ptwiImageType = new QTreeWidgetItem;
        ptwiImageType->setText(0, tr("font"));
        pTreeItemMain->addChild(ptwiImageType);
        pTreeRoot->setItemWidget(ptwiImageType, 1, m_pleFontName);
    }
}

YCQUiTreeItemTextHelper::~YCQUiTreeItemTextHelper()
{
    //
}

void YCQUiTreeItemTextHelper::onChangedFontName(const QString& rsFontName)
{
    m_sFontName = rsFontName;
    onChanged(m_sFontName);
}

void YCQUiTreeItemTextHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    if (NULL != m_pleFontName)
    {
        m_pleFontName->setText(rpUiItem->getFontName().c_str());
    }
}
