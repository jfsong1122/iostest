//
//  VEH5WebViewDelegateProxy.h
//  ABRInterface
//
//  Created by 李晓鹏 on 2021.
//

#import <Foundation/Foundation.h>
#import <BDH5WebView/BDWebView.h>

@protocol VEH5WebViewDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface VEH5WebViewDelegateProxy : NSProxy<BDWebViewDelegate>

@property(nonatomic, strong, readonly) NSHashTable *delegatesHashTable;

+ (instancetype)initWithMainDelegate:(NSObject<VEH5WebViewDelegate> *)mainDelegate;

- (void)addDelegate:(NSObject<VEH5WebViewDelegate> *)delegate;
- (void)removeDelegate:(NSObject<VEH5WebViewDelegate> *)delegate;

@end

NS_ASSUME_NONNULL_END
