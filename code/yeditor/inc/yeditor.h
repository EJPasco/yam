#ifndef Y_YEDITOR_H
#define Y_YEDITOR_H

#include "yeditor.main.ui.h"

#include <json.h>
#include <yam.h>

#include <QtWidgets/QMainWindow>

class YEditor : public QMainWindow
{
	Q_OBJECT

public:
	YEditor(QWidget* pParent = NULL);
	virtual ~YEditor();

public slots:
	void onClickedOpen();
	void onClickedSave();
	void onClickedSync();

private:
	Ui_MainWindow			m_UI;

public:
	const static QString	ms_sTitle;
};

#endif