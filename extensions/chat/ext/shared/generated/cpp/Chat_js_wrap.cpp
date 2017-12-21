

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "Chat"

#include "ChatBase.h"
#include "api_generator/js_helpers.h"
#include "api_generator/JSONResultConvertor.h"

#include "common/StringConverter.h"

extern "C" void rho_os_impl_performOnUiThread(rho::common::IRhoRunnable* pTask);

#ifdef OS_ANDROID
#include <jni.h>
extern "C" void* rho_nativethread_start();
JNIEnv* jnienv();
#endif //OS_ANDROID

using namespace rho;
using namespace rho::json;
using namespace rho::common;
using namespace rho::apiGenerator;


rho::String js_Chat_getSimpleStringProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("getSimpleStringProperty(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;


    oRes.setRequestedType(CMethodResult::eString);

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strObjID);

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::IChat::getSimpleStringProperty,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->getSimpleStringProperty(  oRes );
    }
    
    return oRes.toJSON();

}

rho::String js_Chat_setSimpleStringProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("setSimpleStringProperty(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;



    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strObjID);

    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    
    rho::String arg0 = "";
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getStringObject();
        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::IChat::setSimpleStringProperty, arg0,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->setSimpleStringProperty( arg0,  oRes );
    }
    
    return oRes.toJSON();

}

rho::String js_s_Chat_enumerate(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("enumerate(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;


    oRes.setParamName( "result" );
    oRes.setJSObjectClassPath( "Rho.Chat" );
    oRes.setRequestedType(CMethodResult::eStringArray);

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    oRes.setCallInUIThread(false);
    oRes.setJSCallback( strCallbackID );
    oRes.setCallbackParam( strCallbackParam );

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor1( rho::CChatFactoryBase::getChatSingletonS(), &rho::IChatSingleton::enumerate,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        rho::CChatFactoryBase::getChatSingletonS()->enumerate(  oRes );
    }
    
    return oRes.toJSON();

}

rho::String js_Chat_init(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("init(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;


    oRes.setRequestedType(CMethodResult::eString);

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strObjID);

    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toJSON();
    }
    
    rho::String arg0 = "";
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getStringObject();
        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }

    if ( argc == 1 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toJSON();
    }
    
    rho::String arg1 = "";
    if ( argc > 1 )
    {
        if ( argv[1].isString() )
        {
            arg1 = argv[1].getStringObject();
        }
        else if (!argv[1].isNull())
        {
            oRes.setArgError( "Type error: argument " "1" " should be " "string" );
            return oRes.toJSON();
        }
    }

    if ( argc == 2 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toJSON();
    }
    
    rho::String arg2 = "";
    if ( argc > 2 )
    {
        if ( argv[2].isString() )
        {
            arg2 = argv[2].getStringObject();
        }
        else if (!argv[2].isNull())
        {
            oRes.setArgError( "Type error: argument " "2" " should be " "string" );
            return oRes.toJSON();
        }
    }

    if ( argc == 3 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toJSON();
    }
    
    rho::String arg3 = "";
    if ( argc > 3 )
    {
        if ( argv[3].isString() )
        {
            arg3 = argv[3].getStringObject();
        }
        else if (!argv[3].isNull())
        {
            oRes.setArgError( "Type error: argument " "3" " should be " "string" );
            return oRes.toJSON();
        }
    }

    if ( argc == 4 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toJSON();
    }
    
    rho::String arg4 = "";
    if ( argc > 4 )
    {
        if ( argv[4].isString() )
        {
            arg4 = argv[4].getStringObject();
        }
        else if (!argv[4].isNull())
        {
            oRes.setArgError( "Type error: argument " "4" " should be " "string" );
            return oRes.toJSON();
        }
    }

    if ( argc == 5 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toJSON();
    }
    
    rho::String arg5 = "";
    if ( argc > 5 )
    {
        if ( argv[5].isString() )
        {
            arg5 = argv[5].getStringObject();
        }
        else if (!argv[5].isNull())
        {
            oRes.setArgError( "Type error: argument " "5" " should be " "string" );
            return oRes.toJSON();
        }
    }

    if ( argc == 6 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(7) );
        return oRes.toJSON();
    }
    
    rho::String arg6 = "";
    if ( argc > 6 )
    {
        if ( argv[6].isString() )
        {
            arg6 = argv[6].getStringObject();
        }
        else if (!argv[6].isNull())
        {
            oRes.setArgError( "Type error: argument " "6" " should be " "string" );
            return oRes.toJSON();
        }
    }

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor8( pObj, &rho::IChat::init, arg0, arg1, arg2, arg3, arg4, arg5, arg6,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->init( arg0, arg1, arg2, arg3, arg4, arg5, arg6,  oRes );
    }
    
    return oRes.toJSON();

}

