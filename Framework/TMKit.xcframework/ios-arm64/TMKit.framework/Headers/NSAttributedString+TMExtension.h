//
//  NSAttributedString+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2022/7/12.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSAttributedString (TMExtension)

#pragma mark - 文本高度计算
- (CGSize)tm_boundingSizeWithWidth:(CGFloat)width;

+ (NSAttributedString *)tm_attributedStringWithHTML:(NSString *)html;

@end

NS_ASSUME_NONNULL_END
