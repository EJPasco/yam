#ifndef Y_QUITREEWIDGETHELPER_H
#define Y_QUITREEWIDGETHELPER_H

#include "quitreehelper.h"

#include "quitreeitemboundhelper.h"
#include "quitreeitemlayerweighthelper.h"
#include "quitreeitemimagehelper.h"

class YCQUiTreeUiHelper : public YCQUiTreeHelper
{
    typedef YCQUiTreeHelper        super;

    Q_OBJECT

public:
    explicit YCQUiTreeUiHelper(QTreeWidget* pTreeRoot);
    virtual ~YCQUiTreeUiHelper();

public Q_SLOTS:
    void onItemChangedBound(const QRect& roBound);
    void onItemChangedLayerWeight(const int& riLayerWeight);
    void onItemChangedImageSource(const QString& rsImageSource);

public:
    virtual void setUiItem(YCQUiItem*& rpUiItem);

private:
    YCQUiTreeItemBoundHelper*            m_pTreeItemBoundHelper;
    YCQUiTreeItemLayerWeightHelper*        m_pTreeItemLayerWeightHelper;
    YCQUiTreeItemImageHelper*            m_pTreeItemImageHelper;
};

#endif // Y_QUITREEWIDGETHELPER_H
