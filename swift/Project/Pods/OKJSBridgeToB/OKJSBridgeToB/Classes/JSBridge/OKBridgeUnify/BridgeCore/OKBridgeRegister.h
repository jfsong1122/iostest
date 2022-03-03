//
//  BridgeRegister.h
//  Pods
//
//  Created by renpeng on 2018/10/9.
//

#import <Foundation/Foundation.h>
#import "OKBridgePlugin.h"
#import "OKBridgeDefines.h"
#import "OKBridgeCommand.h"
#import "OKBridgeEngine.h"

NS_ASSUME_NONNULL_BEGIN


@protocol OKBridgeInterceptor;


FOUNDATION_EXTERN void OKRegisterBridge(OKBridgeRegisterEngineType engineType,
                             NSString *pluginName,
                             OKBridgeName bridgeName,
                             OKBridgeAuthType authType,
                             NSArray<NSString *> * _Nullable domains);

FOUNDATION_EXTERN void OKRegisterWebViewBridge(NSString *pluginName, OKBridgeName bridgeName);

FOUNDATION_EXTERN void OKRegisterAllBridge(NSString *pluginName, OKBridgeName bridgeName);

@interface OKBridgeMethodInfo : NSObject

@property (nonatomic, copy, readonly) NSDictionary<NSNumber*, NSNumber*> *authTypes;

@end

typedef void(^OKBridgeHandler)(NSDictionary * _Nullable params, OKBridgeCallback callback, id<OKBridgeEngine> engine, UIViewController * _Nullable controller);


@interface OKBridgeRegisterMaker : NSObject

@property (nonatomic, copy, readonly, nullable) OKBridgeRegisterMaker *(^authType)(OKBridgeAuthType authType);//Default: OKBridgeAuthProtected.
@property (nonatomic, copy, readonly, nullable) OKBridgeRegisterMaker *(^pluginName)(NSString *pluginName);
@property (nonatomic, copy, readonly, nullable) OKBridgeRegisterMaker *(^bridgeName)(NSString *bridgeName);
@property (nonatomic, copy, readonly, nullable) OKBridgeRegisterMaker *(^engineType)(OKBridgeRegisterEngineType engineType);//Default: OKBridgeRegisterAll.
@property (nonatomic, copy, readonly, nullable) OKBridgeRegisterMaker *(^privateDomains)(NSArray<NSString *> *domains);//This needs be configured when registering private bridges.
@property (nonatomic, copy, readonly, nullable) OKBridgeRegisterMaker *(^handler)(OKBridgeHandler handler);//The bridge can also be implemented By sending a block.
@property (nonatomic, copy, readonly, nullable) OKBridgeRegisterMaker *(^extraInfo)(NSDictionary *extraInfo);//This property is the extra info needed to send to the front-end for local bridge.
@end

@protocol OKBridgeDocumentor <NSObject>

- (void)documentizeBridge:(OKBridgeName)bridgeName authType:(OKBridgeAuthType)authType engineType:(OKBridgeRegisterEngineType)engineType desc:(nullable NSString *)desc;

@end

@interface OKBridgeRegister : NSObject

@property(nonatomic, weak, class) id<OKBridgeDocumentor> documentor;

+ (instancetype)sharedRegister;

- (void)registerMethod:(OKBridgeName)bridgeName
            engineType:(OKBridgeRegisterEngineType)engineType
              authType:(OKBridgeAuthType)authType
               domains:(NSArray<NSString *> *)domains;

- (void)registerMethod:(OKBridgeName)bridgeName
               handler:(nullable OKBridgeHandler)handler
            engineType:(OKBridgeRegisterEngineType)engineType
              authType:(OKBridgeAuthType)authType
               domains:(nullable NSArray<NSString *> *)domains;


- (BOOL)respondsToBridge:(OKBridgeName)bridgeName;
- (OKBridgeMethodInfo *)methodInfoForBridge:(OKBridgeName)bridgeName;
- (NSMutableArray *)privateBridgesOfDomain:(NSString *)domain;

- (void)registerBridge:(void(^)(OKBridgeRegisterMaker *maker))block;
- (void)unregisterBridge:(OKBridgeName)bridgeName;

- (void)executeCommand:(OKBridgeCommand *)command engine:(id<OKBridgeEngine>)engine completion:(OKBridgeCallback)completion;

#pragma mark - deprecated
- (BOOL)bridgeHasRegistered:(OKBridgeName)bridgeName __deprecated_msg("Use -[OKBridgeRegister respondsToBridge:");


/// If the engine has not only one interceptor, please use +[OKBridgeRegister addInterceptor:] to add interceptors.
@property(nonatomic, weak, class) id<OKBridgeInterceptor> interceptor;

+ (void)addInterceptor:(id<OKBridgeInterceptor>)interceptor;
+ (void)removeInterceptor:(id<OKBridgeInterceptor>)interceptor;

+ (BOOL)bridgeEngine:(id<OKBridgeEngine>)engine shouldHandleGlobalBridgeCommand:(OKBridgeCommand *)command;
+ (BOOL)bridgeEngine:(id<OKBridgeEngine>)engine shouldHandleLocalBridgeCommand:(OKBridgeCommand *)command;
+ (void)bridgeEngine:(id<OKBridgeEngine>)engine willExecuteBridgeCommand:(OKBridgeCommand *)command;
+ (BOOL)bridgeEngine:(id<OKBridgeEngine>)engine shouldCallbackUnregisteredCommand:(OKBridgeCommand *)command;
+ (void)bridgeEngine:(id<OKBridgeEngine>)engine willCallbackBridgeCommand:(OKBridgeCommand *)command;

@end

@protocol OKBridgeInterceptor <NSObject>

@optional
+ (BOOL)bridgeEngine:(id<OKBridgeEngine>)engine shouldHandleGlobalBridgeCommand:(OKBridgeCommand *)command;
+ (BOOL)bridgeEngine:(id<OKBridgeEngine>)engine shouldHandleLocalBridgeCommand:(OKBridgeCommand *)command;
+ (void)bridgeEngine:(id<OKBridgeEngine>)engine willExecuteBridgeCommand:(OKBridgeCommand *)command;
+ (BOOL)bridgeEngine:(id<OKBridgeEngine>)engine shouldCallbackUnregisteredCommand:(OKBridgeCommand *)command;
+ (void)bridgeEngine:(id<OKBridgeEngine>)engine willCallbackBridgeCommand:(OKBridgeCommand *)command;

- (BOOL)bridgeEngine:(id<OKBridgeEngine>)engine shouldHandleGlobalBridgeCommand:(OKBridgeCommand *)command;
- (BOOL)bridgeEngine:(id<OKBridgeEngine>)engine shouldHandleLocalBridgeCommand:(OKBridgeCommand *)command;
- (void)bridgeEngine:(id<OKBridgeEngine>)engine willExecuteBridgeCommand:(OKBridgeCommand *)command;
- (BOOL)bridgeEngine:(id<OKBridgeEngine>)engine shouldCallbackUnregisteredCommand:(OKBridgeCommand *)command;
- (void)bridgeEngine:(id<OKBridgeEngine>)engine willCallbackBridgeCommand:(OKBridgeCommand *)command;

@end

@interface OKBridgeRegister (AuthManager)
- (void)registerForAuthManagerWithMethod:(NSString *)method authType:(OKBridgeAuthType)authType;
@end

NS_ASSUME_NONNULL_END
