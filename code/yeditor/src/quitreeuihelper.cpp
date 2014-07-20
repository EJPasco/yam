#include "yeditorcommon.h"

#include "yeditor.h"
#include "yconverter.h"
#include "yexportyam.h"
#include "quitreeuihelper.h"

#include "quitreeitemsizehelper.h"
#include "quitreeitemboundhelper.h"
#include "quitreeitemlayerweighthelper.h"
#include "quitreeitemsrchelper.h"
#include "quitreeitemimagehelper.h"
#include "quitreeitemtexthelper.h"
#include "quitreeitempanelhelper.h"
#include "quitreeitemscenehelper.h"

YCQUiTreeUiHelper::YCQUiTreeUiHelper(QTreeWidget* pTreeRoot)
    : YCQUiTreeHelper(pTreeRoot)
    , m_pTreeItemSizeHelper(NULL)
    , m_pTreeItemBoundHelper(NULL)
    , m_pTreeItemLayerWeightHelper(NULL)
    , m_pTreeItemSrcHelper(NULL)
    , m_pTreeItemTextHelper(NULL)
    , m_pTreeItemPanelHelper(NULL)
    , m_pTreeItemSceneHelper(NULL)
{
    //
}

YCQUiTreeUiHelper::~YCQUiTreeUiHelper()
{
    YEDITOR_DELETE(m_pTreeItemSizeHelper);
    YEDITOR_DELETE(m_pTreeItemBoundHelper);
    YEDITOR_DELETE(m_pTreeItemLayerWeightHelper);
    YEDITOR_DELETE(m_pTreeItemSrcHelper);
    YEDITOR_DELETE(m_pTreeItemTextHelper);
    YEDITOR_DELETE(m_pTreeItemPanelHelper);
    YEDITOR_DELETE(m_pTreeItemSceneHelper);
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

void YCQUiTreeUiHelper::onItemChangedSrc(const EImageType& reImageType, const yam::yint32& riImageIndex, YCQUiTreeItemImageHelper* pImageHelper)
{
    if (NULL == m_pUiItem)
    {
        return;
    }

    const yam::base::YIFormat* pFormat = YNULL;
    if (m_pUiItem->getImageSource(reImageType, riImageIndex) != pImageHelper->getSource().toLocal8Bit().data())
    {
        std::vector<yam::ystring> vsPathSeg;
        SRelationship stRelationship;
        stRelationship._pUiItem = NULL;
        stRelationship._pTreeItem = NULL;
        {
            QStringList qvsPathSeg = pImageHelper->getSource().split(".");
            for (int i = 1; i < qvsPathSeg.size(); ++i)
            {
                yam::ystring sPathSeg(qvsPathSeg[i].toLocal8Bit());
                if (0 >= sPathSeg.size())
                {
                    continue;
                }
                vsPathSeg.push_back(sPathSeg);
            }

            pFormat = gs_FileTreeData.Find<yam::base::YCFormat>(vsPathSeg);
            stRelationship = YEditor::getRelationship(pImageHelper->getSource().toLocal8Bit().data());
        }
        if (NULL == pFormat)
        {
            //m_pUiItem->setImage(reImageType, riImageIndex, pImageHelper->getSource().toLocal8Bit().data(), yam::YRect2D(), NULL);
            m_pUiItem->setColor(qRgba((qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff, (qrand() + 0x10) % 0xff));
        }
        else
        {
            m_pUiItem->setImage(reImageType, riImageIndex, YCConverter::Instance().Convert(pImageHelper->getOffset()), pFormat);
        }
    }
    else
    {
        m_pUiItem->setImage(reImageType, riImageIndex, YCConverter::Instance().Convert(pImageHelper->getOffset()), pFormat);
    }
}

void YCQUiTreeUiHelper::onItemChangedSrc(const EImageType& reImageType, const yam::yfloat32& rfSpeed, const yam::ystring& rsType)
{
    if (NULL == m_pUiItem)
    {
        return;
    }

    m_pUiItem->getImagesData(reImageType)._fSpeed = rfSpeed;
    m_pUiItem->getImagesData(reImageType)._sType = rsType;
}

void YCQUiTreeUiHelper::onItemChangedSrc(const EImageType& reImageType)
{
    if (NULL == m_pUiItem)
    {
        return;
    }

    m_pUiItem->addImage(reImageType);
}

void YCQUiTreeUiHelper::onItemChangedSrc(const EImageType& reImageType, const yam::yint32& riImageIndex)
{
    if (NULL == m_pUiItem)
    {
        return;
    }

    m_pUiItem->delImage(reImageType, riImageIndex);
}

void YCQUiTreeUiHelper::onItemSelectedSrc(const EImageType& reImageType, const yam::yint32& riImageIndex)
{
    if (NULL == m_pUiItem)
    {
        return;
    }

    m_pUiItem->setCurrentImage(reImageType, riImageIndex);
}

void YCQUiTreeUiHelper::onItemChangedText(const QString& rsFace, const int& riSize, const QString& rsAlign, const QString& rsValue)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->setTextFace(rsFace.toLocal8Bit().data());
    m_pUiItem->setTextSize(riSize);
    m_pUiItem->setTextAlign(rsAlign.toLocal8Bit().data());
    m_pUiItem->setTextValue(rsValue.toLocal8Bit().data());
}

void YCQUiTreeUiHelper::onItemChangedPanel(const bool& rbNoInput, const SConfigLayout& rstConfigLayout)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->setNoInput(rbNoInput);
    m_pUiItem->setConfigLayout(rstConfigLayout);
}

