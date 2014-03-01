#ifndef Y_QUITREEITEMBOUNDFHELPER_H
#define Y_QUITREEITEMBOUNDFHELPER_H

#include <QtCore/QObject>
#include <QtCore/QRect>

class QTreeWidget;
class QTreeWidgetItem;
class QDoubleSpinBox;

class YCQUiTreeItemBoundfHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemBoundfHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem);
    virtual ~YCQUiTreeItemBoundfHelper();

Q_SIGNALS:
    void onChanged(const QRectF& roBound);

public Q_SLOTS:
    void onItemChangedX(double dValue);
    void onItemChangedY(double dValue);
    void onItemChangedW(double dValue);
    void onItemChangedH(double dValue);

public:
    void setBound(const QRectF& roBound);

private:
    void setBoundText(const QRectF& roBound);

private:
    QTreeWidgetItem*        m_pTreeItemBound;
    QDoubleSpinBox*    m_pSpinBoxX;
    QDoubleSpinBox*    m_pSpinBoxY;
    QDoubleSpinBox*    m_pSpinBoxW;
    QDoubleSpinBox*    m_pSpinBoxH;
    QRectF       m_Bound;
};

#endif // Y_QUITREEITEMBOUNDFHELPER_H
