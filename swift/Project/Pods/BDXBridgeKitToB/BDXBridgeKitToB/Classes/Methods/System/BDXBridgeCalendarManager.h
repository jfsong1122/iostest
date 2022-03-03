//
//  BDXBridgeCalendarManager.h
//  BDXBridgeKit
//
//  Created by Lizhen Hu on 2021/3/9.
//

#import "BDXBridgeMethod.h"

NS_ASSUME_NONNULL_BEGIN

@class BDXBridgeSetCalendarEventMethodParamModel;

@interface BDXBridgeCalendarManager : NSObject

@property (class, nonatomic, strong, readonly) BDXBridgeCalendarManager *sharedManager;

- (void)createEventWithParamModel:(BDXBridgeSetCalendarEventMethodParamModel *)eventInfo completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;
- (void)updateEventWithParamModel:(BDXBridgeSetCalendarEventMethodParamModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;
- (void)deleteEventWithEventID:(NSString *)eventID completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;

#if 0
- (void)readEventWithEventID:(NSString *)eventID completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;
#endif

@end

NS_ASSUME_NONNULL_END
