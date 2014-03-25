#ifndef Y_QUITREE_H
#define Y_QUITREE_H

#include "quiitem.h"

#include <QtWidgets/QTreeWidget>

class YCQUiTreeHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeHelper(QTreeWidget* pTreeRoot);
    virtual ~YCQUiTreeHelper();

public Q_SLOTS:
    virtual void onItemChanged(QTreeWidgetItem* pItem, int iColume);

public:
    virtual void setUiItem(YCQUiItem*& rpUiItem);

protected:
    QTreeWidget*    m_pTreeRoot;
    YCQUiItem*        m_pUiItem;
};

#endif // Y_QUITREE_H
