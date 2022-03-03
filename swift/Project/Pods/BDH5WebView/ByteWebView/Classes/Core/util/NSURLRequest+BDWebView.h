//
//  NSURLRequest+BDWebView.h
//  ByteWebView
//
//  Created by Luo Qisheng on 2019/10/10.
//

#import <WebKit/WebKit.h>
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, BDWebViewInterceptURLType) {
    BDWebViewInterceptURLTypeNone   =   0,
    BDWebViewInterceptURLTypeUniversalLink,
    BDWebViewInterceptURLTypeScheme
};

FOUNDATION_EXTERN NSString *bd_base64DecodedString(NSString *origin);
NS_ASSUME_NONNULL_BEGIN

@interface NSURLRequest (BDWebView)
@property (nonatomic, weak) WKNavigationAction *navigationAction;
@property (nonatomic, assign, readonly) BOOL userInitiated;
@property (nonatomic, assign, readonly) BOOL shouldOpenAppLinks; // 用于判断本次请求的链接是否Universal Link
@property (nonatomic, assign, readonly) BOOL shouldOpenExternalSchemes;
@property (nonatomic, assign) BDWebViewInterceptURLType URLType;

@end

NS_ASSUME_NONNULL_END
