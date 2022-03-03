//
//  WKWebView+BDNativeBridge.h
//  Pods
//
//  Created by liuyunxuan on 2019/7/8.
//

#import <WebKit/WebKit.h>
#import "BDNativeBridgeManager.h"
#import "BDNativeMessageHandler.h"

@interface WKWebView (BDNativeBridge) <BDNativeMessageHandlerDelegate,BDNativeBridgeManagerDelegate>

- (void)enableBDNativeBridge;

- (void)registerHandler:(BDNativeBridgeHandler)handler bridgeName:(NSString *)bridgeName;
@end
