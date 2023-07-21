//
//  NSString+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2018/6/29.
//  Copyright © 2018年 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TMStringProtocol <NSObject>

/**
 *  按照中文 2 个字符、英文 1 个字符的方式来计算文本长度
 */
@property(readonly) NSUInteger tm_lengthWhenCountingNonASCIICharacterAsTwo;

/**
 *  将字符串从指定的 index 开始裁剪到结尾，裁剪时会避免将 emoji 等 "character sequences" 拆散（一个 emoji 表情占用1-4个长度的字符）。
 *
 *  例如对于字符串“😊😞”，它的长度为4，若调用 [string tm_substringAvoidBreakingUpCharacterSequencesFromIndex:1]，将返回“😊😞”。
 *  若调用系统的 [string substringFromIndex:1]，将返回“?😞”。（?表示乱码，因为第一个 emoji 表情被从中间裁开了）。
 *
 *  @param index 要从哪个 index 开始裁剪文字，如果 countingNonASCIICharacterAsTwo 为 YES，则 index 也要按 YES 的方式来算
 *  @param lessValue 要按小的长度取，还是按大的长度取
 *  @param countingNonASCIICharacterAsTwo 是否按照 英文 1 个字符长度、中文 2 个字符长度的方式来裁剪
 *  @return 裁剪完的字符
 */
- (nullable instancetype)tm_substringAvoidBreakingUpCharacterSequencesFromIndex:(NSUInteger)index lessValue:(BOOL)lessValue countingNonASCIICharacterAsTwo:(BOOL)countingNonASCIICharacterAsTwo;

/**
 *  相当于 `tm_substringAvoidBreakingUpCharacterSequencesFromIndex: lessValue:YES` countingNonASCIICharacterAsTwo:NO
 *  @see tm_substringAvoidBreakingUpCharacterSequencesFromIndex:lessValue:countingNonASCIICharacterAsTwo:
 */
- (nullable instancetype)tm_substringAvoidBreakingUpCharacterSequencesFromIndex:(NSUInteger)index;

/**
 *  将字符串从开头裁剪到指定的 index，裁剪时会避免将 emoji 等 "character sequences" 拆散（一个 emoji 表情占用1-4个长度的字符）。
 *
 *  例如对于字符串“😊😞”，它的长度为4，若调用 [string tm_substringAvoidBreakingUpCharacterSequencesToIndex:1 lessValue:NO countingNonASCIICharacterAsTwo:NO]，将返回“😊”。
 *  若调用系统的 [string substringToIndex:1]，将返回“?”。（?表示乱码，因为第一个 emoji 表情被从中间裁开了）。
 *
 *  @param index 要裁剪到哪个 index 为止（不包含该 index，策略与系统的 substringToIndex: 一致），如果 countingNonASCIICharacterAsTwo 为 YES，则 index 也要按 YES 的方式来算
 *  @param lessValue 裁剪时若遇到“character sequences”，是向下取整还是向上取整。
 *  @param countingNonASCIICharacterAsTwo 是否按照 英文 1 个字符长度、中文 2 个字符长度的方式来裁剪
 *  @return 裁剪完的字符
 */
- (nullable instancetype)tm_substringAvoidBreakingUpCharacterSequencesToIndex:(NSUInteger)index lessValue:(BOOL)lessValue countingNonASCIICharacterAsTwo:(BOOL)countingNonASCIICharacterAsTwo;

/**
 *  相当于 `tm_substringAvoidBreakingUpCharacterSequencesToIndex:lessValue:YES` countingNonASCIICharacterAsTwo:NO
 *  @see tm_substringAvoidBreakingUpCharacterSequencesToIndex:lessValue:countingNonASCIICharacterAsTwo:
 */
- (nullable instancetype)tm_substringAvoidBreakingUpCharacterSequencesToIndex:(NSUInteger)index;

/**
 *  将字符串里指定 range 的子字符串裁剪出来，会避免将 emoji 等 "character sequences" 拆散（一个 emoji 表情占用1-4个长度的字符）。
 *
 *  例如对于字符串“😊😞”，它的长度为4，在 lessValue 模式下，裁剪 (0, 1) 得到的是空字符串，裁剪 (0, 2) 得到的是“😊”。
 *  在非 lessValue 模式下，裁剪 (0, 1) 或 (0, 2)，得到的都是“😊”。
 *
 *  @param range 要裁剪的文字位置
 *  @param lessValue 裁剪时若遇到“character sequences”，是向下取整还是向上取整（系统的 rangeOfComposedCharacterSequencesForRange: 会尽量把给定 range 里包含的所有 character sequences 都包含在内，也即 lessValue = NO）。
 *  @param countingNonASCIICharacterAsTwo 是否按照 英文 1 个字符长度、中文 2 个字符长度的方式来裁剪
 *  @return 裁剪完的字符
 */
- (nullable instancetype)tm_substringAvoidBreakingUpCharacterSequencesWithRange:(NSRange)range lessValue:(BOOL)lessValue countingNonASCIICharacterAsTwo:(BOOL)countingNonASCIICharacterAsTwo;

