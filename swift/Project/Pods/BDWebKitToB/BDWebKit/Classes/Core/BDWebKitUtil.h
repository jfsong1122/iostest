//
//  BDWebKitUtil.h
//  BDWebKit
//
//  Created by wealong on 2020/3/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDWebKitUtil : NSObject

// https://stackoverflow.com/questions/8801377/getting-the-default-file-extension-for-a-content-type-in-javascript
+ (NSString *)contentTypeOfExtension:(NSString *)extension;

@end

BOOL BDWK_isEmptyString(id param);

NS_ASSUME_NONNULL_END
