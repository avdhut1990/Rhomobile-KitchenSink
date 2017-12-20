
#import "IChat.h"

@interface ChatFactoryBase : NSObject<IChatFactory> {
    NSMutableDictionary* mChatInstances;
    id<IChatSingleton> mChatSingleton;
}

-(id)init;

-(id<IChatSingleton>) getChatSingleton;
-(id<IChat>) getChatByID:(NSString*)ID;

-(void) destroyObjectByID:(NSString*)ID;

-(id<IChat>)createChatByID:(NSString*)ID;

-(NSArray*) enumerateChatInstances;

-(void)dealloc;

@end