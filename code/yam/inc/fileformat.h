#ifndef Y_FILEFORMAT_H
#define Y_FILEFORMAT_H

#include "common.h"

#include "panel.h"

namespace yam{ namespace base{

class IYFileFormat
{
public:
	IYFileFormat() { ; }
	virtual ~IYFileFormat() = 0;

public:
};

class CYFileFormat : public IYFileFormat
{
public:
	CYFileFormat();
	virtual ~CYFileFormat();

public:
};

}}

#endif // Y_FILEFORMAT_H
