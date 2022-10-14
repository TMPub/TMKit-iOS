//
//  TMDomainRetryer.h
//  TMetworking
//
//  Created by TMKit on 2022/4/18.
//  Copyright © 2022 TMKit. All rights reserved.
//  多域名重试机制

#import <Foundation/Foundation.h>
#import "TMServiceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^RetryBlock)(NSString *urlString, BOOL shouldUseDomain);

@interface TMDomainRetryer : NSObject

/// 发起重试，重试结束则返回 NO
/// @param urlString 当前请求的 URL
/// @param originDomain 当前请求的 domain（非 IP）
/// @param service  域名服务
/// @param error 当前的错误
/// @param retry 重试发起的操作，返回重试时所用的 URL String（非 IP）, shouldUseDomain 代表返回的 URL 不允许经过 DNS 查询
- (BOOL)startWithOriginURLString:(NSString *)urlString originDomain:(NSString *)originDomain service:(id<TMServiceProtocol>)service error:(NSError *)error retry:(RetryBlock)retry;

/// 重置请求的请求信息，通常在请求成功或重试结束后调用该方法
- (void)reset;

/// 是否是最后一次请求（失败了也不再发起重试）
- (BOOL)isFinal;

/// 所有重试请求中额外增加的域名
@property (nonatomic, copy, nullable) NSString *additionDomain;

/// 所有重试请求中额外增加的域名在所有域名中的位置，必须大于 0
@property (nonatomic, assign) NSInteger additionDomainIndex;

@end

NS_ASSUME_NONNULL_END
