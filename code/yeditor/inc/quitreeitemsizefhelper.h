#ifndef Y_QUITREEITEMSIZEFHELPER_H
#define Y_QUITREEITEMSIZEFHELPER_H

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QSpinBox>

class YCQUiTreeItemSizefHelper : public QObject
{
	Q_OBJECT

public:
	explicit YCQUiTreeItemSizefHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem);
	virtual ~YCQUiTreeItemSizefHelper();

Q_SIGNALS:
    void onChanged(const QSizeF& roSize);

public Q_SLOTS:
	void onItemChangedWidth(double dValue);
	void onItemChangedHeight(double dValue);

public:
	void setSize(const QSizeF& roSize);

private:
	void setSizeText(const QSizeF& roSize);

private:
    QTreeWidgetItem*        m_pTreeItemSize;
    QDoubleSpinBox*               m_pSpinBoxWidth;
    QDoubleSpinBox*               m_pSpinBoxHeight;
    QSizeF                  m_Size;
};

#endif // Y_QUITREEITEMSIZEFHELPER_H
