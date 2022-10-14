//
//  TMImpressTrackModel.h
//  TMEVL
//
//  Created by TMKit on 2022/6/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ImpressCompletionBlock)(void);

@interface TMImpressTrackModel : NSObject

@property (nonatomic, copy) NSString *impressId;

@property (nonatomic, strong, nullable) id impressData;

@property (nonatomic, assign) NSTimeInterval startTimeInterval;

@property (nonatomic, assign) NSTimeInterval impressSeconds;

@property (nonatomic, strong) ImpressCompletionBlock impressCompletionBlock;

- (instancetype)initWithImpressId:(NSString *)impressId;

@end

NS_ASSUME_NONNULL_END
