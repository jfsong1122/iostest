//
//  NSString+IESFalconConvenience.h
//  Pods
//
//  Created by 陈煜钏 on 2019/9/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (IESFalconConvenience)

- (nullable NSString *)ies_removeFragment;

- (nullable NSString *)ies_removeQuery;

- (BOOL)ies_comboAllowExtention;

// It follows the same pattern for enabling the concatenation. It uses two ?, like this: http://example.com/??style1.css,style2.css,foo/style3.css
// ies_comboPaths result @[http://example.com/style1.css , http://example.com/style2.css , http://example.com/style3.css]
- (NSArray <NSString *> *)ies_comboPaths;

- (NSString *)ies_stringByTrimmingQueryString;

- (NSString *)ies_prefixMatchedByRegex:(NSString *)pattern;

@end

NS_ASSUME_NONNULL_END
