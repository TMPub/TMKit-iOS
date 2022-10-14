//
//  TMEVLUploaderProtocol.h
//  TMEVL
//
//  Created by TMKit on 2022/6/15.
//

#import "TMEVLEventProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^TMEVLUploadingEventsBlock)(BOOL success);
@protocol TMEVLUploaderProtocol <NSObject>

@optional
- (void)attemptUploadingEvents:(NSArray<id<TMEVLEventProtocol>> *)idleEvents inChannel:(TMEVLChannel)channel completion:(TMEVLUploadingEventsBlock)completion;

@end

NS_ASSUME_NONNULL_END
