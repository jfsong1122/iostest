//
//  BDALogPlaceholder.h
//  Pods
//
//  Created by 朱元清 on 2021/4/13.
//

#ifndef BDALogPlaceholder_h
#define BDALogPlaceholder_h

#ifdef __OBJC__
#import<Foundation/Foundation.h>

#define NSCHAR_LOG(format, ...) ([[NSString stringWithFormat:format, ##__VA_ARGS__, nil] UTF8String])

#pragma mark -  OC method and its usage is same as 'NSLog'
//自定义level
#define BDALOG_PROTOCOL(level, format, ...)\
@autoreleasepool {ALOG_PROTOCOL(level, "", NSCHAR_LOG(format, ##__VA_ARGS__))};

//自定义level和tag
#define BDALOG_PROTOCOL_TAG(level, tag, format, ...)\
@autoreleasepool {ALOG_PROTOCOL(level, [tag UTF8String], NSCHAR_LOG(format, ##__VA_ARGS__))};


//debug log
#define BDALOG_PROTOCOL_DEBUG(format, ...)\
@autoreleasepool {ALOG_PROTOCOL(kLogLevelDebug, "", NSCHAR_LOG(format, ##__VA_ARGS__))};

//info log
#define BDALOG_PROTOCOL_INFO(format, ...)\
@autoreleasepool {ALOG_PROTOCOL(kLogLevelInfo, "", NSCHAR_LOG(format, ##__VA_ARGS__))};

//warn log
#define BDALOG_PROTOCOL_WARN(format, ...)\
@autoreleasepool {ALOG_PROTOCOL(kLogLevelWarn, "", NSCHAR_LOG(format, ##__VA_ARGS__))};

//error log
#define BDALOG_PROTOCOL_ERROR(format, ...)\
@autoreleasepool {ALOG_PROTOCOL(kLogLevelError, "", NSCHAR_LOG(format, ##__VA_ARGS__))};

//fatal log
#define BDALOG_PROTOCOL_FATAL(format, ...)\
@autoreleasepool {ALOG_PROTOCOL(kLogLevelFatal, "", NSCHAR_LOG(format, ##__VA_ARGS__))};


/** TAG*/
//debug log
#define BDALOG_PROTOCOL_DEBUG_TAG(tag, format, ...)\
@autoreleasepool {ALOG_PROTOCOL(kLogLevelDebug, [tag UTF8String], NSCHAR_LOG(format, ##__VA_ARGS__))};

//info log
#define BDALOG_PROTOCOL_INFO_TAG(tag, format, ...)\
@autoreleasepool {ALOG_PROTOCOL(kLogLevelInfo, [tag UTF8String], NSCHAR_LOG(format, ##__VA_ARGS__))};

//warn log
#define BDALOG_PROTOCOL_WARN_TAG(tag, format, ...)\
@autoreleasepool {ALOG_PROTOCOL(kLogLevelWarn, [tag UTF8String], NSCHAR_LOG(format, ##__VA_ARGS__))};

//error log
#define BDALOG_PROTOCOL_ERROR_TAG(tag, format, ...)\
@autoreleasepool {ALOG_PROTOCOL(kLogLevelError, [tag UTF8String], NSCHAR_LOG(format, ##__VA_ARGS__))};

//fatal log
#define BDALOG_PROTOCOL_FATAL_TAG(tag, format, ...)\
@autoreleasepool {ALOG_PROTOCOL(kLogLevelFatal, [tag UTF8String], NSCHAR_LOG(format, ##__VA_ARGS__))};

#endif


#define ALOG_PROTOCOL(_level, _tag, _format, ...)\
do{\
}while(0);\


#endif /* BDALogPlaceholder_h */
