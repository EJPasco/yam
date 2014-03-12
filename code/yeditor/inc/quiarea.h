#ifndef Y_QUIAREA_H
#define Y_QUIAREA_H

#include "quiitem.h"

#include <QtWidgets/QFrame>

class YCQUiItem;

class YCQUiArea : public QFrame
{
    typedef QFrame                            super;
    typedef std::vector<YCQUiItem*>            yvuiitemptr;

    Q_OBJECT

public:
    YCQUiArea(QWidget* parent = 0, Qt::WindowFlags f = 0);
    YCQUiArea(QFramePrivate &dd, QWidget* parent = 0, Qt::WindowFlags f = 0);
    virtual ~YCQUiArea();

Q_SIGNALS:
    void visibilityChanged(bool bVisible);

public Q_SLOTS:
    void onClickedReset();

protected:
    virtual void showEvent(QShowEvent* pEvent);
    virtual void hideEvent(QHideEvent* pEvent);
    virtual void mousePressEvent(QMouseEvent* pEvent);
    virtual void mouseReleaseEvent(QMouseEvent* pEvent);
    virtual void mouseMoveEvent(QMouseEvent* pEvent);

public:
    void setGrabable(const bool& rbGrabable);
    void setRaiseBySelected(const bool& rbRaiseBySelected);
    void setSelected(const YCQUiItem* const& rpSelectedItem);
    YCQUiItem* addChildItem(const yam::base::YIFormat* pFormat);
    YCQUiItem* addChildItem(const yam::base::YIWidget* pWidget);
    void removeChildItem(const YCQUiItem* const& rpItem);
    void clearChildrenItem();
    void toTiled();

private:
    bool FindAndDelete(yam::yvrect& rvRect2D, const yam::YVec2D& rstVec2D, yam::YRect2D& rstRect2D) const;
    void MoveChildItem(const QPointF& rOffsetF);

private:
    bool            m_bPressed;
    QPointF         m_oPosMousePressStart;
    QPointF         m_oPosOffset;
    yvuiitemptr     m_vItemPtr;
    bool            m_bGrabable;
    bool            m_bRaiseBySelected;
};

#endif // Y_QUIAREA_H
