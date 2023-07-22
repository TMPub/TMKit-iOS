//
//  NSObject+TMSemaphore.h
//  TMKit
//
//  Created by TMKit on 2022/8/22.
//

#import <Foundation/Foundation.h>

#define tmSemaphoreLock [self tm_Lock];

#define tmSemaphoreUnlock [self tm_Unlock];

NS_ASSUME_NONNULL_BEGIN

typedef void (^SemaphoreLockBlock) (void);
/// 通过 Block 方式加锁
extern void tmSemaphoreAutoLock(NSObject * target, SemaphoreLockBlock block);

@interface NSObject (Semaphore)

/// 加锁, 内部定义了 dispatch_semaphore_create(1)
- (void)tm_Lock;

/// 解锁, 内部定义了 dispatch_semaphore_create(1)
- (void)tm_Unlock;

@end

NS_ASSUME_NONNULL_END
