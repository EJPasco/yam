#ifndef Y_QUITREEITEMIMAGESHELPER_H
#define Y_QUITREEITEMIMAGESHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "yeditorcommon.h"

class QTreeWidget;
class QTreeWidgetItem;
class QDoubleSpinBox;
class QLineEdit;
class YCQUiTreeItemImageHelper;

class YCQUiTreeItemImagesHelper : public QObject
{
    Q_OBJECT

public:
    typedef std::vector<YCQUiTreeItemImageHelper*>      VImageHelper;

public:
    explicit YCQUiTreeItemImagesHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const EImageType& reImageType, const QString sName = "Images");
    virtual ~YCQUiTreeItemImagesHelper();

Q_SIGNALS:
    void onChanged(const EImageType& reImageType, const yam::yint32& riImageIndex, YCQUiTreeItemImageHelper* pImageHelper);
    void onChanged(const EImageType& reImageType, const yam::yfloat32& riSpeed, const yam::ystring& rsType);
    void onChanged(const EImageType& reImageType);     //< add
    void onChanged(const EImageType& reImageType, const yam::yint32& riImageIndex);     //< delete

public Q_SLOTS:
    void onAddButtonClicked();
    void onChangedImage(const yam::yint32& riIndex, YCQUiTreeItemImageHelper* pImageHelper);
    void onChangedImage(const yam::yint32& riIndex);
    void onChangedSpeed(double dSpeed);
    void onItemChangedType(const QString& rsType);

public:
    YCQUiTreeItemImageHelper* toAddImageHelper();
    void toDeleteImageHelper(YCQUiTreeItemImageHelper* pImageHelper);
    void toClearImageHelper();
    const EImageType& getImageType();
    void setUiItem(YCQUiItem*& rpUiItem);

private:
    VImageHelper        m_vpImageHelper;
    QTreeWidget*        m_pTreeRoot;
    QTreeWidgetItem*    m_pTreeItemImages;
    QDoubleSpinBox*     m_pdsbSpeed;
    QLineEdit*          m_pleType;
    EImageType          m_eImageType;
    float               m_fSpeed;
    yam::ystring        m_sType;
};

#endif // Y_QUITREEITEMIMAGESHELPER_H
