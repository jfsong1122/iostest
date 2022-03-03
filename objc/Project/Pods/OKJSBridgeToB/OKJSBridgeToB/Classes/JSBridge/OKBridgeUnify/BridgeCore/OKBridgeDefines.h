//
//  OKBridgeDefines.h
//  OKBridgeUnify
//
//  Modified from OKRexxar of muhuai.
//  Created by lizhuopeng on 2018/10/30.
//

#import <Foundation/Foundation.h>
#import "OKSectionFunction.h"

NS_ASSUME_NONNULL_BEGIN

#define OKRegisterBridgeKey "OKRegisterBridgeKey"
#define OKRegisterBridgeFunction OK_FUNCTION_EXPORT(OKRegisterBridgeKey)

typedef NS_OPTIONS(NSInteger, OKBridgeRegisterEngineType) {
    OKBridgeRegisterWebView = 1 << 0,
    OKBridgeRegisterAll = OKBridgeRegisterWebView
};

#define OK_BRIDGE_EXPORT_HANDLER(NAME) - (void)NAME##WithParam:(NSDictionary *)param callback:(OKBridgeCallback)callback engine:(id<OKBridgeEngine>)engine controller:(UIViewController *)controller;

/**
 This Macro can be used to ensure the existence of the native method when register a JSB.
 
 Examples：
 OKRegisterAllBridge(OKClassBridgeMethod(OKAppBridge, appInfo), @"app.getAppInfo");
 is equal to
 OKRegisterAllBridge(@"OKAppBridge.appInfo", @"app.getAppInfo");
 
 When the method doesn't exist, the compiler will throw an error!
 */
#define OKClassBridgeMethod(CLASS, METHOD) \
((void)(NO && ((void)[((CLASS *)(nil)) METHOD##WithParam:nil callback:nil engine:nil controller:nil], NO)), [NSString stringWithFormat:@"%@.%@", @(#CLASS), @(#METHOD)])


#define OKBRIDGE_CALLBACK_SUCCESS \
if (callback) {\
callback(OKBridgeMsgSuccess, @{}, nil);\
}\

#define OKBRIDGE_CALLBACK_FAILED \
if (callback) {\
callback(OKBridgeMsgFailed, @{}, nil);\
}\

#define OKBRIDGE_CALLBACK_FAILED_MSG(msg) \
if (callback) {\
callback(OKBridgeMsgFailed, @{@"msg": [NSString stringWithFormat:msg]? :@""}, nil);\
}\

#define OKBRIDGE_CALLBACK_WITH_MSG(status, msg) \
if (callback) {\
callback(status, @{@"msg": [NSString stringWithFormat:msg]? [NSString stringWithFormat:msg] :@""}, nil);\
}\

#define OKBRIDGE_CALLBACK_FAILED_MSG_FORMAT(format, ...) \
    if (callback) {\
        callback(OKBridgeMsgFailed, @{@"msg": [NSString stringWithFormat:format, ##__VA_ARGS__] ?: @""}, nil);\
    }\

#define OKBRIDGE_CALLBACK_WITH_MSG_FORMAT(status, format, ...) \
    if (callback) {\
        callback(status, @{@"msg": [NSString stringWithFormat:format, ##__VA_ARGS__] ?: @""}, nil);\
    }\

#ifndef isEmptyString
#define isEmptyString(str) (!str || ![str isKindOfClass:[NSString class]] || str.length == 0)
#endif

#ifndef tt_dispatch_async_safe
#define tt_dispatch_async_safe(queue, block)\
if (dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL) == dispatch_queue_get_label(queue)) {\
    block();\
} else {\
    dispatch_async(queue, block);\
}
#endif

#ifndef tt_dispatch_async_main_thread_safe
#define tt_dispatch_async_main_thread_safe(block) tt_dispatch_async_safe(dispatch_get_main_queue(), block)
#endif

#ifndef stringify
#define stringify(s) #s
#endif

typedef NS_ENUM(NSUInteger, OKBridgeInstanceType) {
    OKBridgeInstanceTypeNormal, //Different plugin Instance in different Piper call. (This type is default and recommended.)
    OKBridgeInstanceTypeGlobal, //A global singleton plugin, +(instance)sharedPlugin must be implemented.
    OKBridgeInstanceTypeAssociated, //A singleton plugin for the source object, the plugin is initialized in the initiation of the engine.
};

typedef NS_ENUM(NSUInteger, OKBridgeAuthType){
    OKBridgeAuthNotRegistered = 0, 
    OKBridgeAuthPublic = 1, // The bridge can be called by all domains.
    OKBridgeAuthProtected, // The bridge can be called by inner domains and domains from Allowlist.
    OKBridgeAuthPrivate, // The bridge can only be called by inner domains.
    OKBridgeAuthSecure // The bridge can only be called by adding domains into 'included' group on Gecko.
};

typedef NS_ENUM(NSInteger, OKBridgeMsg){
    OKBridgeMsgUnknownError   = -1000,
    OKBridgeMsgManualCallback = -999,
    OKBridgeMsgCodeUndefined      = -998,
    OKBridgeMsgCode404            = -997,
    OKBridgeMsgSuccess = 1,
    OKBridgeMsgFailed = 0,
    OKBridgeMsgParamError = -3,
    OKBridgeMsgNoHandler = -2,
    OKBridgeMsgNoPermission = -1
};

typedef void(^OKBridgeCallback)(OKBridgeMsg msg, NSDictionary * _Nullable params, void(^ _Nullable resultBlock)(NSString *result));

typedef NSString * OKBridgeName;

typedef void(^OKBridgePluginHandler)(NSDictionary * _Nullable params, OKBridgeCallback callback);
NS_ASSUME_NONNULL_END
