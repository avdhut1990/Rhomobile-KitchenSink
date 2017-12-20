#include "Chat_impl.h"
#include "ChatFactory.h"
#include "api_generator/uwp/MethodResultImpl.h"

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

void CChatImpl::getPlatformName(CMethodResult& oResult)
{
    try {
        _runtime->getPlatformName(ref new CMethodResultImpl((int64)&oResult));
    } catch (Platform::Exception^ e) {
        LOG(ERROR) + rho::common::convertStringAFromWP8(e->ToString());
    }
}

void CChatImpl::calcSumm(int a, int b, CMethodResult& oResult)
{
    try {
        _runtime->calcSumm(a, b, ref new CMethodResultImpl((int64)&oResult));
    } catch (Platform::Exception^ e) {
        LOG(ERROR) + rho::common::convertStringAFromWP8(e->ToString());
    }
}

void CChatImpl::joinStrings(const rho::String& a, const rho::String& b, CMethodResult& oResult)
{
        Platform::String^ _a = rho::common::convertStringToWP8(a);
        Platform::String^ _b = rho::common::convertStringToWP8(b);
    try {
        _runtime->joinStrings(_a, _b, ref new CMethodResultImpl((int64)&oResult));
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
    return new CChatImpl(strID, _impl->getImpl(rho::common::convertStringToWP8(strID)));
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
