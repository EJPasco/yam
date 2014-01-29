#ifndef Y_PSPARSER_H
#define Y_PSPARSER_H

#include "pstoyamcommon.h"

#include "psformat.h"

namespace yam{ namespace external{

class YIPsFormatReader : public YIPsFormat
{
public:
    virtual ~YIPsFormatReader() { ; }

public:
};

template<typename TNBase>
class YTPsFormatReader : public YTPsFormat<TNBase>
{
public:
    YTPsFormatReader() { ; }
    virtual ~YTPsFormatReader() { ; }

public:
};

class YCPsFormatReader : public YTPsFormatReader<YIPsFormatReader>
{
public:
    YCPsFormatReader();
    virtual ~YCPsFormatReader();

public:
    virtual void Do(FormatRecordPtr& rpRecord);

protected:
    void Do(ReadImageDocumentDesc*& rpDocu, yam::base::YCTree& rTree);
    void Do(ReadLayerDesc*& rpLayer, yam::base::YCTree& rTree);
};

}}

#endif // Y_PSPARSER_H
