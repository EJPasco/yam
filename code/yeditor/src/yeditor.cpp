#include "yeditor.h"

#include "json.h"

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

	json::Object obj;
	obj["coin"] = 1.0f;
	obj["title"] = "hello world";
	std::string sRes = json::Serialize(obj);

	CYPanel* pPanel = new CYPanel;
	CYPanel* pPanelA = pPanel->NewChild<CYPanel>();
	CYWidget* pWidgetA = pPanelA->NewChild<CYWidget>();
	CYPanel* pPanelB = pPanel->NewChild<CYPanel>();
	CYWidget* pWidgetB = pPanelB->NewChild<CYWidget>();

	pPanel->GetId() = "root";
	pPanel->GetBound().Pos.X = 1;
	pPanel->GetBound().Pos.Y = 2;
	pPanel->GetBound().Size.X = 3;
	pPanel->GetBound().Size.Y = 4;

	pPanelA->GetId() = "pPanelA";
	pPanelA->GetBound().Pos.X = 5;
	pPanelA->GetBound().Pos.Y = 6;
	pPanelA->GetBound().Size.X = 7;
	pPanelA->GetBound().Size.Y = 8;

	pWidgetA->GetId() = "pWidgetA";
	pWidgetA->GetBound().Pos.X = 9;
	pWidgetA->GetBound().Pos.Y = 10;
	pWidgetA->GetBound().Size.X = 11;
	pWidgetA->GetBound().Size.Y = 12;

	pPanelB->GetId() = "pPanelB";
	pPanelB->GetBound().Pos.X = 13;
	pPanelB->GetBound().Pos.Y = 14;
	pPanelB->GetBound().Size.X = 15;
	pPanelB->GetBound().Size.Y = 16;

	pWidgetB->GetId() = "pWidgetB";
	pWidgetB->GetBound().Pos.X = 17;
	pWidgetB->GetBound().Pos.Y = 18;
	pWidgetB->GetBound().Size.X = 19;
	pWidgetB->GetBound().Size.Y = 20;

	yam::ystring sFileName = "test.yui";
	yam::file::CYFile::Instance().Save(sFileName, pPanel);
	delete pPanel; pPanel = NULL;

	IYWidget* pWidget = YNULL;
	yam::file::CYFile::Instance().Load(sFileName, pWidget);
	delete pWidget; pWidget = YNULL;

	QApplication a(argc, argv);
	YEditor editor;
	editor.show();
	return a.exec();
}