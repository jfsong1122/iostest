//
//  IESGeckoKit.h
//  IESGeckoKit
//
//  Created by willorfang on 2017/8/7.
//
//

#import <Foundation/Foundation.h>
#import "IESGeckoDefines.h"
#import "IESGurdProtocolDefines.h"
#import "IESGurdCacheConfiguration.h"
#import "IESGurdFetchResourcesParams.h"
#import "IESGurdLoadResourcesParams.h"
#import "IESGurdRegisterModel.h"

NS_ASSUME_NONNULL_BEGIN

#define IESGeckoKit IESGurdKit
#define IESGeckoNetworkDelegate IESGurdNetworkDelegate
#define IESGeckoKitSDKVersion IESGurdKitSDKVersion
#define IESGeckoKitDidRegisterAccessKeyNotification IESGurdKitDidRegisterAccessKeyNotification

FOUNDATION_EXTERN NSString *IESGurdKitSDKVersion(void);

@interface IESGurdKit : NSObject

@property (class, assign) BOOL enable; // default YES

@property (class, nonatomic, copy) NSString *deviceID; // DeviceID。统计用。 注意：需要在syncResources之前进行设置。

@property (class, nonatomic, copy) NSString *(^getDeviceID)(void);

@property (class, nonatomic, copy) NSString *platformDomain; // Gecko 系统的domain; 注意：需要在syncResources之前进行设置。

@property (class, nonatomic, copy) NSString *httpProtocol; // Gecko 请求的协议，默认是 https，用户可以设置 http

@property (class, nonatomic, copy) NSString *v4BusinessDomain; // 用于 tob 用户自定义整个 v4 path

@property (class, nonatomic, copy) NSString *appSecretKey; // 用于 mars 请求鉴权加密

@property (class, nonatomic, copy) NSString *appKey; // 用于 mars 请求鉴权加密

@property (class, nonatomic, assign, getter=isLogEnabled) BOOL logEnable; // 废弃

@property (class, nonatomic, assign, getter=isEventTraceEnabled) BOOL eventTraceEnabled; // 开启内存日志（线上环境不开启）

@property (class, nonatomic, strong) id<IESGurdNetworkDelegate> _Nullable networkDelegate; // 设置网络代理

@property (class, nonatomic, strong) id<IESGurdDownloaderDelegate> _Nullable downloaderDelegate; // 设置下载代理

@property (class, nonatomic, strong) id<IESGurdAppLogDelegate> _Nullable appLogDelegate;

#pragma mark - Config

/**
 * @brief 返回是否已配置
 * 在请求资源前必须先调用 +[IESGurdKit setupWithAppId:appVersion:cacheRootDirectory:]
 */
+ (BOOL)didSetup;

/**
 * @brief 设置基本参数
 * @param appId                  应用id
 * @param appVersion             应用版本
 * @param cacheRootDirectory     Gecko系统的cache根目录；可为空，默认 Library/Caches/IESWebCache/
 *
 * 注意：尽可能提前设置
 */
+ (void)setupWithAppId:(NSString * _Nonnull)appId
            appVersion:(NSString * _Nonnull)appVersion
    cacheRootDirectory:(NSString * _Nullable)cacheRootDirectory;

/**
 * @brief Gecko 系统的cache根目录
 */
+ (NSString *)cacheRootDir;

/**
 注册事件代理；内部弱持有
 */
+ (void)registerEventDelegate:(id<IESGurdEventDelegate>)eventDelegate;

/**
 反注册事件代理
 */
+ (void)unregiserEventDelegate:(id<IESGurdEventDelegate>)eventDelegate;

/**
 * @brief 注册要更新的accessKey
 *
 * 注意 : 需要在syncResources之前进行设置。
 */
+ (void)registerAccessKey:(NSString *)accessKey;

/**
 * @brief 注册要更新的accessKey
 *
 * 注意 : 需要在syncResources之前进行设置。
 */
+ (void)registerAccessKey:(NSString *)accessKey
               SDKVersion:(NSString *)SDKVersion;

/**
 所有注册信息
 */
+ (NSArray<IESGurdRegisterModel *> *)allRegisterModels;

/**
 设置请求 header field
 */
+ (void)setRequestHeaderFieldBlock:(NSDictionary<NSString *, NSString *> *(^)(void))block;

+ (void)setGurdLogDelegate:(id<IESGurdLogProxyDelegate>)logDelegate;

#pragma mark - Apply

/**
 * @brief 将所有未激活的缓存进行激活
 */
+ (void)applyInactivePackages:(IESGurdSyncStatusBlock _Nullable)completion;

/**
 * @brief 将指定accesskey & channel下未激活的缓存进行激活
 */
+ (void)applyInactivePackageForAccessKey:(NSString *)accessKey
                                 channel:(NSString *)channel
                              completion:(IESGurdSyncStatusBlock _Nullable)completion;

#pragma mark - Download

/**
 * @brief 下载指定的包，并不直接进行更新。
 *
 * @param accessKey     business的部署key
 * @param channels      指定的channel
 * @param completion    completion
 */
