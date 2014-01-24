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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
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
    QAction *actionBarExport;
    QAction *actionDockRes;
    QAction *actionDockUi;
    QAction *actionFff;
    QAction *actionAreaRes;
    QAction *actionAreaUi;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *resAreaGroupBox;
    QVBoxLayout *verticalLayout_8;
    YCQUiArea *resArea;
    QGroupBox *uiAreaGroupBox;
    QVBoxLayout *verticalLayout_9;
    YCQUiArea *uiArea;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuWindow;
    QMenu *menuDock;
    QMenu *menuArea;
    QStatusBar *statusbar;
    QDockWidget *resDock;
    QWidget *resDockLayout;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *resTree;
    QGroupBox *resPropertyGroupBox;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *resPropertyTableWidget;
    QDockWidget *uiDock;
    QWidget *uiTreeLayout;
    QVBoxLayout *verticalLayout;
    QTreeWidget *uiTree;
    QGroupBox *uiPropertyGroupBox;
    QVBoxLayout *verticalLayout_6;
    QToolBox *uiPropertyBox;
    QWidget *uiBasicPage;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *uiBasicTableWidget;
    QWidget *uiAdvancedPage;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *uiAdvancedTableWidget;
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
        actionBarExport = new QAction(MainWindow);
        actionBarExport->setObjectName(QStringLiteral("actionBarExport"));
        actionDockRes = new QAction(MainWindow);
        actionDockRes->setObjectName(QStringLiteral("actionDockRes"));
        actionDockRes->setCheckable(true);
        actionDockRes->setChecked(true);
        actionDockUi = new QAction(MainWindow);
        actionDockUi->setObjectName(QStringLiteral("actionDockUi"));
        actionDockUi->setCheckable(true);
        actionDockUi->setChecked(true);
        actionFff = new QAction(MainWindow);
        actionFff->setObjectName(QStringLiteral("actionFff"));
        actionAreaRes = new QAction(MainWindow);
        actionAreaRes->setObjectName(QStringLiteral("actionAreaRes"));
        actionAreaRes->setCheckable(true);
        actionAreaRes->setChecked(true);
        actionAreaUi = new QAction(MainWindow);
        actionAreaUi->setObjectName(QStringLiteral("actionAreaUi"));
        actionAreaUi->setCheckable(true);
        actionAreaUi->setChecked(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        resAreaGroupBox = new QGroupBox(centralwidget);
        resAreaGroupBox->setObjectName(QStringLiteral("resAreaGroupBox"));
        verticalLayout_8 = new QVBoxLayout(resAreaGroupBox);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        resArea = new YCQUiArea(resAreaGroupBox);
        resArea->setObjectName(QStringLiteral("resArea"));
        resArea->setFrameShape(QFrame::Panel);
        resArea->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(resArea);


        horizontalLayout_3->addWidget(resAreaGroupBox);

        uiAreaGroupBox = new QGroupBox(centralwidget);
        uiAreaGroupBox->setObjectName(QStringLiteral("uiAreaGroupBox"));
        verticalLayout_9 = new QVBoxLayout(uiAreaGroupBox);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        uiArea = new YCQUiArea(uiAreaGroupBox);
        uiArea->setObjectName(QStringLiteral("uiArea"));
        uiArea->setFrameShape(QFrame::Panel);
        uiArea->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(uiArea);


        horizontalLayout_3->addWidget(uiAreaGroupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 853, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuDock = new QMenu(menuWindow);
        menuDock->setObjectName(QStringLiteral("menuDock"));
        menuArea = new QMenu(menuWindow);
        menuArea->setObjectName(QStringLiteral("menuArea"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        resDock = new QDockWidget(MainWindow);
        resDock->setObjectName(QStringLiteral("resDock"));
        resDock->setFloating(false);
        resDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
        resDockLayout = new QWidget();
        resDockLayout->setObjectName(QStringLiteral("resDockLayout"));
        verticalLayout_2 = new QVBoxLayout(resDockLayout);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        resTree = new QTreeWidget(resDockLayout);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        resTree->setHeaderItem(__qtreewidgetitem);
        resTree->setObjectName(QStringLiteral("resTree"));
        resTree->setContextMenuPolicy(Qt::CustomContextMenu);

        verticalLayout_2->addWidget(resTree);

        resPropertyGroupBox = new QGroupBox(resDockLayout);
        resPropertyGroupBox->setObjectName(QStringLiteral("resPropertyGroupBox"));
        verticalLayout_7 = new QVBoxLayout(resPropertyGroupBox);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        resPropertyTableWidget = new QTableWidget(resPropertyGroupBox);
        resPropertyTableWidget->setObjectName(QStringLiteral("resPropertyTableWidget"));
        resPropertyTableWidget->setFrameShape(QFrame::Panel);

        verticalLayout_7->addWidget(resPropertyTableWidget);


        verticalLayout_2->addWidget(resPropertyGroupBox);

        resDock->setWidget(resDockLayout);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), resDock);
        uiDock = new QDockWidget(MainWindow);
        uiDock->setObjectName(QStringLiteral("uiDock"));
        uiDock->setFloating(false);
        uiDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
        uiTreeLayout = new QWidget();
        uiTreeLayout->setObjectName(QStringLiteral("uiTreeLayout"));
        verticalLayout = new QVBoxLayout(uiTreeLayout);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        uiTree = new QTreeWidget(uiTreeLayout);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(1, QStringLiteral("2"));
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        uiTree->setHeaderItem(__qtreewidgetitem1);
        uiTree->setObjectName(QStringLiteral("uiTree"));
        uiTree->setContextMenuPolicy(Qt::CustomContextMenu);
        uiTree->setFrameShape(QFrame::Panel);
        uiTree->setColumnCount(2);

        verticalLayout->addWidget(uiTree);

        uiPropertyGroupBox = new QGroupBox(uiTreeLayout);
        uiPropertyGroupBox->setObjectName(QStringLiteral("uiPropertyGroupBox"));
        verticalLayout_6 = new QVBoxLayout(uiPropertyGroupBox);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        uiPropertyBox = new QToolBox(uiPropertyGroupBox);
        uiPropertyBox->setObjectName(QStringLiteral("uiPropertyBox"));
        uiBasicPage = new QWidget();
        uiBasicPage->setObjectName(QStringLiteral("uiBasicPage"));
        uiBasicPage->setGeometry(QRect(0, 0, 185, 182));
        verticalLayout_4 = new QVBoxLayout(uiBasicPage);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        uiBasicTableWidget = new QTableWidget(uiBasicPage);
        uiBasicTableWidget->setObjectName(QStringLiteral("uiBasicTableWidget"));
        uiBasicTableWidget->setFrameShape(QFrame::Panel);

        verticalLayout_4->addWidget(uiBasicTableWidget);

        uiPropertyBox->addItem(uiBasicPage, QStringLiteral("Basic"));
        uiAdvancedPage = new QWidget();
        uiAdvancedPage->setObjectName(QStringLiteral("uiAdvancedPage"));
        verticalLayout_5 = new QVBoxLayout(uiAdvancedPage);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        uiAdvancedTableWidget = new QTableWidget(uiAdvancedPage);
        uiAdvancedTableWidget->setObjectName(QStringLiteral("uiAdvancedTableWidget"));
        uiAdvancedTableWidget->setFrameShape(QFrame::Panel);

        verticalLayout_5->addWidget(uiAdvancedTableWidget);

        uiPropertyBox->addItem(uiAdvancedPage, QStringLiteral("Advanced"));

        verticalLayout_6->addWidget(uiPropertyBox);


        verticalLayout->addWidget(uiPropertyGroupBox);

        uiDock->setWidget(uiTreeLayout);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), uiDock);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExport);
        menuFile->addAction(actionSync);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuWindow->addAction(menuDock->menuAction());
        menuWindow->addAction(menuArea->menuAction());
        menuDock->addAction(actionDockRes);
        menuDock->addAction(actionDockUi);
        menuArea->addAction(actionAreaRes);
        menuArea->addAction(actionAreaUi);
        toolBar->addAction(actionBarOpen);
        toolBar->addAction(actionBarSave);
        toolBar->addSeparator();
        toolBar->addAction(actionBarExport);
        toolBar->addAction(actionBarSync);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(onClickedOpen()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainWindow, SLOT(onClickedSave()));
        QObject::connect(actionSync, SIGNAL(triggered()), MainWindow, SLOT(onClickedSync()));
        QObject::connect(actionBarOpen, SIGNAL(triggered()), MainWindow, SLOT(onClickedOpen()));
        QObject::connect(actionBarSave, SIGNAL(triggered()), MainWindow, SLOT(onClickedSave()));
        QObject::connect(actionBarSync, SIGNAL(triggered()), MainWindow, SLOT(onClickedSync()));
        QObject::connect(resTree, SIGNAL(itemClicked(QTreeWidgetItem*,int)), MainWindow, SLOT(onSelectedResTree(QTreeWidgetItem*,int)));
        QObject::connect(actionBarExport, SIGNAL(triggered()), MainWindow, SLOT(onClickedExport()));
        QObject::connect(actionExport, SIGNAL(triggered()), MainWindow, SLOT(onClickedExport()));
        QObject::connect(resTree, SIGNAL(customContextMenuRequested(QPoint)), MainWindow, SLOT(onResTreeContextMenu(QPoint)));
        QObject::connect(uiTree, SIGNAL(customContextMenuRequested(QPoint)), MainWindow, SLOT(onUiTreeContextMenu(QPoint)));
        QObject::connect(actionDockRes, SIGNAL(triggered()), MainWindow, SLOT(onClickedMenuWindowDockRes()));
        QObject::connect(actionDockUi, SIGNAL(triggered()), MainWindow, SLOT(onClickedMenuWindowDockUi()));
        QObject::connect(actionAreaUi, SIGNAL(triggered()), MainWindow, SLOT(onClickedMenuWindowAreaUi()));
        QObject::connect(actionAreaRes, SIGNAL(triggered()), MainWindow, SLOT(onClickedMenuWindowAreaRes()));
        QObject::connect(resDock, SIGNAL(visibilityChanged(bool)), MainWindow, SLOT(onResDockVisibilityChanged(bool)));
        QObject::connect(resArea, SIGNAL(visibilityChanged(bool)), MainWindow, SLOT(onResAreaVisibilityChanged(bool)));
        QObject::connect(uiDock, SIGNAL(visibilityChanged(bool)), MainWindow, SLOT(onUiDockVisibilityChanged(bool)));
        QObject::connect(uiArea, SIGNAL(visibilityChanged(bool)), MainWindow, SLOT(onUiAreaVisibilityChanged(bool)));

        uiPropertyBox->setCurrentIndex(0);


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
        actionBarExport->setText(QApplication::translate("MainWindow", "Export", 0));
        actionDockRes->setText(QApplication::translate("MainWindow", "Resource", 0));
        actionDockUi->setText(QApplication::translate("MainWindow", "Ui", 0));
        actionFff->setText(QApplication::translate("MainWindow", "fff", 0));
        actionAreaRes->setText(QApplication::translate("MainWindow", "Resource", 0));
        actionAreaUi->setText(QApplication::translate("MainWindow", "Ui", 0));
        resAreaGroupBox->setTitle(QApplication::translate("MainWindow", "Resource Area", 0));
        uiAreaGroupBox->setTitle(QApplication::translate("MainWindow", "Ui Area", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0));
        menuDock->setTitle(QApplication::translate("MainWindow", "Dock", 0));
        menuArea->setTitle(QApplication::translate("MainWindow", "Area", 0));
        resDock->setWindowTitle(QApplication::translate("MainWindow", "Resource", 0));
        resPropertyGroupBox->setTitle(QApplication::translate("MainWindow", "Property", 0));
        uiDock->setWindowTitle(QApplication::translate("MainWindow", "UI", 0));
        uiPropertyGroupBox->setTitle(QApplication::translate("MainWindow", "Property", 0));
        uiPropertyBox->setItemText(uiPropertyBox->indexOf(uiBasicPage), QApplication::translate("MainWindow", "Basic", 0));
        uiPropertyBox->setItemText(uiPropertyBox->indexOf(uiAdvancedPage), QApplication::translate("MainWindow", "Advanced", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // YEDITOR_H
