//
//  BDNativeBaseComponent+Private.h
//  BDNativeWebComponent
//
//  Created by liuyunxuan on 2019/9/9.
//

#import "BDNativeBaseComponent.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDNativeBaseComponent()

@property (nonatomic, strong) NSString *iFrameID;
@property (nonatomic, weak) WKWebView *webView;
@property (nonatomic, strong) NSNumber *tagId;
@property (nonatomic, strong) NSArray<NSNumber *> *radiusNums;

@end

@interface BDNativeBaseComponent (Private)

- (void)containerFrameChanged:(BDNativeContainerObject *)containerObject;

- (void)baseInsertInNativeContainerObject:(BDNativeContainerObject *)containerObject params:(NSDictionary *)params;

- (void)baseUpdateInNativeContainerObject:(BDNativeContainerObject *)containerObject params:(NSDictionary *)params;

- (void)baseDeleteInNativeContainerObject:(BDNativeContainerObject *)containerObject params:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
