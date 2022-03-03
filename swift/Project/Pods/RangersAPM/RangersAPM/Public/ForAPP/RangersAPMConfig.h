//
//  RangersAPMConfig.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2021/3/9.
//

#import <Foundation/Foundation.h>
#import "RangersAPMCommon.h"

typedef NS_OPTIONS(NSUInteger, RangersAPMMonitorSwitch) {
    RangersAPMCrashMonitorSwitch = 1<<0,             //崩溃分析
    RangersAPMLagMonitorSwitch = 1<<1,               //卡顿分析
    RangersAPMUserExceptionMonitorSwitch = 1<<2,     //自定义错误
    RangersAPMNetworkMonitorSwitch = 1<<3,           //网络分析
    RangersAPMLaunchMonitorSwitch = 1<<4,            //启动分析
    RangersAPMFPSMonitorSwitch = 1<<5,               //帧率检测
    RangersAPMUIMonitorSwitch = 1<<6,                //页面加载分析
    RangersAPMHybridMonitorSwitch = 1<<7,            //Web页面分析
    RangersAPMMemoryGraphMonitorSwitch = 1<<8,       //内存分析：包括内存指标、泄漏分析、大对象、单设备查询等
    RangersAPMCrashProtectorSwitch = 1<<9            //崩溃防护
};

NS_ASSUME_NONNULL_BEGIN

@interface RangersAPMConfig : NSObject

/*! @abstract The channel where your app will be published.
 @discussion Nonnull & require. Default : "App Store"
 */
@property (atomic, copy) NSString *channel;

/*! @abstract The ID of your app that you registered from APMInsight.
 @discussion Nonnull & require.
 */
@property (atomic, copy) NSString *appID;

/*!@abstract The source where we will get the device ID.
 @discussion Nonnull & require. Default : RAPMDeviceIDSourceFromUser.
 */
@property (atomic, assign) RAPMDeviceIDSource deviceIDSource;

/*!@abstract The monitors you'd like to allow them start before APM SDK pull the remote configuration.
 @discussion Nonnull & require. Default : All the monitors ---- RangersAPMCrashMonitor | RangersAPMLagMonitor | RangersAPMUserExceptionMonitor | RangersAPMNetworkMonitor | RangersAPMLaunchMonitor | RangersAPMFPSMonitor | RangersAPMUIMonitor | RangersAPMHybridMonitor | RangersAPMMemoryGraphMonitor.
 @discussion This configuration is only useful when there is no remote configuration. 
 */
@property (atomic, assign) RangersAPMMonitorSwitch defaultMonitors;

/*!@abstract The identifier of your app user.
 @discussion Nullable & optional.
 */
@property (nonatomic, copy) NSString *userID;

/*!@abstract The domain address where apm logs should be uploaded to.
 @discussion If you are using APMPlus Saas version, just ignore this.
 @discussion Set the domain with 'http://' or 'https://' to specify the scheme, else 'https://' is default.
 */
@property (nonatomic, copy) NSString *domain;

/*!@abstract An application group identifier to contact with the extension.
 @discussion Nullable & optional.
 */
@property (atomic, copy) NSString *groupID;

/**
 Initialize a config with appID.
 
 @param appID The ID of your app that you registered from APMInsight.
 @result A RangersAPMConfig instance.
 */
+ (instancetype)configWithAppID:(NSString *)appID;
- (id)init __attribute__((unavailable("please use configWithSDKID:")));
+ (instancetype)new __attribute__((unavailable("please use configWithSDKID:")));

@end

NS_ASSUME_NONNULL_END
