#include "yeditor.h"

#include <crtdbg.h>

#include <QtWidgets/QApplication>

YEditor::YEditor(QWidget* pParent /* = NULL */)
	: QMainWindow(pParent)
{
	ui.setupUi(this);
}

YEditor::~YEditor()
{
	//
}

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	using namespace yam::base;
	CYPanel* pPanel = new CYPanel;
	CYPanel* pPanelA = pPanel->NewChild<CYPanel>();
	pPanelA->NewChild<CYWidget>();
	CYPanel* pPanelB = pPanel->NewChild<CYPanel>();
	pPanelB->NewChild<CYWidget>();
	delete pPanel; pPanel = NULL;


	QApplication a(argc, argv);
	YEditor editor;
	editor.show();
	return a.exec();
}