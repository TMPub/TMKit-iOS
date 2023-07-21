//
//  TMDeviceUtil.h
//  TMDeviceUtil
//
//  Created by TMKit on 2022/6/16.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TMDevicePerformance) {
    TMDevicePerformanceLow = 1, // LOW
    TMDevicePerformanceMiddle = 2, // MIDDLE
    TMDevicePerformanceHigh = 3 // HIGH
};

@interface TMDeviceUtil : NSObject

@property (nonatomic, copy, nullable, readonly) NSString *deviceId;

// 系统设备标识信息，有性能考虑，只在初始化获取一次
@property (nonatomic, copy, nullable, readonly) NSString *idfa;
@property (nonatomic, copy, nullable, readonly) NSString *idfv;

@property (nonatomic, copy, readonly) NSString *brand;
@property (nonatomic, copy, readonly) NSString *os;
@property (nonatomic, copy, readonly) NSString *deviceModel;
@property (nonatomic, assign, readonly) CGFloat screenSize;
@property (nonatomic, assign, readonly) NSInteger numberOfCores;
@property (nonatomic, assign, readonly) CGFloat l2CacheSize;
@property (nonatomic, assign, readonly) CGFloat physicalMemory;

@property (nonatomic, assign, readonly) CGFloat rom;
@property (nonatomic, assign, readonly) CGFloat ram;
@property (nonatomic, assign, readonly) UIInterfaceOrientation orientation;
@property (nonatomic, assign, readonly) UIApplicationState appState;
@property (nonatomic, assign, readonly) TMDevicePerformance performanceLevel;

// 即时获取
@property (nonatomic, copy, readonly) NSString *language;
@property (nonatomic, copy, readonly) NSString *timeZone;

/// 运营商名称，有性能考虑，只在初始化获取一次
@property (nonatomic, copy, nullable, readonly) NSString *carrierName;

/// 移动国家码，有性能考虑，只在初始化获取一次
@property (nonatomic, copy, nullable, readonly) NSString *mcc;

/// 移动网络码，有性能考虑，只在初始化获取一次
@property (nonatomic, copy, nullable, readonly) NSString *mnc;

+ (NSTimeInterval)systemUptime;

+ (NSString *)recognizeIsoCountryCode;

+ (instancetype)shareUtil;

+ (NSString *)newUUID;

+ (NSString *)appName;

/// 版本号
- (NSString *)version;

+ (nullable NSString *)randomStringOfLength:(NSInteger)length;

/// 编译号
- (NSString *)buildNumber;

#pragma mark - Os Version
@property (nonatomic, copy, readonly) NSString *osVersionString;

- (NSUInteger)osVersionMajor;
- (NSUInteger)osVersionMinor;
- (NSUInteger)osVersionPatch;

/// 当前系统版本 等于 指定版本号
/// - Parameter v: 指定版本号
- (BOOL)isOsVersionEqualToVersion:(NSString *)v;

/// 当前系统版本 大于 指定版本号
/// - Parameter v: 指定版本号
- (BOOL)isOsVersionGreaterThanVersion:(NSString *)v;

/// 当前系统版本  大于或等于 指定版本号
/// - Parameter v: 指定版本号
- (BOOL)isOsVersionGreaterThanOrEqualToVersion:(NSString *)v;

/// 当前系统版本  大于或等于 v1 小于v2
/// - Parameters:
///   - v1: 大于或等于该版本
///   - v2: 小于该版本
- (BOOL)isOsVersionGreaterThanOrEqualToVersion:(NSString *)v1 andLessThanVersion:(NSString *)v2;

/// 当前系统版本 小于 指定版本号
/// - Parameter v: 指定版本号
- (BOOL)isOsVersionLessThanVersion:(NSString *)v;

/// 当前系统版本 小于或等于 指定版本号
/// - Parameter v: 指定版本号
- (BOOL)isOsVersionLessThanOrEqualToVersion:(NSString *)v;

/// 当前系统版本 在区间范围（两端都含等于逻辑）
/// - Parameters:
///   - v1: 大于或等于 该版本
///   - v2: 小于或等于 该版本
- (BOOL)isOsVersionBetweenVersion:(NSString *)v1 andVersion:(NSString *)v2;

/// 状态栏高度
- (CGFloat)statusBarHeightConstant;

@end

NS_ASSUME_NONNULL_END
