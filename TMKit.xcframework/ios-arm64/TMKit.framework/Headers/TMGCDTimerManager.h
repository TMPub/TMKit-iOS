//
//  TMGCDTimerManager.h
//  TMUtil
//
//  Created by TMKit on 2018/2/7.
//  Copyright © 2018年 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SharedGCDTimerManager     [TMGCDTimerManager sharedManager]

@interface TMGCDTimerManager : NSObject

+ (instancetype)sharedManager;

/**
 *  @author TMKit, 15-10-26 18:10:40
 *
 *  启动一个timer
 *
 *  @param timerName timer名称，唯一标识
 *  @param interval  执行间隔时间，单位s
 *  @param queue     timer所在队列，传入nil将自动放到一个子线程队列中
 *  @param repeats   是否循环调用
 *  @param block    timer要执行的方法
 */
- (void)scheduledTimerWithName:(NSString *)timerName interval:(NSTimeInterval)interval queue:(dispatch_queue_t)queue repeats:(BOOL)repeats block:(dispatch_block_t)block;

/**
 *  @author TMKit, 15-10-26 18:10:59
 *
 *  撤销一个timer
 *
 *  @param timerName timer名称，唯一标识
 */
- (void)cancelTimerWithName:(NSString *)timerName;

/// 重置一个timer
/// @param timerName timer名称，唯一标识
/// @param timeInterval  执行间隔时间，单位s
- (void)resetTimerWithName:(NSString *)timerName interval:(double)timeInterval;

/**
 *  @author TMKit, 15-10-26 18:10:12
 *
 *  撤销所有timer
 */
- (void)cancelAllTimer;

/**
 *  @author TMKit, 16-07-06 19:07
 *
 *  是否存在指定timer
 *
 *  @param timerName timer名称，唯一标识
 *
 *  @return 是否存在结果
 */
- (BOOL)hasTimerWithName:(NSString *)timerName;

- (void)dispatchTimer:(id)target interval:(double)timeInterval handler:(void (^)(dispatch_source_t))handler timerName:(NSString *)timerName queue:(dispatch_queue_t)queue;

- (void)dispatchTimer:(id)target timerName:(NSString *)timerName queue:(dispatch_queue_t)queue totalTime:(double)toalTime interval:(double)timeInterval completeHandler:(void (^)(dispatch_source_t))completeHandler;

- (void)dispatchTimer:(id)target timerName:(NSString *)timerName queue:(dispatch_queue_t)queue totalTime:(double)toalTime interval:(double)timeInterval completeHandler:(void (^)(dispatch_source_t))completeHandler countingHander:(void(^)(double))countingHander;

@end
