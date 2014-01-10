#ifndef Y_YUIFILE_H
#define Y_YUIFILE_H

#include "common.h"

#include "tree.h"

#include <vector>

namespace yam{ namespace base{

class YIBuffer;
class YIWidget;
class YIFormat;

}}

namespace yam{ namespace file{

class YIUIFile
{
public:
	virtual ~YIUIFile() { ; }

public:
	virtual void Close() = 0;
};

template<typename TNBase>
class YTUIFile : public TNBase
{
public:
	YTUIFile() { ; }
	virtual ~YTUIFile() { ; }

public:

protected:
};

class YIUIFileWriter : public YIUIFile
{
public:
	virtual ~YIUIFileWriter() { ; }

public:
	virtual YIUIFileWriter& Save(const ystring& rsFileName) = 0;
	virtual YIUIFileWriter& operator<<(const base::YIBuffer* const& rvpBuffer) = 0;
};

template<typename TNBase>
class YTUIFileWriter : public YTUIFile<TNBase>
{
public:
	YTUIFileWriter() { ; }
	virtual ~YTUIFileWriter() { ; }

public:

protected:
};

class YCUIFileWriter : public YTUIFileWriter<YIUIFileWriter>
{
public:
	YCUIFileWriter();
	virtual ~YCUIFileWriter();

public:
	template<typename TNType>
	YIUIFileWriter& operator<<(const TNType& rData)
	{
		if (!mbOpened)
		{
			return *this;
		}
		Write(sizeof(TNType), (ybuffptr)&rData);
		return *this;
	}

	template<typename TNItem>
	YIUIFileWriter& operator<<(const base::YITree<TNItem>* const& rpData)
	{
		if (!mbOpened)
		{
			return *this;
		}
		// write the next
		const TNItem* pNext = rpData->GetNext();
		ybool bHasNext = YNULL != pNext;
		*this << bHasNext;
		if (bHasNext)
		{
			*this << pNext;
		}

		// write the children
		const TNItem* pChildren = rpData->GetChildren();
		ybool bHasChildren = YNULL != pChildren;
		*this << bHasChildren;
		if (bHasChildren)
		{
			*this << pChildren;
		}
		return *this;
	}

public:
	virtual void Close();
	virtual YIUIFileWriter& Save(const ystring& rsFileName);
	virtual YIUIFileWriter& operator<<(const base::YIBuffer* const& rvpBuffer);

protected:
	YIUIFileWriter& operator<<(const ystring& rData);
	void Write(const ybuffsize& riSize, const ybuffptr& rpBuff);

private:
	ybool				mbOpened;
	yofstream			mFileStream;
};

class YIUIFileReader : public YIUIFile
{
public:
	virtual ~YIUIFileReader() { ; }

public:
	virtual YIUIFileReader& Open(const ystring& rsFileName) = 0;
	virtual YIUIFileReader& operator>>(base::YIBuffer*& rvpBuffer) = 0;
};

template<typename TNBase>
class YTUIFileReader : public YTUIFile<TNBase>
{
public:
	YTUIFileReader() { ; }
	virtual ~YTUIFileReader() { ; }

public:
//
};

class YCUIFileReader : public YTUIFileReader<YIUIFileReader>
{
public:
	YCUIFileReader();
	virtual ~YCUIFileReader();

public:
	template<typename TNType>
	YIUIFileReader& operator>>(TNType& rData)
	{
		if (!mbOpened)
		{
			return *this;
		}
		ybuffptr pData = (ybuffptr)&rData;
		Read(sizeof(TNType), pData);
		return *this;
	}

	template<typename TNItem>
	YIUIFileReader& operator>>(base::YITree<TNItem>*& rpData)
	{
		assert(YNULL != rpData);
		if (!mbOpened)
		{
			return *this;
		}
		ybool bHasNext = false;
		*this >> bHasNext;
		if (bHasNext)
		{
			TNItem* pNext = YNULL;
			*this >> pNext;
			rpData->AddNext(pNext);
		}

		ybool bHasChildren = false;
		*this >> bHasChildren;
		if (bHasChildren)
		{
			TNItem* pChildren = YNULL;
			*this >> pChildren;
			rpData->AddChild(pChildren);
		}
		return *this;
	}

public:
	virtual void Close();
	virtual YIUIFileReader& Open(const ystring& rsFileName);
	virtual YIUIFileReader& operator>>(base::YIBuffer*& rvpBuffer);

protected:
	YIUIFileReader& operator>>(ystring& rData);
	void Read(const ybuffsize& riSize, const ybuffptr& rpBuff);

private:
	ybool				mbOpened;
	yifstream			mFileStream;
};


}}

#endif // Y_YUIFILE_H
