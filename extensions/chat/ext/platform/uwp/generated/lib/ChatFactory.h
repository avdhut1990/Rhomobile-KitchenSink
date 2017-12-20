#pragma once

#include "../../../../shared/generated/cpp/ChatBase.h"
#include "ChatRuntime.h"


namespace rho {
class CChatFactory: public CChatFactoryBase
{
private:
    static rhoruntime::IChatFactoryImpl^ _impl;
public:
    static void setImpl(rhoruntime::IChatFactoryImpl^ impl) { _impl = impl; }
    ~CChatFactory(){}
    virtual IChatSingleton* createModuleSingleton();
    virtual IChat* createModuleByID(const rho::String& strID);
};

}
