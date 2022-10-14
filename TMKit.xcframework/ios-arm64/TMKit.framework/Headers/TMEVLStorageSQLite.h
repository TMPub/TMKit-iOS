//
//  TMEVLStorageSQLite.h
//  TMEVL
//
//  Created by TMKit on 2022/6/13.
//

#import <Foundation/Foundation.h>
#import "TMEVLStorageProtocol.h"
#import "TMEVLEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface TMEVLStorageSQLite : NSObject <TMEVLStorageProtocol>

- (instancetype)init NS_UNAVAILABLE;

// 从队列尾部添加埋点
/// @param event 埋点实例
- (void)appendEvent:(TMEVLEvent *)event;

/// 从队列尾部批量添加埋点
/// @param events 批量埋点实例
- (void)appendEvents:(NSArray <TMEVLEvent *> *)events;

/// 淘汰策略
/// @param count 限定个数
- (void)trimToCount:(NSUInteger)count;

/// 重制所有发送中的event 变成idle
- (void)resetToPostStateIdle;

/// 查询闲置的（未发送）的events
/// @param count 查询数量
- (NSArray<TMEVLEvent *> *)selectIdleEventsWithCount:(NSUInteger)count;

/// 更新打点数据的状态
/// @param newState 更新后的状态
/// @param events 打点数据组
- (void)updatePostState:(TMEVLEventPostState)newState forEvents:(NSArray<TMEVLEvent *> *)events;

/// 删除打点数据
/// @param events 打点数据组
- (void)deletePostedEvents:(NSArray<TMEVLEvent *> *)events;

@end

NS_ASSUME_NONNULL_END
