#ifndef Y_QUITREEITEMTEXTHELPER_H
#define Y_QUITREEITEMTEXTHELPER_H

#include <QtCore/QRect>
#include <QtCore/QString>
#include <QtCore/QObject>

#include "yeditorcommon.h"

class QTreeWidget;
class QTreeWidgetItem;
class QLineEdit;
class QSpinBox;
class QComboBox;

class YCQUiTreeItemTextHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemTextHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem, const QString sName = "text");
    virtual ~YCQUiTreeItemTextHelper();

Q_SIGNALS:
    void onChanged(const QString& rsFace, const int& riSize, const QString& rsAlignType, const QString& rsValue);

public Q_SLOTS:
    void onChangedFace(const QString& rsFace);
    void onChangedSize(int iSize);
    void onChangedAlignType(const QString& rsAlignType);
    void onChangedValue(const QString& rsValue);

public:
    void setUiItem(YCQUiItem*& rpUiItem);

private:
    QLineEdit* m_pleFace;
    QSpinBox* m_psbSize;
    QComboBox* m_pcbAlignType;
    QLineEdit* m_pleValue;

    QString m_sFace;
    int m_iSize;
    QString m_sAlignType;
    QString m_sValue;
};

#endif // Y_QUITREEITEMTEXTHELPER_H
