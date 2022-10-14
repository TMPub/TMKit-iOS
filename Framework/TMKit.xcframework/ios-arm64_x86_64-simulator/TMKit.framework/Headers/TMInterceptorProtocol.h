//
//  TMInterceptorProtocol.h
//  TMetworking
//
//  Created by TMKit on 2022/3/2.
//  Copyright © 2022 TMKit. All rights reserved.
//

#import "TMResponse.h"
@class TMApi;

NS_ASSUME_NONNULL_BEGIN

@protocol TMInterceptorProtocol <NSObject>

- (void)interceptResponse:(TMResponse *)response api:(TMApi *)api;

@end

NS_ASSUME_NONNULL_END
