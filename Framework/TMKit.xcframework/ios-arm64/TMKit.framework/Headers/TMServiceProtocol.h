//
//  TMServiceProtocol.h
//  TMetworking
//
//  Created by TMKit on 2022/2/14.
//

#import <AFNetworking/AFHTTPSessionManager.h>
#import "TMHTTPDNSConfig.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TMServiceProtocol <NSObject>

@required

/// AFHTTPSessionManager 对象
@property (nonatomic, strong) AFHTTPSessionManager *sessionManager;

/// baseURL 列表, 若包含多个，则支持域名切换策略，baseURLString = scheme+host+port
@property (nonatomic, copy) NSArray<NSString *> *baseURLStrings;

/// 定义该 Service 下产生的错误是否需要域名切换重试
- (BOOL)shouldRetry:(NSError *)error;

@optional
/// 域名列表（来源：baseURLStrings）
@property (nonatomic, copy) NSSet<NSString *> *domains;

/// 通用参数
@property (nonatomic, copy, nullable) NSDictionary *commonParameters;

/// 通用请求头
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *commonHeaders;

#pragma mark - DNS
/// 不为空时，将使用配置项进行 HTTPDNS 解析 IP，再进行请求
@property (nonatomic, strong, nullable) TMHTTPDNSConfig *HTTPDNSConfig;

/// DNS 域名白名单列表，API 请求若执行 HTTPDnsModeNormal 的解析时，会同时检查该列表内的域名是否过期/即将过期，是的话重新执行查询
@property (nonatomic, copy) NSSet<NSString *> *dnsDomainWhiteLists;

@end

NS_ASSUME_NONNULL_END
