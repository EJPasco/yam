#include "quitreeitemimageshelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

#include "quitreeitemimagehelper.h"

YCQUiTreeItemImagesHelper::YCQUiTreeItemImagesHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const EImageType& reImageType, const QString sName /*= "Image"*/)
    : m_pTreeRoot(pTreeRoot)
    , m_pTreeItemImages(NULL)
    , m_pdsbSpeed(NULL)
    , m_eImageType(reImageType)
    , m_fSpeed(0.1f)
    , m_sType("")
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

    {
        m_pdsbSpeed = new QDoubleSpinBox;
        m_pdsbSpeed->setValue(m_fSpeed);
        connect(m_pdsbSpeed, SIGNAL(valueChanged(double)), this, SLOT(onChangedSpeed(double)));
        QTreeWidgetItem* pTreeItemSpeed = new QTreeWidgetItem;
        pTreeItemSpeed->setText(0, tr("speed"));
        m_pTreeItemImages->addChild(pTreeItemSpeed);
        pTreeRoot->setItemWidget(pTreeItemSpeed, 1, m_pdsbSpeed);
    }

    {
        m_pleType = new QLineEdit;
        m_pleType->setText(m_sType.c_str());
        connect(m_pleType, SIGNAL(textChanged(const QString&)), this, SLOT(onItemChangedType(const QString&)));
        QTreeWidgetItem* pTreeType = new QTreeWidgetItem;
        pTreeType->setText(0, tr("type"));
        m_pTreeItemImages->addChild(pTreeType);
        pTreeRoot->setItemWidget(pTreeType, 1, m_pleType);
    }
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

    onChanged(m_eImageType);
}

void YCQUiTreeItemImagesHelper::onChangedImage(const yam::yint32& riIndex, YCQUiTreeItemImageHelper* pImageHelper)
{
    onChanged(m_eImageType, riIndex, pImageHelper);
}

void YCQUiTreeItemImagesHelper::onChangedImage(const yam::yint32& riIndex)
{
    onChanged(m_eImageType, riIndex);
}

void YCQUiTreeItemImagesHelper::onChangedSpeed(double dSpeed)
{
    m_fSpeed = (float)dSpeed;

    onChanged(m_eImageType, m_fSpeed, m_sType);
}

void YCQUiTreeItemImagesHelper::onItemChangedType(const QString& rsType)
{
    m_sType = rsType.toLocal8Bit().data();

    onChanged(m_eImageType, m_fSpeed, m_sType);
}

YCQUiTreeItemImageHelper* YCQUiTreeItemImagesHelper::toAddImageHelper()
{
    QString name;
    YCQUiTreeItemImageHelper* pImageHelper = new YCQUiTreeItemImageHelper(this, m_pTreeRoot, m_pTreeItemImages, m_vpImageHelper.size(), name.sprintf("%d", (int)m_vpImageHelper.size()));
    connect(pImageHelper, SIGNAL(onChanged(const yam::yint32&, YCQUiTreeItemImageHelper*)), this, SLOT(onChangedImage(const yam::yint32&, YCQUiTreeItemImageHelper*)));
    connect(pImageHelper, SIGNAL(onChanged(const yam::yint32&)), this, SLOT(onChangedImage(const yam::yint32&)));
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
        QTreeWidgetItem* pTreeWidgetItem = (*it)->getTreeWidgetItem();
        m_pTreeItemImages->removeChild(pTreeWidgetItem);
        /// We must handle to free the memory of QTreeWidgetItem.
        /// Because the item already was removed from Qt, Qt will don't delete it.
        YEDITOR_DELETE(pTreeWidgetItem);
        YEDITOR_DELETE(*it);
        m_vpImageHelper.erase(it);
        break;
    }

    for (size_t i = 0; i < m_vpImageHelper.size(); ++i)
    {
        m_vpImageHelper[i]->setIndex((yam::yint32)i);
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
    m_fSpeed = rpUiItem->getImagesData(m_eImageType)._fSpeed;
    m_pdsbSpeed->setValue(m_fSpeed);
    m_sType = rpUiItem->getImagesData(m_eImageType)._sType;
    m_pleType->setText(m_sType.c_str());

    for (yam::yint32 i = 0; i < iCount; ++i)
    {
        YCQUiTreeItemImageHelper* pImageHelper = toAddImageHelper();
        pImageHelper->setSource(rpUiItem->getImageSource(m_eImageType, i));
        pImageHelper->setOffset(rpUiItem->getImageOffset(m_eImageType, i));
    }
}
