//
//  OKJSMethodManager.h
//  IESWebKit
//
//  Created by Lizhen Hu on 2019/7/19.
//

#import <Foundation/Foundation.h>
#import "OKJSBridgeDefines.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString * const OKJSMethodKeyInvokeMethod;
extern NSString * const OKJSMethodKeyHandleMessageFromNative;
extern NSString * const OKJSMethodKeyFetchQueue;
extern NSString * const OKJSMethodKeyHanlderName;

extern NSString * const IESPiperOnMethodParamsHandler;

@interface OKJSMethod : NSObject

@property (nonatomic, copy, readonly) NSString *bridgeName;
@property (nonatomic, copy, readonly) NSString *methodName;
@property (nonatomic, copy, readonly) NSString *fullName;

@end


typedef void (^OKJSMethodQueryingHandler)(OKJSMethod * _Nullable method);
typedef void (^OKJSMethodCheckingHandler)(OKJSMethod *method, BOOL defined);

@protocol OKJSBridgeExecutor;

@interface OKJSMethodManager : NSObject

+ (instancetype)managerWithBridgeExecutor:(id<OKJSBridgeExecutor>)bridgeExecutor;

+ (NSString *)injectionScriptWithJSMethod:(OKJSMethod *)method messageHandler:(NSString *)messageHandler;
+ (NSString *)injectionScriptWithJSMethods:(NSArray<OKJSMethod *> *)methods messageHandler:(NSString *)messageHandler;

- (NSDictionary<IESPiperProtocolVersion, OKJSMethod *> *)allJSMethodsForKey:(NSString *)key;
- (NSArray<IESPiperProtocolVersion> *)allHandlerNames;

- (void)queryPreferredJSMethodForKey:(NSString *)key withHandler:(OKJSMethodQueryingHandler)handler;
- (void)checkAllJSMethodsDefinedForKey:(NSString *)key withHandler:(OKJSMethodCheckingHandler)handler;

- (void)deleteAllPipers;

@end

NS_ASSUME_NONNULL_END