/**
 *  相当于 `tm_substringAvoidBreakingUpCharacterSequencesWithRange:lessValue:YES` countingNonASCIICharacterAsTwo:NO
 *  @see tm_substringAvoidBreakingUpCharacterSequencesWithRange:lessValue:countingNonASCIICharacterAsTwo:
 */
- (nullable instancetype)tm_substringAvoidBreakingUpCharacterSequencesWithRange:(NSRange)range;

/**
 *  移除指定位置的字符，可兼容emoji表情的情况（一个emoji表情占1-4个length）
 *  @param index 要删除的位置
 */
- (nullable instancetype)tm_stringByRemoveCharacterAtIndex:(NSUInteger)index;

/**
 *  移除最后一个字符，可兼容emoji表情的情况（一个emoji表情占1-4个length）
 *  @see `tm_stringByRemoveCharacterAtIndex:`
 */
- (nullable instancetype)tm_stringByRemoveLastCharacter;

/// 获取指定宽度内的字符串
/// @param width 指定的宽度
/// @param font 字体
/// @param breakByChar 是否以字符为单位截断
- (NSRange)tm_rangeWithWidth:(CGFloat)width font:(UIFont *)font breakByChar:(BOOL)breakByChar;

/// 获取字符串在指定宽度内显示的行数
/// @param width 指定宽度
/// @param font 字体
- (NSInteger)tm_lineCountWithWidth:(CGFloat)width Font:(UIFont *)font;

/// 字符串在给定宽度显示的每一行
/// @param width 给定宽度
/// @param font 字体
- (NSArray *)tm_multilineStringsWithWidth:(CGFloat)width font:(UIFont *)font;

/// 字符串在给定宽度显示的每一行
/// @param width 给定的宽度
/// @param font 字体
/// @param breakLine 最后一行
/// @param breakByChar 是否以字符为单位换行
- (NSArray *)tm_multilineStringsWithWidth:(CGFloat)width font:(UIFont *)font breakLineIndex:(NSInteger)breakLine breakByChar:(BOOL)breakByChar;

@end

@interface NSString (TMExtension) <TMStringProtocol>

#pragma mark - 移除

/// 去除空格
- (NSString *)tm_trimmingWhitespace;

/// 移除空格和换行
- (NSString *)tm_trimingWhitespaceAndNewline;

/// 移除换行
- (NSString *)tm_trimingNewline;

/// 换行替换为空格
- (NSString *)tm_replaceNewlineWithSpace;

/// 只保留数字
- (NSString *)tm_trimmingSpecialCharactersOnlyNumberLeft;

/// 删除左边的零
- (NSString *)tm_trimmingLeftZeros;

#pragma mark - 解析

- (NSMutableArray *)tm_getArrayByMatchStringToRegexString:(NSString *)regexStr;

- (nullable NSDictionary *)tm_toDictionary;

- (nullable NSArray *)tm_toArray;

#pragma mark - 文本高度计算

- (CGSize)tm_sizeWithFont:(UIFont *)font;

- (CGSize)tm_boundingSizeWithWidth:(CGFloat)width font:(UIFont *)font;

- (CGSize)tm_boundingSizeWithSize:(CGSize)size font:(UIFont *)font;

- (CGSize)tm_boundingSizeWithWidth:(CGFloat)width attributes:(NSDictionary *)attributes;

#pragma mark - 其他

/// 文本相似度比较(莱文斯坦算法),返回值范围:[0-100]
- (float)tm_similarityPercentByCompareToText:(NSString *)targetText;

/// 计算 某字符串 出现的次数
- (NSInteger)tm_countOccurencesOfString:(NSString *)targetString;

- (NSString *)tm_urlHost;

- (NSString *)tm_urlPath;

- (NSString *)tm_replaceHostByNewHost:(NSString *)newHost;

#pragma mark - Style

/// 返回MB/GB为单位的数据 (带单位); 111MB/111.3GB 小数点后为零时,自动省略
/// @param bytes 文件大小
+ (NSString *)tm_fileSizeOnMBWithBytes:(uint64_t)bytes;

/**
 将整数转换成千分位形式的字符串
 eg. 19921116 -> 19,921,116
 
 @param i 整数
 @return 千分位字符串
 */
+ (NSString *)tm_decimalStringOfLongLong:(int64_t)i;

/**
 数据显示规则：
 1.如果数据小于1万，则显示该数字,带千分位符；
 2.如果数字大于等于1万小于100万，则显示xxx.xk，精确到1位小数；
 3.如果数字大于等于1百万小于10亿，则显示xxx.xm，精确到1位小数；
 4.如果数字大于等于10亿，则显示xxx.xb，精确到1位小数；
 5.如果数字大于等于1万亿，则显示xxx.xt，精确到1位小数；
 6.如果小数点后1位为0 就不显示；
 @param i 正整数
 @return 计数缩写字符串
 */
