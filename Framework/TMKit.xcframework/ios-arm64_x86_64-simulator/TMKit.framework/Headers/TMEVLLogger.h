//
//  TMEVLLogger.h
//  TMKit
//
//  Created by TMKit on 2022/6/8.
//

#import <Foundation/Foundation.h>
#import "TMEVLEventProtocol.h"
#import "TMEVLUploaderProtocol.h"
#import "TMEVLStorageProtocol.h"
#import "TMEVLConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface TMEVLLogger : NSObject

+ (instancetype)shared;

/// 调试模式，只输出日志，不上报
@property (nonatomic, assign) BOOL isDebugMode;

/// 是否已经完成配置
@property (nonatomic, assign, readonly) BOOL hasSetup;

@property (nonatomic, strong, readonly) id<TMEVLUploaderProtocol> uploader;

/// 绿色通道磁盘存储
@property (nonatomic, strong, readonly) id<TMEVLStorageProtocol> greenStorage;

/// 红色通道磁盘存储
@property (nonatomic, strong, readonly) id<TMEVLStorageProtocol> redStorage;

- (instancetype)init NS_UNAVAILABLE;

- (void)setupWithConfig:(TMEVLConfig *)config uploader:(id<TMEVLUploaderProtocol>)uploader greenStorage:(nullable id<TMEVLStorageProtocol>)greenStorage redStorage:(nullable id<TMEVLStorageProtocol>)redStorage;

- (void)logEvent:(id<TMEVLEventProtocol>)event;

- (void)logEvents:(NSArray<id<TMEVLEventProtocol>> *)events;

@end

NS_ASSUME_NONNULL_END
