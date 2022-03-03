//
//  BDWebViewDetectBlankContent.h
//  ByteWebView
//
//  Created by Lin Yong on 2019/3/13.
//

#import <Foundation/Foundation.h>
#import <BDWebKitToB/BDWebViewBlankDetect.h>

NS_ASSUME_NONNULL_BEGIN

@class BDWebView;

@protocol BDWebViewDetectBlankContentInterface <NSObject>
- (void)detectBlankWebView:(BDWebView *)webview completeBlock:(void(^)(BOOL, NSError *)) block;
@end

/**
 * iOS 11以上 使用wk提供的系统API检测，UIWebview或者wk iOS11 以下检测，则必须打开needOldSapshotDetect
 * needOldSapshotDetect 开启旧检测方式，需要截屏，可能会有性能损耗，默认NO
 * needNewSapshotDetect 开启新检测方式（只在iOS 11以上 wk使用），默认YES
 */
@interface BDWebViewDetectBlankContentByNewSapshot : NSObject <BDWebViewDetectBlankContentInterface>
@property (nonatomic, assign) BOOL needOldSapshotDetect;
@property (nonatomic, assign) BOOL needNewSapshotDetect;
@end
NS_ASSUME_NONNULL_END
