//
//  BDWebViewCommon.h
//  ByteWebView
//
//  Created by Lin Yong on 2019/3/21.
//

#import <Foundation/Foundation.h>
#import <BDWebKitToB/BDWebKitDefine.h>

@interface BDWebViewWKConfigurationSetting : NSObject

/*
 @discussion Default is NO
 */
@property (nonatomic, assign) BOOL allowsInlineMediaPlayBack;

/*
 @discussion Default is NO
 */
@property (nonatomic, assign) BOOL mediaPlaybackRequiresUserAction;

/*
 @discussion Default is NO
 */
@property (nonatomic, assign) BOOL mediaPlaybackAllowsAirPlay;

/*
 @discussion Defalt is NO
 */
@property (nonatomic, assign) BOOL suppressesIncrementalRendering;
/*
 @discussion Default is NO
 */
@property (nonatomic, assign) BOOL forbiddenAddUserScriptByBDWebView;

/*
@discussion Default is NO
*/
@property (nonatomic, assign) BOOL ignoresViewportScaleLimits;

@end

