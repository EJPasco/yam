#include "qdlgexport.h"

#include <QtWidgets/QFileDialog>

bool YCQDlgExport::showDialog(SConfigExport& rstConfig, QWidget *parent /* = 0 */)
{
    YCQDlgExport dlg(parent);
    if (dlg.exec() == 0)
    {
        return false;
    }
    return dlg.toConfig(rstConfig);
}

YCQDlgExport::YCQDlgExport(QWidget *parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
    : QDialog(parent, f)
{
    m_Ui.setupUi(this);
}

YCQDlgExport::~YCQDlgExport()
{
    //
}

void YCQDlgExport::onBrowserJson()
{
    QString sSelectedFilter = "";
    m_Ui.leJsonFileName->setText(QFileDialog::getSaveFileName(this
        , tr("Save a json file"), ""
        , tr("json (*.json)"), &sSelectedFilter
        , QFileDialog::DontUseCustomDirectoryIcons | QFileDialog::DontUseSheet));
}

void YCQDlgExport::onBrowserPng()
{
    QString sSelectedFilter = "";
    m_Ui.lePngFileName->setText(QFileDialog::getSaveFileName(this
        , tr("Save a png file"), ""
        , tr("json (*.png)"), &sSelectedFilter
        , QFileDialog::DontUseCustomDirectoryIcons | QFileDialog::DontUseSheet));
}

bool YCQDlgExport::toConfig(SConfigExport& rstConfig) const
{
    rstConfig._sLogicName = m_Ui.leLogicName->text();
    rstConfig._sJsonFileName = m_Ui.leJsonFileName->text();
    rstConfig._sPngFileName = m_Ui.lePngFileName->text();
    return toCheck(rstConfig);
}

bool YCQDlgExport::toCheck(const SConfigExport& rstConfig) const
{
    if (0 >= rstConfig._sLogicName.size()
        || 0 >= rstConfig._sJsonFileName.size()
        || 0 >= rstConfig._sPngFileName.size())
    {
        return false;
    }
    //TODO: more detail
    return true;
}
