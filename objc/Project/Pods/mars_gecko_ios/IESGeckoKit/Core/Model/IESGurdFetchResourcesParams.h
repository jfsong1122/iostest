//
//  IESGurdFetchResourcesParams.h
//  IESGeckoKit
//
//  Created by 陈煜钏 on 2020/8/19.
//

#import <Foundation/Foundation.h>

#import "IESGeckoDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface IESGurdFetchResourcesParams : NSObject

@property (nonatomic, copy) NSString *accessKey;

@property (nonatomic, copy) NSArray<NSString *> *channels;

@property (nonatomic, copy) NSString *groupName;

@property (nonatomic, copy) NSString *SDKVersion;

@property (nonatomic, copy) NSString *resourceVersion;

@property (nonatomic, copy) NSString *businessDomain;

@property (nonatomic, copy) NSDictionary *customParams;

@property (nonatomic, assign) BOOL forceRequest;

@property (nonatomic, assign) BOOL disableThrottle;

@property (nonatomic, assign) IESGurdPollingPriority pollingPriority;

@property (nonatomic, assign) IESGurdDownloadPriority downloadPriority;

- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
