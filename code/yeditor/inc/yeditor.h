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

public Q_SLOTS:
	void onClickedOpen();
	void onClickedSave();
	void onClickedExport();
	void onClickedSync();
	void onClickedMenuWindowDockRes();
	void onClickedMenuWindowDockUi();
	void onClickedMenuWindowAreaRes();
	void onClickedMenuWindowAreaUi();
	void onSelectedResTree(QTreeWidgetItem* pTreeItem, int iIndex);
	void onResTreeContextMenu(QPoint oPos);
	void onUiTreeContextMenu(QPoint oPos);

public Q_SLOTS:
	void onPressedResItem(YCQUiItem* pUiItem);

public Q_SLOTS:
	void onResDockVisibilityChanged(bool bVisible);
	void onResAreaVisibilityChanged(bool bVisible);
	void onClickedResMenuItem_ShowHide();
	void onClickedResMenuItem_Tiled();

public Q_SLOTS:
	void onUiDockVisibilityChanged(bool bVisible);
	void onUiAreaVisibilityChanged(bool bVisible);
	void onClickedUiMenuItem_CreateScene();
	void onClickedUiMenuItem_CreatePanel();
	void onClickedUiMenuItem_CreateImage();
	void onClickedUiMenuItem_CreateButton();

private:
	void reloadFile(const yam::ystring& rsFileName);
	void reloadRes(const yam::base::YIFormat*& rpFormat, YCQUiItem* pUiParent, QTreeWidgetItem* pTreeParent);
	void reloadUi(const yam::base::YIWidget*& rpWidget, YCQUiItem* pUiParent, QTreeWidgetItem* pTreeParent);
	QString getFullName(const yam::base::YITree* pTree);
	YCQUiItem* getUiItem(QTreeWidgetItem* pTreeItem) const;
	QTreeWidgetItem* getTreeItem(YCQUiItem* pUiItem) const;

private:
	Ui_MainWindow			m_UI;
	yam::base::YCTree		m_FileTreeData;
	ymnamerelationship		m_mRelationship;
	yam::ystring			m_sFileName;

public:
	const static QString	ms_sTitle;
};

#endif