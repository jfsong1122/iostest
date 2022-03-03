//
//  RangersAPMALogUtil.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2021/8/5.
//

#ifndef RangersAPMALogUtil_h
#define RangersAPMALogUtil_h

#ifdef __FILE_NAME__
#define __RANGERSAPM_ALOG_FILE_NAME__ __FILE_NAME__
#else
#define __RANGERSAPM_ALOG_FILE_NAME__ __FILE__
#endif

#define RANGERSAPM_ALOG(_level, _tag, _format, ...)\
do{\
rangers_apm_log_write(__RANGERSAPM_ALOG_FILE_NAME__, __FUNCTION__, _tag, _level, __LINE__, _format);\
}while(0);\

#define RANGERSAPM_ALOG_C(_level, _tag, _format, ...)\
do{\
rangers_apm_log_write_var(__RANGERSAPM_ALOG_FILE_NAME__, __FUNCTION__, _tag, _level, __LINE__, _format, ##__VA_ARGS__);\
}while(0);\

typedef enum {
    kLogLevelDebug = 0,    // Detailed information on the flow through the system.
    kLogLevelInfo = 1,     // Interesting runtime events (startup/shutdown), should be cautious and keep to a minimum.
    kLogLevelWarn = 2,     // Other runtime situations that are undesirable or unexpected, but not necessarily "wrong".
    kLogLevelError = 3,    // Other runtime errors or unexpected conditions.
} kRangersAPMALogLevel;

void rangers_apm_log_write_var(const char *_filename, const char *_func_name, const char *_tag, kRangersAPMALogLevel _level, int _line, const char * _format, ...);

void rangers_apm_log_write(const char *_filename, const char *_func_name, const char *_tag, kRangersAPMALogLevel _level, int _line, const char * _format);

#endif /* RangersAPMALogUtil_h */
