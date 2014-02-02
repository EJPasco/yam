#include "qdlgcreatewidget.h"

YCQDlgCreateWidget::YCQDlgCreateWidget(QWidget *parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
    : QDialog(parent, f)
{
    m_Ui.setupUi(this);
    //
}

YCQDlgCreateWidget::~YCQDlgCreateWidget()
{
    //
}

QString YCQDlgCreateWidget::getId() const
{
    return m_Ui.idLineEdit->text();
}
