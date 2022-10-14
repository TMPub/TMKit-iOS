//
//  TMStringPrivate.h
//  TMKit
//
//  Created by TMKit on 2022/8/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMStringPrivate : NSObject

+ (nullable id)substring:(id)aString avoidBreakingUpCharacterSequencesFromIndex:(NSUInteger)index lessValue:(BOOL)lessValue countingNonASCIICharacterAsTwo:(BOOL)countingNonASCIICharacterAsTwo;
+ (nullable id)substring:(id)aString avoidBreakingUpCharacterSequencesToIndex:(NSUInteger)index lessValue:(BOOL)lessValue countingNonASCIICharacterAsTwo:(BOOL)countingNonASCIICharacterAsTwo;
+ (nullable id)substring:(id)aString avoidBreakingUpCharacterSequencesWithRange:(NSRange)range lessValue:(BOOL)lessValue countingNonASCIICharacterAsTwo:(BOOL)countingNonASCIICharacterAsTwo;
+ (nullable id)string:(id)aString avoidBreakingUpCharacterSequencesByRemoveCharacterAtIndex:(NSUInteger)index;

@end

NS_ASSUME_NONNULL_END
