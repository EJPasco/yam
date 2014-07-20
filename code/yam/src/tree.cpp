#include "tree.h"

namespace yam{ namespace base{

YOBJECT_IMPL(YCTree);

YCTree::YCTree()
{
    //
}

YCTree::~YCTree()
{
    //
}

YCTreeNew::YCTreeNew()
{
    //
}

YCTreeNew::~YCTreeNew()
{
    //
}

bool YCTreeNew::operator>>(YCBuffer& rBuffer) const
{
    YCBuffer buf;
    buf.GetId() = GetId();
    buf.GetClassName() = GetClassName();
    buf >> rBuffer;

    return super::operator >>(rBuffer);
}

bool YCTreeNew::operator<<(YCBuffer& rBuffer)
{
    YCBuffer buf;
    buf << rBuffer;

    if (buf.GetClassName() != GetClassName())
    {
        assert(false);
        return false;
    }
    GetId() = buf.GetId();

    return super::operator <<(rBuffer);
}

}}
