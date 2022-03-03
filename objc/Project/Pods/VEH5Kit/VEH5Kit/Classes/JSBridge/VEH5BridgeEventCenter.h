//
//  VEH5BridgeEventCenter.h
//  VEH5BridgeEventCenter
//
//  Created by lixiaopeng on 2021/4/21.
//

#import <Foundation/Foundation.h>
#import "VEH5BridgeEvent.h"
NS_ASSUME_NONNULL_BEGIN

@interface VEH5BridgeEventCenter : NSObject
+ (instancetype)sharedInstance;
- (void)publishEvent:(VEH5BridgeEvent *)event;
@end

NS_ASSUME_NONNULL_END
