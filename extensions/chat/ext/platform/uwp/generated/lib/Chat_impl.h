#include "common/RhodesApp.h"
#include "api_generator/uwp/MethodResultImpl.h"
#include "../../../../shared/generated/cpp/ChatBase.h"
#include "ChatRuntime.h"
#include "../../uwp/rhoruntime/common/RhoConvertWP8.h"


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
    virtual void getPlatformName(rho::apiGenerator::CMethodResult& oResult);
    virtual void calcSumm(int a, int b, rho::apiGenerator::CMethodResult& oResult);
    virtual void joinStrings(const rho::String& a, const rho::String& b, rho::apiGenerator::CMethodResult& oResult);
};

}
