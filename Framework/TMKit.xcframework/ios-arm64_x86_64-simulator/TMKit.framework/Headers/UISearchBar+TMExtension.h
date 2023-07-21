//
//  UISearchBar+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2019/9/26.
//  Copyright © 2019 TMKit. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UISearchBar (TMExtension)

- (nullable UITextField *)tm_textField;

- (nullable UIButton *)tm_cancelButton;

- (nullable UIView *)tm_backgroundView;

@end

NS_ASSUME_NONNULL_END
