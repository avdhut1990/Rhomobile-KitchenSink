#include "common/RhodesApp.h"
#include "api_generator/wp8/MethodResultImpl.h"
#include "../../../../shared/generated/cpp/ChatBase.h"
#include "ChatRuntime.h"
#include "../../wp8/rhoruntime/common/RhoConvertWP8.h"


namespace rho {

class CChatImpl: public CChatBase
{
private:
    rhoruntime::IChatImpl^ _runtime;
public:
    CChatImpl(const rho::String& strID, rhoruntime::IChatImpl^ runtime): CChatBase(), _runtime(runtime)
    {
        _runtime->setNativeImpl(rho::common::convertStringToWP8(strID), (int64)this);
    }

    virtual void getSimpleStringProperty(rho::apiGenerator::CMethodResult& oResult);
    virtual void setSimpleStringProperty(const rho::String& simpleStringProperty, rho::apiGenerator::CMethodResult& oResult);
    virtual void init(const rho::String& google_api_key, const rho::String& google_app_id, const rho::String& gcm_sender_id, const rho::String& google_project_id, const rho::String& google_storage_bucket, const rho::String& dialogflow_client_access_token, const rho::String& dialogflow_language, rho::apiGenerator::CMethodResult& oResult);
    virtual void sendMessage(const rho::String& query, rho::apiGenerator::CMethodResult& oResult);
};

}
