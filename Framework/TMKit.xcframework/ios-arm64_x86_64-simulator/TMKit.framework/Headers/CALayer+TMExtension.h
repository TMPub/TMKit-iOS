//
//  CALayer+TMExtension.h
//  TMExtensions
//
//  Created by TMKi on 2022/3/29.
//  Copyright © 2022 TMKit. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CALayer (TMExtension)

/// 渐变色Layer
/// @param vP0 向量初始点 eg: (0,0)->(0,1):垂直下方向 ; (0,0)->(1,0):水平右方向
/// @param vP1 向量结束点
/// @param colors 颜色数组 eg: [clear,green,black]:按向量方向,一次透明->绿->黑 渐变
/// @param frame layer frame
+ (CALayer *)tm_gradientColorLayerWithVectorBeginPoint:(CGPoint)vP0
                                        vectorEndPoint:(CGPoint)vP1
                                                colors:(NSArray <UIColor *>*)colors
                                                 frame:(CGRect)frame;

/// 垂直向下渐变Layer 透明->某颜色
/// @param color 颜色
/// @param frame layer frame
+ (CALayer *)tm_gradientColorLayerVerticalFromClearTo:(UIColor *)color
                                                frame:(CGRect)frame;

@end

NS_ASSUME_NONNULL_END
