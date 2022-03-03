//
//  RangersAPM+NetworkPro.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2021/11/25.
//

#import "RangersAPM.h"

NS_ASSUME_NONNULL_BEGIN

@interface RangersAPM (NetworkPro)

/**
 如果需要通过 traceID 打通客户端网络监控和服务端日志，请调用此接口配置 traceIDKey，我们的 SDK 会根据在网络请求的 responseHeader 中获取对应的值进行上报。
 
 If you need to connet the client network monitor log to server log through traceID, please set traceIDKey, our SDK will report according to the corresponding value obtained in the responseHeader of the network request.
 
 @param traceIDKey The key of your traceID in the responseHeader.
 */
+ (void)setTraceIDKey:(NSString *)traceIDKey;

@end

NS_ASSUME_NONNULL_END
