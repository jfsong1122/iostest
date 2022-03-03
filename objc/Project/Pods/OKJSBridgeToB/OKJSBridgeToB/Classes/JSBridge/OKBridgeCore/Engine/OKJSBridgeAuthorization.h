//
//  OKJSBridgeAuthorization.h
//  OKJSBridgeCore
//
//  Created by bytedance on 2021/2/24.
//

#import <Foundation/Foundation.h>
#import "OKJSBridgeDefines.h"

NS_ASSUME_NONNULL_BEGIN

@protocol OKJSBridgeAuthProtocol <NSObject>

+ (void)registerMethod:(NSString *)method withAuthType:(OKPiperAuthType)authType;

+ (void)registerMethod:(NSString *)method withAuthType:(OKPiperAuthType)authType inMethodNameSpace:(NSString *)methodNameSpace;

+ (BOOL)isAuthorizedMethod:(NSString *)method forURL:(NSURL *)url;

+ (BOOL)isAuthorizedMethod:(NSString *)method forURL:(NSURL *)url inMethodNameSpace:(NSString *)methodNameSpace;

@end

@interface OKJSBridgeAuthorization : NSObject

@end

@interface OKJSBridgeAuthorization (AuthManager) <OKJSBridgeAuthProtocol>

@end

NS_ASSUME_NONNULL_END
