//
//  BDWebView+BDServerTrust.h
//  ByteWebView
//
//  Created by Nami on 2019/3/6.
//

#import "BDWebView.h"
#import <BDWebKitToB/WKWebView+BDWebServerTrust.h>
NS_ASSUME_NONNULL_BEGIN

@interface BDWebView (BDServerTrust)

@property (nonatomic, weak) id<BDWebServerTrustDelegate> serverTrustDelegate;

@property (nonatomic, assign) BOOL skipSSLError;

// enable dispatch handler to async queue ,default is NO, which means it's forced to handle ssl chanllenge on main queue.
@property (nonatomic, assign) BOOL serverTrustAsync;

@end

NS_ASSUME_NONNULL_END
