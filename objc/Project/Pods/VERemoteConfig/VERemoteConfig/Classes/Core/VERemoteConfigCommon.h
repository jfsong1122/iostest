//
//  VERemoteConfigCommon.h
//  Pods
//
//  Created by Ada on 2021/11/1.
//

// 拉取远程配置的回调类型
typedef void (^FetchCallback)(NSError *_Nullable error);

// 数据类型
typedef enum {
    STRING,
    INT,
    FLOAT,
    BOOLEAN
} VEDataType;

extern NSString* _Nonnull VEDataTypeString[];
