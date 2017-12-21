
(function ($, rho, rhoUtil) {
    'use strict';

    var moduleNS = 'Rho.Chat';
    var apiReq = rhoUtil.apiReqFor(moduleNS);


    // === Chat class definition ===

    function Chat() {
        var id = null;
        this.getId = function () {return id;};

        if (1 == arguments.length && arguments[0][rhoUtil.rhoIdParam()]) {
            if (moduleNS != arguments[0][rhoUtil.rhoClassParam()]) {
                throw "Wrong class instantiation!";
            }
            id = arguments[0][rhoUtil.rhoIdParam()];
        } else {
            id = rhoUtil.nextId();
            // constructor methods are following:
            
        }
    };

    // === Chat instance properties ===

    rhoUtil.createPropsProxy(Chat.prototype, [
        { propName: 'simpleStringProperty', propAccess: 'rw' }
    ], apiReq, function(){ return this.getId(); });

    // === Chat instance methods ===

    rhoUtil.createMethodsProxy(Chat.prototype, [
    
          // function(/* const rho::String& */ google_api_key, /* const rho::String& */ google_app_id, /* const rho::String& */ gcm_sender_id, /* const rho::String& */ google_project_id, /* const rho::String& */ google_storage_bucket, /* const rho::String& */ dialogflow_client_access_token, /* const rho::String& */ dialogflow_language, /* optional function */ oResult)
          { methodName: 'init', nativeName: 'init', valueCallbackIndex: 7 }
    
          // function(/* const rho::String& */ propertyName, /* optional function */ oResult)
        , { methodName: 'getProperty', nativeName: 'getProperty', persistentCallbackIndex: 1, valueCallbackIndex: 3 }
    
          // function(/* const rho::Vector<rho::String>& */ arrayofNames, /* optional function */ oResult)
        , { methodName: 'getProperties', nativeName: 'getProperties', persistentCallbackIndex: 1, valueCallbackIndex: 3 }
    
          // function(/* optional function */ oResult)
        , { methodName: 'getAllProperties', nativeName: 'getAllProperties', persistentCallbackIndex: 0, valueCallbackIndex: 2 }
    
          // function(/* const rho::String& */ propertyName, /* const rho::String& */ propertyValue, /* optional function */ oResult)
        , { methodName: 'setProperty', nativeName: 'setProperty', valueCallbackIndex: 2 }
    
          // function(/* const rho::Hashtable<rho::String, rho::String>& */ propertyMap, /* optional function */ oResult)
        , { methodName: 'setProperties', nativeName: 'setProperties', valueCallbackIndex: 1 }
    
    ], apiReq, function(){ return this.getId(); });

    

    rhoUtil.createRawPropsProxy(Chat.prototype, [
    ]);

    // === Chat constants ===

    



    // === Chat static properties ===

    rhoUtil.createPropsProxy(Chat, [
    ], apiReq);

    // === Chat static methods ===

    rhoUtil.createMethodsProxy(Chat, [
    
          // function(/* optional function */ oResult)
          { methodName: 'enumerate', nativeName: 'enumerate', persistentCallbackIndex: 0, valueCallbackIndex: 2 }
    
    ], apiReq);

    // === Chat default instance support ===
    

        rhoUtil.createPropsProxy(Chat, [
            { propName: 'defaultInstance:getDefault:setDefault', propAccess: 'rw', customSet: function(obj) { if(!obj || 'function' != typeof obj.getId){ throw 'Default object should provide getId method!' }; Chat.setDefaultID(obj.getId()); } }
          , { propName: 'defaultID:getDefaultID:setDefaultID', propAccess: 'rw' }
        ], apiReq);

        Chat.getId = function() {
            return Chat.getDefaultID();
        }

        // === Chat default instance properties ===

        rhoUtil.createPropsProxy(Chat, [
            { propName: 'simpleStringProperty', propAccess: 'rw' }
        ], apiReq, function(){ return this.getId(); });

        // === Chat default instance methods ===

        rhoUtil.createMethodsProxy(Chat, [
        
              // function(/* const rho::String& */ google_api_key, /* const rho::String& */ google_app_id, /* const rho::String& */ gcm_sender_id, /* const rho::String& */ google_project_id, /* const rho::String& */ google_storage_bucket, /* const rho::String& */ dialogflow_client_access_token, /* const rho::String& */ dialogflow_language, /* optional function */ oResult)
              { methodName: 'init', nativeName: 'init', valueCallbackIndex: 7 }
        
              // function(/* const rho::String& */ propertyName, /* optional function */ oResult)
            , { methodName: 'getProperty', nativeName: 'getProperty', persistentCallbackIndex: 1, valueCallbackIndex: 3 }
        
              // function(/* const rho::Vector<rho::String>& */ arrayofNames, /* optional function */ oResult)
            , { methodName: 'getProperties', nativeName: 'getProperties', persistentCallbackIndex: 1, valueCallbackIndex: 3 }
        
              // function(/* optional function */ oResult)
            , { methodName: 'getAllProperties', nativeName: 'getAllProperties', persistentCallbackIndex: 0, valueCallbackIndex: 2 }
        
              // function(/* const rho::String& */ propertyName, /* const rho::String& */ propertyValue, /* optional function */ oResult)
            , { methodName: 'setProperty', nativeName: 'setProperty', valueCallbackIndex: 2 }
        
              // function(/* const rho::Hashtable<rho::String, rho::String>& */ propertyMap, /* optional function */ oResult)
            , { methodName: 'setProperties', nativeName: 'setProperties', valueCallbackIndex: 1 }
        
        ], apiReq, function(){ return this.getId(); });

        // will reuse already defined methods
        rhoUtil.createRawPropsProxy(Chat, [
        ]);

    

    rhoUtil.namespace(moduleNS, Chat);

    

    

})(Rho.jQuery, Rho, Rho.util);
