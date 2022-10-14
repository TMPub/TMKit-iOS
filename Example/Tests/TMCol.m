//
//  TMCol.m
//  TMKit_Tests
//
//  Created by Frank Du on 2022/7/14.
//  Copyright © 2022 frank-du. All rights reserved.
//

#import "TMCol.h"

@implementation TMCol

+ (NSDictionary *)tm_modelCustomPropertyMapper {
    return @{
        @"colId" : @"identifier",
        @"colType" : @"type",
        @"colArtists" : @"artists"
    };
}

+ (NSDictionary *)tm_modelContainerPropertyGenericClass {
    return @{@"colArtists" : [TMArtist class]};
}

- (BOOL)tm_modelCustomTransformFromDictionary:(NSDictionary *)dic {
    if (![super tm_modelCustomTransformFromDictionary:dic]) return NO;
    
    if (dic && [dic objectForKey:@"type"]) {
        NSString *string = [dic objectForKey:@"type"];
        self.colType = [self.class colTypeFromString:string];
    }
    
    return YES;
}

- (BOOL)tm_modelCustomTransformToDictionary:(NSMutableDictionary *)dic {
    if (![super tm_modelCustomTransformToDictionary:dic]) return NO;
    
    NSString *string = [self.class colTypeToString:self.colType];
    [dic setObject:string forKey:@"type"];
    
    return YES;
}

+ (NSString *)colTypeToString:(TMColType)colType {
    NSString *string;
    switch (colType) {
        case TMColTypeAlbum:
            string = @"ALBUM";
            break;
        case TMColTypePlaylist:
            string = @"PLAYLIST";
            break;
        case TMColTypeNone:
        default:
            string = @"";
            break;
    }
    
    return string;
}

+ (TMColType)colTypeFromString:(NSString *)string {
    if ([string isEqualToString:@"ALBUM"]) return TMColTypeAlbum;
    if ([string isEqualToString:@"PLAYLIST"]) return TMColTypeAlbum;
    
    return TMColTypeNone;
}


@end
