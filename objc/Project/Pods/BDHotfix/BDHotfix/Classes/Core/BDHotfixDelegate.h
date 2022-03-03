//
//  BDHotfixDelegate.h
//  BDHotfix
//
//  Created by 朱元清 on 2021/2/10.
//
#import "BDHotfixPatch.h"
#import "BDHotfixPatchModel.h"

#ifndef BDHotfixDelegate_h
#define BDHotfixDelegate_h


@protocol BDHotfixDelegate <NSObject>
@required

/// @return 是否允许拉取热修包列表。可以返回NO以阻止SDK拉取热修包列表。
- (BOOL)BDHotfixWillStartFetchingPatchList;

/// 拉取热修包列表完成的回调。
- (void)BDHotfixDidFinishFetchingPatchList:(NSArray <BDHotfixPatchModel *> *)patchList withError:(NSError *)error;

/// @return 是否允许下载热修包。可以返回NO以阻止SDK下载此热修包。
- (BOOL)BDHotfixWillStartDownloadingPatch:(BDHotfixPatchModel *)patchModel;

/// 下载热修包完成的回调。
- (void)BDHotfixDidFinishDownloadingPatch:(BDHotfixPatch *)patch withError:(NSError *)error;

@end

#endif
