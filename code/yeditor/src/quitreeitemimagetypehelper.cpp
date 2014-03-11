#include "quitreeitemimagetypehelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QComboBox>

#include "yeditorcommon.h"
#include "quitreeitemboundhelper.h"

YCQUiTreeItemImageTypeHelper::YCQUiTreeItemImageTypeHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const yam::yuint8& riImageTypeGroup, const QString sName /*= "Image"*/)
    : m_pTreeItemImage(NULL)
    , m_pComboBox(NULL)
    , m_eImageType(YCQUiItem::eImageType_Normal)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    m_pTreeItemImage = new QTreeWidgetItem;
    m_pTreeItemImage->setText(0, sName);
    pTreeItem->addChild(m_pTreeItemImage);

    {
        m_pComboBox = new QComboBox;
        if (riImageTypeGroup & (1 << YCQUiItem::eImageType_Normal))
        {
            m_pComboBox->addItem("Normal");
        }
        if (riImageTypeGroup & (1 << YCQUiItem::eImageType_Hover))
        {
            m_pComboBox->addItem("Hover");
        }
        if (riImageTypeGroup & (1 << YCQUiItem::eImageType_Press))
        {
            m_pComboBox->addItem("Press");
        }
        if (riImageTypeGroup & (1 << YCQUiItem::eImageType_Disable))
        {
            m_pComboBox->addItem("Disable");
        }
        connect(m_pComboBox, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(onItemChanged(const QString&)));
        QTreeWidgetItem* pTreeImageSrc = new QTreeWidgetItem;
        pTreeImageSrc->setText(0, tr("Type"));
        m_pTreeItemImage->addChild(pTreeImageSrc);
        pTreeRoot->setItemWidget(pTreeImageSrc, 1, m_pComboBox);
    }
}

YCQUiTreeItemImageTypeHelper::~YCQUiTreeItemImageTypeHelper()
{
    //
}

void YCQUiTreeItemImageTypeHelper::onItemChanged(const QString& rsImageType)
{
    if (rsImageType == "Normal")
    {
        m_eImageType = YCQUiItem::eImageType_Normal;
    }
    else if (rsImageType == "Hover")
    {
        m_eImageType = YCQUiItem::eImageType_Hover;
    }
    else if (rsImageType == "Press")
    {
        m_eImageType = YCQUiItem::eImageType_Press;
    }
    else if (rsImageType == "Disable")
    {
        m_eImageType = YCQUiItem::eImageType_Disable;
    }
    onChanged(m_eImageType);
}

void YCQUiTreeItemImageTypeHelper::setImageType(const YCQUiItem::EImageType& reImageType)
{
    m_eImageType = reImageType;
}
