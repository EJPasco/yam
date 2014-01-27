#include "quitreewidgethelper.h"

YCQUiTreeWidgetHelper::YCQUiTreeWidgetHelper(QTreeWidget* pTreeRoot)
	: YCQUiTreeHelper(pTreeRoot)
	, m_pTreeItemBoundHelper(NULL)
	, m_pTreeItemLayerWeightHelper(NULL)
{
	//
}

YCQUiTreeWidgetHelper::~YCQUiTreeWidgetHelper()
{
	if (NULL != m_pTreeItemBoundHelper)
	{
		delete m_pTreeItemBoundHelper;
		m_pTreeItemBoundHelper = NULL;
	}
	if (NULL != m_pTreeItemLayerWeightHelper)
	{
		delete m_pTreeItemLayerWeightHelper;
		m_pTreeItemLayerWeightHelper = NULL;
	}
}

void YCQUiTreeWidgetHelper::onItemChangedBound(const QRect& roBound)
{
	if (NULL == m_pUiItem)
	{
		return;
	}
	m_pUiItem->move(roBound.topLeft());
	m_pUiItem->resize(roBound.size());
}

void YCQUiTreeWidgetHelper::onItemChangedLayerWeight(const int& riLayerWeight)
{
	if (NULL == m_pUiItem)
	{
		return;
	}
	m_pUiItem->setLayerWeight(riLayerWeight);
}

void YCQUiTreeWidgetHelper::setUiItem(YCQUiItem*& rpUiItem)
{
	__super::setUiItem(rpUiItem);
	if (NULL == rpUiItem)
	{
		return;
	}

	QTreeWidgetItem* pTreeWidget = new QTreeWidgetItem;
	pTreeWidget->setText(0, tr("Widget"));
	m_pTreeRoot->insertTopLevelItem(m_pTreeRoot->topLevelItemCount(), pTreeWidget);

	if (NULL == m_pTreeItemBoundHelper)
	{
		m_pTreeItemBoundHelper = new YCQUiTreeItemBoundHelper(m_pTreeRoot, pTreeWidget);
		m_pTreeItemBoundHelper->setBound(rpUiItem->rect());
		connect(m_pTreeItemBoundHelper, SIGNAL(onChanged(const QRect&)), this, SLOT(onItemChangedBound(const QRect&)));
	}

	if (NULL == m_pTreeItemLayerWeightHelper)
	{
		m_pTreeItemLayerWeightHelper =  new YCQUiTreeItemLayerWeightHelper(m_pTreeRoot, pTreeWidget);
		m_pTreeItemLayerWeightHelper->setLayerWeight(rpUiItem->getLayerWeight());
		connect(m_pTreeItemLayerWeightHelper, SIGNAL(onChanged(const int&)), this, SLOT(onItemChangedLayerWeight(const int&)));
	}
}
