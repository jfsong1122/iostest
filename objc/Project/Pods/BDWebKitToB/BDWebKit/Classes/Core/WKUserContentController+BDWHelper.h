//
//  WKUserContentController+BDWHelper.h
//  BDWebKit
//
//  Created by caiweilong on 2020/4/2.
//

#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^WebViewLogHandler)(id msg);

typedef void(^WKScriptMessageHandler)(WKScriptMessage *msg);

@interface WKUserContentController(BDWHelper)

//添加script方法
- (void)bdw_register:(NSString *)handelName handle:(WKScriptMessageHandler)handle;
- (void)bdw_unregister:(NSString *)handelName;

/// 通过JS注入和JSBridge, 在Native端监听window.console.log打出的日志
- (void)bdw_installHookConsoleLog:(WebViewLogHandler)handle;

- (void)bdw_hookCookieSync;

@end

NS_ASSUME_NONNULL_END
