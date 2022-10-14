//
//  TMClassInfo.h
//  TMModel
//  Evo from YYModel <https://github.com/ibireme/YYModel>
//
//  Created by TMKit on 15/5/9.
//  Copyright © 2018年 TMKit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Type encoding's type.
 */
typedef NS_OPTIONS(NSUInteger, TMEncodingType) {
    TMEncodingTypeMask       = 0xFF, ///< mask of type value
    TMEncodingTypeUnknown    = 0, ///< unknown
    TMEncodingTypeVoid       = 1, ///< void
    TMEncodingTypeBool       = 2, ///< bool
    TMEncodingTypeInt8       = 3, ///< char / BOOL
    TMEncodingTypeUInt8      = 4, ///< unsigned char
    TMEncodingTypeInt16      = 5, ///< short
    TMEncodingTypeUInt16     = 6, ///< unsigned short
    TMEncodingTypeInt32      = 7, ///< int
    TMEncodingTypeUInt32     = 8, ///< unsigned int
    TMEncodingTypeInt64      = 9, ///< long long
    TMEncodingTypeUInt64     = 10, ///< unsigned long long
    TMEncodingTypeFloat      = 11, ///< float
    TMEncodingTypeDouble     = 12, ///< double
    TMEncodingTypeLongDouble = 13, ///< long double
    TMEncodingTypeObject     = 14, ///< id
    TMEncodingTypeClass      = 15, ///< Class
    TMEncodingTypeSEL        = 16, ///< SEL
    TMEncodingTypeBlock      = 17, ///< block
    TMEncodingTypePointer    = 18, ///< void*
    TMEncodingTypeStruct     = 19, ///< struct
    TMEncodingTypeUnion      = 20, ///< union
    TMEncodingTypeCString    = 21, ///< char*
    TMEncodingTypeCArray     = 22, ///< char[10] (for example)
    
    TMEncodingTypeQualifierMask   = 0xFF00,   ///< mask of qualifier
    TMEncodingTypeQualifierConst  = 1 << 8,  ///< const
    TMEncodingTypeQualifierIn     = 1 << 9,  ///< in
    TMEncodingTypeQualifierInout  = 1 << 10, ///< inout
    TMEncodingTypeQualifierOut    = 1 << 11, ///< out
    TMEncodingTypeQualifierBycopy = 1 << 12, ///< bycopy
    TMEncodingTypeQualifierByref  = 1 << 13, ///< byref
    TMEncodingTypeQualifierOneway = 1 << 14, ///< oneway
    
    TMEncodingTypePropertyMask         = 0xFF0000, ///< mask of property
    TMEncodingTypePropertyReadonly     = 1 << 16, ///< readonly
    TMEncodingTypePropertyCopy         = 1 << 17, ///< copy
    TMEncodingTypePropertyRetain       = 1 << 18, ///< retain
    TMEncodingTypePropertyNonatomic    = 1 << 19, ///< nonatomic
    TMEncodingTypePropertyWeak         = 1 << 20, ///< weak
    TMEncodingTypePropertyCustomGetter = 1 << 21, ///< getter=
    TMEncodingTypePropertyCustomSetter = 1 << 22, ///< setter=
    TMEncodingTypePropertyDynamic      = 1 << 23, ///< @dynamic
};

/**
 Get the type from a Type-Encoding string.
 
 @discussion See also:
 https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtTypeEncodings.html
 https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtPropertyIntrospection.html
 
 @param typeEncoding  A Type-Encoding string.
 @return The encoding type.
 */
TMEncodingType TMEncodingGetType(const char *typeEncoding);


/**
 Instance variable information.
 */
@interface TMClassIvarInfo : NSObject
@property (nonatomic, assign, readonly) Ivar ivar;              ///< ivar opaque struct
@property (nonatomic, strong, readonly) NSString *name;         ///< Ivar's name
@property (nonatomic, assign, readonly) ptrdiff_t offset;       ///< Ivar's offset
@property (nonatomic, strong, readonly) NSString *typeEncoding; ///< Ivar's type encoding
@property (nonatomic, assign, readonly) TMEncodingType type;    ///< Ivar's type

/**
 Creates and returns an ivar info object.
 
 @param ivar ivar opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithIvar:(Ivar)ivar;
@end


/**
 Method information.
 */
@interface TMClassMethodInfo : NSObject
@property (nonatomic, assign, readonly) Method method;                  ///< method opaque struct
@property (nonatomic, strong, readonly) NSString *name;                 ///< method name
@property (nonatomic, assign, readonly) SEL sel;                        ///< method's selector
@property (nonatomic, assign, readonly) IMP imp;                        ///< method's implementation
@property (nonatomic, strong, readonly) NSString *typeEncoding;         ///< method's parameter and return types
@property (nonatomic, strong, readonly) NSString *returnTypeEncoding;   ///< return value's type
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *argumentTypeEncodings; ///< array of arguments' type

/**
 Creates and returns a method info object.
 
 @param method method opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithMethod:(Method)method;
@end


/**
 Property information.
 */
@interface TMClassPropertyInfo : NSObject
@property (nonatomic, assign, readonly) objc_property_t property; ///< property's opaque struct
@property (nonatomic, strong, readonly) NSString *name;           ///< property's name
@property (nonatomic, assign, readonly) TMEncodingType type;      ///< property's type
@property (nonatomic, strong, readonly) NSString *typeEncoding;   ///< property's encoding value
@property (nonatomic, strong, readonly) NSString *ivarName;       ///< property's ivar name
@property (nullable, nonatomic, assign, readonly) Class cls;      ///< may be nil
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *protocols; ///< may nil
@property (nonatomic, assign, readonly) SEL getter;               ///< getter (nonnull)
@property (nonatomic, assign, readonly) SEL setter;               ///< setter (nonnull)

/**
 Creates and returns a property info object.
 
 @param property property opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithProperty:(objc_property_t)property;
@end


/**
 Class information for a class.
 */
@interface TMClassInfo : NSObject
@property (nonatomic, assign, readonly) Class cls; ///< class object
@property (nullable, nonatomic, assign, readonly) Class superCls; ///< super class object
@property (nullable, nonatomic, assign, readonly) Class metaCls;  ///< class's meta class object
@property (nonatomic, readonly) BOOL isMeta; ///< whether this class is meta class
@property (nonatomic, strong, readonly) NSString *name; ///< class name
@property (nullable, nonatomic, strong, readonly) TMClassInfo *superClassInfo; ///< super class's class info
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, TMClassIvarInfo *> *ivarInfos; ///< ivars
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, TMClassMethodInfo *> *methodInfos; ///< methods
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, TMClassPropertyInfo *> *propertyInfos; ///< properties

/**
 If the class is changed (for example: you add a method to this class with
 'class_addMethod()'), you should call this method to refresh the class info cache.
 
 After called this method, `needUpdate` will returns `YES`, and you should call 
 'classInfoWithClass' or 'classInfoWithClassName' to get the updated class info.
 */
- (void)setNeedUpdate;

/**
 If this method returns `YES`, you should stop using this instance and call
 `classInfoWithClass` or `classInfoWithClassName` to get the updated class info.
 
 @return Whether this class info need update.
 */
- (BOOL)needUpdate;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param cls A class.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClass:(Class)cls;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param className A class name.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClassName:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
