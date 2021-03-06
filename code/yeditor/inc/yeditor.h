#ifndef Y_YEDITOR_H
#define Y_YEDITOR_H

#include "yeditorcommon.h"

#include "yeditor_main_ui.h"

#include <QtWidgets/QMainWindow>

class YCQUiTreeResHelper;
class YCQUiTreeUiHelper;

class YEditor : public QMainWindow
{
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
    void onResTreeItemSelected(QTreeWidgetItem* pTreeItem, int iColumn);
    void onResTreeContextMenu(QPoint oPos);
    void onUiTreeItemSelected(QTreeWidgetItem* pTreeItem, int iColumn);
    void onUiTreeContextMenu(QPoint oPos);

public Q_SLOTS:
    void onSelectedResItem(YCQUiItem* pUiItem);
    void onSelectedUiItem(YCQUiItem* pUiItem);

public Q_SLOTS:
    void onResDockVisibilityChanged(bool bVisible);
    void onResAreaVisibilityChanged(bool bVisible);
    void onClickedResMenuItem_CopyImageSource();
    void onClickedResMenuItem_Tiled();

public Q_SLOTS:
    void onUiDockVisibilityChanged(bool bVisible);
    void onUiAreaVisibilityChanged(bool bVisible);
    void onClickedUiMenuItem_CreateScene();
    void onClickedUiMenuItem_CreatePanel();
    void onClickedUiMenuItem_CreateImage();
    void onClickedUiMenuItem_CreateButton();
    void onClickedUiMenuItem_CreateText();
    void onClickedUiMenuItem_EditRemove();

private:
    void reloadFile(const yam::ystring& rsFileName);
    void reloadRes(const yam::base::YIFormat*& rpFormat, YCQUiItem* pUiParent, QTreeWidgetItem* pTreeParent);
    void reloadUi(const yam::base::YIWidget*& rpWidget, YCQUiItem* pUiParent, QTreeWidgetItem* pTreeParent);
    bool readyToCreate(QTreeWidgetItem*& rpTreeWidgetItem, SConfigCreateWidget& rstConfig);

public:
    static yam::ystring getFullName(const yam::base::YITree* pTree);
    static SRelationship getRelationship(const yam::ystring& rsKey);
    static YCQUiTreeItem* getTreeItem(const YCQUiItem* pUiItem);
    static YCQUiItem* getUiItem(const QTreeWidgetItem* pTreeItem);
    static void removeUiItem(QTreeWidgetItem*& rpTreeItem, const bool bRemove = true);

private:
    void refreshResProperty(YCQUiItem*& rpUiItem);
    void refreshUiProperty(YCQUiItem*& rpUiItem);

private:
    void parseArgument(const QStringList& rvStr);

private:
    Ui_MainWindow               m_Ui;
    yam::ystring                m_sFileName;
    YCQUiTreeResHelper*         m_pTreeResHelper;
    YCQUiTreeUiHelper*          m_pTreeUiHelper;
};

#endif