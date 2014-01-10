#ifndef Y_FILEFORMAT_H
#define Y_FILEFORMAT_H

#include "common.h"

#include <map>

namespace yam{ namespace base{

class YIBuffer;
class YIWidget;
class YIFormat;

}}

namespace yam{ namespace file{

class YIFile
{
public:
	virtual ~YIFile() { ; }

public:
	virtual void Load(const ystring& rsFileName, base::YIFormat*& rpFormat) const = 0;
	virtual void Save(const ystring& rsFileName, const base::YIFormat* pFormat) const = 0;

	virtual void Load(const ystring& rsFileName, base::YIWidget*& rpWidget) const = 0;
	virtual void Save(const ystring& rsFileName, const base::YIWidget* pWidget) const = 0;

public:
	virtual void Read(yistream& rStream, const ybuffsize& rSize, ybuffptr pBuffer) const = 0;
	virtual void Write(yostream& rStream, const ybuffsize& rSize, const ybuffptr& rpBuffer) const = 0;

	virtual void Read(yistream& rStream, ystreambuff& rData) const = 0;
	virtual void Write(yostream& rStream, const ystreambuff& rData) const = 0;

	virtual void Read(yistream& rStream, yistream& rData) const = 0;
	virtual void Write(yostream& rStream, const yostream& rData) const = 0;

	virtual void Read(yistream& rStream, ystring& rRes) const = 0;
	virtual void Write(yostream& rStream, const ystring& rData) const = 0;

	virtual void Read(yistream& rStream, ybool& rRes) const = 0;
	virtual void Write(yostream& rStream, const ybool& rData) const = 0;

	virtual void Read(yistream& rStream, yint32& rRes) const = 0;
	virtual void Write(yostream& rStream, const yint32& rData) const = 0;

	virtual void Read(yistream& rStream, YVec2D& rRes) const = 0;
	virtual void Write(yostream& rStream, const YVec2D& rData) const = 0;

	virtual void Read(yistream& rStream, YRect2D& rRes) const = 0;
	virtual void Write(yostream& rStream, const YRect2D& rData) const = 0;

	virtual void Read(yistream& rStream, base::YIBuffer*& rpData) const = 0;
	virtual void Write(yostream& rStream, const base::YIBuffer*& rpData) const = 0;

	virtual void Read(yistream& rStream, base::YIWidget*& rpData) const = 0;
	virtual void Write(yostream& rStream, const base::YIWidget*& rpData) const = 0;

	virtual void Read(yistream& rStream, base::YIFormat*& rpData) const = 0;
	virtual void Write(yostream& rStream, const base::YIFormat*& rpData) const = 0;
};

class YCFile : public YIFile
{
	typedef std::map<ystring, base::YIBuffer*>		tmbuffer;

public:
	SINGLETON_DECL(YCFile);

protected:
	YCFile();
	virtual ~YCFile();

public:
	virtual void Load(const ystring& rsFileName, base::YIFormat*& rpFormat) const;
	virtual void Save(const ystring& rsFileName, const base::YIFormat* pFormat) const;

	virtual void Load(const ystring& rsFileName, base::YIWidget*& rpWidget) const;
	virtual void Save(const ystring& rsFileName, const base::YIWidget* pWidget) const;

public:
	virtual void Read(yistream& rStream, const ybuffsize& rSize, ybuffptr pBuffer) const;
	virtual void Write(yostream& rStream, const ybuffsize& rSize, const ybuffptr& rpBuffer) const;

	virtual void Read(yistream& rStream, ystreambuff& rData) const;
	virtual void Write(yostream& rStream, const ystreambuff& rData) const;

	virtual void Read(yistream& rStream, yistream& rData) const;
	virtual void Write(yostream& rStream, const yostream& rData) const;

	virtual void Read(yistream& rStream, ystring& rRes) const;
	virtual void Write(yostream& rStream, const ystring& rData) const;

	virtual void Read(yistream& rStream, ybool& rRes) const;
	virtual void Write(yostream& rStream, const ybool& rData) const;

