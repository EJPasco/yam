#ifndef Y_CONVERTER_H
#define Y_CONVERTER_H

#include <yam.h>

#include <QtCore/QSize>
#include <QtCore/QPoint>
#include <QtCore/QRect>

class YCConverter
{
	SINGLETON_DECL(YCConverter);

protected:
	YCConverter();
	virtual ~YCConverter();

public:
	yam::YVec2D Convert(const QSize& rSize) const;
	QSize Convert(const yam::YVec2D& rSize) const;
	yam::YRect2D Convert(const QRect& rRect) const;
	QRect Convert(const yam::YRect2D& rRect) const;
	yam::YRect2D Merge(const yam::YRect2D& rstRect2Da, const yam::YRect2D& rstRect2Db) const;
	yam::YRect2D Merge(const yam::yvrect& rvRect2D) const;
};

#endif // Y_CONVERTER_H
