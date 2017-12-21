#include "Chat_impl.h"
#include "ChatFactory.h"
#include "api_generator/wp8/MethodResultImpl.h"

using namespace rho::apiGenerator;
using namespace rhoruntime;

namespace rho {


void CChatImpl::getSimpleStringProperty(CMethodResult& oResult)
{
    try {
        _runtime->getSimpleStringProperty(ref new CMethodResultImpl((int64)&oResult));
    } catch (Platform::Exception^ e) {
        LOG(ERROR) + rho::common::convertStringAFromWP8(e->ToString());
    }
}

void CChatImpl::setSimpleStringProperty(const rho::String& simpleStringProperty, CMethodResult& oResult)
{
        Platform::String^ _simpleStringProperty = rho::common::convertStringToWP8(simpleStringProperty);
    try {
        _runtime->setSimpleStringProperty(_simpleStringProperty, ref new CMethodResultImpl((int64)&oResult));
    } catch (Platform::Exception^ e) {
        LOG(ERROR) + rho::common::convertStringAFromWP8(e->ToString());
    }
}

void CChatImpl::init(const rho::String& google_api_key, const rho::String& google_app_id, const rho::String& gcm_sender_id, const rho::String& google_project_id, const rho::String& google_storage_bucket, const rho::String& dialogflow_client_access_token, const rho::String& dialogflow_language, CMethodResult& oResult)
{
        Platform::String^ _google_api_key = rho::common::convertStringToWP8(google_api_key);
        Platform::String^ _google_app_id = rho::common::convertStringToWP8(google_app_id);
        Platform::String^ _gcm_sender_id = rho::common::convertStringToWP8(gcm_sender_id);
        Platform::String^ _google_project_id = rho::common::convertStringToWP8(google_project_id);
        Platform::String^ _google_storage_bucket = rho::common::convertStringToWP8(google_storage_bucket);
        Platform::String^ _dialogflow_client_access_token = rho::common::convertStringToWP8(dialogflow_client_access_token);
        Platform::String^ _dialogflow_language = rho::common::convertStringToWP8(dialogflow_language);
    try {
        _runtime->init(_google_api_key, _google_app_id, _gcm_sender_id, _google_project_id, _google_storage_bucket, _dialogflow_client_access_token, _dialogflow_language, ref new CMethodResultImpl((int64)&oResult));
    } catch (Platform::Exception^ e) {
        LOG(ERROR) + rho::common::convertStringAFromWP8(e->ToString());
    }
}


class CChatSingleton: public CChatSingletonBase
{
private:
    IChatSingletonImpl^ _runtime;
public:
    CChatSingleton(IChatSingletonImpl^ runtime): CChatSingletonBase(), _runtime(runtime) {}
    ~CChatSingleton(){}

    virtual void enumerate(CMethodResult& oResult)
    {
        try {
            _runtime->enumerate(ref new CMethodResultImpl((int64)&oResult));
        } catch (Platform::Exception^ e) {
            LOG(ERROR) + rho::common::convertStringAFromWP8(e->ToString());
        }
    }


    virtual rho::String getDefaultID(){return "1";} // TODO: implement getDefaultID
    virtual rho::String getInitialDefaultID(){return "1";} // TODO: implement getInitialDefaultID
    virtual void setDefaultID(const rho::String& strID){} // TODO: implement setDefaultID
    
    //virtual void addCommandToQueue(rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor){} // TODO: implement addCommandToQueue
    //virtual void callCommandInThread(rho::common::IRhoRunnable* pFunctor){} // TODO: implement callCommandInThread
};

IChatFactoryImpl^ CChatFactory::_impl;

IChat* CChatFactory::createModuleByID(const rho::String& strID)
{
    return new CChatImpl(strID, _impl->getImpl());
}

IChatSingleton* CChatFactory::createModuleSingleton()
{
    return new CChatSingleton(_impl->getSingletonImpl());
}

}

extern "C" void Init_Chat_extension()
{
    rho::CChatFactory::setInstance( new rho::CChatFactory() );
    rho::Init_Chat_API();

    RHODESAPP().getExtManager().requireRubyFile("RhoChatApi");
}
