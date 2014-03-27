// The MIT License (MIT) Copyright (c) 2014 Code 4 Game
/*!
  \file buffer.h
  \author Alex Chi
  \brief hold a block of memory to store the data

 */
#ifndef Y_BUFFER_H
#define Y_BUFFER_H

#include "common.h"

#include "object.h"

namespace yam{ namespace base{

/*!
  \class YIBuffer
  \brief holder of memory block, easy to use to store a memory data
 */
class YIBuffer : public YIObject
{
public:
    virtual ~YIBuffer() { ; }

public:
    /*! \brief get the size of buffer */
    virtual GET_DECL_CONST(ybuffsize&, GetSize) = 0;
    /*! \brief get the data of buffer */
    virtual GET_DECL_CONST(ybuffptr&, GetData) = 0;

public:
    /*! \brief allocate a new memory */
    virtual void New(const ybuffsize& riSize) = 0;
    /*! \brief set current memory position to 0 before write new buffer */
    virtual YIBuffer& Begin() = 0;
    /*! \brief call it after write all buffers, it will merge the all buffers to one buffer */
    virtual void End() = 0;
    /*! \brief write a memory buffer to buffer list */
    virtual bool Write(const ybuffsize& riSize, const ybuffptr& rpSrc) = 0;
    /*! \brief read a memory buffer */
    virtual bool Read(const ybuffsize& riSize, const ybuffptr& rpDst) = 0;
    /*! \brief clear the data buffer, notice: it don't clear the list of buffer */
    virtual YIBuffer& Clear() = 0;
};

/*!
  \class YTBuffer
  \brief a template class of YIBuffer
 */
template<typename TNBase, typename TNReal>
class YTBuffer : public YTObject<TNBase, TNReal>
{
public:
    /*!
      \brief constructor

      set the m_iSize to 0

      set the m_pData to YNULL
      */
    YTBuffer() : m_iSize(0), m_pData(YNULL) { ; }
    /*! \brief destructor */
    virtual ~YTBuffer() { ; }

public:
    /*! \sa YIBuffer::GET_DECL_CONST(ybuffsize&, GetSize) */
    virtual GET_FUNC_CONST(ybuffsize&, GetSize, m_iSize);

public:

protected:
    /*! the size of data */
    ybuffsize        m_iSize;
    /*! the data */
    ybuffptr        m_pData;
};

/*!
  \class YCBuffer
  \brief a implement class of YIBuffer
 */
class YCBuffer : public YTBuffer<YIBuffer, YCBuffer>
{
    typedef YTBuffer<YIBuffer, YCBuffer>        super;
    YOBJECT_DECL(YCBuffer);

public:
    /*! \brief constructor */
    YCBuffer();
    /*! \brief destructor */
    virtual ~YCBuffer();

public:
    /*!
      \brief a template function to write some common type variables
      \param rData a variable, it will be write to buffer
      */
    template<typename TNType>
    YIBuffer& In(const TNType& rData)
    {
        /// write the memory of rData to buffer
        Write(sizeof(TNType), (ybuffptr)&rData);
        return *this;
    }

    /*!
      \brief a template function to read some common type variables
      \param rData a variable, it will be read from buffer
      */
    template<typename TNType>
    YIBuffer& Out(TNType& rData)
    {
        /// check the current position and the size of the buffer
        if (0 >= m_iSize || m_iSize <= m_iPosCurrent)
        {
            return *this;
        }
        /// read the memory of rData to buffer
        Read(sizeof(TNType), (ybuffptr)&rData);
        return *this;
    }

    /*! \brief a function to write a string */
    YIBuffer& In(const ystring& rData);
    /*! \brief a function to read a string */
    YIBuffer& Out(ystring& rData);

public:
    /*! \sa YIObject::operator>>(YCBuffer& rBuffer) const */
    virtual bool operator>>(YCBuffer& rBuffer) const;
    /*! \sa YIObject::operator<<(YCBuffer& rBuffer) */
    virtual bool operator<<(YCBuffer& rBuffer);

public:
    /*! \sa YIBuffer::GET_DECL_CONST(ybuffptr&, GetData) */
    virtual GET_DECL_CONST(ybuffptr&, GetData);

public:
    /*! \sa YIBuffer::New(const ybuffsize& riSize) */
    virtual void New(const ybuffsize& riSize);
    /*! \sa YIBuffer::Begin() */
    virtual YIBuffer& Begin();
    /*! \sa YIBuffer::End() YCBuffer::Merge() */
    virtual void End();
    /*! \sa YIBuffer::Write(const ybuffsize& riSize, const ybuffptr& rpSrc) */
    virtual bool Write(const ybuffsize& riSize, const ybuffptr& rpSrc);
    /*! \sa YIBuffer::Read(const ybuffsize& riSize, const ybuffptr& rpDst) */
    virtual bool Read(const ybuffsize& riSize, const ybuffptr& rpDst);
    /*! \sa YIBuffer::Clear() */
    virtual YIBuffer& Clear();

public:
    /*! \brief copy with another buffer */
    void operator=(const YCBuffer& rBuffer);

protected:
    /*! \brief merge the small buffer to one */
    void Merge();

private:
    /*! the list of buffer */
    yvbuffer        m_vBufferSeg;
    /*! the current position to read */
    ybuffpos        m_iPosCurrent;
};

}}

#endif // Y_BUFFER_H
