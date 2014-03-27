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
        tagImageData() : _pImage(NULL) { ; }
    } SImageData;
    typedef std::vector<SImageData>        VImageData;
    typedef struct tagImagesData
    {
        yam::yfloat32   _fSpeed;
        VImageData      _vstImageData;
        tagImagesData() : _fSpeed(0.1f) { ; }
    } SImagesData;

    typedef struct tagFormatData
    {
        const yam::base::YIFormat* _pFormat;
        yam::ystring _sSource;
        yam::YVec2D _stOffset;
        tagFormatData() : _pFormat(NULL) { ; }
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
    void addImage(const EImageType& reImageType);
    void delImage(const EImageType& reImageType, const yam::yint32& riImageIndex);
    void clearImage(const EImageType& reImageType);
    YCQUiItem* setLayerWeight(const int& riLayerWeight);
    void setCurrentImage(const EImageType& reImageType, const yam::yint32& riIndex);
    void setTextFace(const yam::ystring& rsFace);
    void setTextSize(const yam::yint32& riSize);
    void setTextAlign(const yam::ystring& rsAlignType);
    void setTextValue(const yam::ystring& rsValue);
    void setNoInput(const bool& rbNoInput);
    void setConfigScene(const SConfigScene& rstConfig);

public:
    int getLayerWeight() const;
    SImagesData& getImagesData(const EImageType& reImageType);
    yam::yint32 getImageCount(const EImageType& reImageType) const;
    yam::yfloat32 getImageSpeed(const EImageType& reImageType) const;
    SImageData getImageData(const EImageType& reImageType, const size_t& riIndex) const;
    QImage* getImage(const EImageType& reImageType, const size_t& riIndex) const;
    QString getImageSource(const EImageType& reImageType, const size_t& riIndex) const;
    QRect getImageBound(const EImageType& reImageType, const size_t& riIndex) const;
    QPoint getImageOffset(const EImageType& reImageType, const size_t& riIndex) const;
    yam::EWidgetType getType() const;
    YCQUiArea* getArea() const;
    const yam::ystring& getTextFace() const;
    const yam::yint32& getTextSize() const;
    const yam::ystring& getTextAlign() const;
    const yam::ystring& getTextValue() const;
    const bool& getNoInput() const;
    const SConfigScene& getConfigScene() const;

public:
    QRgb convertFromYColor(const yam::ycolor& riColor) const;
    static yam::ystring convertImageTypeToString(const EImageType& reImageType);

private:
    void setImage(SImageData& rstImageData, const yam::YRect2D& rstRect, const yam::ycolorptr& rpColorData);
    bool getFormatImages(const EImageType& reImageType, const yam::base::YIWidget*& rpWidget, yam::yfloat32& rfSpeed, VFormatData& rvFormatData) const;
    void getConfigScene(yam::base::YCProperty*& rpProperty, SConfigScene& rstConfig);

private:
    YCQUiArea*              m_pUiArea;
    SImagesData             m_astImagesData[eImageType_Max];
    SImageData              m_stImageDataDefault;
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
    yam::ystring            m_sTextFace;
    yam::yint32             m_iTextSize;
    yam::ystring            m_sTextAlign;
    yam::ystring            m_sTextValue;
    bool                    m_bNoInput;
    SConfigScene            m_stConfigScene;
};


#endif // Y_QUIITEM_H
