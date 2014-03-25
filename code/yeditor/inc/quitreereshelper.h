#ifndef Y_QUITREERESHELPER_H
#define Y_QUITREERESHELPER_H

#include "yeditorcommon.h"
#include "quitreehelper.h"

class YCQUiTreeItemBoundHelper;

class YCQUiTreeResHelper : public YCQUiTreeHelper
{
    typedef YCQUiTreeHelper        super;

    Q_OBJECT

public:
    explicit YCQUiTreeResHelper(QTreeWidget* pTreeRoot);
    virtual ~YCQUiTreeResHelper();

public:
    virtual void setUiItem(YCQUiItem*& rpUiItem);

private:
    YCQUiTreeItemBoundHelper* m_pTreeItemBoundHelper;
};

#endif // Y_QUITREERESHELPER_H
