//
//  RARKitRegisterService.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2021/6/2.
//

#import <Foundation/Foundation.h>
#import "RARegisterInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface RARKitRegisterService : NSObject

/**
 本地缓存的 deviceID，可能为空
 */
@property (atomic, copy, readonly) NSString *deviceID;

/**
 1、先初始化一个 RARegisterInfo 实例，然后用该实例获取一个注册服务
 2、获取注册服务之后，可以先通过 deviceID 属性获取本地缓存的信息
 3、通过监听通知可以获取到服务端注册服务返回的信息，通知名称通过 RARegisterInfo.registerSuccessNotificationName 属性获取
 4、相同的 appID 获取到的注册服务实例相同
 */
+ (nullable instancetype)serviceForRegisterInfo:(RARegisterInfo *)info;
- (id)init __attribute__((unavailable("please use serviceForRegisterInfo:")));
+ (instancetype)new __attribute__((unavailable("please use serviceForRegisterInfo:")));

@end

NS_ASSUME_NONNULL_END
