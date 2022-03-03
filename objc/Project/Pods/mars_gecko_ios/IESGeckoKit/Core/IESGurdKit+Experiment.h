//
//  IESGurdKit+Experiment.h
//  IESGeckoKit
//
//  Created by 陈煜钏 on 2020/8/23.
//

#import "IESGeckoKit.h"

NS_ASSUME_NONNULL_BEGIN

@interface IESGurdKit (Experiment)

@property (class, nonatomic, assign, getter=isThrottleEnabled) BOOL throttleEnabled;

@property (class, nonatomic, assign, getter=isRetryEnabled) BOOL retryEnabled;

@property (class, nonatomic, assign, getter=isPollingEnabled) BOOL pollingEnabled;

@end

NS_ASSUME_NONNULL_END
