//
//  BDDYCJSPatchApplyerProtocol.h
//  BDDynamicallyToBTest
//
//  Created by 朱元清 on 2021/2/8.
//

#import <Foundation/Foundation.h>
#import "BDHotfixPatch.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BDHPatchApplyerProtocol <NSObject>
@required

/// 应用热修包接口。用户应在此处实现应用热修包的逻辑。
/// @param patch 热修包对象，包含有热修文件。用户应自行接入相应热修引擎（如JSPatch）以执行这些热修文件。可选地，用户可在执行前根据热修包的属性做二重校验。
/// @return 是否成功应用热修包
- (BOOL)applyPatch:(BDHotfixPatch *)patch;

@end

NS_ASSUME_NONNULL_END
