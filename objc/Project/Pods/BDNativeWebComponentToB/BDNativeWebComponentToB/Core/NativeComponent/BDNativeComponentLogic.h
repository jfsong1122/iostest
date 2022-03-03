//
//  BDNativeComponentLogic.h
//  ByteWebView
//
//  Created by liuyunxuan on 2019/6/12.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "BDNativeContainerObject.h"
#import "BDNativeBaseComponent.h"
NS_ASSUME_NONNULL_BEGIN

@protocol BDNativeComponentLogicDelegate <NSObject>

@required
-(UIView *)attachWebScrollViewByIndex:(NSInteger)index scrollContentWidth:(NSInteger)scrollContentWidth;

- (WKWebView *)nativeComponentWebView;

@end

@interface BDNativeComponentLogic : NSObject

@property (nonatomic, weak) id <BDNativeComponentLogicDelegate>delegate;

@property (nonatomic, strong) NSMutableDictionary <NSString *, BDNativeContainerObject *>*containerObjects;

- (NSArray *)insertNativeTags:(NSArray *)params;

- (NSArray *)updateNativeTags:(NSArray *)params;

- (NSArray *)deleteNativeTags:(NSArray *)params;

- (void)dispatchAction:(NSDictionary *)param callback:(BDNativeDispatchActionCallback)callback;

- (NSArray *)checkNativeInfos;

- (void)clearNativeComponentWithIFrameID:(NSString *)iFrameID;

- (void)clearNativeComponent;

+ (void)registerGloablNativeComponent:(NSArray<Class> *)components;

- (void)registerNativeComponent:(NSArray<Class> *)components;

@end

NS_ASSUME_NONNULL_END
