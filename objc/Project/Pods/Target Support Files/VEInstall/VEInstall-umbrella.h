#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "VEInstall+CAID.h"
#import "VEInstallExtraParams.h"
#import "VEInstall.h"
#import "VEInstallASAProvider.h"
#import "VEInstallConfig.h"
#import "VEInstallDataEncryptProvider.h"
#import "VEInstallManager.h"
#import "VEInstallNotificationConstants.h"
#import "VEInstallRegisterResponse.h"
#import "VEInstallURLService.h"
#import "VEInstallVersion.h"
#import "VEInstallIDFA.h"
#import "VEInstallIDFAManager.h"
#import "VEInstallStartUpTask.h"
#import "VEInstallURLChina.h"

FOUNDATION_EXPORT double VEInstallVersionNumber;
FOUNDATION_EXPORT const unsigned char VEInstallVersionString[];

