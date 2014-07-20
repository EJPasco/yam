#include "yqt2yam.h"

#include "yeditor.h"
#include "yconverter.h"

#include "quiitem.h"
#include "quitreeitem.h"

namespace yam{ namespace io{

SINGLETON_IMPL(CYQt2Yam);

CYQt2Yam::CYQt2Yam()
{
    //
}

CYQt2Yam::~CYQt2Yam()
{
    //
}

yam::ybool CYQt2Yam::Convert(const YEditor* pEditor, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpTree) const
{
    YCQUiItem* pItem = pEditor->getUiItem(pUiItem);
    if (NULL == pEditor || NULL == pItem|| NULL == pUiItem || NULL == rpTree)
    {
        return false;
    }
    return Generate(pEditor, pItem, pUiItem, rpTree);
}

yam::ybool CYQt2Yam::Generate(const YEditor* pEditor, const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const
{
    if (NULL == pEditor || NULL == pItem || NULL == pUiItem)
    {
        return false;
    }

    yam::EWidgetType eType = pItem->getType();
    switch (eType)
    {
    case eWidgetType_Scene: {
        //rpWidget = new yam::base::YCWidget;
        GenerateScene(pItem, pUiItem, rpWidget);
        } break;

    case eWidgetType_Panel: {
        rpWidget = new yam::base::YCWidget;
        GeneratePanel(pItem, pUiItem, rpWidget);
        } break;

    case eWidgetType_Image: {
        rpWidget = new yam::base::YCWidget;
        GenerateImage(pItem, pUiItem, rpWidget);
        } break;

    case eWidgetType_Button: {
        rpWidget = new yam::base::YCWidget;
        GenerateButton(pItem, pUiItem, rpWidget);
        } break;

    case eWidgetType_Text: {
        rpWidget = new yam::base::YCWidget;
        GenerateText(pItem, pUiItem, rpWidget);
        } break;

    default:
        return false;
    }

    GenerateWidgetChildren(pEditor, pUiItem, rpWidget);
    return rpWidget != YNULL;
}

yam::ybool CYQt2Yam::GenerateWidget(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const
{
    rpWidget->GetId() = pUiItem->text(0).toLocal8Bit().data();
    rpWidget->GetType() = pItem->getType();
    rpWidget->GetLayerWeight() = pItem->getLayerWeight();
    rpWidget->GetBound().Pos.X = pItem->pos().x();
    rpWidget->GetBound().Pos.Y = pItem->pos().y();
    rpWidget->GetBound().Size.X = pItem->size().width();
    rpWidget->GetBound().Size.Y = pItem->size().height();

    rpWidget->GetExternalProperty().AddChild("visible")->FromString(pItem->isVisible() ? "true" : "false");
    return true;
}

void CYQt2Yam::GenerateWidgetChildren(const YEditor* pEditor, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const
{
    int iCount = pUiItem->childCount();
    for (int i = 0; i < iCount; ++i)
    {
        YCQUiTreeItem* pUiItemChild = dynamic_cast<YCQUiTreeItem*>(pUiItem->child(i));
        YCQUiItem* pItemChild = pEditor->getUiItem(pUiItemChild);
        yam::base::YIWidget* pWidget = YNULL;
        if (!Generate(pEditor, pItemChild, pUiItemChild, pWidget))
        {
            continue;
        }
        rpWidget->AddChild(pWidget);
    }
}

yam::ybool CYQt2Yam::GenerateScene(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const
{
    GenerateWidget(pItem, pUiItem, rpWidget);

    const SConfigScene& rstConfigScene = pItem->getConfigScene();

    yam::base::YCProperty* pPropertyScene = rpWidget->GetExternalProperty().AddChild("scene");
    pPropertyScene->ClearChildren();
    pPropertyScene->AddChild("logic")->FromString(rstConfigScene._sLogic);

    yam::base::YCProperty* pPropertyAssets = pPropertyScene->AddChild("assets");
    pPropertyAssets->AddChild("count")->FromInt32((yam::yint32)rstConfigScene._vAssets.size());

    GenerateLayout(*pPropertyScene, pItem->getConfigLayout());

    for (size_t i = 0; i < rstConfigScene._vAssets.size(); ++i)
    {
        const SConfigAsset& rstConfigAsset = rstConfigScene._vAssets[i];
        std::stringstream ss;
        ss << i;
        yam::base::YCProperty* pPropertyAsset = pPropertyAssets->AddChild(ss.str());
        pPropertyAsset->AddChild("file")->FromString(rstConfigAsset._sFile);
        pPropertyAsset->AddChild("name")->FromString(rstConfigAsset._sName);
        pPropertyAsset->AddChild("type")->FromString(rstConfigAsset._sType);
    }
    return true;
}

yam::ybool CYQt2Yam::GeneratePanel(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const
{
    GenerateWidget(pItem, pUiItem, rpWidget);

    yam::base::YIProperty* pPropertyFace = rpWidget->GetExternalProperty().AddChild("noinput");
    pPropertyFace->ClearChildren();
    pPropertyFace->FromString(pItem->getNoInput() ? "true" : "false");

    GenerateLayout(rpWidget->GetExternalProperty(), pItem->getConfigLayout());
    return true;
}

yam::ybool CYQt2Yam::GenerateImage(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, const EImageType eType, const int& riIndex, yam::base::YIWidget*& rpWidget, yam::base::YIProperty*& rpProperty) const
{
    yam::ystring sSource = pItem->getImageSource(eType, riIndex).toLocal8Bit().data();
    rpProperty->AddChild("source")->FromString(sSource);

    SRelationship stRel = YEditor::getRelationship(sSource);
    if (NULL == stRel._pUiItem)
    {
        rpProperty->AddChild("bound")->FromRect2D(YCConverter::Instance().Convert(pItem->getImageBound(eType, riIndex)));
    }
    else
    {
        QRect bound(stRel._pUiItem->pos(), stRel._pUiItem->size());
        rpProperty->AddChild("bound")->FromRect2D(YCConverter::Instance().Convert(bound));
    }
    rpProperty->AddChild("offset")->FromVec2D(YCConverter::Instance().Convert(pItem->getImageOffset(eType, riIndex)));
    return true;
}

yam::ybool CYQt2Yam::GenerateImages(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, const EImageType eType, yam::base::YIWidget*& rpWidget, yam::base::YIProperty*& rpProperty) const
{
    rpProperty->ClearChildren();

    int iCount = pItem->getImageCount(eType);
    rpProperty->AddChild("count")->FromInt32(iCount);
    rpProperty->AddChild("speed")->FromFloat32(pItem->getImageSpeed(eType));
    rpProperty->AddChild("type")->FromString(pItem->getImageType(eType));

    for (int i = 0; i < iCount; ++i)
    {
        std::stringstream ss;
        ss << i;
        yam::base::YIProperty* pPropertyItem = rpProperty->AddChild(ss.str());
        GenerateImage(pItem, pUiItem, eType, i, rpWidget, pPropertyItem);
    }
    return true;
}

yam::ybool CYQt2Yam::GenerateImage(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const
{
    GenerateWidget(pItem, pUiItem, rpWidget);

    yam::base::YIProperty* pProperty = rpWidget->GetExternalProperty().AddChild("images")->AddChild(YCQUiItem::convertImageTypeToString(eImageType_Normal));
    GenerateImages(pItem, pUiItem, eImageType_Normal, rpWidget, pProperty);

    return true;
}

yam::ybool CYQt2Yam::GenerateButton(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const
{
    GenerateWidget(pItem, pUiItem, rpWidget);

    for (int i = 0; i < eImageType_Max; ++i)
    {
        if (i != eImageType_Normal && i != eImageType_Hover && i != eImageType_Pressed && i != eImageType_Disable)
        {
            continue;
        }
        yam::base::YIProperty* pProperty = rpWidget->GetExternalProperty().AddChild("images")->AddChild(YCQUiItem::convertImageTypeToString((EImageType)i));
        GenerateImages(pItem, pUiItem, (EImageType)i, rpWidget, pProperty);
    }
    return true;
}

yam::ybool CYQt2Yam::GenerateText(const YCQUiItem* pItem, const YCQUiTreeItem* pUiItem, yam::base::YIWidget*& rpWidget) const
{
    GenerateWidget(pItem, pUiItem, rpWidget);

    yam::base::YIProperty* pPropertyFace = rpWidget->GetExternalProperty().AddChild("face");
    pPropertyFace->FromString(pItem->getTextFace());

    yam::base::YIProperty* pPropertySize = rpWidget->GetExternalProperty().AddChild("size");
    pPropertySize->FromInt32(pItem->getTextSize());

    yam::base::YIProperty* pPropertyAlign = rpWidget->GetExternalProperty().AddChild("align");
    pPropertyAlign->FromString(pItem->getTextAlign());

    yam::base::YIProperty* pPropertyValue = rpWidget->GetExternalProperty().AddChild("value");
    pPropertyValue->FromString(pItem->getTextValue());
    return true;
}

void CYQt2Yam::GenerateLayout(yam::base::YCProperty& rProperty, const SConfigLayout& rstConfig) const
{
    yam::base::YCProperty* pPropertyLayout = rProperty.AddChild("layout");
    {
        pPropertyLayout->AddChild("type")->FromString(rstConfig._sType);
        yam::base::YCProperty* pPropertyLayoutValue = pPropertyLayout->AddChild("value");
        {
            pPropertyLayoutValue->AddChild("type")->FromString(rstConfig._sValue);
        }
    }
}

}}
