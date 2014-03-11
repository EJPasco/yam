#include "yeditorcommon.h"

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
    , m_pTreeItemImageNormalHelper(NULL)
    , m_pTreeItemImageHoverHelper(NULL)
    , m_pTreeItemImagePressHelper(NULL)
    , m_pTreeItemImageDisableHelper(NULL)
{
    //
}

YCQUiTreeUiHelper::~YCQUiTreeUiHelper()
{
    YEDITOR_DELETE(m_pTreeItemSizeHelper);
    YEDITOR_DELETE(m_pTreeItemBoundHelper);
    YEDITOR_DELETE(m_pTreeItemLayerWeightHelper);
    YEDITOR_DELETE(m_pTreeItemImageTypeHelper);
    YEDITOR_DELETE(m_pTreeItemImageNormalHelper);
    YEDITOR_DELETE(m_pTreeItemImageHoverHelper);
    YEDITOR_DELETE(m_pTreeItemImagePressHelper);
    YEDITOR_DELETE(m_pTreeItemImageDisableHelper);
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

void YCQUiTreeUiHelper::onItemChangedNormalImage(const QString& rsImageSource, const QRect& roBound)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->setImageSource(YCQUiItem::eImageType_Normal, rsImageSource);

    std::vector<yam::ystring> vsPathSeg;
    const yam::base::YIFormat* pFormat = YNULL;
    {
        QStringList qvsPathSeg = rsImageSource.split(".");
        for (int i = 1; i < qvsPathSeg.size(); ++i)
        {
            yam::ystring sPathSeg(qvsPathSeg[i].toLocal8Bit());
            vsPathSeg.push_back(sPathSeg);
        }

        const yam::base::YITree* pImage = gs_FileTreeData.Find(vsPathSeg);
        if (pImage != NULL && YOBJECT_GETCLASSNAME(yam::base::YCFormat) == pImage->GetClassName())
        {
            pFormat = (const yam::base::YIFormat*)pImage;
        }
    }
    if (NULL == pFormat)
    {
        m_pUiItem->setColor(qRgba((qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff));
    }
    else
    {
        m_pUiItem->setImage(YCQUiItem::eImageType_Normal, pFormat->GetBound(), pFormat->GetColorData());
    }
    if (NULL != m_pTreeItemImageNormalHelper)
    {
        //m_pTreeItemImageNormalHelper->setBound(m_pUiItem->rect());
        m_pTreeItemImageNormalHelper->setBound(YCConverter::Instance().Convert(pFormat->GetBound()));
    }
}

void YCQUiTreeUiHelper::onItemChangedHoverImage(const QString& rsImageSource, const QRect& roBound)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->setImageSource(YCQUiItem::eImageType_Hover, rsImageSource);

    std::vector<yam::ystring> vsPathSeg;
    const yam::base::YIFormat* pFormat = YNULL;
    {
        QStringList qvsPathSeg = rsImageSource.split(".");
        for (int i = 1; i < qvsPathSeg.size(); ++i)
        {
            yam::ystring sPathSeg(qvsPathSeg[i].toLocal8Bit());
            vsPathSeg.push_back(sPathSeg);
        }

        const yam::base::YITree* pImage = gs_FileTreeData.Find(vsPathSeg);
        if (pImage != NULL && YOBJECT_GETCLASSNAME(yam::base::YCFormat) == pImage->GetClassName())
        {
            pFormat = (const yam::base::YIFormat*)pImage;
        }
    }
    if (NULL == pFormat)
    {
        m_pUiItem->setColor(qRgba((qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff));
    }
    else
    {
        m_pUiItem->setImage(YCQUiItem::eImageType_Hover, pFormat->GetBound(), pFormat->GetColorData());
    }
    if (NULL != m_pTreeItemImageHoverHelper)
    {
        //m_pTreeItemImageHoverHelper->setBound(m_pUiItem->rect());
        m_pTreeItemImageHoverHelper->setBound(YCConverter::Instance().Convert(pFormat->GetBound()));
    }
}

void YCQUiTreeUiHelper::onItemChangedPressImage(const QString& rsImageSource, const QRect& roBound)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->setImageSource(YCQUiItem::eImageType_Press, rsImageSource);

    std::vector<yam::ystring> vsPathSeg;
    const yam::base::YIFormat* pFormat = YNULL;
    {
        QStringList qvsPathSeg = rsImageSource.split(".");
        for (int i = 1; i < qvsPathSeg.size(); ++i)
        {
            yam::ystring sPathSeg(qvsPathSeg[i].toLocal8Bit());
            vsPathSeg.push_back(sPathSeg);
        }

        const yam::base::YITree* pImage = gs_FileTreeData.Find(vsPathSeg);
        if (pImage != NULL && YOBJECT_GETCLASSNAME(yam::base::YCFormat) == pImage->GetClassName())
        {
            pFormat = (const yam::base::YIFormat*)pImage;
        }
    }
    if (NULL == pFormat)
    {
        m_pUiItem->setColor(qRgba((qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff));
    }
    else
    {
        m_pUiItem->setImage(YCQUiItem::eImageType_Press, pFormat->GetBound(), pFormat->GetColorData());
    }
    if (NULL != m_pTreeItemImagePressHelper)
    {
        //m_pTreeItemImagePressHelper->setBound(m_pUiItem->rect());
        m_pTreeItemImagePressHelper->setBound(YCConverter::Instance().Convert(pFormat->GetBound()));
    }
}

void YCQUiTreeUiHelper::onItemChangedDisableImage(const QString& rsImageSource, const QRect& roBound)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->setImageSource(YCQUiItem::eImageType_Disable, rsImageSource);

    std::vector<yam::ystring> vsPathSeg;
    const yam::base::YIFormat* pFormat = YNULL;
    {
        QStringList qvsPathSeg = rsImageSource.split(".");
        for (int i = 1; i < qvsPathSeg.size(); ++i)
        {
            yam::ystring sPathSeg(qvsPathSeg[i].toLocal8Bit());
            vsPathSeg.push_back(sPathSeg);
        }

        const yam::base::YITree* pImage = gs_FileTreeData.Find(vsPathSeg);
        if (pImage != NULL && YOBJECT_GETCLASSNAME(yam::base::YCFormat) == pImage->GetClassName())
        {
            pFormat = (const yam::base::YIFormat*)pImage;
        }
    }
    if (NULL == pFormat)
    {
        m_pUiItem->setColor(qRgba((qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff));
    }
    else
    {
        m_pUiItem->setImage(YCQUiItem::eImageType_Disable, pFormat->GetBound(), pFormat->GetColorData());
    }
    if (NULL != m_pTreeItemImageDisableHelper)
    {
        //m_pTreeItemImageDisableHelper->setBound(m_pUiItem->rect());
        m_pTreeItemImageDisableHelper->setBound(YCConverter::Instance().Convert(pFormat->GetBound()));
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
        }
        m_pTreeItemSizeHelper->setSize(rpUiItem->size());
        connect(m_pTreeItemSizeHelper, SIGNAL(onChanged(const QSize&)), this, SLOT(onItemChangedSize(const QSize&)));
    }
    else
    {
        if (NULL == m_pTreeItemBoundHelper)
        {
            m_pTreeItemBoundHelper = new YCQUiTreeItemBoundHelper(m_pTreeRoot, pTreeWidget);
            m_pTreeItemBoundHelper->setBound(rpUiItem->rect());
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
            if (NULL == m_pTreeItemImageNormalHelper)
            {
                m_pTreeItemImageNormalHelper = new YCQUiTreeItemImageHelper(m_pTreeRoot, pTreeWidget);
                m_pTreeItemImageNormalHelper->setSource(rpUiItem->getImageSource(YCQUiItem::eImageType_Normal));
                m_pTreeItemImageNormalHelper->setBound(rpUiItem->getImageBound(YCQUiItem::eImageType_Normal));
                connect(m_pTreeItemImageNormalHelper, SIGNAL(onChanged(const QString&, const QRect&)), this, SLOT(onItemChangedNormalImage(const QString&, const QRect&)));
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
            if (NULL == m_pTreeItemImageNormalHelper)
            {
                m_pTreeItemImageNormalHelper = new YCQUiTreeItemImageHelper(m_pTreeRoot, pTreeWidget, tr("Normal Image"));
                m_pTreeItemImageNormalHelper->setSource(rpUiItem->getImageSource(YCQUiItem::eImageType_Normal));
                m_pTreeItemImageNormalHelper->setBound(rpUiItem->getImageBound(YCQUiItem::eImageType_Normal));
                connect(m_pTreeItemImageNormalHelper, SIGNAL(onChanged(const QString&, const QRect&)), this, SLOT(onItemChangedNormalImage(const QString&, const QRect&)));
            }
            if (NULL == m_pTreeItemImageHoverHelper)
            {
                m_pTreeItemImageHoverHelper = new YCQUiTreeItemImageHelper(m_pTreeRoot, pTreeWidget, tr("Hover Image"));
                m_pTreeItemImageHoverHelper->setSource(rpUiItem->getImageSource(YCQUiItem::eImageType_Hover));
                m_pTreeItemImageHoverHelper->setBound(rpUiItem->getImageBound(YCQUiItem::eImageType_Hover));
                connect(m_pTreeItemImageHoverHelper, SIGNAL(onChanged(const QString&, const QRect&)), this, SLOT(onItemChangedHoverImage(const QString&, const QRect&)));
            }
            if (NULL == m_pTreeItemImagePressHelper)
            {
                m_pTreeItemImagePressHelper = new YCQUiTreeItemImageHelper(m_pTreeRoot, pTreeWidget, tr("Press Image"));
                m_pTreeItemImagePressHelper->setSource(rpUiItem->getImageSource(YCQUiItem::eImageType_Press));
                m_pTreeItemImagePressHelper->setBound(rpUiItem->getImageBound(YCQUiItem::eImageType_Press));
                connect(m_pTreeItemImagePressHelper, SIGNAL(onChanged(const QString&, const QRect&)), this, SLOT(onItemChangedPressImage(const QString&, const QRect&)));
            }
            if (NULL == m_pTreeItemImageDisableHelper)
            {
                m_pTreeItemImageDisableHelper = new YCQUiTreeItemImageHelper(m_pTreeRoot, pTreeWidget, tr("Disable Image"));
                m_pTreeItemImageDisableHelper->setSource(rpUiItem->getImageSource(YCQUiItem::eImageType_Disable));
                m_pTreeItemImageDisableHelper->setBound(rpUiItem->getImageBound(YCQUiItem::eImageType_Disable));
                connect(m_pTreeItemImageDisableHelper, SIGNAL(onChanged(const QString&, const QRect&)), this, SLOT(onItemChangedDisableImage(const QString&, const QRect&)));
            }
        }
    }
}
