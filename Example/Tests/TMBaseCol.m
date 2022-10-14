//
//  TMBaseCol.m
//  TMKit_Tests
//
//  Created by Frank Du on 2022/7/14.
//  Copyright © 2022 frank-du. All rights reserved.
//

#import "TMBaseCol.h"

@implementation TMBaseCol

+ (NSDictionary *)tm_modelCustomPropertyMapper {
    return @{@"colId" : @"identifier",
             @"colName" : @"name"
    };
}

@end
