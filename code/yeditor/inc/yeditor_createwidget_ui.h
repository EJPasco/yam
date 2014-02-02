/********************************************************************************
** Form generated from reading UI file 'createwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef YEDITOR_CREATEWIDGET_UI_H
#define YEDITOR_CREATEWIDGET_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateWidget
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *idLineEdit;

    void setupUi(QDialog *CreateWidget)
    {
        if (CreateWidget->objectName().isEmpty())
            CreateWidget->setObjectName(QStringLiteral("CreateWidget"));
        CreateWidget->resize(400, 300);
        buttonBox = new QDialogButtonBox(CreateWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        idLineEdit = new QLineEdit(CreateWidget);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));
        idLineEdit->setGeometry(QRect(50, 20, 113, 20));

        retranslateUi(CreateWidget);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateWidget, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateWidget, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateWidget);
    } // setupUi

    void retranslateUi(QDialog *CreateWidget)
    {
        CreateWidget->setWindowTitle(QApplication::translate("CreateWidget", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateWidget: public Ui_CreateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // YEDITOR_CREATEWIDGET_UI_H
