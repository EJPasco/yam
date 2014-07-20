#ifndef Y_QT2YAM_H
#define Y_QT2YAM_H

#include "yeditorcommon.h"

class YEditor;

namespace yam{ namespace io{

class CYQt2Yam
{
    SINGLETON_DECL(CYQt2Yam);

public:
    CYQt2Yam();
    virtual ~CYQt2Yam();

public:
    yam::ybool Convert(const YEditor* pEditor, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& pTree) const;

private:
    yam::ybool Generate(const YEditor* pEditor, const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const;
    yam::ybool GenerateWidget(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const;
    void GenerateWidgetChildren(const YEditor* pEditor, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const;
    yam::ybool GenerateScene(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const;
    yam::ybool GeneratePanel(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const;
    yam::ybool GenerateImage(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, const EImageType eType, const int& riIndex, yam::base::YIWidget*& rpWidget, yam::base::YIProperty*& rpProperty) const;
    yam::ybool GenerateImages(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, const EImageType eType, yam::base::YIWidget*& rpWidget, yam::base::YIProperty*& rpProperty) const;
    yam::ybool GenerateImage(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const;
    yam::ybool GenerateButton(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const;
    yam::ybool GenerateText(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const;
    void GenerateLayout(yam::base::YCProperty& rProperty, const SConfigLayout& rstConfig) const;
};

}}

#endif // Y_QT2YAM_H
