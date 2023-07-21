//
//  WKWebView+TMExtension.h
//  TMExtensions
//
//  Created by TMKi on 2022/5/5.
//  Copyright © 2022 TMKit. All rights reserved.
//

#import <Webkit/Webkit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WKWebView (BKExtension)

/// 设置 UserAgent 的正确方式，不要使用 WKWebViewConfiguration.applicationNameForUserAgent，会导致缺少 Mobile/15E148，从而导致其他问题（例如 https://apps.apple.com/cn/app/id1437251983 -> itms-appss://apps.apple.com 重定向失败）
/// @param customUserAgent 自定义的 UserAgent
- (void)tm_setCustomUserAgent:(NSString *)customUserAgent;

+ (void)tm_deleteWebCache;

@end

NS_ASSUME_NONNULL_END
