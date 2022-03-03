//
//  VEH5WebView.h
//  Aurum
//
//  Created by 李晓鹏 on 2021.
//

#import <UIKit/UIKit.h>
#import <BDH5WebView/BDWebView.h>
#import <BDXBridgeKitToB/BDXBridgeMethod.h>
@class VEH5WebView;

NS_ASSUME_NONNULL_BEGIN

@protocol VEH5WebViewDelegate <NSObject>

@optional
- (void)webViewDidStartLoad:(VEH5WebView *)webView;
- (void)webViewDidFinishLoad:(VEH5WebView *)webView;
- (void)webViewDidTerminate:(VEH5WebView *)webView;
- (void)webViewDidLayoutSubviews:(VEH5WebView *)webView;
- (void)webView:(VEH5WebView *)webView didFailLoadWithError:(NSError *)error;
- (BOOL)webView:(VEH5WebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(BDWebViewNavigationType)navigationType;
- (BOOL)webView:(VEH5WebView *)webView decidePolicyForNavigationResponse:(WKNavigationResponse *)response;
- (void)webView:(VEH5WebView *)webView renderingProgressDidChange:(BDRenderingProgressEvents)progressEvents;

- (void)webView:(VEH5WebView *)webView didStartProvisionalNavigation:(null_unspecified WKNavigation *)navigation;
- (void)webView:(VEH5WebView *)webView didReceiveServerRedirectForProvisionalNavigation:(null_unspecified WKNavigation *)navigation;
- (void)webView:(VEH5WebView *)webView didFailProvisionalNavigation:(null_unspecified WKNavigation *)navigation withError:(NSError *)error;
- (void)webView:(VEH5WebView *)webView didCommitNavigation:(null_unspecified WKNavigation *)navigation;
- (void)webView:(VEH5WebView *)webView didFailNavigation:(null_unspecified WKNavigation *)navigation withError:(NSError *)error;
- (BOOL)webView:(VEH5WebView *)webView shouldTryOpenUniversalLink:(NSURL *)url API_AVAILABLE(ios(9.0));
- (void)webView:(VEH5WebView *)webView didOpenUniversalLink:(NSURL *)url API_AVAILABLE(ios(10.0));

@end

@protocol VEH5WebViewActionDelegate <NSObject>

@optional
- (void)webView:(VEH5WebView *)webView shouldDragBackDisbale:(BOOL)disable;
- (void)webView:(VEH5WebView *)webView didStartLoadRequest:(NSURLRequest *)request;
- (void)webView:(VEH5WebView *)webView didRefreshDataWithRequest:(NSURLRequest *)request;
- (void)webView:(VEH5WebView *)webView didScrollToContentOffset:(CGPoint)contentOffset;
@end

@interface VEH5WebView : UIView

- (instancetype)initWithFrame:(CGRect)frame;

/**
 * 是否支持离线化
 */
- (instancetype)initWithFrame:(CGRect)frame withOfflineEnable:(BOOL)offlineEnable;

#pragma mark - 基础能力
/**
 * 设置delegate，实现XIGWebViewDelegate，支持一对多回调，内部采用NSHashTable实现，协议回调顺序不保证与添加顺序一致
 */
- (void)addDelegate:(NSObject<VEH5WebViewDelegate> *)delegate;

/**
 * 移除指定delegate
 */
- (void)removeDelegate:(NSObject<VEH5WebViewDelegate> *)delegate;

/**
 * 设置action delegate，实现XIGWebViewActionDelegate，支持一对多回调，内部采用NSHashTable实现，协议回调顺序不保证与添加顺序一致
 */
- (void)addActionDelegate:(NSObject<VEH5WebViewActionDelegate> *)actionDelegate;

/**
 * 移除指定action delegate
 */
- (void)removeActionDelegate:(NSObject<VEH5WebViewActionDelegate> *)actionDelegate;

/**
 * 通过UNSURLRequestf加载页面，默认加载超时300s
 * @params request - the url request
 */
- (void)loadRequest:(NSURLRequest *)request;

/**
 * WebView内部返回上一个页面
 */
- (BOOL)canGoBack;
- (void)goBack;

/**
 * 刷新当前页面
 */
- (void)reload;

/**
 * 当前WebView加载的NSURLRequest，不一定与打开页面的request相同
 */
- (NSURLRequest *)currentRequest;

#pragma mark - UI配置相关
@property (nonatomic, assign) CGFloat progressViewTopInset;

/**
 * 配置WebView背景色，默认白色
 */
- (void)configWebViewBackgroundColor:(UIColor *)backgroundColor;

/**
 * 设置WebView是否支持回弹，默认支持
 */
- (void)setBouncesEnable:(BOOL)bouncesEnable;

/**
 * 设置WebView是否可滚动，默认可滚动
 */
- (void)setScrollEnabled:(BOOL)scrollEnabled;

/**
 * 设置是否显示进度条，默认显示
 */
- (void)setProgressViewHidden:(BOOL)hidden;

/**
 * local bridge 方法只注入到指定容器内，并且会覆盖 global bridge方法实现
 */
- (void)registerLocalMethod:(BDXBridgeMethod *)method;


@end
NS_ASSUME_NONNULL_END
