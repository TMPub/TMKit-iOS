//
//  UINavigationController+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2022/7/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TMViewControllerEquality <NSObject>

- (BOOL)isEqualToViewController:(UIViewController *)otherViewController;

@end

typedef NS_ENUM(NSUInteger, TMPushOptions) {
    TMPushOptionsNone                = 1 <<  0,
    TMPushOptionsRemoveDuplicates    = 1 <<  1,
    TMPushOptionsRemoveEquals        = 1 <<  2,
};

@interface UINavigationController (TMExtension)

#pragma mark - Push
/// Push展示一个ViewController实例
/// @param viewController 要展示的ViewController实例
/// @param animated 是否有动画
- (void)tm_pushViewController:(__kindof UIViewController *)viewController animated:(BOOL)animated;

/// Push展示一个ViewController实例
/// @param viewController ViewController实例
/// @param animated 是否有动画
/// @param pushOptions 跳转选项
- (void)tm_pushViewController:(__kindof UIViewController *)viewController animated:(BOOL)animated pushOptions:(TMPushOptions)pushOptions;

#pragma mark - Pop
/// Pop到根视图
/// @param animated 是否有动画
- (nullable NSArray<__kindof UIViewController *> *)tm_popToRootViewControllerAnimated:(BOOL)animated;

/// Pop到一个UIViewController实例
/// @param viewController viewController实例
/// @param animated 是否有动画
- (nullable NSArray<__kindof UIViewController *> *)tm_popToViewController:(UIViewController *)viewController animated:(BOOL)animated;

/// Pop到最近的class类型的ViewController
/// @param viewControllerClass 限定ViewController类型
/// @param animated 是否有动画
- (BOOL)tm_popToLastViewControllerOfClass:(Class)viewControllerClass animated:(BOOL)animated;

/// Pop当前视图控制器
/// @param animated 是否有动画
- (void)tm_popViewControllerAnimated:(BOOL)animated;

#pragma mark - Remove
/// 移除视图控制器
/// @param viewController 要移除的视图控制器
- (void)tm_removeViewController:(__kindof UIViewController *)viewController;

/// 移除 viewControllers 上某一个 Class，原本在   - (void)removeViewControllerClass:(Class)viewControllerClass fromNavigationController:(UINavigationController *)navController
/// @param viewControllerClass 需要移除的 Class
- (void)tm_removeViewControllerClass:(Class)viewControllerClass;

/// 是否正在转场动画中 (⚠️)
@property (nonatomic, readwrite, getter = isViewTransitionInProgress) BOOL viewTransitionInProgress;

@end

NS_ASSUME_NONNULL_END
