#ifndef Y_QUITREEWIDGETHELPER_H
#define Y_QUITREEWIDGETHELPER_H

#include "quitreehelper.h"

class YCQUiTreeItemSizeHelper;
class YCQUiTreeItemBoundHelper;
class YCQUiTreeItemLayerWeightHelper;
class YCQUiTreeItemSrcHelper;
class YCQUiTreeItemImageHelper;
class YCQUiTreeItemTextHelper;
class YCQUiTreeItemPanelHelper;
class YCQUiTreeItemSceneHelper;

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
    void onItemChangedSrc(const EImageType& reImageType, const yam::yint32& riImageIndex, YCQUiTreeItemImageHelper* pImageHelper);
    void onItemChangedSrc(const EImageType& reImageType, const yam::yfloat32& rfSpeed, const yam::ystring& rsType);
    void onItemChangedSrc(const EImageType& reImageType);
    void onItemChangedSrc(const EImageType& reImageType, const yam::yint32& riImageIndex);
    void onItemSelectedSrc(const EImageType& reImageType, const yam::yint32& riImageIndex);
    void onItemChangedText(const QString& rsFace, const int& riSize, const QString& rsAlign, const QString& rsValue);
    void onItemChangedPanel(const bool& rbNoInput, const SConfigLayout& rstConfigLayout);
    void onItemChangedScene(const SConfigScene& rstConfigScene, const SConfigLayout& rstConfigLayout);

public:
    virtual void setUiItem(YCQUiItem*& rpUiItem);

private:
    YCQUiTreeItemSizeHelper*                m_pTreeItemSizeHelper;
    YCQUiTreeItemBoundHelper*               m_pTreeItemBoundHelper;
    YCQUiTreeItemLayerWeightHelper*         m_pTreeItemLayerWeightHelper;
    YCQUiTreeItemSrcHelper*                 m_pTreeItemSrcHelper;
    YCQUiTreeItemTextHelper*                m_pTreeItemTextHelper;
    YCQUiTreeItemPanelHelper*               m_pTreeItemPanelHelper;
    YCQUiTreeItemSceneHelper*               m_pTreeItemSceneHelper;
};

#endif // Y_QUITREEWIDGETHELPER_H
