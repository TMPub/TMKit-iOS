//
//  TMEVLStorageProtocol.h
//  TMEVL
//
//  Created by TMKit on 2022/6/15.
//

#import "TMEVLEventProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TMEVLStorageProtocol <NSObject>

@required
- (instancetype)initWithPath:(NSString *)path inChannel:(TMEVLChannel)channel;

@property (nonatomic, copy, readonly) NSString *path;
@property (nonatomic, assign, readonly) TMEVLChannel channel;

/// 从队列尾部添加打点Event
/// @param event 打点
- (void)appendEvent:(id<TMEVLEventProtocol>)event;

- (void)appendEvents:(NSArray<id<TMEVLEventProtocol>> *)events;

/// 淘汰策略
/// @param count 限定个数
- (void)trimToCount:(NSUInteger)count;

/// 重制所有发送中的event 变成idle
- (void)resetToPostStateIdle;

/// 查询闲置的（未发送）的events
/// @param count 查询数量
- (NSArray<id<TMEVLEventProtocol>> *)selectIdleEventsWithCount:(NSUInteger)count;

/// 更新打点数据的状态
/// @param newState 更新后的状态
/// @param events 打点数据组
- (void)updatePostState:(TMEVLEventPostState)newState forEvents:(NSArray<id<TMEVLEventProtocol>> *)events;

/// 删除打点数据
/// @param events 打点数据组
- (void)deletePostedEvents:(NSArray<id<TMEVLEventProtocol>> *)events;


@end

NS_ASSUME_NONNULL_END
