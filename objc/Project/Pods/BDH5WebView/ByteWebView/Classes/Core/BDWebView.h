//
//  BDWebView.h
//
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "BDWebViewDetectBlankContent.h"
#import "BDWebViewCommon.h"

typedef NS_ENUM(NSInteger, BDWebViewNavigationType) {
    BDWebViewNavigationTypeLinkClicked,
    BDWebViewNavigationTypeFormSubmitted,
    BDWebViewNavigationTypeBackForward,
    BDWebViewNavigationTypeReload,
    BDWebViewNavigationTypeFormResubmitted,
    BDWebViewNavigationTypeOther
};

NS_ASSUME_NONNULL_BEGIN

/**
 *  值：@(YES) or @(NO)，默认为@(NO)。当为 YES 时，BDWebView 不会往 WKUserContentController 中注入 UserScript
 */
FOUNDATION_EXPORT NSString *const BDWebViewExtraKeyForbiddenAddScriptByBDWebView;
/**
*  值：http proxy的url, e.g: https://accproxy.snssdk.com:8900
*/
FOUNDATION_EXPORT NSString *const BDWebViewExtraKeyHTTPProxy;
/**
*  值：https proxy的url, e.g: https://accproxy.snssdk.com:8900
*/
FOUNDATION_EXPORT NSString *const BDWebViewExtraKeyHTTPSProxy;
/**
*  值：自定义预创建池的precreateKey，用于业务后续根据precreateKey获取到对应预创建的webview
*/
FOUNDATION_EXPORT NSString *const BDWebViewExtraKeyCustomPrecreateKey;

typedef NS_OPTIONS(NSUInteger, BDRenderingProgressEvents) {
    BDRenderingProgressEventFirstLayout = 1 << 0,
    BDRenderingProgressEventFirstVisuallyNonEmptyLayout = 1 << 1,
};

typedef NS_ENUM(NSInteger, BDProcessTerminationReason) {
    BDProcessTerminationReasonExceededMemoryLimit,
    BDProcessTerminationReasonExceededCPULimit,
    BDProcessTerminationReasonRequestedByClient,
    BDProcessTerminationReasonCrash,
} API_AVAILABLE(macos(10.14), ios(12.0));

@protocol BDContentRuleListAction <NSObject>

@property (nonatomic, readonly) BOOL blockedLoad;
@property (nonatomic, readonly) BOOL blockedCookies;
@property (nonatomic, readonly) BOOL madeHTTPS;
@property (nonatomic, readonly, copy) NSArray<NSString *> *notifications;

@end

@class BDWebView;

@protocol BDWebViewDelegate <NSObject>

