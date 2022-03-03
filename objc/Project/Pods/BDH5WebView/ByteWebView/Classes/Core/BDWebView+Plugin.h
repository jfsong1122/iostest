//
//  BDWebView+Plugin.h
//  ByteWebView
//
//  Created by wealong on 2020/3/4.
//

#import <WebKit/WebKit.h>
#import "BDWebView.h"
#import <BDWebCoreToB/IWKPluginObject.h>
#import <BDWebKitToB/BDWebCookiePlugin.h>

NS_ASSUME_NONNULL_BEGIN

@class IWKPluginObject;

@interface BDWebView (Plugin)

+ (void)loadPlugin:(__kindof IWKPluginObject<IWKClassPlugin> *)plugin;

- (void)loadPlugin:(__kindof IWKPluginObject<IWKInstancePlugin> *)plugin;

@property (readwrite) BOOL pluginsEnable;

@property (readonly) NSArray<IWKPluginObject *> *allPlugins;

@end

NS_ASSUME_NONNULL_END
