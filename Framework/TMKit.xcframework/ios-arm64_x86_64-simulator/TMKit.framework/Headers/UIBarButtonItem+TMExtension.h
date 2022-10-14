//
//  UIBarButtonItem+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2022/8/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIBarButtonItem (TMExtension)

/// 基于 UIButton 初始化 UIBarButtonItem
- (instancetype)initWithButtonImageName:(NSString *)imageName size:(CGSize)size target:(nullable id)target action:(SEL)action;

@end

NS_ASSUME_NONNULL_END
