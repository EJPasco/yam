#include "quiitem.h"

#include "yeditorcommon.h"
#include "yeditor.h"
#include "yconverter.h"
#include "quiarea.h"
#include <QtGui/QtEvents>
#include <QtGui/QPainter>
#include <QtWidgets/QPushButton>

YCQUiItem::YCQUiItem(YCQUiArea* parent /* = 0 */, Qt::WindowFlags f /* = 0 */)
    : QWidget(parent, f)
    , m_pUiArea(parent)
    , m_bPressed(false)
    , m_bGrabed(false)
    , m_bSelected(false)
    , m_fAlpha(1.0f)
    , m_bGrabable(true)
    , m_iLayerWeight(0)
    , m_eType(yam::eWidgetType_None)
    , m_eImageType(eImageType_Normal)
    , m_iIndex(0)
    , m_sTextFace("")
    , m_iTextSize(1)
    , m_sTextAlign("")
    , m_sTextValue("")
    , m_bNoInput(true)
{
    QSizePolicy policy = QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    policy.setHeightForWidth(true);
    setSizePolicy(policy);

    for (int i = 0; i < eImageType_Max; ++i)
    {
        m_astImagesData[i]._fSpeed = 0.1f;
    }
    m_stImageDataDefault._pImage = NULL;
}

YCQUiItem::~YCQUiItem()
{
    for (int i = 0; i < eImageType_Max; ++i)
    {
        VImageData::iterator it = m_astImagesData[i]._vstImageData.begin();
        VImageData::iterator itEnd = m_astImagesData[i]._vstImageData.end();
        for (; it != itEnd; ++it)
        {
            YEDITOR_DELETE((*it)._pImage);
        }
        m_astImagesData[i]._vstImageData.clear();
    }
    YEDITOR_DELETE(m_stImageDataDefault._pImage);
}

void YCQUiItem::paintEvent(QPaintEvent* pEvent)
{
    QPainter oPainter(this);

    QImage* pImage = NULL;
    VImageData& rvpImage = m_astImagesData[m_eImageType]._vstImageData;
    QPoint oOffset;
    if (0 <= m_iIndex && rvpImage.size() > m_iIndex)
    {
        pImage = rvpImage[m_iIndex]._pImage;
        oOffset = rvpImage[m_iIndex]._oOffset;
    }
    else
    {
        pImage = m_stImageDataDefault._pImage;
        oOffset = m_stImageDataDefault._oOffset;
    }
    if (NULL != pImage)
    {
        oPainter.setOpacity(m_fAlpha);
        QRect bound = rect();
        bound.moveTo(oOffset);
        oPainter.drawImage(bound, *pImage);
    }

    if (m_bGrabed || m_bSelected)
    {
        oPainter.setOpacity(0.05f);
        oPainter.setBrush(QBrush(Qt::green));
        oPainter.drawRect(0, 0, size().width() - 1, size().height() - 1);
        oPainter.setBrush(Qt::NoBrush);
    }

    if (m_bGrabed)
    {
        oPainter.setOpacity(1.0f);
        oPainter.setPen(QPen(Qt::red));
        oPainter.drawRect(0, 0, size().width() - 1, size().height() - 1);
    }
    else if (m_bSelected)
    {
        oPainter.setOpacity(1.0f);
        oPainter.setPen(QPen(Qt::yellow));
        oPainter.drawRect(0, 0, size().width() - 1, size().height() - 1);
    }
}

void YCQUiItem::mousePressEvent(QMouseEvent* pEvent)
{
    onPressed(this);
    if (m_bGrabable)
    {
        m_bPressed = true;
        m_oPosMousePressStart = pEvent->screenPos();

        setGrabed(true);
    }
    setSelected(true);
}

void YCQUiItem::mouseReleaseEvent(QMouseEvent* pEvent)
{
    m_bPressed = false;

    setGrabed(false);
}

void YCQUiItem::mouseMoveEvent(QMouseEvent* pEvent)
{
    if (!m_bPressed)
    {
        return;
    }
    QPointF oOffset = pEvent->screenPos() - m_oPosMousePressStart;
    move(pos() + oOffset.toPoint());
    m_oPosMousePressStart = pEvent->screenPos();
}

void YCQUiItem::setGrabable(const bool& rbGrabable)
{
    m_bGrabable = rbGrabable;
}

