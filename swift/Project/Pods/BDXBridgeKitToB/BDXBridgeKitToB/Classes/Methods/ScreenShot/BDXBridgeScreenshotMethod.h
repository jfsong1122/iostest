//
//  BDXBridgeScreenshotMethod.h
//  BDXBridgeKit
//
//  Created by dengjinan on 2021/4/20.
//

#import "BDXBridgeMethod.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDXBridgeScreenshotMethod : BDXBridgeMethod
@property (nonatomic, copy) BDXBridgeMethodCompletionHandler completionHandler;
@end

@interface BDXBridgeScreenshotMethodResultModel : BDXBridgeModel

@property (nonatomic, assign) BDXBridgeStatusCode statusCode;
@property (nonatomic, copy, nullable) NSString *message;

@end

NS_ASSUME_NONNULL_END
