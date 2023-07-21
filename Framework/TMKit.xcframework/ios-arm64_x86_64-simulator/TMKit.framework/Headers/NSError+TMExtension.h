//
//  NSError+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2022/5/12.
//  Copyright © 2022 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSError (TMExtension)

/// 用户设备本身的网络问题
- (BOOL)tm_isDeviceConnectionIssue;

/// SSL 类型错误
- (BOOL)tm_isSSLIssue;

/// 被取消的 NSURLError
- (BOOL)tm_isURLCancel;

@end

NS_ASSUME_NONNULL_END
