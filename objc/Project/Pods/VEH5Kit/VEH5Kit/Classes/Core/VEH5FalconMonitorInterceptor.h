//
//  VEH5FalconMonitorInterceptor.h
//  VEH5Kit
//
//  Created by lixiaopeng on 2021/5/23.
//

#import <Foundation/Foundation.h>
#import <BDWebKitToB/IESFalconManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface VEH5FalconMonitorInterceptor : NSObject <IESFalconMonitorInterceptor>
@property (nonatomic, strong)NSMutableDictionary* offlineDictionary;

+ (instancetype)sharedInstance;
- (void)clearOfflineDictionary;
@end

NS_ASSUME_NONNULL_END
