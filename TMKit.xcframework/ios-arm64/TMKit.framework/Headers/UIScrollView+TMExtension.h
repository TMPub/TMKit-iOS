//
//  UIScrollView+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2022/7/28.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIScrollView (TMExtension)

/// contentInset 顶部
@property (nonatomic, assign) CGFloat tm_contentInsetTop;

/// contentInset 左
@property (nonatomic, assign) CGFloat tm_contentInsetLeft;

/// contentInset 底部
@property (nonatomic, assign) CGFloat tm_contentInsetBottom;

/// contentInset 右
@property (nonatomic, assign) CGFloat tm_contentInsetRight;

/**
 * 判断当前的scrollView内容是否足够滚动
 * @warning 避免与<i>scrollEnabled</i>混淆
 */
- (BOOL)tm_canScroll;

@end

NS_ASSUME_NONNULL_END
