//
//  TMResponse.h
//  TMetworking
//
//  Created by TMKit on 2022/2/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMResponse : NSObject

/// 请求任务
@property (nonatomic, strong, readonly, nullable) NSHTTPURLResponse *urlResponse;

@property (nonatomic, strong, readonly, nullable) id responseObject;

@property (nonatomic, strong, nullable) NSError *error;

/// 错误信息，由 Interceptor 自定义解析，并交给上层自行显示
@property (nonatomic, strong, nullable) NSString *errorMessage;

/// 成功信息，由 Interceptor 自定义解析，并交给上层自行显示
@property (nonatomic, strong, nullable) NSString *message;

@property (nonatomic, strong) NSURLSessionTaskTransactionMetrics *metrics;

+ (instancetype)responseWithURLResponse:(nullable NSHTTPURLResponse *)urlResponse
                         responseObject:(nullable id)responseObject
                                  error:(nullable NSError *)error;

@end

NS_ASSUME_NONNULL_END
