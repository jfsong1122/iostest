//
//  VEInstall+CAID.h
//  VEInstall
//
//  Created by KiBen on 2021/9/15.
//

#import "VEInstall.h"

NS_ASSUME_NONNULL_BEGIN

@interface VEInstall (CAID)

@property (nonatomic, copy, nullable) NSString *caid;
@property (nonatomic, copy, nullable) NSString *prevCaid;

@end

NS_ASSUME_NONNULL_END
