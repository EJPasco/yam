#include "quitreeitemboundfhelper.h"

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QDoubleSpinBox>

YCQUiTreeItemBoundfHelper::YCQUiTreeItemBoundfHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem)
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
    m_pTreeItemBound->setText(0, tr("Boundf"));
    pTreeItem->addChild(m_pTreeItemBound);

    {
        m_pSpinBoxX = new QDoubleSpinBox;
        m_pSpinBoxX->setRange(INT_MIN, INT_MAX);
        m_pSpinBoxX->setValue(0);
        connect(m_pSpinBoxX, SIGNAL(valueChanged(double)), this, SLOT(onItemChangedX(double)));
        QTreeWidgetItem* pTreeBoundX = new QTreeWidgetItem;
        pTreeBoundX->setText(0, tr("X"));
        m_pTreeItemBound->addChild(pTreeBoundX);
        pTreeRoot->setItemWidget(pTreeBoundX, 1, m_pSpinBoxX);

        m_pSpinBoxY = new QDoubleSpinBox;
        m_pSpinBoxY->setRange(INT_MIN, INT_MAX);
        m_pSpinBoxY->setValue(0);
        connect(m_pSpinBoxY, SIGNAL(valueChanged(double)), this, SLOT(onItemChangedY(double)));
        QTreeWidgetItem* pTreeBoundY = new QTreeWidgetItem;
        pTreeBoundY->setText(0, tr("Y"));
        m_pTreeItemBound->addChild(pTreeBoundY);
        pTreeRoot->setItemWidget(pTreeBoundY, 1, m_pSpinBoxY);

        m_pSpinBoxW = new QDoubleSpinBox;
        m_pSpinBoxW->setRange(1, INT_MAX);
        m_pSpinBoxW->setValue(0);
        connect(m_pSpinBoxW, SIGNAL(valueChanged(double)), this, SLOT(onItemChangedW(double)));
        QTreeWidgetItem* pTreeBoundW = new QTreeWidgetItem;
        pTreeBoundW->setText(0, tr("Width"));
        m_pTreeItemBound->addChild(pTreeBoundW);
        pTreeRoot->setItemWidget(pTreeBoundW, 1, m_pSpinBoxW);

        m_pSpinBoxH = new QDoubleSpinBox;
        m_pSpinBoxH->setRange(1, INT_MAX);
        m_pSpinBoxH->setValue(0);
        connect(m_pSpinBoxH, SIGNAL(valueChanged(double)), this, SLOT(onItemChangedH(double)));
        QTreeWidgetItem* pTreeBoundH = new QTreeWidgetItem;
        pTreeBoundH->setText(0, tr("Height"));
        m_pTreeItemBound->addChild(pTreeBoundH);
        pTreeRoot->setItemWidget(pTreeBoundH, 1, m_pSpinBoxH);
    }
}

YCQUiTreeItemBoundfHelper::~YCQUiTreeItemBoundfHelper()
{
    //
}

void YCQUiTreeItemBoundfHelper::onItemChangedX(double dValue)
{
    float fWidth = m_Bound.width();
    m_Bound.setX(dValue);
    m_Bound.setWidth(fWidth);

    setBoundText(m_Bound);

    onChanged(m_Bound);
}

void YCQUiTreeItemBoundfHelper::onItemChangedY(double dValue)
{
    int fHeight = m_Bound.height();
    m_Bound.setY(dValue);
    m_Bound.setHeight(fHeight);

    setBoundText(m_Bound);

    onChanged(m_Bound);
}

void YCQUiTreeItemBoundfHelper::onItemChangedW(double dValue)
{
    m_Bound.setWidth(dValue);

    setBoundText(m_Bound);

    onChanged(m_Bound);
}

void YCQUiTreeItemBoundfHelper::onItemChangedH(double dValue)
{
    m_Bound.setHeight(dValue);

    setBoundText(m_Bound);

    onChanged(m_Bound);
}

void YCQUiTreeItemBoundfHelper::setBound(const QRectF& roBound)
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

void YCQUiTreeItemBoundfHelper::setBoundText(const QRectF& roBound)
{
    if (NULL == m_pTreeItemBound)
    {
        return;
    }
    QString sBound;
    sBound.sprintf("%f, %f, %f, %f", roBound.x(), roBound.y(), roBound.width(), roBound.height());
    m_pTreeItemBound->setText(1, sBound);
}
