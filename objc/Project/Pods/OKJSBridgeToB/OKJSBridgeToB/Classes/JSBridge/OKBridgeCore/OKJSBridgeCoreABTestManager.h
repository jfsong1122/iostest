//
//  OKJSBridgeCoreABTestManager.h
//  IESWebKit
//
//  Created by Lizhen Hu on 2019/8/21.
//

#import <Foundation/Foundation.h>

#if __has_include("OKJSBridgeCore_Rename.h")
#import "OKJSBridgeCore_Rename.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface IESPiperCoreABTestManager : NSObject

@property (class, nonatomic, strong, readonly) IESPiperCoreABTestManager *sharedManager;

@property (nonatomic, assign, getter=shouldUseBridgeEngineV2) BOOL useBridgeEngineV2;
@property (nonatomic, assign, getter=shouldMonitorJSBInvokeEvent) BOOL monitorJSBInvokeEvent;
@property (nonatomic, assign, getter=shouldEnableIFrameJSB) BOOL enableIFrameJSB;

@end

NS_ASSUME_NONNULL_END
