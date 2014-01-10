#include "yeditor.h"

#include "yexport.h"

#include <crtdbg.h>

#include <QtWidgets/QApplication>

YEditor::YEditor(QWidget* pParent /* = NULL */)
	: QMainWindow(pParent)
{
	ui.setupUi(this);

	yam::output::YIPsFormat* ff = new yam::output::YCPsFormat;
	delete ff;
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

	/*yam::ystring sFileNameT = "testa.yui";
	yam::ystring sst = "test";
	yam::yint32 sit = 10;

	yam::yofstream ost;
	ost.open(sFileNameT, std::ios::out | std::ios::binary);
	//yam::file::YCFile::Instance().Write(ost, sit);
	//yam::file::YCFile::Instance().Write(ost, sst);
	ost << sst;
	ost.close();
	yam::yifstream ist;
	ist.open(sFileNameT, std::ios::in | std::ios::binary);
	sit = 50;
	sst = "";
	//yam::file::YCFile::Instance().Read(ist, sit);
	//yam::file::YCFile::Instance().Read(ist, sst);
	ist >> sst;
	if (ist.eof())
	{
		sst = "00";
	}
	ist.close();*/

	/*yam::ystring sFileName = "test.yui";

	YCPanel* pPanel = new YCPanel;
	yam::ybuffsize rrsize = pPanel->SizeOfData();

	YCPanel* pPanelA = pPanel->NewChild<YCPanel>();
	rrsize = pPanel->SizeOfData();
	YCPanel* pPanelB = pPanel->NewChild<YCPanel>();
	rrsize = pPanel->SizeOfData();
	rrsize = pPanelA->SizeOfData();
	rrsize = pPanelB->SizeOfData();

	YCWidget* pWidgetA = pPanelA->NewChild<YCWidget>();
	rrsize = pWidgetA->SizeOfData();
	rrsize = pPanel->SizeOfData();
	YCWidget* pWidgetB = pPanelB->NewChild<YCWidget>();
	rrsize = pPanel->SizeOfData();

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
	rrsize = pPanel->SizeOfData();

	yam::file::YCFile::Instance().Save(sFileName, pPanel);
	delete pPanel; pPanel = YNULL;

	YIWidget* pWidget = YNULL;
	yam::file::YCFile::Instance().Load(sFileName, pWidget);
	delete pWidget; pWidget = YNULL;
	
	YIFormat* pFormat = new YCFormat;
	yam::file::YCFile::Instance().Save(sFileName, pFormat);
	delete pFormat; pFormat = YNULL;
	yam::file::YCFile::Instance().Load(sFileName, pFormat);
	delete pFormat; pFormat = YNULL;*/

	QApplication a(argc, argv);
	YEditor editor;
	editor.show();
	return a.exec();
}