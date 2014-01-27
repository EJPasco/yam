#include "quitreeitemlayerweighthelper.h"

YCQUiTreeItemLayerWeightHelper::YCQUiTreeItemLayerWeightHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem)
	: m_pSpinBox(NULL)
	, m_iLayerWeight(0)
{
	if (NULL == pTreeRoot || NULL == pTreeItem)
	{
		return;
	}

	m_pSpinBox = new QSpinBox;
	m_pSpinBox->setRange(0, 8);
	m_pSpinBox->setValue(0);
	connect(m_pSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onItemChanged(int)));
	QTreeWidgetItem* pTree = new QTreeWidgetItem;
	pTree->setText(0, tr("Layer Weight"));
	pTreeItem->addChild(pTree);
	pTreeRoot->setItemWidget(pTree, 1, m_pSpinBox);
}

YCQUiTreeItemLayerWeightHelper::~YCQUiTreeItemLayerWeightHelper()
{
	if (NULL != m_pSpinBox)
	{
		delete m_pSpinBox;
		m_pSpinBox = NULL;
	}
}

void YCQUiTreeItemLayerWeightHelper::onItemChanged(int iValue)
{
	m_iLayerWeight = iValue;
	onChanged(m_iLayerWeight);
}

void YCQUiTreeItemLayerWeightHelper::setLayerWeight(const int& riLayerWeight)
{
	m_iLayerWeight = riLayerWeight;

	if (NULL != m_pSpinBox)
	{
		m_pSpinBox->setValue(m_iLayerWeight);
	}
}