void YCQUiItem::setGrabed(const bool& rbGrabed)
{
    if (m_bGrabed == rbGrabed)
    {
        return;
    }
    m_bGrabed = rbGrabed;

    repaint();
}

void YCQUiItem::setSelected(const bool& rbSelected)
{
    if (m_bSelected == rbSelected)
    {
        return;
    }
    m_bSelected = rbSelected;

    if (m_bSelected)
    {
        m_pUiArea->setSelected(this);
    }
    onSelected(this);

    repaint();
}

void YCQUiItem::setFormat(const yam::base::YIFormat*& rpFormat)
{
    if (YNULL == rpFormat)
    {
        return;
    }
    move(rpFormat->GetBound().Pos.X, rpFormat->GetBound().Pos.Y);
    resize(rpFormat->GetBound().Size.X, rpFormat->GetBound().Size.Y);

    clearImage(eImageType_Normal);
    setImage(eImageType_Normal, 0, yam::YVec2D(), rpFormat);
    if (YNULL == rpFormat->GetColorData())
    {
        setAlpah(0.2f);
    }
    else
    {
        setAlpah(1.0f);
    }

    repaint();
}

void YCQUiItem::setWidget(const yam::base::YIWidget*& rpWidget)
{
    if (NULL == rpWidget)
    {
        return;
    }

    m_eType = rpWidget->GetType();

    if (yam::eWidgetType_Text == m_eType)
    {
        yam::base::YCProperty* pPropertyTextFace = rpWidget->GetExternalProperty().FindChild<yam::base::YCProperty>("face");
        if (YNULL != pPropertyTextFace)
        {
            pPropertyTextFace->ToString(m_sTextFace);
        }

        yam::base::YCProperty* pPropertyTextSize = rpWidget->GetExternalProperty().FindChild<yam::base::YCProperty>("size");
        if (YNULL != pPropertyTextSize)
        {
            pPropertyTextSize->ToInt32(m_iTextSize);
        }

        yam::base::YCProperty* pPropertyTextAlign = rpWidget->GetExternalProperty().FindChild<yam::base::YCProperty>("align");
        if (YNULL != pPropertyTextAlign)
        {
            pPropertyTextAlign->ToString(m_sTextAlign);
        }

        yam::base::YCProperty* pPropertyTextValue = rpWidget->GetExternalProperty().FindChild<yam::base::YCProperty>("value");
        if (YNULL != pPropertyTextValue)
        {
            pPropertyTextValue->ToString(m_sTextValue);
        }
    }

    if (yam::eWidgetType_Panel == m_eType)
    {
        yam::base::YCProperty* pPropertyNoInput = rpWidget->GetExternalProperty().FindChild<yam::base::YCProperty>("noinput");
        if (YNULL != pPropertyNoInput)
        {
            yam::ystring sNoInput;
            pPropertyNoInput->ToString(sNoInput);
            m_bNoInput = (sNoInput == "false") ? false : true;
        }
    }

    if (yam::eWidgetType_Scene == m_eType)
    {
        yam::base::YCProperty* pPropertyScene = rpWidget->GetExternalProperty().FindChild<yam::base::YCProperty>("scene");
        getConfigScene(pPropertyScene, m_stConfigScene);
        m_stConfigScene._stSize = rpWidget->GetBound().Size;
    }

    move(rpWidget->GetBound().Pos.X, rpWidget->GetBound().Pos.Y);
    resize(rpWidget->GetBound().Size.X, rpWidget->GetBound().Size.Y);

    bool bHasImage = false;
    for (int i = 0; i < eImageType_Max; ++i)
    {
        m_astImagesData[i]._vstImageData.clear();

        VFormatData vFormats;
        getFormatImages((EImageType)i, rpWidget, m_astImagesData[i]._fSpeed, vFormats);
        for (size_t j = 0; j < vFormats.size(); ++j)
        {
            setImage((EImageType)i, j, vFormats[j]._stOffset, vFormats[j]._pFormat);
            bHasImage = true;
        }
    }

    if (!bHasImage)
    {
        setColor(qRgba(qrand(), qrand(), qrand(), qrand()));
        setAlpah(0.2f);
    }

    repaint();
}

