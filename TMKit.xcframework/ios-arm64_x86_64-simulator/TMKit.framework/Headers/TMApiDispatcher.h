//
//  TMApiDispatcher.h
//  TMetworking
//
//  Created by TMKit on 2022/4/11.
//  Copyright © 2022 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMApi.h"

NS_ASSUME_NONNULL_BEGIN

#define SharedApiDispatcher             TMApiDispatcher.sharedDispatcher

@interface TMApiDispatcher : NSObject

+ (instancetype)sharedDispatcher;

/// 将Api的生命周期交给SharedApiDispatcher管理，由它持有，响应回来后强制回收
/// @param api 需要被SharedApiDispatcher管理的Api
- (void)addApi:(__kindof TMApi *)api;

/// 在SharedApiDispatcher中移除对Api生命周期的管理
/// @param apiId api唯一标识
- (void)removeApiWithApiId:(NSUInteger)apiId;

/// 根据apiId查找被SharedApiDispatcher管理的api
/// @param apiId api唯一标识
- (__kindof TMApi *)apiWithApiId:(NSUInteger)apiId;

/// 根据apiId查询api是否被SharedApiDispatcher管理
/// @param apiId api唯一标识
- (BOOL)containsApi:(NSUInteger)apiId;

@end

NS_ASSUME_NONNULL_END
