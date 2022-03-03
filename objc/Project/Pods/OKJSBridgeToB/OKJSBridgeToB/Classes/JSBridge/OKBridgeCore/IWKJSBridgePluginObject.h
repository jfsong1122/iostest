//
//  IWKJSBridgePluginObject.h
//  IESWebKit
//
//  Created by Lizhen Hu on 2019/7/16.
//

#import "WKWebView+OKJSBridgeExecutor.h"
#import <BDWebCoreToB/IWKPluginObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface IWKPiperPluginObject : IWKPluginObject <IWKInstancePlugin>

@property(nonatomic, assign) BOOL protocolV1Enabled;

@property(nonatomic, strong) NSURL *commitURL;

@end

NS_ASSUME_NONNULL_END
