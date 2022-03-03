//
//  BDHotfixPatchModel.h
//  BDDynamically
//
//  Created by 朱元清 on 2021/2/9.
//

#import <Foundation/Foundation.h>

/**
 [接口Response中单个补丁的信息描述]
 "patch_id":        "xxx",          // 补丁ID          int
 "patch_name":      "xxx",          // 补丁包名         string
 "versioncode":     5,              // 补丁版本号        string
 "appVersion":      "xxx",          // 下发APP的主版本号  string
 "appBuildVersion": "xxx",          // 下发APP的编译版本号 string
 "url":             "xxx",          // 下载url           string
 "md5":             "xxx",          // 下载包md5          string
 "backup_urls": [
    "xxx",
    "xxx",
 ]
 "offline":         false,          // patch开关          int
 "wifionly":        true,           // 是否只在wifi下载     int
 */
@interface BDHotfixPatchModel : NSObject

/*  MODEL  */
/// 热修ID。hotfix_id
@property (nonatomic) NSNumber *hotfixID;

/// 热修包ID. patch_id
@property (nonatomic) NSNumber *patchId;

/// 热修包名称. patch_name
@property (nonatomic, copy) NSString *patchName;

/// 热修包版本 versioncode
@property (nonatomic, copy) NSString *version;

/// app_version
@property (nonatomic, copy) NSString *appVersion;

/// app_build_version
@property (nonatomic, copy) NSString *appBuildVersion;

/// 是否仅仅wifi环境下进行下载. 目前忽略此字段. wifionly
@property (nonatomic) BOOL wifionly;

/// 热修包是否已经在后台下线. offline
@property (nonatomic) BOOL offline;

/// 热修包文件md5. md5
@property (nonatomic, copy) NSString *md5;

/// 热修包文件下载地址. url
@property (nonatomic, copy) NSString *url;

/// 热修包文件下载备份地址地址. backup_urls
@property (nonatomic, copy) NSArray<NSString *> *backupUrls;

/// 是否应异步加载. async_load
@property (nonatomic, getter=isAsyncLoad) BOOL asyncLoad;

/// channel
@property (nonatomic, copy) NSArray *channelList;

/// app_version_list
@property (nonatomic, copy) NSArray *appVersionList;

/// os_version_range
@property (nonatomic, copy) NSDictionary *osVersionRange;

/* OTHER */
/// 热修包加密相关 目前没有用到
@property (nonatomic, getter=isEncrypted) BOOL encrypted;
@property (nonatomic, copy) NSString *privateKey;

+ (instancetype)modelWithDictionary:(NSDictionary *)dict;

/// 存储的沙盒文件夹路径
- (NSString *)storageDirectory;

/// 本地沙盒中是否有Patch代码
- (BOOL)hasLocalStorage;

#pragma mark 数据转换方法
// 转化为本地存储的结构
- (NSDictionary *)toDictionary;

// 转化为上传至服务端的结构 {"name": ***, "": ***}
- (NSDictionary *)toReportDicitonary;

- (NSDictionary *)toLogDicitonary;

/// 不知道干什么用的，没有用到
- (NSString *)uniquekey;

@end
