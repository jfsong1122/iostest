//
//  OKJSBridgeEngine_Deprecated.h
//  IESWebKit
//
//  Created by li keliang on 2019/4/8.
//

#import "OKJSBridgeEngine.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - OKJSBridgeEngine_Deprecated

@protocol OKJSBridgeEngineDelegate_Deprecated;

@interface OKJSBridgeEngine_Deprecated : NSObject

+ (void)addGlobalMethod:(OKJSBridgeMethod *)method;

- (instancetype)init NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readwrite, weak) id<OKJSBridgeExecutor> executor;
@property (nonatomic, weak) id<OKJSBridgeEngineDelegate_Deprecated> delegate;

- (void)addMethod:(OKJSBridgeMethod *)method;

- (void)removeAllMethods;

@property (nonatomic, readonly, copy) NSArray<OKJSBridgeMethod *> *methods;

- (void)sendEvent:(NSString*)event params:(NSDictionary * __nullable)params;

@end


#pragma mark - OKJSBridgeEngineDelegate_Deprecated

@protocol OKJSBridgeEngineDelegate_Deprecated <NSObject>

- (void)bridgeEngine:(OKJSBridgeEngine_Deprecated *)engine didExcuteMethod:(OKJSBridgeMethod *)method;
- (void)bridgeEngine:(OKJSBridgeEngine_Deprecated *)engine didReceiveUnauthorizedMethod:(OKJSBridgeMethod *)method;
- (void)bridgeEngine:(OKJSBridgeEngine_Deprecated *)engine didReceiveUnregisteredMessage:(OKJSBridgeMessage *)message;

@end


NS_ASSUME_NONNULL_END
