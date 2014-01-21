#ifndef Y_YEDITOR_H
#define Y_YEDITOR_H

#include "yeditor.main.ui.h"

#include <json.h>
#include <yam.h>

#include <QtWidgets/QMainWindow>

#define YNAME_FILE_PSFORMAT		"psformat"
#define YNAME_FILE_UIWIDGET		"uiwidget"

class YEditor : public QMainWindow
{
	struct SRelationship
	{
		YCQUiItem*			_pUiItem;
		QTreeWidgetItem*	_pTreeItem;
	};
	typedef std::map<QString, SRelationship>		ymnamerelationship;

	Q_OBJECT

public:
	YEditor(QWidget* pParent = NULL);
	virtual ~YEditor();

public slots:
	void onClickedOpen();
	void onClickedSave();
	void onClickedExport();
	void onClickedSync();
	void onSelectedFormatTree(QTreeWidgetItem* pTreeItem, int iIndex);
	void onFormatTreeContextMenu(QPoint oPos);
	void onUiTreeContextMenu(QPoint oPos);

public slots:
	void onClickedFormatMenuItem_ShowHide();

public slots:
	void onClickedUiWidgetMenuItem_CreateScene();
	void onClickedUiWidgetMenuItem_CreatePanel();
	void onClickedUiWidgetMenuItem_CreateImage();
	void onClickedUiWidgetMenuItem_CreateButton();

private:
	void reloadFormat(const yam::base::YIFormat*& rpFormat, YCQUiItem* pUiParent, QTreeWidgetItem* pTreeParent);
	void reloadWidget(const yam::base::YIWidget*& rpWidget, YCQUiItem* pUiParent, QTreeWidgetItem* pTreeParent);
	QString getFullName(const yam::base::YITree* pTree);
	YCQUiItem* getUiItem(QTreeWidgetItem* pTreeItem) const;

private:
	Ui_MainWindow			m_UI;
	yam::base::YCTree		m_FileTreeData;
	ymnamerelationship		m_mRelationship;

public:
	const static QString	ms_sTitle;
};

#endif