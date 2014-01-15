#include "pschannel.h"

namespace yam{ namespace external{

YCPsBufferProcs::YCPsBufferProcs()
	: m_pProcAllocate(NULL)
	, m_pProcFree(NULL)
	, m_pProcLock(NULL)
	, m_pProcUnlock(NULL)
{
	//
}

YCPsBufferProcs::~YCPsBufferProcs()
{
	//
}

void YCPsBufferProcs::operator=(BufferProcs*& rpBufferProcs)
{
	m_pProcAllocate = rpBufferProcs->allocateProc;
	m_pProcFree = rpBufferProcs->freeProc;
	m_pProcLock = rpBufferProcs->lockProc;
	m_pProcUnlock = rpBufferProcs->unlockProc;
}

BufferID YCPsBufferProcs::New(const int32& riSize)
{
	if (NULL == m_pProcAllocate)
	{
		return NULL;
	}
	BufferID pstBufferId = NULL;
	if (noErr != m_pProcAllocate(riSize, &pstBufferId))
	{
		return NULL;
	}
	return pstBufferId;
}

void YCPsBufferProcs::Delete(BufferID& rpstBufferId)
{
	if (NULL == m_pProcFree || NULL == rpstBufferId)
	{
		return;
	}
	m_pProcFree(rpstBufferId);
}

Ptr YCPsBufferProcs::Lock(BufferID& rpstBufferId)
{
	if (NULL == m_pProcLock || NULL == rpstBufferId)
	{
		return NULL;
	}
	return m_pProcLock(rpstBufferId, TRUE);

}

void YCPsBufferProcs::Unlock(BufferID& rpstBufferId)
{
	if (NULL == m_pProcUnlock || NULL == rpstBufferId)
	{
		return;
	}
	m_pProcUnlock(rpstBufferId);
}


YCPsChannelProcs::YCPsChannelProcs()
	: m_pProcReadPixel(NULL)
	, m_pProcWritePixel(NULL)
	, m_pProcReadForWrite(NULL)
{
	//
}

YCPsChannelProcs::~YCPsChannelProcs()
{
	//
}

void YCPsChannelProcs::operator=(FormatRecordPtr& rpRecord)
{
	*this = rpRecord->channelPortProcs;

	m_BufferProcs = rpRecord->bufferProcs;
}

void YCPsChannelProcs::operator=(ChannelPortProcs*& rpChannelProcs)
{
	m_pProcReadPixel = rpChannelProcs->readPixelsProc;
	m_pProcWritePixel = rpChannelProcs->writeBasePixelsProc;
	m_pProcReadForWrite = rpChannelProcs->readPortForWritePortProc;
}

void YCPsChannelProcs::ReadPixel(ReadChannelDesc*& rpChannelDesc, const VRect& rstBox, base::YCBuffer& rPixelBuffer)
{
	if (NULL == m_pProcReadPixel || NULL == rpChannelDesc || rpChannelDesc->depth != YBITCOUNT_INT8)
	{
		return;
	}
	yint32 iWidth = rstBox.right - rstBox.left;
	yint32 iHeigth = rstBox.bottom - rstBox.top;

	BufferID pstBufferId = m_BufferProcs.New(iWidth * iHeigth);
	if (NULL == pstBufferId)
	{
		return;
	}

	PSScaling stScaling;
	stScaling.sourceRect = stScaling.destinationRect = rstBox;

	PixelMemoryDesc stPixelDesc;
	stPixelDesc.data = m_BufferProcs.Lock(pstBufferId);
	stPixelDesc.rowBits = (rstBox.right - rstBox.left) * rpChannelDesc->depth;
	stPixelDesc.colBits = rpChannelDesc->depth;
	stPixelDesc.bitOffset = 0;
	stPixelDesc.depth = rpChannelDesc->depth;

	VRect stBoxRes;
	if (noErr != m_pProcReadPixel(rpChannelDesc->port, &stScaling, &rstBox, &stPixelDesc, &stBoxRes))
	{
		return;
	}

	rPixelBuffer.Begin();
	rPixelBuffer.Write(sizeof(ybuff) * iWidth * iHeigth, (ybuffptr)stPixelDesc.data);
	rPixelBuffer.End();
}

}}
