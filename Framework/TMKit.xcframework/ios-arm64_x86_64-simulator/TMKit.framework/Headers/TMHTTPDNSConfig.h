//
//  TMHTTPDNSConfig.h
//  TMetworking
//
//  Created by TMKit on 2022/4/8.
//  Copyright © 2022 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TMHTTPDnsMode) {
    TMHTTPDnsModeAsync = 0, // 异步请求
    TMHTTPDnsModeSync = 1, // 同步请求，会阻断，等待请求返回
};

@interface TMHTTPDNSConfig : NSObject

/// DNS 过期时间（若不设置，默认以返回结果的 ttl 字段 为准）
@property (nonatomic, assign) NSTimeInterval customTTL;

/// DNS 解析的过期时间（若设置，则生效）
@property (nonatomic, assign) NSTimeInterval requestTimeout;

/// DNS 解析结果剩余多少秒时，重新触发解析
@property (nonatomic, assign) NSTimeInterval refreshRemainTime;

/// 请求策略 异步：等待解析结果 同步：查询是否有解析结果
@property (nonatomic, assign) TMHTTPDnsMode mode;

- (instancetype)initWithCustomTTL:(NSTimeInterval)customTTL requestTimeout:(NSTimeInterval)requestTimeout refreshRemainTime:(NSTimeInterval)refreshRemainTime mode:(TMHTTPDnsMode)mode;

@end

NS_ASSUME_NONNULL_END
