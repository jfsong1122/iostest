//
//  VEInstallDataEncryptProvider.h
//  VEInstall
//
//  Created by KiBen on 2021/9/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 如果需要自定义加密算法，可通过实现该协议，然后将provider传给VEInstallConfig.encryptProvider属性即可
@protocol VEInstallDataEncryptProvider <NSObject>

/// 数据加密
/// @param originalData 原始待加密数据
/// @return 加密后的数据
+ (NSData *_Nullable)encryptData:(NSData *)originalData forAppID:(NSString *)appID;

@end

NS_ASSUME_NONNULL_END
