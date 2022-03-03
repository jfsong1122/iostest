//
//  BDXBridgeServiceDefinitions.h
//  BDXBridgeKit
//
//  Created by Lizhen Hu on 2021/3/16.
//

#import <Foundation/Foundation.h>
#import "BDXBridgeContainerProtocol.h"
#import "BDXBridgeMethod.h"
#import "BDXBridgeModel.h"



NS_ASSUME_NONNULL_BEGIN

@protocol BDXBridgeContainerProtocol;

#pragma mark - Info Service

@protocol BDXBridgeInfoServiceProtocol <NSObject>

- (nullable NSString *)channel;
- (nullable NSString *)language;
- (nullable NSString *)appTheme;
- (BOOL)isTeenMode;
- (nullable id)settingForKeyPath:(NSString *)keyPath;

@end

#pragma mark - Account Service

@class BDXBridgeLoginMethodParamModel;
@class BDXBridgeLogoutMethodParamModel;

@protocol BDXBridgeAccountServiceProtocol <NSObject>

- (BOOL)hasLoggedIn;
- (nullable NSString *)userID;
- (nullable NSString *)secureUserID;
- (nullable NSString *)uniqueID;
- (nullable NSString *)nickname;
- (nullable NSString *)avatarURLString;
- (nullable NSString *)boundPhone;

- (void)loginWithParamModel:(BDXBridgeLoginMethodParamModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;
- (void)logoutWithParamModel:(BDXBridgeLogoutMethodParamModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;

@end

# pragma mark - Network Service

@class TTHttpResponse;
@protocol TTHTTPRequestSerializerProtocol, TTJSONResponseSerializerProtocol;

typedef void(^BDXBridgeRequestCompletionHandler)(TTHttpResponse * _Nullable response, id _Nullable object, NSError * _Nullable error);

@interface BDXBridgeRequestParam : NSObject

@property (nonatomic, copy) NSString *urlString;
@property (nonatomic, copy) NSString *httpMethod;
@property (nonatomic, copy, nullable) NSDictionary *headers;
@property (nonatomic, copy, nullable) NSDictionary *params;
@property (nonatomic, assign) BOOL needCommonParams;
@property (nonatomic, strong, nullable) Class<TTHTTPRequestSerializerProtocol> requestSerializer;
@property (nonatomic, strong, nullable) Class<TTJSONResponseSerializerProtocol> responseSerializer;

@end

@protocol BDXBridgeNetworkServiceProtocol <NSObject>

- (nullable NSDictionary *)apiParams;

@optional
- (void)requestWithParam:(BDXBridgeRequestParam *)param completionHandler:(BDXBridgeRequestCompletionHandler)completionHandler;

@end

#pragma mark - Route Service

@class BDXBridgeOpenMethodParamModel;

@protocol BDXBridgeRouteServiceProtocol <NSObject>

- (void)openSchemaWithParamModel:(BDXBridgeOpenMethodParamModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;

@optional
- (void)closeContainer:(id<BDXBridgeContainerProtocol>)container animated:(BOOL)animated completionHandler:(nullable BDXBridgeMethodCompletionHandler)completionHandler;

@end

#pragma mark - UI Service

@class BDXBridgeShowActionSheetMethodParamModel;

@protocol BDXBridgeUIServiceProtocol <NSObject>

- (void)showLoadingInContainer:(id<BDXBridgeContainerProtocol>)container withParamModel:(BDXBridgeModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;
- (void)hideLoadingInContainer:(id<BDXBridgeContainerProtocol>)container withParamModel:(BDXBridgeModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;
- (void)showModalWithParamModel:(BDXBridgeModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;
- (void)showToastWithParamModel:(BDXBridgeModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;
- (void)showActionSheetWithParamModel:(BDXBridgeShowActionSheetMethodParamModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;

@end

#pragma mark - Media Service

@class BDXBridgeChooseMediaMethodParamModel, BDXBridgeChooseMediaMethodResultModel;

typedef void(^BDXBridgeChooseMediaCompletionHandler)(BDXBridgeChooseMediaMethodResultModel * _Nullable resultModel, BDXBridgeStatus * _Nullable status);
typedef void(^BDXBridgeUploadImageCompletionHandler)(id _Nullable object, NSError * _Nullable error);
typedef void(^BDXBridgeDownloadFileCompletionHandler)(TTHttpResponse * _Nullable response, NSURL * _Nullable fileURL, NSError * _Nullable error);

@protocol BDXBridgeChooseMediaPicker <NSObject>

@required
- (BOOL)supportedWithParamModel:(BDXBridgeChooseMediaMethodParamModel *)paramModel;

- (UIViewController * _Nullable)mediaPickerWithParamModel:(BDXBridgeChooseMediaMethodParamModel *)paramModel completionHandler:(BDXBridgeChooseMediaCompletionHandler)completionHandler;

@end

@interface BDXBridgeUploadImageParam : NSObject

@property (nonatomic, copy) NSString *urlString;
@property (nonatomic, copy, nullable) NSDictionary *headers;
@property (nonatomic, copy, nullable) NSDictionary *params;
@property (nonatomic, copy) NSString *mimeType;
@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, strong) NSData *fileData;

@end

@interface BDXBridgeDownloadFileParam : NSObject

@property (nonatomic, copy) NSString *urlString;
@property (nonatomic, copy, nullable) NSDictionary *headers;
@property (nonatomic, copy, nullable) NSDictionary *params;
@property (nonatomic, copy) NSString *filePath;

@end

@protocol BDXBridgeMediaServiceProtocol <NSObject>

@optional
- (nullable id<BDXBridgeChooseMediaPicker>)mediaPicker;
- (UIColor *)barTintColor;
- (UIColor *)tintColor;

- (void)uploadImageWithParam:(BDXBridgeUploadImageParam *)param completionHandler:(BDXBridgeUploadImageCompletionHandler)completionHandler;
- (void)downloadFileWithParam:(BDXBridgeDownloadFileParam *)param completionHandler:(BDXBridgeDownloadFileCompletionHandler)completionHandler;

@end

#pragma mark - Log Service

@class BDXBridgeReportADLogMethodParamModel;
@class BDXBridgeReportAppLogMethodParamModel;
@class BDXBridgeReportMonitorLogMethodParamModel;

@protocol BDXBridgeLogServiceProtocol <NSObject>

- (void)reportADLogWithParamModel:(BDXBridgeReportADLogMethodParamModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;
- (void)reportAppLogWithParamModel:(BDXBridgeReportAppLogMethodParamModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;
- (void)reportMonitorLogWithParamModel:(BDXBridgeReportMonitorLogMethodParamModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;

@end

#pragma mark - Open Service

@class BDXBridgeScanCodeMethodParamModel;

@protocol BDXBridgeOpenServiceProtocol <NSObject>

- (void)scanCodeWithParamModel:(BDXBridgeScanCodeMethodParamModel *)paramModel completionHandler:(BDXBridgeMethodCompletionHandler)completionHandler;

@end

NS_ASSUME_NONNULL_END
