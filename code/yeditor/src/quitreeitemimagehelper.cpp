#include "quitreeitemimagehelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

#include "yeditorcommon.h"
#include "quitreeitemimageshelper.h"
#include "quitreeitempointhelper.h"
#include "quitreeitemboundhelper.h"

YCQUiTreeItemImageHelper::YCQUiTreeItemImageHelper(YCQUiTreeItemImagesHelper* pImagesHelper, QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const yam::yint32& riIndex, const QString sName /*= "Image"*/)
    : m_pImagesHelper(pImagesHelper)
    , m_pTreeItemImage(NULL)
    , m_pEditor(NULL)
    , m_pTreeItemPointHelper(NULL)
    , m_sImageSource("")
    , m_iImageIndex(riIndex)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    m_pTreeItemImage = new QTreeWidgetItem;
    m_pTreeItemImage->setText(0, sName);
    pTreeItem->addChild(m_pTreeItemImage);

    {
        QPushButton* ppbDelButton = new QPushButton;
        ppbDelButton->setText("delete");
        connect(ppbDelButton, SIGNAL(clicked()), this, SLOT(onDelButtonClicked()));
        pTreeRoot->setItemWidget(m_pTreeItemImage, 1, ppbDelButton);
    }

    {
        m_pEditor = new QLineEdit;
        m_pEditor->setText(m_sImageSource);
        connect(m_pEditor, SIGNAL(textChanged(const QString&)), this, SLOT(onItemChangedSource(const QString&)));
        QTreeWidgetItem* pTreeImageSrc = new QTreeWidgetItem;
        pTreeImageSrc->setText(0, tr("source"));
        m_pTreeItemImage->addChild(pTreeImageSrc);
        pTreeRoot->setItemWidget(pTreeImageSrc, 1, m_pEditor);
    }

    {
        m_pTreeItemPointHelper = new YCQUiTreeItemPointHelper(pTreeRoot, m_pTreeItemImage, "offset");
        connect(m_pTreeItemPointHelper, SIGNAL(onChanged(const QPoint&)), this, SLOT(onItemChangedOffset(const QPoint&)));
    }
}

YCQUiTreeItemImageHelper::~YCQUiTreeItemImageHelper()
{
    YEDITOR_DELETE(m_pTreeItemPointHelper);
}

void YCQUiTreeItemImageHelper::onItemChangedSource(const QString& rsImageSource)
{
    m_sImageSource = rsImageSource;
    onChanged(m_iImageIndex, this);
}

void YCQUiTreeItemImageHelper::onItemChangedOffset(const QPoint& roOffset)
{
    m_oOffset = roOffset;
    onChanged(m_iImageIndex, this);
}

void YCQUiTreeItemImageHelper::onDelButtonClicked()
{
    m_pImagesHelper->toDeleteImageHelper(this);
}

void YCQUiTreeItemImageHelper::setText(const QString& rsName)
{
    m_pTreeItemImage->setText(0, rsName);
}

const QString& YCQUiTreeItemImageHelper::getSource() const
{
    return m_sImageSource;
}

void YCQUiTreeItemImageHelper::setSource(const QString& rsValue)
{
    m_sImageSource = rsValue;
    if (NULL != m_pEditor)
    {
        m_pEditor->setText(m_sImageSource);
    }
}

const QPoint& YCQUiTreeItemImageHelper::getOffset() const
{
    return m_oOffset;
}

void YCQUiTreeItemImageHelper::setOffset(const QPoint& rOffset)
{
    m_oOffset = rOffset;
}

void YCQUiTreeItemImageHelper::setIndex(const yam::yint32& riIndex)
{
    m_iImageIndex = riIndex;
}

QTreeWidgetItem* YCQUiTreeItemImageHelper::getTreeWidgetItem()
{
    return m_pTreeItemImage;
}
