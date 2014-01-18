#include "yeditor.h"

#include "yexport.h"

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

	const yam::base::YIFormat* pFormat = (yam::base::YIFormat*)pTreePsFormat;
	reloadFormat(pFormat);
}

void YEditor::onClickedSave()
{
	qDebug("on clicked save");
	//
}

void YEditor::onClickedSync()
{
	qDebug("on clicked sync");
	//
}

void YEditor::reloadFormat(const yam::base::YIFormat*& rpFormat)
{
	if (YNULL == rpFormat)
	{
		return;
	}

	m_UI.uiArea->addChildItem(rpFormat);

	const yam::base::YITree* pTreeNext = rpFormat->GetNext();
	if (YNULL != pTreeNext && YOBJECT_GETCLASSNAME(yam::base::YCFormat) == pTreeNext->GetClassName())
	{
		const yam::base::YIFormat* pFormatNext = (const yam::base::YIFormat*)pTreeNext;
		reloadFormat(pFormatNext);
	}

	const yam::base::YITree* pTreeChildren = rpFormat->GetChildren();
	if (YNULL != pTreeChildren && YOBJECT_GETCLASSNAME(yam::base::YCFormat) == pTreeChildren->GetClassName())
	{
		const yam::base::YIFormat* pFormatChildren = (const yam::base::YIFormat*)pTreeChildren;
		reloadFormat(pFormatChildren);
	}
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