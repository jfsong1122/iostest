//
//  UIScrollView+BDNative.h
//  AFgzipRequestSerializer
//
//  Created by liuyunxuan on 2019/7/17.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^BDNativeScrollFrameBlock)(void);
typedef void(^BDScrollDestructAction)(void);

@interface BDNativeLifeObserverObject : NSObject


@end


@interface UIScrollView (BDNative)

@property (nonatomic) BOOL bdNativeDisableScroll;

@property (nonatomic, strong) BDNativeLifeObserverObject *bdNativeLifeObject;

@property (nonatomic, copy) BDNativeScrollFrameBlock scrollSetFrameBlock;

- (void)configScrollDestructAction:(BDScrollDestructAction)descructAction;

@end

NS_ASSUME_NONNULL_END
