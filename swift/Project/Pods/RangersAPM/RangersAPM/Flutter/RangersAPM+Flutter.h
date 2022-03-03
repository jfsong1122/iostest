//
//  RangersAPM+Flutter.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2021/4/13.
//

#import "RangersAPM.h"

NS_ASSUME_NONNULL_BEGIN

@interface RangersAPM (Flutter)

+ (void)setDartConfigUpdateHandler:(void (^)(NSDictionary * _Nullable config))handler;

/**
 Dart异常埋点接口，异步写入

 @param stack 调用栈字符串
 @param customData 用户自定义环境数据
 @param customLog 用户自定义日志
 @param filters 用户自定义筛选项
*/
+ (void)recordDartErrorWithTraceStack:(NSString *)stack customData:(NSDictionary *)customData customLog:(NSString *)customLog filters:(NSDictionary *)filters;

+ (void)recordPerformanceLog:(NSDictionary *)log;

@end

NS_ASSUME_NONNULL_END
