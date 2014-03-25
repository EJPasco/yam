#include "yexportyam.h"

#include <json.h>
#include <QtCore/QFile>
#include <QtGui/QPainter>

#include "yeditor.h"
#include "yconverter.h"
#include "yrectpacker.h"

namespace yam{ namespace io{

YCExportYam::YCExportYam()
{
    //
}

YCExportYam::~YCExportYam()
{
    //
}

void YCExportYam::Save(const yam::base::YCTree* pTree) const
{
    yam::ystring sLogicName;
    {
        yam::base::YCProperty* pLogicName = GetProperty().FindChild<yam::base::YCProperty>("logic");
        if (YNULL != pLogicName)
        {
            pLogicName->ToString(sLogicName);
        }
    }
    yam::ystring sFileName;
    {
        yam::base::YCProperty* pFileName = GetProperty().FindChild<yam::base::YCProperty>("filename");
        if (YNULL != pFileName)
        {
            pFileName->ToString(sFileName);
        }
    }
    yam::ystring sDirectory;
    {
        yam::base::YCProperty* pDirectory = GetProperty().FindChild<yam::base::YCProperty>("directory");
        if (YNULL != pDirectory)
        {
            pDirectory->ToString(sDirectory);
        }
    }

    yam::ystring sJsonFileName = sDirectory + "/" + sFileName + ".json";
    yam::ystring sPngFileName = sDirectory + "/" + sFileName + ".png";

    json::Object jObj;
    yam::base::YITree* pUi = pTree->FindChild(YFILE_KEY_UI);
    if (YNULL == pUi)
    {
        return;
    }
    yam::base::YITree* pUiRoot = pUi->GetChildren();
    if (YNULL == pUiRoot || YOBJECT_GETCLASSNAME(yam::base::YCWidget) != pUiRoot->GetClassName())
    {
        return;
    }
    ToJson((yam::base::YIWidget*)pUiRoot, jObj);

    QFile file(sJsonFileName.c_str());
    file.open(QIODevice::WriteOnly);
    std::string sRes = json::Serialize(jObj);
    file.write(sRes.c_str());
    file.close();

    QRect stAreaBound;
    ymnamerelationship::const_iterator citEnd = gs_mRelationship.end();
    for (ymnamerelationship::const_iterator cit = gs_mRelationship.begin(); cit != citEnd; ++cit)
    {
        if (cit->second._eType != eRelationshipType_Res || NULL == cit->second._pUiItem)
        {
            continue;
        }
        stAreaBound |= QRect(cit->second._pUiItem->pos(), cit->second._pUiItem->size());
    }

    QImage oImage(stAreaBound.size(), QImage::Format_ARGB32);
    oImage.fill(Qt::transparent);
    QPainter oPainter(&oImage);
    for (ymnamerelationship::const_iterator cit = gs_mRelationship.begin(); cit != citEnd; ++cit)
    {
        if (cit->second._eType != eRelationshipType_Res || NULL == cit->second._pUiItem)
        {
            continue;
        }
        for (yam::yint32 i = 0; i < cit->second._pUiItem->getImageCount(eImageType_Normal); ++i)
        {
            QImage* const& pImage = cit->second._pUiItem->getImage(eImageType_Normal, i);
            if (NULL == pImage)
            {
                continue;
            }
            oPainter.drawImage(cit->second._pUiItem->pos(), *pImage);
        }
    }
    oImage.save(sPngFileName.c_str(), "PNG");
}

void YCExportYam::ToJson(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
{
    rjObj["type"] = GetNameByWidgetType(pWidget->GetType());

    json::Object jObjValue;
    switch (pWidget->GetType())
    {
    case eWidgetType_Scene:
        ToJsonScene(pWidget, jObjValue);
        break;

    case eWidgetType_Panel:
        ToJsonPanel(pWidget, jObjValue);
        break;

    case eWidgetType_Picture:
        ToJsonPicture(pWidget, jObjValue);
        break;

    case eWidgetType_Button:
        ToJsonButton(pWidget, jObjValue);
        break;

    case eWidgetType_Text:
        ToJsonText(pWidget, jObjValue);
        break;

    default:
        break;
    }

    rjObj["value"] = jObjValue;
}
void YCExportYam::ToJsonWidgetCommon(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
{
    rjObj["id"] = pWidget->GetId();
    rjObj["layer"] = pWidget->GetLayerWeight();

    json::Object jObjDst;
    {
        json::Object jObjDstPos;
        jObjDstPos["x"] = pWidget->GetBound().Pos.X;
        jObjDstPos["y"] = pWidget->GetBound().Pos.Y;
        jObjDst["pos"] = jObjDstPos;
        json::Object jObjDstSize;
        jObjDstSize["x"] = pWidget->GetBound().Size.X;
        jObjDstSize["y"] = pWidget->GetBound().Size.Y;
        jObjDst["size"] = jObjDstSize;
    }
    rjObj["dst"] = jObjDst;

    ToJsonWidgetChildren(pWidget, rjObj);
}

void YCExportYam::ToJsonWidgetChildren(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
{
    const yam::base::YITree* pChild = pWidget->GetChildren();
    if (YNULL == pChild || YOBJECT_GETCLASSNAME(yam::base::YCWidget) != pWidget->GetClassName())
    {
        return;
    }
    json::Array jArr;
    while (YNULL != pChild)
    {
        json::Object jObj;
        ToJson((yam::base::YIWidget*)pChild, jObj);
        jArr.push_back(jObj);

        pChild = pChild->GetNext();
    }
    rjObj["children"] = jArr;
}

void YCExportYam::ToJsonScene(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
{
    ToJsonWidgetCommon(pWidget, rjObj);

    yam::base::YCProperty* pLogic = GetProperty().FindChild<yam::base::YCProperty>("logic");
    yam::ystring sLogicName;
    if (YNULL != pLogic)
    {
        pLogic->ToString(sLogicName);
        rjObj["logic"] = sLogicName;
    }

    json::Array jArr;
    yam::base::YITree* pAssets = GetProperty().FindChild("assets");
    if (YNULL != pAssets)
    {
        yam::base::YITree* pFile = pAssets->FindChild("image");
        while (YNULL != pFile)
        {
            yam::ystring sFile = "";
            yam::ystring sName = "";
            yam::ystring sType = "";
            GetStringByIdFromProperty(pFile, "file", sFile);
            GetStringByIdFromProperty(pFile, "name", sName);
            GetStringByIdFromProperty(pFile, "type", sType);

            json::Object jObjAst;
            jObjAst["file"] = sFile + ".png";
            jObjAst["name"] = sName;
            jObjAst["type"] = sType;
            jArr.push_back(jObjAst);

            pFile = pFile->GetNext();
        }
        rjObj["assets"] = jArr;
    }
}

void YCExportYam::ToJsonPanel(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
{
    ToJsonWidgetCommon(pWidget, rjObj);

    yam::base::YIProperty* pPropertyNoInput = pWidget->GetExternalProperty().FindChild<yam::base::YCProperty>("noinput");
    if (YNULL != pPropertyNoInput)
    {
        std::string sNoInput = "true";
        pPropertyNoInput->ToString(sNoInput);
        rjObj["noinput"] = sNoInput;
    }
}

void YCExportYam::ToJsonImage(const yam::base::YCProperty* pProperty, json::Object& rjObj) const
{
    yam::base::YCProperty* pPropertyOffset = pProperty->FindChild<yam::base::YCProperty>("offset");
    if (YNULL != pPropertyOffset)
    {
        yam::YVec2D stOffset;
        pPropertyOffset->ToVec2D(stOffset);
        json::Object jObjOffset;
        ToJsonVec2D(stOffset, jObjOffset);
        rjObj["offset"] = jObjOffset;
    }

    yam::base::YCProperty* pPropertyBound = pProperty->FindChild<yam::base::YCProperty>("bound");
    if (YNULL != pPropertyBound)
    {
        yam::YRect2D stBound;
        pPropertyBound->ToRect2D(stBound);
        json::Object jObjBound;
        ToJsonRect2D(stBound, jObjBound);
        rjObj["bound"] = jObjBound;
    }
}

void YCExportYam::ToJsonImages(const yam::base::YCProperty* pProperty, json::Array& rjArr) const
{
    yam::base::YCProperty* pPropertyCount = pProperty->FindChild<yam::base::YCProperty>("count");
    if (YNULL == pPropertyCount)
    {
        return;
    }

    json::Array jArrImage;

    yam::yint32 iCount = 0;
    pPropertyCount->ToInt32(iCount);
    for (yam::yint32 i = 0; i < iCount; ++i)
    {
        std::stringstream ss;
        ss << i;
        yam::base::YCProperty* pPropertyItem = pProperty->FindChild<yam::base::YCProperty>(ss.str());
        if (YNULL == pPropertyItem)
        {
            continue;
        }
        json::Object jObjItem;
        ToJsonImage(pPropertyItem, jObjItem);
        rjArr.push_back(jObjItem);
    }
}

void YCExportYam::ToJsonPicture(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
{
    ToJsonWidgetCommon(pWidget, rjObj);

    std::vector<yam::ystring> vsImageName;
    vsImageName.push_back("assets");
    vsImageName.push_back("image");
    vsImageName.push_back("name");
    yam::base::YCProperty* pImageName = GetProperty().Find<yam::base::YCProperty>(vsImageName);
    if (YNULL != pImageName)
    {
        yam::ystring sImageName;
        pImageName->ToString(sImageName);
        rjObj["image"] = sImageName;
    }

    std::vector<yam::ystring> vsPath;
    vsPath.push_back("images");
    vsPath.push_back(YCQUiItem::convertImageTypeToString(eImageType_Normal));
    yam::base::YCProperty* pPropertyImage = pWidget->GetExternalProperty().Find<yam::base::YCProperty>(vsPath);
    if (YNULL != pPropertyImage)
    {
        json::Array jArrSrc;
        ToJsonImages(pPropertyImage, jArrSrc);
        rjObj["src"] = jArrSrc;
    }
}

void YCExportYam::ToJsonButton(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
{
    ToJsonWidgetCommon(pWidget, rjObj);

    std::vector<yam::ystring> vsImageName;
    vsImageName.push_back("assets");
    vsImageName.push_back("image");
    vsImageName.push_back("name");
    yam::base::YIProperty* pImageName = GetProperty().Find<yam::base::YCProperty>(vsImageName);
    if (YNULL != pImageName)
    {
        yam::ystring sImageName;
        pImageName->ToString(sImageName);
        rjObj["image"] = sImageName;
    }

    json::Object jObjSrc;

    for (int i = 0; i < eImageType_Max; ++i)
    {
        EImageType eImageType = (EImageType)i;
        yam::ystring sTypeName = YCQUiItem::convertImageTypeToString(eImageType);

        std::vector<yam::ystring> vsPath;
        vsPath.push_back("images");
        vsPath.push_back(sTypeName);
        yam::base::YCProperty* pPropertySrc = pWidget->GetExternalProperty().Find<yam::base::YCProperty>(vsPath);
        if (YNULL == pPropertySrc)
        {
            continue;
        }

        json::Array jArrImage;
        ToJsonImages(pPropertySrc, jArrImage);
        jObjSrc[sTypeName] = jArrImage;
    }

    rjObj["src"] = jObjSrc;
}

void YCExportYam::ToJsonText(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
{
    ToJsonWidgetCommon(pWidget, rjObj);

    yam::base::YIProperty* pPropertyFont = pWidget->GetExternalProperty().FindChild<yam::base::YCProperty>("font");
    if (YNULL != pPropertyFont)
    {
        std::string sFontName = "";
        pPropertyFont->ToString(sFontName);
        rjObj["font"] = sFontName;
    }
}

yam::ystring YCExportYam::GetNameByWidgetType(const yam::EWidgetType& reType)
{
    switch (reType)
    {
    case yam::eWidgetType_Scene:
        return "scene";

    case yam::eWidgetType_Panel:
        return "panel";

    case yam::eWidgetType_Picture:
        return "picture";

    case yam::eWidgetType_Button:
        return "button";

    case yam::eWidgetType_Image:
        return "image";

    case yam::eWidgetType_Text:
        return "text";

    default:
        return "none";
    }
}

void YCExportYam::GetStringByIdFromProperty(const yam::base::YITree* const& rpTree, const yam::ystring& rsId, yam::ystring& rsValue)
{
    if (YNULL == rpTree)
    {
        return;
    }
    const yam::base::YITree* pChild = rpTree->FindChild(rsId);
    if (YNULL == pChild || YOBJECT_GETCLASSNAME(yam::base::YCProperty) != pChild->GetClassName())
    {
        return;
    }
    ((yam::base::YCProperty*)pChild)->ToString(rsValue);
}

void YCExportYam::ToJsonVec2D(const yam::YVec2D& rstVec2D, json::Object& rjObj)
{
    rjObj["x"] = rstVec2D.X;
    rjObj["y"] = rstVec2D.Y;
}

void YCExportYam::ToJsonRect2D(const yam::YRect2D& rstRect2D, json::Object& rjObj)
{
    json::Object jObjPos;
    ToJsonVec2D(rstRect2D.Pos, jObjPos);
    rjObj["pos"] = jObjPos;

    json::Object jObjSize;
    ToJsonVec2D(rstRect2D.Size, jObjSize);
    rjObj["size"] = jObjSize;
}

}}
