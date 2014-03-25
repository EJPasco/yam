#include "quitreeitemsizehelper.h"

YCQUiTreeItemSizeHelper::YCQUiTreeItemSizeHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem)
    : m_pTreeItemSize(NULL)
    , m_pSpinBoxWidth(NULL)
    , m_pSpinBoxHeight(NULL)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    m_pTreeItemSize = new QTreeWidgetItem;
    m_pTreeItemSize->setText(0, tr("Size"));
    pTreeItem->addChild(m_pTreeItemSize);

    {
        m_pSpinBoxWidth = new QSpinBox;
        m_pSpinBoxWidth->setRange(1, INT_MAX);
        m_pSpinBoxWidth->setValue(0);
        connect(m_pSpinBoxWidth, SIGNAL(valueChanged(int)), this, SLOT(onItemChangedWidth(int)));
        QTreeWidgetItem* pTreeWidth = new QTreeWidgetItem;
        pTreeWidth->setText(0, tr("width"));
        m_pTreeItemSize->addChild(pTreeWidth);
        pTreeRoot->setItemWidget(pTreeWidth, 1, m_pSpinBoxWidth);

        m_pSpinBoxHeight = new QSpinBox;
        m_pSpinBoxHeight->setRange(1, INT_MAX);
        m_pSpinBoxHeight->setValue(0);
        connect(m_pSpinBoxHeight, SIGNAL(valueChanged(int)), this, SLOT(onItemChangedHeight(int)));
        QTreeWidgetItem* pTreeHeight = new QTreeWidgetItem;
        pTreeHeight->setText(0, tr("height"));
        m_pTreeItemSize->addChild(pTreeHeight);
        pTreeRoot->setItemWidget(pTreeHeight, 1, m_pSpinBoxHeight);
    }

    setSizeText(m_Size);
}

YCQUiTreeItemSizeHelper::~YCQUiTreeItemSizeHelper()
{
    //
}

void YCQUiTreeItemSizeHelper::onItemChangedWidth(int iValue)
{
    m_Size.setWidth(iValue);

    setSizeText(m_Size);

    onChanged(m_Size);
}

void YCQUiTreeItemSizeHelper::onItemChangedHeight(int iValue)
{
    m_Size.setHeight(iValue);

    setSizeText(m_Size);

    onChanged(m_Size);
}

void YCQUiTreeItemSizeHelper::setSize(const QSize& roSize)
{
    m_Size = roSize;

    setSizeText(m_Size);

    if (NULL != m_pSpinBoxWidth)
    {
        m_pSpinBoxWidth->setValue(m_Size.width());
    }
    if (NULL != m_pSpinBoxHeight)
    {
        m_pSpinBoxHeight->setValue(m_Size.height());
    }
}

void YCQUiTreeItemSizeHelper::setSizeText(const QSize& roSize)
{
    if (NULL == m_pTreeItemSize)
    {
        return;
    }

    QString sSize;
    sSize.sprintf("%d, %d", roSize.width(), roSize.height());
    m_pTreeItemSize->setText(1, sSize);
}
