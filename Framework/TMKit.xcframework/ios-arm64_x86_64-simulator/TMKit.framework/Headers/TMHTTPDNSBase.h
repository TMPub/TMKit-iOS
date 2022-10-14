//
//  TMHTTPDNSBase.h
//  TMetworking
//
//  Created by TMKit on 2022/2/18.
//  Copyright © 2022 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMHTTPDNSRecord.h"

const static NSString *kHTTPDNS_GOOGLE_SERVER_ADDRESS = @"8.8.8.8";

@protocol HTTPDNSBaseProtocol

@required

/// 执行 TMHTTPDNS 查询的 URL
/// @param domain 需要查询的域名
- (NSString *)getRequestString:(NSString *)domain;

/// 解析查询后的返回数据，转换为 TMHTTPDNSRecord
- (TMHTTPDNSRecord *)parseResult:(NSData *)data;

@end

typedef void(^HTTPDNSRequsetCallback)(TMHTTPDNSRecord *record, NSError *error);

typedef void(^HTTPDNSCallback)(TMHTTPDNSRecord *record);

@interface TMHTTPDNSBase : NSObject <HTTPDNSBaseProtocol>

/// 请求的超时时间
@property (nonatomic, assign) NSTimeInterval requestTimeout;

/// 请求耗时
@property (nonatomic, assign) NSTimeInterval requestDuration;

/// 是否正在请求
@property (nonatomic, assign, readonly) BOOL isRequesting;

/// 发起查询
/// @param domain 域名
/// @param callback 查询结果
- (void)requsetRecord:(NSString *)domain callback:(HTTPDNSRequsetCallback)callback;

@end
