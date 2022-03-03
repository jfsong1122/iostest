//
//  OKWebViewBridgeEngine.h
//  NewsInHouse
//
//  Created by lizhuopeng on 2018/10/23.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "OKBridgeEngine.h"
#import "OKBridgeAuthorization.h"
#import "OKBridgeRegister.h"

NS_ASSUME_NONNULL_BEGIN

@class OKWebViewBridgeEngine;



@interface WKWebView (OKBridge)

@property (nonatomic, strong, readonly) OKWebViewBridgeEngine *tt_engine;

- (void)tt_installBridgeEngine:(OKWebViewBridgeEngine *)bridge;
- (void)tt_uninstallBridgeEngine;

@end

@interface OKWebViewBridgeEngine : NSObject<OKBridgeEngine>

@property (nonatomic, weak, readonly, nullable) UIViewController *sourceController;

@property (nonatomic, strong, readonly, nullable) NSURL *sourceURL;

@property (nonatomic, weak, readonly) NSObject *sourceObject;


- (void)installOnWKWebView:(WKWebView *)webView;
- (void)uninstallFromWKWebView:(WKWebView *)webView;

- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(nullable void (^)(id result, NSError *error))completionHandler;

+ (void)postEventNotification:(OKBridgeName)bridgeName params:(nullable NSDictionary *)params;
+ (void)postEventNotification:(OKBridgeName)bridgeName msg:(OKBridgeMsg)msg params:(nullable NSDictionary *)params resultBlock:(nullable void (^)(NSString *))resultBlock;

// Default authorization is [OKBridgeAuthManager sharedManager].
- (instancetype)initWithAuthorization:(nullable id<OKBridgeAuthorization>)authorization;

@property (nonatomic, strong, nullable) id<OKBridgeAuthorization> authorization;

@property(nonatomic, strong, readonly) OKBridgeRegister *bridgeRegister;

@property(nonatomic, weak, readonly, nullable) WKWebView *wkWebView;


/// When this property is YES, bytedance://dispatch_message will be Intercepted. And it is YES by default.
@property(nonatomic, assign) BOOL schemaInterceptionEnabled;

@property(nonatomic, strong, class, readonly) NSHashTable *webViewEngines;

@end

@interface OKWebViewBridgeEngine (AuthManager)
- (id<OKBridgeAuthorization>)defaultAuthManager;
@end

NS_ASSUME_NONNULL_END
