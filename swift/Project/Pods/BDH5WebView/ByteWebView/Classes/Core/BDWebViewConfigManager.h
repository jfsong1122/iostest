//
//  BDConfigManager.h
//  ByteWebView
//
//  Created by Lin Yong on 2019/1/28.
//

#import <Foundation/Foundation.h>
#import "BDWebView.h"
#import "BDWebViewCommon.h"
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

extern BOOL isInitConfigBlockFailed;

@interface BDWebViewConfigManager : NSObject

/**
* 将初始化config的任务放到BDWebView init时执行
*/
@property (nonatomic, strong) dispatch_block_t initConfigBlock;
/**
 * App是否处理内测版本，组件可能会采用不同的实现，或者下载不同的资源
 */
@property (nonatomic, assign) BOOL isInHouse;
/**
 * 默认为YES，会把NSHTTPCookieStorage中的cookie同步到WK环境，具体有3个时机：
 * 1. WKWebView创建时。如果大于iOS11，则使用WKWebViewConfiguration.websiteDataStore.httpCookieStore；否则注入js实现。
 * 2. WKWebView.loadRequest时；
 * 3. WKWebView中发送ajax时；通过注入js hook ajax，把请求转到native发送实现。
 */
@property (nonatomic, assign) BOOL isSyncCookiesToWKWebView;

/**
 * 组件需要DeviceId
 */
@property (nonatomic, strong) NSString *deviceId;

/**
 * 组件需要AppId
 */
@property (nonatomic, strong) NSString *appId;

+ (instancetype)sharedInstance;

/**
 *  设置可以缓存的 WKWebView 实例的最大数量
 * @note
 * 当设置为 0 时，就会清空已有的缓存实例。默认为 0。
 */
- (void)setMaxNumberOfWKInProvider:(int) number;

/**
 * 设置内存警告时，不缓存实例的时间。当内存警告发生时，缓存会被清空，只有等到下次 fetch 或者 setMaxNumberOfInstances 接口被调用才会重新创建缓存实例。
 * 默认为 5 分钟。
 **/
@property (nonatomic, assign) int memoryWarningProtectDurationInProvider;
/*! @abstract 内存警告时是否清空预创建的WK
 @discussion 默认为 YES
 */
@property (nonatomic, assign) BOOL isClearPreCreateWKWhenMemoryWarning;

/**
 *  手工预创建一个WK，使用自定义的setting。需要在主线程调用。调用时就会创建WK。
 *
 *  @param setting 自定义配置
 *
 *  @return 返回一个`configuration`，在BDWebView init时使用它，可以使用到这里预创建的WKWebView。
 */
- (WKWebViewConfiguration *)manualPreCreateWKWithSetting:(BDWebViewWKConfigurationSetting *)setting;

/**
 * Default: 3 and max 5
 */
@property (nonatomic, assign) NSUInteger templateMaxTemplateCount;


@property (nonatomic, readonly) BDWebViewWKConfigurationSetting *defaultWKConfigurationSetting;

/*! @abstract Falcon除了拦截about，是否拦截http/http。默认为YES，如果设置为NO，则只拦截about。
 @discussion Falcon除了拦截about，是否拦截http/http。默认为YES，如果设置为NO，则只拦截about。
 */
@property (nonatomic, assign) BOOL falconInterceptionWKHttpScheme;

/*! @abstract 是否预创建 BDWebViewOfflineTypeTaskScheme 的 WKWebview，默认为 NO
 @discussion BDWebViewOfflineTypeTaskScheme 网络请求会使用 ttnet 代理
 */
@property (nonatomic, assign) BOOL isPreCreateWKForTaskSchemeOfflineType;

@property (nonatomic, copy) NSArray *safeHostList;

/*! @abstract 处理SchemeTask时是否异步
 @discussion 默认为YES
 */
@property (nonatomic, assign) BOOL isAsyncWhenHandleSchemeTask;

/*! @abstract 处理 30x cookie 泄露问题
 @discussion 默认为 NO
 */
@property (nonatomic, assign) BOOL fixRequest30xCORSSecurity;

/*! @abstract 禁止使用 LoadRequest 加载 FileURL
 @discussion 默认为 YES
 */
@property (nonatomic, assign) BOOL disableLoadRequestWithFileURL;

// 测试
@property (nonatomic, assign) BOOL uploadWebViewBlankImage;
@property (nonatomic, assign) BOOL saveWebViewBlankImage;

//修复TTNet无网不走fail回调的问题
@property (nonatomic, assign) BOOL bdTTNetAvoidNoResponseException;

@end

NS_ASSUME_NONNULL_END
