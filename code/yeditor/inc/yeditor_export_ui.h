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
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *leDirectory;
    QPushButton *pbtnBrowserDirectory;
    QLineEdit *leFileName;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *leLogicName;
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
        groupBox = new QGroupBox(Export);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        leDirectory = new QLineEdit(groupBox);
        leDirectory->setObjectName(QStringLiteral("leDirectory"));

        horizontalLayout_2->addWidget(leDirectory);

        pbtnBrowserDirectory = new QPushButton(groupBox);
        pbtnBrowserDirectory->setObjectName(QStringLiteral("pbtnBrowserDirectory"));

        horizontalLayout_2->addWidget(pbtnBrowserDirectory);


        verticalLayout_3->addLayout(horizontalLayout_2);

        leFileName = new QLineEdit(groupBox);
        leFileName->setObjectName(QStringLiteral("leFileName"));

        verticalLayout_3->addWidget(leFileName);


        verticalLayout->addWidget(groupBox);


        verticalLayout_2->addLayout(verticalLayout);

        groupBox_3 = new QGroupBox(Export);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        leLogicName = new QLineEdit(groupBox_3);
        leLogicName->setObjectName(QStringLiteral("leLogicName"));

        horizontalLayout_3->addWidget(leLogicName);


        verticalLayout_2->addWidget(groupBox_3);

        buttonBox = new QDialogButtonBox(Export);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(Export);
        QObject::connect(buttonBox, SIGNAL(accepted()), Export, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Export, SLOT(reject()));
        QObject::connect(pbtnBrowserDirectory, SIGNAL(clicked()), Export, SLOT(onBrowserDirectory()));

        QMetaObject::connectSlotsByName(Export);
    } // setupUi

    void retranslateUi(QDialog *Export)
    {
        Export->setWindowTitle(QApplication::translate("Export", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("Export", "Json", 0));
        pbtnBrowserDirectory->setText(QApplication::translate("Export", "Browser", 0));
        groupBox_3->setTitle(QApplication::translate("Export", "Set Data", 0));
    } // retranslateUi

};

namespace Ui {
    class Export: public Ui_Export {};
} // namespace Ui

QT_END_NAMESPACE

#endif // YEDITOR_EXPORT_UI_H