	virtual void Read(yistream& rStream, yint32& rRes) const;
	virtual void Write(yostream& rStream, const yint32& rData) const;

	virtual void Read(yistream& rStream, YVec2D& rRes) const;
	virtual void Write(yostream& rStream, const YVec2D& rData) const;

	virtual void Read(yistream& rStream, YRect2D& rRes) const;
	virtual void Write(yostream& rStream, const YRect2D& rData) const;

	virtual void Read(yistream& rStream, base::YIBuffer*& rpData) const;
	virtual void Write(yostream& rStream, const base::YIBuffer*& rpData) const;

	virtual void Read(yistream& rStream, base::YIFormat*& rpData) const;
	virtual void Write(yostream& rStream, const base::YIFormat*& rpData) const;

	virtual void Read(yistream& rStream, base::YIWidget*& rpData) const;
	virtual void Write(yostream& rStream, const base::YIWidget*& rpData) const;

	template<typename TNKey, typename TNValue>
	void ReadMapPtr(yistream& rStream, std::map<TNKey, TNValue*>& rData) const
	{
		if (!rStream.good())
		{
			return;
		}

		rStream.seekg(0, std::ios::end);
		yistream::pos_type real_size = rStream.tellg();
		rStream.seekg(0, std::ios::beg);

		while (!rStream.eof())
		{
			TNKey key;
			Read(rStream, key);
			TNValue* val = YNULL;
			Read(rStream, val);
			rData.insert(std::make_pair(key, val));

			if (real_size == rStream.tellg())
			{
				break;
			}
		}
	}

	template<typename TNKey, typename TNValue>
	void WriteMapPtr(yistream& rStream, const std::map<TNKey, TNValue*>& rData) const
	{
		std::map<TNKey, TNValue*>::const_iterator citData = rData.begin();
		std::map<TNKey, TNValue*>::const_iterator citDataEnd = rData.end();
		for (; citData != citDataEnd; ++citData)
		{
			Write(rStream, citData->first);
			Write(rStream, citData->second);
		}
	}

	template<typename TNKey, typename TNValue>
	void DeleteMapPtr(std::map<TNKey, TNValue*>& rData) const
	{
		std::map<TNKey, TNValue*>::iterator itData = rData.begin();
		std::map<TNKey, TNValue*>::iterator itDataEnd = rData.end();
		for (; itData != itDataEnd; ++itData)
		{
			if (YNULL == itData->second)
			{
				continue;
			}
			Delete(itData->second);
		}
		rData.clear();
	}

	template<typename TNItem>
	void ReadTree(yistream& rStream, TNItem*& rpData) const
	{
		ybool bHasNext = false;
		Read(rStream, bHasNext);
		if (bHasNext)
		{
			TNItem* pNext = YNULL;
			Read(rStream, pNext);
			rpData->AddNext(pNext);
		}

		ybool bHasChildren = false;
		Read(rStream, bHasChildren);
		if (bHasChildren)
		{
			TNItem* pChildren = YNULL;
			Read(rStream, pChildren);
			rpData->AddChild(pChildren);
		}
	}

	template<typename TNItem>
	void WriteTree(yostream& rStream, const TNItem*& rpData) const
	{
		// write the next
		const TNItem* pNext = rpData->GetNext();
		ybool bHasNext = YNULL != pNext;
		Write(rStream, bHasNext);
		if (bHasNext)
		{
			Write(rStream, pNext);
		}

		// write the children
		const TNItem* pChildren = rpData->GetChildren();
		ybool bHasChildren = YNULL != pChildren;
		Write(rStream, bHasChildren);
		if (bHasChildren)
		{
			Write(rStream, pChildren);
		}
	}

private:
	void New(base::YIBuffer*& rpNew) const;
	void Delete(base::YIBuffer*& rpNew) const;
	void New(base::YIFormat*& rpNew) const;
	void New(base::YIWidget*& rpNew, const ystring& rsClass) const;
};

}}

#endif // Y_FILEFORMAT_H