+ (void)downloadResourcesWithAccessKey:(NSString *)accessKey
                              channels:(NSArray<NSString *> *)channels
                            completion:(IESGurdSyncStatusDictionaryBlock _Nullable)completion;

/**
 * @brief 下载指定的包，并不直接进行更新。
 *
 * @param paramsBlock       配置参数
 * @param completion    completion
 */
+ (void)downloadResourcesWithParamsBlock:(IESGurdFetchResourcesParamsBlock)paramsBlock
                              completion:(IESGurdSyncStatusDictionaryBlock _Nullable)completion;

#pragma mark - Sync Resource

/**
 * @brief 更新指定的包，准备好缓存环境。
 *
 * @param accessKey     business的部署key
 * @param channels      指定的channel
 * @param completion    completion
 */
+ (void)syncResourcesWithAccessKey:(NSString *)accessKey
                          channels:(NSArray<NSString *> * _Nullable)channels
                        completion:(IESGurdSyncStatusDictionaryBlock _Nullable)completion;

/**
 * @brief 更新指定的包，准备好缓存环境。
 *
 * @param paramsBlock       配置参数
 * @param completion        completion
 */
+ (void)syncResourcesWithParamsBlock:(IESGurdFetchResourcesParamsBlock)paramsBlock
                          completion:(IESGurdSyncStatusDictionaryBlock _Nullable)completion;

/**
 * @brief 异步加载指定资源；如果本地存在资源，直接返回；否则发起请求；回调在主线程
 */
+ (void)loadResourceForAccessKey:(NSString *)accessKey
                         channel:(NSString *)channel
                            path:(NSString *)path
                      completion:(IESGurdLoadResourceCompletion)completion;

/**
 * @brief 异步加载指定资源；如果本地存在资源，直接返回；否则发起请求；回调在主线程
 */
+ (void)loadResourceWithParamsBlock:(void (^)(IESGurdLoadResourcesParams *params))paramsBlock
                         completion:(IESGurdLoadResourceCompletion)completion;


#pragma mark - Cache

/**
 * @brief 是否有缓存
 *
 * @param path      文件相对路径
 * @param accessKey 包名
 * @param channel   渠道名
 *                  文件绝对路径：Library/Caches/IESWebCache/<accessKey>/<channel>/<path>
 */
+ (BOOL)hasCacheForPath:(NSString *)path accessKey:(NSString *)accessKey channel:(NSString *)channel;

/**
 * @brief 根据缓存policy返回离线资源绝对路径，若没有离线资源，则返回nil
 *
 * @param path      文件相对路径
 * @param accessKey 包名
 * @param channel   渠道名
 *                  文件绝对路径：Library/Caches/IESWebCache/<accessKey>/<channel>/<path>
 */
+ (NSString *)cachePathForPath:(NSString *)path accessKey:(NSString *)accessKey channel:(NSString *)channel;

/**
 * @brief 读取缓存数据
 */
+ (NSData *)dataForPath:(NSString *)path accessKey:(NSString *)accessKey channel:(NSString *)channel;

/**
 * @brief 读取缓存数据
 */
+ (NSData *)dataForPath:(NSString *)path accessKey:(NSString *)accessKey channel:(NSString *)channel options:(NSDataReadingOptions)options;

/**
 * @brief 异步读取缓存数据；回调在主线程
 */
+ (void)asyncGetDataForPath:(NSString *)path
                  accessKey:(NSString *)accessKey
                    channel:(NSString *)channel
                 completion:(IESGurdAccessResourceCompletion)completion;

/**
 * @brief 返回文件类型；如果文件未激活，则返回-1
 */
+ (IESGurdChannelFileType)fileTypeForAccessKey:(NSString *)accessKey channel:(NSString *)channel;

/**
 * @brief 返回文件版本；如果文件未激活，则返回0
 */
+ (uint64_t)packageVersionForAccessKey:(NSString *)accessKey channel:(NSString *)channel;

/**
 * @brief 获取指定accessKey根目录
 */
+ (NSString *)rootDirForAccessKey:(NSString *)accessKey;

/**
 * @brief 获取指定channel根目录
 */
+ (NSString *)rootDirForAccessKey:(NSString *)accessKey channel:(NSString *)channel;

/**
 返回channel缓存的状态
 */
+ (IESGurdChannelCacheStatus)cacheStatusForAccessKey:(NSString *)accessKey channel:(NSString *)channel;

/**
 清除cache
 */
+ (void)clearCache;

/**
 根据accessKey和channel清理对应的缓存;
 */
+ (void)clearCacheForAccessKey:(NSString *)accessKey
                       channel:(NSString *)channel;

#pragma mark - Clean

/**
 设置缓存策略
 */
+ (void)setCacheConfiguration:(IESGurdCacheConfiguration *)configuration
                 forAccessKey:(NSString *)accessKey;

/**
 添加channel白名单，不被清理
 */
+ (void)addChannelsWhitelist:(NSArray<NSString *> *)channels
                forAccessKey:(NSString *)accessKey;

@end

NS_ASSUME_NONNULL_END
