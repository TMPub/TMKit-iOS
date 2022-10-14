//
//  TMDeviceUtil.h
//  TMUtil
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
@property (nonatomic, copy, readonly) NSString *osVersion;

@property (nonatomic, copy, readonly) NSString *modelString;
@property (nonatomic, assign, readonly) CGFloat screenSize;

@property (nonatomic, assign, readonly) CGFloat rom;
@property (nonatomic, assign, readonly) CGFloat ram;
@property (nonatomic, assign, readonly) NSInteger orientation;
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

+ (instancetype)shareUtil;

+ (NSString *)newUUID;

+ (NSString *)appName;

@end

NS_ASSUME_NONNULL_END
