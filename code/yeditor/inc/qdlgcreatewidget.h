#ifndef Y_QDLGCREATEWIDGET_H
#define Y_QDLGCREATEWIDGET_H

#include "yeditorcommon.h"

#include "yeditor_createwidget_ui.h"

#include <QtWidgets/QDialog>

typedef struct tagConfigCreateWidget
{
    QString     _sId;
} SConfigCreateWidget;

class YCQDlgCreateWidget : public QDialog
{
    Q_OBJECT;

public:
    static bool showDialog(SConfigCreateWidget& rstConfig, QWidget *parent = 0);

public:
    YCQDlgCreateWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    virtual ~YCQDlgCreateWidget();

public:
    bool toConfig(SConfigCreateWidget& rstConfig) const;

protected:
    bool toCheck(const SConfigCreateWidget& rstConfig) const;

private:
    Ui_CreateWidget     m_Ui;
};

#endif // Y_QDLGCREATEWIDGET_H
