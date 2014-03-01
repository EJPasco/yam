#include "qdlgcreatewidget.h"

bool YCQDlgCreateWidget::showDialog(SConfigCreateWidget& rstConfig, QWidget *parent /* = 0 */)
{
    YCQDlgCreateWidget dlg(parent);
    if (dlg.exec() == 0)
    {
        return false;
    }
    return dlg.toConfig(rstConfig);
}

YCQDlgCreateWidget::YCQDlgCreateWidget(QWidget *parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
    : QDialog(parent, f)
{
    m_Ui.setupUi(this);
}

YCQDlgCreateWidget::~YCQDlgCreateWidget()
{
    //
}

bool YCQDlgCreateWidget::toConfig(SConfigCreateWidget& rstConfig) const
{
    rstConfig._sId = m_Ui.leId->text();
    return toCheck(rstConfig);
}

bool YCQDlgCreateWidget::toCheck(const SConfigCreateWidget& rstConfig) const
{
    if (0 >= rstConfig._sId.size())
    {
        return false;
    }
    //TODO: more detail
    return true;
    
}