@optional
- (void)webViewDidStartLoad:(BDWebView *)webView;
- (void)webViewDidFinishLoad:(BDWebView *)webView;
- (void)webViewDidTerminate:(BDWebView *)webView;
- (void)webViewDidLayoutSubviews:(BDWebView *)webView;
- (void)webView:(BDWebView *)webView didFailLoadWithError:(NSError *)error;
- (BOOL)webView:(BDWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(BDWebViewNavigationType)navigationType;
- (BOOL)webView:(BDWebView *)webView decidePolicyForNavigationResponse:(WKNavigationResponse *)response;
- (void)webView:(BDWebView *)webView renderingProgressDidChange:(BDRenderingProgressEvents)progressEvents;

- (void)webView:(BDWebView *)webView didStartProvisionalNavigation:(null_unspecified WKNavigation *)navigation;
- (void)webView:(BDWebView *)webView didReceiveServerRedirectForProvisionalNavigation:(null_unspecified WKNavigation *)navigation;
- (void)webView:(BDWebView *)webView didFailProvisionalNavigation:(null_unspecified WKNavigation *)navigation withError:(NSError *)error;
- (void)webView:(BDWebView *)webView didCommitNavigation:(null_unspecified WKNavigation *)navigation;
- (void)webView:(BDWebView *)webView didFailNavigation:(null_unspecified WKNavigation *)navigation withError:(NSError *)error;

/// return NO 表示即使该链接为UniversalLink也不允许跳转，return YES 表示允许该链接打开
/// @param webView BDWebView
/// @param url http / https链接
- (BOOL)webView:(BDWebView *)webView shouldTryOpenUniversalLink:(NSURL *)url API_AVAILABLE(ios(9.0));
- (void)webView:(BDWebView *)webView didOpenUniversalLink:(NSURL *)url API_AVAILABLE(ios(10.0));
/*
 是否拦截当前URL的加载，Default is NO
 @param webView BDWebView
 @param navigationAction 当前的navigationAction
 */
- (BOOL)webView:(BDWebView *)webView shouldInterceptURLWithNavigationAction:(WKNavigationAction *)navigationAction;

/*
 shouldInterceptURLWithNavigationAction 返回YES后，将拦截到的 Universal Link / Scheme 加载事件回调到上层业务，对于 Universal Link 会禁止自动拉端。
 @param webView BDWebView
 @param navigationAction 当前的navigationAction
 */
- (void)webView:(BDWebView *)webView didInterceptURLWithNavigationAction:(WKNavigationAction *)navigationAction;

/// ttnet代理的请求回调
- (void)webView:(BDWebView *)webview willStartLoadURL:(NSURL *)url;
- (void)webView:(BDWebView *)webview didStartLoadURL:(NSURL *)url;
- (void)webView:(BDWebView *)webview didReceiveResponse:(NSURLResponse *)response;
- (void)webView:(BDWebView *)webview didReceiveData:(NSData *)data forURL:(NSURL *)url;
- (void)webView:(BDWebView *)webview didFinishLoadURL:(NSURL *)url;
- (void)webView:(BDWebView *)webview didFailLoadURL:(NSURL *)url withError:(NSError *)error;
- (void)webView:(BDWebView *)webview didPerformRedirection:(NSURLResponse *)response newRequest:(NSURLRequest *)request;
- (BOOL)webView:(BDWebView *)webview shouldUsePrefetchResponse:(NSHTTPURLResponse *)response withRequest:(NSURLRequest *)request;
- (float)webView:(BDWebView *)webview priorityForRequest:(NSURLRequest *)request;
@end


typedef void(^JavaScriptCompletionBlock)(NSString *_Nullable result, NSError *_Nullable error);

/**
 *  Generic web view class that wraps a UIWebView or WKWebView,
 *  depending on which one is available, as its internal implementation
 */
@interface BDWebView : UIView

/*! @abstract The web view's back-forward list. */
@property (nonatomic, strong, readonly) WKBackForwardList *backForwardList;
@property (nonatomic, assign) BOOL allowsBackForwardNavigationGestures; // 是否开始手势返回，默认NO
@property (nonatomic, strong, readonly) WKWebViewConfiguration *configuration;
@property (nonatomic, weak) id<BDWebViewDelegate> delegate;
///iOS12以上，最近一次webcontent进程崩溃原因
@property (nonatomic, assign) BDProcessTerminationReason lastWebProcessTerminationReason API_AVAILABLE(ios(12.0));
@property (nonatomic, readonly, weak) UIScrollView *scrollView;
@property (nullable, nonatomic, strong) NSString *customUserAgent; // iOS9以上，WKWebView下生效
@property (nullable, nonatomic, weak) id <WKUIDelegate> UIDelegate; // BDWebView有默认实现，可覆盖
@property (nullable, nonatomic, readwrite, copy) void(^consoleLogHandler)(NSString *); //可以用这个实现回调，对WK和UI都生效。也可以使用[WKUserContentController+BDWebViewHookJS bdw_installHookConsoleLog]

- (void)loadFileURL:(NSURL *)URL allowingReadAccessToURL:(NSURL *)readAccessURL;

/**
 * Loads the web view with content returned by an url request
 * @params request - the url request
 */
- (void)loadRequest:(NSURLRequest *)request;

/**
 * Loads the web view with content returned by an url request
 * @params request - the url request
 * @params timeOut - max time imterval to wait for the page to load
 */
- (void)loadRequest:(NSURLRequest *)request timeOut:(NSTimeInterval)timeOut;

/**
* Loads the web view with content returned by an url request and sync cookie
* if reset the cookie, must use this API, otherwise the cookie will be lost
* @params request - the url request
*/
- (void)loadRequestWithSyncCookie:(NSURLRequest *)request;

/**
 * Loads the web view with HTML content
 * @params string - the string to use as the contents of the webpage
 * @params baseURL - a URL that's used for resolving relative URLs within the document
 */
- (void)loadHTMLString:(NSString *)string baseURL:(NSURL *)baseURL;

/*! @abstract Sets the webpage contents and base URL.
 @param data The data to use as the contents of the webpage.
 @param MIMEType The MIME type of the data.
 @param characterEncodingName The data's character encoding name.
 @param baseURL A URL that is used to resolve relative URLs within the document.
 */
- (void)loadData:(NSData *)data MIMEType:(NSString *)MIMEType characterEncodingName:(NSString *)characterEncodingName baseURL:(NSURL *)baseURL;

/**
 * Loads the web view with HTML content
 * @params string - the string to use as the contents of the webpage
 * @params baseURL - a URL that's used for resolving relative URLs within the document
 * @params timeOut - max time imterval to wait for the page to load
 */
- (void)loadHTMLString:(NSString *)string baseURL:(NSURL *)baseURL timeOut:(NSTimeInterval)timeOut;

/**
* pefetch the web view with content returned by an url request
* @params request - the url request
*/
- (void)prefetchRequest:(NSURLRequest *)request;

/**
 * Returns the result of running a script（历史原因：以前 UIWebView 返回的是字符串，所以旧的处理逻辑用的都是字符串，导致如果返回了其他类型会错误）
 * @params script - the script to run
 */
- (void)evaluateJavaScriptFromString:(nullable NSString *)script completionBlock:(nullable JavaScriptCompletionBlock)block;

/*
 Wapper Function For evaluateJavaScriptFromString in WKWebView（上面的接口会将结果强转为字符串，这个不会，直接返回结果）
 */
- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))completionHandler;

