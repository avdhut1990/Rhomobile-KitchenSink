
#import "IChat.h"
#import "ChatSingletonBase.h"

@interface ChatSingleton : ChatSingletonBase<IChatSingleton> {
}


-(NSString*)getInitialDefaultID;


-(void) enumerate:(id<IMethodResult>)methodResult;




@end