//
//  BDNativeVideoView.h
//  BDNativeWebComponent
//
//  Created by liuyunxuan on 2019/8/21.
//

#import <UIKit/UIKit.h>
//#import <TTVPlayerPod/TTVPlayer.h>
//#import <TTVPlayerPod/TTVPlayerKitHeader.h>
//#import <BDWebImage/BDImageView.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDNativeVideoView : UIView

@property (nonatomic, strong) AVPlayer *player;

@property (nonatomic, strong, readonly) UIImageView *posterImageView;

@property (nonatomic, assign) BOOL loop;
@property (nonatomic, assign) BOOL showControls;
@property (nonatomic, assign) BOOL autoPlay;

@property (nonatomic, assign) NSUInteger initialTime;

- (void)resetNotification;

@end

NS_ASSUME_NONNULL_END
