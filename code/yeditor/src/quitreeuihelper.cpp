#include "yeditorcommon.h"

#include "quitreeuihelper.h"

YCQUiTreeUiHelper::YCQUiTreeUiHelper(QTreeWidget* pTreeRoot)
    : YCQUiTreeHelper(pTreeRoot)
    , m_pTreeItemBoundHelper(NULL)
    , m_pTreeItemLayerWeightHelper(NULL)
    , m_pTreeItemImageHelper(NULL)
{
    //
}

YCQUiTreeUiHelper::~YCQUiTreeUiHelper()
{
    if (NULL != m_pTreeItemBoundHelper)
    {
        delete m_pTreeItemBoundHelper;
        m_pTreeItemBoundHelper = NULL;
    }
    if (NULL != m_pTreeItemLayerWeightHelper)
    {
        delete m_pTreeItemLayerWeightHelper;
        m_pTreeItemLayerWeightHelper = NULL;
    }
    if (NULL != m_pTreeItemImageHelper)
    {
        delete m_pTreeItemImageHelper;
        m_pTreeItemImageHelper = NULL;
    }
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
        if (pImage == NULL || YOBJECT_GETCLASSNAME(yam::base::YCFormat) != pImage->GetClassName())
        {
            return;
        }
        pFormat = (const yam::base::YIFormat*)pImage;
    }
    m_pUiItem->setImage(pFormat->GetBound(), pFormat->GetColorData());
    m_pTreeItemBoundHelper->setBound(m_pUiItem->rect());
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

    if (NULL == m_pTreeItemImageHelper)
    {
        m_pTreeItemImageHelper = new YCQUiTreeItemImageHelper(m_pTreeRoot, pTreeWidget);
        m_pTreeItemImageHelper->setImageSource(rpUiItem->getImageSource());
        connect(m_pTreeItemImageHelper, SIGNAL(onChangedSource(const QString&)), this, SLOT(onItemChangedImageSource(const QString&)));
    }
}
