//
//  VEInstallStartUpTask.h
//  VEInstall
//
//  Created by KiBen on 2021/10/14.
//

#import <Foundation/Foundation.h>
#import <OneKit/OKStartUpTask.h>
#import <OneKit/OKServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface VEInstallStartUpTask : OKStartUpTask<OKDeviceService>

- (nullable NSString *)deviceID;
- (nullable NSString *)installID;
- (nullable NSString *)ssID;

@end

NS_ASSUME_NONNULL_END
