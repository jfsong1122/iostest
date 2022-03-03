//
//  IESGurdDefines.h
//  Pods
//
//  Created by willorfang on 2018/6/15.
//

#ifndef IESGurdDefines_h
#define IESGurdDefines_h

NS_ASSUME_NONNULL_BEGIN

/**
 * 资源更新的过程中，可能出现的status集合
 */
typedef NS_ENUM(NSInteger, IESGurdSyncStatus)
{
    IESGurdSyncStatusDisable = -2,
    IESGurdSyncStatusUnknown = -1,
    
    /// 更新成功
    IESGurdSyncStatusSuccess = 0,
    /// 更新失败
    IESGurdSyncStatusFailed = 1,
    
    
    /// 更新inactive 缓存成功
    IESGurdApplyInactivePackagesStatusSuccess = 50,
    /// 更新inactive 缓存失败
    IESGurdApplyInactivePackagesStatusFailed  = 51,
    /// 更新inactive 无更新
    IESGurdApplyInactivePackagesStatusNoCaches= 52,
    
    /**
     * 客户端Error
     */
    /// 请求参数不合法
    IESGurdSyncStatusParameterInvalid = 100,
    /// 参数没有注册
    IESGurdSyncStatusParameterNotRegister = 101,
    /// config请求失败
    IESGurdSyncStatusFetchConfigFailed = 200,
    /// config请求的response结构不合法
    IESGurdSyncStatusFetchConfigResponseInvalid = 201,
    
    /// 下载package包（全量包）失败
    IESGurdSyncStatusDownloadPackageFailed = 300,
    /// package包MD5校验失败
    IESGurdSyncStatusMD5PackageFailed = 450,
    
    /// 下载Patch包失败
    IESGurdSyncStatusDownloadPatchFailed = 301,
    /// config response里没有patch
    IESGurdSyncStatusNoPatch = 400,
    /// config response里有patch，但是没有package
    IESGurdSyncStatusNoBasePackageForPatch = 401,
    /// patch包MD5校验失败
    IESGurdSyncStatusMD5PatchFailed = 402,
    /// 打patch操作失败
    IESGurdSyncStatusBSPatchFailed = 403,
    
    /// package包归档失败
    IESGurdSyncStatusAchievePackageZipFailed = 404,
    /// business bundle目录不存在
    IESGurdSyncStatusBusinesspBundlePathNotExist = 405,
    /// 为解压准备tmp目录失败
    IESGurdSyncStatusCreateTmpPathForUnzipFailed = 406,
    /// 解压失败
    IESGurdSyncStatusUnzipPackageFailed = 407,
    /// 删除过时的package失败
    IESGurdSyncStatusRemoveObsoletePackageFailed = 408,
    
    /// package激活失败
    IESGurdSyncStatusActivatePackageFailed = 409,
    
    // 移动文件时目标路径为空
    IESGurdSyncStatusMoveToNilDestinationPath = 410,
    
    // 计算文件哈希失败
    IESGurdSyncStatusFileHashFailed = 411,
    
    // 复制文件失败
    IESGurdSyncStatusCopyPackageFailed = 501,
    // 重命名patched包失败
    IESGurdSyncStatusRenamePatchedPackageFailed = 502,
    
    // 下载的版本已经激活
    IESGurdSyncStatusDownloadVersionIsActive = 504,
    // 下载的版本未激活
    IESGurdSyncStatusDownloadVersionIsInactive = 505,
    
    // 删除缓存成功
    IESGurdSyncStatusCleanCacheSuccess = 600,
    // 删除缓存失败
    IESGurdSyncStatusCleanCacheFailed = 601,
    
    // 请求节流
    IESGurdSyncStatusRequestThrottle = 700,
    // 服务端不可用
    IESGurdSyncStatusServerUnavailable = 701,
    
    /**
     * 服务端Error
     */
    IESGurdSyncStatusServerAccessKeyInvalid = 1000,
    IESGurdSyncStatusServerAppVersionInvalid = 1001,
    IESGurdSyncStatusServerDeviceIDInvalid = 1002,
    IESGurdSyncStatusServerPackageIDInvalid = 1003,
    IESGurdSyncStatusServerDeviceIDInvalid_2 = 1004,
    IESGurdSyncStatusServerStatsTypeInvalid = 1005,
    IESGurdSyncStatusServerPackageVersionInvalid = 1006,
    IESGurdSyncStatusServerPatchIDInvalid = 1007,
    IESGurdSyncStatusServerURLInvalid = 1008,
    IESGurdSyncStatusServerDomainInvalid = 1009,
    IESGurdSyncStatusServerCommitIDInvalid = 1010,
    IESGurdSyncStatusServerChannelInvalid = 1011,
    IESGurdSyncStatusServerUploadedFileEmpty = 1012,
    IESGurdSyncStatusServerOSInvalid = 1013,
    IESGurdSyncStatusServerScmVersionInvalid = 1014,
    /// 无需更新
    IESGurdSyncStatusServerPackageUnavailable = 2000,
};

