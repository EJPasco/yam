#include "yconverter.h"

SINGLETON_IMPL(YCConverter);

YCConverter::YCConverter()
{
    //
}

YCConverter::~YCConverter()
{
    //
}

yam::YVec2D YCConverter::Convert(const QSize& rSize) const
{
    yam::YVec2D stVec2D;
    stVec2D.X = rSize.width();
    stVec2D.Y = rSize.height();
    return stVec2D;
}

QSize YCConverter::Convert(const yam::YVec2D& rSize) const
{
    return QSize(rSize.X, rSize.Y);
}

yam::YRect2D YCConverter::Convert(const QRect& rRect) const
{
    yam::YRect2D stRect2D;
    stRect2D.Pos.X = rRect.x();
    stRect2D.Pos.Y = rRect.y();
    stRect2D.Size.X = rRect.width();
    stRect2D.Size.Y = rRect.height();
    return stRect2D;
}

QRect YCConverter::Convert(const yam::YRect2D& rRect) const
{
    return QRect(rRect.Pos.X, rRect.Pos.Y, rRect.Size.X, rRect.Size.Y);
}

yam::YRect2D YCConverter::Merge(const yam::YRect2D& rstRect2Da, const yam::YRect2D& rstRect2Db) const
{
    yam::YRect2D stRect2D;
    stRect2D.Pos.X = (rstRect2Da.Pos.X < rstRect2Db.Pos.X) ? rstRect2Da.Pos.X : rstRect2Db.Pos.X;
    stRect2D.Pos.Y = (rstRect2Da.Pos.Y < rstRect2Db.Pos.Y) ? rstRect2Da.Pos.Y : rstRect2Db.Pos.Y;
    yam::yint32 iRight = ((rstRect2Da.Pos.X + rstRect2Da.Size.X) > (rstRect2Db.Pos.X + rstRect2Db.Size.X)) ? (rstRect2Da.Pos.X + rstRect2Da.Size.X) : (rstRect2Db.Pos.X + rstRect2Db.Size.X);
    yam::yint32 iBottom = ((rstRect2Da.Pos.Y + rstRect2Da.Size.Y) > (rstRect2Db.Pos.Y + rstRect2Db.Size.Y)) ? (rstRect2Da.Pos.Y + rstRect2Da.Size.Y) : (rstRect2Db.Pos.Y + rstRect2Db.Size.Y);
    stRect2D.Size.X = iRight - stRect2D.Pos.X;
    stRect2D.Size.Y = iBottom - stRect2D.Pos.Y;
    return stRect2D;
}

yam::YRect2D YCConverter::Merge(const yam::yvrect& rvRect2D) const
{
    yam::YRect2D stRect2D;
    if (rvRect2D.empty())
    {
        return stRect2D;
    }
    stRect2D = rvRect2D[0];
    for (size_t i = 1; i < rvRect2D.size(); ++i)
    {
        stRect2D = Merge(stRect2D, rvRect2D[i]);
    }
    return stRect2D;
}
