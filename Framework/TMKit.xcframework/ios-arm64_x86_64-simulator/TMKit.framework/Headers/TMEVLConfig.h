//
//  TMEVLConfig.h
//  TMEVL
//
//  Created by TMKit on 2022/6/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 埋点分2条通道：
 ①红色通道，走RedQueue，积累一定条数上报
 ②绿色通道，走GreenQueue，单条立即上报
 
 MemoryCache内存缓存，Storage磁盘缓存
 
 流程示意：
 event产生 -> 加入event到MemoryCache，并计数 -> 达到thresholdForMemoryCacheSaving -> 写入Storage（磁盘缓存）
 
 累积加入到MemoryCache达到上传阈值 -> 读取Storage中的数据（数据长度为） -> 提交上传
 
 */

@interface TMEVLGreenChannelConfig : NSObject

/// 每次uploading，提交Event的最大数量
@property (nonatomic, assign) NSUInteger maxEventsCountPerUploading;

/// Storage最大存储event条数。该限制非实时，只会在重新启动时候做检测并淘汰。
@property (nonatomic, assign) NSInteger maxEventsCountOfStorage;

@end

@interface TMEVLRedChannelConfig : NSObject

/// MemoryCache中event条数达到该阈值后，触发写入Storage，默认是10
@property (nonatomic, assign) NSUInteger thresholdForMemoryCacheStoring;

/// 触发上传行为的阈值。到达这个数量，则触发上传，默认是20
@property (nonatomic, assign) NSUInteger thresholdForUploading;

/// 每次uploading，提交Event的最大数量，默认是50
@property (nonatomic, assign) NSUInteger maxEventsCountPerUploading;

/// Storage最大存储event条数。该限制非实时，只会在重新启动时候做检测并淘汰。默认是2000
@property (nonatomic, assign) NSInteger maxEventsCountOfStorage;

@end

@interface TMEVLConfig : NSObject

@property (nonatomic, strong, readonly) TMEVLRedChannelConfig *rConfig;
@property (nonatomic, strong, readonly) TMEVLGreenChannelConfig *gConfig;


- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithGreenChannelConfig:(TMEVLGreenChannelConfig *)gConfig redChannelConfig:(TMEVLRedChannelConfig *)rConfig;

@end

NS_ASSUME_NONNULL_END
