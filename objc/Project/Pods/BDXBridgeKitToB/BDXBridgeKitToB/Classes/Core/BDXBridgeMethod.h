//
//  BDXBridgeMethod.h
//  BDXBridge
//
//  Created by Lizhen Hu on 2020/5/28.
//

#import <Foundation/Foundation.h>
#import "BDXBridgeModel.h"
#import "BDXBridgeStatus.h"
#import "BDXBridgeMacros.h"
#import "BDXBridgeContext.h"
#import "BDXBridgeDefinitions.h"
#import "BDXBridgeContainerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^BDXBridgeMethodCompletionHandler)(BDXBridgeModel * _Nullable resultModel, BDXBridgeStatus * _Nullable status);

@interface BDXBridgeMethod : NSObject

/// A set of engine types ORed by multiple `BDXBridgeEngineType`s.
@property (nonatomic, assign, readonly) BDXBridgeEngineType engineTypes;

/// The name of bridge method.
@property (nonatomic, copy, readonly) NSString *methodName;

/// The auth type of bridge method, callers in a lower auth group are not allowed to call this bridge method.
@property (nonatomic, assign, readonly) BDXBridgeAuthType authType;

/// A development method will only be registered in development mode.
@property (nonatomic, assign, readonly) BOOL isDevelopmentMethod;

/// Arbitrary data which can be accessed by each invocation of the call method.
@property (nonatomic, strong, readonly) BDXBridgeContext *context;

/// The class of the param model.
@property (nonatomic, strong, readonly, nullable) Class paramModelClass;

/// The class of the result model.
@property (nonatomic, strong, readonly, nullable) Class resultModelClass;

- (instancetype)initWithContext:(BDXBridgeContext *)context;


- (void)callWithParamModel:(nullable BDXBridgeModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;

@end

NS_ASSUME_NONNULL_END
