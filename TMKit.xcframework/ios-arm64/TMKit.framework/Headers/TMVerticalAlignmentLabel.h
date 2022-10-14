//
//  TMVerticalAlignmentLabel.h
//  TMUI
//
//  Created by TMKit on 2022/7/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TMVerticalAlignment) {
    TMVerticalAlignmentTop = 0,
    TMVerticalAlignmentMiddle = 1,
    TMVerticalAlignmentBottom = 2,
};

@interface TMVerticalAlignmentLabel : UILabel

@property (nonatomic, assign) TMVerticalAlignment verticalAlignment;

@end

NS_ASSUME_NONNULL_END
