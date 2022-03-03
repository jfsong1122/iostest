//
//  IESFalconManager.h
//  IESWebKit
//
//  Created by li keliang on 2018/10/9.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "IESFalconCustomInterceptor.h"
#import "IESFalconGurdInterceptionDelegate.h"

#if __has_include(<mars_gecko_ios/IESGeckoKit.h>)
#import "IESFalconGurdInterceptor.h"
#define IESFalconGurdInterceptorEnable  1
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol IESFalconInterceptionDelegate <NSObject>

@optional
- (void)falconInterceptedRequest:(NSURLRequest *)request willLoadFromCache:(BOOL)fromCache;

@end

@protocol IESFalconMonitorInterceptor <NSObject>

@optional
- (void)willGetMetaData:(id<IESFalconMetaData> _Nullable)metaData forRequest:(NSURLRequest *)request;
- (void)didGetMetaData:(id<IESFalconMetaData> _Nullable)metaData forRequest:(NSURLRequest *)request isGetMethod:(BOOL)isGetMethod isCustomInterceptor:(BOOL)isCustomInterceptor;
- (void)webView:(WKWebView *)webView loadRequest:(NSURLRequest *)request metaData:(id<IESFalconMetaData> _Nullable)metaData isCustomInterceptor:(BOOL)isCustomInterceptor;
-(void)webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation;
@end

@interface IESFalconManager : NSObject

@property (nullable,  class) id<IESFalconInterceptionDelegate> interceptionDelegate;

@property (nonatomic, class, assign) BOOL interceptionLock;

@property (nonatomic, class, assign) BOOL webpDecodeEnable;

@property (nonatomic, class, assign) BOOL interceptionWKHttpScheme;
@property (nonatomic, class, assign) BOOL interceptionEnable;

//call before set interceptionEnable.
@property (nonatomic, class, assign) BOOL interceptionUseFalconURLSchemaHandle;

@property(nonatomic, strong, class, readonly) NSHashTable *monitorInterceptors;

+ (void)addInterceptor:(id<IESFalconMonitorInterceptor>)interceptor;

+ (void)removeInterceptor:(id<IESFalconMonitorInterceptor>)interceptor;

@property (nonatomic, class, readonly, copy) NSArray <id<IESFalconCustomInterceptor>> *customInterceptors;

+ (void)registerPattern:(NSString *)pattern forGurdAccessKey:(NSString *)accessKey;
+ (void)registerPatterns:(NSArray <NSString *> *)patterns forGurdAccessKey:(NSString *)accessKey;

+ (void)registerPattern:(NSString *)pattern forSearchPath:(NSString *)searchPath;
+ (void)registerPatterns:(NSArray <NSString *> *)patterns forSearchPath:(NSString *)searchPath;

+ (void)unregisterPatterns:(NSArray <NSString *> *)patterns;

+ (void)registerCustomInterceptor:(id<IESFalconCustomInterceptor>)interceptor;
+ (void)unregisterCustomInterceptor:(id<IESFalconCustomInterceptor>)interceptor;

+ (id<IESFalconMetaData> _Nullable)falconMetaDataForURLRequest:(NSURLRequest *)request;

+ (BOOL)shouldInterceptForRequest:(NSURLRequest*)request;

+ (NSData * _Nullable)falconDataForURLRequest:(NSURLRequest *)request;

+ (void)webView:(WKWebView *)webView loadRequest:(NSURLRequest *)request metaData:(id<IESFalconMetaData> _Nullable)metaData;
+ (void) webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation;
@end

NS_ASSUME_NONNULL_END