void YCQUiItem::setColor(const uint& riColor)
{
    if (NULL == m_stImageDataDefault._pImage)
    {
        m_stImageDataDefault._pImage = new QImage(size(), QImage::Format_ARGB32);
    }

    for (int j = 0; j < size().height(); ++j)
    {
        for (int i = 0; i < size().width(); ++i)
        {
            m_stImageDataDefault._pImage->setPixel(i, j, riColor);
        }
    }
}

void YCQUiItem::setAlpah(const qreal& rfAlpha)
{
    m_fAlpha = rfAlpha;
}

void YCQUiItem::setImage(const EImageType& reImageType, const yam::yint32& riImageIndex, const yam::YVec2D& rstImageOffset, const yam::base::YIFormat*& rpFormat)
{
    while (riImageIndex >= (yam::yint32)m_astImagesData[reImageType]._vstImageData.size())
    {
        SImageData stImageData;
        m_astImagesData[reImageType]._vstImageData.push_back(stImageData);
    }

    SImageData& rstImageData = m_astImagesData[reImageType]._vstImageData[riImageIndex];

    if (YNULL != rpFormat)
    {
        yam::ystring sFormatUrl = YEditor::getFullName(rpFormat);
        if (sFormatUrl != rstImageData._sSource.toLocal8Bit().data())
        {
            YEDITOR_DELETE(rstImageData._pImage);
            rstImageData._sSource = sFormatUrl.c_str();
        }

        setImage(rstImageData, rpFormat->GetBound(), rpFormat->GetColorData());
    }

    rstImageData._oOffset = YCConverter::Instance().Convert2Point(rstImageOffset);

    if (reImageType == m_eImageType)
    {
        setAlpah(1.0f);

        repaint();
    }
}

void YCQUiItem::addImage(const EImageType& reImageType)
{
    SImageData stImageData;
    m_astImagesData[reImageType]._vstImageData.push_back(stImageData);
}

void YCQUiItem::delImage(const EImageType& reImageType, const yam::yint32& riImageIndex)
{
    if (riImageIndex < 0 || riImageIndex >= (yam::yint32)m_astImagesData[reImageType]._vstImageData.size())
    {
        return;
    }
    m_astImagesData[reImageType]._vstImageData.erase(m_astImagesData[reImageType]._vstImageData.begin() + riImageIndex);
}

void YCQUiItem::setImage(SImageData& rstImageData, const yam::YRect2D& rstRect, const yam::ycolorptr& rpColorData)
{
    if (NULL != rstImageData._pImage)
    {
        delete rstImageData._pImage;
        rstImageData._pImage = NULL;
    }
    rstImageData._oBound = YCConverter::Instance().Convert(rstRect);

    if (YNULL != rpColorData)
    {
        rstImageData._pImage = new QImage(QSize(rstRect.Size.X, rstRect.Size.Y), QImage::Format_ARGB32);
        for (int y = 0; y < rstRect.Size.Y; ++y)
        {
            for (int x = 0; x < rstRect.Size.X; ++x)
            {
                rstImageData._pImage->setPixel(x, y, convertFromYColor(rpColorData[x + y * rstRect.Size.X]));
            }
        }
    }
}

void YCQUiItem::clearImage(const EImageType& reImageType)
{
    //
}

YCQUiItem* YCQUiItem::setLayerWeight(const int& riLayerWeight)
{
    m_iLayerWeight = riLayerWeight;
    return this;
}

void YCQUiItem::setCurrentImage(const EImageType& reImageType, const yam::yint32& riIndex)
{
    if (m_eImageType == reImageType && m_iIndex == riIndex)
    {
        return;
    }
    m_eImageType = reImageType;
    m_iIndex = riIndex;

    repaint();
}

void YCQUiItem::setTextFace(const yam::ystring& rsFace)
{
    m_sTextFace = rsFace;
}

void YCQUiItem::setTextSize(const yam::yint32& riSize)
{
    m_iTextSize = riSize;
}

void YCQUiItem::setTextAlign(const yam::ystring& rsAlign)
{
    m_sTextAlign = rsAlign;
}

void YCQUiItem::setTextValue(const yam::ystring& rsValue)
{
    m_sTextValue = rsValue;
}

void YCQUiItem::setNoInput(const bool& rbNoInput)
{
    m_bNoInput = rbNoInput;
}

void YCQUiItem::setConfigScene(const SConfigScene& rstConfig)
{
    m_stConfigScene = rstConfig;
}

int YCQUiItem::getLayerWeight() const
{
    return m_iLayerWeight;
}

