#include "quitreeitemimageshelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QPushButton>

#include "quitreeitemimagehelper.h"

YCQUiTreeItemImagesHelper::YCQUiTreeItemImagesHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const EImageType& reImageType, const QString sName /*= "Image"*/)
    : m_pTreeRoot(pTreeRoot)
    , m_pTreeItemImages(NULL)
    , m_eImageType(reImageType)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    m_pTreeItemImages = new QTreeWidgetItem;
    m_pTreeItemImages->setText(0, sName);
    pTreeItem->addChild(m_pTreeItemImages);

    {
        QPushButton* ppbAddButton = new QPushButton;
        ppbAddButton->setText("add");
        connect(ppbAddButton, SIGNAL(clicked()), this, SLOT(onAddButtonClicked()));
        pTreeRoot->setItemWidget(m_pTreeItemImages, 1, ppbAddButton);
    }
    //
}

YCQUiTreeItemImagesHelper::~YCQUiTreeItemImagesHelper()
{
    VImageHelper::iterator it = m_vpImageHelper.begin();
    VImageHelper::iterator itEnd = m_vpImageHelper.end();
    for (; it != itEnd; ++it)
    {
        YEDITOR_DELETE(*it);
    }
}

void YCQUiTreeItemImagesHelper::onAddButtonClicked()
{
    toAddImageHelper();
}

void YCQUiTreeItemImagesHelper::onImageChanged(const yam::yint32& riIndex, YCQUiTreeItemImageHelper* pImageHelper)
{
    onChanged(m_eImageType, riIndex, pImageHelper);
}

YCQUiTreeItemImageHelper* YCQUiTreeItemImagesHelper::toAddImageHelper()
{
    QString name;
    YCQUiTreeItemImageHelper* pImageHelper = new YCQUiTreeItemImageHelper(this, m_pTreeRoot, m_pTreeItemImages, m_vpImageHelper.size(), name.sprintf("%d", m_vpImageHelper.size()));
    connect(pImageHelper, SIGNAL(onChanged(const yam::yint32&, YCQUiTreeItemImageHelper*)), this, SLOT(onImageChanged(const yam::yint32&, YCQUiTreeItemImageHelper*)));
    m_vpImageHelper.push_back(pImageHelper);
    return pImageHelper;
}

void YCQUiTreeItemImagesHelper::toDeleteImageHelper(YCQUiTreeItemImageHelper* pImageHelper)
{
    VImageHelper::iterator it = m_vpImageHelper.begin();
    VImageHelper::iterator itEnd = m_vpImageHelper.end();
    for (; it != itEnd; ++it)
    {
        if ((*it) !=  pImageHelper)
        {
            continue;
        }
        m_pTreeItemImages->removeChild((*it)->getTreeWidgetItem());
        YEDITOR_DELETE(*it);
        m_vpImageHelper.erase(it);
        break;
    }

    for (size_t i = 0; i < m_vpImageHelper.size(); ++i)
    {
        std::stringstream ss;
        ss << i;
        m_vpImageHelper[i]->setText(ss.str().c_str());
    }
}

void YCQUiTreeItemImagesHelper::toClearImageHelper()
{
    while (0 < m_vpImageHelper.size())
    {
        toDeleteImageHelper(m_vpImageHelper[m_vpImageHelper.size() - 1]);
    }
}

const EImageType& YCQUiTreeItemImagesHelper::getImageType()
{
    return m_eImageType;
}

void YCQUiTreeItemImagesHelper::setUiItem(YCQUiItem*& rpUiItem)
{
    toClearImageHelper();

    yam::yint32 iCount = rpUiItem->getImageCount(m_eImageType);
    for (yam::yint32 i = 0; i < iCount; ++i)
    {
        YCQUiTreeItemImageHelper* pImageHelper = toAddImageHelper();
        pImageHelper->setSource(rpUiItem->getImageSource(m_eImageType, i));
        pImageHelper->setOffset(rpUiItem->getImageOffset(m_eImageType, i));
    }
}
