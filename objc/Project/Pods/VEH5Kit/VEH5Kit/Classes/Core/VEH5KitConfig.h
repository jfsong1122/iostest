//
//  VEH5KitConfig.h
//  VEH5Kit
//
//  Created by 朱元清 on 2021/6/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VEH5KitConfig : NSObject

/************* Commom config *************/
@property (nonatomic) NSString *appID;

@property (nonatomic) NSString *appVersion;

@property (nonatomic) NSString *accessKey;

@property (nonatomic) NSString *secretKey;

@property (nonatomic, copy,  nonnull) NSString* (^getDeviceIDBlock)(void);

@property (nonatomic, copy, readonly) NSString *deviceID;

@property (nonatomic) BOOL isInhouseApp;

/// start TTNetworkManager SDK at start. Default to YES.
@property (nonatomic) BOOL startTTNetwork;


/************* JSBridge config *************/
@property (nonatomic) NSString *authDomain;


/************* Gecko config *************/
@property (nonatomic) NSString *platformDomain;

@property (nonatomic) NSString *pattern;

@property (nonatomic) NSArray <NSString *> *geckoChannels;

@property (nonatomic) NSString *geckoAccessKey;

@end

NS_ASSUME_NONNULL_END
