#ifndef Y_QUITREEITEMASSERTHELPER_H
#define Y_QUITREEITEMASSERTHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "yeditorcommon.h"

class QTreeWidget;
class QTreeWidgetItem;
class QLineEdit;
class YCQUiTreeItemAssertsHelper;

class YCQUiTreeItemAssertHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemAssertHelper(YCQUiTreeItemAssertsHelper* pAssertsHelper, QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const int& riIndex, const QString sName = "assert");
    virtual ~YCQUiTreeItemAssertHelper();

Q_SIGNALS:
    void onChanged(const int& riIndex, const SConfigAssert& rstConfig);
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
    YCQUiTreeItemAssertsHelper* m_pAssertsHelper;
    QTreeWidgetItem*            m_pTreeItemMain;
    QLineEdit*      m_pleFile;
    QLineEdit*      m_pleName;
    QLineEdit*      m_pleType;
    SConfigAssert   m_stAssert;
    int             m_iAssertIndex;
};

#endif // Y_QUITREEITEMASSERTHELPER_H
