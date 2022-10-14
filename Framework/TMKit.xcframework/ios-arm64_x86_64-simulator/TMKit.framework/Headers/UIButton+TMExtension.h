//
//  UIButton+TMExtension.h
//  TMExtension
//
//  Created by TMKit on 2021/11/11.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TMButtonImageLayout) {
    TMButtonImageLayoutLeft           = 0,        //图片在左边
    TMButtonImageLayoutRight          = 1,        //图片在右边
    TMButtonImageLayoutTop            = 2,        //图片在上边
    TMButtonImageLayoutBottom         = 3         //图片在下边
};

typedef void(^TMImageCompletionBlock)(UIImage * _Nullable image);

@interface UIButton (TMExtension)

/// 修改按钮点击范围
- (void)tm_setEnlargeEdge:(UIEdgeInsets)edgeInsets;

- (void)tm_setSpacingBetweenTitleAndImage:(CGFloat)spacing;

/// button不同状态的背景颜色（代替图片）
- (void)tm_setBackgroundColor:(UIColor *)backgroundColor forState:(UIControlState)state;

/// 隐藏 UIButton 的 imageView （保留 titleLabel）
/// @param hidden 是否隐藏
- (void)tm_setImageViewHidden:(BOOL)hidden;

/// 对按钮内部的图片和文本重新进行布局
/// @param layout 重新布局的类型
/// @param spacing 内部图片和文本之间的间距
- (void)tm_setButtonImageLayout:(TMButtonImageLayout)layout spacing:(CGFloat)spacing;

@end

NS_ASSUME_NONNULL_END
