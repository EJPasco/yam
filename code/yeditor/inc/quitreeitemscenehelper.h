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
class YCQUiTreeItemAssertsHelper;

class YCQUiTreeItemSceneHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemSceneHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName = "scene");
    virtual ~YCQUiTreeItemSceneHelper();

Q_SIGNALS:
    void onChanged(const SConfigScene& rstConfig);

public Q_SLOTS:
    void onChangedLogic(const QString& roLogic);
    void onChangedSize(const QSize& roSize);
    void onChangedAsserts(const int& riIndex, const SConfigAssert& rstAssert);
    void onChangedAsserts();    //< add
    void onChangedAsserts(const int& riIndex);  //< delete

public:
    void setUiItem(YCQUiItem*& rpUiItem);

private:
    QLineEdit*                      m_pleLogic;
    YCQUiTreeItemSizeHelper*        m_pTreeItemSizeHelper;
    YCQUiTreeItemAssertsHelper*     m_pTreeItemAssertsHelper;
    SConfigScene m_stConfig;
};

#endif // Y_QUITREEITEMSCENEHELPER_H