//某个channel缓存的状态
typedef NS_ENUM(NSInteger, IESGurdChannelCacheStatus) {
    IESGurdChannelCacheStatusNotFound,  //未找到
    IESGurdChannelCacheStatusInactive,  //未激活
    IESGurdChannelCacheStatusActive     //已激活
};

//某个channel文件类型
typedef NS_ENUM(NSInteger, IESGurdChannelFileType) {
    IESGurdChannelFileTypeCompressed,
    IESGurdChannelFileTypeUncompressed,
    IESGurdChannelFileTypeSettingsFile,
    IESGurdChannelFileTypeSettingsData
};

typedef NS_ENUM(NSInteger, IESGurdRequestChannelConfigStatus) {
    IESGurdRequestChannelConfigStatusNotFound,      //未找到channel包
    IESGurdRequestChannelConfigStatusNewVersion,    //找到channel包，需要下载
    IESGurdRequestChannelConfigStatusLatestVersion  //找到channel包，已经是最新版本
};

typedef NS_ENUM(NSInteger, IESGurdCleanCachePolicy) {
    IESGurdCleanCachePolicyNone,
    IESGurdCleanCachePolicyFIFO,
    IESGurdCleanCachePolicyLRU
};

@class IESGurdResourceModel;

typedef void(^IESResourceConfigResponse)(IESGurdSyncStatus status, NSArray<IESGurdResourceModel *> *_Nullable recordList);

typedef NS_ENUM(NSInteger, IESGurdStatsType)
{
    IESGurdStatsTypeDownloadSucceed = 0, // 全量包下载成功
    IESGurdStatsTypeDownloadFail = 1, // 全量包下载失败
    IESGurdStatsTypeActivateSucceed = 2, // 全量包激活成功
    IESGurdStatsTypeActivateFail = 3, // 全量包激活失败
    
    IESGurdStatsTypePatchDownloadSucceed = 100, // 增量包下载成功
    IESGurdStatsTypePatchDownloadFail = 101, // 增量包下载失败
    IESGurdStatsTypePatchActivateSucceed = 102, // 增量包激活成功
    IESGurdStatsTypePatchActivateFail = 103, // 增量包激活失败
    
    IESGurdStatsTypeCleanCacheSucceed = 200, // 资源清理成功
    IESGurdStatsTypeCleanCacheFail = 201 // 资源清理失败
};

typedef NS_ENUM(NSInteger, IESGurdDownloadContinuationType)
{
    // 正常下载
    IESGurdDownloadContinuationTypeNormal = 0,
    // 基于断点的续传下载
    IESGurdDownloadContinuationTypeContinuation = 1
};

typedef NS_ENUM(NSInteger, IESGurdDownloadType)
{
    // 原有下载方式
    IESGurdDownloadTypeOriginal = 0,
    // 接入 TTDownloader 的下载方式
    IESGurdDownloadTypeTTDownloader = 1
};

typedef NS_ENUM(NSInteger, IESGurdPackagesConfigRequestType) {
    IESGurdPackagesConfigRequestTypeNormal = 1,
    IESGurdPackagesConfigRequestTypeRetry = 2,
    IESGurdPackagesConfigRequestTypePolling = 3,
    IESGurdPackagesConfigRequestTypeByteSync = 4
};

typedef NS_ENUM(NSInteger, IESGurdPollingPriority) {
    IESGurdPollingPriorityNone,
    // High priority
    IESGurdPollingPriorityLevel1,
    // Normal priority
    IESGurdPollingPriorityLevel2,
    // Low priority
    IESGurdPollingPriorityLevel3
};

typedef NS_ENUM(NSInteger, IESGurdDownloadPriority) {
    IESGurdDownloadPriorityLow,
    IESGurdDownloadPriorityMedium,
    IESGurdDownloadPriorityHigh,
    IESGurdDownloadPriorityUserInteraction
};

typedef NS_ENUM(NSInteger, IESGurdDataAccessPolicy) {
    // 只读取平台下发资源
    IESGurdDataAccessPolicyNormal,
    // 优先读取平台下发资源，内置包作为备份读取
    IESGurdDataAccessPolicyInternalPackageBackup,
    // 优先读取内置包
    IESGurdDataAccessPolicyInternalPackageFirst
};