rho::String js_Chat_getProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("getProperty(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;


    oRes.setRequestedType(CMethodResult::eString);

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strObjID);

    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    
    rho::String arg0 = "";
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getStringObject();
        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }

    oRes.setCallInUIThread(false);
    oRes.setJSCallback( strCallbackID );
    oRes.setCallbackParam( strCallbackParam );

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::IChat::getProperty, arg0,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->getProperty( arg0,  oRes );
    }
    
    return oRes.toJSON();

}

rho::String js_Chat_getProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("getProperties(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;


    oRes.setRequestedType(CMethodResult::eStringHash);

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strObjID);

    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    
    rho::Vector<rho::String> arg0;
    if ( argc > 0 )
    {
        CJSONEntry value(argv[0]);
        if ( value.isArray() )
        {
            
            CJSONArray arParam(value);
            arg0.reserve(arParam.getSize());
            for( int i = 0; i < arParam.getSize(); i++ )
            {
                arg0.addElement( arParam[i].getStringObject() );
            }
            
        }
        else if (!value.isNull())
        {
            oRes.setArgError("Type error: argument " "0" " should be " "array" );
            return oRes.toJSON();
        }
    }

    oRes.setCallInUIThread(false);
    oRes.setJSCallback( strCallbackID );
    oRes.setCallbackParam( strCallbackParam );

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::IChat::getProperties, arg0,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->getProperties( arg0,  oRes );
    }
    
    return oRes.toJSON();

}

rho::String js_Chat_getAllProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("getAllProperties(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;


    oRes.setRequestedType(CMethodResult::eStringHash);

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strObjID);

    oRes.setCallInUIThread(false);
    oRes.setJSCallback( strCallbackID );
    oRes.setCallbackParam( strCallbackParam );

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::IChat::getAllProperties,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->getAllProperties(  oRes );
    }
    
    return oRes.toJSON();

}

rho::String js_Chat_setProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("setProperty(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;



    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strObjID);

    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toJSON();
    }
    
    rho::String arg0 = "";
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getStringObject();
        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }

    if ( argc == 1 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toJSON();
    }
    
    rho::String arg1 = "";
    if ( argc > 1 )
    {
        if ( argv[1].isString() )
        {
            arg1 = argv[1].getStringObject();
        }
        else if (!argv[1].isNull())
        {
            oRes.setArgError( "Type error: argument " "1" " should be " "string" );
            return oRes.toJSON();
        }
    }

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor3( pObj, &rho::IChat::setProperty, arg0, arg1,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->setProperty( arg0, arg1,  oRes );
    }
    
    return oRes.toJSON();

}

rho::String js_Chat_setProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    RAWTRACE4("setProperties(strObjID = %s, argc = %d, strCallbackID = %s, strJsVmID = %s)", strObjID.c_str(), argv.getSize(), strCallbackID.c_str(), strJsVmID.c_str());

#ifdef OS_ANDROID
    if ( jnienv() == 0 )
    {
        rho_nativethread_start();
    }
#endif

    rho::apiGenerator::CMethodResult oRes;



    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    int argc = argv.getSize();

    rho::IChat* pObj = rho::CChatFactoryBase::getInstance()->getModuleByID(strObjID);

    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    
    rho::Hashtable<rho::String, rho::String> arg0;
    if ( argc > 0 )
    {
        CJSONEntry value(argv[0]);
        if ( value.isObject() )
        {
            
            CJSONStructIterator objIter(value);

            for( ; !objIter.isEnd(); objIter.next() )
            {
                arg0[objIter.getCurKey()] = objIter.getCurString();
            }
            
        }
        else if (!value.isNull())
        {
            oRes.setArgError("Type error: argument " "0" " should be " "hash" );
            return oRes.toJSON();
        }
    }

    if ( oRes.hasCallback() )
    {
        pFunctor = rho_makeInstanceClassFunctor2( pObj, &rho::IChat::setProperties, arg0,  oRes );
        rho::CChatFactoryBase::getChatSingletonS()->addCommandToQueue( pFunctor );
    }
    else 
    {

        pObj->setProperties( arg0,  oRes );
    }
    
    return oRes.toJSON();

}



rho::String js_s_Chat_getDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    rho::apiGenerator::CMethodResult oRes;
    rho::String strDefaultID = rho::CChatFactoryBase::getChatSingletonS()->getDefaultID();
    oRes.set(strDefaultID);

    return oRes.toJSON();
}

rho::String js_s_Chat_getDefault(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    rho::apiGenerator::CMethodResult oRes;
    rho::String strDefaultID = rho::CChatFactoryBase::getChatSingletonS()->getDefaultID();
    oRes.set(strDefaultID);
    oRes.setJSObjectClassPath("Rho.Chat");

    return oRes.toJSON();
}

rho::String js_s_Chat_setDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    rho::apiGenerator::CMethodResult oRes;
    rho::json::CJSONEntry el = argv[0];

    if (el.isString()) {
        rho::CChatFactoryBase::getChatSingletonS()->setDefaultID(el.getString());
    } else {
        oRes.setError("Method parameter should be defined as string!");
    }

    return oRes.toJSON();
}


