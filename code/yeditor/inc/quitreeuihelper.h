#ifndef Y_QUITREEWIDGETHELPER_H
#define Y_QUITREEWIDGETHELPER_H

#include "quitreehelper.h"

class YCQUiTreeItemSizeHelper;
class YCQUiTreeItemBoundHelper;
class YCQUiTreeItemLayerWeightHelper;
class YCQUiTreeItemImageTypeHelper;
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
    void onItemChangedImageType(const YCQUiItem::EImageType& reImageType);
    void onItemChangedNormalImage(const QString& rsImageSource, const QRect& roBound);
    void onItemChangedHoverImage(const QString& rsImageSource, const QRect& roBound);
    void onItemChangedPressImage(const QString& rsImageSource, const QRect& roBound);
    void onItemChangedDisableImage(const QString& rsImageSource, const QRect& roBound);

public:
    virtual void setUiItem(YCQUiItem*& rpUiItem);

private:
    YCQUiTreeItemSizeHelper*                m_pTreeItemSizeHelper;
    YCQUiTreeItemBoundHelper*               m_pTreeItemBoundHelper;
    YCQUiTreeItemLayerWeightHelper*         m_pTreeItemLayerWeightHelper;
    YCQUiTreeItemImageTypeHelper*           m_pTreeItemImageTypeHelper;
    YCQUiTreeItemImageHelper*               m_pTreeItemImageNormalHelper;
    YCQUiTreeItemImageHelper*               m_pTreeItemImageHoverHelper;
    YCQUiTreeItemImageHelper*               m_pTreeItemImagePressHelper;
    YCQUiTreeItemImageHelper*               m_pTreeItemImageDisableHelper;
};

#endif // Y_QUITREEWIDGETHELPER_H
