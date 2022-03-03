//
//  BDHotfixConfig.h
//  BDDynamically
//
//  Created by 朱元清 on 2021/2/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 产品发布地区，目前只有中国是有效的。
typedef NS_ENUM(NSInteger, BDHotfixDistArea) {
    kBDHotfixDistAreaCN = 0,  // 中国
    kBDHotfixDistAreaSG,      // 新加坡
    kBDHotfixDistAreaVA,      // 美东
};

@interface BDHotfixConfig : NSObject
/// 是否打开 debug 调试信息，默认为NO
@property (nonatomic) BOOL debug;

/// 是否在SDK启动时与后台同步热修包，默认为YES
@property (nonatomic) BOOL syncAtStartUp;
#pragma mark - 热修包拉取参数
/// 产品发布地区. 默认是 `kBDHotfixDistAreaCN`
@property (nonatomic, assign) BDHotfixDistArea distArea;

/// 热修包接口的请求域名. 默认使用 distArea 对应的域名。可以通过设置覆盖。
@property (nonatomic, copy, nonnull) NSString *domainName;

/// 您在MARS平台上的应用的AppID. 默认从OneKit读取。
@property (nonatomic, copy, nonnull) NSString *appID;

/// App渠道. 默认从OneKit读取。
@property (nonatomic, copy, nonnull) NSString *channel;

/// App三位主版本号；默认读取`CFBundleShortVersionString`. 默认从OneKit读取。
@property (nonatomic, copy, nonnull) NSString *appVersion;

/// App编译版本号，默认读取`CFBundleVersion`. 默认从OneKit读取。
@property (nonatomic, copy, nonnull) NSString *appBuildVersion;

/// MARS appKey
@property (nonatomic, copy) NSString *accessKey;

/// MARS secretKey
@property (nonatomic, copy) NSString *secretKey;

/*! 获取DeviceID的Block，是热修包请求参数之一。用于匹配后台配置的DeviceID白名单和灰度放量。
 @discussion 如果不需要白名单和灰度放量，一般无需关心此字段。如果需要白名单和灰度放量，在此处传入一个返回本应用DeviceID的Block。DeviceID由设备注册服务提供，可以参考其接入文档来传入。如本应用已接入RangersAppLog 6.0.1+和OneKit应用框架，SDK将默认读取RangersAppLog获取的DeviceID。
 */
@property (nonatomic, readonly) NSString *deviceID;

#pragma mark - network parameters

/// Common network (query) parameters. 一般不需要设置。
@property (nonatomic, copy, nonnull) NSDictionary* (^commonNetworkParamsBlock)(void);
@property (nonatomic, strong, readonly) NSDictionary *commonParams;

+ (void)setCustomDeviceId:(NSString *)did;

@end


NS_ASSUME_NONNULL_END
