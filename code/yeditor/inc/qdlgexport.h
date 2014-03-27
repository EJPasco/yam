#ifndef Y_QDLGEXPORT_H
#define Y_QDLGEXPORT_H

#include "yeditorcommon.h"

#include "yeditor_export_ui.h"

#include <QtWidgets/QDialog>

typedef struct tagConfigExport
{
    QString     _sDirectory;
    QString     _sFileName;
} SConfigExport;

class YCQDlgExport : public QDialog
{
    Q_OBJECT

public:
    static bool showDialog(SConfigExport& rstConfig, QWidget *parent = 0);

public:
    YCQDlgExport(QWidget *parent = 0, Qt::WindowFlags f = 0);
    virtual ~YCQDlgExport();

public Q_SLOTS:
    void onBrowserDirectory();

public:
    bool toConfig(SConfigExport& rstConfig) const;

protected:
    bool toCheck(const SConfigExport& rstConfig) const;

private:
    Ui_Export   m_Ui;
};

#endif // Y_QDLGEXPORT_H
