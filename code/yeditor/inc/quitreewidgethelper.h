#ifndef Y_QUITREEWIDGETHELPER_H
#define Y_QUITREEWIDGETHELPER_H

#include "quitreehelper.h"

#include "quitreeitemboundhelper.h"
#include "quitreeitemlayerweighthelper.h"

class YCQUiTreeWidgetHelper : public YCQUiTreeHelper
{
	Q_OBJECT

public:
	explicit YCQUiTreeWidgetHelper(QTreeWidget* pTreeRoot);
	virtual ~YCQUiTreeWidgetHelper();

public Q_SLOTS:
	void onItemChangedBound(const QRect& roBound);
	void onItemChangedLayerWeight(const int& riLayerWeight);

public:
	virtual void setUiItem(YCQUiItem*& rpUiItem);

private:
	YCQUiTreeItemBoundHelper*			m_pTreeItemBoundHelper;
	YCQUiTreeItemLayerWeightHelper*		m_pTreeItemLayerWeightHelper;
};

#endif // Y_QUITREEWIDGETHELPER_H
