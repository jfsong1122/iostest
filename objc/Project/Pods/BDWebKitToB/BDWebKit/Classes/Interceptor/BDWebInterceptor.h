//
//  BDWebInterceptor.h
//  BDWebKit
//
//  Created by li keliang on 2020/3/13.
//

#import <Foundation/Foundation.h>
#import <BDWebCoreToB/IWKPluginObject.h>
#import <BDWebKitToB/BDWebURLSchemeTaskHandler.h>
#import "BDWebRequestDecorator.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDWebInterceptor : NSObject

+ (instancetype)sharedInstance;

- (void)registerCustomURLSchemaHandler:(Class<BDWebURLSchemeTaskHandler>)schemaHandler;
- (void)registerCustomRequestDecorator:(Class<BDWebRequestDecorator>)requestDecorator;

@end

@interface WKWebViewConfiguration (BDWebInterceptor)

@property (nonatomic, assign) BOOL bdw_enableInterceptor API_AVAILABLE(ios(12.0));

@end

NS_ASSUME_NONNULL_END
