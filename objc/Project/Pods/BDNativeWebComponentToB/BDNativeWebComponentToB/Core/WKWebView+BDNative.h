//
//  WKWebView+BDNative.h
//  BDNativeWebView
//
//  Created by liuyunxuan on 2019/6/15.
//  Copyright © 2019 liuyunxuan. All rights reserved.
//
#import <WebKit/WebKit.h>

@interface WKWebView (BDNative)

/**
 * 开启native功能，只能使用通过全局注册的native组件
 */
- (void)enableNative;

/**
 * 开启native功能，传入的组件只针对于webview实例，如果tagName一致，会使用传入的组件
 */
- (void)enableNativeWithComponents:(nullable NSArray<Class> *)components;

/**
 * 注册全局native组件，通过enableNative调用的webview实例都可以支持该组件
 */
+ (void)registerGlobalNativeWithComponents:(nullable NSArray<Class> *)components;

/**
 * 清理web组件实例，在webviewdidstartload的时候可以调用，如果有页面内跳转
 */
- (void)clearNativeComponent;

/**
 *
 */
- (void)bdNativefireEvent:(nonnull NSString *)event data:(nullable NSDictionary *)data;


// 支持解决按钮点击失效的新方案,用来做setting开关，后续会干掉，目前默认关闭
- (void)bdNativeEnableNewHandleTouchInvalid:(BOOL)enable;

@end
