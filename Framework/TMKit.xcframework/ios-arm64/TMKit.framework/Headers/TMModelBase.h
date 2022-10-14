//
//  TMModelBase.h
//  TMKit
//
//  Created by TMKit on 2018/1/31.
//  Copyright © 2018年 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSObject+TMModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TMModelBase : NSObject <NSCoding, NSCopying>

/**
 Custom property mapper.
 
 @discussion If the key in JSON/Dictionary does not match to the model's property name,
 implements this method and returns the additional mapper.
 
 Example:
    
    json:
        {
            "n":"Harry Pottery",
            "p": 256,
            "ext" : {
                "desc" : "A book written by J.K.Rowling."
            },
            "ID" : 100010
        }
 
    model:
    @code
        @interface TMBook : NSObject
        @property NSString *name;
        @property NSInteger page;
        @property NSString *desc;
        @property NSString *bookID;
        @end
        
        @implementation TMBook
        + (NSDictionary *)tm_modelCustomPropertyMapper {
            return @{@"name"  : @"n",
                     @"page"  : @"p",
                     @"desc"  : @"ext.desc",
                     @"bookID": @[@"id", @"ID", @"book_id"]};
        }
        @end
     @endcode
 
 @return A custom mapper for properties.
 */
+ (nullable NSDictionary<NSString *, id> *)tm_modelCustomPropertyMapper;

/**
 The generic class mapper for container properties.
 
 @discussion If the property is a container object, such as NSArray/NSSet/NSDictionary,
 implements this method and returns a property->class mapper, tells which kind of
 object will be add to the array/set/dictionary.
 
  Example:
  @code
        @class TMShadow, TMBorder, TMAttachment;
 
        @interface TMAttributes
        @property NSString *name;
        @property NSArray *shadows;
        @property NSSet *borders;
        @property NSDictionary *attachments;
        @end
 
        @implementation TMAttributes
        + (NSDictionary *)tm_modelContainerPropertyGenericClass {
            return @{@"shadows" : [TMShadow class],
                     @"borders" : TMBorder.class,
                     @"attachments" : @"TMAttachment" };
        }
        @end
  @endcode
 
 @return A class mapper.
 */
+ (nullable NSDictionary<NSString *, id> *)tm_modelContainerPropertyGenericClass;

/**
 All the properties in blacklist will be ignored in model transform process.
 Returns nil to ignore this feature.
 
 @return An array of property's name.
 */
+ (nullable NSArray<NSString *> *)tm_modelPropertyBlacklist;

/**
 If a property is not in the whitelist, it will be ignored in model transform process.
 Returns nil to ignore this feature.
 
 @return An array of property's name.
 */
+ (nullable NSArray<NSString *> *)tm_modelPropertyWhitelist;

/**
 This method's behavior is similar to `- (BOOL)tm_modelCustomTransformFromDictionary:(NSDictionary *)dic;`,
 but be called before the model transform.
 
 @discussion If the model implements this method, it will be called before
 `+modelWithJSON:`, `+modelWithDictionary:`, `-modelSetWithJSON:` and `-modelSetWithDictionary:`.
 If this method returns nil, the transform process will ignore this model.
 
 @param dic  The json/kv dictionary.
 
 @return Returns the modified dictionary, or nil to ignore this model.
 */
- (NSDictionary *)tm_modelCustomWillTransformFromDictionary:(NSDictionary *)dic;

/**
 If the default json-to-model transform does not fit to your model object, implement
 this method to do additional process. You can also use this method to validate the
 model's properties.
 
 @discussion If the model implements this method, it will be called at the end of
 `+modelWithJSON:`, `+modelWithDictionary:`, `-modelSetWithJSON:` and `-modelSetWithDictionary:`.
 If this method returns NO, the transform process will ignore this model.
 
 @param dic  The json/kv dictionary.
 
 @return Returns YES if the model is valid, or NO to ignore this model.
 */
- (BOOL)tm_modelCustomTransformFromDictionary:(NSDictionary *)dic;

/**
 If the default model-to-json transform does not fit to your model class, implement
 this method to do additional process. You can also use this method to validate the
 json dictionary.
 
 @discussion If the model implements this method, it will be called at the end of
 `-modelToJSONObject` and `-modelToJSONString`.
 If this method returns NO, the transform process will ignore this json dictionary.
 
 @param mdic  The json dictionary.
 
 @return Returns YES if the model is valid, or NO to ignore this model.
 */
- (BOOL)tm_modelCustomTransformToDictionary:(NSMutableDictionary *)mdic;

@end

NS_ASSUME_NONNULL_END
