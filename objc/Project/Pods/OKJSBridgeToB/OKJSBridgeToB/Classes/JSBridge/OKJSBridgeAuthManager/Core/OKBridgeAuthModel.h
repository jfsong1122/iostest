//
//  OKBridgeAuthModel.h
//
//  Created by Lizhen Hu on 2019/8/29.
//

#import <Foundation/Foundation.h>
#import "OKJSBridgeAuthManager.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - OKBridgeAuthRule

@interface OKBridgeAuthRule : NSObject <NSCoding>

@property (nonatomic, copy, readonly) NSString *pattern;
@property (nonatomic, assign, readonly) OKPiperAuthType group;
@property (nonatomic, copy, readonly) NSArray<NSString *> *includedMethods;
@property (nonatomic, copy, readonly) NSArray<NSString *> *excludedMethods;

- (instancetype)initWithDictionary:(NSDictionary *)dict;
- (instancetype)initWithPattern:(NSString *)pattern group:(OKPiperAuthType)group;

@end

#pragma mark - OKOverriddenMethodPackage

@interface OKOverriddenMethodPackage : NSObject <NSCoding>

@property (nonatomic, strong, readonly) NSMutableSet<NSString *> *publicMethods;
@property (nonatomic, strong, readonly) NSMutableSet<NSString *> *protectedMethods;
@property (nonatomic, strong, readonly) NSMutableSet<NSString *> *privateMethods;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

- (BOOL)containsMethodName:(NSString *)methodName;

@end

#pragma mark - OKBridgeAuthPackage

extern NSString * const OKBridgeAuthInfoChannel;

@interface OKBridgeAuthPackage : NSObject <NSCoding>

@property (nonatomic, copy, readonly) NSDictionary<NSString *, NSArray<OKBridgeAuthRule *> *> *content;
@property (nonatomic, strong, readonly) OKOverriddenMethodPackage *overriddenMethodPackage;
@property (nonatomic, assign, readonly, getter=isBridgeAuthInfo) BOOL bridgeAuthInfo;

@property (nonatomic, copy, readonly) NSString *namespace;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

@interface OKBridgeAuthRequestParams : NSObject

@property (nonatomic, copy) NSString *authDomain;
@property (nonatomic, copy) NSString *accessKey;
@property (nonatomic, copy) NSString *secretKey;
@property (nonatomic, copy) NSArray<NSString *> *extraChannels;

@property (nonatomic, copy) OKBridgeAuthCommonParamsBlock commonParams;

@end


NS_ASSUME_NONNULL_END
