//
//  TMCookieManager.h
//  TMUtil
//
//  Created by TMKit on 2022/8/10.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

@interface TMCookieManager : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, strong) WKProcessPool *processPool;

+ (NSString *)getCookieValue:(NSString *)domain;

@end
