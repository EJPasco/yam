#ifndef Y_MERGE_H
#define Y_MERGE_H

#include "common.h"

namespace yam{ namespace util{

class YIMerge
{
public:
	virtual ~YIMerge() { ; }

public:
	virtual void Do(const yvvec2d& rvSizeList, YRect2D& rstFinal, yvrect& rvDetail) const = 0;
};

template<typename TNBase>
class YTMerge : public TNBase
{
public:
	YTMerge() { ; }
	virtual ~YTMerge() { ; }

public:
};

class YCMerge : public YTMerge<YIMerge>
{
	SINGLETON_DECL(YCMerge);

public:
	YCMerge();
	virtual ~YCMerge();

public:
	virtual void Do(const yvvec2d& rvSizeList, YRect2D& rstFinal, yvrect& rvDetail) const;

public:
	static YRect2D Unite(const YRect2D& rstA, const YRect2D& rstB);
	static yint32 CalcLengthSquare(const YVec2D& rstSize);
};

}}

#endif // Y_MERGE_H
