#include "quitreeitemimagehelper.h"

YCQUiTreeItemImageHelper::YCQUiTreeItemImageHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem)
	: m_pTreeItemImage(NULL)
	, m_pEditor(NULL)
	, m_sImageSource("")
{
	if (NULL == pTreeRoot || NULL == pTreeItem)
	{
		return;
	}

	m_pTreeItemImage = new QTreeWidgetItem;
	m_pTreeItemImage->setText(0, tr("Image"));
	pTreeItem->addChild(m_pTreeItemImage);

	{
		m_pEditor = new QLineEdit;
		m_pEditor->setText(m_sImageSource);
		connect(m_pEditor, SIGNAL(editingFinished()), this, SLOT(onItemChangedSource()));
		QTreeWidgetItem* pTreeImageSrc = new QTreeWidgetItem;
		pTreeImageSrc->setText(0, tr("Source"));
		m_pTreeItemImage->addChild(pTreeImageSrc);
		pTreeRoot->setItemWidget(pTreeImageSrc, 1, m_pEditor);
	}
	//
}

YCQUiTreeItemImageHelper::~YCQUiTreeItemImageHelper()
{
	if (NULL != m_pTreeItemImage)
	{
		delete m_pTreeItemImage;
		m_pTreeItemImage = NULL;
	}
	if (NULL != m_pEditor)
	{
		delete m_pEditor;
		m_pEditor = NULL;
	}
}

void YCQUiTreeItemImageHelper::onItemChangedSource()
{
	m_sImageSource = m_pEditor->text();
	onChangedSource(m_sImageSource);
}

void YCQUiTreeItemImageHelper::setImageSource(const QString& rsValue)
{
	m_sImageSource = rsValue;
	if (NULL != m_pEditor)
	{
		m_pEditor->setText(m_sImageSource);
	}
}