YCQUiItem::SImagesData& YCQUiItem::getImagesData(const EImageType& reImageType)
{
    return m_astImagesData[reImageType];
}

yam::yint32 YCQUiItem::getImageCount(const EImageType& reImageType) const
{
    return (yam::yint32)m_astImagesData[reImageType]._vstImageData.size();
}

yam::yfloat32 YCQUiItem::getImageSpeed(const EImageType& reImageType) const
{
    return m_astImagesData[reImageType]._fSpeed;
}

QImage* YCQUiItem::getImage(const EImageType& reImageType, const size_t& riIndex) const
{
    if (riIndex < 0 || riIndex >= m_astImagesData[reImageType]._vstImageData.size())
    {
        return NULL;
    }
    return m_astImagesData[reImageType]._vstImageData[riIndex]._pImage;
}

QString YCQUiItem::getImageSource(const EImageType& reImageType, const size_t& riIndex) const
{
    if (riIndex < 0 || riIndex >= m_astImagesData[reImageType]._vstImageData.size())
    {
        return QString();
    }
    return m_astImagesData[reImageType]._vstImageData[riIndex]._sSource;
}

QRect YCQUiItem::getImageBound(const EImageType& reImageType, const size_t& riIndex) const
{
    if (riIndex < 0 || riIndex >= m_astImagesData[reImageType]._vstImageData.size())
    {
        return QRect();
    }
    return m_astImagesData[reImageType]._vstImageData[riIndex]._oBound;
}

QPoint YCQUiItem::getImageOffset(const EImageType& reImageType, const size_t& riIndex) const
{
    if (riIndex < 0 || riIndex >= m_astImagesData[reImageType]._vstImageData.size())
    {
        return QPoint();
    }
    return m_astImagesData[reImageType]._vstImageData[riIndex]._oOffset;
}

yam::EWidgetType YCQUiItem::getType() const
{
    return m_eType;
}

YCQUiArea* YCQUiItem::getArea() const
{
    return m_pUiArea;
}

const yam::ystring& YCQUiItem::getTextFace() const
{
    return m_sTextFace;
}

const yam::yint32& YCQUiItem::getTextSize() const
{
    return m_iTextSize;
}

const yam::ystring& YCQUiItem::getTextAlign() const
{
    return m_sTextAlign;
}

const yam::ystring& YCQUiItem::getTextValue() const
{
    return m_sTextValue;
}

const bool& YCQUiItem::getNoInput() const
{
    return m_bNoInput;
}

const SConfigScene& YCQUiItem::getConfigScene() const
{
    return m_stConfigScene;
}

QRgb YCQUiItem::convertFromYColor(const yam::ycolor& riColor) const
{
    using namespace yam;
    return qRgba(YGETCOLORBIT(riColor, YBITOFFSET_RED)
                , YGETCOLORBIT(riColor, YBITOFFSET_GREEN)
                , YGETCOLORBIT(riColor, YBITOFFSET_BLUE)
                , YGETCOLORBIT(riColor, YBITOFFSET_ALPHA));
}

yam::ystring YCQUiItem::convertImageTypeToString(const EImageType& reImageType)
{
    switch (reImageType)
    {
    case eImageType_Normal:
        return "normal";

    case eImageType_Hover:
        return "hover";

    case eImageType_Press:
        return "press";

    case eImageType_Disable:
        return "disable";

    case eImageType_Checked:
        return "checked";

    case eImageType_Unchecked:
        return "unchecked";

    default:
        break;
    }

    return "";
}

