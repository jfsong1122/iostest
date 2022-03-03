//
//  BDXBridgePublishEventMethod.h
//  BDXBridgeKit
//
//  Created by Lizhen Hu on 2020/9/4.
//

#import "BDXBridgeMethod.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDXBridgePublishEventMethod : BDXBridgeMethod

@end

@interface BDXBridgePublishEventMethodParamModel : BDXBridgeModel

@property (nonatomic, copy) NSString *eventName;
@property (nonatomic, copy) NSDictionary *params;
@property (nonatomic, strong) NSNumber *timestamp;

@end

NS_ASSUME_NONNULL_END
