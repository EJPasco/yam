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
        yam::base::YCProperty* pLogicName = GetProperty().Find<yam::base::YCProperty>("logic");
        if (YNULL != pLogicName)
        {
            pLogicName->ToString(sLogicName);
        }
    }
    yam::ystring sFileName;
    {
        yam::base::YCProperty* pFileName = GetProperty().Find<yam::base::YCProperty>("filename");
        if (YNULL != pFileName)
        {
            pFileName->ToString(sFileName);
        }
    }
    yam::ystring sDirectory;
    {
        yam::base::YCProperty* pDirectory = GetProperty().Find<yam::base::YCProperty>("directory");
        if (YNULL != pDirectory)
        {
            pDirectory->ToString(sDirectory);
        }
    }

    yam::ystring sJsonFileName = sDirectory + "/" + sFileName + ".json";
    yam::ystring sPngFileName = sDirectory + "/" + sFileName + ".png";

    json::Object jObj;
    yam::base::YIWidget* pUi = pTree->FindChild<yam::base::YCWidget>(YFILE_KEY_UI);
    if (YNULL == pUi)
    {
        return;
    }
    ToJson(pUi, jObj);

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
        QImage* const& pImage = cit->second._pUiItem->getImage(YCQUiItem::eImageType_Normal);
        if (NULL == pImage)
        {
            continue;
        }
        oPainter.drawImage(cit->second._pUiItem->pos(), *pImage);
    }
    oImage.save(sPngFileName.c_str(), "PNG");
    //
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

    case eWidgetType_Image:
        ToJsonImage(pWidget, jObjValue);
        break;

    case eWidgetType_Button:
        ToJsonButton(pWidget, jObjValue);
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

    yam::base::YCProperty* pLogic = GetProperty().Find<yam::base::YCProperty>("logic");
    yam::ystring sLogicName;
    if (YNULL != pLogic)
    {
        pLogic->ToString(sLogicName);
        rjObj["logic"] = sLogicName;
    }

    json::Array jArr;
    yam::base::YITree* pAssets = GetProperty().Find("assets");
    if (YNULL != pAssets)
    {
        yam::base::YITree* pFile = pAssets->Find("image");
        while (YNULL != pFile)
        {
            yam::ystring sFile = "";
            yam::ystring sName = "";
            yam::ystring sType = "";
            GetStringByIdFromProperty(pFile, "file", sFile);
            GetStringByIdFromProperty(pFile, "name", sName);
            GetStringByIdFromProperty(pFile, "type", sType);

            json::Object jObjAst;
            jObjAst["file"] = sFile;
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
    //
}

void YCExportYam::ToJsonImage(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
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

    yam::ystring sTypeName = YCQUiItem::convertImageTypeToString(YCQUiItem::eImageType_Normal);

    std::vector<yam::ystring> vsPath;
    vsPath.push_back("image");
    vsPath.push_back(sTypeName);
    vsPath.push_back("source");
    yam::base::YIProperty* pPropertySrc = pWidget->GetExternalProperty().Find<yam::base::YCProperty>(vsPath);
    if (YNULL != pPropertySrc)
    {
        yam::ystring sSrc;
        pPropertySrc->ToString(sSrc);
        SRelationship stRelationship = YEditor::getRelationship(sSrc);
        if (stRelationship._pUiItem)
        {
            json::Object jObjBound;
            ToJsonRect2D(YCConverter::Instance().Convert(QRect(stRelationship._pUiItem->pos(), stRelationship._pUiItem->size())), jObjBound);
            rjObj["src"] = jObjBound;
        }
    }
    //
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

    for (int i = 0; i < YCQUiItem::eImageType_Max; ++i)
    {
        YCQUiItem::EImageType eImageType = (YCQUiItem::EImageType)i;
        yam::ystring sTypeName = YCQUiItem::convertImageTypeToString(eImageType);

        std::vector<yam::ystring> vsPath;
        vsPath.push_back("image");
        vsPath.push_back(sTypeName);
        vsPath.push_back("source");
        yam::base::YIProperty* pPropertySrc = pWidget->GetExternalProperty().Find<yam::base::YCProperty>(vsPath);
        if (YNULL != pPropertySrc)
        {
            yam::ystring sSrc;
            pPropertySrc->ToString(sSrc);
            SRelationship stRelationship = YEditor::getRelationship(sSrc);
            if (stRelationship._pUiItem)
            {
                json::Object jObjBound;
                ToJsonRect2D(YCConverter::Instance().Convert(QRect(stRelationship._pUiItem->pos(), stRelationship._pUiItem->size())), jObjBound);
                jObjSrc[sTypeName] = jObjBound;
            }
        }
    }
    rjObj["src"] = jObjSrc;
    //
}

yam::ystring YCExportYam::GetNameByWidgetType(const yam::EWidgetType& reType)
{
    switch (reType)
    {
    case yam::eWidgetType_Scene:
        return "scene";

    case yam::eWidgetType_Panel:
        return "panel";

    case yam::eWidgetType_Image:
        return "staticimage";

    case yam::eWidgetType_Button:
        return "button";

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
