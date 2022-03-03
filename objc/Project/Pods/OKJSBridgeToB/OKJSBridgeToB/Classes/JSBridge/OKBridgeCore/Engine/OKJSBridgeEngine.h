//
//  OKJSBridgeEngine.h
//  IESWebKit
//
//  Created by li keliang on 2019/4/8.
//

#import <WebKit/WebKit.h>
#import "OKJSBridgeMethod.h"
#import "OKJSBridgeDefines.h"

NS_ASSUME_NONNULL_BEGIN

#define IES_EXPORT_BRIDGE_METHOD(js_name_, auth_type_, method_) _IES_EXPORT_BRIDGE_METHOD(js_name_, auth_type_, method_, __COUNTER__)

@class OKJSBridgeMethod, OKJSBridgeMessage, OKJSMethod, OKJSBridgeEngine;
@protocol OKJSBridgeEngineDelegate, OKJSBridgeEngineInterceptor, OKJSBridgeExecutor;

typedef void (^OKJSBridgeExecutorCompletion)(id _Nullable result, NSError * _Nullable error);

typedef void (^OKJSCallbackHandler)(id _Nullable result);

typedef NSDictionary * _Nullable (^OKJSCallHandler)(NSString * _Nullable callbackId, NSDictionary * _Nullable result, NSString * _Nullable JSSDKVersion, BOOL * _Nullable executeCallback);

#pragma mark - OKJSBridgeEngine

@interface OKJSBridgeEngine : NSObject

@property (nonatomic, weak) id<OKJSBridgeEngineDelegate> delegate;
@property (nonatomic, weak) id<OKJSBridgeEngineInterceptor> interceptor;
@property (nonatomic, weak, readonly) id<OKJSBridgeExecutor> executor;
@property (nonatomic, copy, readonly) NSArray<OKJSBridgeMethod *> *methods;

- (instancetype)initWithExecutor:(id<OKJSBridgeExecutor>)executor;

- (void)registerHandler:(OKJSCallHandler)handler forJSMethod:(NSString *)method authType:(OKPiperAuthType)authType;
- (void)registerHandler:(OKJSCallHandler)handler forJSMethod:(NSString *)method authType:(OKPiperAuthType)authType methodNamespace:(NSString *)methodNameSpace;
- (void)invokeJSWithCallbackID:(NSString *)callbackID statusCode:(OKPiperStatusCode)statusCode params:(nullable NSDictionary *)params;
- (void)invokeCallbackWithMessage:(OKJSBridgeMessage *)message statusCode:(OKPiperStatusCode)statusCode resultBlock:(nullable OKJSCallbackHandler)resultBlock;
- (void)fireEvent:(NSString *)eventID withParams:(NSDictionary *)params  status:(OKPiperStatusCode)status callback:(OKJSCallbackHandler)callback;
- (void)fireEvent:(NSString *)eventID withParams:(nullable NSDictionary *)params callback:(nullable OKJSCallbackHandler)callback;
- (void)fireEvent:(NSString *)eventID withParams:(nullable NSDictionary *)params;

- (void)handleBridgeMessage:(OKJSBridgeMessage *)message;
- (void)flushBridgeMessages;
- (void)deleteAllPipers;

// 如果需要添加多个 interceptor, 请使用 addInterceptor 方法
+ (void)addInterceptor:(id<OKJSBridgeEngineInterceptor>)interceptor;
+ (void)removeInterceptor:(id<OKJSBridgeEngineInterceptor>)interceptor;
@end


#pragma mark - OKJSBridgeEngineDelegate

@protocol OKJSBridgeEngineDelegate <NSObject>

@optional
- (void)bridgeEngine:(OKJSBridgeEngine *)engine didExcuteMethod:(OKJSBridgeMethod *)method;
- (void)bridgeEngine:(OKJSBridgeEngine *)engine didReceiveUnauthorizedMethod:(OKJSBridgeMethod *)method;
- (void)bridgeEngine:(OKJSBridgeEngine *)engine didReceiveUnregisteredMessage:(OKJSBridgeMessage *)bridgeMessage;

@end


#pragma mark - OKJSBridgeEngineInterceptor

@protocol OKJSBridgeEngineInterceptor <NSObject>

@optional
- (BOOL)bridgeEngine:(OKJSBridgeEngine *)engine shouldHandleBridgeMessage:(OKJSBridgeMessage *)bridgeMessage;
- (BOOL)bridgeEngine:(OKJSBridgeEngine *)engine shouldCallbackUnregisteredMessage:(OKJSBridgeMessage *)bridgeMessage;

- (void)bridgeEngine:(OKJSBridgeEngine *)engine willHandleBridgeMessage:(OKJSBridgeMessage *)bridgeMessage;
- (void)bridgeEngine:(OKJSBridgeEngine *)engine didHandleBridgeMessage:(OKJSBridgeMessage *)bridgeMessage;

- (void)bridgeEngine:(OKJSBridgeEngine *)engine willCallbackWithMessage:(OKJSBridgeMessage *)bridgeMessage;
- (void)bridgeEngine:(OKJSBridgeEngine *)engine didCallbackWithMessage:(OKJSBridgeMessage *)bridgeMessage;

- (void)bridgeEngine:(OKJSBridgeEngine *)engine willFireEventWithMessage:(OKJSBridgeMessage *)bridgeMessage;
- (void)bridgeEngine:(OKJSBridgeEngine *)engine didFireEventWithMessage:(OKJSBridgeMessage *)bridgeMessage;

- (void)bridgeEngine:(OKJSBridgeEngine *)engine willFetchQueueWithInfo:(NSMutableDictionary *)information;
- (void)bridgeEngine:(OKJSBridgeEngine *)engine didFetchQueueWithInfo:(NSMutableDictionary *)information;

@end


#pragma mark - OKJSBridgeExecutor

@protocol OKJSBridgeExecutor <NSObject>

@required
- (OKJSBridgeEngine *)ies_bridgeEngine;
- (nullable NSURL *)ies_url;
- (NSURL*)ies_commitURL;
- (void)set_iesCommitURL:(NSURL*)url;
- (void)ies_executeJavaScript:(NSString *)javaScriptString completion:(nullable OKJSBridgeExecutorCompletion)completion;

@optional
- (NSString *)ies_namespace;

@end


NS_ASSUME_NONNULL_END
