#ifndef Y_QUITREEITEMBOUNDHELPER_H
#define Y_QUITREEITEMBOUNDHELPER_H

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QSpinBox>

class YCQUiTreeItemBoundHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemBoundHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem);
    virtual ~YCQUiTreeItemBoundHelper();

Q_SIGNALS:
    void onChanged(const QRect& roBound);

public Q_SLOTS:
    void onItemChangedX(int iValue);
    void onItemChangedY(int iValue);
    void onItemChangedW(int iValue);
    void onItemChangedH(int iValue);

public:
    void setBound(const QRect& roBound);
    void setEnabled(const bool& rbEnable);

private:
    void setBoundText(const QRect& roBound);

private:
    QTreeWidgetItem*        m_pTreeItemBound;
    QSpinBox*    m_pSpinBoxX;
    QSpinBox*    m_pSpinBoxY;
    QSpinBox*    m_pSpinBoxW;
    QSpinBox*    m_pSpinBoxH;
    QRect        m_Bound;
};

#endif // Y_QUITREEITEMBOUNDHELPER_H
