//
//  TMIdGenerator.h
//  TMetworking
//
//  Created by TMKit on 2022/4/12.
//  Copyright © 2022 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMIdGenerator : NSObject

+ (instancetype)sharedIdGenerator;

- (NSUInteger)newApiId;

@end

NS_ASSUME_NONNULL_END
