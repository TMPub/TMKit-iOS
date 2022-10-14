//
//  TMCookieManager.h
//  TMUtil
//
//  Created by TMKit on 2022/8/10.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

@interface TMCookieManager : NSObject

@property (nonatomic, strong) WKProcessPool *processPool;

+ (instancetype)sharedInstance;

+ (NSString *)getCookieValue;

/// 将所有cookie以document.cookie = 'key=value';形式进行拼接
+ (NSString *)getCookieSets;

+ (void)clearCookie;

/// 利用iOS 11 API WKHTTPCookieStore解决WKWebView首次请求不携带Cookie的问题
- (void)copyNSHTTPCookieStorageToWKHTTPCookieStoreWithWebView:(WKWebView *)webView completionHandler:(void (^)(void))completionHandler;

@end
