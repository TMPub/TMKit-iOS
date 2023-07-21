//
//  NSData+TMAES.h
//  TMExtensions
//
//  Created by TMKit on 2021/6/16.
//  Copyright © 2021 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (TMAES)

/// AES128/CBC/PKCS7Padding 加密
/// @param key 密钥
/// @param iv 向量
- (NSData *)tm_encryptAES128CBCUsingKey:(NSString *)key iv:(NSString *)iv;

/// AES128/CBC/PKCS7Padding 解密
/// @param key 密钥
/// @param iv 向量
- (NSData *)tm_decryptAES128CBCUsingKey:(NSString *)key iv:(NSString *)iv;

/// AES128/ECB/PKCS7Padding 加密
/// @param key 密钥
- (NSData *)tm_encryptAES128ECBUsingKey:(NSString *)key;

/// AES128/ECB/PKCS7Padding 解密
/// @param key 密钥
- (NSData *)tm_decryptAES128ECBUsingKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
