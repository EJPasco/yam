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

void YCQDlgExport::onBrowserDirectory()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly);

    if (dialog.exec() == 0)
    {
        return;
    }
    m_Ui.leDirectory->setText(dialog.directory().path());
}

bool YCQDlgExport::toConfig(SConfigExport& rstConfig) const
{
    rstConfig._sDirectory = m_Ui.leDirectory->text();
    rstConfig._sFileName = m_Ui.leFileName->text();
    rstConfig._sLogicName = m_Ui.leLogicName->text();
    return toCheck(rstConfig);
}

bool YCQDlgExport::toCheck(const SConfigExport& rstConfig) const
{
    if (0 >= rstConfig._sDirectory.size()
        || 0 >= rstConfig._sFileName.size()
        || 0 >= rstConfig._sLogicName.size())
    {
        return false;
    }
    //TODO: more detail
    return true;
}
