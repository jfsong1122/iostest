
#import <Foundation/Foundation.h>

@interface PushMessageBaseObject : NSObject

@property (nonatomic, assign) uint64_t sequenceId;
@property (nonatomic, assign) uint64_t logId;
@property (nonatomic, assign) int32_t method;
@property (nonatomic, assign) int32_t service;
@property (nonatomic, copy) NSData *payload;
@property (nonatomic, copy) NSString *payloadType;
@property (nonatomic, copy) NSString *payloadEncoding;
@property (nonatomic, copy) NSDictionary<NSString *, NSString *> *headers;

@end
