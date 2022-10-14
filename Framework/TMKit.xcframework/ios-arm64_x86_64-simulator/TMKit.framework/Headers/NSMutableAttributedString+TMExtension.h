//
//  NSMutableAttributedString+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2022/7/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableAttributedString (TMExtension)

- (void)tm_trimmingFirstCharactersInset:(NSCharacterSet *)characterSet;

- (void)tm_trimmingLastCharactersInset:(NSCharacterSet *)characterSet;

@end

NS_ASSUME_NONNULL_END
