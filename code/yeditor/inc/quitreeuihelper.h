#ifndef Y_QUITREEWIDGETHELPER_H
#define Y_QUITREEWIDGETHELPER_H

#include "quitreehelper.h"

class YCQUiTreeItemSizeHelper;
class YCQUiTreeItemBoundHelper;
class YCQUiTreeItemLayerWeightHelper;
class YCQUiTreeItemImageHelper;

class YCQUiTreeUiHelper : public YCQUiTreeHelper
{
    typedef YCQUiTreeHelper        super;

    Q_OBJECT

public:
    explicit YCQUiTreeUiHelper(QTreeWidget* pTreeRoot);
    virtual ~YCQUiTreeUiHelper();

public Q_SLOTS:
    void onItemChangedSize(const QSize& roSize);
    void onItemChangedBound(const QRect& roBound);
    void onItemChangedLayerWeight(const int& riLayerWeight);
    void onItemChangedImageSource(const QString& rsImageSource);

public:
    virtual void setUiItem(YCQUiItem*& rpUiItem);

private:
    YCQUiTreeItemSizeHelper*                m_pTreeItemSizeHelper;
    YCQUiTreeItemBoundHelper*               m_pTreeItemBoundHelper;
    YCQUiTreeItemLayerWeightHelper*         m_pTreeItemLayerWeightHelper;
    YCQUiTreeItemImageHelper*               m_pTreeItemImageHelper;
};

#endif // Y_QUITREEWIDGETHELPER_H