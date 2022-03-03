                //
//  OKBridgePlugin.h
//  OKBridgeUnify
//
//  Modified from OKRexxar of muhuai.
//  Created by lizhuopeng on 2018/10/30.
//

#import <Foundation/Foundation.h>
#import "OKBridgeDefines.h"
#import "OKBridgeEngine.h"


#define OKBridgeSEL(CLASS, METHOD) \
((void)(NO && ((void)[((CLASS *)(nil)) METHOD##WithParam:nil callback:nil engine:nil controller:nil], NO)), @selector(METHOD##WithParam:callback:engine:controller:))


@interface OKBridgePlugin : NSObject

/**
 The engine which the plugin is executed by.
 */
@property (nonatomic, weak) id<OKBridgeEngine> engine;


/**
 When JSB's type is OKBridgeInstanceTypeGlobal, this method should be implemented. This method is not commonly recommended.

 @return singleton plugin
 */
+ (instancetype)sharedPlugin;

+ (OKBridgeInstanceType)instanceType;


#pragma mark - deprecated, The API that is no longer recommended for local bridge.
+ (void)registerHandlerBlock:(OKBridgePluginHandler)handler forEngine:(id<OKBridgeEngine>)engine selector:(SEL)selector __deprecated_msg("Use -[OKBridgeRegister registerBridge:]");

- (BOOL)hasExternalHandleForMethod:(NSString *)method params:(NSDictionary *)params callback:(OKBridgeCallback)callback __deprecated_msg("The API that is no longer recommended for local bridge.");

@end
