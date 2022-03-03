//
//  BDWebURLSchemeTask.h
//  BDWebKit
//
//  Created by li keliang on 2020/3/13.
//

#import <Foundation/Foundation.h>
#import "BDWebInterceptor.h"

NS_ASSUME_NONNULL_BEGIN

@class BDWebURLSchemeTask;
@protocol BDWebURLSchemeTaskDelegate <NSObject>

- (void)URLSchemeTask:(BDWebURLSchemeTask *)task didReceiveResponse:(NSURLResponse *)response;

- (void)URLSchemeTask:(BDWebURLSchemeTask *)task didLoadData:(NSData *)data;

- (void)URLSchemeTaskDidFinishLoading:(BDWebURLSchemeTask *)task;

- (void)URLSchemeTask:(BDWebURLSchemeTask *)task didFailWithError:(NSError *)error;

@optional
- (void)URLSchemeTask:(BDWebURLSchemeTask *)task didPerformRedirection:(NSURLResponse *)response newRequest:(NSURLRequest *)request;

@end

@interface BDWebURLSchemeTask : NSObject <BDWebURLSchemeTask>

@property (nonatomic, weak) id<BDWebURLSchemeTaskDelegate> delegate;

@property (nonatomic, readwrite, copy) NSURLRequest *bdw_request;

@property (nonatomic, assign) BOOL taskHasFinishOrFail;

@end

NS_ASSUME_NONNULL_END
