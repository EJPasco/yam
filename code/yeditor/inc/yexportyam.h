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
    virtual void Save(const yam::base::YITree* pTree) const;

private:
    void ToJson(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonWidgetCommon(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonWidgetGroup(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonScene(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonPanel(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonImage(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;
    void ToJsonButton(const yam::base::YIWidget* pWidget, json::Object& rjObj) const;

public:
    static yam::ystring GetNameByWidgetType(const yam::EWidgetType& reType);
};

}}

#endif // Y_EXPORTYAM_H
