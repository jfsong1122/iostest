//
//  BDWebView+Private.h
//  ByteWebView
//
//  Created by Lin Yong on 2019/1/28.
//

#import <WebKit/WebKit.h>
#import "BDWebView.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDWebView (Private) <WKNavigationDelegate>

@property (nonatomic, strong) WKWebView *webViewWK;
@property (nonatomic, assign) BDWebViewOfflineType offlineType;

/*
 * 在 iOS 11 以下或者 BDWebViewOfflineTypeBetweenStartAndFinishLoad 与 WholeLife 时效果和[NSURLProtocol registerClass:protocol]一样
 * 在BDWebViewOfflineTypeTaskScheme并且系统为iOS 11及以上时，会注册到WebView实例上，各个实例之间相互不影响。
 */
- (void)registerURLProtocolClass:(Class)protocol;
- (void)unregisterURLProtocolClass:(Class)protocol;

@end

NS_ASSUME_NONNULL_END
