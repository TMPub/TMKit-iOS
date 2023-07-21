//
//  UIViewController+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2022/7/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (TMExtension)

+ (UIViewController *)tm_topViewController;

- (void)tm_popToTabbarViewController:(BOOL)animated;

- (void)tm_fullPresentViewControllerAfterDismiss:(__kindof UIViewController *)viewController;

- (void)tm_fullPresentViewController:(__kindof UIViewController *)viewController;

- (void)tm_fullPresentViewController:(__kindof UIViewController *)viewController animated:(BOOL)animated completion:(void (^ __nullable)(void))completion;

- (void)tm_closeViewControllerAnimated:(BOOL)animated;

- (void)tm_popSelf;

/// 找到 presentingViewController 的出发地
- (UIViewController *)tm_rootPresentingViewController;

// https://stackoverflow.com/questions/13118529/wrong-presentingviewcontroller A present B，A 不一定是 B的系统的 presentingviewcontroller，因此使用 truePresentingViewController（前提是使用了 tm_fullPresentViewController），已经验证，不需要 weak
@property (nonatomic, strong) UIViewController *tm_presentingViewController;

@end

NS_ASSUME_NONNULL_END
