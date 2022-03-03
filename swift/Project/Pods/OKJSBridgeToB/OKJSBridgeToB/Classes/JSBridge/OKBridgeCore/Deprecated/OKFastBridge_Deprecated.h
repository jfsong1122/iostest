//
//  OKFastBridge_Deprecated.h
//  IESWebKit
//
//  Created by li keliang on 2019/4/7.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "OKJSBridgeEngine_Deprecated.h"

NS_ASSUME_NONNULL_BEGIN

@interface OKFastBridge_Deprecated : NSObject

+ (void)injectionBridgeIntoWKWebView:(WKWebView *)webView;
+ (void)injectionBridge:(OKJSBridgeEngine_Deprecated *)bridgeEngine intoWKWebView:(WKWebView *)webView;

@end

@interface WKWebView (OKFastBridge_Deprecated)

@property (nonatomic, readonly, nullable) OKJSBridgeEngine_Deprecated *iesFastBridge;

@end

NS_ASSUME_NONNULL_END
