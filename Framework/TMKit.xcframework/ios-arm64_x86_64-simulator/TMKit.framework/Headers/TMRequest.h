//
//  TMRequest.h
//  TMetworking
//
//  Created by TMKit on 2022/2/11.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFHTTPSessionManager.h>

NS_ASSUME_NONNULL_BEGIN

@class TMRequest, TMResponse;

typedef NS_ENUM(NSUInteger, TMRequestMethod) {
    TMRequestMethodGET,
    TMRequestMethodPOST,
    TMRequestMethodDELETE,
    TMRequestMethodPUT,
    TMRequestMethodHEAD,
    TMRequestMethodPATCH
};

typedef NS_ENUM(NSUInteger, TMRequestState) {
    TMRequestStateIdle = 0,
    TMRequestStateOngoing,
    TMRequestStateCompleted
};

/// Request之间的竞争策略
typedef NS_ENUM(NSUInteger, TMRequestConcurrencyStrategy) {
    TMRequestConcurrencyStrategyCancelOlder = 0,
    TMRequestConcurrencyStrategyCancelNewer,
    TMRequestConcurrencyStrategyAllowAll
};

/// 进度闭包
typedef void(^TMRequestProgressBlock)(NSProgress *progress);

/// 请求完成闭包
typedef void(^TMRequestCompletionBlock)(TMResponse *response);

/// 网络请求响应代理
@protocol TMResponseDelegate <NSObject>
@optional

- (void)request:(__kindof TMRequest *)request completionWithResponse:(TMResponse *)response;

/// 上传进度
- (void)request:(__kindof TMRequest *)request uploadProgress:(NSProgress *)progress;

/// 下载进度
- (void)request:(__kindof TMRequest *)request downloadProgress:(NSProgress *)progress;

@end

@interface TMRequest : NSObject

/// 由TMApi发起，其对应的apiId
@property (nonatomic, assign) NSUInteger apiId;

#pragma mark - 请求准备
/// 指定 sessionManager
@property (nonatomic, strong) AFHTTPSessionManager *sessionManager;

/// 请求方式
@property (nonatomic, assign) TMRequestMethod method;

/// 请求方式字符串
- (NSString *)methodString;

/// 完整地址
@property (nonatomic, copy) NSString *URLString;

/// 请求的域名 (若用 IP 请求，则返回其 Header 中的 Host 信息)
@property (nonatomic, copy, readonly) NSString *domain;

/// 请求参数
@property (nonatomic, copy, nullable) NSDictionary *parameters;

/// 请求头
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *headers;

/// 下载路径
@property (nonatomic, copy) NSString *downloadPath;

@property (nonatomic, strong) NSURLRequest *urlRequest;

/// 请求上传文件包
@property (nonatomic, copy, nullable) void(^requestConstructingBody)(id<AFMultipartFormData> formData);

#pragma mark - 发起/取消请求
/// 当前请求状态
@property (nonatomic, assign, readonly) TMRequestState state;

/// 发起网络请求
- (void)start;

/// 发起网络请求带回调
/// @param completion 请求完成回调
- (void)startWithCompletion:(nullable TMRequestCompletionBlock)completion;

/// 发起网络请求带回调
/// @param uploadProgress 上传进度回调
/// @param downloadProgress 下载进度回调
/// @param completion 请求完成回调
- (void)startWithUploadProgress:(nullable TMRequestProgressBlock)uploadProgress
               downloadProgress:(nullable TMRequestProgressBlock)downloadProgress
                     completion:(nullable TMRequestCompletionBlock)completion;

/// 取消网络请求
- (void)cancel;

#pragma - 相关回调代理

/// 请求结果回调代理
@property (nonatomic, weak) id<TMResponseDelegate> responseDelegate;

/// 请求任务ID，由下层返回
@property (nonatomic, assign, readonly) NSUInteger taskId;

/// 请求序列化器
@property (nonatomic, strong, nullable) AFHTTPRequestSerializer *requestSerializer;

@end

NS_ASSUME_NONNULL_END
