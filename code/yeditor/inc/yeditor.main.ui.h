/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef YEDITOR_H
#define YEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "quiarea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionSync;
    QAction *actionBarOpen;
    QAction *actionBarSave;
    QAction *actionBarSync;
    QAction *actionExport;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    YCQUiArea *uiArea;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QDockWidget *formatDock;
    QWidget *formatDockLayout;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *formatTree;
    QDockWidget *uiTreeDock;
    QWidget *uiTreeLayout;
    QVBoxLayout *verticalLayout;
    QTreeView *uiTree;
    QDockWidget *uiDetailDock;
    QWidget *uiDetailLayout;
    QVBoxLayout *verticalLayout_3;
    QToolBox *varBox;
    QWidget *basePage;
    QVBoxLayout *verticalLayout_4;
    QListView *varList;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(853, 532);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setMenuRole(QAction::QuitRole);
        actionSync = new QAction(MainWindow);
        actionSync->setObjectName(QStringLiteral("actionSync"));
        actionBarOpen = new QAction(MainWindow);
        actionBarOpen->setObjectName(QStringLiteral("actionBarOpen"));
        actionBarSave = new QAction(MainWindow);
        actionBarSave->setObjectName(QStringLiteral("actionBarSave"));
        actionBarSync = new QAction(MainWindow);
        actionBarSync->setObjectName(QStringLiteral("actionBarSync"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        uiArea = new YCQUiArea(centralwidget);
        uiArea->setObjectName(QStringLiteral("uiArea"));
        uiArea->setFrameShape(QFrame::Panel);
        uiArea->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(uiArea);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 853, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        formatDock = new QDockWidget(MainWindow);
        formatDock->setObjectName(QStringLiteral("formatDock"));
        formatDock->setFeatures(QDockWidget::DockWidgetMovable);
        formatDockLayout = new QWidget();
        formatDockLayout->setObjectName(QStringLiteral("formatDockLayout"));
        verticalLayout_2 = new QVBoxLayout(formatDockLayout);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formatTree = new QTreeWidget(formatDockLayout);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        formatTree->setHeaderItem(__qtreewidgetitem);
        formatTree->setObjectName(QStringLiteral("formatTree"));

        verticalLayout_2->addWidget(formatTree);

        formatDock->setWidget(formatDockLayout);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), formatDock);
        uiTreeDock = new QDockWidget(MainWindow);
        uiTreeDock->setObjectName(QStringLiteral("uiTreeDock"));
        uiTreeDock->setFeatures(QDockWidget::DockWidgetMovable);
        uiTreeLayout = new QWidget();
        uiTreeLayout->setObjectName(QStringLiteral("uiTreeLayout"));
        verticalLayout = new QVBoxLayout(uiTreeLayout);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        uiTree = new QTreeView(uiTreeLayout);
        uiTree->setObjectName(QStringLiteral("uiTree"));
        uiTree->setFrameShape(QFrame::Panel);

        verticalLayout->addWidget(uiTree);

        uiTreeDock->setWidget(uiTreeLayout);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), uiTreeDock);
        uiDetailDock = new QDockWidget(MainWindow);
        uiDetailDock->setObjectName(QStringLiteral("uiDetailDock"));
        uiDetailLayout = new QWidget();
        uiDetailLayout->setObjectName(QStringLiteral("uiDetailLayout"));
        verticalLayout_3 = new QVBoxLayout(uiDetailLayout);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        varBox = new QToolBox(uiDetailLayout);
        varBox->setObjectName(QStringLiteral("varBox"));
        basePage = new QWidget();
        basePage->setObjectName(QStringLiteral("basePage"));
        basePage->setGeometry(QRect(0, 0, 274, 192));
        verticalLayout_4 = new QVBoxLayout(basePage);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        varList = new QListView(basePage);
        varList->setObjectName(QStringLiteral("varList"));
        varList->setFrameShape(QFrame::Panel);
        varList->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(varList);

        varBox->addItem(basePage, QStringLiteral("Base"));

        verticalLayout_3->addWidget(varBox);

        uiDetailDock->setWidget(uiDetailLayout);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), uiDetailDock);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExport);
        menuFile->addAction(actionSync);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        toolBar->addAction(actionBarOpen);
        toolBar->addAction(actionBarSave);
        toolBar->addSeparator();
        toolBar->addAction(actionBarSync);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(onClickedOpen()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainWindow, SLOT(onClickedSave()));
        QObject::connect(actionSync, SIGNAL(triggered()), MainWindow, SLOT(onClickedSync()));
        QObject::connect(actionBarOpen, SIGNAL(triggered()), MainWindow, SLOT(onClickedOpen()));
        QObject::connect(actionBarSave, SIGNAL(triggered()), MainWindow, SLOT(onClickedSave()));
        QObject::connect(actionBarSync, SIGNAL(triggered()), MainWindow, SLOT(onClickedSync()));
        QObject::connect(formatTree, SIGNAL(itemClicked(QTreeWidgetItem*,int)), MainWindow, SLOT(onSelectedFormatTree(QTreeWidgetItem*,int)));
        QObject::connect(actionExport, SIGNAL(triggered()), MainWindow, SLOT(onClickedExport()));

        varBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionSync->setText(QApplication::translate("MainWindow", "Sync", 0));
        actionBarOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionBarSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionBarSync->setText(QApplication::translate("MainWindow", "Sync", 0));
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        formatDock->setWindowTitle(QApplication::translate("MainWindow", "Format", 0));
        uiTreeDock->setWindowTitle(QApplication::translate("MainWindow", "UI Tree", 0));
        uiDetailDock->setWindowTitle(QApplication::translate("MainWindow", "UI Detail", 0));
        varBox->setItemText(varBox->indexOf(basePage), QApplication::translate("MainWindow", "Base", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // YEDITOR_H
