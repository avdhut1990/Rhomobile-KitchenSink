
#import "ChatFactoryBase.h"
#import "Chat.h"
#import "ChatSingleton.h"



@implementation ChatFactoryBase

-(id)init {
    self = [super init];
    mChatInstances = [[NSMutableDictionary dictionaryWithCapacity:4] retain];
    mChatSingleton = nil;
    return self;
}

-(id<IChat>) getChatByID:(NSString*)ID {
    id<IChat> obj = (Chat*)[mChatInstances objectForKey:ID];
    if (obj == nil) {
        obj = [self createChatByID:ID];
        [mChatInstances setObject:obj forKey:ID];
    }
    return obj;
}

-(void) destroyObjectByID:(NSString*)ID {
    Chat* obj = [mChatInstances objectForKey:ID];
    if (obj != nil) {
        [mChatInstances removeObjectForKey:ID];
    }
}


-(id<IChat>)createChatByID:(NSString*)ID {
    Chat* obj = [[Chat alloc] init];

    [obj setProperty:@"ID" propertyValue:ID methodResult:nil];

    return obj;
}


-(id<IChatSingleton>) getChatSingleton {
    if (mChatSingleton == nil) {
        mChatSingleton = [[ChatSingleton alloc] init];
    }
    return mChatSingleton;
}

-(NSArray*) enumerateChatInstances {
    return [mChatInstances allKeys];
}

-(void)dealloc {
    [mChatInstances release];
    [super dealloc];
}


@end