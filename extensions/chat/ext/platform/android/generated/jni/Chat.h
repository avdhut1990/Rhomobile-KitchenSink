#pragma once

#include "common/RhoStd.h"
#include "logging/RhoLog.h"
#include "rhodes/JNIRhodes.h"
#include "MethodExecutorJni.h"
#include "MethodResultJni.h"


namespace rho {

using rho::apiGenerator::MethodResultJni;
using rho::apiGenerator::MethodExecutorJni;

class CChatBase : public MethodExecutorJni
{
protected:
    DEFINE_LOGCLASS;

    static const char* const FACTORY_SINGLETON_CLASS;
    static jclass s_clsFactorySingleton;
    static jmethodID s_midFactorySetInstance;
    static jmethodID s_midFactoryGetInstance;

    //IChatFactory staff
    static const char* const IFACTORY_CLASS;
    static jclass s_clsIFactory;
    static jmethodID s_midGetApiSingleton;
    static jmethodID s_midGetApiObject;

    //ChatSingletonBase staff
    static const char* const SINGLETON_BASE_CLASS;
    static jclass s_clsSingletonBase;

    //ChatBase staff
    static const char* const OBJECT_BASE_CLASS;
    static jclass s_clsObjectBase;

    //Method tasks

    static const char* const GETSIMPLESTRINGPROPERTY_TASK_CLASS;
    static jclass s_clsgetSimpleStringPropertyTask;
    static jmethodID s_midgetSimpleStringPropertyTask;
    static const char* const SETSIMPLESTRINGPROPERTY_TASK_CLASS;
    static jclass s_clssetSimpleStringPropertyTask;
    static jmethodID s_midsetSimpleStringPropertyTask;
    static const char* const ENUMERATE_TASK_CLASS;
    static jclass s_clsenumerateTask;
    static jmethodID s_midenumerateTask;
    static const char* const INIT_TASK_CLASS;
    static jclass s_clsinitTask;
    static jmethodID s_midinitTask;
    static const char* const GETPROPERTY_TASK_CLASS;
    static jclass s_clsgetPropertyTask;
    static jmethodID s_midgetPropertyTask;
    static const char* const GETPROPERTIES_TASK_CLASS;
    static jclass s_clsgetPropertiesTask;
    static jmethodID s_midgetPropertiesTask;
    static const char* const GETALLPROPERTIES_TASK_CLASS;
    static jclass s_clsgetAllPropertiesTask;
    static jmethodID s_midgetAllPropertiesTask;
    static const char* const SETPROPERTY_TASK_CLASS;
    static jclass s_clssetPropertyTask;
    static jmethodID s_midsetPropertyTask;
    static const char* const SETPROPERTIES_TASK_CLASS;
    static jclass s_clssetPropertiesTask;
    static jmethodID s_midsetPropertiesTask;

    //IRhoApiDefaultId staff
    static const char* const IDEFAULTID_CLASS;
    static jclass s_clsIDefaultId;
    static jmethodID s_midGetDefaultID;
    static jmethodID s_midSetDefaultID;

    static JNIEnv* jniInit(JNIEnv* env);
    static JNIEnv* jniInit();

    static jobject getFactory(JNIEnv* env);
    static jobject getSingleton(JNIEnv* env);

    rho::String m_id;
    jobject getObject(JNIEnv* env);
public:
    static void setJavaFactory(JNIEnv* env, jobject jFactory);

    static rho::String getDefaultID();
    static void setDefaultID(const rho::String& id); 

    CChatBase(const rho::String& id)
        : MethodExecutorJni(), m_id(id)
        {}
    virtual ~CChatBase() {}
};

template <typename T>
class CChatProxy : public CChatBase
{
public:
    CChatProxy(const rho::String& id)
        : CChatBase(id)
        {}
    virtual ~CChatProxy() {}

