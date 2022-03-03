//
//  TestPageViewController.h
//  Pods
//
//  Created by Ada on 2021/10/12.
//

@import UIKit;
#import "VERemoteConfigManager.h"

@interface TestPageViewController : UIViewController<UITableViewDelegate,UITableViewDataSource,UIViewControllerTransitioningDelegate,UIGestureRecognizerDelegate,UITextFieldDelegate>

// 默认初始化，持有VERemoteConfigManager的默认单例
- (nonnull instancetype)init;

// 带参初始化，持有传入的VERemoteConfigManager实例
- (nonnull instancetype)initWithManager:(VERemoteConfigManager *_Nonnull)manager;

@end

