
#import "IChat.h"
#import "ChatFactoryBase.h"

static ChatFactoryBase* ourChatFactory = nil;

@implementation ChatFactorySingleton

+(id<IChatFactory>) getChatFactoryInstance {
    if (ourChatFactory == nil) {
        ourChatFactory = [[ChatFactoryBase alloc] init];
    }
    return ourChatFactory;
}

@end