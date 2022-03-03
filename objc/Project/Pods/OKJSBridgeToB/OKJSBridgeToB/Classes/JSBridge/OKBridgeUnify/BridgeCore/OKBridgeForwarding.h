//
//  OKBridgeForwarding.h
//  OKBridgeUnify
//
//  Modified from OKRexxar of muhuai.
//  Created by lizhuopeng on 2018/10/30.
//


#import <Foundation/Foundation.h>
#import "OKBridgeCommand.h"
#import "OKBridgeEngine.h"
#import "OKBridgeDefines.h"

@interface OKBridgeForwarding : NSObject

+ (instancetype)sharedInstance;


/**
 Forward  the command to the plugin.

 @param command bridge command
 @param engine Hybrid container. It can be the webview, RNView or weex, which should implement  the OKBridgeEngine protocol.
 @param completion callback block
 */
- (void)forwardWithCommand:(OKBridgeCommand *)command weakEngine:(id<OKBridgeEngine>)engine completion:(OKBridgeCallback)completion;

/**
 Register a plugin name for a bridge name.
 
 @param plugin plugin name
 @param bridgeName bridge name
 */
- (void)registerPlugin:(NSString *)plugin forBridge:(OKBridgeName)bridgeName;
- (void)unregisterPluginForBridge:(OKBridgeName)bridgeName;


/**
 original name -> alias

 @param orig original name
 @return alias
 */
- (NSString *)aliasForOrig:(NSString *)orig;
@end

