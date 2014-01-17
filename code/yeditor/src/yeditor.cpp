#include "yeditor.h"

#include "yexport.h"

#include <crtdbg.h>

#include <QtWidgets/QApplication>

#ifdef _WINDOWS
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif // _WINDOWS_

const QString YEditor::ms_sTitle = "Yam Editor";

YEditor::YEditor(QWidget* pParent /* = NULL */)
	: QMainWindow(pParent)
{
	setWindowTitle(ms_sTitle);

	m_UI.setupUi(this);
}

YEditor::~YEditor()
{
	//
}

void YEditor::onClickedOpen()
{
	qDebug("on clicked open");
	//
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

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	QApplication a(argc, argv);
	YEditor editor;
	editor.setWindowTitle(YEditor::ms_sTitle);
	editor.show();
	return a.exec();
}