//
//  OKUnifyBridgeAuthManager.h
//  BridgeUnifyDemo
//
//  Created by renpeng on 2018/10/9.
//  Copyright © 2018年 tt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OKBridgeAuthorization.h"

@protocol OKUnifyBridgeAuthDefaultSettings <NSObject>

- (NSString *)defaultAuthRequesthHost;

- (NSArray *)defaultInnerDomains;

@end

typedef NSDictionary *(^OKUnifyBridgeAuthCommonParamsBlock)(void);
@interface OKUnifyBridgeAuthManager : NSObject<OKBridgeAuthorization, OKUnifyBridgeAuthDefaultSettings>

+ (instancetype)sharedManager;

// Union the local inner domains and domains from Allowlist in settings.
- (void)updateInnerDomainsFromRemote:(NSArray<NSString *> *)domains;

- (void)updateInnerDomainsFromRemote:(NSArray<NSString *> *)domains shouldUpdateGeckoPrivateDomains:(BOOL) shouldUpdateGeckoPrivateDomains;

- (BOOL)isInnerDomainForURL:(NSURL *)url;

- (void)startGetAuthConfigWithPartnerClientKey:(NSString*)clientKey
                                 partnerDomain:(NSString*)domain
                                     secretKey:(NSString*)secretKey
                                   finishBlock:(void(^)(BOOL success))finishBlock;

// 3.0 new auth interface
+ (void)configureWithAuthDomain:(NSString *)authDomain accessKey:(NSString *)accessKey secretKey:(NSString *)secretKey commonParams:(OKUnifyBridgeAuthCommonParamsBlock)commonParams;

+ (void)configureWithAuthDomain:(nullable NSString *)authDomain accessKey:(NSString *)accessKey secretKey:(NSString *)secretKey boeHostSuffix:(nullable NSString *)boeHostSuffix afterDelay:(NSTimeInterval)delay commonParams:(OKUnifyBridgeAuthCommonParamsBlock)commonParams;

/**
 Default YES.
 */
@property (nonatomic, assign) BOOL authEnabled;


@property (atomic, copy) NSString *authRequesthHost;

/**
Default YES.
*/
@property (nonatomic, assign) BOOL geckoAuthEnabled;

@end
