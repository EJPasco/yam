#include "quitreeitemsrchelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include "quiitem.h"
#include "quitreeitemimagehelper.h"
#include "quitreeitemimageshelper.h"

YCQUiTreeItemSrcHelper::YCQUiTreeItemSrcHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const yam::yuint8& riImageTypeGroup, const QString sName /*= "Image"*/)
    : m_eImageType(eImageType_Normal)
    , m_iImageIndex(0)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    QTreeWidgetItem* pTreeItemMain = new QTreeWidgetItem;
    pTreeItemMain->setText(0, sName);
    pTreeItem->addChild(pTreeItemMain);

    {
        QComboBox* pcbImageType = new QComboBox;
        for (int i = 0; i < eImageType_Max; ++i)
        {
            if (!(riImageTypeGroup & (1 << i)))
            {
                continue;
            }
            pcbImageType->addItem(tr(YCQUiItem::convertImageTypeToString((EImageType)i).c_str()));
        }
        connect(pcbImageType, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(onImageTypeChanged(const QString&)));
        QTreeWidgetItem* ptwiImageType = new QTreeWidgetItem;
        ptwiImageType->setText(0, tr("Type"));
        pTreeItemMain->addChild(ptwiImageType);
        pTreeRoot->setItemWidget(ptwiImageType, 1, pcbImageType);
    }

    {
        QSpinBox* psbImageIndex = new QSpinBox;
        psbImageIndex->setRange(0, INT_MAX);
        psbImageIndex->setValue(0);
        connect(psbImageIndex, SIGNAL(valueChanged(int)), this, SLOT(onImageIndexChanged(int)));
        QTreeWidgetItem* ptwiImageIndex = new QTreeWidgetItem;
        ptwiImageIndex->setText(0, tr("Index"));
        pTreeItemMain->addChild(ptwiImageIndex);
        pTreeRoot->setItemWidget(ptwiImageIndex, 1, psbImageIndex);
    }

    for (int i = 0; i < eImageType_Max; ++i)
    {
        m_apImagesHelper[i] = NULL;
        if (!(riImageTypeGroup & (1 << i)))
        {
            continue;
        }
        m_apImagesHelper[i] = new YCQUiTreeItemImagesHelper(pTreeRoot, pTreeItemMain, (EImageType)i, tr(YCQUiItem::convertImageTypeToString((EImageType)i).c_str()));
        connect(m_apImagesHelper[i], SIGNAL(onChanged(const EImageType&, const yam::yint32&, YCQUiTreeItemImageHelper*)), this, SLOT(onImagesChanged(const EImageType&, const yam::yint32&, YCQUiTreeItemImageHelper*)));
    }
}

YCQUiTreeItemSrcHelper::~YCQUiTreeItemSrcHelper()
{
    for (int i = 0; i < eImageType_Max; ++i)
    {
        YEDITOR_DELETE(m_apImagesHelper[i]);
    }
}

void YCQUiTreeItemSrcHelper::onImageTypeChanged(const QString& rsImageType)
{
    for (yam::yint32 i = 0; i < eImageType_Max; ++i)
    {
        if (YCQUiItem::convertImageTypeToString((EImageType)i) != rsImageType.toLocal8Bit().data())
        {
            continue;
        }
        m_eImageType = (EImageType)i;
        break;
    }

    onSelected(m_eImageType, m_iImageIndex);
}

void YCQUiTreeItemSrcHelper::onImageIndexChanged(const int& riImageIndex)
{
    m_iImageIndex = riImageIndex;

    onSelected(m_eImageType, m_iImageIndex);
}

void YCQUiTreeItemSrcHelper::onImagesChanged(const EImageType& reImageType, const yam::yint32& iImageIndex, YCQUiTreeItemImageHelper* pImageHelper)
{
    onChanged(reImageType, iImageIndex, pImageHelper);
}

void YCQUiTreeItemSrcHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    for (int i = 0; i < eImageType_Max; ++i)
    {
        if (NULL == m_apImagesHelper[i])
        {
            continue;
        }
        m_apImagesHelper[i]->setUiItem(rpUiItem);
    }
}
