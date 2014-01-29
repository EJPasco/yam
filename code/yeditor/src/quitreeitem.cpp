#include "quitreeitem.h"

YCQUiTreeItem::YCQUiTreeItem()
    : QTreeWidgetItem()
{
    //
}

YCQUiTreeItem::~YCQUiTreeItem()
{
    //
}

void YCQUiTreeItem::setDataProperty(const QString& rsKey, const QString& rsValue)
{
    m_mDataProperty.insert(rsKey, rsValue);
}

QString YCQUiTreeItem::getDataProperty(const QString& rsKey) const
{
    MapDataProperty::const_iterator citFind = m_mDataProperty.find(rsKey);
    if (citFind == m_mDataProperty.end())
    {
        return QString("");
    }
    return citFind.value();
}
