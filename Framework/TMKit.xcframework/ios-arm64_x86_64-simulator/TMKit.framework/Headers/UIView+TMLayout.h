//
//  UIView+TMLayout.h
//  TMExtension
//
//  Created by TMKit on 2021/7/28.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (TMLayout)

@property (nonatomic, assign) CGFloat tm_x;
@property (nonatomic, assign) CGFloat tm_y;

@property (nonatomic, assign) CGSize tm_size;
@property (nonatomic, assign) CGFloat tm_width;
@property (nonatomic, assign) CGFloat tm_height;

@property (nonatomic, assign) CGPoint tm_origin;
@property (nonatomic, assign) CGFloat tm_centerX;
@property (nonatomic, assign) CGFloat tm_centerY;

@property (nonatomic, assign) CGFloat tm_top;
@property (nonatomic, assign) CGFloat tm_left;
@property (nonatomic, assign) CGFloat tm_bottom;
@property (nonatomic, assign) CGFloat tm_right;

- (void)tm_centerToSuperView;

@end

NS_ASSUME_NONNULL_END