    void getSimpleStringProperty(const T& argsAdapter, MethodResultJni& result)
    {
        LOG(TRACE) + "getSimpleStringProperty";

        JNIEnv *env = jniInit();
        if (!env) {
            LOG(FATAL) + "JNI initialization failed";
            return;
        }

        jhobject jhObject = 
            getObject(env); 

        jhobject jhTask = env->NewObject(s_clsgetSimpleStringPropertyTask, s_midgetSimpleStringPropertyTask,
                    jhObject.get(), 
                    static_cast<jobject>(result));

        run(env, jhTask.get(), result, rho::apiGenerator::NOT_FORCE_THREAD);
        if(env->ExceptionCheck() == JNI_TRUE)
        {
            rho::String message = rho::common::clearException(env);
            LOG(ERROR) + message;
            result.setError(message);
        }
    }

    void setSimpleStringProperty(const T& argsAdapter, MethodResultJni& result)
    {
        LOG(TRACE) + "setSimpleStringProperty";

        JNIEnv *env = jniInit();
        if (!env) {
            LOG(FATAL) + "JNI initialization failed";
            return;
        }

        jhobject jhObject = 
            getObject(env); 

        if(argsAdapter.size() <= 0)
        {
            LOG(ERROR) + "Wrong number of arguments: 'simpleStringProperty' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'simpleStringProperty' must be set");
            return;
        }
        jholder< jstring > jhsimpleStringProperty = 
            rho_cast< jstring >(env, argsAdapter[0]);

        jhobject jhTask = env->NewObject(s_clssetSimpleStringPropertyTask, s_midsetSimpleStringPropertyTask,
                    jhObject.get(), 
                    jhsimpleStringProperty.get(),
                    static_cast<jobject>(result));

        run(env, jhTask.get(), result, rho::apiGenerator::NOT_FORCE_THREAD);
        if(env->ExceptionCheck() == JNI_TRUE)
        {
            rho::String message = rho::common::clearException(env);
            LOG(ERROR) + message;
            result.setError(message);
        }
    }

    static
    void enumerate(const T& argsAdapter, MethodResultJni& result)
    {
        LOG(TRACE) + "enumerate";

        JNIEnv *env = jniInit();
        if (!env) {
            LOG(FATAL) + "JNI initialization failed";
            return;
        }

        jhobject jhObject = 
            getSingleton(env); 

        jhobject jhTask = env->NewObject(s_clsenumerateTask, s_midenumerateTask,
                    jhObject.get(), 
                    static_cast<jobject>(result));

        run(env, jhTask.get(), result, rho::apiGenerator::NOT_FORCE_THREAD);
        if(env->ExceptionCheck() == JNI_TRUE)
        {
            rho::String message = rho::common::clearException(env);
            LOG(ERROR) + message;
            result.setError(message);
        }
    }

    void init(const T& argsAdapter, MethodResultJni& result)
    {
        LOG(TRACE) + "init";

        JNIEnv *env = jniInit();
        if (!env) {
            LOG(FATAL) + "JNI initialization failed";
            return;
        }

        jhobject jhObject = 
            getObject(env); 

        if(argsAdapter.size() <= 0)
        {
            LOG(ERROR) + "Wrong number of arguments: 'google_api_key' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'google_api_key' must be set");
            return;
        }
        jholder< jstring > jhgoogle_api_key = 
            rho_cast< jstring >(env, argsAdapter[0]);

