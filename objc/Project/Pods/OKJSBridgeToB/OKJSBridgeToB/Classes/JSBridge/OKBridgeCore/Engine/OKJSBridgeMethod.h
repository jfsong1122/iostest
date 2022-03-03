//
//  OKJSBridgeMethod.h
//  IESWebKit
//
//  Created by li keliang on 2019/4/8.
//

#import <Foundation/Foundation.h>
#import "OKJSBridgeDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface OKJSBridgeMethod : NSObject

@property (nonatomic, readonly, assign) OKPiperAuthType authType;
@property (nonatomic, readonly,   copy) NSString *methodName;
@property (nonatomic, readonly,   copy) NSString *methodNamespace;
@property (nonatomic, readonly,   copy) OKJSBridgeHandler handler;

- (instancetype)initWithMethodName:(NSString *)methodName methodNamespace:(NSString *)methodNamespace authType:(OKPiperAuthType)authType handler:(OKJSBridgeHandler)handler;

@end

NS_ASSUME_NONNULL_END
