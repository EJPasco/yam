#include "merge.h"

#include <algorithm>

namespace yam{ namespace util{

SINGLETON_IMPL(YCMerge);

YCMerge::YCMerge()
{
	//
}

YCMerge::~YCMerge()
{
	//
}

class CompareYVec2D
{
public:
	bool operator()(const YVec2D& rstA, const YVec2D& rstB)
	{
		return (YCMerge::CalcLengthSquare(rstA) > YCMerge::CalcLengthSquare(rstB));
	}
};

void YCMerge::Do(const yvvec2d& rvSizeList, YRect2D& rstFinal, yvrect& rvDetail) const
{
	rstFinal = YRect2D::None;
	rvDetail.clear();

	if (0 >= rvSizeList.size())
	{
		return;
	}

	yvvec2d vSizeList = rvSizeList;
	std::sort(vSizeList.begin(), vSizeList.end(), CompareYVec2D());

	YRect2D stBound = YRect2D(YVec2D::None, vSizeList[0]);
	rstFinal = Unite(rstFinal, stBound);
	rvDetail.push_back(stBound);
	//
}

YRect2D YCMerge::Unite(const YRect2D& rstA, const YRect2D& rstB)
{
	YVec2D stPos;
	stPos.X = (rstA.Pos.X < rstB.Pos.X ? rstA.Pos.X : rstB.Pos.X);
	stPos.Y = (rstA.Pos.Y < rstB.Pos.Y ? rstA.Pos.Y : rstB.Pos.Y);
	YVec2D stSize;
	stSize.X = ((rstA.Pos.X + rstA.Size.X) > (rstB.Pos.X + rstB.Size.X) ? (rstA.Pos.X + rstA.Size.X) : (rstB.Pos.X + rstB.Size.X));
	stSize.Y = ((rstA.Pos.Y + rstA.Size.Y) > (rstB.Pos.Y + rstB.Size.Y) ? (rstA.Pos.Y + rstA.Size.Y) : (rstB.Pos.Y + rstB.Size.Y));
	return YRect2D(stPos, stSize);
}

yint32 YCMerge::CalcLengthSquare(const YVec2D& rstSize)
{
	return (rstSize.X * rstSize.X + rstSize.Y * rstSize.Y);
}

}}
