//
//  RALSecML.h
//  RangersAppLog
//
//  Created by 朱元清 on 2021/4/27.
//

#import <Foundation/Foundation.h>
#if __has_include(<VolMetaSecML/MSManager.h>)
  #import <VolMetaSecML/MSManager.h>
#else
  #import "local_MSManager.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface RALSecML : NSObject

/* 获取安全SDK实例
 */
+ (MSManagerML *)getMSManager;

/*! SDK在初始化时自动调用. 开发者一般不需要手动调用
 初始化安全反作弊SDK
 */
+ (void)bootMSSecML;

@end

NS_ASSUME_NONNULL_END
