#include "rhodes.h"
#include "Chat.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "Chat_impl"

#define CHAT_FACTORY_CLASS "com.rho.chat.ChatFactory"

extern "C" void Init_Chat_API(void);

extern "C" void Init_Chat(void)
{
    RAWTRACE(__FUNCTION__);

    JNIEnv *env = jnienv();
    if(env)
    {
        jclass cls = rho_find_class(env, CHAT_FACTORY_CLASS);
        if(!cls)
        {
            RAWLOG_ERROR1("Failed to find java class: %s", CHAT_FACTORY_CLASS);
            return;
        }
        jmethodID midFactory = env->GetMethodID(cls, "<init>", "()V");
        if(!midFactory)
        {
            RAWLOG_ERROR1("Failed to get constructor for java class %s", CHAT_FACTORY_CLASS);
            return;
        }
        jobject jFactory = env->NewObject(cls, midFactory);
        if(env->IsSameObject(jFactory, NULL))
        {
            RAWLOG_ERROR1("Failed to create %s instance", CHAT_FACTORY_CLASS);
            return;
        }
        
        RAWTRACE("Initializing Java factory");

        rho::CChatBase::setJavaFactory(env, jFactory);

        RAWTRACE("Deleting JNI reference");

        env->DeleteLocalRef(jFactory);

        RAWTRACE("Initializing API");

        Init_Chat_API();

        RAWTRACE("Init_Chat succeeded");
    }
    else
    {
        RAWLOG_ERROR("Failed to initialize Chat API: jnienv() is failed");
    }

}

extern "C" void Init_Chat_extension() {
    Init_Chat();
}
