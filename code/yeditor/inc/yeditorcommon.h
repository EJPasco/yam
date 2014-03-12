#ifndef Y_EDITORCOMMON_H
#define Y_EDITORCOMMON_H

#include <json.h>
#include <yam.h>

#define YEDITOR_NAME                    "Yam Editor"


#define YEDITOR_DELETE(_Object_Ptr)     if (NULL != _Object_Ptr)\
    {\
        delete _Object_Ptr;\
        _Object_Ptr = NULL;\
    }

extern yam::base::YCTree                    gs_FileTreeData;

class YCQUiItem;
class YCQUiTreeItem;

enum ERelationshipType
{
    eRelationshipType_None,
    eRelationshipType_Res,
    eRelationshipType_Ui,
};

typedef struct tagRelationship
{
    ERelationshipType   _eType;
    YCQUiItem*          _pUiItem;
    YCQUiTreeItem*      _pTreeItem;
} SRelationship;

typedef std::map<yam::ystring, SRelationship>    ymnamerelationship;

extern ymnamerelationship                   gs_mRelationship;

#endif // Y_EDITORCOMMON_H
