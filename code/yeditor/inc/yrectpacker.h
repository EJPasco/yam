#ifndef Y_RECTPACKER_H
#define Y_RECTPACKER_H

#include <yam.h>

#include <GuillotineBinPack.h>
#include <MaxRectsBinPack.h>

#include <QtCore/QRect>
#include <QtCore/QSize>

class YCRectPacker
{
	SINGLETON_DECL(YCRectPacker);

protected:
	YCRectPacker();
	virtual ~YCRectPacker();

public:
	void Do(const yam::yvvec2d& rvSize, yam::YVec2D& rstSize, yam::yvrect& rvRect) const;

private:
	yam::YVec2D TryPack(const yam::yvvec2d& rvSize, const yam::YVec2D& rstSize, const yam::yfloat32& rfPercentSmall, const yam::yfloat32& rfPercentBig, const yam::yfloat32& rfPercentLastInvalidSmall) const;
	bool CanPack(const yam::yvvec2d& rvSize, const yam::YVec2D& rstSize) const;
	yam::YVec2D ToScale(const yam::YVec2D& rstSize, const yam::yfloat32& rfPercent) const;
	yam::YVec2D ToResize(const yam::YVec2D& rstSize, const yam::yint32& riOffset) const;
	yam::YVec2D Convert(const rbp::RectSize& rstSize) const;
	rbp::RectSize Convert(const yam::YVec2D& rstSize) const;
	yam::yvvec2d Convert(const std::vector<rbp::RectSize>& rvSize) const;
	std::vector<rbp::RectSize> Convert(const yam::yvvec2d& rvSize) const;
	yam::YRect2D Convert(const rbp::Rect& rstRect) const;
	rbp::Rect Convert(const yam::YRect2D& rstRect) const;
	yam::yvrect Convert(const std::vector<rbp::Rect>& rvRect) const;
	std::vector<rbp::Rect> Convert(const yam::yvrect& rvRect) const;
	std::vector<rbp::Rect> ToPack(const yam::yvvec2d& rvSize, const yam::YVec2D& rstSize) const;
};

#endif // Y_RECTPACKER_H