void YCQUiTreeUiHelper::onItemChangedScene(const SConfigScene& rstConfigScene, const SConfigLayout& rstConfigLayout)
{
    if (NULL == m_pUiItem)
    {
        return;
    }
    m_pUiItem->setConfigScene(rstConfigScene);
    m_pUiItem->setConfigLayout(rstConfigLayout);
}

void YCQUiTreeUiHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    super::setUiItem(rpUiItem);
    if (NULL == rpUiItem)
    {
        return;
    }

    QTreeWidgetItem* pTreeWidget = new QTreeWidgetItem;
    pTreeWidget->setText(0, tr(yam::io::YCExportYam::GetNameByWidgetType(rpUiItem->getType()).c_str()));
    m_pTreeRoot->insertTopLevelItem(m_pTreeRoot->topLevelItemCount(), pTreeWidget);

    if (yam::eWidgetType_Scene == rpUiItem->getType())
    {
        if (NULL == m_pTreeItemSceneHelper)
        {
            m_pTreeItemSceneHelper = new YCQUiTreeItemSceneHelper(m_pTreeRoot, pTreeWidget);
            m_pTreeItemSceneHelper->setUiItem(rpUiItem);
            connect(m_pTreeItemSceneHelper, SIGNAL(onChanged(const SConfigScene&, const SConfigLayout&)), this, SLOT(onItemChangedScene(const SConfigScene&, const SConfigLayout&)));
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
            if (NULL == m_pTreeItemPanelHelper)
            {
                m_pTreeItemPanelHelper = new YCQUiTreeItemPanelHelper(m_pTreeRoot, pTreeWidget);
                m_pTreeItemPanelHelper->setUiItem(rpUiItem);
                connect(m_pTreeItemPanelHelper, SIGNAL(onChanged(const bool&, const SConfigLayout&)), this, SLOT(onItemChangedPanel(const bool&, const SConfigLayout&)));
            }
        }
        else if (yam::eWidgetType_Image == rpUiItem->getType())
        {
            if (NULL == m_pTreeItemSrcHelper)
            {
                m_pTreeItemSrcHelper = new YCQUiTreeItemSrcHelper(m_pTreeRoot, pTreeWidget, (1 << eImageType_Normal), "src");
                m_pTreeItemSrcHelper->setUiItem(rpUiItem);
                connect(m_pTreeItemSrcHelper, SIGNAL(onChanged(const EImageType&, const yam::yint32&, YCQUiTreeItemImageHelper*)), this, SLOT(onItemChangedSrc(const EImageType&, const yam::yint32&, YCQUiTreeItemImageHelper*)));
                connect(m_pTreeItemSrcHelper, SIGNAL(onChanged(const EImageType&, const yam::yfloat32&, const yam::ystring&)), this, SLOT(onItemChangedSrc(const EImageType&, const yam::yfloat32&, const yam::ystring&)));
                connect(m_pTreeItemSrcHelper, SIGNAL(onChanged(const EImageType&)), this, SLOT(onItemChangedSrc(const EImageType&)));
                connect(m_pTreeItemSrcHelper, SIGNAL(onChanged(const EImageType&, const yam::yint32&)), this, SLOT(onItemChangedSrc(const EImageType&, const yam::yint32&)));
                connect(m_pTreeItemSrcHelper, SIGNAL(onSelected(const EImageType&, const yam::yint32&)), this, SLOT(onItemSelectedSrc(const EImageType&, const yam::yint32&)));
            }
        }
        else if (yam::eWidgetType_Button == rpUiItem->getType())
        {
            if (NULL == m_pTreeItemSrcHelper)
            {
                m_pTreeItemSrcHelper = new YCQUiTreeItemSrcHelper(m_pTreeRoot, pTreeWidget, (1 << eImageType_Normal) | (1 << eImageType_Hover) | (1 << eImageType_Pressed) | (1 << eImageType_Disable), "src");
                m_pTreeItemSrcHelper->setUiItem(rpUiItem);
                connect(m_pTreeItemSrcHelper, SIGNAL(onChanged(const EImageType&, const yam::yint32&, YCQUiTreeItemImageHelper*)), this, SLOT(onItemChangedSrc(const EImageType&, const yam::yint32&, YCQUiTreeItemImageHelper*)));
                connect(m_pTreeItemSrcHelper, SIGNAL(onChanged(const EImageType&, const yam::yfloat32&, const yam::ystring&)), this, SLOT(onItemChangedSrc(const EImageType&, const yam::yfloat32&, const yam::ystring&)));
                connect(m_pTreeItemSrcHelper, SIGNAL(onSelected(const EImageType&, const yam::yint32&)), this, SLOT(onItemSelectedSrc(const EImageType&, const yam::yint32&)));
            }
        }
        else if (yam::eWidgetType_Text == rpUiItem->getType())
        {
            if (NULL == m_pTreeItemTextHelper)
            {
                m_pTreeItemTextHelper = new YCQUiTreeItemTextHelper(m_pTreeRoot, pTreeWidget);
                m_pTreeItemTextHelper->setUiItem(rpUiItem);
                connect(m_pTreeItemTextHelper, SIGNAL(onChanged(const QString&, const int&, const QString&, const QString&)), this, SLOT(onItemChangedText(const QString&, const int&, const QString&, const QString&)));
            }
        }
    }
}
