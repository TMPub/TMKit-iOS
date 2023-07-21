//
//  UIColor+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2021/8/17.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (TMExtension)

+ (nullable UIColor *)tm_colorWithRGBString:(NSString *)RGBString;

+ (nullable UIColor *)tm_colorWithRGBString:(NSString *)RGBString alpha:(CGFloat)alpha;

/// "#0D0D0D" -> UIColor
/// @param hexString "#0D0D0D"
+ (nullable UIColor *)tm_colorWithHexString:(NSString *)hexString;

/// "#0D0D0D" -> UIColor
/// @param hexString "#0D0D0D"
/// @param alpha 透明度
+ (nullable UIColor *)tm_colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;

/// UIColor -> HexString
- (NSString *)tm_transformToNoAlphaHexString;

+ (CGFloat)tm_hueValueFromColor:(UIColor *)color;

// 类似色
+ (nullable UIColor *)tm_similarColorFromColor:(UIColor *)aColor;

// 对比色
+ (nullable UIColor *)tm_contrastingColorFromColor:(UIColor *)aColor;

- (BOOL)tm_isLighterColor;

@end

NS_ASSUME_NONNULL_END
