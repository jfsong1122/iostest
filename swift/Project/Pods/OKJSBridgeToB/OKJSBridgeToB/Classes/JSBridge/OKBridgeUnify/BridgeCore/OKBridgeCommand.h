//
//  OKBridgeCommand.h
//  OKBridgeUnify
//
//  Modified from OKRexxar of muhuai.
//  Created by lizhuopeng on 2018/10/30.
//

#import <Foundation/Foundation.h>
#import "OKBridgeDefines.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, OKBridgeType) {
    OKBridgeTypeCall= 0,
    OKBridgeTypeOn,
};

typedef NS_ENUM(NSUInteger, OKPiperProtocolType) {
    OKPiperProtocolUnknown= 0,
    OKPiperProtocolSchemaInterception = 1,//1.0 protocol，rexxar
    OKPiperProtocolInjection,//2.0 or 3.0 protocol，inject js.
};

@interface OKBridgeCommand : NSObject

@property (nonatomic, assign) OKBridgeType bridgeType;

@property(nonatomic, copy, nullable) NSString *messageType;

@property(nonatomic, copy, nullable) NSString *eventID;

@property(nonatomic, copy, nullable) NSString *callbackID;

@property(nonatomic, copy, nullable) NSDictionary *params;

@property(nonatomic, copy, nullable) NSDictionary *extraInfo;

@property(nonatomic, assign) OKBridgeMsg bridgeMsg;
/**
 BridgeName from the front-end. Format: "Namespace.method".
 */
@property(nonatomic, copy, nullable) OKBridgeName bridgeName;

/**
 Format："Class.method".
 */
@property(nonatomic, copy, nullable) NSString *pluginName;

/**
 Class name of the plugin.
 */
@property(nonatomic, copy, nullable) NSString *className;

/**
 Method name of the plugin.
 */
@property(nonatomic, copy, nullable) NSString *methodName;

/**
 No use.
 */
@property(nonatomic, copy, nullable) NSString *JSSDKVersion;

/**
 The time when receive the request from the front-end.
 */
@property (nonatomic, copy, nullable) NSString *startTime;

/**
 The time when submit the callback to the front-end.
 */
@property (nonatomic, copy, nullable) NSString *endTime;


/// Protocol type of Piper.
@property(nonatomic, assign) OKPiperProtocolType protocolType;

- (instancetype)initWithDictonary:(NSDictionary *)dic;

- (NSString *)toJSONString;
- (NSDictionary *)rawDictionary;

@property(nonatomic, strong, readonly) NSString *wrappedParamsString;

@end

NS_ASSUME_NONNULL_END
