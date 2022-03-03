//
//  IESGurdResourceModel.h
//  IESGurdKit
//
//  Created by 01 on 17/6/30.
//

#import <Foundation/Foundation.h>

#import "IESGeckoDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface IESGurdResourceStrategies : NSObject

@property (nonatomic, assign) BOOL deleteIfDownloadFailed;
@property (nonatomic, assign) BOOL deleteBeforeDownload;

@end

@interface IESGurdResourceURLInfo : NSObject

// 包ID
@property (nonatomic, assign) int ID;

// 下载URL
@property (nonatomic, copy) NSString *url;

// 下载URL列表(包含url)
@property (nonatomic, copy) NSArray<NSString *> *urlList;

// 包MD5值
@property (nonatomic, copy) NSString *md5;

@end

@interface IESGurdResourceModel : NSObject

// 版本号
@property (nonatomic, assign) int version;

// accessKey
@property (nonatomic, copy) NSString *accessKey;

// 所属频道
@property (nonatomic, copy) NSString *channel;

// 文件类型
@property (nonatomic, assign) IESGurdChannelFileType packageType;

// 全量包信息
@property (nonatomic, strong) IESGurdResourceURLInfo *package;

// 增量包信息
@property (nonatomic, strong) IESGurdResourceURLInfo * _Nullable patch;

// 离线包策略
@property (nonatomic, strong) IESGurdResourceStrategies * _Nullable strategies;

// 需要解压
@property (nonatomic, readonly, assign) BOOL needUnzip;

// 组名
@property (nonatomic, copy) NSString *groupName;

// 下载优先级
@property (nonatomic, assign) IESGurdDownloadPriority downloadPriority;

// 业务identifier
@property (nonatomic, copy) NSArray<NSString *> *businessIdentifiers;

@property (nonatomic, readonly, copy) NSString *logId;

// 当channel为kIESGurdOfflinePrefixChannel时有效
@property (nonatomic, copy) NSArray<NSString *> *offlinePrefixURLsArray;

+ (instancetype _Nullable)instanceWithDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
