//
//  BDWebView+TTNet.h
//  ByteWebView
//
//  Created by 杨牧白 on 2019/12/30.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDWebViewTTNetUtil : NSObject

@property (nonatomic, class, readonly)NSArray * ttnetRefErrorURLs;

+ (void)addTTNetBlockList:(NSString *)url;

+ (BOOL)isHitTTNetBlockListWithURL:(NSString *)url;

+ (NSInteger)ttnetAutoBlockListCount;

@end

NS_ASSUME_NONNULL_END