typedef NS_ENUM(NSInteger, IESGurdLogLevel) {
    IESGurdLogLevelInfo,
    IESGurdLogLevelWarning,
    IESGurdLogLevelError
};

#define IESGeckoSyncStatusDict IESGurdSyncStatusDict
/**
 * 对于每个app，所有channel更新的status。
 *
 * Key：channel名称；Value：IESGurdSyncStatus
 */
typedef NSDictionary<NSString *, NSNumber *> *IESGurdSyncStatusDict;

@class IESGurdFetchResourcesParams;
typedef void(^IESGurdFetchResourcesParamsBlock)(IESGurdFetchResourcesParams *params);

typedef void(^IESGurdSyncStatusBlock)(BOOL succeed, IESGurdSyncStatus status);
typedef void(^IESGurdSyncStatusDictionaryBlock)(BOOL succeed, IESGurdSyncStatusDict dict);
typedef void(^IESGurdSyncAccessKeyStatusDictionaryBlock)(BOOL succeed, IESGurdSyncStatusDict dict, NSString *accessKey);

typedef void(^IESGurdAccessResourceCompletion)(NSData * _Nullable data);
typedef void(^IESGurdLoadResourceCompletion)(NSData * _Nullable data, IESGurdSyncStatus status);

typedef void(^IESGurdDownloadResourceCompletion)(NSURL * _Nullable pathURL, NSDictionary *downloadInfo, NSError * _Nullable error);

/**
 * IESGurdSyncStatusDict中，代表整个business的channel
 */
__unused static NSString * const IESGurdChannelPlaceHolder = @"__channel_ph__";

/**
 * IESGurdMakePlaceHolder
 */
__unused static inline IESGurdSyncStatusDict IESGurdMakePlaceHolder(IESGurdSyncStatus status)
{
    return @{ IESGurdChannelPlaceHolder : @(status) };
}

/**
 * IESGurdStatusForChannel
 */
__unused static inline IESGurdSyncStatus IESGurdStatusForChannel(IESGurdSyncStatusDict _Nonnull dict, NSString * _Nonnull channel)
{
    NSNumber *statusNumber = [dict objectForKey:channel];
    if (statusNumber != nil) {
        return (IESGurdSyncStatus)statusNumber.integerValue;
    }
    return (IESGurdSyncStatus)[[dict objectForKey:IESGurdChannelPlaceHolder] integerValue];
}

/**
 * IESGurdStatusForBusiness
 */
__unused static inline IESGurdSyncStatus IESGurdStatusForBusiness(IESGurdSyncStatusDict _Nonnull dict)
{
    return IESGurdStatusForChannel(dict, IESGurdChannelPlaceHolder);
}

__unused static NSDateFormatter *IESGurdDateFormatter (NSString *dateFormat)
{
    if (dateFormat.length == 0) {
        return nil;
    }
    
    static NSMutableDictionary<NSString *, NSDateFormatter *> *dateFormatterDictionary = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        dateFormatterDictionary = [NSMutableDictionary dictionary];
    });
    
    __block NSDateFormatter *dateFormatter = nil;
    @synchronized (dateFormatterDictionary) {
        dateFormatter = dateFormatterDictionary[dateFormat];
        if (!dateFormatter) {
            dateFormatter = [[NSDateFormatter alloc] init];
            dateFormatter.dateFormat = dateFormat;
            dateFormatterDictionary[dateFormat] = dateFormatter;
        }
    }
    return dateFormatter;
}

__unused static NSDateFormatter *IESGurdNormalDateFormatter (void)
{
    return IESGurdDateFormatter(@"yyyy-MM-dd HH:mm:ss");
}

#define IESGurdKitDidRegisterAccessKeyNotification @"IESGurdKitDidRegisterAccessKeyNotification"

#define IESGurdKitDidSetEnableGurdNotification @"IESGurdKitDidSetEnableGurdNotification"
#define IESGurdKitDidSetupGurdNotification @"IESGurdKitDidSetupGurdNotification"

#ifndef dispatch_queue_async_safe
#define dispatch_queue_async_safe(queue, block)\
if (dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL) == dispatch_queue_get_label(queue)) {\
    block();\
} else {\
    dispatch_async(queue, block);\
}
#endif

#ifndef dispatch_queue_sync_safe
#define dispatch_queue_sync_safe(queue, block)\
if (dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL) == dispatch_queue_get_label(queue)) {\
block();\
} else {\
dispatch_sync(queue, block);\
}
#endif

NS_ASSUME_NONNULL_END

#endif /* IESGurdDefines_h */
