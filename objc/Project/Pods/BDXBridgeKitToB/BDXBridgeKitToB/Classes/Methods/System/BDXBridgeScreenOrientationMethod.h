//
//  BDXBridgeBDXBridgescreenOrientationMethodMethod.h
//  BDXBridgeKit
//
//  Created by bytedance on 2021/04/20

#import "BDXBridgeMethod.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDXBridgeScreenOrientationMethod : BDXBridgeMethod
@property (nonatomic, copy) BDXBridgeMethodCompletionHandler completionHandler;
@end

@interface BDXBridgeScreenOrientationMethodParamModel : BDXBridgeModel
@property (nonatomic, copy) NSString *eventName;
@end

@interface BDXBridgeScreenOrientationMethodResultModel : BDXBridgeModel
@property (nonatomic, copy) NSString *orientation;
@end

NS_ASSUME_NONNULL_END
