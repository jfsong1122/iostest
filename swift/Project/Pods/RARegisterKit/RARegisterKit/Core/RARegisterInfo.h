//
//  RARegisterInfo.h
//  RARegisterKit
//
//  Created by xuminghao.eric on 2022/2/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString *const RARegisterKitDeviceIDKey;
FOUNDATION_EXTERN NSString *const RARegisterKitAppIDKey;

@interface RARegisterInfo : NSObject

/**
 App 标识符，此属性不可单独赋值，请通过 infoWithAppID:registerURL: 传入
 */
@property (atomic, copy, readonly) NSString *appID;

/**
 注册服务请求的路径，此属性不可单独赋值，请通过 infoWithAppID:registerURL: 传入
 */
@property (atomic, copy, readonly) NSString *registerURL;

/**
 监听此通知获取服务端返回的设备注册信息，userInfo 格式为 { RARegisterKitDeviceIDKey : deviceID, RARegisterKitAppIDKey : appID }
 */
@property (atomic, copy, readonly) NSString *registerSuccessNotificationName;

/**
 App 发放渠道，根据实际情况赋值，无默认值
 */
@property (atomic, copy) NSString *channel;

/**
 App 的版本号，默认值通过 [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"] 获取
 */
@property (atomic, copy) NSString *appVersion;

/**
 App 的 build version，默认值通过 [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"] 获取
 */
@property (atomic, copy) NSString *buildCode;

/**
 如果当前是以 SDK 视角使用注册服务，可以配置此属性传入宿主的标识符
 */
@property (atomic, copy) NSString *hostAppID;

/**
 如果当前是以 SDK 视角使用注册服务，可以配置此属性传入 SDK 的版本号
 */
@property (atomic, copy) NSString *sdkVersion;

+ (nullable instancetype)infoWithAppID:(NSString *)appID registerURL:(NSString *)registerURL;
- (id)init __attribute__((unavailable("please use infoWithAppID:")));
+ (instancetype)new __attribute__((unavailable("please use infoWithAppID:")));

@end

NS_ASSUME_NONNULL_END
