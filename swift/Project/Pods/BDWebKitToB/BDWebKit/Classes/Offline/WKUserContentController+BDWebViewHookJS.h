//
//  WKUserContentController+BDWebViewHookJS.h
//  BDWebKit
//
//  Created by wealong on 2019/12/15.
//

#import <WebKit/WebKit.h>
#import "WKUserContentController+BDWHelper.h"

typedef void(^WebViewLogHandler)(id _Nullable msg);

NS_ASSUME_NONNULL_BEGIN

@interface WKUserContentController(BDWebViewHookJS)

- (void)bdw_installHookAjax;

- (void)bdw_installNativeDomReady;

@end

NS_ASSUME_NONNULL_END
