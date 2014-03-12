#ifndef Y_QUITREEITEMIMAGEHELPER_H
#define Y_QUITREEITEMIMAGEHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "quiitem.h"

class QTreeWidget;
class QTreeWidgetItem;
class QLineEdit;
class YCQUiTreeItemBoundHelper;

class YCQUiTreeItemImageHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemImageHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const YCQUiItem::EImageType& reImageType, const QString sName = "Image");
    virtual ~YCQUiTreeItemImageHelper();

Q_SIGNALS:
    void onChanged(const YCQUiItem::EImageType& reImageType, const QString& rsImageSource, const QRect& roBound);

public Q_SLOTS:
    void onItemChangedSource(const QString& rsImageSource);
    void onItemChangedBound(const QRect& roBound);

public:
    void setSource(const QString& rsValue);
    void setBound(const QRect& rBound);

private:
    QTreeWidgetItem*            m_pTreeItemImage;
    QLineEdit*                  m_pEditor;
    YCQUiTreeItemBoundHelper*   m_pTreeItemBoundHelper;
    YCQUiItem::EImageType       m_eImageType;
    QString                     m_sImageSource;
    QRect                       m_oRect;
};

#endif // Y_QUITREEITEMIMAGEHELPER_H
