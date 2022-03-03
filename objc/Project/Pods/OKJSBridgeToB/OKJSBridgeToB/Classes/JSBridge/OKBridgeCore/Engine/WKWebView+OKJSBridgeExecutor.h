//
//  WKWebView+OKJSBridgeExecutor.h
//  IESWebKit
//
//  Created by li keliang on 2019/10/10.
//

#import <WebKit/WebKit.h>
#import "OKJSBridgeEngine.h"

NS_ASSUME_NONNULL_BEGIN

@interface WKWebView (OKJSBridgeExecutor) <OKJSBridgeExecutor>

- (OKJSBridgeEngine *)ies_bridgeEngine;

@end

NS_ASSUME_NONNULL_END
