//
//  RangersAPM_ALog.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2021/8/6.
//

#ifndef RangersAPM_ALog_h
#define RangersAPM_ALog_h

#include "RangersAPMALogUtil.h"

/**
 C、C++ 日志记录方法
 */
#pragma mark - C & C++
/**
 记录一条 DEBUG 类型的日志，使用方式参考：
 ...
 RANGERSAPM_ALOG_DEBUG_C("Business", "version : %s", version())
 */
#define RANGERSAPM_ALOG_DEBUG_C(tag,format, ...) RANGERSAPM_ALOG_C(kLogLevelDebug, tag, format, ##__VA_ARGS__);

/**
 记录一条 Info 类型的日志，使用方式参考：
 ...
 RANGERSAPM_ALOG_INFO_C("Business", "version : %s", version())
 */
#define RANGERSAPM_ALOG_INFO_C(tag,format, ...) RANGERSAPM_ALOG_C(kLogLevelInfo, tag, format, ##__VA_ARGS__);

/**
 记录一条 Warn 类型的日志，使用方式参考：
 ...
 RANGERSAPM_ALOG_WARN_C("Business", "version : %s", version())
 */
#define RANGERSAPM_ALOG_WARN_C(tag,format, ...) RANGERSAPM_ALOG_C(kLogLevelWarn, tag, format, ##__VA_ARGS__);

/**
 记录一条 Error 类型的日志，使用方式参考：
 ...
 RANGERSAPM_ALOG_ERROR_C("Business", "version : %s", version())
 */
#define RANGERSAPM_ALOG_ERROR_C(tag,format, ...) RANGERSAPM_ALOG_C(kLogLevelError, tag, format, ##__VA_ARGS__);

#endif /* RangersAPM_ALog_h */
