#ifndef Y_QUITREEITEMIMAGEHELPER_H
#define Y_QUITREEITEMIMAGEHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "quiitem.h"

class QTreeWidget;
class QTreeWidgetItem;
class QLineEdit;
class YCQUiTreeItemImagesHelper;
class YCQUiTreeItemPointHelper;
class YCQUiTreeItemBoundHelper;

class YCQUiTreeItemImageHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemImageHelper(YCQUiTreeItemImagesHelper* pImagesHelper, QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const yam::yint32& riIndex, const QString sName = "Image");
    virtual ~YCQUiTreeItemImageHelper();

Q_SIGNALS:
    void onChanged(const yam::yint32& riIndex, YCQUiTreeItemImageHelper* pImageHelper);
    void onChanged(const yam::yint32& riIndex);

public Q_SLOTS:
    void onItemChangedSource(const QString& rsImageSource);
    void onItemChangedOffset(const QPoint& roOffset);
    void onDelButtonClicked();

public:
    const QString& getSource() const;
    void setSource(const QString& rsValue);
    const QPoint& getOffset() const;
    void setOffset(const QPoint& rOffset);
    void setIndex(const yam::yint32& riIndex);
    QTreeWidgetItem* getTreeWidgetItem();

private:
    YCQUiTreeItemImagesHelper*  m_pImagesHelper;
    QTreeWidgetItem*            m_pTreeItemImage;
    QLineEdit*                  m_pEditor;
    YCQUiTreeItemPointHelper*   m_pTreeItemPointHelper;
    QString                     m_sImageSource;
    QPoint                      m_oOffset;
    yam::yint32                 m_iImageIndex;
};

#endif // Y_QUITREEITEMIMAGEHELPER_H
