#ifndef Y_QUITREEITEMLAYOUTHELPER_H
#define Y_QUITREEITEMLAYOUTHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "yeditorcommon.h"

class QTreeWidget;
class QTreeWidgetItem;
class QLineEdit;

class YCQUiTreeItemSizeHelper;

class YCQUiTreeItemLayoutHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemLayoutHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName = "layout");
    virtual ~YCQUiTreeItemLayoutHelper();

Q_SIGNALS:
    void onChanged(const SConfigLayout& rstConfig);

public Q_SLOTS:
    void onChangedType(const QString& rsType);
    void onChangedValue(const QString& rsValue);

public:
    void setUiItem(YCQUiItem*& rpUiItem);

private:
    //QComboBox* m_pcbNoInput;
    QLineEdit*                  m_pleType;
    QLineEdit*                  m_pleValue;
    SConfigLayout               m_stConfig;
};

#endif // Y_QUITREEITEMLAYOUTHELPER_H
