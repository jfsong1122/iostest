//
//  VEInstallConfig.h
//  VEInstall
//
//  Created by KiBen on 2021/9/1.
//

#import <Foundation/Foundation.h>
#import <VEInstall/VEInstallURLService.h>
#import <VEInstall/VEInstallDataEncryptProvider.h>
#import <VEInstall/VEInstallASAProvider.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSDictionary<NSString*, id> *_Nullable (^VEInstallCustomParamsBlock)(void);

@interface VEInstallConfig : NSObject

/// ⚠️必传！！！业务方AppID
@property (nonatomic, copy) NSString *appID;


/// ⚠️必传！！！当前App包渠道
@property (nonatomic, copy) NSString *channel;


/// ⚠️必传！！！当前App名称
@property (nonatomic, copy) NSString *name;


/// ⚠️必传！！！当前服务使用的域名；目前提供CN(中国)、SG(新加坡)、VA(美东)
@property (nonatomic, copy) Class<VEInstallURLService> URLService;


/// 当前用户ID
@property (nonatomic, copy, nullable) NSString *userUniqueID;


/// 是否自动激活设备，如果为YES，SDK内部会在设备注册成功后，
/// 自动调用设备激活逻辑；如果为NO，SDK只做注册逻辑；该属性默认为YES
@property (nonatomic, assign, getter=isAutoActivated) BOOL autoActivated;


/// 是否数据加密，默认为YES;
/// @note Debug阶段可设置为NO，方便抓包调试
@property (nonatomic, assign, getter=isEncryptEnable) BOOL encryptEnable;


/// 自定义数据加密器; 默认为nil，则使用SDK提供的默认数据加密器
/// @note 该属性只在encryptEnable设置为YES时生效
@property (nonatomic, copy, nullable) Class<VEInstallDataEncryptProvider> encryptProvider;


/// Apple Search Ads参数生成器，默认为nil
/// @note 该属性适用于需要私有化项目，在设备注册阶段透传ASA统计激活
@property (nonatomic, copy, nullable) Class<VEInstallASAProvider> ASAProvider;


/// 请求超时时长；默认为15秒
@property (nonatomic, assign) NSTimeInterval timeoutInterval;


/// 设备注册/激活请求重试次数；默认为3次
@property (nonatomic, assign) NSUInteger retryTimes;


/// 设备注册/激活请求重试时间间隔；默认为5秒
@property (nonatomic, assign) NSTimeInterval retryDuration;


/// 自定义Header中的扩展字段，会单独保存在header中独立的custom字段中
@property (nonatomic, copy, nullable) VEInstallCustomParamsBlock customHeaderBlock;

@end

NS_ASSUME_NONNULL_END
