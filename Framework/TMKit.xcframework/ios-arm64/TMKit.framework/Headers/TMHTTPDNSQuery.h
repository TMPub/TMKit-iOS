//
//  TMHTTPDNSQuery.h
//  TMetworking
//
//  Created by TMKit on 2022/4/14.
//  Copyright © 2022 TMKit. All rights reserved.
//  基于域名服务的策略进行 DNS 解析，返回域名对应的 IP

#import <Foundation/Foundation.h>
#import "TMServiceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^URLStringBlock)(NSString * _Nullable urlString, BOOL changed);
typedef void (^IPStringBlock)(NSString * _Nullable ip);
typedef void (^CronetHostResolverRulesBlock)(NSString * _Nullable rules);

@interface TMHTTPDNSQuery : NSObject

/// DNS 解析的业务逻辑，若 URL 已经是 IP/不在 Service /Service黑名单中，不会触发 DNS 解析。非 Cronet 下返回的 IP 会进行连通性测试，OK 的话才会返回（避免后续使用 IP 发生 SNI 错误）
/// @param url 原有的请求 URL
/// @param service 请求 Service
/// @param completion 完成回调，urlString: 返回新的请求 URL String changed: URL 是否被替换为 IP（若替换，调用者需要设置 Header-Host : url.host）
+ (void)requestDNSByOriginURL:(NSURL *)url service:(id<TMServiceProtocol>)service completion:(URLStringBlock)completion;

+ (void)requestDNSByDomain:(NSString *)domain HTTPDNSConfig:(TMHTTPDNSConfig *)config completion:(nullable IPStringBlock)completion;

+ (TMHTTPDNSQuery *)sharedInstance;

@property (nonatomic, copy) CronetHostResolverRulesBlock cronetHostResolverRuleBlock;

@end

NS_ASSUME_NONNULL_END
