//
//  TMLoggerApi.h
//  TMetworking
//
//  Created by TMKi on 2022/4/27.
//  Copyright © 2022 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMLoggerRequest : NSObject

/// scheme+host+path
@property (nonatomic, copy) NSString *urlString;
/// 域名（非 IP）
@property (nonatomic, copy) NSString *domain;
///  IP
@property (nonatomic, copy) NSString *ip;
/// 路径
@property (nonatomic, copy) NSString *path;
/// 请求信息
@property (nonatomic, copy) NSString *requestString;
/// 返回信息
@property (nonatomic, copy) NSString *responseString;
/// 是否正在请求
@property (nonatomic, assign) BOOL isRunning;
/// 错误信息（成功为 nil）
@property (nonatomic, strong, nullable) NSError *error;
/// 请求开始的时间
@property (nonatomic, strong) NSDate *startTime;
/// 请求结束的时间
@property (nonatomic, strong) NSDate *endTime;

@end

@interface TMLoggerApi : NSObject

/// 一次请求的唯一标识
@property (nonatomic, copy) NSString *apiId;
/// URL 路径
@property (nonatomic, copy) NSString *path;
/// 生命周期内（从发起到最终失败/成功为结束点）的所有请求
@property (nonatomic, strong, readonly) NSMutableArray<TMLoggerRequest *> *requests;
/// 是否正在请求
@property (nonatomic, assign) BOOL isRunning;
/// 是否最终失败/成功
@property (nonatomic, assign) BOOL isSuccess;
/// 是否取消
@property (nonatomic, assign) BOOL isCancel;

- (void)addRequest:(TMLoggerRequest *)request;

- (TMLoggerRequest *)requestByUrlString:(NSString *)urlString;

@end

NS_ASSUME_NONNULL_END
