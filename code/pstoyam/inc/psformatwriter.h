#ifndef Y_PSWRITER_H
#define Y_PSWRITER_H

#include "pstoyamcommon.h"

#include "psformat.h"
#include "pschannel.h"

namespace yam{ namespace external{

class YIPsFormatWriter : public YIPsFormat
{
public:
	virtual ~YIPsFormatWriter() { ; }
};

template<typename TNBase>
class YTPsFormatWriter : public YTPsFormat<TNBase>
{
public:
	YTPsFormatWriter() { ; }
	virtual ~YTPsFormatWriter() { ; }
};

class YCPsFormatWriter : public YTPsFormatWriter<YIPsFormatWriter>
{
public:
	YCPsFormatWriter();
	virtual ~YCPsFormatWriter();

public:
	virtual void Do(FormatRecordPtr& rpRecord);

protected:
	void Do(ReadLayerDesc*& rpLayerDesc, base::YIFormat*& rpFormat);
	void Do(ReadChannelDesc*& rpChannelDesc, const VRect& rstBox, base::YIFormat*& rpFormat, const yuint32& riOffset);
	YRect2D Convert(const VRect& rstBox);

protected:
	YCPsChannelProcs	m_ChannelProc;
};

}}

#endif // Y_PSWRITER_H
