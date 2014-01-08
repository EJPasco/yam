#ifndef Y_EXPORT_H
#define Y_EXPORT_H

#include <yam.h>

namespace yam{ namespace output{

class IYPsFormat : public base::IYFormat
{
public:
	virtual ~IYPsFormat() { ; }

public:
};

template<typename TNBase>
class TYPsFormat : public base::TYFormat<TNBase>
{
public:
	TYPsFormat() { ; }
	virtual ~TYPsFormat() { ; }

public:
};

class CYPsFormat : public TYPsFormat<IYPsFormat>
{
public:
	CYPsFormat();
	virtual ~CYPsFormat();

public:
};

}}

#endif // Y_EXPORT_H
