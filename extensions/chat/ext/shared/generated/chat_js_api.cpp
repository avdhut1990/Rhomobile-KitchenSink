#include "api_generator/js_helpers.h"
#include "api_generator/Api.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "Chat"




rho::String js_Chat_getSimpleStringProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Chat_def_getSimpleStringProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_Chat_setSimpleStringProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Chat_def_setSimpleStringProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_s_Chat_enumerate(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_Chat_init(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Chat_def_init(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_Chat_getProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Chat_def_getProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_Chat_getProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Chat_def_getProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_Chat_getAllProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Chat_def_getAllProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_Chat_setProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Chat_def_setProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);

rho::String js_Chat_setProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Chat_def_setProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);



rho::String js_s_Chat_getDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Chat_getDefault(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);
rho::String js_s_Chat_setDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam);



namespace {
  using namespace rho::apiGenerator;
  class ChatDispatcher : public ApiHandler<Func_JS>
  {
  public:
    ChatDispatcher() : ApiHandler("Rho:Chat") {}
    virtual ~ChatDispatcher() {}
    virtual void initialize();
  };
  
  void ChatDispatcher::initialize()
  {
    ApiHandler<Func_JS>::initialize();
    
    RAWTRACE("Initializing Rho:Chat API...");


    defineInstanceMethod("simpleStringProperty", js_Chat_getSimpleStringProperty);
    //  should define static method !     defineStaticMethod("def_simpleStringProperty", js_s_Chat_def_getSimpleStringProperty);;


    defineInstanceMethod("simpleStringProperty=", js_Chat_setSimpleStringProperty);
    //  should define static method !     defineStaticMethod("def_simpleStringProperty=", js_s_Chat_def_setSimpleStringProperty);;


    defineStaticMethod("enumerate", js_s_Chat_enumerate);


    defineInstanceMethod("init", js_Chat_init);
    //  should define static method !     defineStaticMethod("def_init", js_s_Chat_def_init);;


    defineInstanceMethod("getProperty", js_Chat_getProperty);
    //  should define static method !     defineStaticMethod("def_getProperty", js_s_Chat_def_getProperty);;


    defineInstanceMethod("getProperties", js_Chat_getProperties);
    //  should define static method !     defineStaticMethod("def_getProperties", js_s_Chat_def_getProperties);;


    defineInstanceMethod("getAllProperties", js_Chat_getAllProperties);
    //  should define static method !     defineStaticMethod("def_getAllProperties", js_s_Chat_def_getAllProperties);;


    defineInstanceMethod("setProperty", js_Chat_setProperty);
    //  should define static method !     defineStaticMethod("def_setProperty", js_s_Chat_def_setProperty);;


    defineInstanceMethod("setProperties", js_Chat_setProperties);
    //  should define static method !     defineStaticMethod("def_setProperties", js_s_Chat_def_setProperties);;


    defineStaticMethod("getDefaultID", js_s_Chat_getDefaultID);
    defineStaticMethod("getDefault", js_s_Chat_getDefault);
    defineStaticMethod("setDefaultID", js_s_Chat_setDefaultID);

    RAWTRACE("Rho:Chat API - done");
  }
}

extern "C" void Init_JSAPI_Chat(void)
{
  rho::apiGenerator::defineJSApiModule(new ChatDispatcher);
}
