//
//  OKBridgeUnify_internal.h
//  AFgzipRequestSerializer-iOS12.0
//
//  Created by lizhuopeng on 2019/9/26.
//

#import <Foundation/Foundation.h>
#import "OKBridgeForwarding.h"
#import "OKBridgeRegister.h"

NS_ASSUME_NONNULL_BEGIN


@interface OKBridgeForwarding (OKBridgeInternal)

- (void)_installAssociatedPluginsOnEngine:(id<OKBridgeEngine>)engine;

@end

@interface OKBridgeRegister (OKBridgeInternal)

+ (void)_doRegisterIfNeeded;

@end



NS_ASSUME_NONNULL_END
