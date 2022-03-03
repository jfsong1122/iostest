//
//  RangersAPM+UITracker.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2021/7/8.
//

#import "RangersAPM.h"

NS_ASSUME_NONNULL_BEGIN

@interface RangersAPM (UITracker)

/** 默认采用isa hook方案统计页面加载时间，数据更加准确；如果遇到冲突，可以调用此方法切换到method exchange方案
    ⚠️请在调用[RangersAPM startWithConfig:]之前调用此方法，否则方法调用无效
*/
+ (void)switchToMethodExchange;

@end

NS_ASSUME_NONNULL_END
