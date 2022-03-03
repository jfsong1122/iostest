//
//  LicenseCenter.h
//  OneKit
//
//  Created by bytedance on 2022/1/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int)  {
    None = 0,
    LicenseSignatureError,
    LicenseParseError,
    AppNameNotFound,
    ModuleNotFound,
    FeatureNotFound,
    FeatureExpired,
} LicenseError;

typedef struct {
    BOOL valid;
    LicenseError error;
    NSString *licenseVersion;
}VerificationResult;

@interface LicenseCenter : NSObject

+ (VerificationResult)verify:(NSString *) module andFeature:(NSString*) feature;
@end

NS_ASSUME_NONNULL_END
