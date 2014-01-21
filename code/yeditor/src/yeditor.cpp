#include "yeditor.h"

#include "yexport.h"
#include "yrectpacker.h"

#include <crtdbg.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QBoxLayout>

#ifdef _WINDOWS
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif // _WINDOWS_

const QString YEditor::ms_sTitle = "Yam Editor";

YEditor::YEditor(QWidget* pParent /* = NULL */)
	: QMainWindow(pParent)
{
	setWindowTitle(ms_sTitle);

	m_UI.setupUi(this);
	//
}

YEditor::~YEditor()
{
	//
}

void YEditor::onClickedOpen()
{
	qDebug("on clicked open");

	int isize = 0;
	if (m_UI.uiArea->layout() != NULL)
	{
		isize = m_UI.uiArea->layout()->children().size();
	}

	yam::ystring sFileName = "";
	{
		QString qsFileName = QFileDialog::getOpenFileName(this, tr("Open a yui file"), "", tr("YUI (*.yui)"));
		sFileName.append(qsFileName.toLocal8Bit());
	}
	
	yam::storage::YCFileReader file;
	file.Open(sFileName);
	yam::base::YCBuffer buffer;
	file >> buffer;
	file.Close();
	m_FileTreeData.Clear();
	m_FileTreeData << buffer;

	yam::base::YITree* pTreePsFormat = m_FileTreeData.FindChild("psformat");
	if (YNULL == pTreePsFormat || YOBJECT_GETCLASSNAME(yam::base::YCFormat) != pTreePsFormat->GetClassName())
	{
		return;
	}
	m_UI.uiArea->clearChildrenItem();
	m_UI.formatTree->clear();
	m_mRelationship.clear();

	const yam::base::YIFormat* pFormat = (yam::base::YIFormat*)pTreePsFormat;
	reloadFormat(pFormat, NULL, NULL);
}

void YEditor::onClickedSave()
{
	qDebug("on clicked save");
	//
}

void YEditor::onClickedExport()
{
	yam::yvvec2d vSize;
	yam::YVec2D stSize;
	stSize.X = 50; stSize.Y = 50;
	vSize.push_back(stSize);
	stSize.X = 50; stSize.Y = 50;
	vSize.push_back(stSize);
	stSize.X = 50; stSize.Y = 50;
	vSize.push_back(stSize);
	stSize.X = 50; stSize.Y = 50;
	vSize.push_back(stSize);
	stSize.X = 500; stSize.Y = 500;
	yam::yvrect vRect;
	YCRectPacker::Instance().Do(vSize, stSize, vRect);
	/*QImage* pImage = new QImage;
	delete pImage;*/
}

void YEditor::onClickedSync()
{
	qDebug("on clicked sync");
	//
}

void YEditor::onSelectedFormatTree(QTreeWidgetItem* pTreeItem, int iIndex)
{
	if (NULL == pTreeItem)
	{
		return;
	}
	YCQUiItem* pUiItem = getUiItem(pTreeItem);
	if (NULL == pUiItem)
	{
		return;
	}
	pUiItem->setSelected(true);
}

void YEditor::reloadFormat(const yam::base::YIFormat*& rpFormat, YCQUiItem* pUiParent, QTreeWidgetItem* pTreeParent)
{
	if (YNULL == rpFormat)
	{
		return;
	}

	YCQUiItem* pUiItem = m_UI.uiArea->addChildItem(rpFormat);

	QTreeWidgetItem* pTreeItem = new QTreeWidgetItem;
	pTreeItem->setText(0, rpFormat->GetId().c_str());
	if (NULL == pTreeParent)
	{
		m_UI.formatTree->insertTopLevelItem(0, pTreeItem);
	}
	else
	{
		pTreeParent->insertChild(0, pTreeItem);
	}

	SRelationship stRelationship;
	stRelationship._pUiItem = pUiItem;
	stRelationship._pTreeItem = pTreeItem;
	m_mRelationship.insert(std::make_pair(getFullName(rpFormat), stRelationship));

	const yam::base::YITree* pTreeNext = rpFormat->GetNext();
	if (YNULL != pTreeNext && YOBJECT_GETCLASSNAME(yam::base::YCFormat) == pTreeNext->GetClassName())
	{
		const yam::base::YIFormat* pFormatNext = (const yam::base::YIFormat*)pTreeNext;
		reloadFormat(pFormatNext, pUiParent, pTreeParent);
	}

	const yam::base::YITree* pTreeChildren = rpFormat->GetChildren();
	if (YNULL != pTreeChildren && YOBJECT_GETCLASSNAME(yam::base::YCFormat) == pTreeChildren->GetClassName())
	{
		const yam::base::YIFormat* pFormatChildren = (const yam::base::YIFormat*)pTreeChildren;
		reloadFormat(pFormatChildren, pUiItem, pTreeItem);
	}
}

QString YEditor::getFullName(const yam::base::YITree* pTree)
{
	QString sRes = "";
	if (YNULL != pTree)
	{
		sRes.append(".");
		sRes.append(pTree->GetId().c_str());
		sRes.append(getFullName(pTree->GetParent()));
	}
	return sRes;
}

YCQUiItem* YEditor::getUiItem(QTreeWidgetItem* pTreeItem) const
{
	if (NULL == pTreeItem)
	{
		return NULL;
	}

	ymnamerelationship::const_iterator cit = m_mRelationship.begin();
	ymnamerelationship::const_iterator citEnd = m_mRelationship.end();
	for (; cit != citEnd; ++cit)
	{
		if (pTreeItem != cit->second._pTreeItem)
		{
			continue;
		}
		return cit->second._pUiItem;
	}
	return NULL;
}

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	QApplication a(argc, argv);
	YEditor editor;
	editor.setWindowTitle(YEditor::ms_sTitle);
	editor.show();
	return a.exec();
}