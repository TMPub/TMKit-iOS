//
//  TMManager.h
//  TMetworking
//
//  Created by TMKit on 2022/2/14.
//

#import <Foundation/Foundation.h>
#import "TMRequest.h"
@class TMResponse;

NS_ASSUME_NONNULL_BEGIN

typedef void(^TMCompletionBlock)(TMResponse *response);
typedef void(^TMProgressBlock)(NSProgress *progress);

@interface TMRequestManager : NSObject

+ (instancetype)sharedManager;

- (instancetype)init OBJC_UNAVAILABLE("use '+sharedManager' instead");
+ (instancetype)new OBJC_UNAVAILABLE("use '+sharedManager' instead");

- (NSUInteger)startRequest:(__kindof TMRequest *)request
            uploadProgress:(nullable TMProgressBlock)uploadProgress
          downloadProgress:(nullable TMProgressBlock)downloadProgress
                completion:(nullable TMCompletionBlock)completion;

- (void)cancelRequestWithTaskId:(NSUInteger)taskId;
- (void)cancelRequestWithTaskIds:(NSSet<NSNumber *> *)taskIds;

@end

NS_ASSUME_NONNULL_END
