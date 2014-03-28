#ifndef Y_QUITREEITEMASSETHELPER_H
#define Y_QUITREEITEMASSETHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "yeditorcommon.h"

class QTreeWidget;
class QTreeWidgetItem;
class QLineEdit;
class YCQUiTreeItemAssetsHelper;

class YCQUiTreeItemAssetHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemAssetHelper(YCQUiTreeItemAssetsHelper* pAssetsHelper, QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const int& riIndex, const QString sName = "asset");
    virtual ~YCQUiTreeItemAssetHelper();

Q_SIGNALS:
    void onChanged(const int& riIndex, const SConfigAsset& rstConfig);
    void onChanged(const int& riIndex);

public Q_SLOTS:
    void onClickedDelete();
    void onChangedFile(const QString& rsFile);
    void onChangedName(const QString& rsName);
    void onChangedType(const QString& rsType);

public:
    void setFile(const yam::ystring& rsFile);
    void setName(const yam::ystring& rsName);
    void setType(const yam::ystring& rsType);
    void setIndex(const int& riIndex);
    QTreeWidgetItem* getTreeWidgetItem();

private:
    YCQUiTreeItemAssetsHelper* m_pAssetsHelper;
    QTreeWidgetItem*            m_pTreeItemMain;
    QLineEdit*      m_pleFile;
    QLineEdit*      m_pleName;
    QLineEdit*      m_pleType;
    SConfigAsset    m_stAsset;
    int             m_iAssetIndex;
};

#endif // Y_QUITREEITEMASSETHELPER_H
