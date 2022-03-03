//
//  OKJSBridgeDefines.h
//  Pods
//
//  Created by li keliang on 2019/4/8.
//

#ifndef OKJSBridgeDefines_h
#define OKJSBridgeDefines_h

#if __has_include("OKJSBridgeCore_Rename.h")
#import "OKJSBridgeCore_Rename.h"
#endif

@class OKJSBridgeMessage;

#define IESConcat_(A, B) A ## B
#define IESConcat(A, B) IESConcat_(A, B)

typedef NS_ENUM(NSInteger, OKPiperStatusCode) {
    OKPiperStatusCodeUnknownError   = -1000,// 未知错误
    OKPiperStatusCodeManualCallback = -999, // 业务方回调
    OKPiperStatusCodeUndefined      = -998, // 前端方法未定义
    OKPiperStatusCode404            = -997, // 前端返回 404
    OKPiperStatusCodeNamespaceError = -4,   // 错误命名空间
    OKPiperStatusCodeParameterError = -3,   // 参数错误
    OKPiperStatusCodeNoHandler      = -2,   // 未注册方法
    OKPiperStatusCodeNotAuthroized  = -1,   // 未授权
    OKPiperStatusCodeFail           = 0,    // 失败
    OKPiperStatusCodeSucceed        = 1     // 成功
};

#ifndef OKPiperAuthTypeDef
#define OKPiperAuthTypeDef
typedef NS_ENUM(NSUInteger, OKPiperAuthType){
    OKPiperAuthPublic = 0,
    OKPiperAuthProtected,
    OKPiperAuthPrivate,
    OKPiperAuthSecure,
};
#endif

typedef void (^OKJSBridgeResponseBlock)(OKPiperStatusCode status, NSDictionary * _Nullable response);

typedef void (^OKJSBridgeHandler)(OKJSBridgeMessage * _Nonnull message, OKJSBridgeResponseBlock _Nonnull responseBlock);

#define IES_BRIDGE_INVOKE_FAILED_CALLBACK(block) (block?:block(IESPiperStatusCodeFail, nil));

#define IES_BRIDGE_INVOKE_SUCCEED_CALLBACK(block, response) (block?:block(IESPiperStatusCodeSucceed, response));


typedef NSString * IESPiperProtocolVersion;

#define IESPiperCoreBridgeHostnameDispatchMessage @"dispatch_message"

#define stringify(s) #s

#endif /* OKJSBridgeDefines_h */
