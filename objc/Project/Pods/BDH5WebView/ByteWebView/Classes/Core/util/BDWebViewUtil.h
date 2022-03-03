//
//  BDWebViewUtil.h
//  ByteWebView
//
//  Created by Lin Yong on 2019/5/5.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

#define dispatch_main($block) ([NSThread isMainThread] ? $block() : dispatch_sync(dispatch_get_main_queue(), $block))

#define weakify(var) __weak typeof(var) XYWeak_##var = var;
#define strongify(var) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
__strong typeof(var) var = XYWeak_##var; \
_Pragma("clang diagnostic pop")

NS_ASSUME_NONNULL_BEGIN

void BDWebViewMethodSwizzle(Class cls, SEL originalSelector, SEL swizzledSelector);
void BDWebViewClassMethodSwizzle(Class cls, SEL originalSelector, SEL swizzledSelector);

FOUNDATION_EXPORT NSDictionary<NSString *, NSString *> *URLQueryDict(NSString *str);

@interface BDWebViewUtil : NSObject
+ (UIViewController*)topmostViewController;
+ (UIViewController*)topViewControllerFor:(UIResponder*)responder;
@end

#ifndef isEmptyString
#define isEmptyString(str) (!str || ![str isKindOfClass:[NSString class]] || str.length == 0)
#endif

NS_ASSUME_NONNULL_END
