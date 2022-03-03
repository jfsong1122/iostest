//
//  BDNativeBaseComponent.h
//  ByteWebView
//
//  Created by liuyunxuan on 2019/6/12.
//

#import <Foundation/Foundation.h>
#import "BDNativeContainerObject.h"

typedef void(^BDNativeDispatchActionCallback)(NSDictionary *callbackData);

@class WKWebView;

@interface BDNativeBaseComponent : NSObject

+ (NSString *)nativeTagName;

- (UIView *)insertInNativeContainerObject:(BDNativeContainerObject *)containerObject params:(NSDictionary *)params;

- (void)updateInNativeContainerObject:(BDNativeContainerObject *)containerObject params:(NSDictionary *)params;

- (void)deleteInNativeContainerObject:(BDNativeContainerObject *)containerObject params:(NSDictionary *)params;

- (void)actionInNativeContainerObject:(BDNativeContainerObject *)containerObject
                               method:(NSString *)method
                               params:(NSDictionary *)params
                             callback:(BDNativeDispatchActionCallback)callback;

- (void)fireComponentAction:(NSString *)action params:(NSDictionary *)params;


@end
