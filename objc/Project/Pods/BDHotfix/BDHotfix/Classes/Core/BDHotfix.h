//
//  BDHotfix.h
//  BDHotfix
//
//  Created by 朱元清 on 2021/2/9.
//

#import <Foundation/Foundation.h>
#import "BDHotfixConfig.h"
#import "BDHotfixPatchModel.h"
#import "BDHotfixPatch.h"
#import "BDHotfixDelegate.h"
#import "BDHPatchApplyerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// 单例
@interface BDHotfix : NSObject

/// 代理对象。可选传入。
@property (nonatomic, weak) id<BDHotfixDelegate> delegate;
@property (nonatomic, readonly) NSString *deviceId;

/// 热修包运行引擎。
@property (nonatomic, strong) id<BDHPatchApplyerProtocol> patchApplyer;

+ (instancetype)sharedInstance;
+ (void)setCustomDid:(NSString *)did;

/// 启动SDK: 应用本地热修包；同步热修包（如配置）
- (void)startWithConfig:(BDHotfixConfig *)config;

/// 同步热修包
- (void)sync;

- (instancetype)init __attribute__((unavailable("init not available for singleton")));

+ (instancetype)new __attribute__((unavailable("new not available for singleton")));

@end

NS_ASSUME_NONNULL_END
