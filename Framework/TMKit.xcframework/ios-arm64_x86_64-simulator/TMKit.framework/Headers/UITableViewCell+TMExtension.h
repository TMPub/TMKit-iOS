//
//  UITableViewCell+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2021/7/29.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UITableViewCell (TMExtension)

@property (nonatomic, copy) void(^tm_cellSubviewActionBlock)(id aView,id value,int type);

+ (NSString *)tm_reuseIdentifier;

+ (NSString *)tm_reuseIdentifier_1;

- (void)tm_setSeparatorInsetByLeft:(CGFloat)left;

@end

NS_ASSUME_NONNULL_END
