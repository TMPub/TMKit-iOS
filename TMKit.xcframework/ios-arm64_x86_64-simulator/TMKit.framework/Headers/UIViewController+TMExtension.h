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

- (void)tm_fullPresentViewController:(__kindof UIViewController *)viewController;

- (void)tm_fullPresentViewController:(__kindof UIViewController *)viewController animated:(BOOL)animated completion:(void (^ __nullable)(void))completion;

- (void)tm_closeViewControllerAnimated:(BOOL)animated;

- (void)tm_popSelf;

@end

NS_ASSUME_NONNULL_END
