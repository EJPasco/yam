#include "file.h"

#include "buffer.h"

namespace yam{ namespace storage{

YCFileWriter::YCFileWriter()
	: mbOpened(false)
{
	//
}

YCFileWriter::~YCFileWriter()
{
	Close();
}

void YCFileWriter::Close()
{
	if (!mbOpened)
	{
		return;
	}
	mFileStream.close();
	mbOpened = false;
}

YIFileWriter& YCFileWriter::Save(const ystring& rsFileName)
{
	Close();

	mFileStream.open(rsFileName, std::ios::out | std::ios::binary);
	mbOpened = true;
	return *this;
}

ybool YCFileWriter::operator<<(const base::YCBuffer& rBuffer)
{
	if (!mbOpened)
	{
		return YFALSE;
	}
	//*this << rBuffer.GetSize();
	Write(rBuffer.GetSize(), rBuffer.GetData());
	return YTRUE;
}

void YCFileWriter::Write(const ybuffsize& riSize, const ybuffptr& rpBuff)
{
	if (!mbOpened || 0 >= riSize || YNULL == rpBuff)
	{
		return;
	}
	mFileStream.write(rpBuff, riSize);
}

YCFileReader::YCFileReader()
	: mbOpened(false)
{
	//
}

YCFileReader::~YCFileReader()
{
	Close();
}

void YCFileReader::Close()
{
	if (!mbOpened)
	{
		return;
	}
	mFileStream.close();
	mbOpened = false;
}

YIFileReader& YCFileReader::Open(const ystring& rsFileName)
{
	Close();

	mFileStream.open(rsFileName, std::ios::in | std::ios::binary);
	mbOpened = true;
	return *this;
}

ybool YCFileReader::operator>>(base::YCBuffer& rBuffer)
{
	if (!mbOpened)
	{
		return YFALSE;
	}

	ybuffsize iSize = 0;
	//*this >> iSize;
	mFileStream.seekg(0, std::ios::end);
	iSize = static_cast<ybuffsize>(mFileStream.tellg());
	mFileStream.seekg(0, std::ios::beg);
	rBuffer.New(iSize);
	Read(rBuffer.GetSize(), rBuffer.GetData());
	return YTRUE;
}

void YCFileReader::Read(const ybuffsize& riSize, const ybuffptr& rpBuff)
{
	if (!mbOpened || 0 >= riSize || YNULL == rpBuff)
	{
		return;
	}
	mFileStream.read(rpBuff, riSize);
}

}}
