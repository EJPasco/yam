/********************************************************************************
** Form generated from reading UI file 'export.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef YEDITOR_EXPORT_UI_H
#define YEDITOR_EXPORT_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Export
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *leLogicName;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leJsonFileName;
    QPushButton *pbtnJsonFileBrowser;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lePngFileName;
    QPushButton *pbtnPngFileBrowser;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Export)
    {
        if (Export->objectName().isEmpty())
            Export->setObjectName(QStringLiteral("Export"));
        Export->resize(346, 235);
        Export->setModal(true);
        verticalLayout_2 = new QVBoxLayout(Export);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_3 = new QGroupBox(Export);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        leLogicName = new QLineEdit(groupBox_3);
        leLogicName->setObjectName(QStringLiteral("leLogicName"));

        horizontalLayout_3->addWidget(leLogicName);


        verticalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(Export);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leJsonFileName = new QLineEdit(groupBox);
        leJsonFileName->setObjectName(QStringLiteral("leJsonFileName"));

        horizontalLayout->addWidget(leJsonFileName);

        pbtnJsonFileBrowser = new QPushButton(groupBox);
        pbtnJsonFileBrowser->setObjectName(QStringLiteral("pbtnJsonFileBrowser"));

        horizontalLayout->addWidget(pbtnJsonFileBrowser);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Export);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lePngFileName = new QLineEdit(groupBox_2);
        lePngFileName->setObjectName(QStringLiteral("lePngFileName"));

        horizontalLayout_2->addWidget(lePngFileName);

        pbtnPngFileBrowser = new QPushButton(groupBox_2);
        pbtnPngFileBrowser->setObjectName(QStringLiteral("pbtnPngFileBrowser"));

        horizontalLayout_2->addWidget(pbtnPngFileBrowser);


        verticalLayout->addWidget(groupBox_2);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(Export);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(Export);
        QObject::connect(buttonBox, SIGNAL(accepted()), Export, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Export, SLOT(reject()));
        QObject::connect(pbtnJsonFileBrowser, SIGNAL(clicked()), Export, SLOT(onBrowserJson()));
        QObject::connect(pbtnPngFileBrowser, SIGNAL(clicked()), Export, SLOT(onBrowserPng()));

        QMetaObject::connectSlotsByName(Export);
    } // setupUi

    void retranslateUi(QDialog *Export)
    {
        Export->setWindowTitle(QApplication::translate("Export", "Dialog", 0));
        groupBox_3->setTitle(QApplication::translate("Export", "Logic", 0));
        groupBox->setTitle(QApplication::translate("Export", "Json", 0));
        pbtnJsonFileBrowser->setText(QApplication::translate("Export", "Browser", 0));
        groupBox_2->setTitle(QApplication::translate("Export", "Png", 0));
        pbtnPngFileBrowser->setText(QApplication::translate("Export", "Browser", 0));
    } // retranslateUi

};

namespace Ui {
    class Export: public Ui_Export {};
} // namespace Ui

QT_END_NAMESPACE

#endif // YEDITOR_EXPORT_UI_H
