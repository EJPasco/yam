#ifndef Y_QUITREEITEMIMAGEHELPER_H
#define Y_QUITREEITEMIMAGEHELPER_H

#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QLineEdit>

class YCQUiTreeItemImageHelper : public QObject
{
    Q_OBJECT

public:
    explicit YCQUiTreeItemImageHelper(QTreeWidget* pTreeRoot, QTreeWidgetItem* pTreeItem);
    virtual ~YCQUiTreeItemImageHelper();

Q_SIGNALS:
    void onChanged(const QString& rsImageSource);

public Q_SLOTS:
    void onItemChangedSource(const QString& rsImageSource);

public:
    void setImageSource(const QString& rsValue);

private:
    QTreeWidgetItem*        m_pTreeItemImage;
    QLineEdit*                m_pEditor;
    QString                    m_sImageSource;
};

#endif // Y_QUITREEITEMIMAGEHELPER_H
