//
//  UIImage+TMExtension.h
//  TMExtensions
//
//  Created by TMKi on 2018/3/21.
//  Copyright © 2018年 TMKit. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (TMExtension)

/// 通过颜色创建 UIImage
+ (UIImage *)tm_imageWithColor:(UIColor *)color;

/// 合成一张具有外边距的图片
/// @param contentInset 外边距
/// @param color 外边距颜色
- (UIImage *)tm_imageWithInset:(UIEdgeInsets)contentInset color:(UIColor *)color;

/// 图片压缩 图片size固定 质量小于200kb
- (NSData *)tm_imageCompresss;

/// 图片尺寸修改
/// @param newSize 修改后的size
- (UIImage *)tm_scaleToSize:(CGSize)newSize;

/// 图片尺寸修改
/// @param scale 修改后的scale
- (UIImage *)tm_scaleTo:(CGFloat)scale;

/// 图片裁剪
/// @param rect 单位为像素px
- (UIImage *)tm_tailorToPxRect:(CGRect)rect;

/// 图片旋转方向修正
- (UIImage *)tm_fixOrientation;

/// 图片尺寸修改
/// @param sourceName 图片名称
/// @param scale 需要修改的比例 (0,1)
+ (UIImage *)tm_imageWithSourceName:(NSString *)sourceName scale:(CGFloat)scale;

/// 高斯模糊图片
/// @param aImage 原图片
+ (UIImage *)tm_blurEffectWithImage:(UIImage *)aImage;

/// 黑色高斯模糊图片
/// @param aImage 原图片
/// @param size 输出的图片尺寸(若不输入,则为图片的size)
+ (UIImage *)tm_darkBlurImageWithImage:(UIImage *)aImage size:(CGSize)size;

/// 截图
/// @param aView view
+ (UIImage *)tm_imageWithView:(__kindof UIView *)aView;

/// 添加水印
/// @param markText 水印文字
- (UIImage *)tm_addWatermark:(NSString *)markText;

@end
