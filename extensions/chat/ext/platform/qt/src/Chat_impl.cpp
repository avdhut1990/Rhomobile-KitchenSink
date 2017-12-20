#include "../../../shared/generated/cpp/ChatBase.h"

namespace rho {

using namespace apiGenerator;

class CChatImpl: public CChatBase
{
public:
    CChatImpl(const rho::String& strID): CChatBase()
    {
    }

    virtual void getPlatformName(rho::apiGenerator::CMethodResult& oResult) {
         oResult.set("Win32");
    }

    virtual void calcSumm( int a,  int b, rho::apiGenerator::CMethodResult& oResult) {
         oResult.set(a+b);
    }
    
    virtual void joinStrings( const rho::String& a,  const rho::String& b, rho::apiGenerator::CMethodResult& oResult) {
         oResult.set(a+b);
    }

};

class CChatSingleton: public CChatSingletonBase
{
    ~CChatSingleton(){}
    virtual rho::String getInitialDefaultID();
    virtual void enumerate(CMethodResult& oResult);
};

class CChatFactory: public CChatFactoryBase
{
    ~CChatFactory(){}
    virtual IChatSingleton* createModuleSingleton();
    virtual IChat* createModuleByID(const rho::String& strID);
};

extern "C" void Init_Chat_extension()
{
    CChatFactory::setInstance( new CChatFactory() );
    Init_Chat_API();
}

IChat* CChatFactory::createModuleByID(const rho::String& strID)
{
    return new CChatImpl(strID);
}

IChatSingleton* CChatFactory::createModuleSingleton()
{
    return new CChatSingleton();
}

void CChatSingleton::enumerate(CMethodResult& oResult)
{
    rho::Vector<rho::String> arIDs;
    arIDs.addElement("SC1");
    arIDs.addElement("SC2");

    oResult.set(arIDs);
}

rho::String CChatSingleton::getInitialDefaultID()
{
    CMethodResult oRes;
    enumerate(oRes);

    rho::Vector<rho::String>& arIDs = oRes.getStringArray();
        
    return arIDs[0];
}

}