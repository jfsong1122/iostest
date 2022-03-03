//
//  RangersAPM+Network.h
//  RangersAPM
//
//  Created by xuminghao.eric on 2021/1/11.
//

#import "RangersAPM.h"

NS_ASSUME_NONNULL_BEGIN

@interface RangersAPM (Network)

/**
 是否信任服务器返回的证书，用于代理方法 URLSession:task:didReceiveChallenge:completionHandler:
 
 @param handler 根据session、task、challenge参数判断是否信任服务器返回的证书，并设置credential
 
 Default : 如果未设置handler，当证书类型是NSURLAuthenticationMethodServerTrust时，使用challenge.protectionSpace.serverTrust构造credential，证书处理方式为NSURLSessionAuthChallengeUseCredential
 */
+ (void)setTaskDidReceiveAuthenticationChallengeHandler:(NSURLSessionAuthChallengeDisposition (^)(NSURLSession *session, NSURLSessionTask *task, NSURLAuthenticationChallenge *challenge, NSURLCredential * _Nullable __autoreleasing * _Nullable credential))handler;

/**
 是否信任服务器返回的证书，用于代理方法 URLSession:didReceiveChallenge:completionHandler:
 
 @param handler 根据session、challenge参数判断是否信任服务器返回的证书，并设置credential
 
 Default : 如果未设置handler，当证书类型是NSURLAuthenticationMethodServerTrust时，使用challenge.protectionSpace.serverTrust构造credential，证书处理方式为NSURLSessionAuthChallengeUseCredential
 */

+ (void)setSessionDidReceiveAuthenticationChallengeHandler:(NSURLSessionAuthChallengeDisposition (^)(NSURLSession *session, NSURLAuthenticationChallenge *challenge, NSURLCredential * _Nullable __autoreleasing * _Nullable credential))handler;

@end

NS_ASSUME_NONNULL_END
