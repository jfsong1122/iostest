//
//  IESGurdKit+InternalPackages.h
//  BDAssert
//
//  Created by 陈煜钏 on 2020/9/16.
//

#import "IESGeckoKit.h"

NS_ASSUME_NONNULL_BEGIN

/// 内置包资源文件必须放在某个bundle下，如多个bundle中都包含某个channel所对应的包，则只会应用首次对该channel所解压的包，如想激活其他bundle中该channel的包，需先调用clearInternalPackageForChannel

@interface IESGurdKit (InternalPackages)

// 激活主bundle中传入channels数组的所对应的内置离线包
+ (void)activeAllInternalPackagesInMainBundleWithChannels:(NSArray<NSString *> *)channels completion:(void (^)(BOOL succeed))completion;

// 激活传入bundle中对应channels数组中所有的内置离线包
+ (void)activeAllInternalPackagesWithBundleName:(NSString * _Nullable)bundleName
                                       channels:(NSArray<NSString *> *)channels
                                     completion:(void (^)(BOOL succeed))completion;

// 清除传入channel所对应的所有内置包资源
+ (void)clearInternalPackageForChannel:(NSString *)channel;

// 离线包根目录
+ (NSString *)internalRootDirectory;

// 返回对应channel和相对路径(path)所在的目录，如不存在该资源，则返回nil
+ (NSString *)internalPackageDirectoryForChannel:(NSString *)channel path:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
