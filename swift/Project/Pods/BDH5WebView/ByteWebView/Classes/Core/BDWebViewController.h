//
//  BDWebViewController.h
//  ByteWebView
//
//  Created by Lin  Yong on 2019/1/22.
//

#import <Foundation/Foundation.h>
#import "BDWebView.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Base browser.
 * Override configWebView method to provide a custom webview.
 */
@interface BDWebViewController : UIViewController

@property (nonatomic, retain) BDWebView *webview;

// 是否显示 toolbar，默认为NO
@property (nonatomic, assign) BOOL toolbarHidden;
- (void)setToolbarHidden:(BOOL)toolbarHidden animated:(BOOL)animated;

// 当页面消失时 是否隐藏 toolbar，默认为YES
@property (nonatomic, assign) BOOL toolbarHiddenWhenDisappear;

- (instancetype)initWithURL:(NSURL *)url;

- (void)refresh;

- (void)goBack;

- (BOOL)canGoBack;

- (void)goForward;

- (BOOL)canGoFaward;

@end

NS_ASSUME_NONNULL_END
