#include "quitreeitempointhelper.h"

YCQUiTreeItemPointHelper::YCQUiTreeItemPointHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, std::string sName /*= "Point"*/)
    : m_pTreeItemMain(NULL)
    , m_psbX(NULL)
    , m_psbY(NULL)
{
    if (NULL == pTreeRoot || NULL == pTreeItem)
    {
        return;
    }

    m_pTreeItemMain = new QTreeWidgetItem;
    m_pTreeItemMain->setText(0, tr(sName.c_str()));
    pTreeItem->addChild(m_pTreeItemMain);

    {
        m_psbX = new QSpinBox;
        m_psbX->setRange(INT_MIN, INT_MAX);
        m_psbX->setValue(0);
        connect(m_psbX, SIGNAL(valueChanged(int)), this, SLOT(onItemChangedX(int)));
        QTreeWidgetItem* pTreeWidth = new QTreeWidgetItem;
        pTreeWidth->setText(0, tr("x"));
        m_pTreeItemMain->addChild(pTreeWidth);
        pTreeRoot->setItemWidget(pTreeWidth, 1, m_psbX);

        m_psbY = new QSpinBox;
        m_psbY->setRange(INT_MIN, INT_MAX);
        m_psbY->setValue(0);
        connect(m_psbY, SIGNAL(valueChanged(int)), this, SLOT(onItemChangedY(int)));
        QTreeWidgetItem* pTreeHeight = new QTreeWidgetItem;
        pTreeHeight->setText(0, tr("y"));
        m_pTreeItemMain->addChild(pTreeHeight);
        pTreeRoot->setItemWidget(pTreeHeight, 1, m_psbY);
    }

    setPointText(m_Point);
}

YCQUiTreeItemPointHelper::~YCQUiTreeItemPointHelper()
{
    //
}

void YCQUiTreeItemPointHelper::onItemChangedX(int iValue)
{
    m_Point.setX(iValue);

    setPointText(m_Point);

    onChanged(m_Point);
}

void YCQUiTreeItemPointHelper::onItemChangedY(int iValue)
{
    m_Point.setY(iValue);

    setPointText(m_Point);

    onChanged(m_Point);
}

void YCQUiTreeItemPointHelper::setPoint(const QPoint& roPoint)
{
    m_Point = roPoint;

    setPointText(m_Point);

    if (NULL != m_psbX)
    {
        m_psbX->setValue(m_Point.x());
    }
    if (NULL != m_psbY)
    {
        m_psbY->setValue(m_Point.y());
    }
}

void YCQUiTreeItemPointHelper::setPointText(const QPoint& roPoint)
{
    if (NULL == m_pTreeItemMain)
    {
        return;
    }

    QString sSize;
    m_pTreeItemMain->setText(1, sSize.sprintf("%d, %d", roPoint.x(), roPoint.y()));
}
