#pragma once

#include "IChat.h"
#include "logging/RhoLog.h"
#include "common/StringConverter.h"
#include "common/ExtManager.h"


namespace rho {

using namespace rho::apiGenerator;
using namespace rho;

// hash keys used in properties and parameters 
namespace chat {

    static const char PROPERTY_SIMPLE_STRING_PROPERTY[] = "simpleStringProperty"; 
 
} 

class CChatFactoryBase : public CModuleFactoryBase<IChat, IChatSingleton, IChatFactory>
{
protected:
    static rho::common::CAutoPtr<CChatFactoryBase> m_pInstance;
    HashtablePtr<rho::String,IChat*> m_hashModules;

public:

    static void setInstance(CChatFactoryBase* pInstance){ m_pInstance = pInstance; }
    static CChatFactoryBase* getInstance(){ return m_pInstance; }

    static IChatSingleton* getChatSingletonS(){ return getInstance()->getModuleSingleton(); }

    virtual IChat* getModuleByID(const rho::String& strID)
    {
        if ( !m_hashModules.containsKey(strID) )
        {
            IChat* pObj = createModuleByID(strID);
            m_hashModules.put(strID, pObj );

            return pObj;
        }

        return m_hashModules[strID];
    }

    virtual IChat* createModuleByID(const rho::String& strID){ return (IChat*)0; };
    virtual void deleteModuleByID(const rho::String& strID)
    {
        m_hashModules.remove(strID);
    }

};

class CChatSingletonBase : public CModuleSingletonBase< IChatSingleton >, public rho::common::IRhoExtension
{
protected:
    DEFINE_LOGCLASS;


    rho::String m_strDefaultID;




public:
    virtual rho::LogCategory getModuleLogCategory(){ return getLogCategory(); }

    CChatSingletonBase();
    ~CChatSingletonBase();




    virtual void setDefaultID(const rho::String& strDefaultID){ m_strDefaultID = strDefaultID; }
    virtual rho::String getDefaultID()
    { 
        if ( m_strDefaultID.length() == 0 )
            setDefaultID(getInitialDefaultID());
        return m_strDefaultID; 
    }

};

class CChatBase: public IChat
{
protected:
    DEFINE_LOGCLASS;


    rho::Hashtable<rho::String, rho::String> m_hashProps;
    rho::Hashtable<rho::String, rho::apiGenerator::CMethodAccessor< IChat > *> m_mapPropAccessors;

public:


    CChatBase();

    virtual void getProperty( const rho::String& propertyName, CMethodResult& oResult);
    virtual void getProperties( const rho::Vector<rho::String>& arrayofNames, CMethodResult& oResult);
    virtual void getAllProperties(CMethodResult& oResult);
    virtual void setProperty( const rho::String& propertyName,  const rho::String& propertyValue, CMethodResult& oResult);
    virtual void setProperties( const rho::Hashtable<rho::String, rho::String>& propertyMap, CMethodResult& oResult);
    virtual void clearAllProperties(CMethodResult& oResult);


    virtual void getSimpleStringProperty(rho::apiGenerator::CMethodResult& oResult);

    virtual void setSimpleStringProperty( const rho::String& simpleStringProperty, rho::apiGenerator::CMethodResult& oResult);


    static CChatBase* getInstance(){ return static_cast< CChatBase* >(CChatFactoryBase::getInstance()->getModuleByID(CChatFactoryBase::getChatSingletonS()->getDefaultID())); }
 

};

extern "C" void Init_Chat_API();


}
