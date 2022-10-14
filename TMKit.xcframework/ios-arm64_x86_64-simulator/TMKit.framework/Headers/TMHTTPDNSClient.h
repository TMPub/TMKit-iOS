//
//  TMHTTPDNSClient.h
//  TMetworking
//
//  Created by TMKit on 2022/2/18.
//  Copyright © 2022 TMKit. All rights reserved.
//  

#import <Foundation/Foundation.h>
#import "TMHTTPDNSBase.h"

@protocol TMHTTPDNSClientDelegate <NSObject>

/// 查询回调
/// @param record 查询结果
/// @param domain 所查域名
/// @param duration 耗时（秒）
/// @param error 错误
- (void)requestDidResponse:(TMHTTPDNSRecord *)record domain:(NSString *)domain duration:(NSTimeInterval)duration error:(NSError *)error;

@optional
/// 查询即将开始
/// @param domain 所查域名
- (void)requestWillBegin:(NSString *)domain;

@end

@interface TMHTTPDNSClient : NSObject

/// TMHTTPDNSClient sharedInstance
+ (TMHTTPDNSClient *)sharedInstance;

/// TTL剩余多少秒时，重新触发解析
@property (nonatomic, assign) NSTimeInterval refreshRemainTime;

/// 自定义TTL
@property (nonatomic, assign) NSTimeInterval customTTL;

/// 最大的失败次数，大于该次数，失败后将不再重试（重置后可以再次重试），为 0 时不生效，默认为 0
@property (nonatomic, assign) NSInteger maxFailCount;

/// 有效的域名-IP键值对
@property (nonatomic, strong, readonly) NSDictionary *recordsMap;

@property (nonatomic, weak) id<TMHTTPDNSClientDelegate> delegate;

/// 清除 DNS 解析缓存
- (void)cleanAllCache;

/// 同步获取 HTTPDNS 解析
/// @param domain 需要解析的域名
/// @param requestTimeout 检查后有必要发起解析的超时时间
- (TMHTTPDNSRecord *)syncGetRecord:(NSString *)domain requestTimeout:(NSTimeInterval)requestTimeout;

/// HTTPDNS 异步解析（同时多次请求解析，只会发起一次真正的请求）
/// @param domain 域名
/// @param requestTimeout 解析的超时时间
/// @param callback 回调
- (void)getRecord:(NSString *)domain requestTimeout:(NSTimeInterval)requestTimeout callback:(HTTPDNSCallback)callback;

/// 需要时，执行 HTTPDNS 解析
- (void)requestRecordIfNeed:(NSString *)domain requestTimeout:(NSTimeInterval)requestTimeout;

/// 重置失败次数（如网络发生变化时）
- (void)resetFailRecord;

- (NSString *)cronetRules;

@end
