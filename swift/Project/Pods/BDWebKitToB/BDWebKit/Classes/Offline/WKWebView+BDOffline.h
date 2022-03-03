//
//  WKWebView+BDOffline.h
//  BDWebKit
//
//  Created by wealong on 2019/12/5.
//

#import <WebKit/WebKit.h>
#import "NSObject+BDWRuntime.h"
#import "BDWebKitDefine.h"
#import "IESFalconCustomInterceptor.h"

@interface WKWebView(BDOffline)

@property (nonatomic) BOOL bdw_hitPreload;

@property (nonatomic, copy) NSArray <IESFalconCustomInterceptor> *channelInterceptorList;

@property (nonatomic, assign) BOOL didFinishOrFail;

@end

