//
//  TTHttpRequest+OKSignature.h
//  OneKit
//
//  Created by 朱元清 on 2021/1/13.
//
#import <Foundation/Foundation.h>
#import <TTNetworkManager/TTNetworkManager.h>
NS_ASSUME_NONNULL_BEGIN

@interface TTHttpRequest (OKSignature)

- (void)ok_signWithAK:(NSString *)AK SK:(NSString *)SK;

@end

NS_ASSUME_NONNULL_END
