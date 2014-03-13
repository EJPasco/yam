#include "quiitem.h"

#include "yeditorcommon.h"
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
    , m_eImageType(YCQUiItem::eImageType_Normal)
{
    QSizePolicy policy = QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    policy.setHeightForWidth(true);
    setSizePolicy(policy);

    for (int i = 0; i < eImageType_Max; ++i)
    {
        m_apImage[i] = NULL;
    }
    
}

YCQUiItem::~YCQUiItem()
{
    for (int i = 0; i < eImageType_Max; ++i)
    {
        YEDITOR_DELETE(m_apImage[i]);
    }
}

void YCQUiItem::paintEvent(QPaintEvent* pEvent)
{
    QPainter oPainter(this);

    QImage* pImage = m_apImage[m_eImageType];
    if (NULL == pImage)
    {
        pImage = m_apImage[eImageType_Normal];
    }
    if (NULL != pImage)
    {
        oPainter.setOpacity(m_fAlpha);
        oPainter.drawImage(rect(), *pImage);
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

    setImage(eImageType_Normal, rpFormat->GetBound(), rpFormat->GetColorData());
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

    move(rpWidget->GetBound().Pos.X, rpWidget->GetBound().Pos.Y);
    resize(rpWidget->GetBound().Size.X, rpWidget->GetBound().Size.Y);

    yam::ystring sImageSourceNormal = "";
    const yam::base::YIFormat* pFormatNormal = getFormat(eImageType_Normal, rpWidget, sImageSourceNormal);

    if (NULL != pFormatNormal)
    {
        setImage(eImageType_Normal, pFormatNormal->GetBound(), pFormatNormal->GetColorData());
        setImageBound(eImageType_Normal, YCConverter::Instance().Convert(pFormatNormal->GetBound()));
        setImageSource(eImageType_Normal, sImageSourceNormal.c_str());

        for (int i = 0; i < eImageType_Max; ++i)
        {
            EImageType eType = (EImageType)i;
            if (eImageType_Normal == eType)
            {
                continue;
            }
            yam::ystring sImageSource = "";
            const yam::base::YIFormat* pFormat = getFormat(eType, rpWidget, sImageSource);
            if (YNULL == pFormat)
            {
                continue;
            }
            setImage(eType, pFormat->GetBound(), pFormat->GetColorData());
            setImageBound(eImageType_Normal, YCConverter::Instance().Convert(pFormat->GetBound()));
            setImageSource(eType, sImageSource.c_str());
        }
        setAlpah(1.0f);
    }
    else
    {
        setColor(qRgba(qrand(), qrand(), qrand(), qrand()));
        setAlpah(0.2f);
    }

    repaint();
}

void YCQUiItem::setColor(const uint& riColor)
{
    if (NULL == m_apImage[eImageType_Normal])
    {
        m_apImage[eImageType_Normal] = new QImage(size(), QImage::Format_ARGB32);
    }
    for (int j = 0; j < size().height(); ++j)
    {
        for (int i = 0; i < size().width(); ++i)
        {
            m_apImage[eImageType_Normal]->setPixel(i, j, riColor);
        }
    }
}

void YCQUiItem::setAlpah(const qreal& rfAlpha)
{
    m_fAlpha = rfAlpha;
}

void YCQUiItem::setImage(const EImageType& reImageType, const yam::YRect2D& rstRect, const yam::ycolorptr& rpColorData)
{
    if (NULL != m_apImage[reImageType])
    {
        delete m_apImage[reImageType];
        m_apImage[reImageType] = NULL;
    }

    if (YNULL != rpColorData)
    {
        m_apImage[reImageType] = new QImage(QSize(rstRect.Size.X, rstRect.Size.Y), QImage::Format_ARGB32);
        for (int y = 0; y < rstRect.Size.Y; ++y)
        {
            for (int x = 0; x < rstRect.Size.X; ++x)
            {
                m_apImage[reImageType]->setPixel(x, y, convertFromYColor(rpColorData[x + y * rstRect.Size.X]));
            }
        }
    }

    if (reImageType == m_eImageType)
    {
        setAlpah(1.0f);

        repaint();
    }
}

YCQUiItem* YCQUiItem::setImageSource(const EImageType& reImageType, const QString& rsImageSource)
{
    m_asImageSource[reImageType] = rsImageSource;
    return this;
}

YCQUiItem* YCQUiItem::setImageBound(const EImageType& reImageType, const QRect& roImageBound)
{
    m_aoImageBound[reImageType] = roImageBound;
    return this;
}

YCQUiItem* YCQUiItem::setLayerWeight(const int& riLayerWeight)
{
    m_iLayerWeight = riLayerWeight;
    return this;
}

void YCQUiItem::setImageType(const EImageType& reImageType)
{
    if (m_eImageType == reImageType)
    {
        return;
    }
    m_eImageType = reImageType;
    repaint();
}

int YCQUiItem::getLayerWeight() const
{
    return m_iLayerWeight;
}

QImage* const& YCQUiItem::getImage(const EImageType& reImageType) const
{
    return m_apImage[reImageType];
}

QString YCQUiItem::getImageSource(const EImageType& reImageType) const
{
    return m_asImageSource[reImageType];
}

QRect YCQUiItem::getImageBound(const EImageType& reImageType) const
{
    return m_aoImageBound[reImageType];
}

yam::EWidgetType YCQUiItem::getType() const
{
    return m_eType;
}

YCQUiArea* YCQUiItem::getArea() const
{
    return m_pUiArea;
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
    yam::ystring sTypeName = "";
    if (eImageType_Normal == reImageType)
    {
        sTypeName = "normal";
    }
    else if (eImageType_Hover == reImageType)
    {
        sTypeName = "hover";
    }
    else if (eImageType_Press == reImageType)
    {
        sTypeName = "press";
    }
    else if (eImageType_Disable == reImageType)
    {
        sTypeName = "disable";
    }
    else if (eImageType_Checked == reImageType)
    {
        sTypeName = "checked";
    }
    else if (eImageType_Unchecked == reImageType)
    {
        sTypeName = "unchecked";
    }
    return sTypeName;
}

const yam::base::YIFormat* YCQUiItem::getFormat(const EImageType& reImageType, const yam::base::YIWidget*& rpWidget, yam::ystring& rsImagesource)
{
    yam::base::YIProperty* pPropertyImageSource = NULL;
    {
        std::vector<yam::ystring> vsPath;
        vsPath.push_back("image");
        vsPath.push_back(convertImageTypeToString(reImageType));
        vsPath.push_back("source");
        pPropertyImageSource = rpWidget->GetExternalProperty().Find<yam::base::YCProperty>(vsPath);
        if (NULL != pPropertyImageSource)
        {
            pPropertyImageSource->ToString(rsImagesource);
        }
    }

    std::vector<yam::ystring> vsPathSeg;
    {
        QString qsImageSource(rsImagesource.c_str());
        QStringList qvsPathSeg = qsImageSource.split(".");
        for (int i = 1; i < qvsPathSeg.size(); ++i)
        {
            yam::ystring sPathSeg(qvsPathSeg[i].toLocal8Bit());
            vsPathSeg.push_back(sPathSeg);
        }
    }
    return gs_FileTreeData.Find<yam::base::YCFormat>(vsPathSeg);
}
