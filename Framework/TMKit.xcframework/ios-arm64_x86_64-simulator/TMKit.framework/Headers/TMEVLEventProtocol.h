//
//  TMEVLEventProtocol.h
//  TMEVL
//
//  Created by TMKit on 2022/6/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TMEVLChannel) {
    TMEVLChannelRed = 0, // 红色通道，积累一定条数批量上报
    TMEVLChannelGreen = 1, // 绿色通道，单条独立上报
};

typedef NS_ENUM(NSInteger, TMEVLEventPostState) {
    TMEVLEventPostStateNone = -1,     // 默认，无意义，预留
    TMEVLEventPostStateIdle = 0,      // 空闲，未发送
    TMEVLEventPostStatePosting = 1,   // 发送中
    TMEVLEventPostStatePosted = 2,    // 已发送，这个值其实用不到，因为已发送就会删除
};

static inline NSString * TMEVLChannelString (TMEVLChannel channel) {
    switch (channel) {
        case TMEVLChannelRed:
            return @"Red";
        case TMEVLChannelGreen:
            return @"Green";
    }
}

static inline NSString * TMEVLPostStateString (TMEVLEventPostState postState) {
    switch (postState) {
        case TMEVLEventPostStateNone:
            return @"默认";
        case TMEVLEventPostStateIdle:
            return @"空闲";
        case TMEVLEventPostStatePosting:
            return @"发送中";
        case TMEVLEventPostStatePosted:
            return @"已发送";
    }
}

@protocol TMEVLEventProtocol <NSObject>

@required

/// 唯一标识符。每个实例必须唯一
- (NSString *)idf;

/// 通道。详见枚举。
- (TMEVLChannel)channel;

/// 提交状态
- (TMEVLEventPostState)postState;

/// 点位产生时间。时间戳，单位秒
- (uint64_t)genTs;

- (BOOL)onlyForReachable;

@end

NS_ASSUME_NONNULL_END
