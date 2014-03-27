// The MIT License (MIT) Copyright (c) 2014 Code 4 Game
/*!
  \file buffer.cpp
  \author Alex Chi
  \brief implement of buffer

 */
#include "buffer.h"

namespace yam{ namespace base{

YOBJECT_IMPL(YCBuffer);

/*!
  initialize all member variables
  set the current position to 0
 */
YCBuffer::YCBuffer()
    : m_iPosCurrent(0)
{
    //
}

/*!
  free all memory buffers
 */
YCBuffer::~YCBuffer()
{
    Merge();

    m_iSize = 0;
    if (YNULL != m_pData)
    {
        delete[] m_pData;
        m_pData = YNULL;
    }
}

/*!
  \param rData a string, it will be write to buffer list

  write a string to buffer list
 */
YIBuffer& YCBuffer::In(const ystring& rData)
{
    /// detail:

    /// write the size of string
    yint32 iLen = rData.size();
    Write(sizeof(yint32), (ybuffptr)&iLen);

    /// write the data of string
    Write(sizeof(char) * iLen, (ybuffptr)rData.c_str());
    return *this;
}

/*!
  \param rData a string, it will be set from buffer

  read a string from buffer
 */
YIBuffer& YCBuffer::Out(ystring& rData)
{
    /// detail:

    /// clear the string
    rData = "";

    /// read a int value as size of string
    yint32 iLen = 0;
    Read(sizeof(yint32), (ybuffptr)&iLen);
    /// allocate a memory for string
    ybuffptr pData = new ybuff[iLen + 1];
    /// set '\0' as the end of string
    pData[iLen] = '\0';
    /// read the data
    Read(sizeof(char) * iLen, pData);
    /// set the data to string
    rData.append(pData);
    // free the memory
    delete[] pData; pData = YNULL;
    return *this;
}

/*!
 \return true if it is success to write
  write the data to another buffer
  */
bool YCBuffer::operator>>(YCBuffer& rBuffer) const
{
    /// detail:

    /// write the id
    rBuffer.In(GetId());
    /// write the class name
    rBuffer.In(GetClassName());
    /// write the size of data
    rBuffer.In(GetSize());
    /// write the data
    rBuffer.Write(GetSize(), GetData());
    return true;
}

/*!
  \return true if it is success to read
  read the data from another buffer
 */
bool YCBuffer::operator<<(YCBuffer& rBuffer)
{
    /// detail:

    /// read/set the id
    rBuffer.Out(GetId());
    /// read/set the class name
    rBuffer.Out(GetClassName());
    /// read the size of data
    ybuffsize iSize = 0;
    rBuffer.Out(iSize);
    /// allocate a new memory block
    New(iSize);
    if (0 < iSize)
    {
        /// read the data
        rBuffer.Read(iSize, GetData());
    }
    return true;
}

GET_FUNC_CONST_CUSTOM(ybuffptr&, YCBuffer::GetData)
{
    /// you must make sure the list of buffer already was merge to one buffer
    assert(0 >= m_vBufferSeg.size());
    return m_pData;
}

/*!
  \param riSize the size of data, will be allocated

  it will free old data and allocate a new data
 */
void YCBuffer::New(const ybuffsize& riSize)
{
    /// detail:

    /// free data if it already has a data
    if (YNULL != m_pData)
    {
        delete[] m_pData;
        m_pData = YNULL;
    }

    /// set the size of buffer
    m_iSize = riSize;
    if (0 < m_iSize)
    {
        /// allocate a new block memory for data
        m_pData = new ybuff[m_iSize];
    }
}

/*!
  ready to read the data of buffer
 */
YIBuffer& YCBuffer::Begin()
{
    m_iPosCurrent = 0;
    return *this;
}

/*!
  it will merges the list of buffer after write all data
 */
void YCBuffer::End()
{
    Merge();
}

/*!
  \return true if it success to write the data to buffer

  copy a buffer and push it to the list of buffer
 */
bool YCBuffer::Write(const ybuffsize& riSize, const ybuffptr& rpSrc)
{
    /// detail:

    /// copy the data to a new buffer
    YBuffer stBuffer;
    stBuffer.Size = riSize;
    if (0 < stBuffer.Size)
    {
        assert(YNULL != rpSrc);
        stBuffer.Data = new ybuff[stBuffer.Size];
        ::memcpy(stBuffer.Data, rpSrc, sizeof(ybuff) * stBuffer.Size);
    }
    /// push the new buffer to list
    m_vBufferSeg.push_back(stBuffer);
    return true;
}

/*!
  \return true if it success to read the data from buffer
 */
bool YCBuffer::Read(const ybuffsize& riSize, const ybuffptr& rpDst)
{
    /// detail:

    /// check the current position and the size before reading
    if (0 >= m_iSize || m_iSize < (m_iPosCurrent + riSize) || YNULL == rpDst)
    {
        return false;
    }
    /// copy the data to buffer
    ::memcpy(rpDst, m_pData + m_iPosCurrent, riSize);
    /// move the current position
    m_iPosCurrent += riSize;
    return true;
}

/*!
  \return this reference

  free the data
 */
YIBuffer& YCBuffer::Clear()
{
    /// detail:

    /// set the size of buffer to 0
    m_iSize = 0;
    if (YNULL != m_pData)
    {
        /// free the data memory
        delete[] m_pData;
        m_pData = YNULL;
    }
    /// set the current position to 0
    m_iPosCurrent = 0;
    return *this;
}

/*!
  \param rBuffer another buffer
 */
void YCBuffer::operator=(const YCBuffer& rBuffer)
{
    /// clear the data
    Clear();
    /// ready for write
    Begin();
    /// write the another buffer to self
    /// you need make sure the another is already merged
    Write(rBuffer.GetSize(), rBuffer.GetData());
    /// merge the list of buffer to one buffer
    End();
}

/*!
  merge all buffers to one buffer in the list of buffer
 */
void YCBuffer::Merge()
{
    /// detail:

    /// return if the list of buffer is empty
    if (0 >= m_vBufferSeg.size())
    {
        return;
    }

    /// calculate the total size of buffers
    ybuffsize iSize = m_iSize;
    ybuffptr pData = YNULL;
    {
        yvbuffer::iterator itBuffer = m_vBufferSeg.begin();
        yvbuffer::iterator itBufferEnd = m_vBufferSeg.end();
        for (; itBuffer != itBufferEnd; ++itBuffer)
        {
            iSize += itBuffer->Size;
        }
    }

    /// clear all buffers if the total size is 0
    if (0 >= iSize || iSize == m_iSize)
    {
        m_vBufferSeg.clear();
        return;
    }

    /// allocate a memory for data
    ybuffpos iPos = 0;
    pData = new ybuff[iSize];

    /// copy the buffer data to new data at first
    if (0 < m_iSize)
    {
        ::memcpy((void*)(pData + iPos), m_pData, m_iSize);
        iPos += m_iSize;
    }
    /// free the buffer data
    if (YNULL != m_pData)
    {
        delete[] m_pData;
        m_pData = YNULL;
    }

    /// copy every buffer to new data
    {
        yvbuffer::iterator itBuffer = m_vBufferSeg.begin();
        yvbuffer::iterator itBufferEnd = m_vBufferSeg.end();
        for (; itBuffer != itBufferEnd; ++itBuffer)
        {
            if (0 >= itBuffer->Size)
            {
                continue;
            }
            ::memcpy((void*)(pData + iPos), itBuffer->Data, itBuffer->Size);
            iPos += itBuffer->Size;
            delete[] itBuffer->Data;
        }
        m_vBufferSeg.clear();
    }

    /// set the size of buffer
    m_iSize = iSize;
    /// set the new data as buffer data
    m_pData = pData;
}

}}
