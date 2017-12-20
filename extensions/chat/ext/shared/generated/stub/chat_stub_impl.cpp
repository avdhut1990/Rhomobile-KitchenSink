//
//  ChatImpl.cpp
#include "common/RhoStd.h"
#include "common/AutoPointer.h"
#include "common/RhodesApp.h"
#include "common/RhoConf.h"
#include "generated/cpp/ChatBase.h"
#include "logging/RhoLog.h"

namespace rho {
    
    using namespace apiGenerator;
    using namespace common;
    
    class CChatSingletonImpl: public CChatSingletonBase
    {
    public:
        
        CChatSingletonImpl(): CChatSingletonBase(){}
        
        //methods
        // enumerate  
        virtual void enumerate(rho::apiGenerator::CMethodResult& oResult) {
            // RAWLOGC_INFO("enumerate","Chat");
            
        } 

    };
    
    class CChatImpl : public CChatBase
    {
    public:
        virtual ~CChatImpl() {}

        //methods

        virtual void getSimpleStringProperty(rho::apiGenerator::CMethodResult& oResult) {

        } 

        virtual void setSimpleStringProperty( const rho::String& simpleStringProperty, rho::apiGenerator::CMethodResult& oResult) {

        } 

        virtual void init( const rho::String& google_api_key,  const rho::String& google_app_id,  const rho::String& gcm_sender_id,  const rho::String& google_project_id,  const rho::String& google_storage_bucket, rho::apiGenerator::CMethodResult& oResult) {

        } 

        virtual void getProperty( const rho::String& propertyName, rho::apiGenerator::CMethodResult& oResult) {

        } 

        virtual void getProperties( const rho::Vector<rho::String>& arrayofNames, rho::apiGenerator::CMethodResult& oResult) {

        } 

        virtual void getAllProperties(rho::apiGenerator::CMethodResult& oResult) {

        } 

        virtual void setProperty( const rho::String& propertyName,  const rho::String& propertyValue, rho::apiGenerator::CMethodResult& oResult) {

        } 

        virtual void setProperties( const rho::Hashtable<rho::String, rho::String>& propertyMap, rho::apiGenerator::CMethodResult& oResult) {

        } 

    };
    
    ////////////////////////////////////////////////////////////////////////
    
    class CChatFactory: public CChatFactoryBase    {
    public:
        CChatFactory(){}
        
        IChatSingleton* createModuleSingleton()
        { 
            return new CChatSingletonImpl();
        }
        
        virtual IChat* createModuleByID(const rho::String& strID){ return new CChatImpl(); };
        
    };
    
}

extern "C" void Init_Chat_extension()
{
    rho::CChatFactory::setInstance( new rho::CChatFactory() );
    rho::Init_Chat_API();
    
}