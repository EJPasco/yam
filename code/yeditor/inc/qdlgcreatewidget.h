#ifndef Y_QDLGCREATEWIDGET_H
#define Y_QDLGCREATEWIDGET_H

#include "yeditorcommon.h"

#include "yeditor_createwidget_ui.h"

#include <QtWidgets/QDialog>

class YCQDlgCreateWidget : public QDialog
{
    Q_OBJECT;

public:
    YCQDlgCreateWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    virtual ~YCQDlgCreateWidget();

public:
    QString getId() const;

private:
    Ui_CreateWidget     m_Ui;
};

#endif // Y_QDLGCREATEWIDGET_H
