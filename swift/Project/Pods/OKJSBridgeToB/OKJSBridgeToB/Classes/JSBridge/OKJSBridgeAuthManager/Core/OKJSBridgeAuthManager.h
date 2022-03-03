//
//  OKJSBridgeAuthManager.h
//
//  Created by Lizhen Hu on 2019/8/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef OKPiperAuthTypeDef
#define OKPiperAuthTypeDef
typedef NS_ENUM(NSUInteger, OKPiperAuthType){
    OKPiperAuthPublic = 0,
    OKPiperAuthProtected,
    OKPiperAuthPrivate,
    OKPiperAuthSecure,
};
#endif
extern NSString * const OKPiperDefaultNamespace;

typedef NSDictionary * _Nonnull (^OKBridgeAuthCommonParamsBlock)(void);

@class OKJSBridgeAuthManager;

@protocol OKJSBridgeAuthManagerDelegate <NSObject>

- (BOOL)authManager:(OKJSBridgeAuthManager *)authManager isAuthorizedMethod:(NSString *)method forURL:(NSURL *)url;

- (void)authManager:(OKJSBridgeAuthManager *)authManager isAuthorizedMethod:(NSString *)method success:(BOOL)success forURL:(NSURL *)url stage:(NSString *)stage list:(nullable NSArray <NSString *> *)list;

@end

@interface OKJSBridgeAuthManager : NSObject

+ (void)configureWithAuthDomain:(nullable NSString *)authDomain accessKey:(NSString *)accessKey secretKey:(NSString *)secretKey boeHostSuffix:(nullable NSString *)boeHostSuffix afterDelay:(NSTimeInterval)delay commonParams:(OKBridgeAuthCommonParamsBlock)commonParams extraChannels:(nullable NSArray<NSString *> *)extraChannels;
+ (void)configureWithAuthDomain:(nullable NSString *)authDomain accessKey:(NSString *)accessKey secretKey:(NSString *)secretKey afterDelay:(NSTimeInterval)delay commonParams:(OKBridgeAuthCommonParamsBlock)commonParams extraChannels:(nullable NSArray<NSString *> *)extraChannels;
+ (void)configureWithAuthDomain:(nullable NSString *)authDomain accessKey:(NSString *)accessKey secretKey:(NSString *)secretKey commonParams:(OKBridgeAuthCommonParamsBlock)commonParams;
+ (void)configureWithAuthDomain:(nullable NSString *)authDomain accessKey:(NSString *)accessKey secretKey:(NSString *)secretKey afterDelay:(NSTimeInterval)delay commonParams:(OKBridgeAuthCommonParamsBlock)commonParams;

+ (void)addPrivateDomains:(NSArray<NSString *> *)privateDomains inNamespace:(NSString *)namespace;

+ (instancetype)sharedManager;

+ (instancetype)sharedManagerWithNamesapce:(NSString *_Nullable)namespace;

- (void)addPrivateDomains:(NSArray<NSString *> *)privateDomains;

- (void)registerMethod:(NSString *)method withAuthType:(OKPiperAuthType)authType;

- (BOOL)isAuthorizedMethod:(NSString *)method forURL:(NSURL *)url;
- (OKPiperAuthType)authGroupForURL:(NSURL *)url;

// Reminder: keep disabled in production environment.
@property (nonatomic, assign, getter=isBypassJSBAuthEnabled) BOOL bypassJSBAuthEnabled;

@property (nonatomic, assign, getter=isBuiltinAuthInfosEnabled) BOOL builtinAuthInfosEnabled;
@property (nonatomic, assign, getter=hasFetchedAuthInfos, readonly) BOOL fetchedAuthInfos;
@property (nonatomic, assign, readonly) BOOL hasCachedAuthInfos;
@property (nonatomic, weak) id<OKJSBridgeAuthManagerDelegate> delegate;

@property (nonatomic, copy) NSArray<NSString *> *innerDomains;

@end
NS_ASSUME_NONNULL_END
