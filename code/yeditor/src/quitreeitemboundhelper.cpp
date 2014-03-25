#include "quitreeitemboundhelper.h"

YCQUiTreeItemBoundHelper::YCQUiTreeItemBoundHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, std::string sName /*= "bound"*/)
    : m_pTreeItemBound(NULL)
    , m_pSpinBoxX(NULL)
    , m_pSpinBoxY(NULL)
    , m_pSpinBoxW(NULL)
    , m_pSpinBoxH(NULL)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    m_pTreeItemBound = new QTreeWidgetItem;
    m_pTreeItemBound->setText(0, tr(sName.c_str()));
    pTreeItem->addChild(m_pTreeItemBound);

    {
        m_pSpinBoxX = new QSpinBox;
        m_pSpinBoxX->setRange(INT_MIN, INT_MAX);
        m_pSpinBoxX->setValue(0);
        connect(m_pSpinBoxX, SIGNAL(valueChanged(int)), this, SLOT(onItemChangedX(int)));
        QTreeWidgetItem* pTreeBoundX = new QTreeWidgetItem;
        pTreeBoundX->setText(0, tr("X"));
        m_pTreeItemBound->addChild(pTreeBoundX);
        pTreeRoot->setItemWidget(pTreeBoundX, 1, m_pSpinBoxX);

        m_pSpinBoxY = new QSpinBox;
        m_pSpinBoxY->setRange(INT_MIN, INT_MAX);
        m_pSpinBoxY->setValue(0);
        connect(m_pSpinBoxY, SIGNAL(valueChanged(int)), this, SLOT(onItemChangedY(int)));
        QTreeWidgetItem* pTreeBoundY = new QTreeWidgetItem;
        pTreeBoundY->setText(0, tr("Y"));
        m_pTreeItemBound->addChild(pTreeBoundY);
        pTreeRoot->setItemWidget(pTreeBoundY, 1, m_pSpinBoxY);

        m_pSpinBoxW = new QSpinBox;
        m_pSpinBoxW->setRange(1, INT_MAX);
        m_pSpinBoxW->setValue(0);
        connect(m_pSpinBoxW, SIGNAL(valueChanged(int)), this, SLOT(onItemChangedW(int)));
        QTreeWidgetItem* pTreeBoundW = new QTreeWidgetItem;
        pTreeBoundW->setText(0, tr("Width"));
        m_pTreeItemBound->addChild(pTreeBoundW);
        pTreeRoot->setItemWidget(pTreeBoundW, 1, m_pSpinBoxW);

        m_pSpinBoxH = new QSpinBox;
        m_pSpinBoxH->setRange(1, INT_MAX);
        m_pSpinBoxH->setValue(0);
        connect(m_pSpinBoxH, SIGNAL(valueChanged(int)), this, SLOT(onItemChangedH(int)));
        QTreeWidgetItem* pTreeBoundH = new QTreeWidgetItem;
        pTreeBoundH->setText(0, tr("Height"));
        m_pTreeItemBound->addChild(pTreeBoundH);
        pTreeRoot->setItemWidget(pTreeBoundH, 1, m_pSpinBoxH);
    }

    pTreeRoot->collapseItem(pTreeItem);
}

YCQUiTreeItemBoundHelper::~YCQUiTreeItemBoundHelper()
{
    //
}

void YCQUiTreeItemBoundHelper::onItemChangedX(int iValue)
{
    int iWidth = m_Bound.width();
    m_Bound.setX(iValue);
    m_Bound.setWidth(iWidth);

    setBoundText(m_Bound);

    onChanged(m_Bound);
}

void YCQUiTreeItemBoundHelper::onItemChangedY(int iValue)
{
    int iHeight = m_Bound.height();
    m_Bound.setY(iValue);
    m_Bound.setHeight(iHeight);

    setBoundText(m_Bound);

    onChanged(m_Bound);
}

void YCQUiTreeItemBoundHelper::onItemChangedW(int iValue)
{
    m_Bound.setWidth(iValue);

    setBoundText(m_Bound);

    onChanged(m_Bound);
}

void YCQUiTreeItemBoundHelper::onItemChangedH(int iValue)
{
    m_Bound.setHeight(iValue);

    setBoundText(m_Bound);

    onChanged(m_Bound);
}

void YCQUiTreeItemBoundHelper::setBound(const QRect& roBound)
{
    m_Bound = roBound;

    setBoundText(m_Bound);

    if (NULL != m_pSpinBoxX)
    {
        m_pSpinBoxX->setValue(m_Bound.x());
    }
    if (NULL != m_pSpinBoxY)
    {
        m_pSpinBoxY->setValue(m_Bound.y());
    }
    if (NULL != m_pSpinBoxW)
    {
        m_pSpinBoxW->setValue(m_Bound.width());
    }
    if (NULL != m_pSpinBoxH)
    {
        m_pSpinBoxH->setValue(m_Bound.height());
    }
}

void YCQUiTreeItemBoundHelper::setEnabled(const bool& rbEnable)
{
    if (NULL != m_pSpinBoxX)
    {
        m_pSpinBoxX->setEnabled(rbEnable);
    }
    if (NULL != m_pSpinBoxY)
    {
        m_pSpinBoxY->setEnabled(rbEnable);
    }
    if (NULL != m_pSpinBoxW)
    {
        m_pSpinBoxW->setEnabled(rbEnable);
    }
    if (NULL != m_pSpinBoxH)
    {
        m_pSpinBoxH->setEnabled(rbEnable);
    }
    //
}

void YCQUiTreeItemBoundHelper::setBoundText(const QRect& roBound)
{
    if (NULL == m_pTreeItemBound)
    {
        return;
    }
    QString sBound;
    sBound.sprintf("%d, %d, %d, %d", roBound.x(), roBound.y(), roBound.width(), roBound.height());
    m_pTreeItemBound->setText(1, sBound);
}
