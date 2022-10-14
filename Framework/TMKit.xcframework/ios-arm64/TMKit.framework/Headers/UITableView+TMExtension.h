//
//  UITableView+TMExtension.h
//  TMExtensions
//
//  Created by TMKit on 2022/7/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UITableView (TMExtension)

- (void)tm_scrollToFirstIndex;

- (NSArray *)tm_visibleSectionHeaders;

- (NSArray *)tm_visibleSectionFooters;

@end

NS_ASSUME_NONNULL_END
