#include "yeditorcommon.h"

#include "quitreeuihelper.h"

#include "quitreeitemsizehelper.h"
#include "quitreeitemboundhelper.h"
#include "quitreeitemlayerweighthelper.h"
#include "quitreeitemimagehelper.h"

YCQUiTreeUiHelper::YCQUiTreeUiHelper(QTreeWidget* pTreeRoot)
    : YCQUiTreeHelper(pTreeRoot)
    , m_pTreeItemSizeHelper(NULL)
    , m_pTreeItemBoundHelper(NULL)
    , m_pTreeItemLayerWeightHelper(NULL)
    , m_pTreeItemImageHelper(NULL)
{
    //
}

YCQUiTreeUiHelper::~YCQUiTreeUiHelper()
{
    YEDITOR_DELETE(m_pTreeItemSizeHelper);
    YEDITOR_DELETE(m_pTreeItemBoundHelper);
    YEDITOR_DELETE(m_pTreeItemLayerWeightHelper);
    YEDITOR_DELETE(m_pTreeItemImageHelper);
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

void YCQUiTreeUiHelper::onItemChangedImageSource(const QString& rsImageSource)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->setImageSource(rsImageSource);

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
        m_pUiItem->setColor(qRgba(qrand(), qrand(), qrand(), qrand()));
    }
    else
    {
        m_pUiItem->setImage(pFormat->GetBound(), pFormat->GetColorData());
    }
    if (NULL != m_pTreeItemSizeHelper)
    {
        m_pTreeItemSizeHelper->setSize(m_pUiItem->size());
    }
    if (NULL != m_pTreeItemBoundHelper)
    {
        m_pTreeItemBoundHelper->setBound(m_pUiItem->rect());
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
        }
        m_pTreeItemBoundHelper->setBound(rpUiItem->rect());
        connect(m_pTreeItemBoundHelper, SIGNAL(onChanged(const QRect&)), this, SLOT(onItemChangedBound(const QRect&)));
    }

    if (NULL == m_pTreeItemLayerWeightHelper)
    {
        m_pTreeItemLayerWeightHelper =  new YCQUiTreeItemLayerWeightHelper(m_pTreeRoot, pTreeWidget);
        m_pTreeItemLayerWeightHelper->setLayerWeight(rpUiItem->getLayerWeight());
        connect(m_pTreeItemLayerWeightHelper, SIGNAL(onChanged(const int&)), this, SLOT(onItemChangedLayerWeight(const int&)));
    }

    if (NULL == m_pTreeItemImageHelper)
    {
        m_pTreeItemImageHelper = new YCQUiTreeItemImageHelper(m_pTreeRoot, pTreeWidget);
        m_pTreeItemImageHelper->setImageSource(rpUiItem->getImageSource());
        connect(m_pTreeItemImageHelper, SIGNAL(onChanged(const QString&)), this, SLOT(onItemChangedImageSource(const QString&)));
    }
}
