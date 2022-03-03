//
//  OKJSBridgeMessage.h
//  IESWebKit
//
//  Created by li keliang on 2019/4/8.
//

#import <Foundation/Foundation.h>
#import "OKJSBridgeDefines.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString *const OKJSMessageTypeEvent;
FOUNDATION_EXTERN NSString *const OKJSMessageTypeCall;
FOUNDATION_EXTERN NSString *const OKJSMessageTypeCallback;


extern IESPiperProtocolVersion const IESPiperProtocolVersion1_0;
extern IESPiperProtocolVersion const IESPiperProtocolVersion2_0;// 2.0 版本协议
extern IESPiperProtocolVersion const IESPiperProtocolVersion3_0;
extern IESPiperProtocolVersion const IESPiperProtocolVersionUnknown;


typedef NS_ENUM (NSUInteger, OKJSBridgeFrom) {
    OKJSBridgeMessageFromIframe = 0,
    OKJSBridgeMessageFromJSCall
};

typedef void (^OKJSBridgeMessageCallback)(NSString * _Nullable result);

@interface OKJSBridgeMessage : NSObject

@property (nonatomic, copy) NSString *messageType;
@property (nonatomic, copy) NSString *eventID;
@property (nonatomic, copy) NSString *callbackID;
@property (nonatomic, copy) NSDictionary *invokeParams; // 该字段用于在调用jsb后保存前端调用jsb时的参数信息
@property (nonatomic, copy) NSDictionary *params;
@property (nonatomic, copy) NSString *methodName;
@property (nonatomic, copy) NSString *methodNamespace;
@property (nonatomic, copy) NSString *JSSDKVersion;
@property (nonatomic, copy) NSString *beginTime;
@property (nonatomic, copy) NSString *endTime;
@property(nonatomic, assign) OKPiperStatusCode statusCode;
@property (nonatomic, assign) OKJSBridgeFrom from;
@property (nonatomic, copy) IESPiperProtocolVersion protocolVersion;
@property(nonatomic, copy) NSString *iframeURLString;
@property(nonatomic, strong, readonly) NSString *statusDescription;

@property (nonatomic, copy) OKJSBridgeMessageCallback callback;

- (instancetype)initWithDictionary:(NSDictionary *)dict;
- (instancetype)initWithDictionary:(NSDictionary *)dict callback:(nullable OKJSBridgeMessageCallback)callback;

- (NSString *)wrappedParamsString;
+ (NSString *)statusDescriptionWithStatusCode:(OKPiperStatusCode)statusCode;


@end

NS_ASSUME_NONNULL_END
