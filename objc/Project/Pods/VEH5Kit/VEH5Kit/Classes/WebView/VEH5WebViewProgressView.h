//
//  VEH5WebViewProgressView.h
//  ABRInterface
//
//  Created by 李晓鹏 on 2021.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface VEH5WebViewProgressView : UIView

- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;
- (void)finishProgress;

@end

NS_ASSUME_NONNULL_END
