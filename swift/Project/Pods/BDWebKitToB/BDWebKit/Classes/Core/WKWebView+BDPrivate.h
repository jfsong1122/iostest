//
//  WKWebView+BDPrivate.h
//  BDWebKit
//
//  Created by wealong on 2020/1/5.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "BDWebKitDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface WKWebView (BDPrivate)

@property (nonatomic, readonly) NSArray *bdw_urlProtocols;

@property (nonatomic) BDWebViewOfflineType bdw_offlineType;

- (void)bdw_registerURLProtocolClass:(Class)protocol;

- (void)bdw_unregisterURLProtocolClass:(Class)protocol;

- (BOOL)bd_isPageValid;

- (UIView*)bd_contentView;
@end

NS_ASSUME_NONNULL_END
