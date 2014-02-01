#ifndef Y_QUITREEITEMSIZEHELPER_H
#define Y_QUITREEITEMSIZEHELPER_H

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QSpinBox>

class YCQUiTreeItemSizeHelper : public QObject
{
	Q_OBJECT

public:
	explicit YCQUiTreeItemSizeHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem);
	virtual ~YCQUiTreeItemSizeHelper();

Q_SIGNALS:
    void onChanged(const QSize& roSize);

public Q_SLOTS:
	void onItemChangedWidth(int iValue);
	void onItemChangedHeight(int iValue);

public:
	void setSize(const QSize& roSize);

private:
	void setSizeText(const QSize& roSize);

private:
    QTreeWidgetItem*        m_pTreeItemSize;
    QSpinBox*               m_pSpinBoxWidth;
    QSpinBox*               m_pSpinBoxHeight;
    QSize                   m_Size;
};

#endif // Y_QUITREEITEMSIZEHELPER_H
