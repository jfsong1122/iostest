//
//  BDWebKitSettingsManger.h
//  BDWebKit
//
//  Created by wealong on 2020/3/6.
//

#import <Foundation/Foundation.h>


@protocol BDWebKitSettingsDelegate <NSObject>

@optional

#pragma mark - Fix Crash

@optional

+ (BOOL)bdFixWKWebViewSchemeTaskCrash;

+ (BOOL)bdWKWebViewFixEnable;

+ (BOOL)bdValidPointerCheckEnable; //

+ (BOOL)bdValidObjectCheckEnable; //

+ (BOOL)bdFixWebViewBackGroundTaskHangEnable; //

+ (BOOL)bdFixWebViewBackGroundTaskAfterReleaseEnable; //

+ (BOOL)bdFixWebViewBackGroundNotifyHangEnable;  //

+ (BOOL)bdFixWebViewBackGroundNotifyTimeOutEnable; //

+ (CGFloat)bdFixWebViewBackGroundTaskTimeout; //

+ (NSInteger)bdFixProcessTerminateCrash;

+ (BOOL)bdFixRequestURLCrashEnable;

+ (BOOL)bdFixDelegateDeallocCrashEnable;

+ (BOOL)bdFixBlobCrashEnable;

+ (BOOL)bdFixWKScriptMessageCrash;

+ (BOOL)bdFixWKRecoveryAttempterCrash;

+ (BOOL)bdFixWKReloadFrameErrorRecoveryAttempter;

+ (BOOL)bdFixWKReleaseEarlyCrash;

+ (float)bdFixWKReleaseEarlyCrashKeeperTs;

+ (BOOL)bdFixAddUpdateCrash;

#pragma mark - XDebugger

+ (BOOL)bdXDebuggerEnable;

#pragma mark - Offline

+ (NSArray <NSString *>*_Nonnull)skipSSLCertificateList;

+ (BOOL)checkOfflineWholeLife:(NSString *_Nullable)url;

+ (BOOL)checkOfflineChannelInterceptor;

+ (BOOL)checkOfflineChannelInterceptorInjectJS;

#pragma mark - TTNet

+ (BOOL)bdTTNetOriginOpitimise; //

+ (BOOL)bdTTNetFixRedirect; //

+ (BOOL)bdFixSyncAjaxCrashEnable; //

+ (CGFloat)bdFixTTNetTimeout; //

+ (BOOL)bdTTNetCacheControlEnable;

+ (BOOL)bdTTNetAutoBlockListEnable;

+ (BOOL)bdTTNetBlobAutoBlackEnable;

+ (NSArray *_Nullable)bdTTNetAutoBlockListErrorStatusCode;

+ (BOOL)bdEnablePrefetch;

+ (BOOL)useNewBlankCheck;

+ (BOOL)bdTTNetFixCors;

+ (BOOL)bdTTNetAvoidNoResponseException;

+ (BOOL)bdCookieSecureEnable;

+ (NSArray<NSString *> *)bdSecureCookieList;

+ (BOOL)bdAddAcceptLanguageHeaderIfNeeded;

@end

NS_ASSUME_NONNULL_BEGIN

@interface BDWebKitSettingsManger : NSObject <BDWebKitSettingsDelegate>

@property (strong, nonatomic, class) Class<BDWebKitSettingsDelegate> settingsDelegate;

@end

NS_ASSUME_NONNULL_END
