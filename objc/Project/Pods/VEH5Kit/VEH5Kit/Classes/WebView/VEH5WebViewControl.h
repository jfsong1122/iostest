//
//  VEH5WebViewControl.h
//  Aurum
//
//  Created by 李晓鹏 on 2021/4/20.
//

#import <Foundation/Foundation.h>
#import "VEH5WebView.h"

@interface VEH5WebViewControl : NSObject

/**
 WKWebView打开第三方url scheme白名单
 */
+ (NSArray<NSString *> *)openURLSchemeWhiteList;

/**
 WKWebView拦截跳转url黑名单
 */
+ (NSArray<NSString *> *)interceptURLsList;

/**
 WKWebView TTNet拦截黑名单
 ⚠️：由于当前BDWebKit需要初始化时设置type，且之后无法更改，因此该方法由业务方调用
 */
+ (NSArray<NSString *> *)urlsForTTNetInterceptDisable;

/**
 WKWebView不处理的scheme list
 */
+ (NSArray<NSString *> *)ignoreProcessingSchemeList;

/**
 页面加载时是否禁用schema跳转
 */
+ (BOOL)disableAutoJumpBySchema;

/**
 自动跳转白名单
 */
+ (NSArray<NSString *> *)autoJumpWhiteList;

/**
 是否开启预创建WWKWebView
 */
+ (BOOL)wkWebViewPrecreatedEnable;

/**
 内存不足时是否自动清理预创建WWKWebView内存
 */
+ (BOOL)clearPreCreateWKWhenMemoryWarning;

/**
 是否支持自动播放音频
 */
+ (BOOL)supportMediaAutoPlay;

/**
 是否开启TTNet网络代理
 */
+ (BOOL)networkProxyEnable;

/**
 安全域名
 */
+ (NSArray<NSString *> *)safeDomainList;

/**
 是否开启IESWebMonitor监控
 */
+ (BOOL)IESWebMonitorEnable;

/**
 离线化能力
 */
+ (BOOL)offlineEnable;
+ (void)setOfflineEnable:(BOOL)enable;

/**
 http代理
 */
+ (NSString *)httpProxyURLStr;

/**
 https代理
 */
+ (NSString *)httpsProxyURLStr;

/**
 是否使用BDWebview schemeTask 异步处理
 */
+ (BOOL)bdWebViewAsycSchemeTaskEnable;

/**
 根据Url判断是否需要添加Query通参
 */
+ (BOOL)shouldAppendCommonParamsForUrl:(NSURL *)url;

/**
 给NSURLRequest添加通参
 */
+ (NSURLRequest *)appendCommonParamsForRequestWithRequst:(NSURLRequest *)request;

/**
 是否是APPStore下载链接地址
 */
+ (BOOL)isAppStoreRequestURLStr:(NSString *)urlStr;

/**
 WebView单击事件手势响应间隔，为0则不开启自定义手势监听，默认使用BDWebView内部监听
 */
+ (CGFloat)userInteractionMonitorInterval;

/**
 跳过证书校验，默认YES
 */
+ (BOOL)skipServerTrustDefault;

/*
 离线化正则匹配列表
 */
+ (NSArray<NSString *> *)offlineRegxList;

/*
 WKWebView错误码-999时是否显示错误页面
 */
+ (BOOL)errorPageShowWhenCanceled;

/*
 根据url判断是否需要屏蔽JS注入
 */
+ (BOOL)forbiddenAddScriptForURL:(NSURL *)url;

/*
 根据url判断将原始西瓜UA转成头条UA
 */
+ (NSString *)convertToToutiaoUAWithOriginalUserAgent:(NSString *)originalUserAgent urlStr:(NSString *)urlStr;

@end

