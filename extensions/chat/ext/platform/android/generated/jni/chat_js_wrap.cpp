#include "Chat.h"

#include "MethodResultJni.h"

#include "api_generator/MethodResult.h"
#include "api_generator/MethodResultConvertor.h"
#include "api_generator/JSONResultConvertor.h"

#include "rhodes/JNIRhoJS.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "ChatJS"

typedef rho::CChatProxy<ArgumentsAdapter<rho::json::CJSONArray> > ObjectProxy;

using namespace rho::apiGenerator;

rho::String js_s_Chat_getDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE(__FUNCTION__);
    
    rho::apiGenerator::CMethodResult result(false);
    result.set(ObjectProxy::getDefaultID());
    return CMethodResultConvertor().toJSON(result);
}

rho::String js_s_Chat_getDefault(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE(__FUNCTION__);
    
    rho::apiGenerator::CMethodResult result(false);
    result.setJSObjectClassPath("Rho.Chat");
    result.set(ObjectProxy::getDefaultID());
    return CMethodResultConvertor().toJSON(result);
}

rho::String js_s_Chat_setDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE(__FUNCTION__);

    rho::apiGenerator::CMethodResult result(false);
    ObjectProxy::setDefaultID(argv.getItem(0).getString());
    return CMethodResultConvertor().toJSON(result);
} 


rho::String js_Chat_getSimpleStringProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result(false);
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return CMethodResultConvertor().toJSON(result);
    }

    ObjectProxy chat(strObjID);

    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return CMethodResultConvertor().toJSON(result);
    }
    
    if(strCallbackID.length() != 0)
    {
        result.setCallBack(strCallbackID, strCallbackParam);
    }

    chat.getSimpleStringProperty(argumentsAdapter(argv), result); 
    rho::String res = CMethodResultConvertor().toJSON(result);
    RAWTRACE(res.c_str());
    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_Chat_setSimpleStringProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result(false);
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return CMethodResultConvertor().toJSON(result);
    }

    ObjectProxy chat(strObjID);

    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return CMethodResultConvertor().toJSON(result);
    }
    
    if(strCallbackID.length() != 0)
    {
        result.setCallBack(strCallbackID, strCallbackParam);
    }

    chat.setSimpleStringProperty(argumentsAdapter(argv), result); 
    rho::String res = CMethodResultConvertor().toJSON(result);
    RAWTRACE(res.c_str());
    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_Chat_enumerate(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result(false);
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return CMethodResultConvertor().toJSON(result);
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return CMethodResultConvertor().toJSON(result);
    }
    
    if(strCallbackID.length() != 0)
    {
        result.setCallBack(strCallbackID, strCallbackParam);
    }

    result.setObjectClassPath("Rho.Chat");
    RAWTRACE("Object class path is set");
    ObjectProxy::enumerate(argumentsAdapter(argv), result); 
    rho::String res = CMethodResultConvertor().toJSON(result);
    RAWTRACE(res.c_str());
    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_Chat_init(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result(false);
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return CMethodResultConvertor().toJSON(result);
    }

    ObjectProxy chat(strObjID);

    int argc = argv.getSize();
    if((argc < 5) || (argc > 5))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return CMethodResultConvertor().toJSON(result);
    }
    
    if(strCallbackID.length() != 0)
    {
        result.setCallBack(strCallbackID, strCallbackParam);
    }

    chat.init(argumentsAdapter(argv), result); 
    rho::String res = CMethodResultConvertor().toJSON(result);
    RAWTRACE(res.c_str());
    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_Chat_getProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result(false);
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return CMethodResultConvertor().toJSON(result);
    }

    ObjectProxy chat(strObjID);

    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return CMethodResultConvertor().toJSON(result);
    }
    
    if(strCallbackID.length() != 0)
    {
        result.setCallBack(strCallbackID, strCallbackParam);
    }

    chat.getProperty(argumentsAdapter(argv), result); 
    rho::String res = CMethodResultConvertor().toJSON(result);
    RAWTRACE(res.c_str());
    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_Chat_getProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result(false);
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return CMethodResultConvertor().toJSON(result);
    }

    ObjectProxy chat(strObjID);

    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return CMethodResultConvertor().toJSON(result);
    }
    
    if(strCallbackID.length() != 0)
    {
        result.setCallBack(strCallbackID, strCallbackParam);
    }

    chat.getProperties(argumentsAdapter(argv), result); 
    rho::String res = CMethodResultConvertor().toJSON(result);
    RAWTRACE(res.c_str());
    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_Chat_getAllProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result(false);
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return CMethodResultConvertor().toJSON(result);
    }

    ObjectProxy chat(strObjID);

    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return CMethodResultConvertor().toJSON(result);
    }
    
    if(strCallbackID.length() != 0)
    {
        result.setCallBack(strCallbackID, strCallbackParam);
    }

    chat.getAllProperties(argumentsAdapter(argv), result); 
    rho::String res = CMethodResultConvertor().toJSON(result);
    RAWTRACE(res.c_str());
    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_Chat_setProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result(false);
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return CMethodResultConvertor().toJSON(result);
    }

    ObjectProxy chat(strObjID);

    int argc = argv.getSize();
    if((argc < 2) || (argc > 2))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return CMethodResultConvertor().toJSON(result);
    }
    
    if(strCallbackID.length() != 0)
    {
        result.setCallBack(strCallbackID, strCallbackParam);
    }

    chat.setProperty(argumentsAdapter(argv), result); 
    rho::String res = CMethodResultConvertor().toJSON(result);
    RAWTRACE(res.c_str());
    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_Chat_setProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result(false);
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return CMethodResultConvertor().toJSON(result);
    }

    ObjectProxy chat(strObjID);

    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return CMethodResultConvertor().toJSON(result);
    }
    
    if(strCallbackID.length() != 0)
    {
        result.setCallBack(strCallbackID, strCallbackParam);
    }

    chat.setProperties(argumentsAdapter(argv), result); 
    rho::String res = CMethodResultConvertor().toJSON(result);
    RAWTRACE(res.c_str());
    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
