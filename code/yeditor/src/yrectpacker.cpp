#include "yrectpacker.h"

SINGLETON_IMPL(YCRectPacker);

YCRectPacker::YCRectPacker()
{
	//
}

YCRectPacker::~YCRectPacker()
{
	//
}

void YCRectPacker::Do(const yam::yvvec2d& rvSize, yam::YVec2D& rstSize, yam::yvrect& rvRect) const
{
	yam::YVec2D stSize;
	stSize.X = 1024;
	stSize.Y = 1024;
	TryPack(rvSize, stSize, 0.5f, rvRect);
}

void YCRectPacker::TryPack(const yam::yvvec2d& rvSize, yam::YVec2D stSize, yam::yfloat32 fPercent, yam::yvrect& rvRect) const
{
	yam::YVec2D stSizeOld = stSize;
	stSize = ToScale(stSize, fPercent);
	if (stSizeOld.X == stSize.X)
	{
		return;
	}

	rbp::GuillotineBinPack oBinPack;
	oBinPack.Init(stSize.X, stSize.Y);
	std::vector<rbp::RectSize> rectsizes = Convert(rvSize);
	oBinPack.Insert(rectsizes, false, rbp::GuillotineBinPack::RectBestShortSideFit, rbp::GuillotineBinPack::SplitMinimizeArea);
	std::vector<rbp::Rect> rects = oBinPack.GetUsedRectangles();
	if (rects.size() == rvSize.size())
	{
		// to small
		TryPack(rvSize, stSize, fPercent - fPercent * 0.5f, rvRect);
	}
	else
	{
		// to big
		TryPack(rvSize, stSize, fPercent + fPercent * 0.5f, rvRect);
	}
	rvRect = Convert(oBinPack.GetUsedRectangles());
}

yam::YVec2D YCRectPacker::ToScale(const yam::YVec2D& rstSize, const yam::yfloat32& rfPercent) const
{
	yam::YVec2D stSize = rstSize;
	stSize.X = static_cast<yam::yint32>(stSize.X * rfPercent);
	stSize.Y = static_cast<yam::yint32>(stSize.Y * rfPercent);
	return stSize;
}

yam::YVec2D YCRectPacker::ToResize(const yam::YVec2D& rstSize, const yam::yint32& riOffset) const
{
	yam::YVec2D stSize = rstSize;
	stSize.X = stSize.X + riOffset;
	stSize.Y = stSize.Y + riOffset;
	return stSize;
}

yam::YVec2D YCRectPacker::Convert(const rbp::RectSize& rstSize) const
{
	yam::YVec2D stSize;
	stSize.X = rstSize.width;
	stSize.Y = rstSize.height;
	return stSize;
}

rbp::RectSize YCRectPacker::Convert(const yam::YVec2D& rstSize) const
{
	rbp::RectSize stSize;
	stSize.width = rstSize.X;
	stSize.height = rstSize.Y;
	return stSize;
}
yam::yvvec2d YCRectPacker::Convert(const std::vector<rbp::RectSize>& rvSize) const
{
	yam::yvvec2d vSize;
	std::vector<rbp::RectSize>::const_iterator cit = rvSize.begin();
	std::vector<rbp::RectSize>::const_iterator citEnd = rvSize.end();
	for (; cit != citEnd; ++cit)
	{
		vSize.push_back(Convert(*cit));
	}
	return vSize;
}

std::vector<rbp::RectSize> YCRectPacker::Convert(const yam::yvvec2d& rvSize) const
{
	std::vector<rbp::RectSize> vSize;
	yam::yvvec2d::const_iterator cit = rvSize.begin();
	yam::yvvec2d::const_iterator citEnd = rvSize.end();
	for (; cit != citEnd; ++cit)
	{
		vSize.push_back(Convert(*cit));
	}
	return vSize;
}

yam::YRect2D YCRectPacker::Convert(const rbp::Rect& rstRect) const
{
	yam::YRect2D stRect;
	stRect.Pos.X = rstRect.x;
	stRect.Pos.Y = rstRect.y;
	stRect.Size.X = rstRect.width;
	stRect.Size.Y = rstRect.height;
	return stRect;
}

rbp::Rect YCRectPacker::Convert(const yam::YRect2D& rstRect) const
{
	rbp::Rect stRect;
	stRect.x = rstRect.Pos.X;
	stRect.y = rstRect.Pos.Y;
	stRect.width = rstRect.Size.X;
	stRect.height = rstRect.Size.Y;
	return stRect;
}

yam::yvrect YCRectPacker::Convert(const std::vector<rbp::Rect>& rvRect) const
{
	yam::yvrect vRect;
	std::vector<rbp::Rect>::const_iterator cit = rvRect.begin();
	std::vector<rbp::Rect>::const_iterator citEnd = rvRect.end();
	for (; cit != citEnd; ++cit)
	{
		vRect.push_back(Convert(*cit));
	}
	return vRect;
}

std::vector<rbp::Rect> YCRectPacker::Convert(const yam::yvrect& rvRect) const
{
	std::vector<rbp::Rect> vRect;
	yam::yvrect::const_iterator cit = rvRect.begin();
	yam::yvrect::const_iterator citEnd = rvRect.end();
	for (; cit != citEnd; ++cit)
	{
		vRect.push_back(Convert(*cit));
	}
	return vRect;
}
