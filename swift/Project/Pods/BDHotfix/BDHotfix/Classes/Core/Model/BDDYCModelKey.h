//
//  BDDYCModelKey.h
//  BDDynamically
//
//  Created by 朱元清 on 2021/2/9.
//

#ifndef BDDYCModelKey_h
#define BDDYCModelKey_h



#pragma mark - request keys

/**
 URL request parameter keys
 */
#define kBDDYCAppIdReqKey               (@"aid")
#define kBDDYCAppNameReqKey             (@"app_name")
#define kBDDYCDeviceIdReqKey            (@"device_id")
#define kBDDYCChannelReqKey             (@"channel")
#define kBDDYCOSVersionReqKey           (@"os_version")             // system version
#define kBDDYCAppVersionReqKey          (@"version_code")           // app version
#define kBDDYCAppBuildVersionReqKey     (@"update_version_code")    // app build version
#define kBDDYCDeviceMachineReqKey       (@"device_hardware_type")   // device hardware type
#define kBDDYCDevicePlatformReqKey      (@"device_platform")        // device platform 'iphone'
#define kBDDYCActiveArchReqKey          (@"active_arch")            // device supported latest arch
#define kBDDYCLocaleIdentifierReqKey    (@"locale_identifier")      //
#define kBDDYCLanguageReqKey            (@"language")               //
#define kBDDYCCountryCodeReqKey         (@"country")                //
#define kBDDYCSDKVersion                (@"x-sdk-version")

#define kBDDYCBandageListReqKey           (@"patch")                  // patch
#define kBDDYCBandageIdReqKey             (@"patch_id")               // patch id
#define kBDDYCBandageNameReqKey           (@"patch_name")             // patch name
#define kBDDYCBandageVersionReqKey        (@"versioncode")            // lastpatch_version



#pragma mark - response keys

/**
 URL response parameter keys
 */
#define KBDDYCURLResponseMsgKey         (@"message")
#define KBDDYCURLResponseDataKey        (@"data")

#define kBDDYCBandageListRespKey          (@"patch")

#define kBDDYCHotfixIDRespKey             (@"hotfix_id")
#define kBDDYCBandageIDRespKey            (@"patch_id")               // patch_id
#define kBDDYCBandageNameRespKey          (@"patch_name")             // patch_name
#define kBDDYCBandageVersionRespKey       (@"versioncode")            // patch_version
#define kBDDYCAppVersionRespKey         (@"app_version")            // app_version
#define kBDDYCAppBuildVersionRespKey    (@"app_build_version")      // app_build_version
#define kBDDYCBandageMD5RespKey           (@"md5")
#define kBDDYCBandageUrlRespKey           (@"url")
#define kBDDYCBandageBackupUrlsRespKey    (@"backup_urls")
#define kBDDYCBandageOfflineRespKey       (@"offline")                // turn_off
#define kBDDYCBandageWifiOnlyRespKey      (@"wifionly")
#define kBDDYCBandageArchRespKey          (@"arch")
#define kBDDYCBandageAsyncLoad            (@"async_load")
#define kBDDYCBandageChannel              (@"channel")
#define kBDDYCBandageAPPVersionList       (@"app_version_list")
#define kBDDYCBandageOSVersionRange       (@"os_version_range")


#pragma mark - other keys

#define kBDDYCModuleIDKey               (@"module_id")
#define kBDDYCNameRespKey               (@"name")
#define kBDDYCEncryptStatusKey          (@"encrypted")
#define kBDDYCEncryptPrivateKeyKey      (@"private_key")

#define kBDDYCPatchFilePathsKey         (@"file_paths")
#define kBDDYCPatchBundleNameKey        (@"bundle_name")
#define kBDDYCPatchBundlePathKey        (@"bundle_path")

#endif /* BDDYCModelKey_h */

