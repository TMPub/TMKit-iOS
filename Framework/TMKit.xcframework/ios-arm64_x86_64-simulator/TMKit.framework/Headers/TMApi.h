//
//  TMApi.h
//  TMetworking
//
//  Created by TMKit on 2022/3/4.
//

#import <Foundation/Foundation.h>
#import "TMServiceProtocol.h"
#import <AFNetworking/AFHTTPSessionManager.h>
#import "TMInterceptorProtocol.h"
#import "TMRequest.h"

NS_ASSUME_NONNULL_BEGIN

@class TMApi, TMRequest;

@protocol TMApiDelegate <NSObject>

@optional

- (void)api:(TMApi *)api failedWithUrlString:(NSString *)urlString afterError:(NSError *)error domain:(NSString *)domain isFinal:(NSUInteger)isFinal metrics:(NSURLSessionTaskTransactionMetrics *)metrics;

- (void)api:(TMApi *)api successfulWithUrlString:(NSString *)urlString domain:(NSString *)domain metrics:(NSURLSessionTaskTransactionMetrics *)metrics;

@end

@protocol TMActionDelegate <NSObject>

@optional

/// 请求已开始回调
/// @param request 请求体
- (void)requestDidStart:(__kindof TMRequest *)request;

/// 请求响应已完成回调
/// @param request 请求体
/// @param response 响应体
- (void)request:(__kindof TMRequest *)request didResponse:(TMResponse *)response;

@end


@interface TMApi : NSObject <TMInterceptorProtocol, TMApiDelegate>

/// 单个Api实例，初始化生成，由ID生成器控制自增
@property (nonatomic, assign, readonly) NSUInteger apiId;

/// 单个Api实例，每次被用户调用，stage自增
@property (nonatomic, assign, readonly) NSUInteger stage;

/// 单个Api实例，在单个stage内，每次发起请求（如触发重试），phase自增
@property (nonatomic, assign, readonly) NSUInteger phase;

/// 请求方式
@property (nonatomic, assign) TMRequestMethod method;

/// 请求Service, 配置 AFHTTPSessionManager，host，header，common parameters
@property (nonatomic, weak, nullable) id<TMServiceProtocol> service;

/// 请求路径
@property (nonatomic, copy, readonly) NSString *path;

/// 请求参数
@property (nonatomic, copy, nullable) NSDictionary *parameters;

/// 请求头
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *headers;

/// 请求超时时间
@property (nonatomic, assign) NSTimeInterval timeoutInterval;

/// 下载路径
@property (nonatomic, copy) NSString *downloadPath;

/// 是否正在请求
@property (nonatomic, assign, readonly) BOOL isRuning;

/// 是否是最后一次请求（失败了也不再发起重试）
@property (nonatomic, assign, readonly) BOOL isFinal;

/// 所有重试请求中额外增加的域名
@property (nonatomic, copy, nullable) NSString *additionDomain;

/// 所有重试请求中额外增加的域名在所有域名中的位置，必须大于 0
@property (nonatomic, assign) NSInteger additionDomainIndex;

/// TMLogger.shared.isDebug 为 True 且有值时，会使用 mainBundle 的 JSON 文件进行 Mock
@property (nonatomic, copy) NSString *mockJsonPath;

/// 请求上传文件包
@property (nonatomic, copy, nullable) void(^requestConstructingBody)(id<AFMultipartFormData> formData);

/// 请求回调
@property (nonatomic, copy, nullable) TMRequestCompletionBlock completion;

- (instancetype)initWithMethod:(TMRequestMethod)method path:(NSString *)path;

/// 发起网络请求
- (void)startRequest;

/// 发起网络请求带回调
/// @param completion 请求完成回调
- (void)startRequestWithCompletion:(nullable TMRequestCompletionBlock)completion;

/// 发起网络请求带回调
/// @param uploadProgress 上传进度回调
/// @param downloadProgress 下载进度回调
/// @param completion 请求完成回调
- (void)startRequestWithUploadProgress:(nullable TMRequestProgressBlock)uploadProgress
                      downloadProgress:(nullable TMRequestProgressBlock)downloadProgress
                            completion:(nullable TMRequestCompletionBlock)completion;

/// 基于 urlString 发起请求
/// @param urlString 请求链接
/// @param dnsQuery 是否发起 HTTPDNS 查询
- (void)startRequestWithUrlString:(NSString *)urlString dnsQuery:(BOOL)dnsQuery;

/// 请求特定请求
- (void)cancelRequest:(NSUInteger)taskId;

/// 取消所有请求
- (void)cancelAllRequests;

#pragma mark - 相关回调代理
/// 请求结果回调代理
@property (nonatomic, weak) id<TMResponseDelegate> responseDelegate;

/// 请求过程行为回调代理
@property (nonatomic, weak) id<TMActionDelegate> actionDelegate;

/// 自身代理（目前用来外部处理重试逻辑相关业务）
@property (nonatomic, weak) id<TMApiDelegate> apiDelegate;

#pragma mark - 特殊配置
/// 请求序列化器。如果设置了，会被优先使用。如果未设置，会使用则service.sessionManager.requestSerializer。
@property (nonatomic, strong, nullable) AFHTTPRequestSerializer *customRequestSerializer;

/// 拦截器
@property (nonatomic, weak, nullable) id<TMInterceptorProtocol> interceptor;

#pragma mark - URLString & Parameter & Header
/// 预处理请求参数（可进行校验、追加参数等）
/// @param mutableParameters 请求参数
- (void)preprocessParameters:(NSMutableDictionary *)mutableParameters;

/// 预处理请求头（可进行校验、追加参数等）
/// @param mutableHeaders 请求头
- (void)preprocessHeaders:(NSMutableDictionary<NSString *, NSString *> *)mutableHeaders;

@end


@interface TMApi (StageLifecycle)

#pragma mark - Begin/End Stage
- (void)stageWillBegin:(NSUInteger)stage;

- (void)stageDidBegin:(NSUInteger)stage;

- (void)stageWillEnd:(NSUInteger)stage;

- (void)stageDidEnd:(NSUInteger)stage;

@end


@interface TMApi (PhaseLifecycle)

#pragma mark - Begin/End Phase
- (void)phaseWillBegin:(NSUInteger)phase;

- (void)phaseDidBegin:(NSUInteger)phase;

- (void)phaseWillEnd:(NSUInteger)phase;

- (void)phaseDidEnd:(NSUInteger)phase;

@end

NS_ASSUME_NONNULL_END
