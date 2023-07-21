//
//  NSURL+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2020/8/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURL (TMExtension)

/// 若使用原urlString 转 URL失败，则尝试对URLString 做一次‘encode’，再转url
+ (nullable NSURL *)tm_safeURLWithString:(NSString *)urlString;

/// scheme 是否是 http 或 https 的 URL
- (BOOL)tm_isBrowserURL;

/// 获取第一个 path
- (nullable NSString *)tm_firstPathComponent;

/// 在query中，有效的参数组成的NSDictionary
- (NSDictionary<NSString *, NSString *> *)tm_queryItemsDictionary;

/// 在query中，有效的参数组成的NSDictionary,已做Decode
- (NSDictionary<NSString *, NSString *> *)tm_queryItemsDecodeDictionary;

/// NSURL 添加queryItems
/// @param queryItems queryItems
- (NSURL *)tm_appendWithQueryItems:(NSArray<NSURLQueryItem *> *)queryItems;

/// NSString 添加querys
/// @param queryItems queryItems
+ (nullable NSURL *)tm_urlStringWith:(NSString *)urlString appendWithQueryItems:(NSArray<NSURLQueryItem *> *)queryItems;

@end

NS_ASSUME_NONNULL_END
