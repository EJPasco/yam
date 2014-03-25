#ifndef Y_QUITREEITEMPOINTHELPER_H
#define Y_QUITREEITEMPOINTHELPER_H

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QSpinBox>

class YCQUiTreeItemPointHelper : public QObject
{
	Q_OBJECT

public:
	explicit YCQUiTreeItemPointHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, std::string sName = "Point");
	virtual ~YCQUiTreeItemPointHelper();

Q_SIGNALS:
    void onChanged(const QPoint& roSize);

public Q_SLOTS:
	void onItemChangedX(int iValue);
	void onItemChangedY(int iValue);

public:
	void setPoint(const QPoint& roPoint);

private:
	void setPointText(const QPoint& roPoint);

private:
    QTreeWidgetItem*        m_pTreeItemMain;
    QSpinBox*               m_psbX;
    QSpinBox*               m_psbY;
    QPoint                  m_Point;
};

#endif // Y_QUITREEITEMPOINTHELPER_H
