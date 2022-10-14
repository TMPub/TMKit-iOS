//
//  LogUploader.h
//  TMEVL
//
//  Created by TMKit on 2022/6/15.
//

#import <Foundation/Foundation.h>
#import "TMEVLUploaderProtocol.h"
#import "TMServiceProtocol.h"
#import "TMEVLEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface TMEVLUploader : NSObject <TMEVLUploaderProtocol>

- (instancetype)initWithApiService:(id<TMServiceProtocol>)service uploadPath:(NSString *)uploadPath;

- (void)attemptUploadingEvents:(NSArray<TMEVLEvent *> *)idleEvents inChannel:(TMEVLChannel)channel completion:(TMEVLUploadingEventsBlock)completion;

@end

NS_ASSUME_NONNULL_END
