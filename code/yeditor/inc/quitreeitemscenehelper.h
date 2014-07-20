#ifndef Y_QUITREEITEMSCENEHELPER_H
#define Y_QUITREEITEMSCENEHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "yeditorcommon.h"

class QTreeWidget;
class QTreeWidgetItem;
class QLineEdit;
class YCQUiTreeItemSizeHelper;
class YCQUiTreeItemAssetsHelper;
class YCQUiTreeItemLayoutHelper;

class YCQUiTreeItemSceneHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemSceneHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName = "scene");
    virtual ~YCQUiTreeItemSceneHelper();

Q_SIGNALS:
    void onChanged(const SConfigScene& rstConfig, const SConfigLayout& rstConfigLayout);

public Q_SLOTS:
    void onChangedLogic(const QString& roLogic);
    void onChangedSize(const QSize& roSize);
    void onChangedAssets(const int& riIndex, const SConfigAsset& rstAsset);
    void onChangedAssets();    //< add
    void onChangedAssets(const int& riIndex);  //< delete
    void onChangedLayout(const SConfigLayout& rstConfig);

public:
    void setUiItem(YCQUiItem*& rpUiItem);

private:
    QLineEdit*                      m_pleLogic;
    YCQUiTreeItemSizeHelper*        m_pTreeItemSizeHelper;
    YCQUiTreeItemAssetsHelper*      m_pTreeItemAssetsHelper;
    YCQUiTreeItemLayoutHelper*      m_pTreeItemLayoutHelper;
    SConfigScene m_stConfig;
    SConfigLayout m_stConfigLayout;
};

#endif // Y_QUITREEITEMSCENEHELPER_H
