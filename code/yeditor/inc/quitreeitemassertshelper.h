#ifndef Y_QUITREEITEMASSERTSHELPER_H
#define Y_QUITREEITEMASSERTSHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "yeditorcommon.h"

class QTreeWidget;
class QTreeWidgetItem;
class YCQUiTreeItemAssertHelper;

class YCQUiTreeItemAssertsHelper : public QObject
{
    Q_OBJECT

public:
    typedef std::vector<YCQUiTreeItemAssertHelper*>      VAssertHelper;

public:
    explicit YCQUiTreeItemAssertsHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName = "asserts");
    virtual ~YCQUiTreeItemAssertsHelper();

Q_SIGNALS:
    void onChanged(const int& riIndex, const SConfigAssert& rstConfig);
    void onChanged();       //< add
    void onChanged(const int& riIndex); //< delete

public Q_SLOTS:
    void onClickedAdd();
    void onChangedAssert(const int& riIndex, const SConfigAssert& rstAssert);
    void onChangedAssert(const int& riIndex);

public:
    YCQUiTreeItemAssertHelper* toAddAssertHelper();
    void toDeleteAssertHelper(YCQUiTreeItemAssertHelper* pAssertHelper);
    void toClearAssertHelper();
    void setUiItem(YCQUiItem*& rpUiItem);

private:
    QTreeWidget*        m_pTreeRoot;
    QTreeWidgetItem*    m_pTreeItemMain;
    VAssertHelper       m_vpAssertHelper;
};

#endif // Y_QUITREEITEMASSERTSHELPER_H
