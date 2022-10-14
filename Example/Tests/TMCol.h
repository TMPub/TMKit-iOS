//
//  TMCol.h
//  TMKit_Tests
//
//  Created by Frank Du on 2022/7/14.
//  Copyright © 2022 frank-du. All rights reserved.
//

#import "TMBaseCol.h"
#import "TMArtist.h"

typedef NS_ENUM(NSUInteger, TMColType) {
    TMColTypeNone = 0,
    TMColTypeAlbum,
    TMColTypePlaylist
};

NS_ASSUME_NONNULL_BEGIN

@interface TMCol : TMBaseCol

@property (nonatomic, assign) TMColType colType;
@property (nonnull, strong) NSArray<TMArtist *> *colArtists;

@end

NS_ASSUME_NONNULL_END
