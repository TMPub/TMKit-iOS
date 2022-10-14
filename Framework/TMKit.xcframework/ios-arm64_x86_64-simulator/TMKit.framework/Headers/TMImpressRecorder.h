//
//  TMImpressRecorder.h
//  TMEVL
//
//  Created by TMKit on 2022/6/13.
//

#import <Foundation/Foundation.h>
#import "TMImpressTrackModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TMImpressRecorderDelegate <NSObject>

/// 展示打点成功回调
/// @param model 展示打点关联的元数据
- (void)impressDidRecord:(TMImpressTrackModel *)model;

@end

@interface TMImpressRecorder : NSObject

+ (instancetype)shared;

- (void)setDelegate:(id<TMImpressRecorderDelegate>)delegate;

- (void)addRecord:(NSString *)impressId impressData:(id)impressData;

- (void)removeRecord:(NSString *)impressId;

- (void)clearRecord:(NSString *)impressId;

- (TMImpressTrackModel *)recordByImpressId:(NSString *)impressId;

@end

NS_ASSUME_NONNULL_END
