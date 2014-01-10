#ifndef Y_EXPORT_H
#define Y_EXPORT_H

#include <yam.h>

namespace yam{ namespace output{

class YIPsFormat : public base::YIFormat
{
public:
	virtual ~YIPsFormat() { ; }

public:
};

template<typename TNBase, typename TNReal>
class YTPsFormat : public base::YTFormat<TNBase, TNReal>
{
public:
	YTPsFormat() { ; }
	virtual ~YTPsFormat() { ; }

public:
};

class YCPsFormat : public YTPsFormat<YIPsFormat, YCPsFormat>
{
	YOBJECT_DECL(YCPsFormat);

public:
	YCPsFormat();
	virtual ~YCPsFormat();

public:
};

}}

#endif // Y_EXPORT_H
