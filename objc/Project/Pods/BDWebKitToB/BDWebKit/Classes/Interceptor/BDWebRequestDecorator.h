//
//  BDWebRequestDecorator.h
//  BDWebKit
//
//  Created by yuanyiyang on 2020/5/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol BDWebRequestDecorator <NSObject>

- (NSURLRequest *)bdw_decorateRequest:(NSURLRequest *)request;

@end

NS_ASSUME_NONNULL_END
