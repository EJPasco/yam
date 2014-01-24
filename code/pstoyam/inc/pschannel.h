#ifndef Y_PSCHANNEL_H
#define Y_PSCHANNEL_H

#include "pstoyamcommon.h"

namespace yam{ namespace external{

class YIPsBufferProcs
{
public:
	virtual ~YIPsBufferProcs() { ; }

public:
	virtual void operator=(BufferProcs*& rpBufferProcs) = 0;

public:
	virtual BufferID New(const int32& riSize) = 0;
	virtual void Delete(BufferID& rpstBufferId) = 0;
	virtual Ptr Lock(BufferID& rpstBufferId) = 0;
	virtual void Unlock(BufferID& rpstBufferId) = 0;
};

class YCPsBufferProcs : public YIPsBufferProcs
{
public:
	YCPsBufferProcs();
	virtual ~YCPsBufferProcs();

public:
	virtual void operator=(BufferProcs*& rpBufferProcs);

public:
	virtual BufferID New(const int32& riSize);
	virtual void Delete(BufferID& rpstBufferId);
	virtual Ptr Lock(BufferID& rpstBufferId);
	virtual void Unlock(BufferID& rpstBufferId);

private:
	AllocateBufferProc		m_pProcAllocate;
	FreeBufferProc			m_pProcFree;
	LockBufferProc			m_pProcLock;
	UnlockBufferProc		m_pProcUnlock;
};

class YIPsChannelProcs
{
public:
	virtual ~YIPsChannelProcs() { ; }

public:
	virtual void operator=(FormatRecordPtr& rpRecord) = 0;
	virtual void operator=(ChannelPortProcs*& rpChannelProcs) = 0;

public:
	virtual void ReadPixel(const ReadChannelDesc* const& rpChannelDesc, const VRect& rstBox, base::YCBuffer& rPixelBuffer) = 0;
};

class YCPsChannelProcs : public YIPsChannelProcs
{
public:
	explicit YCPsChannelProcs();
	virtual ~YCPsChannelProcs();

public:
	virtual void operator=(FormatRecordPtr& rpRecord);
	virtual void operator=(ChannelPortProcs*& rpChannelProcs);

public:
	virtual void ReadPixel(const ReadChannelDesc* const& rpChannelDesc, const VRect& rstBox, base::YCBuffer& rPixelBuffer);

private:
	ReadPixelsProc				m_pProcReadPixel;
	WriteBasePixelsProc			m_pProcWritePixel;
	ReadPortForWritePortProc	m_pProcReadForWrite;
	YCPsBufferProcs				m_BufferProcs;
};

}}

#endif // Y_PSCHANNEL_H
