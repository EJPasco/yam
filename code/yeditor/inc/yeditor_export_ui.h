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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Export
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *leDirectory;
    QPushButton *pbtnBrowserDirectory;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *leFileName;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Export)
    {
        if (Export->objectName().isEmpty())
            Export->setObjectName(QStringLiteral("Export"));
        Export->resize(346, 138);
        Export->setModal(true);
        verticalLayout_2 = new QVBoxLayout(Export);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(Export);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        leDirectory = new QLineEdit(Export);
        leDirectory->setObjectName(QStringLiteral("leDirectory"));

        horizontalLayout_2->addWidget(leDirectory);

        pbtnBrowserDirectory = new QPushButton(Export);
        pbtnBrowserDirectory->setObjectName(QStringLiteral("pbtnBrowserDirectory"));

        horizontalLayout_2->addWidget(pbtnBrowserDirectory);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(Export);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        leFileName = new QLineEdit(Export);
        leFileName->setObjectName(QStringLiteral("leFileName"));

        horizontalLayout->addWidget(leFileName);


        verticalLayout_2->addLayout(horizontalLayout);

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
        label->setText(QApplication::translate("Export", "Path:", 0));
        pbtnBrowserDirectory->setText(QApplication::translate("Export", "Browser", 0));
        label_2->setText(QApplication::translate("Export", "Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class Export: public Ui_Export {};
} // namespace Ui

QT_END_NAMESPACE

#endif // YEDITOR_EXPORT_UI_H
