#ifndef Y_QUITREEITEMASSETSHELPER_H
#define Y_QUITREEITEMASSETSHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "yeditorcommon.h"

class QTreeWidget;
class QTreeWidgetItem;
class YCQUiTreeItemAssetHelper;

class YCQUiTreeItemAssetsHelper : public QObject
{
    Q_OBJECT

public:
    typedef std::vector<YCQUiTreeItemAssetHelper*>      VAssetHelper;

public:
    explicit YCQUiTreeItemAssetsHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName = "assets");
    virtual ~YCQUiTreeItemAssetsHelper();

Q_SIGNALS:
    void onChanged(const int& riIndex, const SConfigAsset& rstConfig);
    void onChanged();       //< add
    void onChanged(const int& riIndex); //< delete

public Q_SLOTS:
    void onClickedAdd();
    void onChangedAsset(const int& riIndex, const SConfigAsset& rstAsset);
    void onChangedAsset(const int& riIndex);

public:
    YCQUiTreeItemAssetHelper* toAddAssetHelper();
    void toDeleteAssetHelper(YCQUiTreeItemAssetHelper* pAssetHelper);
    void toClearAssetHelper();
    void setUiItem(YCQUiItem*& rpUiItem);

private:
    QTreeWidget*        m_pTreeRoot;
    QTreeWidgetItem*    m_pTreeItemMain;
    VAssetHelper        m_vpAssetHelper;
};

#endif // Y_QUITREEITEMASSETSHELPER_H
