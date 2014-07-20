#ifndef Y_QUITREEITEMSRCHELPER_H
#define Y_QUITREEITEMSRCHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "yeditorcommon.h"

class QTreeWidget;
class QTreeWidgetItem;
class YCQUiTreeItemImageHelper;
class YCQUiTreeItemImagesHelper;

class YCQUiTreeItemSrcHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemSrcHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const yam::yuint8& riImageTypeGroup, const QString sName = "Images");
    virtual ~YCQUiTreeItemSrcHelper();

Q_SIGNALS:
    void onChanged(const EImageType& reImageType, const yam::yint32& riImageIndex, YCQUiTreeItemImageHelper* pImageHelper);
    void onChanged(const EImageType& reImageType, const yam::yfloat32& rfSpeed, const yam::ystring& rsType);
    void onChanged(const EImageType& reImageType);  //< add
    void onChanged(const EImageType& reImageType, const yam::yint32& riImageIndex); //< delete
    void onSelected(const EImageType& reImageType, const yam::yint32& riImageIndex);

public Q_SLOTS:
    void onImageTypeChanged(const QString& rsImageType);
    void onImageIndexChanged(const int& riImageIndex);
    void onChangedImages(const EImageType& reImageType, const yam::yint32& riImageIndex, YCQUiTreeItemImageHelper* pImageHelper);
    void onChangedImages(const EImageType& reImageType, const yam::yfloat32& rfSpeed, const yam::ystring& rsType);
    void onChangedImages(const EImageType& reImageType);
    void onChangedImages(const EImageType& reImageType, const yam::yint32& riImageIndex);

public:
    void setUiItem(YCQUiItem*& rpUiItem);

private:
    YCQUiTreeItemImagesHelper*      m_apImagesHelper[eImageType_Max];
    EImageType      m_eImageType;
    int             m_iImageIndex;
};

#endif // Y_QUITREEITEMSRCHELPER_H
