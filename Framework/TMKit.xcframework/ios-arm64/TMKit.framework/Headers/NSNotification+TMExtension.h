//
//  NSNotification+TMExtension.h
//  TMKit
//
//  Created by TMKit on 2022/7/26.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSNotification (TMExtension)

- (CGFloat)tm_keyBoardHeight;

@end

NS_ASSUME_NONNULL_END
