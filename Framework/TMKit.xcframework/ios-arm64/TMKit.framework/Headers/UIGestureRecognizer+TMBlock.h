//
//  UIGestureRecognizer+TMBlock.h
//  TMExtensions
//
//  Created by TMKit on 2023/1/12.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^TMGestureBlock)(id sender);

@interface UIGestureRecognizer (TMBlock)

- (instancetype)initWithActionBlock:(TMGestureBlock)block;

@end

NS_ASSUME_NONNULL_END
