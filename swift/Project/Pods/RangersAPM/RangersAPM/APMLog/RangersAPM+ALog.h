//
//  RangersAPM+ALog.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2021/7/29.
//

#import "RangersAPMALogUtil.h"
#import "RangersAPM.h"

/**
 Objective-C 日志记录方法，使用方法和 'NSLog' 相似
  
 OC method
 */
#pragma mark - Objective-C

/**
 记录一条 Debug 类型的日志，使用方式参考：
 ...
 RANGERSAPM_ALOG_DEBUG(@"Business", @"version : %@", [self version])
 ...
 */
#define RANGERSAPM_ALOG_DEBUG(tag, format, ...)\
@autoreleasepool {RANGERSAPM_ALOG(kLogLevelDebug, [tag UTF8String], NSCHAR_LOG(format, ##__VA_ARGS__))};

/**
 记录一条 Info 类型的日志，使用方式参考：
 ...
 RANGERSAPM_ALOG_INFO(@"Business", @"version : %@", [self version])
 ...
 */
#define RANGERSAPM_ALOG_INFO(tag, format, ...)\
@autoreleasepool {RANGERSAPM_ALOG(kLogLevelInfo, [tag UTF8String], NSCHAR_LOG(format, ##__VA_ARGS__))};

/**
 记录一条 Warn 类型的日志，使用方式参考：
 ...
 RANGERSAPM_ALOG_WARN(@"Business", @"version : %@", [self version])
 ...
 */
#define RANGERSAPM_ALOG_WARN(tag, format, ...)\
@autoreleasepool {RANGERSAPM_ALOG(kLogLevelWarn, [tag UTF8String], NSCHAR_LOG(format, ##__VA_ARGS__))};

/**
 记录一条 Error 类型的日志，使用方式参考：
 ...
 RANGERSAPM_ALOG_ERROR(@"Business", @"version : %@", [self version])
 ...
 */
#define RANGERSAPM_ALOG_ERROR(tag, format, ...)\
@autoreleasepool {RANGERSAPM_ALOG(kLogLevelError, [tag UTF8String], NSCHAR_LOG(format, ##__VA_ARGS__))};

#define NSCHAR_LOG(format, ...) ([[NSString stringWithFormat:format, ##__VA_ARGS__, nil] UTF8String])

NS_ASSUME_NONNULL_BEGIN

@interface RangersAPM (ALog)

/**
 开启ALog功能
 */
+ (void)setALogEnabled;

/**
 关闭ALog功能
 */
+ (void)setALogDisabled;

/**
 写ALog时同时输出到控制台
 */
+ (void)enableConsoleLog;

/**
 Swift 日志记录方法
 */
#pragma mark - Swift

/**
* 写入Debug Log
* Recommended Usage：RangersAPM.debugALog("alogtest", tag: "hmd", fileName: #file, funcName: #function, line: #line)
*/
+ (void)debugALog:(NSString *)format
              tag:(nullable NSString *)tag
         fileName:(NSString *)fileName
         funcName:(NSString *)funcName
             line:(int)line;

/**
* 写入Info Log
* Recommended Usage：RangersAPM.infoALog("alogtest", tag: "hmd", fileName: #file, funcName: #function, line: #line)
*/
+ (void)infoALog:(NSString *)format
             tag:(nullable NSString *)tag
        fileName:(NSString *)fileName
        funcName:(NSString *)funcName
            line:(int)line;

/**
* 写入Warn Log
* Recommended Usage：RangersAPM.warnALog("alogtest", tag: "hmd", fileName: #file, funcName: #function, line: #line)
*/
+ (void)warnALog:(NSString *)format
             tag:(nullable NSString *)tag
        fileName:(NSString *)fileName
        funcName:(NSString *)funcName
            line:(int)line;

/**
* 写入Error Log
* Recommended Usage：RangersAPM.errorALog("alogtest", tag: "hmd", fileName: #file, funcName: #function, line: #line)
*/
+ (void)errorALog:(NSString *)format
              tag:(nullable NSString *)tag
         fileName:(NSString *)fileName
         funcName:(NSString *)funcName
             line:(int)line;

@end

NS_ASSUME_NONNULL_END
