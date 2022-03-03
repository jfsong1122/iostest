//
//  BDWebView+Offline.h
//  BDALog
//
//  Created by Lin Yong on 2019/1/30.
//

#import "BDWebView.h"
#import <BDWebKitToB/IESFalconCustomInterceptor.h>
//#import <BDWebKitToB/IESAdSplashChannelInterceptor.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDWebView (Offline)

@property (nonatomic, readonly) BOOL isHitPreload;

//@property (nonatomic, strong) IESAdSplashChannelInterceptor *channelInterceptor;//针对三方落地页，指定拦截文件目录
@property (nonatomic, copy) NSArray <IESFalconCustomInterceptor> *channelInterceptorList;

@end

NS_ASSUME_NONNULL_END
