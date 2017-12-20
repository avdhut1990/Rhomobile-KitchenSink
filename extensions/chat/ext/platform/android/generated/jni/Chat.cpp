#include "Chat.h"


namespace rho {

IMPLEMENT_LOGCLASS(CChatBase, "ChatJNI");

//ChatFactorySingleton staff
const char* const CChatBase::FACTORY_SINGLETON_CLASS = "com.rho.chat.ChatFactorySingleton";
jclass CChatBase::s_clsFactorySingleton = 0;
jmethodID CChatBase::s_midFactorySetInstance;
jmethodID CChatBase::s_midFactoryGetInstance;

//ChatFactory staff
const char* const CChatBase::IFACTORY_CLASS = "com.rho.chat.IChatFactory";
jclass CChatBase::s_clsIFactory = 0;
jmethodID CChatBase::s_midGetApiSingleton;
jmethodID CChatBase::s_midGetApiObject;

//ChatSingletonBase staff
const char* const CChatBase::SINGLETON_BASE_CLASS = "com.rho.chat.ChatSingletonBase";
jclass CChatBase::s_clsSingletonBase = 0;

//ChatBase staff
const char* const CChatBase::OBJECT_BASE_CLASS = "com.rho.chat.ChatBase";
jclass CChatBase::s_clsObjectBase = 0;


//IRhoApiDefaultId staff
const char* const CChatBase::IDEFAULTID_CLASS = "com.rhomobile.rhodes.api.IRhoApiDefaultId";
jclass CChatBase::s_clsIDefaultId = 0;
jmethodID CChatBase::s_midGetDefaultID;
jmethodID CChatBase::s_midSetDefaultID;


//Method tasks

const char* const CChatBase::GETSIMPLESTRINGPROPERTY_TASK_CLASS = 
        "com.rho.chat.ChatBase$getSimpleStringPropertyTask";

jclass CChatBase::s_clsgetSimpleStringPropertyTask = 0;
jmethodID CChatBase::s_midgetSimpleStringPropertyTask;

const char* const CChatBase::SETSIMPLESTRINGPROPERTY_TASK_CLASS = 
        "com.rho.chat.ChatBase$setSimpleStringPropertyTask";

jclass CChatBase::s_clssetSimpleStringPropertyTask = 0;
jmethodID CChatBase::s_midsetSimpleStringPropertyTask;

const char* const CChatBase::ENUMERATE_TASK_CLASS = 
        "com.rho.chat.ChatSingletonBase$enumerateTask";

jclass CChatBase::s_clsenumerateTask = 0;
jmethodID CChatBase::s_midenumerateTask;

const char* const CChatBase::INIT_TASK_CLASS = 
        "com.rho.chat.ChatBase$initTask";

jclass CChatBase::s_clsinitTask = 0;
jmethodID CChatBase::s_midinitTask;

const char* const CChatBase::GETPROPERTY_TASK_CLASS = 
        "com.rho.chat.ChatBase$getPropertyTask";

jclass CChatBase::s_clsgetPropertyTask = 0;
jmethodID CChatBase::s_midgetPropertyTask;

const char* const CChatBase::GETPROPERTIES_TASK_CLASS = 
        "com.rho.chat.ChatBase$getPropertiesTask";

jclass CChatBase::s_clsgetPropertiesTask = 0;
jmethodID CChatBase::s_midgetPropertiesTask;

const char* const CChatBase::GETALLPROPERTIES_TASK_CLASS = 
        "com.rho.chat.ChatBase$getAllPropertiesTask";

jclass CChatBase::s_clsgetAllPropertiesTask = 0;
jmethodID CChatBase::s_midgetAllPropertiesTask;

const char* const CChatBase::SETPROPERTY_TASK_CLASS = 
        "com.rho.chat.ChatBase$setPropertyTask";

jclass CChatBase::s_clssetPropertyTask = 0;
jmethodID CChatBase::s_midsetPropertyTask;

const char* const CChatBase::SETPROPERTIES_TASK_CLASS = 
        "com.rho.chat.ChatBase$setPropertiesTask";

jclass CChatBase::s_clssetPropertiesTask = 0;
jmethodID CChatBase::s_midsetPropertiesTask;


//----------------------------------------------------------------------------------------------------------------------

JNIEnv* CChatBase::jniInit()
{
    JNIEnv *env = jnienv();
    if(!env)
    {
        LOG(FATAL) + "JNI init failed: JNIEnv is null";
        return 0;
    }
    return jniInit(env);
}
//----------------------------------------------------------------------------------------------------------------------

JNIEnv* CChatBase::jniInit(JNIEnv* env)
{
    static bool initialized = false;
    env = MethodExecutorJni::jniInit(env);
    if (!env) {
        LOG(FATAL) + "JNI init failed";
        return 0;
    }

    if(!initialized)
    {
        //init ChatFactorySingleton JNI
        s_clsFactorySingleton = loadClass(env, FACTORY_SINGLETON_CLASS);
        if (!s_clsFactorySingleton) return 0;

        s_midFactorySetInstance = env->GetStaticMethodID(s_clsFactorySingleton, "setInstance", "(Lcom/rho/chat/IChatFactory;)V");
        if(!s_midFactorySetInstance)
        {
            LOG(FATAL) + "Failed to get method 'setInstance' for java class " + FACTORY_SINGLETON_CLASS;
            return NULL;
        }
        s_midFactoryGetInstance = env->GetStaticMethodID(s_clsFactorySingleton, "getInstance", "()Lcom/rho/chat/IChatFactory;");
        if(!s_midFactoryGetInstance)
        {
            LOG(FATAL) + "Failed to get method 'getInstance' for java class " + FACTORY_SINGLETON_CLASS;
            return NULL;
        }

        //init IChatFactory JNI
        s_clsIFactory = loadClass(env, IFACTORY_CLASS);
        if (!s_clsIFactory) return 0;
        s_midGetApiSingleton = env->GetMethodID(s_clsIFactory, "getApiSingleton", "()Lcom/rho/chat/IChatSingleton;");
        if(!s_midGetApiSingleton)
        {
            LOG(FATAL) + "Failed to get method 'getApiSingleton' for java class " + IFACTORY_CLASS;
            return NULL;
        }
        s_midGetApiObject = env->GetMethodID(s_clsIFactory, "getApiObject", "(Ljava/lang/String;)Lcom/rho/chat/IChat;");
        if(!s_midGetApiObject)
        {
            LOG(FATAL) + "Failed to get method 'getApiObject' for java class " + IFACTORY_CLASS;
            return NULL;
        }

        s_clsSingletonBase = loadClass(env, SINGLETON_BASE_CLASS);
        if (!s_clsSingletonBase) return 0;
        s_clsObjectBase = loadClass(env, OBJECT_BASE_CLASS);
        if (!s_clsObjectBase) return 0;



        s_clsgetSimpleStringPropertyTask = loadClass(env, GETSIMPLESTRINGPROPERTY_TASK_CLASS);
        if (!s_clsgetSimpleStringPropertyTask) return 0;
        s_midgetSimpleStringPropertyTask = env->GetMethodID(s_clsgetSimpleStringPropertyTask, "<init>",
                        "(Lcom/rho/chat/IChat;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetSimpleStringPropertyTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETSIMPLESTRINGPROPERTY_TASK_CLASS;
            return NULL;
        }

        s_clssetSimpleStringPropertyTask = loadClass(env, SETSIMPLESTRINGPROPERTY_TASK_CLASS);
        if (!s_clssetSimpleStringPropertyTask) return 0;
        s_midsetSimpleStringPropertyTask = env->GetMethodID(s_clssetSimpleStringPropertyTask, "<init>",
                        "(Lcom/rho/chat/IChat;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetSimpleStringPropertyTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETSIMPLESTRINGPROPERTY_TASK_CLASS;
            return NULL;
        }

        s_clsenumerateTask = loadClass(env, ENUMERATE_TASK_CLASS);
        if (!s_clsenumerateTask) return 0;
        s_midenumerateTask = env->GetMethodID(s_clsenumerateTask, "<init>",
                        "(Lcom/rho/chat/IChatSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midenumerateTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + ENUMERATE_TASK_CLASS;
            return NULL;
        }

        s_clsinitTask = loadClass(env, INIT_TASK_CLASS);
        if (!s_clsinitTask) return 0;
        s_midinitTask = env->GetMethodID(s_clsinitTask, "<init>",
                        "(Lcom/rho/chat/IChat;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midinitTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + INIT_TASK_CLASS;
            return NULL;
        }

        s_clsgetPropertyTask = loadClass(env, GETPROPERTY_TASK_CLASS);
        if (!s_clsgetPropertyTask) return 0;
        s_midgetPropertyTask = env->GetMethodID(s_clsgetPropertyTask, "<init>",
                        "(Lcom/rho/chat/IChat;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetPropertyTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETPROPERTY_TASK_CLASS;
            return NULL;
        }

        s_clsgetPropertiesTask = loadClass(env, GETPROPERTIES_TASK_CLASS);
        if (!s_clsgetPropertiesTask) return 0;
        s_midgetPropertiesTask = env->GetMethodID(s_clsgetPropertiesTask, "<init>",
                        "(Lcom/rho/chat/IChat;Ljava/util/List;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetPropertiesTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETPROPERTIES_TASK_CLASS;
            return NULL;
        }

        s_clsgetAllPropertiesTask = loadClass(env, GETALLPROPERTIES_TASK_CLASS);
        if (!s_clsgetAllPropertiesTask) return 0;
        s_midgetAllPropertiesTask = env->GetMethodID(s_clsgetAllPropertiesTask, "<init>",
                        "(Lcom/rho/chat/IChat;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetAllPropertiesTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETALLPROPERTIES_TASK_CLASS;
            return NULL;
        }

        s_clssetPropertyTask = loadClass(env, SETPROPERTY_TASK_CLASS);
        if (!s_clssetPropertyTask) return 0;
        s_midsetPropertyTask = env->GetMethodID(s_clssetPropertyTask, "<init>",
                        "(Lcom/rho/chat/IChat;Ljava/lang/String;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetPropertyTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETPROPERTY_TASK_CLASS;
            return NULL;
        }

        s_clssetPropertiesTask = loadClass(env, SETPROPERTIES_TASK_CLASS);
        if (!s_clssetPropertiesTask) return 0;
        s_midsetPropertiesTask = env->GetMethodID(s_clssetPropertiesTask, "<init>",
                        "(Lcom/rho/chat/IChat;Ljava/util/Map;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetPropertiesTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETPROPERTIES_TASK_CLASS;
            return NULL;
        }


        s_clsIDefaultId = loadClass(env, IDEFAULTID_CLASS);
        if (!s_clsIDefaultId) return 0;
        s_midGetDefaultID = env->GetMethodID(s_clsIDefaultId, "getDefaultID", "()Ljava/lang/String;");
        if(!s_midGetDefaultID)
        {
            LOG(FATAL) + "Failed to get method 'getDefaultID' for java class " + IDEFAULTID_CLASS;
            return NULL;
        }
        s_midSetDefaultID = env->GetMethodID(s_clsIDefaultId, "setDefaultID", "(Ljava/lang/String;)V");
        if(!s_midSetDefaultID)
        {
            LOG(FATAL) + "Failed to get method 'setDefaultID' for java class " + IDEFAULTID_CLASS;
            return NULL;
        }


        initialized = true;
        LOG(TRACE) + "CChat JNI init succeeded";
    }
    return env;
}
//----------------------------------------------------------------------------------------------------------------------

void CChatBase::setJavaFactory(JNIEnv* env, jobject jFactory)
{
    LOG(TRACE) + "setJavaFactory";

    env = jniInit(env);
    if (!env) {
        LOG(FATAL) + "JNI initialization failed";
        return;
    }

    env->CallStaticVoidMethod(s_clsFactorySingleton, s_midFactorySetInstance, jFactory);

    LOG(TRACE) + "setJavaFactory succeeded";
}
//----------------------------------------------------------------------------------------------------------------------

rho::String CChatBase::getDefaultID()
{
    LOG(TRACE) + "getDefaultID";

    JNIEnv *env = jniInit();
    if (!env) {
        LOG(FATAL) + "JNI initialization failed";
        return rho::String();
    }

    jhobject jhSingleton = getSingleton(env);
    jhstring res = static_cast<jstring>(env->CallObjectMethod(jhSingleton.get(), s_midGetDefaultID));
    return rho_cast<rho::String>(env, res);
}
//----------------------------------------------------------------------------------------------------------------------

void CChatBase::setDefaultID(const rho::String& id)
{
    LOG(TRACE) + "setDefaultID: " + id;

    JNIEnv *env = jniInit();
    if (!env) {
        LOG(FATAL) + "JNI initialization failed";
        return;
    }

    jhobject instance = getSingleton(env);
    jhstring jhId = rho_cast<jstring>(env, id);
    env->CallVoidMethod(instance.get(), s_midSetDefaultID, jhId.get());
}
//----------------------------------------------------------------------------------------------------------------------

jobject CChatBase::getFactory(JNIEnv* env)
{
    jobject res = env->CallStaticObjectMethod(s_clsFactorySingleton, s_midFactoryGetInstance);
    return res;
}
//----------------------------------------------------------------------------------------------------------------------

jobject CChatBase::getSingleton(JNIEnv* env)
{
    jhobject jhFactory = getFactory(env);
    jobject res = env->CallObjectMethod(jhFactory.get(), s_midGetApiSingleton);
    return res;
}
//----------------------------------------------------------------------------------------------------------------------

jobject CChatBase::getObject(JNIEnv* env)
{
    jhstring jhId = rho_cast<jstring>(env, m_id);
    jhobject jhFactory = getFactory(env);
    jobject res = env->CallObjectMethod(jhFactory.get(), s_midGetApiObject, jhId.get());
    return res;
}
//----------------------------------------------------------------------------------------------------------------------


}
