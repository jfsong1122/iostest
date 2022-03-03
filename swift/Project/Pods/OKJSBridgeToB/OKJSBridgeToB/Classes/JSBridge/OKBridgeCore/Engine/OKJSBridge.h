//
//  OKJSBridge.h
//
//  Created by willorfang on 2017/8/25.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OKJSBridgeEngine.h"

@protocol OKJSBridgeEngine;
@class OKJSBridgeMessage;

NS_ASSUME_NONNULL_BEGIN

@interface IESPiper : NSObject

#pragma mark - Bridge

// 关联的webView
@property (nonatomic, weak) UIView<OKJSBridgeExecutor> *webView;

// 注册的JS可调用方法集合
@property (nonatomic, strong, readonly) NSMutableSet *publicCallSet;
@property (nonatomic, strong, readonly) NSMutableSet *protectedSet;
@property (nonatomic, strong, readonly) NSMutableSet *privateSet;

- (instancetype)initWithWebView:(UIView<OKJSBridgeExecutor> *)webView NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;    // Override `-[IESPiper initWithWebView:]` instead

#pragma mark - Registration

/*
 * @brief 注册可供JS端调用的Native方法
 *
 * handler  注册的Native方法
 * method   JS端使用的方法名称
 * authType 方法的使用者权限
 */
- (void)registerHandlerBlock:(OKJSCallHandler)handler forJSMethod:(NSString*)method authType:(OKPiperAuthType)authType;

/*
 * @brief 注册可供JS端调用的Native方法
 *
 * handler         注册的Native方法
 * method          JS端使用的方法名称
 * authType        方法的使用者权限
 * methodNamespace 方法所属的命名空间
 */
- (void)registerHandlerBlock:(OKJSCallHandler)handler forJSMethod:(NSString*)method authType:(OKPiperAuthType)authType methodNamespace:(NSString *)methodNamespace;

/*
 * @brief 调用JS端的方法（callback）
 *
 * callbackID   callbackID
 * tParameters  调用callback使用的参数
 */
- (void)invokeJSWithCallbackID:(NSString*)callbackID parameters:(NSDictionary*)tParameters;

/*
 * @brief 向JS端发送事件
 *
 * eventID      eventID
 * tParameters  event的参数
 * finishBlock  完成的回调函数
 */
- (void)invokeJSWithEventID:(NSString*)eventID parameters:(NSDictionary*)tParameters finishBlock:(OKJSCallbackHandler)finishBlock;

+ (NSString*)currentJSSDKVersion;

- (void)flushMessages;
- (BOOL)isAuthorizedForCall:(NSString *)functionName;

@end

NS_ASSUME_NONNULL_END
