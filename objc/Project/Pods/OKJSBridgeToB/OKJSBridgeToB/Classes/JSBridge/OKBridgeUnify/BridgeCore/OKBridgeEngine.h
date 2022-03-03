//
//  OKBridgeEngine
//  OKBridgeUnify
//
//  Modified from OKRexxar of muhuai.
//  Created by lizhuopeng on 2018/10/30.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OKBridgeDefines.h"

NS_ASSUME_NONNULL_BEGIN

@protocol OKBridgeAuthorization;
@class OKBridgeRegister;

@protocol OKBridgeEngine <NSObject>

@required

/**
 The source ViewController of the engine.
 */
@property (nonatomic, weak, nullable) UIViewController *sourceController;

/**
 The url of the current webpage of the engine.
 */
@property (nonatomic, strong, readonly, nullable) NSURL *sourceURL;

/**
 The source object of the engine, and it is a webView generally.
 */
@property (nonatomic, weak, readonly) NSObject *sourceObject;

/**
 The local register. Bridges registered by the local register can only be used in the register's engine. The bridge registered by the local register is prefered when bridge's name is same.
 */
@property(nonatomic, strong, readonly) OKBridgeRegister *bridgeRegister;

@optional
/**
 The authorization of bridges. It can be customized and it is nil by default, which means all bridges are public.
 */
@property (nonatomic, strong) id<OKBridgeAuthorization> authorization;

- (OKBridgeRegisterEngineType)engineType;

- (void)fireEvent:(OKBridgeName)eventName params:(nullable NSDictionary *)params;
- (void)fireEvent:(OKBridgeName)eventName msg:(OKBridgeMsg)msg params:(nullable NSDictionary *)params;
- (void)fireEvent:(OKBridgeName)eventName params:(nullable NSDictionary *)params resultBlock:(nullable void (^)(NSString * _Nullable))resultBlock;
- (void)fireEvent:(OKBridgeName)eventName msg:(OKBridgeMsg)msg params:(nullable NSDictionary *)params resultBlock:(nullable void (^)(NSString * _Nullable))resultBlock;

- (BOOL)respondsToBridge:(OKBridgeName)bridgeName;

#pragma mark - deprecated
- (void)callbackBridge:(OKBridgeName)bridgeName params:(nullable NSDictionary *)params __deprecated_msg("Use -[OKBridgeEngine fireEvent:params:]");
- (void)callbackBridge:(OKBridgeName)bridgeName params:(nullable NSDictionary *)params resultBlock:(nullable void (^)(NSString * _Nullable))resultBlock __deprecated_msg("Use -[OKBridgeEngine fireEvent:params:resultBlock:]");
- (void)callbackBridge:(OKBridgeName)bridgeName msg:(OKBridgeMsg)msg params:(nullable NSDictionary *)params resultBlock:(nullable void (^)(NSString * _Nullable))resultBlock __deprecated_msg("Use -[OKBridgeEngine fireEvent:msg:params:resultBlock:]");

@end
NS_ASSUME_NONNULL_END