+ (NSString *)tm_abbreviatedCountWithDecimalPointOfLongLong:(int64_t)i;

+ (NSString *)tm_stringWithHTML:(NSString *)html;

/// 将字符串按一个一个字符拆成数组，类似 JavaScript 里的 split("")，如果多个空格，则每个空格也会当成一个 item
@property (nullable, readonly, copy) NSArray<NSString *> *tm_splitToArray;

/// 将字符串按一个一个字符拆成数组，类似 JavaScript 里的 split("")，但会自动过滤掉空白字符
@property (nullable, readonly, copy) NSArray<NSString *> *tm_toTrimmedArray;

/// 去掉头尾的空白字符
@property (readonly, copy) NSString *tm_trim;

/// 去掉整段文字内的所有空白字符（包括换行符）
@property (readonly, copy) NSString *tm_trimAllWhiteSpace;

/// 将文字中的换行符替换为空格
@property (readonly, copy) NSString *tm_trimLineBreakCharacter;

/// 把该字符串转换为对应的 md5
@property (readonly, copy) NSString *tm_md5;

/// 返回一个符合 query value 要求的编码后的字符串，例如&、#、=等字符均会被变为 %xxx 的编码
/// @see `NSCharacterSet (QMUI) tm_URLUserInputQueryAllowedCharacterSet`
@property (nullable, readonly, copy) NSString *tm_stringByEncodingUserInputQuery;

/// 把当前文本的第一个字符改为大写，其他的字符保持不变，例如 backgroundView.tm_capitalizedString -> BackgroundView（系统的 capitalizedString 会变成 Backgroundview）
@property (nullable, readonly, copy) NSString *tm_capitalizedString;

/**
 * 用正则表达式匹配的方式去除字符串里一些特殊字符，避免UI上的展示问题
 * @link http://www.croton.su/en/uniblock/Diacriticals.html @/link
 */
@property (nullable, readonly, copy) NSString *tm_removeMagicalChar;

/**
 用正则表达式匹配字符串，将匹配到的第一个结果返回，大小写不敏感
 
 @param pattern 正则表达式
 @return 匹配到的第一个结果，如果没有匹配成功则返回 nil
 */
- (nullable NSString *)tm_stringMatchedByPattern:(NSString *)pattern;

/**
 用正则表达式匹配字符串，返回匹配到的第一个结果里的指定分组（由参数 index 指定）。
 例如使用 @"ing([\\d\\.]+)" 表达式匹配字符串 @"string0.05" 并指定参数 index = 1，则返回 @"0.05"。
 @param pattern 正则表达式，可用括号表示分组
 @param index 要返回第几个分组，0表示整个正则表达式匹配到的结果，1表示匹配到的结果里的第1个分组（第1个括号）
 @return 返回匹配到的第一个结果里的指定分组，如果 index 超过总分组数则返回 nil。匹配失败也返回 nil。
 */
- (nullable NSString *)tm_stringMatchedByPattern:(NSString *)pattern groupIndex:(NSInteger)index;

/**
 用正则表达式匹配字符串，返回匹配到的第一个结果里的指定分组（由参数 name 指定）。
 例如使用 @"ing(?<number>[\\d\\.]+)" 表达式匹配字符串 @"string0.05" 并指定参数 name 为 @"number"，则返回 @"0.05"。
 @param pattern 正则表达式，可用括号表示分组，分组必须用 ?<name> 的语法来为分组命名。
 @param name 要返回的分组名称，可通过 pattern 里的 ?<name> 语法对分组进行命名。
 @return 返回匹配到的第一个结果里的指定分组，如果 name 不存在则返回 nil。匹配失败也返回 nil。
 */
- (nullable NSString *)tm_stringMatchedByPattern:(NSString *)pattern groupName:(NSString *)name;

/**
 *  用正则表达式匹配字符串并将其替换为指定的另一个字符串，大小写不敏感
 *  @param pattern 正则表达式
 *  @param replacement 要替换为的字符串
 *  @return 最终替换后的完整字符串，如果正则表达式匹配不成功则返回原字符串
 */
- (NSString *)tm_stringByReplacingPattern:(NSString *)pattern withString:(NSString *)replacement;

/// 把某个十进制数字转换成十六进制的数字的字符串，例如“10”->“A”
+ (NSString *)tm_hexStringWithInteger:(NSInteger)integer;

/// 把参数列表拼接成一个字符串并返回，相当于用另一种语法来代替 [NSString stringWithFormat:]
+ (NSString *)tm_stringByConcat:(id)firstArgv, ...;

/**
 * 将秒数转换为同时包含分钟和秒数的格式的字符串，例如 100->"01:40"
 */
+ (NSString *)tm_timeStringWithMinsAndSecsFromSecs:(double)seconds;

/// 将单行的 String 按照限制条件裁剪为多行的数组
- (NSArray *)tm_multilineStringsWithWidth:(CGFloat)width font:(UIFont *)font;

@end

NS_ASSUME_NONNULL_END
