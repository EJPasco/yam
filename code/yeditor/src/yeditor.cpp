#include "yeditor.h"

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
	QApplication a(argc, argv);
	YEditor editor;
	editor.show();
	return a.exec();
}