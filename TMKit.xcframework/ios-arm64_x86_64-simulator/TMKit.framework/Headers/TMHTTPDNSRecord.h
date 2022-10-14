//
//  TMHTTPDNSRecord.h
//  TMetworking
//
//  Created by TMKit on 2022/2/18.
//  Copyright © 2022 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TMHTTPDNSRecord : NSObject

@property (nonatomic, copy, readonly) NSString *name;
/// IP 地址
@property (nonatomic, strong, readonly) NSString *ip;
/// IP 数组
@property (nonatomic, readonly) NSArray *ips;
/// 超时时间 timeIntervalSince1970
@property (nonatomic, assign) NSTimeInterval timeout;

/// 初始化方法
/// @param ips IP 数组
/// @param name host name
/// @param ttl 过期时间
- (instancetype)init:(NSArray *)ips name:(NSString *)name ttl:(int)ttl;

@end
