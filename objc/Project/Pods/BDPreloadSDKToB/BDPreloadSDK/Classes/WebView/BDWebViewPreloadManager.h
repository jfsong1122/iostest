//
//  BDWebViewPreloadManager.h
//  BDPreloadSDK
//
//  Created by wealong on 2019/8/12.
//

#import <Foundation/Foundation.h>
#import <YYCache/YYDiskCache.h>

#import "BDPreloadCachedResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDWebViewPreloadManager : NSObject

+ (instancetype)sharedInstance;

// 内部的预加载资源，提供给外界做磁盘管理
@property (nonatomic, strong, readonly) YYDiskCache *diskCache;

// 预加载 WebView 资源接口
- (void)fetchDataForURLString:(NSString *)urlString
                  headerField:(NSDictionary *)headerField
                cacheDuration:(NSTimeInterval)cacheDuration
                queuePriority:(NSOperationQueuePriority)priority
                   completion:(void(^)(NSError *error))callback;

- (void)clearDataForURLString:(NSString *)urlString;
- (nullable BDPreloadCachedResponse *)responseForURLString:(NSString *)urlString;
- (void)saveResponse:(nullable BDPreloadCachedResponse *)response forURLString:(NSString *)urlString;

@end

NS_ASSUME_NONNULL_END
