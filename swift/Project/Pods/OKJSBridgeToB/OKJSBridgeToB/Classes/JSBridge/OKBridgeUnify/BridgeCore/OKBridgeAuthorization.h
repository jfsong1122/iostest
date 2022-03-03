//
//  OKBridgeAuthorization.h
//  OKBridgeUnify
//
//  Modified from OKRexxar of muhuai.
//  Created by lizhuopeng on 2018/10/30.
//

#import <Foundation/Foundation.h>
#import "OKBridgeDefines.h"
#import "OKBridgeCommand.h"
#import "OKBridgeEngine.h"

@protocol OKBridgeAuthorization <NSObject>


/**
 Verify the permission of an engine to call a bridge.

 @param engine engine of the current webView
 @param command Command
 @param domain host of the current webView
 @return authorization result
 */
- (BOOL)engine:(id<OKBridgeEngine>)engine isAuthorizedBridge:(OKBridgeCommand *)command domain:(NSString *)domain;

- (void)engine:(id<OKBridgeEngine>)engine isAuthorizedBridge:(OKBridgeCommand *)command domain:(NSString *)domain completion:(void (^)(BOOL success))completion;

- (BOOL)engine:(id<OKBridgeEngine>)engine isAuthorizedMeta:(NSString *)meta domain:(NSString *)domain;

- (BOOL)engine:(id<OKBridgeEngine>)engine isAuthorizedBridge:(OKBridgeCommand *)command URL:(NSURL *)URL;

@optional
- (BOOL)engine:(id<OKBridgeEngine>)engine isAuthorizedEvent:(NSString *)eventName domain:(NSString *)domain __deprecated_msg("Event no longer requires authorization. This method is no longer needed.");

@end
