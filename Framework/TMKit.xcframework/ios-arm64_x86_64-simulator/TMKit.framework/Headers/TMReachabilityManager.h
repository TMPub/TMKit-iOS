//
//  TMReachabilityManager.h
//  TMUtil
//
//  Created by TMKit on 2021/2/22.
//  Copyright © 2021 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreTelephony/CTCellularData.h>

typedef NS_ENUM(NSInteger, TMReachabilityStatus) {
    TMReachabilityStatusUnknown          = -1,
    TMReachabilityStatusNotReachable     = 0,
    TMReachabilityStatusReachableViaWiFi = 1,
    TMReachabilityStatusReachableVia2G   = 2,
    TMReachabilityStatusReachableVia3G   = 3,
    TMReachabilityStatusReachableVia4G   = 4,
    TMReachabilityStatusReachableVia5G   = 5,
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^TMReachabilityStatusBlock)(TMReachabilityStatus status);
typedef void (^TMCellularDataRestrictedStateBlock)(CTCellularDataRestrictedState state);
typedef void (^TMCellularProvidersDidUpdateBlock)(NSString *identifier);

@interface TMReachabilityManager : NSObject

@property (nonatomic, readonly, assign) TMReachabilityStatus networkReachabilityStatus;
///已经获取到网络初始状态
@property (nonatomic, readonly, assign) BOOL hasInitNetworkState;

@property (nonatomic, readonly, assign, getter = isReachable) BOOL reachable;

@property (nonatomic, readonly, assign, getter = isReachableViaWWAN) BOOL reachableViaWWAN;

@property (nonatomic, readonly, assign, getter = isReachableViaWiFi) BOOL reachableViaWiFi;

@property (nonatomic, copy, nullable, readonly) NSString *carrierName;

@property (nonatomic, copy, nullable, readonly) NSString *mcc;

@property (nonatomic, copy, nullable, readonly) NSString *mnc;

+ (instancetype)sharedManager;

- (void)startMonitoring;

- (void)stopMonitoring;

/// 网络状态回调（若休眠状态下回到前台，点击切换多少次，该回调会触发多少次）
@property (nonatomic, readwrite, copy) TMReachabilityStatusBlock networkReachabilityStatusBlock;

/// 网络权限变化回调，该回调变化其实也会触发 networkReachabilityStatusBlock，因此如果只是想监听网络变化，只需要 networkReachabilityStatusBlock
@property (nonatomic, readwrite, copy) TMCellularDataRestrictedStateBlock cellularDataRestrictionUpdateBlock;

/// 运营商变化回调 (app 在前台才触发)
@property (nonatomic, readwrite, copy) TMCellularProvidersDidUpdateBlock cellularProvidersDidUpdateBlock;

FOUNDATION_EXPORT NSString * const TMReachabilityDidChangeNotification;
FOUNDATION_EXPORT NSString * const TMReachabilityNotificationStatusItem;
FOUNDATION_EXPORT NSString * const TMCellularDataRestrictionDidUpdateNotification;

@end

NS_ASSUME_NONNULL_END
