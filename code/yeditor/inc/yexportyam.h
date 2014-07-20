#ifndef Y_EXPORTYAM_H
#define Y_EXPORTYAM_H

#include "yexport.h"

namespace json{
    class Object;
}

namespace yam{ namespace io{

class YCExportYam : public YTExport<YIExport>
{
public:
    YCExportYam();
    virtual ~YCExportYam();

public:
    virtual void Save(const yam::base::YCTree* pTree) const;

private:
    void ToJson(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonWidgetCommon(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonWidgetChildren(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonScene(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonPanel(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonTile(const yam::base::YCProperty* pProperty, json::Object& rjObj) const;
    void ToJsonTiles(const yam::base::YCProperty* pProperty, json::Object& rjObj) const;
    void ToJsonImage(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonButton(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonText(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonLayout(const yam::base::YCProperty* pProperty, json::Object& rjObj) const;

public:
    static void GetStringByIdFromProperty(const yam::base::YITree* const& rpTree, const yam::ystring& rsId, yam::ystring& rsValue);
    static yam::ystring GetNameByWidgetType(const yam::EWidgetType& reType);
    static yam::ystring GetNameByAlignType(const yam::EAlignType& reType);
    static void ToJsonVec2D(const yam::YVec2D& rstVec2D, json::Object& rjObj);
    static void ToJsonRect2D(const yam::YRect2D& rstRect2D, json::Object& rjObj);
};

}}

#endif // Y_EXPORTYAM_H
