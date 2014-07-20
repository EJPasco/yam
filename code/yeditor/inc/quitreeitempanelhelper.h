#ifndef Y_QUITREEITEMPANELHELPER_H
#define Y_QUITREEITEMPANELHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "yeditorcommon.h"

class QTreeWidget;
class QTreeWidgetItem;
class QComboBox;
class YCQUiTreeItemLayoutHelper;

class YCQUiTreeItemPanelHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemPanelHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName = "panel");
    virtual ~YCQUiTreeItemPanelHelper();

Q_SIGNALS:
    void onChanged(const bool& rbNoInput, const SConfigLayout& rstLayout);

public Q_SLOTS:
    void onChangedNoInput(const QString& rsNoInput);
    void onChangedLayout(const SConfigLayout& rstLayout);

public:
    void setUiItem(YCQUiItem*& rpUiItem);

private:
    QComboBox* m_pcbNoInput;
    bool m_bNoInput;
    YCQUiTreeItemLayoutHelper* m_pTreeItemLayoutHelper;
    SConfigLayout m_stLayout;
};

#endif // Y_QUITREEITEMPANELHELPER_H
