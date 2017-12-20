#include "ChatBase.h"
#include "common/RhodesApp.h"


namespace rho {

IMPLEMENT_LOGCLASS(CChatSingletonBase, "Chat");
IMPLEMENT_LOGCLASS(CChatBase, "Chat");

rho::common::CAutoPtr< CChatFactoryBase> CChatFactoryBase::m_pInstance;



///////////////////////////////////////
//string constants definiton 

////////////////////////////////////////////////

CChatBase::CChatBase()
{

    m_mapPropAccessors["simpleStringProperty"] = 0;


}

void CChatBase::getProperty( const rho::String& propertyName, CMethodResult& oResult)
{

    oResult.resetToEmptyString();
    CMethodAccessor< IChat >* pAccessor = m_mapPropAccessors[propertyName];
    if ( pAccessor )
        pAccessor->callGetter(this, oResult);
    else
    {

        oResult.set(m_hashProps[propertyName]);

    }
}

void CChatBase::getProperties( const rho::Vector<rho::String>& arrayofNames, CMethodResult& oResult)
{
    rho::Hashtable<rho::String, rho::String> res;
    oResult.setCollectionMode(true);
    for ( int i = 0; i < (int)arrayofNames.size(); i++ )
    {
        getProperty(arrayofNames[i], oResult);

        if ( !oResult.isError() )
        {
            res[arrayofNames[i]] = oResult.toString();
        }
    }
    oResult.setCollectionMode(false);

    oResult.set(res);
}

void CChatBase::getAllProperties(CMethodResult& oResult)
{
    rho::Hashtable<rho::String, rho::String> res;
    oResult.setCollectionMode(true);

    
    // user defined properties
    for ( rho::Hashtable<rho::String, rho::String>::const_iterator it = m_hashProps.begin();  it != m_hashProps.end(); ++it )
    {
        res[it->first] = it->second;
    }
    

    // existing properties
    for ( rho::Hashtable<rho::String, rho::apiGenerator::CMethodAccessor< IChat > *>::const_iterator it = m_mapPropAccessors.begin();  it != m_mapPropAccessors.end(); ++it )
    {
        getProperty(it->first, oResult);
        
        if ( oResult.isError() )
            break;
        
        res[it->first] = oResult.toString();
    }
    
    oResult.setCollectionMode(false);
    if ( oResult.isError() )
        oResult.callCallback();
    else
        oResult.set(res);
}

void CChatBase::setProperty( const rho::String& propertyName,  const rho::String& propertyValue, CMethodResult& oResult)
{
    CMethodAccessor< IChat >* pAccessor = m_mapPropAccessors[propertyName];
    if (pAccessor && pAccessor->hasSetter())
        m_mapPropAccessors[propertyName]->callSetter(this, propertyValue, oResult);
    else
    {
        

        m_hashProps.put(propertyName, propertyValue);
    }
}

void CChatBase::setProperties( const rho::Hashtable<rho::String, rho::String>& propertyMap, CMethodResult& oResult)
{
    for ( rho::Hashtable<rho::String, rho::String>::const_iterator it = propertyMap.begin();  it != propertyMap.end(); ++it )
    {
        setProperty( it->first, it->second, oResult );
        if ( oResult.isError() )
            break;
    }
}

void CChatBase::clearAllProperties(CMethodResult& oResult)
{
    m_hashProps.clear();
    // ToDo: set default values to existing properties 
}



void CChatBase::getSimpleStringProperty(rho::apiGenerator::CMethodResult& oResult)
{ 
    getProperty( "simpleStringProperty", oResult); 
}

void CChatBase::setSimpleStringProperty( const rho::String& simpleStringProperty, rho::apiGenerator::CMethodResult& oResult)
{ 
    setProperty( "simpleStringProperty", rho::common::convertToStringA(simpleStringProperty), oResult );
}
CChatSingletonBase::CChatSingletonBase()
{
    RHODESAPP().getExtManager().registerExtension( "Chat", this );
}

CChatSingletonBase::~CChatSingletonBase()
{
    CChatFactoryBase::setInstance(0);
}


}
