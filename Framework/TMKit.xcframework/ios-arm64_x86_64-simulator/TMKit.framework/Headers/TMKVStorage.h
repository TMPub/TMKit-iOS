//
//  TMKVStorage.h
//  TMKVStorage
//
//  Created by TMKit on 2018/2/7.
//  Copyright © 2018年 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMKVStorageItem : NSObject

@property (nonatomic, strong) NSString *key;                ///< key
@property (nonatomic, strong) NSData *value;                ///< value
@property (nonatomic) NSUInteger size;                             ///< value's size in bytes
@property (nonatomic) NSTimeInterval modTime;                          ///< modification unix timestamp

@end

typedef NS_ENUM(NSUInteger, TMExceptionEventType) {
    TMIOTypeRead = 0, // IO读异常
    TMIOTypeWrite // IO写异常
};

@protocol TMKVStorageDelegate <NSObject>

- (void)didReceiveIOError:(NSError *)error sql:(NSString *)sql path:(NSString *)path ioType:(TMExceptionEventType)ioType;

- (void)didReceiveIOException:(NSException *)exception path:(NSString *)path ioType:(TMExceptionEventType)ioType;

@end

@interface TMKVStorage : NSObject

#pragma mark - Attribute

@property (readonly) NSString *path;

@property (nonatomic, weak) id<TMKVStorageDelegate> delegate;

#pragma mark - Initializer

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

- (instancetype)initWithPath:(NSString *)path NS_DESIGNATED_INITIALIZER;
+ (instancetype)storageWithPath:(NSString *)path;

#pragma mark - Access Methods 带withBlock为异步方法
- (BOOL)containsObjectForKey:(NSString *)key;
- (void)containsObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key, BOOL contains))block;
- (nullable id<NSCoding>)objectForKey:(NSString *)key;
- (void)objectForKey:(NSString *)key withBlock:(void(^)(NSString *key, id<NSCoding> _Nullable object))block;
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key;
///异步不保证写入顺序，但是是线程安全的
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key withBlock:(nullable void(^)(void))block;
- (void)setObjectsForKeys:(NSDictionary *)otherDictionary;
- (void)setObjectsForKeys:(NSDictionary *)otherDictionary withBlock:(nullable void(^)(void))block;

/**
 Sets the contents of the receiving dictionary to entries in a given dictionary.
 All entries are removed from the receiving dictionary (with removeAllObjects), then each entry from otherDictionary added into the receiving dictionary.
 
 @param otherDictionary A dictionary containing the new entries.
 */
//- (void)setDictionary:(NSDictionary<NSString *, id<NSCoding>> *)otherDictionary;
- (void)removeObjectForKey:(NSString *)key;
- (void)removeObjectForKey:(NSString *)key withBlock:(nullable void(^)(NSString *key))block;
- (void)removeObjectsForKeys:(NSArray<NSString *> *)keys;
- (void)removeObjectsForKeys:(NSArray<NSString *> *)keys withBlock:(nullable void(^)(NSArray<NSString *> *keys))block;
- (void)removeAllObjects;
- (void)removeAllObjectsWithBlock:(nullable void(^)(void))block;
- (nullable NSArray<id<NSCoding>> *)allObjects;
- (void)allObjectsWithBlock:(void(^)(NSArray<id<NSCoding>> * _Nullable objects))block;
- (nullable NSArray<NSString *> *)allKeys;
- (void)allKeysWithBlock:(void(^)(NSArray<NSString *> * _Nullable objects))block;
- (nullable NSDictionary<NSString *, id<NSCoding>> *)allKeyObjects;
- (void)allKeyObjectsWithBlock:(void(^)(NSDictionary<NSString *, id<NSCoding>> * _Nullable keyObjects))block;;
- (NSInteger)itemsCount;
- (void)itemsCountWithBlock:(void(^)(NSInteger count))block;

@end

NS_ASSUME_NONNULL_END
