#ifndef Y_BUFFER_H
#define Y_BUFFER_H

#include "common.h"

#include "object.h"

namespace yam{ namespace base{

class YIBuffer : public YIObject
{
public:
    virtual ~YIBuffer() { ; }

public:
    virtual GET_DECL_CONST(ybuffsize&, GetSize) = 0;
    virtual GET_DECL_CONST(ybuffptr&, GetData) = 0;

public:
    virtual void New(const ybuffsize& riSize) = 0;
    virtual YIBuffer& Begin() = 0;
    virtual void End() = 0;
    virtual bool Write(const ybuffsize& riSize, const ybuffptr& rpSrc) = 0;
    virtual bool Read(const ybuffsize& riSize, const ybuffptr& rpDst) = 0;
    virtual YIBuffer& Clear() = 0;
};

template<typename TNBase, typename TNReal>
class YTBuffer : public YTObject<TNBase, TNReal>
{
public:
    YTBuffer() : m_iSize(0), m_pData(YNULL) { ; }
    virtual ~YTBuffer() { ; }

public:
    virtual GET_FUNC_CONST(ybuffsize&, GetSize, m_iSize);

public:

protected:
    ybuffsize        m_iSize;
    ybuffptr        m_pData;
};

class YCBuffer : public YTBuffer<YIBuffer, YCBuffer>
{
    typedef YTBuffer<YIBuffer, YCBuffer>        super;
    YOBJECT_DECL(YCBuffer);

public:
    YCBuffer();
    virtual ~YCBuffer();

public:
    template<typename TNType>
    YIBuffer& In(const TNType& rData)
    {
        Write(sizeof(TNType), (ybuffptr)&rData);
        return *this;
    }

    template<typename TNType>
    YIBuffer& Out(TNType& rData)
    {
        if (0 >= m_iSize || m_iSize <= m_iPosCurrent)
        {
            return *this;
        }
        Read(sizeof(TNType), (ybuffptr)&rData);
        return *this;
    }

    YIBuffer& In(const ystring& rData);
    YIBuffer& Out(ystring& rData);

public:
    virtual bool operator>>(YCBuffer& rBuffer) const;
    virtual bool operator<<(YCBuffer& rBuffer);

public:
    virtual GET_DECL_CONST(ybuffptr&, GetData);

public:
    virtual void New(const ybuffsize& riSize);
    virtual YIBuffer& Begin();
    virtual void End();
    virtual bool Write(const ybuffsize& riSize, const ybuffptr& rpSrc);
    virtual bool Read(const ybuffsize& riSize, const ybuffptr& rpDst);
    virtual YIBuffer& Clear();

public:
    void operator=(const YCBuffer& rBuffer);

protected:
    void Merge();

private:
    yvbuffer        m_vBufferSeg;
    ybuffpos        m_iPosCurrent;
};

}}

#endif // Y_BUFFER_H
