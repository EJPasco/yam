#ifndef Y_QUITREEITEM_H
#define Y_QUITREEITEM_H

#include <QtWidgets/QTreeWidget>

class YCQUiTreeItem : public QTreeWidgetItem
{
    typedef QMap<QString, QString>        MapDataProperty;

public:
    YCQUiTreeItem();
    virtual ~YCQUiTreeItem();

public:
    void setDataProperty(const QString& rsKey, const QString& rsValue);
    QString getDataProperty(const QString& rsKey) const;

private:
    MapDataProperty        m_mDataProperty;
};

#endif // Y_QUITREEITEM_H
