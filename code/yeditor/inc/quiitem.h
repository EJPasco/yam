#ifndef Y_QUIITEM_H
#define Y_QUIITEM_H

#include "yeditorcommon.h"

#include <QtWidgets/QWidget>

class YCQUiArea;

class YCQUiItem : public QWidget
{
    Q_OBJECT

public:
    typedef struct tagImageData
    {
        QImage*     _pImage;
        QString     _sSource;
        QPoint      _oOffset;
        QRect       _oBound;
    } SImageData;
    typedef std::vector<SImageData>        VImageData;

    typedef struct tagFormatData
    {
        const yam::base::YIFormat* _pFormat;
        yam::ystring _sSource;
        yam::YVec2D _stOffset;
    } SFormatData;
    typedef std::vector<SFormatData>        VFormatData;

public:
    explicit YCQUiItem(YCQUiArea* parent = 0, Qt::WindowFlags f = 0);
    virtual ~YCQUiItem();

Q_SIGNALS:
    void onPressed(YCQUiItem* pUiItem);
    void onSelected(YCQUiItem* pUiItem);

protected:
    virtual void paintEvent(QPaintEvent* pEvent);

protected:
    virtual void mousePressEvent(QMouseEvent* pEvent);
    virtual void mouseReleaseEvent(QMouseEvent* pEvent);
    virtual void mouseMoveEvent(QMouseEvent* pEvent);

public:
    void setGrabable(const bool& rbGrabable);
    void setGrabed(const bool& rbGrabed);
    void setSelected(const bool& rbSelected);
    void setFormat(const yam::base::YIFormat*& rpFormat);
    void setWidget(const yam::base::YIWidget*& rpWidget);
    void setColor(const uint& riColor);
    void setAlpah(const qreal& rfAlpha);
    void setImage(const EImageType& reImageType, const yam::yint32& riImageIndex, const yam::YVec2D& rstImageOffset, const yam::base::YIFormat*& rpFormat);
    void clearImage(const EImageType& reImageType);
    YCQUiItem* setLayerWeight(const int& riLayerWeight);
    void setCurrentImage(const EImageType& reImageType, const yam::yint32& riIndex);
    void setFontName(const yam::ystring& rsFontName);
    void setNoInput(const bool& rbNoInput);

public:
    int getLayerWeight() const;
    VImageData& getImageDataList(const EImageType& reImageType);
    yam::yint32 getImageCount(const EImageType& reImageType) const;
    SImageData getImageData(const EImageType& reImageType, const size_t& riIndex) const;
    QImage* getImage(const EImageType& reImageType, const size_t& riIndex) const;
    QString getImageSource(const EImageType& reImageType, const size_t& riIndex) const;
    QRect getImageBound(const EImageType& reImageType, const size_t& riIndex) const;
    QPoint getImageOffset(const EImageType& reImageType, const size_t& riIndex) const;
    yam::EWidgetType getType() const;
    YCQUiArea* getArea() const;
    const yam::ystring& getFontName() const;
    const bool& getNoInput() const;

public:
    QRgb convertFromYColor(const yam::ycolor& riColor) const;
    static yam::ystring convertImageTypeToString(EImageType eImageType);

private:
    void setImage(SImageData& rstImageData, const yam::YRect2D& rstRect, const yam::ycolorptr& rpColorData);
    bool getFormatImages(const EImageType& reImageType, const yam::base::YIWidget*& rpWidget, VFormatData& rvFormatData) const;
    bool getFormatImage(const EImageType& reImageType, const yam::yint32& riImageIndex, const yam::base::YIWidget*& rpWidget, SFormatData& rstFormatData) const;

private:
    YCQUiArea*              m_pUiArea;
    VImageData              m_avImageData[eImageType_Max];
    SImageData              m_stImageDefault;
    bool                    m_bPressed;
    QPointF                 m_oPosMousePressStart;
    bool                    m_bGrabable;
    bool                    m_bGrabed;
    bool                    m_bSelected;
    qreal                   m_fAlpha;
    int                     m_iLayerWeight;
    yam::EWidgetType        m_eType;
    size_t                  m_iIndex;
    EImageType              m_eImageType;
    yam::ystring            m_sFontName;
    bool                    m_bNoInput;
};


#endif // Y_QUIITEM_H
