//
//  IESGurdProtocolDefines.h
//  Pods
//
//  Created by chenyuchuan on 2019/6/5.
//

#ifndef IESGurdProtocolDefines_h
#define IESGurdProtocolDefines_h

#import "IESGeckoDefines.h"
#import "IESGeckoResourceModel.h"
#import "IESGurdDownloadPackageInfo.h"
#import "IESGurdUnzipPackageInfo.h"
#import "IESGurdNetworkResponse.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^IESGurdNetworkDelegateDownloadCompletion)(NSURL * _Nullable pathURL, NSError * _Nullable error);

@protocol IESGurdNetworkDelegate <NSObject>

@required
- (void)downloadPackageWithIdentity:(NSString *)identity
                          URLString:(NSString *)packageURLString
                         completion:(IESGurdNetworkDelegateDownloadCompletion)completion;

- (void)requestWithMethod:(NSString *)method
                URLString:(NSString *)URLString
                   params:(NSDictionary *)params
               completion:(void (^)(IESGurdNetworkResponse *response))completion;

@optional
- (NSString *)currentNetworkConnectionString;

@end

@protocol IESGurdDownloaderDelegate <NSObject>

- (void)downloadPackageWithIdentity:(NSString *)identity
                         URLStrings:(NSArray <NSString *> *)URLStrings
                         completion:(IESGurdDownloadResourceCompletion)completion;

// 用于清理任务和下载缓存
- (void)cancelDownloadWithIdentity:(NSString *)identity;

@end

@protocol IESGurdEventDelegate <NSObject>

@optional
/**
 请求资源包的状态
 
 @param accessKey accessKey
 @param configsDictionary @{ channelName : @(IESGurdRequestChannelConfigStatus) }
 */
- (void)gurdDidRequestConfigForAccessKey:(NSString *)accessKey
                       configsDictionary:(NSDictionary<NSString *, NSNumber *> *)configsDictionary;

/**
 新增下载任务
 
 @param model 资源包信息
 */
- (void)gurdDidEnqueueDownloadTaskForModel:(IESGurdResourceModel *)model;

/**
 即将下载资源包
 
 @param accessKey accessKey
 @param channel channel
 @param isPatch 是否增量包
 */
- (void)gurdWillDownloadPackageForAccessKey:(NSString *)accessKey
                                    channel:(NSString *)channel
                                    isPatch:(BOOL)isPatch;

/**
 下载资源包完成；包括成功和失败
 
 @param accessKey accessKey
 @param channel channel
 @param packageInfo 下载资源包信息
 */
- (void)gurdDidFinishDownloadingPackageForAccessKey:(NSString *)accessKey
                                            channel:(NSString *)channel
                                        packageInfo:(IESGurdDownloadPackageInfo *)packageInfo;

/**
 解压资源包完成
 
 @param accessKey accessKey
 @param channel channel
 @param packageInfo 解压资源包信息
 */
- (void)gurdDidFinishUnzippingPackageForAccessKey:(NSString *)accessKey
                                          channel:(NSString *)channel
                                      packageInfo:(IESGurdUnzipPackageInfo *)packageInfo;

/**
 激活资源包完成；包括成功和失败

 @param accessKey accessKey
 @param channel channel
 @param succeed 是否成功
 @param error 失败的错误信息
 */
- (void)gurdDidFinishApplyingPackageForAccessKey:(NSString *)accessKey
                                         channel:(NSString *)channel
                                         succeed:(BOOL)succeed
                                           error:(NSError * _Nullable)error;

/**
 清理资源包
 
 @param accessKey accessKey
 @param channel 被清理的channel
 */
- (void)gurdDidCleanCachePackageForAccessKey:(NSString *)accessKey
                                     channel:(NSString *)channel;


/**
 访问内置包
 */
- (void)gurdDidAccessInternalPackageWithAccessKey:(NSString *)accessKey
                                          channel:(NSString *)channel
                                             path:(NSString *)path
                                 dataAccessPolicy:(IESGurdDataAccessPolicy)dataAccessPolicy;

@end


/// 数据上报
@protocol IESGurdAppLogDelegate <NSObject>

- (void)trackEvent:(NSString *)event params:(NSDictionary *)params;

@end

@protocol IESGurdLogProxyDelegate <NSObject>

- (void)gurdLogLevel:(IESGurdLogLevel)logLevel logMessage:(NSString *)logMessage;

@end

NS_ASSUME_NONNULL_END

#endif /* IESGurdProtocolDefines_h */
