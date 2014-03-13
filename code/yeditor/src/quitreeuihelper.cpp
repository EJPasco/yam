#include "yeditorcommon.h"

#include "yeditor.h"
#include "yconverter.h"
#include "quitreeuihelper.h"

#include "quitreeitemsizehelper.h"
#include "quitreeitemboundhelper.h"
#include "quitreeitemlayerweighthelper.h"
#include "quitreeitemimagetypehelper.h"
#include "quitreeitemimagehelper.h"

YCQUiTreeUiHelper::YCQUiTreeUiHelper(QTreeWidget* pTreeRoot)
    : YCQUiTreeHelper(pTreeRoot)
    , m_pTreeItemSizeHelper(NULL)
    , m_pTreeItemBoundHelper(NULL)
    , m_pTreeItemLayerWeightHelper(NULL)
    , m_pTreeItemImageTypeHelper(NULL)
{
    for (int i = 0; i < YCQUiItem::eImageType_Max; ++i)
    {
        m_apTreeItemImageHelper[i] = NULL;
    }
}

YCQUiTreeUiHelper::~YCQUiTreeUiHelper()
{
    YEDITOR_DELETE(m_pTreeItemSizeHelper);
    YEDITOR_DELETE(m_pTreeItemBoundHelper);
    YEDITOR_DELETE(m_pTreeItemLayerWeightHelper);
    YEDITOR_DELETE(m_pTreeItemImageTypeHelper);

    for (int i = 0; i < YCQUiItem::eImageType_Max; ++i)
    {
        YEDITOR_DELETE(m_apTreeItemImageHelper[i]);
    }
}

void YCQUiTreeUiHelper::onItemChangedSize(const QSize& roSize)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->resize(roSize);
}

void YCQUiTreeUiHelper::onItemChangedBound(const QRect& roBound)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->move(roBound.topLeft());
    m_pUiItem->resize(roBound.size());
}

void YCQUiTreeUiHelper::onItemChangedLayerWeight(const int& riLayerWeight)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->setLayerWeight(riLayerWeight);
}

void YCQUiTreeUiHelper::onItemChangedImageType(const YCQUiItem::EImageType& reImageType)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->setImageType(reImageType);
}

void YCQUiTreeUiHelper::onItemChangedImageSource(const YCQUiItem::EImageType& reImageType, const QString& rsImageSource, const QRect& roBound)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->setImageSource(reImageType, rsImageSource);

    std::vector<yam::ystring> vsPathSeg;
    const yam::base::YIFormat* pFormat = YNULL;
    SRelationship stRelationship;
    stRelationship._pUiItem = NULL;
    stRelationship._pTreeItem = NULL;
    {
        QStringList qvsPathSeg = rsImageSource.split(".");
        for (int i = 1; i < qvsPathSeg.size(); ++i)
        {
            yam::ystring sPathSeg(qvsPathSeg[i].toLocal8Bit());
            vsPathSeg.push_back(sPathSeg);
        }

        pFormat = gs_FileTreeData.Find<yam::base::YCFormat>(vsPathSeg);
        stRelationship = YEditor::getRelationship(rsImageSource.toLocal8Bit().data());
    }
    if (NULL == pFormat || NULL == stRelationship._pUiItem)
    {
        m_pUiItem->setColor(qRgba((qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff));
    }
    else
    {
        m_pUiItem->setImage(reImageType, pFormat->GetBound(), pFormat->GetColorData());
    }
    if (NULL != m_apTreeItemImageHelper[reImageType])
    {
        QRect rect = stRelationship._pUiItem != NULL ? QRect(stRelationship._pUiItem->pos(), stRelationship._pUiItem->size()) : m_pUiItem->rect();
        m_pUiItem->setImageBound(reImageType, rect);
        m_apTreeItemImageHelper[reImageType]->setBound(rect);
    }
}

void YCQUiTreeUiHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    super::setUiItem(rpUiItem);
    if (NULL == rpUiItem)
    {
        return;
    }

    QTreeWidgetItem* pTreeWidget = new QTreeWidgetItem;
    pTreeWidget->setText(0, tr("Widget"));
    m_pTreeRoot->insertTopLevelItem(m_pTreeRoot->topLevelItemCount(), pTreeWidget);

    if (yam::eWidgetType_Scene == rpUiItem->getType())
    {
        if (NULL == m_pTreeItemSizeHelper)
        {
            m_pTreeItemSizeHelper = new YCQUiTreeItemSizeHelper(m_pTreeRoot, pTreeWidget);
            m_pTreeItemSizeHelper->setSize(rpUiItem->size());
            connect(m_pTreeItemSizeHelper, SIGNAL(onChanged(const QSize&)), this, SLOT(onItemChangedSize(const QSize&)));
        }
    }
    else
    {
        if (NULL == m_pTreeItemBoundHelper)
        {
            m_pTreeItemBoundHelper = new YCQUiTreeItemBoundHelper(m_pTreeRoot, pTreeWidget);
            m_pTreeItemBoundHelper->setBound(QRect(rpUiItem->pos(), rpUiItem->size()));
            connect(m_pTreeItemBoundHelper, SIGNAL(onChanged(const QRect&)), this, SLOT(onItemChangedBound(const QRect&)));
        }

        if (NULL == m_pTreeItemLayerWeightHelper)
        {
            m_pTreeItemLayerWeightHelper =  new YCQUiTreeItemLayerWeightHelper(m_pTreeRoot, pTreeWidget);
            m_pTreeItemLayerWeightHelper->setLayerWeight(rpUiItem->getLayerWeight());
            connect(m_pTreeItemLayerWeightHelper, SIGNAL(onChanged(const int&)), this, SLOT(onItemChangedLayerWeight(const int&)));
        }

        if (yam::eWidgetType_Panel == rpUiItem->getType())
        {
            //
        }
        else if (yam::eWidgetType_Image == rpUiItem->getType())
        {
            if (NULL == m_pTreeItemImageTypeHelper)
            {
                m_pTreeItemImageTypeHelper = new YCQUiTreeItemImageTypeHelper(m_pTreeRoot, pTreeWidget, (1 << YCQUiItem::eImageType_Normal));
                m_pTreeItemImageTypeHelper->setImageType(YCQUiItem::eImageType_Normal);
                connect(m_pTreeItemImageTypeHelper, SIGNAL(onChanged(const YCQUiItem::EImageType&)), this, SLOT(onItemChangedImageType(const YCQUiItem::EImageType&)));
            }

            if (NULL == m_apTreeItemImageHelper[YCQUiItem::eImageType_Normal])
            {
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Normal] = new YCQUiTreeItemImageHelper(m_pTreeRoot, pTreeWidget, YCQUiItem::eImageType_Normal);
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Normal]->setSource(rpUiItem->getImageSource(YCQUiItem::eImageType_Normal));
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Normal]->setBound(rpUiItem->getImageBound(YCQUiItem::eImageType_Normal));
                connect(m_apTreeItemImageHelper[YCQUiItem::eImageType_Normal], SIGNAL(onChanged(const YCQUiItem::EImageType&, const QString&, const QRect&)), this, SLOT(onItemChangedImageSource(const YCQUiItem::EImageType&, const QString&, const QRect&)));
            }
        }
        else if (yam::eWidgetType_Button == rpUiItem->getType())
        {
            if (NULL == m_pTreeItemImageTypeHelper)
            {
                m_pTreeItemImageTypeHelper = new YCQUiTreeItemImageTypeHelper(m_pTreeRoot, pTreeWidget
                    , (1 << YCQUiItem::eImageType_Normal) | (1 << YCQUiItem::eImageType_Hover) | (1 << YCQUiItem::eImageType_Press) | (1 << YCQUiItem::eImageType_Disable));
                m_pTreeItemImageTypeHelper->setImageType(YCQUiItem::eImageType_Normal);
                connect(m_pTreeItemImageTypeHelper, SIGNAL(onChanged(const YCQUiItem::EImageType&)), this, SLOT(onItemChangedImageType(const YCQUiItem::EImageType&)));
            }

            if (NULL == m_apTreeItemImageHelper[YCQUiItem::eImageType_Normal])
            {
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Normal] = new YCQUiTreeItemImageHelper(m_pTreeRoot, pTreeWidget, YCQUiItem::eImageType_Normal, tr("Normal Image"));
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Normal]->setSource(rpUiItem->getImageSource(YCQUiItem::eImageType_Normal));
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Normal]->setBound(rpUiItem->getImageBound(YCQUiItem::eImageType_Normal));
                connect(m_apTreeItemImageHelper[YCQUiItem::eImageType_Normal], SIGNAL(onChanged(const YCQUiItem::EImageType&, const QString&, const QRect&)), this, SLOT(onItemChangedImageSource(const YCQUiItem::EImageType&, const QString&, const QRect&)));
            }

            if (NULL == m_apTreeItemImageHelper[YCQUiItem::eImageType_Hover])
            {
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Hover] = new YCQUiTreeItemImageHelper(m_pTreeRoot, pTreeWidget, YCQUiItem::eImageType_Hover, tr("Hover Image"));
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Hover]->setSource(rpUiItem->getImageSource(YCQUiItem::eImageType_Hover));
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Hover]->setBound(rpUiItem->getImageBound(YCQUiItem::eImageType_Hover));
                connect(m_apTreeItemImageHelper[YCQUiItem::eImageType_Hover], SIGNAL(onChanged(const YCQUiItem::EImageType&, const QString&, const QRect&)), this, SLOT(onItemChangedImageSource(const YCQUiItem::EImageType&, const QString&, const QRect&)));
            }

            if (NULL == m_apTreeItemImageHelper[YCQUiItem::eImageType_Press])
            {
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Press] = new YCQUiTreeItemImageHelper(m_pTreeRoot, pTreeWidget, YCQUiItem::eImageType_Press, tr("Press Image"));
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Press]->setSource(rpUiItem->getImageSource(YCQUiItem::eImageType_Press));
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Press]->setBound(rpUiItem->getImageBound(YCQUiItem::eImageType_Press));
                connect(m_apTreeItemImageHelper[YCQUiItem::eImageType_Press], SIGNAL(onChanged(const YCQUiItem::EImageType&, const QString&, const QRect&)), this, SLOT(onItemChangedImageSource(const YCQUiItem::EImageType&, const QString&, const QRect&)));
            }

            if (NULL == m_apTreeItemImageHelper[YCQUiItem::eImageType_Disable])
            {
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Disable] = new YCQUiTreeItemImageHelper(m_pTreeRoot, pTreeWidget, YCQUiItem::eImageType_Disable, tr("Disable Image"));
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Disable]->setSource(rpUiItem->getImageSource(YCQUiItem::eImageType_Disable));
                m_apTreeItemImageHelper[YCQUiItem::eImageType_Disable]->setBound(rpUiItem->getImageBound(YCQUiItem::eImageType_Disable));
                connect(m_apTreeItemImageHelper[YCQUiItem::eImageType_Disable], SIGNAL(onChanged(const YCQUiItem::EImageType&, const QString&, const QRect&)), this, SLOT(onItemChangedImageSource(const YCQUiItem::EImageType&, const QString&, const QRect&)));
            }
        }
    }
}
