//
//  TMGroupingHelper.h
//  TMUtil
//
//  Created by TMKit on 2022/8/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMGroupingResult : NSObject

@property (nonatomic, copy) NSString *groupTitle;
@property (nonatomic, strong) NSArray *groupItems;

@end

@interface TMGroupingHelper : NSObject

+ (NSArray<NSString *> *)groupTitlesWithHashKeyIncludes:(BOOL)hashKeyIncludes;

+ (NSArray<TMGroupingResult *> *)groupingArray:(NSArray *)sortedObjs key:(NSString *)key hashKeyIncludes:(BOOL)hashKeyIncludes;

+ (nullable TMGroupingResult *)groupResultWithGroupTitle:(NSString *)groupTitle inGroupResults:(NSArray<TMGroupingResult *> *)groupResults;

+ (NSArray<TMGroupingResult *> *)groupingArray:(NSArray *)sortedObjs key:(NSString *)key hashKeyIncludes:(BOOL)hashKeyIncludes filterEmpty:(BOOL)filter;

@end

NS_ASSUME_NONNULL_END
