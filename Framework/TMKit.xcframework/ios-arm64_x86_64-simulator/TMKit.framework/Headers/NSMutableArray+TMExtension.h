//
//  NSMutableArray+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2022/7/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableArray (TMExtension)

/// 移动对象 从一个位置到另一个位置
/// @param index  原位置
/// @param newIndex 目标位置
- (void)tm_moveObjectAtIndex:(NSUInteger)index toIndex:(NSUInteger)newIndex;

- (void)tm_sortAlphabeticalWithKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
