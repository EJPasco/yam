#ifndef Y_QUITREEITEMLAYERWEIGHTHELPER_H
#define Y_QUITREEITEMLAYERWEIGHTHELPER_H

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QSpinBox>

class YCQUiTreeItemLayerWeightHelper : public QObject
{
	Q_OBJECT

public:
	explicit YCQUiTreeItemLayerWeightHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem);
	virtual ~YCQUiTreeItemLayerWeightHelper();

Q_SIGNALS:
	void onChanged(const int& riLayerWeight);

public Q_SLOTS:
	void onItemChanged(int iValue);

public:
	void setLayerWeight(const int& riLayerWeight);

private:
	QSpinBox*	m_pSpinBox;
	int			m_iLayerWeight;
};

#endif // Y_QUITREEITEMLAYERWEIGHTHELPER_H
