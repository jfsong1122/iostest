//
//  RangersAPMPerformanceErrorType.h
//  HeimdallrFinder
//
//  Created by xuminghao.eric on 2021/7/15.
//

#ifndef RangersAPMPerformanceErrorType_h
#define RangersAPMPerformanceErrorType_h

typedef void (^RangersAPMStartDetectorCallback)(NSError *_Nullable error);

extern NSErrorDomain const RangersAPMStartDetectorErrorDomain;

typedef NS_ENUM(NSInteger, RangersAPMStartDetectorErrorType) {
    RangersAPMStartDetectorErrorTypeNoStartTime  = 1,     // span没有记录开始时间（就记录结束时间）
    RangersAPMStartDetectorErrorTypeFinish = 2,     // 启动监控已经结束
    RangersAPMStartDetectorErrorTypeDuplicateSpanName = 3, // spanName重复，请使用其他名称
    RangersAPMStartDetectorErrorTypeSpanNameNil = 4    // spanName为nil或length = 0
};

#endif /* RangersAPMPerformanceErrorType_h */
