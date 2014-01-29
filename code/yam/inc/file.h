#ifndef Y_FILE_H
#define Y_FILE_H

#include "common.h"

#include "tree.h"

#include <vector>

namespace yam{ namespace base{

class YIWidget;
class YIFormat;
class YCBuffer;

}}

namespace yam{ namespace storage{

class YIFile
{
public:
    virtual ~YIFile() { ; }

public:
    virtual void Close() = 0;
};

template<typename TNBase>
class YTFile : public TNBase
{
public:
    YTFile() { ; }
    virtual ~YTFile() { ; }

public:

protected:
};

class YIFileWriter : public YIFile
{
public:
    virtual ~YIFileWriter() { ; }

public:
    virtual YIFileWriter& Save(const ystring& rsFileName) = 0;
    virtual ybool operator<<(const base::YCBuffer& rBuffer) = 0;
};

template<typename TNBase>
class YTFileWriter : public YTFile<TNBase>
{
public:
    YTFileWriter() { ; }
    virtual ~YTFileWriter() { ; }

public:

protected:
};

class YCFileWriter : public YTFileWriter<YIFileWriter>
{
public:
    YCFileWriter();
    virtual ~YCFileWriter();

public:
    template<typename TNType>
    YIFileWriter& operator<<(const TNType& rData)
    {
        if (!mbOpened)
        {
            return *this;
        }
        Write(sizeof(TNType), (ybuffptr)&rData);
        return *this;
    }

public:
    virtual void Close();
    virtual YIFileWriter& Save(const ystring& rsFileName);
    virtual ybool operator<<(const base::YCBuffer& rBuffer);

protected:
    void Write(const ybuffsize& riSize, const ybuffptr& rpBuff);

private:
    ybool                mbOpened;
    yofstream            mFileStream;
};

class YIFileReader : public YIFile
{
public:
    virtual ~YIFileReader() { ; }

public:
    virtual YIFileReader& Open(const ystring& rsFileName) = 0;
    virtual ybool operator>>(base::YCBuffer& rBuffer) = 0;
};

template<typename TNBase>
class YTFileReader : public YTFile<TNBase>
{
public:
    YTFileReader() { ; }
    virtual ~YTFileReader() { ; }

public:
//
};

class YCFileReader : public YTFileReader<YIFileReader>
{
public:
    YCFileReader();
    virtual ~YCFileReader();

public:
    template<typename TNType>
    YIFileReader& operator>>(TNType& rData)
    {
        if (!mbOpened)
        {
            return *this;
        }
        ybuffptr pData = (ybuffptr)&rData;
        Read(sizeof(TNType), pData);
        return *this;
    }

public:
    virtual void Close();
    virtual YIFileReader& Open(const ystring& rsFileName);
    virtual ybool operator>>(base::YCBuffer& rBuffer);

protected:
    void Read(const ybuffsize& riSize, const ybuffptr& rpBuff);

private:
    ybool                mbOpened;
    yifstream            mFileStream;
};


}}

#endif // Y_FILE_H
