#ifndef Y_QUIITEM_H
#define Y_QUIITEM_H

#include "yeditorcommon.h"

#include <QtWidgets/QWidget>

class YCQUiArea;

class YCQUiItem : public QWidget
{
    Q_OBJECT

public:
    enum EImageType
    {
        eImageType_Normal,
        eImageType_Hover,
        eImageType_Press,
        eImageType_Disable,
        eImageType_Checked,
        eImageType_Unchecked,
        eImageType_Max,
    };

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
    void setImage(const EImageType& reImageType, const yam::YRect2D& rstRect, const yam::ycolorptr& rpColorData);
    YCQUiItem* setImageSource(const EImageType& reImageType, const QString& rsImageSource);
    YCQUiItem* setImageBound(const EImageType& reImageType, const QRect& roImageBound);
    YCQUiItem* setLayerWeight(const int& riLayerWeight);
    void setImageType(const EImageType& reImageType);

public:
    int getLayerWeight() const;
    QImage* const& getImage(const EImageType& reImageType) const;
    QString getImageSource(const EImageType& reImageType) const;
    QRect getImageBound(const EImageType& reImageType) const;
    yam::EWidgetType getType() const;
    YCQUiArea* getArea() const;

public:
    QRgb convertFromYColor(const yam::ycolor& riColor) const;
    static yam::ystring convertImageTypeToString(const EImageType& reImageType);

private:
    const yam::base::YIFormat* getFormat(const EImageType& reImageType, const yam::base::YIWidget*& rpWidget, yam::ystring& rsImagesource);

private:
    YCQUiArea*          m_pUiArea;
    QImage*             m_apImage[eImageType_Max];
    QString             m_asImageSource[eImageType_Max];
    QRect               m_aoImageBound[eImageType_Max];
    bool                m_bPressed;
    QPointF             m_oPosMousePressStart;
    bool                m_bGrabable;
    bool                m_bGrabed;
    bool                m_bSelected;
    qreal               m_fAlpha;
    int                 m_iLayerWeight;
    yam::EWidgetType    m_eType;
    EImageType          m_eImageType;
};


#endif // Y_QUIITEM_H
