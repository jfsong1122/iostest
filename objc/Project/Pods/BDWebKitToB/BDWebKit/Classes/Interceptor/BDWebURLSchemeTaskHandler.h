//
//  BDWebURLSchemeTaskHandler.h
//  BDWebKit
//
//  Created by li keliang on 2020/4/3.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol BDWebURLSchemeTask <NSObject>

@property (nonatomic, readonly, copy) NSURLRequest *bdw_request;

- (void)bdw_didReceiveResponse:(NSURLResponse *)response;

- (void)bdw_didLoadData:(NSData *)data;

- (void)bdw_didFinishLoading;

- (void)bdw_didFailWithError:(NSError *)error;

- (void)bdw_didPerformRedirection:(NSURLResponse *)response newRequest:(NSURLRequest *)request;

@end

@protocol BDWebURLSchemeTaskHandler <NSObject>

- (instancetype)initWithWebView:(nullable WKWebView *)webView schemeTask:(id<BDWebURLSchemeTask>)task;

+ (BOOL)bdw_canHandleRequest:(NSURLRequest *)request;

- (void)bdw_startURLSchemeTask;

- (void)bdw_stopURLSchemeTask;

@end

NS_ASSUME_NONNULL_END
