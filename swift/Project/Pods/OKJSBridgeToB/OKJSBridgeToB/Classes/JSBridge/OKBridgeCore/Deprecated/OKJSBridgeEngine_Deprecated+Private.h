//
//  OKJSBridgeEngine_Deprecated+Private.h
//  IESWebKit
//
//  Created by li keliang on 2019/4/11.
//

#import "OKJSBridgeEngine_Deprecated.h"

NS_ASSUME_NONNULL_BEGIN

@interface OKJSBridgeEngine_Deprecated (Private)

- (void)executeMethodsWithMessage:(OKJSBridgeMessage *)message;
- (void)sendBridgeMessage:(OKJSBridgeMessage *)message;

@end

NS_ASSUME_NONNULL_END
