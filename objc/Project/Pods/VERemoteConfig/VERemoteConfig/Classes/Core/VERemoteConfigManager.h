//
//  VERemoteConfigManager.h
//  Pods
//
//  Created by Ada on 2021/10/11.
//
#import "VERemoteConfigCommon.h"

@interface VERemoteConfigInfo: NSObject

@property (nonatomic, copy, nonnull) NSString *appKey;           // MARS平台上AppKey信息

@property (nonatomic, copy, nonnull) NSString *appSecret;        // MARS平台上AppSecret信息

@property (nonatomic, copy, nonnull) NSString *deviceID;         // 设备ID，用户传入设备唯一标识符，可选，没有传则无法使用灰度发布功能

@property (nonatomic, copy, nonnull) NSString *channel;          // 渠道名：可选，若没有则无法设置渠道条件，发布的内侧阶段无法使用渠道功能

@property (nonatomic, copy, nonnull) NSString *host;             // API域名：可选，默认公有云线上地址

@property (nonatomic, assign) NSTimeInterval interval;           // Fetch频率控制：可选，默认5分钟，会控制最小频率为5分钟

@end

@interface VEVariable: NSObject

@property (nonatomic, copy, nonnull) id value;           // 变量值

@property (nonatomic, copy, nonnull) NSString *type;     // 变量类型

@end

@interface VERemoteConfigManager : NSObject

// 获取全局单例（推荐APP使用）
+ (nonnull instancetype)sharedInstance;

// 获取和key绑定的全局单例（推荐SDK使用）
+ (nonnull instancetype)sharedInstanceWithKey:(NSString *_Nonnull)key;

// 设置基本信息
- (void)setUp:(VERemoteConfigInfo *_Nonnull)info;

// 设置最小拉取时间间隔
- (void)setInterval:(NSTimeInterval)interval;

// 拉取远程配置
- (void)fetchConfigsWithCheckInterval:(BOOL)checkInterval callback:(FetchCallback _Nullable)callback;

// 获取string类型变量值
- (nullable NSString *)getString:(NSString *_Nonnull)key withDefault:(NSString *_Nullable)defaultValue;

// 获取bool类型变量值
- (BOOL)getBool:(NSString *_Nonnull)key withDefault:(BOOL)defaultValue;

// 获取float类型变量值
- (float)getFloat:(NSString *_Nonnull)key withDefault:(float)defaultValue;

// 获取int类型变量值
- (NSInteger)getInt:(NSString *_Nonnull)key withDefault:(NSInteger)defaultValue;

// 获取变量结构体
- (nullable VEVariable *)get:(NSString *_Nonnull)key;

// 判断变量是否存在
- (BOOL)containsKey:(NSString *_Nonnull)key;

@end

