//
//  BDWKProvider.h
//  ByteWebView
//
//  Created by Lin Yong on 2019/1/28.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "BDWebViewCommon.h"
#import <BDWebKitToB/BDWKPrecreator.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDWKProvider : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, readonly) BDWKPrecreator *normalPrecreator;
@property (nonatomic, readonly) BDWKPrecreator *ttnetPrecreator;
//@property (nonatomic, readonly) BDWKPrecreator *customPrecreator;       // 根据定制的config生成的pre

/**
 *  获取一个预创建的 WKWebView, 如果BDWebViewOfflineTypeTaskScheme则不会使用b预创建的实例
 *
 *  @return WKWebView 实例
 */
- (WKWebView *)fetchWithOfflineType:(BDWebViewOfflineType)type configSetting:(BDWebViewWKConfigurationSetting *)setting;

+ (WKProcessPool*)processPool;

- (WKWebViewConfiguration *)manualPreCreateWKWithSetting:(BDWebViewWKConfigurationSetting *)setting;
- (WKWebView *)fetchManualPreCreateWKWithConfiguration:(WKWebViewConfiguration *)config;

- (WKWebViewConfiguration *)makeWKConfigurationWithSetting:(BDWebViewWKConfigurationSetting *)setting;
- (WKWebView *)makeWKWebViewWithConfigSetting:(BDWebViewWKConfigurationSetting *)setting;


/// 根据业务传入自定义的WKWebViewConfiguration和指定的type（BDWebViewOfflineTypeTaskScheme的类型会ttnet代理）生成自定义WKWebView池，绑定一个precreatorKey，返回是否成功创建的结果
/// @param setting 自定义的setting
/// @param precreatorKey 绑定对应WKWebViewConfiguration的key，业务可以自定义
/// @param type BDWebViewOfflineType类型
- (BOOL)prepareCustomPrecreator:(BDWebViewWKConfigurationSetting *)setting bindPrecreatorKey:(NSString *)precreatorKey offlineType:(BDWebViewOfflineType)type;

/// 根据之前绑定的precreatorKey获取预创建的WKWebView
/// @param precreatorKey 绑定对应WKWebViewConfiguration的key，业务可以自定义
- (nullable WKWebView *)fetchCustomWKWithPrecreatorKey:(NSString *)precreatorKey;

/// 根据之前绑定的precreatorKey销毁对应的预创建池
/// @param precreatorKey 绑定对应WKWebViewConfiguration的key，业务可以自定义
- (void)destroyCustomPrecreator:(NSString *)precreatorKey;


@end

NS_ASSUME_NONNULL_END
