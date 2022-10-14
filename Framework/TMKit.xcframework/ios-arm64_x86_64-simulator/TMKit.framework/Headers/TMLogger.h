//
//  TMLogger.h
//  TMetworking
//
//  Created by TMKi on 2022/4/14.
//  Copyright © 2022 TMKit. All rights reserved.
//  只打印 NSURLRequest 和 NSHTTPURLResponse

#import <Foundation/Foundation.h>
#import "TMLoggerApi.h"
#import "TMRequest.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const TMLoggerUpdateNotificationName;

@interface TMLogger : NSObject

@property (nonatomic, strong) NSMutableArray<TMLoggerApi *> *apis;

/// 是的话会输出 apis，默认为 NO
@property (nonatomic, assign) BOOL isDebug;

+ (instancetype)shared;

/// 新增一个 request（第一次会新增一个 api）
- (void)logRequestStart:(TMRequest *)request apiId:(NSString *)apiId urlPath:(NSString *)urlPath;

/// request 回调
- (void)logRequestUpdate:(TMRequest *)request apiId:(NSString *)apiId response:(TMResponse *)response;

/// Api 回调
- (void)logApiFinishByApiId:(NSString *)apiId response:(nullable TMResponse *)response;

@end

NS_ASSUME_NONNULL_END
