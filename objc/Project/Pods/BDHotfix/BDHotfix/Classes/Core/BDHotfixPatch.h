//
//  BDHotfixPatch.h
//  BDDynamically
//
//  Created by zuopengliu on 7/3/2018.
//

#import <Foundation/Foundation.h>
#import "BDHotfixPatchModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDHotfixPatch : NSObject

@property (nonatomic) BDHotfixPatchModel *model;

/// 热修包文件的路径（绝对路径）。对应用户上传的热修包中的文件。
@property (nonatomic, copy, readonly) NSArray <NSString *> *files;

- (instancetype)initWithModel:(BDHotfixPatchModel *)model;

@end


NS_ASSUME_NONNULL_END
