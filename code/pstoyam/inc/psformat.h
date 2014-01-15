#ifndef Y_PSFORMAT_H
#define Y_PSFORMAT_H

#include "pstoyamcommon.h"

namespace yam{ namespace external{

class YIPsFormat
{
public:
	virtual ~YIPsFormat() { ; }

public:
	virtual void Do(FormatRecordPtr& rpRecord) = 0;
};

template<typename TNBase>
class YTPsFormat : public TNBase
{
public:
	YTPsFormat() : m_pChannelProc(NULL), m_pBuffProc(NULL) { ; }
	virtual ~YTPsFormat() { ; }

public:
	virtual void Do(FormatRecordPtr& rpRecord)
	{
		m_pChannelProc = rpRecord->channelPortProcs;
		m_pBuffProc = rpRecord->bufferProcs;
	}

protected:
	yam::base::YCTree		m_Data;
	ChannelPortProcs*		m_pChannelProc;
	BufferProcs*			m_pBuffProc;
};

}}

#endif // Y_PSFORMAT_H
