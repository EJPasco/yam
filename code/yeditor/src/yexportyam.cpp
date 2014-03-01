#include "yexportyam.h"

#include <json.h>
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

void YCExportYam::Save(const yam::base::YITree* pTree) const
{
    yam::base::YCProperty* pFile = GetProperty().Find<yam::base::YCProperty>("file");
    yam::base::YCProperty* pData = GetProperty().Find<yam::base::YCProperty>("data");
    yam::ystring sDirectory;
    yam::ystring sFileName;
    yam::ystring sLogicName;
    if (YNULL != pFile)
    {
        yam::base::YCProperty* pFileDirectory = pFile->Find<yam::base::YCProperty>("directory");
        if (YNULL != pFileDirectory)
        {
            pFileDirectory->ToString(sDirectory);
            sDirectory.append("/");
        }
        yam::base::YCProperty* pFileName = pFile->Find<yam::base::YCProperty>("name");
        if (YNULL != pFileName)
        {
            pFileName->ToString(sFileName);
        }
    }
    if (YNULL != pData)
    {
        yam::base::YCProperty* pDataLogic = pData->Find<yam::base::YCProperty>("logic");
        if (YNULL != pDataLogic)
        {
            pDataLogic->ToString(sLogicName);
        }
    }
    yam::ystring sJsonFileName = sDirectory + sFileName + ".json";
    yam::ystring sPngFileName = sDirectory + sFileName + ".png";

    json::Object jObj;
    yam::base::YITree* pTreeUi = pTree->FindChild(YFILE_KEY_UI);
    if (YNULL == pTreeUi || YOBJECT_GETCLASSNAME(yam::base::YCWidget) != pTreeUi->GetClassName())
    {
        return;
    }
    const yam::base::YIWidget* pUi = (yam::base::YIWidget*)pTreeUi;
    ToJson(pUi, jObj);

    std::string sRes = json::Serialize(jObj);
    sRes = "";

    /*QFile file(stConfig._sJsonFileName);
    file.open(QIODevice::WriteOnly);
    file.write(sRes.c_str());
    file.close();*/

    /*yam::yvvec2d vSize;
    yam::YVec2D stSize;
    stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
    vSize.push_back(stSize);
    stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
    vSize.push_back(stSize);
    stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
    vSize.push_back(stSize);
    stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
    vSize.push_back(stSize);
    stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
    vSize.push_back(stSize);
    stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
    vSize.push_back(stSize);
    stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
    vSize.push_back(stSize);
    stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
    vSize.push_back(stSize);
    stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
    vSize.push_back(stSize);
    stSize.X = qrand() % 80 + 1; stSize.Y = qrand() % 80 + 1;
    vSize.push_back(stSize);
    stSize.X = 500; stSize.Y = 500;
    yam::yvrect vRect;
    YCRectPacker::Instance().Do(vSize, stSize, vRect);
    QVector<QRect> vQRects;
    yam::yvrect::const_iterator cit = vRect.begin();
    yam::yvrect::const_iterator citEnd = vRect.end();
    for (; cit != citEnd; ++cit)
    {
        const yam::YRect2D& rstRect2D = *cit;
        vQRects.push_back(QRect(rstRect2D.Pos.X, rstRect2D.Pos.Y, rstRect2D.Size.X, rstRect2D.Size.Y));
    }

    QImage oImage(stSize.X, stSize.Y, QImage::Format_ARGB32);
    oImage.fill(Qt::transparent);
    QPainter oPainter(&oImage);
    for (int i = 0; i < vQRects.size(); ++i)
    {
        QRgb rgb = qRgba((qrand() % 0xFF), (qrand() % 0xFF), (qrand() % 0xFF), ((qrand() % 0xFF) + 0x55) % 0xFF);
        QImage oImageBox(vQRects[i].width(), vQRects[i].height(), QImage::Format_ARGB32);
        oImageBox.fill(rgb);
        oPainter.drawImage(vQRects[i].x(), vQRects[i].y(), oImageBox);
    }
    oImage.save("D:\\workspace\\github\\temp\\temp.png", "PNG");*/
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

    ToJsonWidgetGroup(pWidget, rjObj);
}

void YCExportYam::ToJsonWidgetGroup(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
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
    rjObj["widgetgroup"] = jArr;
}

void YCExportYam::ToJsonScene(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
{
    ToJsonWidgetCommon(pWidget, rjObj);
}

void YCExportYam::ToJsonPanel(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
{
    ToJsonWidgetCommon(pWidget, rjObj);
    //
}

void YCExportYam::ToJsonImage(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
{
    ToJsonWidgetCommon(pWidget, rjObj);
    //
}

void YCExportYam::ToJsonButton(const yam::base::YIWidget* pWidget, json::Object& rjObj) const
{
    ToJsonWidgetCommon(pWidget, rjObj);
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

}}
