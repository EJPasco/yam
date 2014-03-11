#ifndef Y_QUITREEITEMIMAGETYPEHELPER_H
#define Y_QUITREEITEMIMAGETYPEHELPER_H

#include "quiitem.h"

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

class QTreeWidget;
class QTreeWidgetItem;
class QComboBox;

class YCQUiTreeItemImageTypeHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemImageTypeHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const yam::yuint8& riImageTypeGroup, const QString sName = "Image Type");
    virtual ~YCQUiTreeItemImageTypeHelper();

Q_SIGNALS:
    void onChanged(const YCQUiItem::EImageType& reImageType);

public Q_SLOTS:
    void onItemChanged(const QString& rsImageType);

public:
    void setImageType(const YCQUiItem::EImageType& reImageType);

private:
    QTreeWidgetItem*            m_pTreeItemImage;
    QComboBox*                  m_pComboBox;
    YCQUiItem::EImageType       m_eImageType;
};

#endif // Y_QUITREEITEMIMAGETYPEHELPER_H
