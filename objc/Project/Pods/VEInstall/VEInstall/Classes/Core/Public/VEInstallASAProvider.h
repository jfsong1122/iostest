//
//  VEInstallASAProvider.h
//  VEInstall
//
//  Created by KiBen on 2021/9/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol VEInstallASAProvider <NSObject>

+ (NSDictionary *)ASAParamsForAppID:(NSString *)appID;

@end

NS_ASSUME_NONNULL_END
