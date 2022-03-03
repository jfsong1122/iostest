//
//  VEH5KitManager.h
//  VEH5KitManager
//
//  Created by lixiaopeng on 2021/4/21.
//

#import <Foundation/Foundation.h>
#import "VEH5KitConfig.h"

typedef void(^VEH5GurdSyncStatusDictionaryBlock)(BOOL succeed);

NS_ASSUME_NONNULL_BEGIN

@interface VEH5KitManager : NSObject

+ (instancetype)sharedInstance;

- (void)startUpWithConfig:(VEH5KitConfig *)config;

- (void)updateOfflineResources:(VEH5GurdSyncStatusDictionaryBlock)completion;

- (void)clearOfflineResources;

- (NSDictionary *)offlineDictionary;

- (void)clearDebugCache;

@end

NS_ASSUME_NONNULL_END
