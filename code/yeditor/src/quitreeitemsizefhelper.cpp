#include "quitreeitemsizefhelper.h"

YCQUiTreeItemSizefHelper::YCQUiTreeItemSizefHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem)
    : m_pTreeItemSize(NULL)
    , m_pSpinBoxWidth(NULL)
    , m_pSpinBoxHeight(NULL)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    m_pTreeItemSize = new QTreeWidgetItem;
    m_pTreeItemSize->setText(0, tr("Sizef"));
    pTreeItem->addChild(m_pTreeItemSize);

    {
        m_pSpinBoxWidth = new QDoubleSpinBox;
        m_pSpinBoxWidth->setRange(1, INT_MAX);
        m_pSpinBoxWidth->setValue(0);
        connect(m_pSpinBoxWidth, SIGNAL(valueChanged(double)), this, SLOT(onItemChangedWidth(double)));
        QTreeWidgetItem* pTreeWidth = new QTreeWidgetItem;
        pTreeWidth->setText(0, tr("Width"));
        m_pTreeItemSize->addChild(pTreeWidth);
        pTreeRoot->setItemWidget(pTreeWidth, 1, m_pSpinBoxWidth);

        m_pSpinBoxHeight = new QDoubleSpinBox;
        m_pSpinBoxHeight->setRange(1, INT_MAX);
        m_pSpinBoxHeight->setValue(0);
        connect(m_pSpinBoxHeight, SIGNAL(valueChanged(double)), this, SLOT(onItemChangedHeight(double)));
        QTreeWidgetItem* pTreeHeight = new QTreeWidgetItem;
        pTreeHeight->setText(0, tr("Height"));
        m_pTreeItemSize->addChild(pTreeHeight);
        pTreeRoot->setItemWidget(pTreeHeight, 1, m_pSpinBoxHeight);
    }
}

YCQUiTreeItemSizefHelper::~YCQUiTreeItemSizefHelper()
{
    //
}

void YCQUiTreeItemSizefHelper::onItemChangedWidth(double dValue)
{
    m_Size.setWidth(dValue);

    setSizeText(m_Size);

    onChanged(m_Size);
}

void YCQUiTreeItemSizefHelper::onItemChangedHeight(double dValue)
{
    m_Size.setHeight(dValue);

    setSizeText(m_Size);

    onChanged(m_Size);
}

void YCQUiTreeItemSizefHelper::setSize(const QSizeF& roSize)
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

void YCQUiTreeItemSizefHelper::setSizeText(const QSizeF& roSize)
{
    if (NULL == m_pTreeItemSize)
    {
        return;
    }

    QString sSize;
    sSize.sprintf("%f, %f", roSize.width(), roSize.height());
    m_pTreeItemSize->setText(1, sSize);
}
