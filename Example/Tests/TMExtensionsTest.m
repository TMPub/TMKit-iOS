//
//  TMExtensionsTest.m
//  TMKit_Tests
//
//  Created by TMKit on 2022/7/21.
//  Copyright © 2022 frank-du. All rights reserved.
//

#import <XCTest/XCTest.h>
@import TMKit.TMExtensions;

@interface TMExtensionsTest : XCTestCase

@end

@implementation TMExtensionsTest

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testExample {
    NSDate *date = [NSDate tm_dateWithString:@"2020-04-27 07:08:08" format:@"yyyy-MM-dd HH:mm:ss"];
    NSDate *date1 = [NSDate tm_dateWithString:@"2020-04-27 08:08:08" format:@"yyyy-MM-dd HH:mm:ss" timeZone:[NSTimeZone localTimeZone] locale:[NSLocale currentLocale]];
    NSDate *date2 = [NSDate tm_dateWithISOFormatString:@"2019-12-30T07:08:08+0800"];
    
    NSString *string = [date tm_stringWithFormat:@"yyyy-MM-dd"];
    NSString *string1 = [date tm_stringWithFormat:@"yyyy-MM-dd" timeZone:[NSTimeZone localTimeZone] locale:[NSLocale currentLocale]];
    NSString *string2 = [date tm_stringWithISOFormat];
    XCTAssertEqual([string isEqualToString:@"2020-04-27"], YES);
    XCTAssertEqual([string1 isEqualToString:@"2020-04-27"], YES);
    XCTAssertEqual([string2 isEqualToString:@"2020-04-27T07:08:08+0800"], YES);
    
    // Components =================
    XCTAssertEqual([date tm_year], 2020);
    XCTAssertEqual([date tm_month], 4);
    XCTAssertEqual([date tm_day], 27);
    XCTAssertEqual([date tm_hour], 7);
    XCTAssertEqual([date tm_minute], 8);
    XCTAssertEqual([date tm_second], 8);
    XCTAssertEqual([date tm_weekday], 2);
    XCTAssertEqual([date tm_weekOfMonth], 5);
    XCTAssertEqual([date tm_weekOfYear], 18);
    // 由于2020年1月1日是星期三，属于一个星期前半部分，所以从12月30号到1月5号这一周都属于 2020的 week 01
    XCTAssertEqual([date2 tm_yearForWeekOfYear], 2020);
    XCTAssertEqual([date tm_quarter], 2);
    
    // Add =================
    NSDate *date3 = [date tm_dateByAddingYears:1];
    date3 = [date3 tm_dateByAddingMonths:1];
    date3 = [date3 tm_dateByAddingDays:1];
    date3 = [date3 tm_dateByAddingHours:1];
    date3 = [date3 tm_dateByAddingMinutes:1];
    date3 = [date3 tm_dateByAddingSeconds:1];
    XCTAssertEqualObjects([date3 tm_stringWithFormat:@"yyyy-MM-dd HH:mm:ss"], @"2021-05-28 08:09:09");
    
    // Update =================
    NSDate *date4 = [date tm_updateYear:2022];
    date4 = [date4 tm_updateMonth:1];
    date4 = [date4 tm_updateDay:1];
    date4 = [date4 tm_updateHour:1];
    date4 = [date4 tm_updateMinute:1];
    date4 = [date4 tm_updateSecond:1];
    XCTAssertEqualObjects([date4 tm_stringWithFormat:@"yyyy-MM-dd HH:mm:ss"], @"2022-01-01 01:01:01");
    
    // Check =================
    NSDate *today = [NSDate date];
    NSDate *yesterday = [[NSDate date] tm_dateByAddingDays:-1];
    NSDate *tomorrowAnd1Hour = [[[NSDate date] tm_dateByAddingDays:1] tm_dateByAddingHours:1];
    
    XCTAssertEqual([date tm_isLeapYear], YES);
    // TODO
    XCTAssertEqual([date tm_isLeapMonth], NO);
    XCTAssertEqual([today tm_isToday], YES);
    XCTAssertEqual([yesterday tm_isYesterday], YES);
    
    XCTAssertEqual([tomorrowAnd1Hour tm_isInDays:1], YES);
    XCTAssertEqual([yesterday tm_isDaysAgo:1], YES);
    
    XCTAssertEqual([NSDate tm_isExpiredDays:1 expiredDate:yesterday], NO);
    XCTAssertEqual([NSDate tm_isExpiredAtDate:tomorrowAnd1Hour afterDays:1], YES);
    
    XCTAssertEqual([date tm_isSameDay:date1], YES);
    XCTAssertEqual([date tm_isSameUTCDay:date1], NO);
    
    
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
