//
//  UIView+TMExtension.h
//  TMExtension
//
//  Created by TMKit on 2021/8/5.
//

#import <UIKit/UIKit.h>

/// 基于 edge，space，计算适配屏幕 Item 的宽度
/// @param edge 左边距
/// @param lineSpacing item 平行间距
/// @param count item 数量
static inline CGFloat TMItemWidthFixScreen(CGFloat edge, CGFloat lineSpacing, CGFloat count) {
    if (count <= 0) {
        return 0;
    }
    return ([[UIScreen mainScreen] bounds].size.width - edge * count - lineSpacing * (count-1)) / count;
}

/// 基于 edge，space，计算穿过屏幕的 Item 的宽度
/// @param edge 左边距
/// @param lineSpacing item 平行间距
/// @param count item 数量
static inline CGFloat TMItemWidthCrossScreen(CGFloat edge, CGFloat lineSpacing, CGFloat count) {
    if (count <= 0) {
        return 0;
    }
    return ([[UIScreen mainScreen] bounds].size.width - edge - lineSpacing * floor(count)) / count;
}

NS_ASSUME_NONNULL_BEGIN

@interface UIView (TMExtension)

@property (nonatomic, assign) CGFloat tm_cornerRadius;

/// TODO: iOS10下有问题
- (void)tm_setCornerRadius:(CGFloat)cornerRadius atCorners:(UIRectCorner)corners;
/// 使用旧的方式生成圆角[使用新Api生成的带圆角UIView转UIImage有问题]
- (void)tm_legacySetCornerRadius:(CGFloat)radius atCorners:(UIRectCorner)corners;

/// 设置view上部分弧度方法 [解决当 radius*2 > self.height 时,弧度异常的问题]
/// @param radius 圆弧半径
- (void)tm_setTopCornerRadius:(CGFloat)radius;

/// 设置不带离屏渲染的背景色
- (void)tm_setNoneOffScreenRenderBgColor:(UIColor *)bgColor;
/// 设置不带离屏渲染的背景色 + 圆角
- (void)tm_setNoneOffScreenRenderBgColor:(UIColor *)bgColor cornerRadius:(CGFloat)cornerRadius;
/// 设置不带离屏渲染的背景色 + 指定圆角
- (void)tm_setNoneOffScreenRenderBgColor:(UIColor *)bgColor cornerRadius:(CGFloat)cornerRadius atCorners:(UIRectCorner)atCorners;

- (UIView *)tm_findSubViewOfSubClassName:(NSString *)className;

///查找子类
- (nullable UIView *)tm_findSubViewOfSubClass:(Class)class;

- (BOOL)tm_isActiveAndVisible;

/// 是否在屏幕中漏出
/// @param proportion 漏出比例
- (BOOL)tm_isVisibleInMainScreen:(CGFloat)proportion;

/// 是否在父控件中漏出
/// @param superView 父控件
/// @param superRect 指定父控件可显示区域大小
/// @param proportion 漏出比例
- (BOOL)tm_isVisibleInSuperView:(UIView *)superView superViewRect:(CGRect)superRect proportion:(CGFloat)proportion;

- (UIView *)tm_topSuperView;

- (nullable UIView *)tm_findSuperViewOfClass:(Class)classname;

- (UIViewController *)tm_currentViewController;

- (void)tm_animationShakeAgreementWithFeedBack:(BOOL)feedback;

@end

NS_ASSUME_NONNULL_END
