//
//  BDNativeContainerObject.h
//  ByteWebView
//
//  Created by liuyunxuan on 2019/6/12.
//

#import <Foundation/Foundation.h>
#import "BDNativeContainerView.h"

@class BDNativeBaseComponent;

@interface BDNativeContainerObject : NSObject

@property(nonatomic, weak) UIScrollView *scrollView;
@property(nonatomic, strong) BDNativeContainerView *containerView;
@property(nonatomic, weak) UIView *nativeView;
@property(nonatomic, strong) BDNativeBaseComponent *component;

- (void)enableObserverFrameChanged;

- (NSMutableDictionary *)checkNativeInfo;
@end