/**
 * Stops the loading of web view
 */
- (void)stopLoading;


- (void)reload;

- (void)goBack;
- (void)goForward;

- (void)resumePlayAudios;
- (void)stopAudios;
//
- (void)updateVisibleContentRects;

// 截图
- (void)takeSnapshotWithConfiguration:(nullable WKSnapshotConfiguration *)snapshotConfiguration completionHandler:(void (^)(UIImage * _Nullable snapshotImage, NSError * _Nullable error))completionHandler API_AVAILABLE(ios(11.0));

@property (nonatomic, readonly) NSInteger statusCode;
/**
 * 在WKWebView的情况下，支持KVO
 */
@property (nonatomic, readonly) NSString* pageTitle;
@property (nonatomic, readonly, getter=canGoBack) BOOL canGoBack;
@property (nonatomic, readonly, getter=canGoForward) BOOL canGoForward;
@property (nonatomic, readonly, getter=isLoading) BOOL loading;
@property (nonatomic, readonly) BOOL isLoadFinish;
@property (nonatomic, readonly, strong, nullable) NSURL *URL;
@property (nonatomic, readonly, strong, nullable) NSURLRequest *request;
@property (nonatomic, readonly, strong, nullable) NSURLRequest *originRequest; // loadRequest 的源请求
@property (nonatomic, readonly) double estimatedProgress;
@property (nonatomic, readonly) NSUInteger adBlockHitCount;
@property (nonatomic) BOOL allowsInlineMediaPlayback;
@property (nonatomic,readonly) BOOL mediaPlaybackRequiresUserAction;
@property (nonatomic, assign) BOOL overridecanBecomeFirstResponder;
@property (nullable, nonatomic, strong) NSDictionary *dictExtra;

@property (nullable, nonatomic, strong) NSArray *allowedMenuActions; /// e.g. @[@":copy")], selector should be in UIResponderStandardEditActions. Default: nil

@property (nonatomic, readonly) BOOL requestByTTNet;// TTNet代理网络请求
@property (nonatomic, readonly) BOOL requestByProxy;

@property (nonatomic, assign, getter=isSupportAlert) BOOL supportAlert; // 是否支持前端 alert 弹窗，默认为 YES

@property (nonatomic,readonly) BOOL isWKFromCachePool;

@property (nonatomic,readonly) BOOL isValid;


// 启用 vConsole ,只有 debug 下生效
- (void)openVConsole;

/*
 * 是否启用离线功能
 */
@property (nonatomic, assign, readonly) BDWebViewOfflineType offlineType;
- (nonnull instancetype)initWithFrame:(CGRect)frame extra:(NSDictionary *)dictExtra;
- (nonnull instancetype)initWithFrame:(CGRect)frame offline:(BDWebViewOfflineType)offlineType;
- (nonnull instancetype)initWithFrame:(CGRect)frame offline:(BDWebViewOfflineType)offlineType extra:(nullable NSDictionary *)dictExtra;
- (nonnull instancetype)initWithFrame:(CGRect)frame offline:(BDWebViewOfflineType)offlineType config:(nullable WKWebViewConfiguration *)config;
- (nonnull instancetype)initWithFrame:(CGRect)frame offline:(BDWebViewOfflineType)offlineType config:(nullable WKWebViewConfiguration *)config extra:(nullable NSDictionary *)dictExtra;

/**
 * 检测白屏，要提供检测的方法
 */
- (void)detectBlankContentWith:(id<BDWebViewDetectBlankContentInterface>)detector completionBlock:(void (^)(BOOL isBlankContent, NSError *err))block;

- (void)setAfterCopyBlock:(void (^)(void)) block;

@end

@interface WKWebView (BDWHelper)

@property (nullable, nonatomic, readonly) BDWebView *bdw_bdWebView;

@end


NS_ASSUME_NONNULL_END
