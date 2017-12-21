#pragma once

#include "common/RhoStd.h"
#include "api_generator/MethodResult.h"
#include "api_generator/BaseClasses.h"


namespace rho {
///////////////////////////////////////////////////////////



struct IChat
{
//constants


//methods
    virtual ~IChat(){}

    virtual void getSimpleStringProperty(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setSimpleStringProperty( const rho::String& simpleStringProperty, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void init( const rho::String& google_api_key,  const rho::String& google_app_id,  const rho::String& gcm_sender_id,  const rho::String& google_project_id,  const rho::String& google_storage_bucket,  const rho::String& dialogflow_client_access_token,  const rho::String& dialogflow_language, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void getProperty( const rho::String& propertyName, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void getProperties( const rho::Vector<rho::String>& arrayofNames, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void getAllProperties(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setProperty( const rho::String& propertyName,  const rho::String& propertyValue, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setProperties( const rho::Hashtable<rho::String, rho::String>& propertyMap, rho::apiGenerator::CMethodResult& oResult) = 0;

};

struct IChatSingleton
{
//constants


    virtual ~IChatSingleton(){}

//methods
    virtual void enumerate(rho::apiGenerator::CMethodResult& oResult) = 0;


    virtual rho::String getDefaultID() = 0;
    virtual rho::String getInitialDefaultID() = 0;
    virtual void setDefaultID(const rho::String& strID) = 0;

    virtual void addCommandToQueue(rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor) = 0;
    virtual void callCommandInThread(rho::common::IRhoRunnable* pFunctor) = 0;
};

struct IChatFactory
{
    virtual ~IChatFactory(){}

    virtual IChatSingleton* getModuleSingleton() = 0;


    virtual IChat* getModuleByID(const rho::String& strID) = 0;

};


}
