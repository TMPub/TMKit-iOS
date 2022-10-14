//
//  TMArtist.m
//  TMKit_Tests
//
//  Created by Frank Du on 2022/7/14.
//  Copyright © 2022 frank-du. All rights reserved.
//

#import "TMArtist.h"

@implementation TMArtist

+ (NSDictionary *)tm_modelCustomPropertyMapper {
    return @{@"artistId" : @"identifier",
             @"artistName" : @"name"
    };
}

@end
