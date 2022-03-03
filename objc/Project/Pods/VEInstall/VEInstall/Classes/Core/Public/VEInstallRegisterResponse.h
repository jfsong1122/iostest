//
//  VEInstallRegisterResponse.h
//  VEInstall
//
//  Created by KiBen on 2021/9/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VEInstallRegisterResponse : NSObject <NSCopying>

/// 标记当前Response实例内容是否为本地缓存
/// @note 只有当是网络请求返回的response，该字段才会为NO；其他情况都为YES
@property (nonatomic, assign, readonly) BOOL fromCache;

@property (nonatomic, copy, readonly) NSString *deviceID;

@property (nonatomic, copy, readonly) NSString *installID;

@property (nonatomic, copy, readonly) NSString *cdValue;

@property (nonatomic, copy, readonly) NSString *ssID;

@property (nonatomic, assign, readonly) BOOL isNewUser;

@property (nonatomic, assign, readonly) NSString *deviceToken;

- (NSString *)description;

@end

NS_ASSUME_NONNULL_END
