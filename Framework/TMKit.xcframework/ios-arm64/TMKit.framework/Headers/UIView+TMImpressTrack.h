//
//  UIView+TMImpressTrack.h
//  TMEVL
//
//  Created by TMKit on 2022/6/13.
//

#import <UIKit/UIKit.h>
#import "TMImpressTrackModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^TMImpressTrackBlock)(BOOL visible);

@interface UIView (TMImpressTrack)

/// 配置展示监测的唯一 ID 和展示打点的数据
/// @param impressId 唯一 ID，由调用方保证其唯一性
/// @param impressData 展示打点的数据，展示打点成功后会回调给上层
- (void)configImpressId:(NSString *)impressId impressData:(id)impressData;

/// 配置展示监测的唯一 ID 和展示打点的数据
/// @param impressId 唯一 ID，由调用方保证其唯一性
/// @param seconds 展示成功所需要的秒数
/// @param proportion 展示成功的屏幕显示比例
/// @param impressData 展示打点的数据，展示打点成功后会回调给上层
/// @param checkAfterLeastSeconds 是否启用定时器检查，请只在高精度场景下调用
- (void)configImpressId:(NSString *)impressId
    impressLeastSeconds:(NSTimeInterval)seconds
 impressLeastProportion:(CGFloat)proportion
            impressData:(id)impressData
 checkAfterLeastSeconds:(BOOL)checkAfterLeastSeconds;

/// 内部方法
- (void)tm_checkScrollViewSubViewsVisible;

@property (nonatomic, copy, nullable) TMImpressTrackBlock tm_visibleBlock;

/// 内部方法
+ (void)tmSwizzle;

@end

NS_ASSUME_NONNULL_END
