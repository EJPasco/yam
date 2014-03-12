#include "quitreeitemimagehelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QLineEdit>

#include "yeditorcommon.h"
#include "quitreeitemboundhelper.h"

YCQUiTreeItemImageHelper::YCQUiTreeItemImageHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const YCQUiItem::EImageType& reImageType, const QString sName /*= "Image"*/)
    : m_pTreeItemImage(NULL)
    , m_pEditor(NULL)
    , m_pTreeItemBoundHelper(NULL)
    , m_eImageType(reImageType)
    , m_sImageSource("")
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    m_pTreeItemImage = new QTreeWidgetItem;
    m_pTreeItemImage->setText(0, sName);
    pTreeItem->addChild(m_pTreeItemImage);

    {
        m_pEditor = new QLineEdit;
        m_pEditor->setText(m_sImageSource);
        connect(m_pEditor, SIGNAL(textChanged(const QString&)), this, SLOT(onItemChangedSource(const QString&)));
        QTreeWidgetItem* pTreeImageSrc = new QTreeWidgetItem;
        pTreeImageSrc->setText(0, tr("Source"));
        m_pTreeItemImage->addChild(pTreeImageSrc);
        pTreeRoot->setItemWidget(pTreeImageSrc, 1, m_pEditor);
    }

    {
        m_pTreeItemBoundHelper = new YCQUiTreeItemBoundHelper(pTreeRoot, m_pTreeItemImage);
        connect(m_pTreeItemBoundHelper, SIGNAL(onChanged(const QRect&)), this, SLOT(onItemChangedBound(const QRect&)));
        m_pTreeItemBoundHelper->setEnabled(false);
    }
}

YCQUiTreeItemImageHelper::~YCQUiTreeItemImageHelper()
{
    YEDITOR_DELETE(m_pTreeItemBoundHelper);
}

void YCQUiTreeItemImageHelper::onItemChangedSource(const QString& rsImageSource)
{
    m_sImageSource = rsImageSource;
    onChanged(m_eImageType, m_sImageSource, m_oRect);
}

void YCQUiTreeItemImageHelper::onItemChangedBound(const QRect& roBound)
{
    m_oRect = roBound;
    onChanged(m_eImageType, m_sImageSource, m_oRect);
}

void YCQUiTreeItemImageHelper::setSource(const QString& rsValue)
{
    m_sImageSource = rsValue;
    if (NULL != m_pEditor)
    {
        m_pEditor->setText(m_sImageSource);
    }
}

void YCQUiTreeItemImageHelper::setBound(const QRect& rBound)
{
    m_oRect = rBound;
    if (NULL != m_pTreeItemBoundHelper)
    {
        m_pTreeItemBoundHelper->setBound(m_oRect);
    }
}
