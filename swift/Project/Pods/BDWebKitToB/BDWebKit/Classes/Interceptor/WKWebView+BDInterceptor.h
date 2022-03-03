//
//  WKWebView+BDInterceptor.h
//  BDWebKit
//
//  Created by caiweilong on 2020/3/29.
//

#import <WebKit/WebKit.h>
#import "BDWebInterceptor.h"

NS_ASSUME_NONNULL_BEGIN

@interface WKWebViewConfiguration (BDInterceptor)

- (void)bdw_installURLSchemeHandler API_AVAILABLE(ios(12.0));

@end

NS_ASSUME_NONNULL_END