bool YCQUiItem::getFormatImages(const EImageType& reImageType, const yam::base::YIWidget*& rpWidget, yam::yfloat32& rfSpeed, YCQUiItem::VFormatData& rvFormatData) const
{
    rvFormatData.clear();

    yam::base::YCProperty* pPropertyImages = rpWidget->GetExternalProperty().FindChild<yam::base::YCProperty>("images");
    if (YNULL == pPropertyImages)
    {
        return false;
    }
    yam::base::YCProperty* pPropertyImagesType = pPropertyImages->FindChild<yam::base::YCProperty>(YCQUiItem::convertImageTypeToString(reImageType));
    if (YNULL == pPropertyImagesType)
    {
        return false;
    }
    yam::base::YCProperty* pPropertyImagesCount = pPropertyImagesType->FindChild<yam::base::YCProperty>("count");
    if (YNULL == pPropertyImagesCount)
    {
        return false;
    }
    yam::yint32 iCount = 0;
    pPropertyImagesCount->ToInt32(iCount);

    yam::base::YCProperty* pPropertyImagesSpeed = pPropertyImagesType->FindChild<yam::base::YCProperty>("speed");
    if (YNULL != pPropertyImagesSpeed)
    {
        pPropertyImagesSpeed->ToFloat32(rfSpeed, 0.1f);
    }

    for (yam::yint32 i = 0; i < iCount; ++i)
    {
        std::stringstream ss;
        ss << i;
        yam::base::YCProperty* pPropertyImage = pPropertyImagesType->FindChild<yam::base::YCProperty>(ss.str());
        if (YNULL == pPropertyImage)
        {
            continue;
        }
        yam::base::YCProperty* pPropertyImageSource = pPropertyImage->FindChild<yam::base::YCProperty>("source");
        yam::base::YCProperty* pPropertyImageOffset = pPropertyImage->FindChild<yam::base::YCProperty>("offset");
        if (YNULL == pPropertyImageSource || NULL == pPropertyImageOffset)
        {
            continue;
        }
        SFormatData stFormatData;
        stFormatData._pFormat = NULL;
        pPropertyImageSource->ToString(stFormatData._sSource);
        pPropertyImageOffset->ToVec2D(stFormatData._stOffset);
        rvFormatData.push_back(stFormatData);
    }

    VFormatData::iterator it = rvFormatData.begin();
    VFormatData::iterator itEnd = rvFormatData.end();
    for (; it != itEnd; ++it)
    {
        std::vector<yam::ystring> vsPathSeg;
        {
            QString qsImageSource((*it)._sSource.c_str());
            QStringList qvsPathSeg = qsImageSource.split(".");
            for (int i = 1; i < qvsPathSeg.size(); ++i)
            {
                yam::ystring sPathSeg(qvsPathSeg[i].toLocal8Bit());
                vsPathSeg.push_back(sPathSeg);
            }
        }
        (*it)._pFormat = gs_FileTreeData.Find<yam::base::YCFormat>(vsPathSeg);
    }

    return true;
}

void YCQUiItem::getConfigScene(yam::base::YCProperty*& rpProperty, SConfigScene& rstConfig)
{
    if (YNULL == rpProperty)
    {
        return;
    }

    yam::base::YCProperty* pPropertyLogic = rpProperty->FindChild<yam::base::YCProperty>("logic");
    if (YNULL != pPropertyLogic)
    {
        pPropertyLogic->ToString(rstConfig._sLogic, rstConfig._sLogic);
    }

    yam::base::YCProperty* pPropertyAssets = rpProperty->FindChild<yam::base::YCProperty>("assets");
    if (YNULL == pPropertyAssets)
    {
        return;
    }
    yam::base::YCProperty* pPropertyAssetsCount = pPropertyAssets->FindChild<yam::base::YCProperty>("count");
    if (YNULL == pPropertyAssetsCount)
    {
        return;
    }
    yam::yint32 iCount = 0;
    pPropertyAssetsCount->ToInt32(iCount);
    for (yam::yint32 i = 0; i < iCount; ++i)
    {
        std::stringstream ss;
        ss << i;
        yam::base::YCProperty* pPropertyAsset = pPropertyAssets->FindChild<yam::base::YCProperty>(ss.str());
        if (YNULL == pPropertyAsset)
        {
            continue;
        }
        SConfigAsset stAsset;
        yam::base::YCProperty* pPropertyAssetFile = pPropertyAsset->FindChild<yam::base::YCProperty>("file");
        if (YNULL != pPropertyAssetFile)
        {
            pPropertyAssetFile->ToString(stAsset._sFile);
        }
        yam::base::YCProperty* pPropertyAssetName = pPropertyAsset->FindChild<yam::base::YCProperty>("name");
        if (YNULL != pPropertyAssetName)
        {
            pPropertyAssetName->ToString(stAsset._sName);
        }
        yam::base::YCProperty* pPropertyAssetType = pPropertyAsset->FindChild<yam::base::YCProperty>("type");
        if (YNULL != pPropertyAssetType)
        {
            pPropertyAssetType->ToString(stAsset._sType);
        }
        rstConfig._vAssets.push_back(stAsset);
    }
}
