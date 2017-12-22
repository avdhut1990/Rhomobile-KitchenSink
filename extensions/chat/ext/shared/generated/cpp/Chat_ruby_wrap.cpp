
#include "ChatBase.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "Chat"

#include "api_generator/RubyResultConvertor.h"

#include "ruby/ext/rho/rhoruby.h"
#include "common/StringConverter.h"
#include "common/AutoPointer.h"

using namespace rho;
using namespace rho::common;
using namespace rho::apiGenerator;

extern "C"
{
void rho_os_impl_performOnUiThread(rho::common::IRhoRunnable* pTask);
VALUE getRuby_Chat_Module();


VALUE rb_Chat_s_default(VALUE klass)
{
    rho::String strDefaultID = rho::CChatFactoryBase::getChatSingletonS()->getDefaultID();

    return rho_ruby_create_object_with_id( klass, strDefaultID.c_str() );
}

VALUE rb_Chat_s_setDefault(VALUE klass, VALUE valObj)
{
    const char* szID = rho_ruby_get_object_id( valObj );
    rho::CChatFactoryBase::getChatSingletonS()->setDefaultID(szID);

    return rho_ruby_get_NIL();
}


static void string_iter(const char* szVal, int valueLen, void* par)
{
    rho::Vector<rho::String>& ar = *((rho::Vector<rho::String>*)(par));
    ar.addElement( rho::String(szVal,valueLen) );
}

static void getStringArrayFromValue(VALUE val, rho::Vector<rho::String>& res)
{
    rho_ruby_enum_strary_json(val, string_iter, &res);
}

static void hash_eachstr(const char* szName, const char* szVal, int valueLen, void* par)
{
    rho::Hashtable<rho::String, rho::String>& hash = *((rho::Hashtable<rho::String, rho::String>*)(par));
    hash.put( szName, rho::String(szVal,valueLen) );
}

static void getStringHashFromValue(VALUE val, rho::Hashtable<rho::String, rho::String>& res)
{
    rho_ruby_enum_strhash_json(val, hash_eachstr, &res);
}
    
static rho::String getStringObjectFromValue(VALUE val)
{
    return rho::String(getStringFromValue(val),getStringLenFromValue(val));
}


static VALUE _api_generator_Chat_getSimpleStringProperty(int argc, VALUE *argv, rho::IChat* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    oRes.setRequestedType(CMethodResult::eString);
    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::IChat::getSimpleStringProperty,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->getSimpleStringProperty(  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Chat_getSimpleStringProperty(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::IChat* pObj =  rho::CChatFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Chat_getSimpleStringProperty(argc, argv, pObj);

    return res;
}



VALUE rb_s_Chat_def_getSimpleStringProperty(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CChatFactoryBase::getChatSingletonS()->getDefaultID();
    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Chat_getSimpleStringProperty(argc, argv, pObj);
}


static VALUE _api_generator_Chat_setSimpleStringProperty(int argc, VALUE *argv, rho::IChat* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    rho::String arg0 = "";
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringObjectFromValue(argv[0]);
        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::IChat::setSimpleStringProperty, arg0,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->setSimpleStringProperty( arg0,  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Chat_setSimpleStringProperty(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::IChat* pObj =  rho::CChatFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Chat_setSimpleStringProperty(argc, argv, pObj);

    return res;
}



VALUE rb_s_Chat_def_setSimpleStringProperty(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CChatFactoryBase::getChatSingletonS()->getDefaultID();
    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Chat_setSimpleStringProperty(argc, argv, pObj);
}


VALUE rb_s_Chat_enumerate(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    oRes.setParamName( "result" );
    oRes.setRubyObjectClass( getRuby_Chat_Module() );
    oRes.setRequestedType(CMethodResult::eStringArray);
    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        if ( rho_ruby_is_proc(argv[nCallbackArg]) || rho_ruby_is_method(argv[nCallbackArg]) )
        {
            oRes.setRubyCallbackProc( argv[nCallbackArg] );
        }else if ( rho_ruby_is_string(argv[nCallbackArg]) )
        {
            oRes.setRubyCallback( getStringObjectFromValue(argv[nCallbackArg]) );
        }else
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toRuby();
        }

        oRes.setCallInUIThread(false);
        if ( argc > nCallbackArg + 1 )
        {
            if ( !rho_ruby_is_NIL(argv[nCallbackArg + 1]) )
            {
                if ( !rho_ruby_is_string(argv[nCallbackArg + 1]) )
                {
                    oRes.setArgError("Type error: callback parameter should be String");
                    return oRes.toRuby();
                }

                oRes.setCallbackParam( getStringObjectFromValue(argv[nCallbackArg + 1]) );
            }
        }
        
        bUseCallback = true;
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor1( rho::CChatFactoryBase::getChatSingletonS(), &rho::IChatSingleton::enumerate,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        rho::CChatFactoryBase::getChatSingletonS()->enumerate(  oRes );
    }
    
    return oRes.toRuby();
}






static VALUE _api_generator_Chat_init(int argc, VALUE *argv, rho::IChat* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    oRes.setRequestedType(CMethodResult::eString);
    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toRuby();
    }
    rho::String arg0 = "";
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringObjectFromValue(argv[0]);
        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 2;
    if ( argc == 1 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toRuby();
    }
    rho::String arg1 = "";
    if ( argc > 1 )
    {
        if ( rho_ruby_is_string(argv[1]) )
        {
            arg1 = getStringObjectFromValue(argv[1]);
        }
        else if (!rho_ruby_is_NIL(argv[1]))
        {
            oRes.setArgError("Type error: argument " "1" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 3;
    if ( argc == 2 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toRuby();
    }
    rho::String arg2 = "";
    if ( argc > 2 )
    {
        if ( rho_ruby_is_string(argv[2]) )
        {
            arg2 = getStringObjectFromValue(argv[2]);
        }
        else if (!rho_ruby_is_NIL(argv[2]))
        {
            oRes.setArgError("Type error: argument " "2" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 4;
    if ( argc == 3 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toRuby();
    }
    rho::String arg3 = "";
    if ( argc > 3 )
    {
        if ( rho_ruby_is_string(argv[3]) )
        {
            arg3 = getStringObjectFromValue(argv[3]);
        }
        else if (!rho_ruby_is_NIL(argv[3]))
        {
            oRes.setArgError("Type error: argument " "3" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 5;
    if ( argc == 4 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toRuby();
    }
    rho::String arg4 = "";
    if ( argc > 4 )
    {
        if ( rho_ruby_is_string(argv[4]) )
        {
            arg4 = getStringObjectFromValue(argv[4]);
        }
        else if (!rho_ruby_is_NIL(argv[4]))
        {
            oRes.setArgError("Type error: argument " "4" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 6;
    if ( argc == 5 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toRuby();
    }
    rho::String arg5 = "";
    if ( argc > 5 )
    {
        if ( rho_ruby_is_string(argv[5]) )
        {
            arg5 = getStringObjectFromValue(argv[5]);
        }
        else if (!rho_ruby_is_NIL(argv[5]))
        {
            oRes.setArgError("Type error: argument " "5" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 7;
    if ( argc == 6 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toRuby();
    }
    rho::String arg6 = "";
    if ( argc > 6 )
    {
        if ( rho_ruby_is_string(argv[6]) )
        {
            arg6 = getStringObjectFromValue(argv[6]);
        }
        else if (!rho_ruby_is_NIL(argv[6]))
        {
            oRes.setArgError("Type error: argument " "6" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toRuby();
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor8( pObj, &rho::IChat::init, arg0, arg1, arg2, arg3, arg4, arg5, arg6,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->init( arg0, arg1, arg2, arg3, arg4, arg5, arg6,  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Chat_init(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::IChat* pObj =  rho::CChatFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Chat_init(argc, argv, pObj);

    return res;
}



VALUE rb_s_Chat_def_init(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CChatFactoryBase::getChatSingletonS()->getDefaultID();
    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Chat_init(argc, argv, pObj);
}


static VALUE _api_generator_Chat_sendMessage(int argc, VALUE *argv, rho::IChat* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    oRes.setRequestedType(CMethodResult::eString);
    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    rho::String arg0 = "";
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringObjectFromValue(argv[0]);
        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::IChat::sendMessage, arg0,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->sendMessage( arg0,  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Chat_sendMessage(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::IChat* pObj =  rho::CChatFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Chat_sendMessage(argc, argv, pObj);

    return res;
}



VALUE rb_s_Chat_def_sendMessage(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CChatFactoryBase::getChatSingletonS()->getDefaultID();
    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Chat_sendMessage(argc, argv, pObj);
}


static VALUE _api_generator_Chat_getProperty(int argc, VALUE *argv, rho::IChat* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    oRes.setRequestedType(CMethodResult::eString);
    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    rho::String arg0 = "";
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringObjectFromValue(argv[0]);
        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        if ( rho_ruby_is_proc(argv[nCallbackArg]) || rho_ruby_is_method(argv[nCallbackArg]) )
        {
            oRes.setRubyCallbackProc( argv[nCallbackArg] );
        }else if ( rho_ruby_is_string(argv[nCallbackArg]) )
        {
            oRes.setRubyCallback( getStringObjectFromValue(argv[nCallbackArg]) );
        }else
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toRuby();
        }

        oRes.setCallInUIThread(false);
        if ( argc > nCallbackArg + 1 )
        {
            if ( !rho_ruby_is_NIL(argv[nCallbackArg + 1]) )
            {
                if ( !rho_ruby_is_string(argv[nCallbackArg + 1]) )
                {
                    oRes.setArgError("Type error: callback parameter should be String");
                    return oRes.toRuby();
                }

                oRes.setCallbackParam( getStringObjectFromValue(argv[nCallbackArg + 1]) );
            }
        }
        
        bUseCallback = true;
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::IChat::getProperty, arg0,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->getProperty( arg0,  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Chat_getProperty(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::IChat* pObj =  rho::CChatFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Chat_getProperty(argc, argv, pObj);

    return res;
}



VALUE rb_s_Chat_def_getProperty(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CChatFactoryBase::getChatSingletonS()->getDefaultID();
    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Chat_getProperty(argc, argv, pObj);
}


static VALUE _api_generator_Chat_getProperties(int argc, VALUE *argv, rho::IChat* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    oRes.setRequestedType(CMethodResult::eStringHash);
    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    rho::Vector<rho::String> arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_array(argv[0]) )
        {
            rho::String res;
            rho_value_to_typed_array<rho::String>(argv[0], arg0, res);
        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "array" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        if ( rho_ruby_is_proc(argv[nCallbackArg]) || rho_ruby_is_method(argv[nCallbackArg]) )
        {
            oRes.setRubyCallbackProc( argv[nCallbackArg] );
        }else if ( rho_ruby_is_string(argv[nCallbackArg]) )
        {
            oRes.setRubyCallback( getStringObjectFromValue(argv[nCallbackArg]) );
        }else
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toRuby();
        }

        oRes.setCallInUIThread(false);
        if ( argc > nCallbackArg + 1 )
        {
            if ( !rho_ruby_is_NIL(argv[nCallbackArg + 1]) )
            {
                if ( !rho_ruby_is_string(argv[nCallbackArg + 1]) )
                {
                    oRes.setArgError("Type error: callback parameter should be String");
                    return oRes.toRuby();
                }

                oRes.setCallbackParam( getStringObjectFromValue(argv[nCallbackArg + 1]) );
            }
        }
        
        bUseCallback = true;
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::IChat::getProperties, arg0,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->getProperties( arg0,  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Chat_getProperties(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::IChat* pObj =  rho::CChatFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Chat_getProperties(argc, argv, pObj);

    return res;
}



VALUE rb_s_Chat_def_getProperties(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CChatFactoryBase::getChatSingletonS()->getDefaultID();
    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Chat_getProperties(argc, argv, pObj);
}


static VALUE _api_generator_Chat_getAllProperties(int argc, VALUE *argv, rho::IChat* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    oRes.setRequestedType(CMethodResult::eStringHash);
    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        if ( rho_ruby_is_proc(argv[nCallbackArg]) || rho_ruby_is_method(argv[nCallbackArg]) )
        {
            oRes.setRubyCallbackProc( argv[nCallbackArg] );
        }else if ( rho_ruby_is_string(argv[nCallbackArg]) )
        {
            oRes.setRubyCallback( getStringObjectFromValue(argv[nCallbackArg]) );
        }else
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toRuby();
        }

        oRes.setCallInUIThread(false);
        if ( argc > nCallbackArg + 1 )
        {
            if ( !rho_ruby_is_NIL(argv[nCallbackArg + 1]) )
            {
                if ( !rho_ruby_is_string(argv[nCallbackArg + 1]) )
                {
                    oRes.setArgError("Type error: callback parameter should be String");
                    return oRes.toRuby();
                }

                oRes.setCallbackParam( getStringObjectFromValue(argv[nCallbackArg + 1]) );
            }
        }
        
        bUseCallback = true;
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::IChat::getAllProperties,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->getAllProperties(  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Chat_getAllProperties(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::IChat* pObj =  rho::CChatFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Chat_getAllProperties(argc, argv, pObj);

    return res;
}



VALUE rb_s_Chat_def_getAllProperties(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CChatFactoryBase::getChatSingletonS()->getDefaultID();
    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Chat_getAllProperties(argc, argv, pObj);
}


static VALUE _api_generator_Chat_setProperty(int argc, VALUE *argv, rho::IChat* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toRuby();
    }
    rho::String arg0 = "";
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringObjectFromValue(argv[0]);
        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 2;
    if ( argc == 1 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toRuby();
    }
    rho::String arg1 = "";
    if ( argc > 1 )
    {
        if ( rho_ruby_is_string(argv[1]) )
        {
            arg1 = getStringObjectFromValue(argv[1]);
        }
        else if (!rho_ruby_is_NIL(argv[1]))
        {
            oRes.setArgError("Type error: argument " "1" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toRuby();
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor3( pObj, &rho::IChat::setProperty, arg0, arg1,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->setProperty( arg0, arg1,  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Chat_setProperty(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::IChat* pObj =  rho::CChatFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Chat_setProperty(argc, argv, pObj);

    return res;
}



VALUE rb_s_Chat_def_setProperty(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CChatFactoryBase::getChatSingletonS()->getDefaultID();
    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Chat_setProperty(argc, argv, pObj);
}


static VALUE _api_generator_Chat_setProperties(int argc, VALUE *argv, rho::IChat* pObj)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    rho::Hashtable<rho::String, rho::String> arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_hash(argv[0]) )
        {
            rho::String res;
            rho_value_to_typed_hash<rho::String, rho::String>(argv[0], arg0, res);
        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "hash" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    if ( bUseCallback )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::IChat::setProperties, arg0,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->setProperties( arg0,  oRes );
    }
    
    return oRes.toRuby();
}



VALUE rb_Chat_setProperties(int argc, VALUE *argv, VALUE obj)
{
    const char* szID = rho_ruby_get_object_id( obj );
    if (!szID)
        rho_ruby_raise_runtime("Object was deleted.");

    VALUE res = 0;
    rho::IChat* pObj =  rho::CChatFactoryBase::getInstance()->getModuleByID(szID);

    res = _api_generator_Chat_setProperties(argc, argv, pObj);

    return res;
}



VALUE rb_s_Chat_def_setProperties(int argc, VALUE *argv)
{
    rho::String strDefaultID = rho::CChatFactoryBase::getChatSingletonS()->getDefaultID();
    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strDefaultID);

    return _api_generator_Chat_setProperties(argc, argv, pObj);
}



}