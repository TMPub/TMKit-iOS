//
//  TMCircleProgressView.h
//  TMUI
//
//  Created by TMKit on 2022/9/9.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMCircleProgressView : UIView

@property (nonatomic, assign) double progress;

@property (nonatomic, strong, nullable) UIColor *trackTintColor;

@property (nonatomic, strong, nullable) UIColor *progressTintColor;

@property (nonatomic, assign) CGFloat lineWidth;

@end

NS_ASSUME_NONNULL_END
