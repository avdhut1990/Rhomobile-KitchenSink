
#import "IChat.h"
//#import "api_generator/common/ruby_helpers.h"

#include "api_generator/js_helpers.h"

#import "api_generator/iphone/CMethodResult.h"
#import "api_generator/iphone/CJSConverter.h"

extern VALUE getRuby_Chat_Module();



id<IChat> Chat_makeInstanceByJSObject(rho::String sid) {
    const char* szID = sid.c_str();
    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    return [factory getChatByID:[NSString stringWithUTF8String:szID]];
}









@interface Chat_getSimpleStringProperty_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IChat> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(Chat_getSimpleStringProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation Chat_getSimpleStringProperty_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(Chat_getSimpleStringProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult {
    Chat_getSimpleStringProperty_caller_params* par = [[[Chat_getSimpleStringProperty_caller_params alloc] init] autorelease];
    par.params = _params;
    par.item = _item;
    par.methodResult = [_methodResult retain];
    return [par retain];
}

@end


@interface Chat_getSimpleStringProperty_caller : NSObject {

}
+(Chat_getSimpleStringProperty_caller*) getSharedInstance;
+(void) getSimpleStringProperty:(Chat_getSimpleStringProperty_caller_params*)caller_params;
+(void) getSimpleStringProperty_in_thread:(Chat_getSimpleStringProperty_caller_params*)caller_params;
+(void) getSimpleStringProperty_in_UI_thread:(Chat_getSimpleStringProperty_caller_params*)caller_params;

@end

static Chat_getSimpleStringProperty_caller* our_Chat_getSimpleStringProperty_caller = nil;

@implementation Chat_getSimpleStringProperty_caller

+(Chat_getSimpleStringProperty_caller*) getSharedInstance {
    if (our_Chat_getSimpleStringProperty_caller == nil) {
        our_Chat_getSimpleStringProperty_caller = [[Chat_getSimpleStringProperty_caller alloc] init];
    }
    return our_Chat_getSimpleStringProperty_caller;
}

-(void) command_getSimpleStringProperty:(Chat_getSimpleStringProperty_caller_params*)caller_params {

    id<IChat> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getSimpleStringProperty:methodResult ];
    [caller_params.methodResult release];
    [caller_params release];
}


+(void) getSimpleStringProperty:(Chat_getSimpleStringProperty_caller_params*)caller_params {
    [[Chat_getSimpleStringProperty_caller getSharedInstance] command_getSimpleStringProperty:caller_params];
}

+(void) getSimpleStringProperty_in_thread:(Chat_getSimpleStringProperty_caller_params*)caller_params {
    [[Chat_getSimpleStringProperty_caller getSharedInstance] performSelectorInBackground:@selector(command_getSimpleStringProperty:) withObject:caller_params];
}

+(void) getSimpleStringProperty_in_UI_thread:(Chat_getSimpleStringProperty_caller_params*)caller_params {
    [[Chat_getSimpleStringProperty_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getSimpleStringProperty:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_Chat_getSimpleStringProperty_Obj(rho::json::CJSONArray& argv, id<IChat>objItem, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    BOOL method_return_result = YES;
    BOOL method_receive_callback = NO;
    int argc = argv.getSize();


    [methodResult setMethodSignature:@"Chat::simpleStringProperty"];

    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = Chat_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
            // TODO: Handle CMethodResultError
            if (params[i] == nil) {
                NSLog(@"Chat::getSimpleStringProperty parameter %d is nil!", i);
                rho::String resValue = rho::String("\"result\":null,\"error\":\"Method parameter is nil!\"");
                return resValue;
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
        if (strCallbackID.size() > 0) {
            method_receive_callback = YES;
        }
    

    

    if (method_receive_callback) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:[NSString stringWithUTF8String:strCallbackID.c_str()] webViewUID:[NSString stringWithUTF8String:strJsVmID.c_str()]];
        [methodResult setCallbackParam:[NSString stringWithUTF8String:strCallbackParam.c_str()]];
        
        [Chat_getSimpleStringProperty_caller getSimpleStringProperty_in_thread:[Chat_getSimpleStringProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        

        // FIXME: callback should not be retained, it must be saved outside of this call
        [methodResult retain];
    }
    else {
        // we do not have callback
        
        [Chat_getSimpleStringProperty_caller getSimpleStringProperty:[Chat_getSimpleStringProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = rho::String("\"result\":null");
    if ((!method_receive_callback) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    [methodResult release];
    return resValue;
}


rho::String js_Chat_getSimpleStringProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    id<IChat> item = Chat_makeInstanceByJSObject(strObjID);
    return js_Chat_getSimpleStringProperty_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);

}

rho::String js_s_Chat_def_getSimpleStringProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {
    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    id<IChatSingleton> singleton = [factory getChatSingleton];

    NSString* defID = [singleton getDefaultID];

    id<IChat> item = [factory getChatByID:defID];
    return js_Chat_getSimpleStringProperty_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);
}







@interface Chat_setSimpleStringProperty_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IChat> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(Chat_setSimpleStringProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation Chat_setSimpleStringProperty_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(Chat_setSimpleStringProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult {
    Chat_setSimpleStringProperty_caller_params* par = [[[Chat_setSimpleStringProperty_caller_params alloc] init] autorelease];
    par.params = _params;
    par.item = _item;
    par.methodResult = [_methodResult retain];
    return [par retain];
}

@end


@interface Chat_setSimpleStringProperty_caller : NSObject {

}
+(Chat_setSimpleStringProperty_caller*) getSharedInstance;
+(void) setSimpleStringProperty:(Chat_setSimpleStringProperty_caller_params*)caller_params;
+(void) setSimpleStringProperty_in_thread:(Chat_setSimpleStringProperty_caller_params*)caller_params;
+(void) setSimpleStringProperty_in_UI_thread:(Chat_setSimpleStringProperty_caller_params*)caller_params;

@end

static Chat_setSimpleStringProperty_caller* our_Chat_setSimpleStringProperty_caller = nil;

@implementation Chat_setSimpleStringProperty_caller

+(Chat_setSimpleStringProperty_caller*) getSharedInstance {
    if (our_Chat_setSimpleStringProperty_caller == nil) {
        our_Chat_setSimpleStringProperty_caller = [[Chat_setSimpleStringProperty_caller alloc] init];
    }
    return our_Chat_setSimpleStringProperty_caller;
}

-(void) command_setSimpleStringProperty:(Chat_setSimpleStringProperty_caller_params*)caller_params {

    NSArray* params = caller_params.params;

    id<IChat> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setSimpleStringProperty:(NSString*)[params objectAtIndex:0] methodResult:methodResult ];
    [caller_params.methodResult release];
    [caller_params release];
}


+(void) setSimpleStringProperty:(Chat_setSimpleStringProperty_caller_params*)caller_params {
    [[Chat_setSimpleStringProperty_caller getSharedInstance] command_setSimpleStringProperty:caller_params];
}

+(void) setSimpleStringProperty_in_thread:(Chat_setSimpleStringProperty_caller_params*)caller_params {
    [[Chat_setSimpleStringProperty_caller getSharedInstance] performSelectorInBackground:@selector(command_setSimpleStringProperty:) withObject:caller_params];
}

+(void) setSimpleStringProperty_in_UI_thread:(Chat_setSimpleStringProperty_caller_params*)caller_params {
    [[Chat_setSimpleStringProperty_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setSimpleStringProperty:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_Chat_setSimpleStringProperty_Obj(rho::json::CJSONArray& argv, id<IChat>objItem, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    BOOL method_return_result = YES;
    BOOL method_receive_callback = NO;
    int argc = argv.getSize();


    [methodResult setMethodSignature:@"Chat::simpleStringProperty="];

    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "simpleStringProperty", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = Chat_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
            // TODO: Handle CMethodResultError
            if (params[i] == nil) {
                NSLog(@"Chat::setSimpleStringProperty parameter %d is nil!", i);
                rho::String resValue = rho::String("\"result\":null,\"error\":\"Method parameter is nil!\"");
                return resValue;
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
        if (strCallbackID.size() > 0) {
            method_receive_callback = YES;
        }
    

    

    if (method_receive_callback) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:[NSString stringWithUTF8String:strCallbackID.c_str()] webViewUID:[NSString stringWithUTF8String:strJsVmID.c_str()]];
        [methodResult setCallbackParam:[NSString stringWithUTF8String:strCallbackParam.c_str()]];
        
        [Chat_setSimpleStringProperty_caller setSimpleStringProperty_in_thread:[Chat_setSimpleStringProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        

        // FIXME: callback should not be retained, it must be saved outside of this call
        [methodResult retain];
    }
    else {
        // we do not have callback
        
        [Chat_setSimpleStringProperty_caller setSimpleStringProperty:[Chat_setSimpleStringProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = rho::String("\"result\":null");
    if ((!method_receive_callback) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    [methodResult release];
    return resValue;
}


rho::String js_Chat_setSimpleStringProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    id<IChat> item = Chat_makeInstanceByJSObject(strObjID);
    return js_Chat_setSimpleStringProperty_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);

}

rho::String js_s_Chat_def_setSimpleStringProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {
    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    id<IChatSingleton> singleton = [factory getChatSingleton];

    NSString* defID = [singleton getDefaultID];

    id<IChat> item = [factory getChatByID:defID];
    return js_Chat_setSimpleStringProperty_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);
}







@interface Chat_enumerate_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IChatSingleton> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(Chat_enumerate_caller_params*) makeParams:(NSArray*)_params _item:(id<IChatSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation Chat_enumerate_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(Chat_enumerate_caller_params*) makeParams:(NSArray*)_params _item:(id<IChatSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    Chat_enumerate_caller_params* par = [[[Chat_enumerate_caller_params alloc] init] autorelease];
    par.params = _params;
    par.item = _item;
    par.methodResult = [_methodResult retain];
    return [par retain];
}

@end


@interface Chat_enumerate_caller : NSObject {

}
+(Chat_enumerate_caller*) getSharedInstance;
+(void) enumerate:(Chat_enumerate_caller_params*)caller_params;
+(void) enumerate_in_thread:(Chat_enumerate_caller_params*)caller_params;
+(void) enumerate_in_UI_thread:(Chat_enumerate_caller_params*)caller_params;

@end

static Chat_enumerate_caller* our_Chat_enumerate_caller = nil;

@implementation Chat_enumerate_caller

+(Chat_enumerate_caller*) getSharedInstance {
    if (our_Chat_enumerate_caller == nil) {
        our_Chat_enumerate_caller = [[Chat_enumerate_caller alloc] init];
    }
    return our_Chat_enumerate_caller;
}

-(void) command_enumerate:(Chat_enumerate_caller_params*)caller_params {

    id<IChatSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem enumerate:methodResult ];
    [caller_params.methodResult release];
    [caller_params release];
}


+(void) enumerate:(Chat_enumerate_caller_params*)caller_params {
    [[Chat_enumerate_caller getSharedInstance] command_enumerate:caller_params];
}

+(void) enumerate_in_thread:(Chat_enumerate_caller_params*)caller_params {
    [[Chat_enumerate_caller getSharedInstance] performSelectorInBackground:@selector(command_enumerate:) withObject:caller_params];
}

+(void) enumerate_in_UI_thread:(Chat_enumerate_caller_params*)caller_params {
    [[Chat_enumerate_caller getSharedInstance] performSelectorOnMainThread:@selector(command_enumerate:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_Chat_enumerate_Obj(rho::json::CJSONArray& argv, id<IChatSingleton>objItem, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    BOOL method_return_result = YES;
    BOOL method_receive_callback = NO;
    int argc = argv.getSize();


    [methodResult setMethodSignature:@"Chat::enumerate"];

    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = Chat_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
            // TODO: Handle CMethodResultError
            if (params[i] == nil) {
                NSLog(@"Chat::enumerate parameter %d is nil!", i);
                rho::String resValue = rho::String("\"result\":null,\"error\":\"Method parameter is nil!\"");
                return resValue;
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
        if (strCallbackID.size() > 0) {
            method_receive_callback = YES;
        }
    

    [methodResult enableObjectCreationModeWithJSClassPath:@"Rho.Chat"];

    if (method_receive_callback) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:[NSString stringWithUTF8String:strCallbackID.c_str()] webViewUID:[NSString stringWithUTF8String:strJsVmID.c_str()]];
        [methodResult setCallbackParam:[NSString stringWithUTF8String:strCallbackParam.c_str()]];
        
        [Chat_enumerate_caller enumerate_in_thread:[Chat_enumerate_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        

        // FIXME: callback should not be retained, it must be saved outside of this call
        [methodResult retain];
    }
    else {
        // we do not have callback
        
        [Chat_enumerate_caller enumerate:[Chat_enumerate_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = rho::String("\"result\":null");
    if ((!method_receive_callback) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    [methodResult release];
    return resValue;
}


rho::String js_s_Chat_enumerate(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    id<IChatSingleton> singleton = [factory getChatSingleton];
    return js_Chat_enumerate_Obj(argv, singleton, strCallbackID, strJsVmID, strCallbackParam);

}







@interface Chat_init_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IChat> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(Chat_init_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation Chat_init_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(Chat_init_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult {
    Chat_init_caller_params* par = [[[Chat_init_caller_params alloc] init] autorelease];
    par.params = _params;
    par.item = _item;
    par.methodResult = [_methodResult retain];
    return [par retain];
}

@end


@interface Chat_init_caller : NSObject {

}
+(Chat_init_caller*) getSharedInstance;
+(void) init:(Chat_init_caller_params*)caller_params;
+(void) init_in_thread:(Chat_init_caller_params*)caller_params;
+(void) init_in_UI_thread:(Chat_init_caller_params*)caller_params;

@end

static Chat_init_caller* our_Chat_init_caller = nil;

@implementation Chat_init_caller

+(Chat_init_caller*) getSharedInstance {
    if (our_Chat_init_caller == nil) {
        our_Chat_init_caller = [[Chat_init_caller alloc] init];
    }
    return our_Chat_init_caller;
}

-(void) command_init:(Chat_init_caller_params*)caller_params {

    NSArray* params = caller_params.params;

    id<IChat> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem init:(NSString*)[params objectAtIndex:0] google_app_id:(NSString*)[params objectAtIndex:1] gcm_sender_id:(NSString*)[params objectAtIndex:2] google_project_id:(NSString*)[params objectAtIndex:3] google_storage_bucket:(NSString*)[params objectAtIndex:4] methodResult:methodResult ];
    [caller_params.methodResult release];
    [caller_params release];
}


+(void) init:(Chat_init_caller_params*)caller_params {
    [[Chat_init_caller getSharedInstance] command_init:caller_params];
}

+(void) init_in_thread:(Chat_init_caller_params*)caller_params {
    [[Chat_init_caller getSharedInstance] performSelectorInBackground:@selector(command_init:) withObject:caller_params];
}

+(void) init_in_UI_thread:(Chat_init_caller_params*)caller_params {
    [[Chat_init_caller getSharedInstance] performSelectorOnMainThread:@selector(command_init:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_Chat_init_Obj(rho::json::CJSONArray& argv, id<IChat>objItem, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[5+1];
    BOOL method_return_result = YES;
    BOOL method_receive_callback = NO;
    int argc = argv.getSize();


    [methodResult setMethodSignature:@"Chat::init"];

    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "google_api_key", 0, 0 }, {RHO_API_STRING, 0, "google_app_id", 0, 0 }, {RHO_API_STRING, 0, "gcm_sender_id", 0, 0 }, {RHO_API_STRING, 0, "google_project_id", 0, 0 }, {RHO_API_STRING, 0, "google_storage_bucket", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO, NO, NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (5); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    

    // enumerate params
    for (int i = 0; i < (5); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = Chat_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
            // TODO: Handle CMethodResultError
            if (params[i] == nil) {
                NSLog(@"Chat::init parameter %d is nil!", i);
                rho::String resValue = rho::String("\"result\":null,\"error\":\"Method parameter is nil!\"");
                return resValue;
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(5)];
    for (i = 0 ; i < (5); i++) {
        [params_array addObject:params[i]];
    }

    
        if (strCallbackID.size() > 0) {
            method_receive_callback = YES;
        }
    

    

    if (method_receive_callback) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:[NSString stringWithUTF8String:strCallbackID.c_str()] webViewUID:[NSString stringWithUTF8String:strJsVmID.c_str()]];
        [methodResult setCallbackParam:[NSString stringWithUTF8String:strCallbackParam.c_str()]];
        
        [Chat_init_caller init_in_thread:[Chat_init_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        

        // FIXME: callback should not be retained, it must be saved outside of this call
        [methodResult retain];
    }
    else {
        // we do not have callback
        
        [Chat_init_caller init:[Chat_init_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = rho::String("\"result\":null");
    if ((!method_receive_callback) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    [methodResult release];
    return resValue;
}


rho::String js_Chat_init(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    id<IChat> item = Chat_makeInstanceByJSObject(strObjID);
    return js_Chat_init_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);

}

rho::String js_s_Chat_def_init(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {
    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    id<IChatSingleton> singleton = [factory getChatSingleton];

    NSString* defID = [singleton getDefaultID];

    id<IChat> item = [factory getChatByID:defID];
    return js_Chat_init_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);
}







@interface Chat_getProperty_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IChat> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(Chat_getProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation Chat_getProperty_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(Chat_getProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult {
    Chat_getProperty_caller_params* par = [[[Chat_getProperty_caller_params alloc] init] autorelease];
    par.params = _params;
    par.item = _item;
    par.methodResult = [_methodResult retain];
    return [par retain];
}

@end


@interface Chat_getProperty_caller : NSObject {

}
+(Chat_getProperty_caller*) getSharedInstance;
+(void) getProperty:(Chat_getProperty_caller_params*)caller_params;
+(void) getProperty_in_thread:(Chat_getProperty_caller_params*)caller_params;
+(void) getProperty_in_UI_thread:(Chat_getProperty_caller_params*)caller_params;

@end

static Chat_getProperty_caller* our_Chat_getProperty_caller = nil;

@implementation Chat_getProperty_caller

+(Chat_getProperty_caller*) getSharedInstance {
    if (our_Chat_getProperty_caller == nil) {
        our_Chat_getProperty_caller = [[Chat_getProperty_caller alloc] init];
    }
    return our_Chat_getProperty_caller;
}

-(void) command_getProperty:(Chat_getProperty_caller_params*)caller_params {

    NSArray* params = caller_params.params;

    id<IChat> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getProperty:(NSString*)[params objectAtIndex:0] methodResult:methodResult ];
    [caller_params.methodResult release];
    [caller_params release];
}


+(void) getProperty:(Chat_getProperty_caller_params*)caller_params {
    [[Chat_getProperty_caller getSharedInstance] command_getProperty:caller_params];
}

+(void) getProperty_in_thread:(Chat_getProperty_caller_params*)caller_params {
    [[Chat_getProperty_caller getSharedInstance] performSelectorInBackground:@selector(command_getProperty:) withObject:caller_params];
}

+(void) getProperty_in_UI_thread:(Chat_getProperty_caller_params*)caller_params {
    [[Chat_getProperty_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getProperty:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_Chat_getProperty_Obj(rho::json::CJSONArray& argv, id<IChat>objItem, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    BOOL method_return_result = YES;
    BOOL method_receive_callback = NO;
    int argc = argv.getSize();


    [methodResult setMethodSignature:@"Chat::getProperty"];

    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "propertyName", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = Chat_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
            // TODO: Handle CMethodResultError
            if (params[i] == nil) {
                NSLog(@"Chat::getProperty parameter %d is nil!", i);
                rho::String resValue = rho::String("\"result\":null,\"error\":\"Method parameter is nil!\"");
                return resValue;
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
        if (strCallbackID.size() > 0) {
            method_receive_callback = YES;
        }
    

    

    if (method_receive_callback) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:[NSString stringWithUTF8String:strCallbackID.c_str()] webViewUID:[NSString stringWithUTF8String:strJsVmID.c_str()]];
        [methodResult setCallbackParam:[NSString stringWithUTF8String:strCallbackParam.c_str()]];
        
        [Chat_getProperty_caller getProperty_in_thread:[Chat_getProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        

        // FIXME: callback should not be retained, it must be saved outside of this call
        [methodResult retain];
    }
    else {
        // we do not have callback
        
        [Chat_getProperty_caller getProperty:[Chat_getProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = rho::String("\"result\":null");
    if ((!method_receive_callback) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    [methodResult release];
    return resValue;
}


rho::String js_Chat_getProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    id<IChat> item = Chat_makeInstanceByJSObject(strObjID);
    return js_Chat_getProperty_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);

}

rho::String js_s_Chat_def_getProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {
    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    id<IChatSingleton> singleton = [factory getChatSingleton];

    NSString* defID = [singleton getDefaultID];

    id<IChat> item = [factory getChatByID:defID];
    return js_Chat_getProperty_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);
}







@interface Chat_getProperties_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IChat> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(Chat_getProperties_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation Chat_getProperties_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(Chat_getProperties_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult {
    Chat_getProperties_caller_params* par = [[[Chat_getProperties_caller_params alloc] init] autorelease];
    par.params = _params;
    par.item = _item;
    par.methodResult = [_methodResult retain];
    return [par retain];
}

@end


@interface Chat_getProperties_caller : NSObject {

}
+(Chat_getProperties_caller*) getSharedInstance;
+(void) getProperties:(Chat_getProperties_caller_params*)caller_params;
+(void) getProperties_in_thread:(Chat_getProperties_caller_params*)caller_params;
+(void) getProperties_in_UI_thread:(Chat_getProperties_caller_params*)caller_params;

@end

static Chat_getProperties_caller* our_Chat_getProperties_caller = nil;

@implementation Chat_getProperties_caller

+(Chat_getProperties_caller*) getSharedInstance {
    if (our_Chat_getProperties_caller == nil) {
        our_Chat_getProperties_caller = [[Chat_getProperties_caller alloc] init];
    }
    return our_Chat_getProperties_caller;
}

-(void) command_getProperties:(Chat_getProperties_caller_params*)caller_params {

    NSArray* params = caller_params.params;

    id<IChat> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getProperties:(NSArray*)[params objectAtIndex:0] methodResult:methodResult ];
    [caller_params.methodResult release];
    [caller_params release];
}


+(void) getProperties:(Chat_getProperties_caller_params*)caller_params {
    [[Chat_getProperties_caller getSharedInstance] command_getProperties:caller_params];
}

+(void) getProperties_in_thread:(Chat_getProperties_caller_params*)caller_params {
    [[Chat_getProperties_caller getSharedInstance] performSelectorInBackground:@selector(command_getProperties:) withObject:caller_params];
}

+(void) getProperties_in_UI_thread:(Chat_getProperties_caller_params*)caller_params {
    [[Chat_getProperties_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getProperties:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_Chat_getProperties_Obj(rho::json::CJSONArray& argv, id<IChat>objItem, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    BOOL method_return_result = YES;
    BOOL method_receive_callback = NO;
    int argc = argv.getSize();


    [methodResult setMethodSignature:@"Chat::getProperties"];

    
    static RHO_API_PARAM rho_api_params_param0[] = { {RHO_API_STRING, 0, "array_param", 0, 0 } };
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_ARRAY, 0, "arrayofNames", 1, rho_api_params_param0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = Chat_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
            // TODO: Handle CMethodResultError
            if (params[i] == nil) {
                NSLog(@"Chat::getProperties parameter %d is nil!", i);
                rho::String resValue = rho::String("\"result\":null,\"error\":\"Method parameter is nil!\"");
                return resValue;
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
        if (strCallbackID.size() > 0) {
            method_receive_callback = YES;
        }
    

    

    if (method_receive_callback) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:[NSString stringWithUTF8String:strCallbackID.c_str()] webViewUID:[NSString stringWithUTF8String:strJsVmID.c_str()]];
        [methodResult setCallbackParam:[NSString stringWithUTF8String:strCallbackParam.c_str()]];
        
        [Chat_getProperties_caller getProperties_in_thread:[Chat_getProperties_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        

        // FIXME: callback should not be retained, it must be saved outside of this call
        [methodResult retain];
    }
    else {
        // we do not have callback
        
        [Chat_getProperties_caller getProperties:[Chat_getProperties_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = rho::String("\"result\":null");
    if ((!method_receive_callback) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    [methodResult release];
    return resValue;
}


rho::String js_Chat_getProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    id<IChat> item = Chat_makeInstanceByJSObject(strObjID);
    return js_Chat_getProperties_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);

}

rho::String js_s_Chat_def_getProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {
    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    id<IChatSingleton> singleton = [factory getChatSingleton];

    NSString* defID = [singleton getDefaultID];

    id<IChat> item = [factory getChatByID:defID];
    return js_Chat_getProperties_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);
}







@interface Chat_getAllProperties_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IChat> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(Chat_getAllProperties_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation Chat_getAllProperties_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(Chat_getAllProperties_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult {
    Chat_getAllProperties_caller_params* par = [[[Chat_getAllProperties_caller_params alloc] init] autorelease];
    par.params = _params;
    par.item = _item;
    par.methodResult = [_methodResult retain];
    return [par retain];
}

@end


@interface Chat_getAllProperties_caller : NSObject {

}
+(Chat_getAllProperties_caller*) getSharedInstance;
+(void) getAllProperties:(Chat_getAllProperties_caller_params*)caller_params;
+(void) getAllProperties_in_thread:(Chat_getAllProperties_caller_params*)caller_params;
+(void) getAllProperties_in_UI_thread:(Chat_getAllProperties_caller_params*)caller_params;

@end

static Chat_getAllProperties_caller* our_Chat_getAllProperties_caller = nil;

@implementation Chat_getAllProperties_caller

+(Chat_getAllProperties_caller*) getSharedInstance {
    if (our_Chat_getAllProperties_caller == nil) {
        our_Chat_getAllProperties_caller = [[Chat_getAllProperties_caller alloc] init];
    }
    return our_Chat_getAllProperties_caller;
}

-(void) command_getAllProperties:(Chat_getAllProperties_caller_params*)caller_params {

    id<IChat> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getAllProperties:methodResult ];
    [caller_params.methodResult release];
    [caller_params release];
}


+(void) getAllProperties:(Chat_getAllProperties_caller_params*)caller_params {
    [[Chat_getAllProperties_caller getSharedInstance] command_getAllProperties:caller_params];
}

+(void) getAllProperties_in_thread:(Chat_getAllProperties_caller_params*)caller_params {
    [[Chat_getAllProperties_caller getSharedInstance] performSelectorInBackground:@selector(command_getAllProperties:) withObject:caller_params];
}

+(void) getAllProperties_in_UI_thread:(Chat_getAllProperties_caller_params*)caller_params {
    [[Chat_getAllProperties_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getAllProperties:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_Chat_getAllProperties_Obj(rho::json::CJSONArray& argv, id<IChat>objItem, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    BOOL method_return_result = YES;
    BOOL method_receive_callback = NO;
    int argc = argv.getSize();


    [methodResult setMethodSignature:@"Chat::getAllProperties"];

    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = Chat_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
            // TODO: Handle CMethodResultError
            if (params[i] == nil) {
                NSLog(@"Chat::getAllProperties parameter %d is nil!", i);
                rho::String resValue = rho::String("\"result\":null,\"error\":\"Method parameter is nil!\"");
                return resValue;
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
        if (strCallbackID.size() > 0) {
            method_receive_callback = YES;
        }
    

    

    if (method_receive_callback) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:[NSString stringWithUTF8String:strCallbackID.c_str()] webViewUID:[NSString stringWithUTF8String:strJsVmID.c_str()]];
        [methodResult setCallbackParam:[NSString stringWithUTF8String:strCallbackParam.c_str()]];
        
        [Chat_getAllProperties_caller getAllProperties_in_thread:[Chat_getAllProperties_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        

        // FIXME: callback should not be retained, it must be saved outside of this call
        [methodResult retain];
    }
    else {
        // we do not have callback
        
        [Chat_getAllProperties_caller getAllProperties:[Chat_getAllProperties_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = rho::String("\"result\":null");
    if ((!method_receive_callback) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    [methodResult release];
    return resValue;
}


rho::String js_Chat_getAllProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    id<IChat> item = Chat_makeInstanceByJSObject(strObjID);
    return js_Chat_getAllProperties_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);

}

rho::String js_s_Chat_def_getAllProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {
    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    id<IChatSingleton> singleton = [factory getChatSingleton];

    NSString* defID = [singleton getDefaultID];

    id<IChat> item = [factory getChatByID:defID];
    return js_Chat_getAllProperties_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);
}







@interface Chat_setProperty_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IChat> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(Chat_setProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation Chat_setProperty_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(Chat_setProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult {
    Chat_setProperty_caller_params* par = [[[Chat_setProperty_caller_params alloc] init] autorelease];
    par.params = _params;
    par.item = _item;
    par.methodResult = [_methodResult retain];
    return [par retain];
}

@end


@interface Chat_setProperty_caller : NSObject {

}
+(Chat_setProperty_caller*) getSharedInstance;
+(void) setProperty:(Chat_setProperty_caller_params*)caller_params;
+(void) setProperty_in_thread:(Chat_setProperty_caller_params*)caller_params;
+(void) setProperty_in_UI_thread:(Chat_setProperty_caller_params*)caller_params;

@end

static Chat_setProperty_caller* our_Chat_setProperty_caller = nil;

@implementation Chat_setProperty_caller

+(Chat_setProperty_caller*) getSharedInstance {
    if (our_Chat_setProperty_caller == nil) {
        our_Chat_setProperty_caller = [[Chat_setProperty_caller alloc] init];
    }
    return our_Chat_setProperty_caller;
}

-(void) command_setProperty:(Chat_setProperty_caller_params*)caller_params {

    NSArray* params = caller_params.params;

    id<IChat> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setProperty:(NSString*)[params objectAtIndex:0] propertyValue:(NSString*)[params objectAtIndex:1] methodResult:methodResult ];
    [caller_params.methodResult release];
    [caller_params release];
}


+(void) setProperty:(Chat_setProperty_caller_params*)caller_params {
    [[Chat_setProperty_caller getSharedInstance] command_setProperty:caller_params];
}

+(void) setProperty_in_thread:(Chat_setProperty_caller_params*)caller_params {
    [[Chat_setProperty_caller getSharedInstance] performSelectorInBackground:@selector(command_setProperty:) withObject:caller_params];
}

+(void) setProperty_in_UI_thread:(Chat_setProperty_caller_params*)caller_params {
    [[Chat_setProperty_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setProperty:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_Chat_setProperty_Obj(rho::json::CJSONArray& argv, id<IChat>objItem, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[2+1];
    BOOL method_return_result = YES;
    BOOL method_receive_callback = NO;
    int argc = argv.getSize();


    [methodResult setMethodSignature:@"Chat::setProperty"];

    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "propertyName", 0, 0 }, {RHO_API_STRING, 0, "propertyValue", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (2); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    

    // enumerate params
    for (int i = 0; i < (2); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = Chat_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
            // TODO: Handle CMethodResultError
            if (params[i] == nil) {
                NSLog(@"Chat::setProperty parameter %d is nil!", i);
                rho::String resValue = rho::String("\"result\":null,\"error\":\"Method parameter is nil!\"");
                return resValue;
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(2)];
    for (i = 0 ; i < (2); i++) {
        [params_array addObject:params[i]];
    }

    
        if (strCallbackID.size() > 0) {
            method_receive_callback = YES;
        }
    

    

    if (method_receive_callback) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:[NSString stringWithUTF8String:strCallbackID.c_str()] webViewUID:[NSString stringWithUTF8String:strJsVmID.c_str()]];
        [methodResult setCallbackParam:[NSString stringWithUTF8String:strCallbackParam.c_str()]];
        
        [Chat_setProperty_caller setProperty_in_thread:[Chat_setProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        

        // FIXME: callback should not be retained, it must be saved outside of this call
        [methodResult retain];
    }
    else {
        // we do not have callback
        
        [Chat_setProperty_caller setProperty:[Chat_setProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = rho::String("\"result\":null");
    if ((!method_receive_callback) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    [methodResult release];
    return resValue;
}


rho::String js_Chat_setProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    id<IChat> item = Chat_makeInstanceByJSObject(strObjID);
    return js_Chat_setProperty_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);

}

rho::String js_s_Chat_def_setProperty(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {
    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    id<IChatSingleton> singleton = [factory getChatSingleton];

    NSString* defID = [singleton getDefaultID];

    id<IChat> item = [factory getChatByID:defID];
    return js_Chat_setProperty_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);
}







@interface Chat_setProperties_caller_params : NSObject

@property (nonatomic, copy) NSArray* params;
@property (assign) id<IChat> item;
@property (assign) CMethodResult* methodResult;

-(void)dealloc;

+(Chat_setProperties_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation Chat_setProperties_caller_params

@synthesize params,item,methodResult;

-(void)dealloc {
    [params release];
    [super dealloc];
}

+(Chat_setProperties_caller_params*) makeParams:(NSArray*)_params _item:(id<IChat>)_item _methodResult:(CMethodResult*)_methodResult {
    Chat_setProperties_caller_params* par = [[[Chat_setProperties_caller_params alloc] init] autorelease];
    par.params = _params;
    par.item = _item;
    par.methodResult = [_methodResult retain];
    return [par retain];
}

@end


@interface Chat_setProperties_caller : NSObject {

}
+(Chat_setProperties_caller*) getSharedInstance;
+(void) setProperties:(Chat_setProperties_caller_params*)caller_params;
+(void) setProperties_in_thread:(Chat_setProperties_caller_params*)caller_params;
+(void) setProperties_in_UI_thread:(Chat_setProperties_caller_params*)caller_params;

@end

static Chat_setProperties_caller* our_Chat_setProperties_caller = nil;

@implementation Chat_setProperties_caller

+(Chat_setProperties_caller*) getSharedInstance {
    if (our_Chat_setProperties_caller == nil) {
        our_Chat_setProperties_caller = [[Chat_setProperties_caller alloc] init];
    }
    return our_Chat_setProperties_caller;
}

-(void) command_setProperties:(Chat_setProperties_caller_params*)caller_params {

    NSArray* params = caller_params.params;

    id<IChat> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setProperties:(NSDictionary*)[params objectAtIndex:0] methodResult:methodResult ];
    [caller_params.methodResult release];
    [caller_params release];
}


+(void) setProperties:(Chat_setProperties_caller_params*)caller_params {
    [[Chat_setProperties_caller getSharedInstance] command_setProperties:caller_params];
}

+(void) setProperties_in_thread:(Chat_setProperties_caller_params*)caller_params {
    [[Chat_setProperties_caller getSharedInstance] performSelectorInBackground:@selector(command_setProperties:) withObject:caller_params];
}

+(void) setProperties_in_UI_thread:(Chat_setProperties_caller_params*)caller_params {
    [[Chat_setProperties_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setProperties:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_Chat_setProperties_Obj(rho::json::CJSONArray& argv, id<IChat>objItem, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    BOOL method_return_result = YES;
    BOOL method_receive_callback = NO;
    int argc = argv.getSize();


    [methodResult setMethodSignature:@"Chat::setProperties"];

    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_HASH, 0, "propertyMap", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = Chat_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
            // TODO: Handle CMethodResultError
            if (params[i] == nil) {
                NSLog(@"Chat::setProperties parameter %d is nil!", i);
                rho::String resValue = rho::String("\"result\":null,\"error\":\"Method parameter is nil!\"");
                return resValue;
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
        if (strCallbackID.size() > 0) {
            method_receive_callback = YES;
        }
    

    

    if (method_receive_callback) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:[NSString stringWithUTF8String:strCallbackID.c_str()] webViewUID:[NSString stringWithUTF8String:strJsVmID.c_str()]];
        [methodResult setCallbackParam:[NSString stringWithUTF8String:strCallbackParam.c_str()]];
        
        [Chat_setProperties_caller setProperties_in_thread:[Chat_setProperties_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        

        // FIXME: callback should not be retained, it must be saved outside of this call
        [methodResult retain];
    }
    else {
        // we do not have callback
        
        [Chat_setProperties_caller setProperties:[Chat_setProperties_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = rho::String("\"result\":null");
    if ((!method_receive_callback) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    [methodResult release];
    return resValue;
}


rho::String js_Chat_setProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {

    id<IChat> item = Chat_makeInstanceByJSObject(strObjID);
    return js_Chat_setProperties_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);

}

rho::String js_s_Chat_def_setProperties(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam) {
    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    id<IChatSingleton> singleton = [factory getChatSingleton];

    NSString* defID = [singleton getDefaultID];

    id<IChat> item = [factory getChatByID:defID];
    return js_Chat_setProperties_Obj(argv, item, strCallbackID, strJsVmID, strCallbackParam);
}







rho::String js_s_Chat_getDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    id<IChatSingleton> singleton = [factory getChatSingleton];

    NSString* defID = [singleton getDefaultID];

    rho::String res =  [[CJSConverter convertToJS:defID level:0] UTF8String];

    return res;
}

rho::String js_s_Chat_getDefault(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    id<IChatSingleton> singleton = [factory getChatSingleton];

    NSString* defID = [singleton getDefaultID];

    rho::String res =  [[CJSConverter convertToJS:[CRhoAPIClassInstance rubyClassByName:@"Rho.Chat" instanceID:defID] level:0] UTF8String];

    return res;
}

rho::String js_s_Chat_setDefaultID(const rho::String& strObjID, rho::json::CJSONArray& argv, const rho::String& strCallbackID, const rho::String& strJsVmID, const rho::String& strCallbackParam)
{
    id<IChatFactory> factory = [ChatFactorySingleton getChatFactoryInstance];
    id<IChatSingleton> singleton = [factory getChatSingleton];

    rho::json::CJSONEntry el = argv[0];

    if (el.isString()) {
        NSString* defID = [NSString stringWithUTF8String:(el.getString())];

        [singleton setDefaultID:defID];

        return [[CJSConverter convertToJS:nil level:0] UTF8String];
    }

    return "\"result\":null,\"error\":\"Method parameter should be defined as string!\"";
}