        if(argsAdapter.size() <= 1)
        {
            LOG(ERROR) + "Wrong number of arguments: 'google_app_id' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'google_app_id' must be set");
            return;
        }
        jholder< jstring > jhgoogle_app_id = 
            rho_cast< jstring >(env, argsAdapter[1]);

        if(argsAdapter.size() <= 2)
        {
            LOG(ERROR) + "Wrong number of arguments: 'gcm_sender_id' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'gcm_sender_id' must be set");
            return;
        }
        jholder< jstring > jhgcm_sender_id = 
            rho_cast< jstring >(env, argsAdapter[2]);

        if(argsAdapter.size() <= 3)
        {
            LOG(ERROR) + "Wrong number of arguments: 'google_project_id' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'google_project_id' must be set");
            return;
        }
        jholder< jstring > jhgoogle_project_id = 
            rho_cast< jstring >(env, argsAdapter[3]);

        if(argsAdapter.size() <= 4)
        {
            LOG(ERROR) + "Wrong number of arguments: 'google_storage_bucket' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'google_storage_bucket' must be set");
            return;
        }
        jholder< jstring > jhgoogle_storage_bucket = 
            rho_cast< jstring >(env, argsAdapter[4]);

        if(argsAdapter.size() <= 5)
        {
            LOG(ERROR) + "Wrong number of arguments: 'dialogflow_client_access_token' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'dialogflow_client_access_token' must be set");
            return;
        }
        jholder< jstring > jhdialogflow_client_access_token = 
            rho_cast< jstring >(env, argsAdapter[5]);

        if(argsAdapter.size() <= 6)
        {
            LOG(ERROR) + "Wrong number of arguments: 'dialogflow_language' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'dialogflow_language' must be set");
            return;
        }
        jholder< jstring > jhdialogflow_language = 
            rho_cast< jstring >(env, argsAdapter[6]);

        jhobject jhTask = env->NewObject(s_clsinitTask, s_midinitTask,
                    jhObject.get(), 
                    jhgoogle_api_key.get(),
                    jhgoogle_app_id.get(),
                    jhgcm_sender_id.get(),
                    jhgoogle_project_id.get(),
                    jhgoogle_storage_bucket.get(),
                    jhdialogflow_client_access_token.get(),
                    jhdialogflow_language.get(),
                    static_cast<jobject>(result));

        run(env, jhTask.get(), result, rho::apiGenerator::NOT_FORCE_THREAD);
        if(env->ExceptionCheck() == JNI_TRUE)
        {
            rho::String message = rho::common::clearException(env);
            LOG(ERROR) + message;
            result.setError(message);
        }
    }

    void getProperty(const T& argsAdapter, MethodResultJni& result)
    {
        LOG(TRACE) + "getProperty";

        JNIEnv *env = jniInit();
        if (!env) {
            LOG(FATAL) + "JNI initialization failed";
            return;
        }

        jhobject jhObject = 
            getObject(env); 

        if(argsAdapter.size() <= 0)
        {
            LOG(ERROR) + "Wrong number of arguments: 'propertyName' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'propertyName' must be set");
            return;
        }
        jholder< jstring > jhpropertyName = 
            rho_cast< jstring >(env, argsAdapter[0]);

        jhobject jhTask = env->NewObject(s_clsgetPropertyTask, s_midgetPropertyTask,
                    jhObject.get(), 
                    jhpropertyName.get(),
                    static_cast<jobject>(result));

        run(env, jhTask.get(), result, rho::apiGenerator::NOT_FORCE_THREAD);
        if(env->ExceptionCheck() == JNI_TRUE)
        {
            rho::String message = rho::common::clearException(env);
            LOG(ERROR) + message;
            result.setError(message);
        }
    }

    void getProperties(const T& argsAdapter, MethodResultJni& result)
    {
        LOG(TRACE) + "getProperties";

        JNIEnv *env = jniInit();
        if (!env) {
            LOG(FATAL) + "JNI initialization failed";
            return;
        }

        jhobject jhObject = 
            getObject(env); 

        if(argsAdapter.size() <= 0)
        {
            LOG(ERROR) + "Wrong number of arguments: 'arrayofNames' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'arrayofNames' must be set");
            return;
        }
        jholder< jobject > jharrayofNames = 
            rho_cast< jobject >(env, argsAdapter[0]);

        jhobject jhTask = env->NewObject(s_clsgetPropertiesTask, s_midgetPropertiesTask,
                    jhObject.get(), 
                    jharrayofNames.get(),
                    static_cast<jobject>(result));

        run(env, jhTask.get(), result, rho::apiGenerator::NOT_FORCE_THREAD);
        if(env->ExceptionCheck() == JNI_TRUE)
        {
            rho::String message = rho::common::clearException(env);
            LOG(ERROR) + message;
            result.setError(message);
        }
    }

    void getAllProperties(const T& argsAdapter, MethodResultJni& result)
    {
        LOG(TRACE) + "getAllProperties";

        JNIEnv *env = jniInit();
        if (!env) {
            LOG(FATAL) + "JNI initialization failed";
            return;
        }

        jhobject jhObject = 
            getObject(env); 

        jhobject jhTask = env->NewObject(s_clsgetAllPropertiesTask, s_midgetAllPropertiesTask,
                    jhObject.get(), 
                    static_cast<jobject>(result));

        run(env, jhTask.get(), result, rho::apiGenerator::NOT_FORCE_THREAD);
        if(env->ExceptionCheck() == JNI_TRUE)
        {
            rho::String message = rho::common::clearException(env);
            LOG(ERROR) + message;
            result.setError(message);
        }
    }

    void setProperty(const T& argsAdapter, MethodResultJni& result)
    {
        LOG(TRACE) + "setProperty";

        JNIEnv *env = jniInit();
        if (!env) {
            LOG(FATAL) + "JNI initialization failed";
            return;
        }

        jhobject jhObject = 
            getObject(env); 

        if(argsAdapter.size() <= 0)
        {
            LOG(ERROR) + "Wrong number of arguments: 'propertyName' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'propertyName' must be set");
            return;
        }
        jholder< jstring > jhpropertyName = 
            rho_cast< jstring >(env, argsAdapter[0]);

        if(argsAdapter.size() <= 1)
        {
            LOG(ERROR) + "Wrong number of arguments: 'propertyValue' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'propertyValue' must be set");
            return;
        }
        jholder< jstring > jhpropertyValue = 
            rho_cast< jstring >(env, argsAdapter[1]);

        jhobject jhTask = env->NewObject(s_clssetPropertyTask, s_midsetPropertyTask,
                    jhObject.get(), 
                    jhpropertyName.get(),
                    jhpropertyValue.get(),
                    static_cast<jobject>(result));

        run(env, jhTask.get(), result, rho::apiGenerator::NOT_FORCE_THREAD);
        if(env->ExceptionCheck() == JNI_TRUE)
        {
            rho::String message = rho::common::clearException(env);
            LOG(ERROR) + message;
            result.setError(message);
        }
    }

    void setProperties(const T& argsAdapter, MethodResultJni& result)
    {
        LOG(TRACE) + "setProperties";

        JNIEnv *env = jniInit();
        if (!env) {
            LOG(FATAL) + "JNI initialization failed";
            return;
        }

        jhobject jhObject = 
            getObject(env); 

        if(argsAdapter.size() <= 0)
        {
            LOG(ERROR) + "Wrong number of arguments: 'propertyMap' must be set ^^^";
            result.setArgError("Wrong number of arguments: 'propertyMap' must be set");
            return;
        }
        jholder< jobject > jhpropertyMap = 
            rho_cast< jobject >(env, argsAdapter[0]);

        jhobject jhTask = env->NewObject(s_clssetPropertiesTask, s_midsetPropertiesTask,
                    jhObject.get(), 
                    jhpropertyMap.get(),
                    static_cast<jobject>(result));

        run(env, jhTask.get(), result, rho::apiGenerator::NOT_FORCE_THREAD);
        if(env->ExceptionCheck() == JNI_TRUE)
        {
            rho::String message = rho::common::clearException(env);
            LOG(ERROR) + message;
            result.setError(message);
        }
    }


};


}
