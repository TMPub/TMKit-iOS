//
//  NSArray+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2022/7/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray<ObjectType> (TMExtension)

- (NSArray *)tm_sortedArrayByAlphabeticalWithKey:(NSString *)key;

/**
 将多个对象合并成一个数组，如果参数类型是数组则会将数组内的元素拆解出来加到 return 内（只会拆解一层，所以多维数组不处理）

 @param object 要合并的多个数组
 @return 合并完的结果
 */
+ (instancetype)tm_arrayWithObjects:(ObjectType)object, ...;

/**
 *  将多维数组打平成一维数组再遍历所有子元素
 */
- (void)tm_enumerateNestedArrayWithBlock:(void (NS_NOESCAPE^)(id obj, BOOL *stop))block;

/**
 *  将多维数组递归转换成 mutable 一维数组
 */
- (NSMutableArray *)tm_mutableCopyNestedArray;

/**
 *  过滤数组元素，将 block 返回 YES 的 item 重新组装成一个数组返回
 */
- (NSArray<ObjectType> *)tm_filterWithBlock:(BOOL (NS_NOESCAPE^)(ObjectType item))block;

/**
*  转换数组元素，将每个 item 都经过 block 转换成一遍 返回转换后的新数组
*/
- (NSArray *)tm_mapWithBlock:(id (NS_NOESCAPE^)(ObjectType item))block;

/**
*  带下标转换数组元素，将每个 item 都经过 block 转换成一遍 返回转换后的新数组
*/
- (NSArray *)tm_mapIndexWithBlock:(id (NS_NOESCAPE^)(ObjectType item, NSInteger index))block;

@end

NS_ASSUME_NONNULL_END
