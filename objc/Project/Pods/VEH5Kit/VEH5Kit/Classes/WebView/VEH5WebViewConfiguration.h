//
//  VEH5WebViewConfiguration.h
//  Aurum
//
//  Created by 李晓鹏 on 2021.
//

#import <Foundation/Foundation.h>

@protocol VEH5WebViewConfigurationProtocol <NSObject>

@required
+ (void)registerUserAgent:(BOOL)appendAppInfo;
+ (NSString *)userAgentString:(BOOL)appendAppInfo;

@end

@interface VEH5WebViewConfiguration : NSObject

@property (nonatomic, weak, class) Class<VEH5WebViewConfigurationProtocol> delegate;

@end

