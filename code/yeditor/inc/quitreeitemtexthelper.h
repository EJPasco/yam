#ifndef Y_QUITREEITEMFONTHELPER_H
#define Y_QUITREEITEMFONTHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "yeditorcommon.h"

class QTreeWidget;
class QTreeWidgetItem;
class QLineEdit;

class YCQUiTreeItemTextHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemTextHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName = "text");
    virtual ~YCQUiTreeItemTextHelper();

Q_SIGNALS:
    void onChanged(const QString& rsFontName);

public Q_SLOTS:
    void onChangedFontName(const QString& rsFontName);

public:
    void setUiItem(YCQUiItem*& rpUiItem);

private:
    QLineEdit* m_pleFontName;
    QString m_sFontName;
};

#endif // Y_QUITREEITEMFONTHELPER_H
