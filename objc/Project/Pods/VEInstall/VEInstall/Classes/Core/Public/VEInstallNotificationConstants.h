//
//  VEInstallNotificationConstants.h
//  VEInstall
//
//  Created by KiBen on 2021/9/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 通知名称
FOUNDATION_EXTERN NSString *const VEInstallDidRegisterDeviceNotification;
FOUNDATION_EXTERN NSString *const VEInstallDidActivateDeviceNotification;

/// 通知userinfo的key
FOUNDATION_EXTERN NSString *const VEInstallNotificationKeyAppID;
FOUNDATION_EXTERN NSString *const VEInstallNotificationKeyRegisterResponse;
FOUNDATION_EXTERN NSString *const VEInstallNotificationKeyIsActivated;

NS_ASSUME_NONNULL_END
