#ifndef Y_FILEFORMAT_H
#define Y_FILEFORMAT_H

#include "common.h"

namespace yam{ namespace base{

class IYWidget;
class IYFormat;

}}

namespace yam{ namespace file{

class IYFile
{
public:
	virtual ~IYFile() { ; }

public:
	virtual void Load(const ystring& rsFileName, base::IYWidget*& rpWidget) const = 0;
	virtual void Save(const ystring& rsFileName, const base::IYWidget* pWidget) const = 0;

protected:
	virtual void Read(yifstream& rStream, const ybuffsize& rSize, ybuffptr pBuffer) const = 0;
	virtual void Write(yofstream& rStream, const ybuffsize& rSize, const ybuffptr& rpBuffer) const = 0;

	virtual void Read(yifstream& rStream, ystring& rRes) const = 0;
	virtual void Write(yofstream& rStream, const ystring& rData) const = 0;

	virtual void Read(yifstream& rStream, ybool& rRes) const = 0;
	virtual void Write(yofstream& rStream, const ybool& rData) const = 0;

	virtual void Read(yifstream& rStream, yint32& rRes) const = 0;
	virtual void Write(yofstream& rStream, const yint32& rData) const = 0;

	virtual void Read(yifstream& rStream, yvec2d& rRes) const = 0;
	virtual void Write(yofstream& rStream, const yvec2d& rData) const = 0;

	virtual void Read(yifstream& rStream, yrect2d& rRes) const = 0;
	virtual void Write(yofstream& rStream, const yrect2d& rData) const = 0;

	virtual void Read(yifstream& rStream, base::IYWidget*& rRes) const = 0;
	virtual void Write(yofstream& rStream, const base::IYWidget*& rData) const = 0;

	virtual void Read(yifstream& rStream, base::IYFormat*& rRes) const = 0;
	virtual void Write(yofstream& rStream, const base::IYFormat*& rData) const = 0;
};

class CYFile : public IYFile
{
public:
	SINGLETON_DECL(CYFile);

protected:
	CYFile();
	virtual ~CYFile();

public:
	virtual void Load(const ystring& rsFileName, base::IYWidget*& rpWidget) const;
	virtual void Save(const ystring& rsFileName, const base::IYWidget* pWidget) const;

protected:
	virtual void Read(yifstream& rStream, const ybuffsize& rSize, ybuffptr pBuffer) const;
	virtual void Write(yofstream& rStream, const ybuffsize& rSize, const ybuffptr& rpBuffer) const;

	virtual void Read(yifstream& rStream, ystring& rRes) const;
	virtual void Write(yofstream& rStream, const ystring& rData) const;

	virtual void Read(yifstream& rStream, ybool& rRes) const;
	virtual void Write(yofstream& rStream, const ybool& rData) const;

	virtual void Read(yifstream& rStream, yint32& rRes) const;
	virtual void Write(yofstream& rStream, const yint32& rData) const;

	virtual void Read(yifstream& rStream, yvec2d& rRes) const;
	virtual void Write(yofstream& rStream, const yvec2d& rData) const;

	virtual void Read(yifstream& rStream, yrect2d& rRes) const;
	virtual void Write(yofstream& rStream, const yrect2d& rData) const;

	virtual void Read(yifstream& rStream, base::IYWidget*& rRes) const;
	virtual void Write(yofstream& rStream, const base::IYWidget*& rData) const;

	virtual void Read(yifstream& rStream, base::IYFormat*& rRes) const;
	virtual void Write(yofstream& rStream, const base::IYFormat*& rData) const;

private:
	base::IYWidget* NewWidget(const ystring& rsType) const;
};

}}

#endif // Y_FILEFORMAT_H
