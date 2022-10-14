//
//  NSString+TMCheck.h
//  TMExtension
//
//  Created by TMKit on 2018/6/29.
//  Copyright © 2018年 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (TMCheck)

#pragma mark - 判断

/// 移除空格和换行后，判断字符串是否为空
- (BOOL)tm_isEmptyStringByTrimingSpace;

/// 是否是链接string
- (BOOL)tm_isLinkString;

/// 是否只包含数字
- (BOOL)tm_isAllDigits;

/// 是否为浮点型
- (BOOL)tm_isStringFloat;

/// 判断文本是否包含表情
- (BOOL)tm_isContainsEmoji;

/// 手机号码校验
- (BOOL)tm_isPhoneNumber;

/// 邮箱校验
- (BOOL)tm_isEmailExpression;

- (BOOL)tm_isIPAddress;

/// 字符串不为空
/// @param string 字符串
+ (BOOL)tm_isStringAvailable:(NSString *)string;

@end


