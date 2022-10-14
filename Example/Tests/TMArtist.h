//
//  TMArtist.h
//  TMKit_Tests
//
//  Created by Frank Du on 2022/7/14.
//  Copyright © 2022 frank-du. All rights reserved.
//

#import <TMKit/TMKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMArtist : TMModelBase

@property (nonatomic, assign) NSUInteger artistId;
@property (nonatomic, copy) NSString *artistName;

@end

NS_ASSUME_NONNULL_END
