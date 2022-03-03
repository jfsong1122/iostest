//
//  BDXBridgeOpenService.h
//  BDXBridgeKit
//
//  Created by Bomao Huang on 2020/4/19.
//

#import "BDXBridgeServiceDefinitions.h"
#import <QRCodeReaderViewController/QRCodeReaderDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDXBridgeOpenService : NSObject<BDXBridgeOpenServiceProtocol, QRCodeReaderDelegate>

@end

NS_ASSUME_NONNULL_END
