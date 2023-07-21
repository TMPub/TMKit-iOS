//
//  NSDate+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2022/7/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (TMExtension)

#pragma mark - Date->String
- (NSString *)tm_stringWithFormat:(NSString *)format;

- (NSString *)tm_stringWithFormat:(NSString *)format locale:(NSLocale *)locale;

- (NSString *)tm_stringWithFormat:(NSString *)format localeIdentifier:(NSString *)localeIdentifier;

#pragma mark - String->Date
+ (NSDate *)tm_dateWithString:(NSString *)dateString format:(NSString *)format;

+ (NSDate *)tm_dateWithString:(NSString *)dateString format:(NSString *)format locale:(NSLocale *)locale;

+ (NSDate *)tm_dateWithString:(NSString *)dateString format:(NSString *)format localeIdentifier:(NSString *)localeIdentifier;

#pragma mark - Components
/// 取年份
- (NSInteger)tm_year;

/// 取月份
- (NSInteger)tm_month;

/// 取天
- (NSInteger)tm_day;

/// 取小时
- (NSInteger)tm_hour;

/// 取分钟
- (NSInteger)tm_minute;

/// 取秒
- (NSInteger)tm_second;

/// 取周 周日为 1，周一为 2，周二为 3，周三为 4，周四为 5，周五为 6
- (NSInteger)tm_weekday;

/// 当前日期在当前月处于第几周
- (NSInteger)tm_weekOfMonth;

/// 当前日期在当前年处于第几周
- (NSInteger)tm_weekOfYear;

/// 当前日期所在周所在的年份（对于跨年的周，取决于该周在哪一年的天数较多）
- (NSInteger)tm_yearForWeekOfYear;

/// 当前日期在当前年处于第几季度
- (NSInteger)tm_quarter;

#pragma mark - Add
- (NSDate *)tm_dateByAddingYears:(NSInteger)years;

- (NSDate *)tm_dateByAddingMonths:(NSInteger)months;

- (NSDate *)tm_dateByAddingWeeks:(NSInteger)weeks;

- (NSDate *)tm_dateByAddingDays:(NSInteger)days;

- (NSDate *)tm_dateByAddingHours:(NSInteger)hours;

- (NSDate *)tm_dateByAddingMinutes:(NSInteger)minutes;

- (NSDate *)tm_dateByAddingSeconds:(NSInteger)seconds;

#pragma mark - Update
- (NSDate *)tm_updateYear:(NSInteger)year;

- (NSDate *)tm_updateMonth:(NSInteger)month;

- (NSDate *)tm_updateDay:(NSInteger)day;

- (NSDate *)tm_updateHour:(NSInteger)hour;

- (NSDate *)tm_updateMinute:(NSInteger)minute;

- (NSDate *)tm_updateSecond:(NSInteger)second;

#pragma mark - Check
/// 是否闰年
- (BOOL)tm_isLeapYear;

/// 是否闰月
- (BOOL)tm_isLeapMonth;

/// 是否今天
- (BOOL)tm_isToday;

/// 是否昨天
- (BOOL)tm_isYesterday;

/// 是否是未来 n 天
- (BOOL)tm_isInDays:(NSInteger)days;

/// 是否在过去 n 天
- (BOOL)tm_isDaysAgo:(NSInteger)days;

/// 距离过期时间是否小于 N 天（是否在保质期内N天）
/// @param date 过期时间
/// @param days 距离过期时间的天数
+ (BOOL)tm_willExpiredAtDate:(NSDate *)date inDays:(NSInteger)days;

/// 距离过期时间是否超过了 N 天（是否在保质期外N天）
/// @param days 超过过期时间天数
/// @param date 过期时间
+ (BOOL)tm_isExpiredOverDays:(NSInteger)days expiredDate:(NSDate *)date;

#pragma mark - Compare
/// 2个日期是否是同一天（相同时区下比较）
- (BOOL)tm_isSameDay:(NSDate *)dateTwo;

/// 2个日期在 UTC 下是否是同一天（不同时区下比较，例如和服务器时间比较，统一转成 UTC 去比较）
- (BOOL)tm_isSameUTCDay:(NSDate *)dateTwo;

@end

NS_ASSUME_NONNULL_END
