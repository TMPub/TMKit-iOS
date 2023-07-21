//
//  TMMacro.h
//  TMKit
//
//  Created by TMKit on 2021/7/28.
//

#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIKit.h>

#pragma mark -  ============================ Color ============================
#define UIColorFromHexWithAlpha(hexValue,a) [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16))/255.0 green:((float)((hexValue & 0xFF00) >> 8))/255.0 blue:((float)(hexValue & 0xFF))/255.0 alpha:a]
#define UIColorFromHex(hexValue)            UIColorFromHexWithAlpha(hexValue,1.0)
#define UIColorFromRGBA(r,g,b,a)            [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define UIColorFromRGB(r,g,b)               UIColorFromRGBA(r,g,b,1.0)

#pragma mark -  ============================ Size ============================
#define SCREEN_WIDTH [[UIScreen mainScreen] bounds].size.width
#define SCREEN_HEIGHT [[UIScreen mainScreen] bounds].size.height

#define SAFE_BOTTOM_MARGIN \
({CGFloat safeAreaBottom = 0;\
if (@available(iOS 11.0, *)) {\
safeAreaBottom = [UIApplication sharedApplication].delegate.window.safeAreaInsets.bottom;\
}\
(safeAreaBottom);})

#define STATUS_BAR_HEIGHT ([[TMDeviceUtil shareUtil] statusBarHeightConstant])
#define NAVIGATION_BAR_HEIGHT  (44.f)
#define TOP_BAR_HEIGHT (STATUS_BAR_HEIGHT + NAVIGATION_BAR_HEIGHT)
#define TAB_BAR_HEIGHT (56.f)

#pragma mark -  ============================ Device ============================
#define TARGETED_DEVICE_IS_IPHONE UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone
#define TARGETED_DEVICE_IS_IPHONE_568 (TARGETED_DEVICE_IS_IPHONE && SCREEN_HEIGHT == 568) // 5/5S/5C/SE
#define TARGETED_DEVICE_IS_IPHONE_667 (TARGETED_DEVICE_IS_IPHONE && SCREEN_HEIGHT == 667) // 6/6S/7/7S/8/SE2
#define TARGETED_DEVICE_IS_IPHONE_693 (TARGETED_DEVICE_IS_IPHONE && SCREEN_HEIGHT == 693) // 12 mini 放大模式
#define TARGETED_DEVICE_IS_IPHONE_736 (TARGETED_DEVICE_IS_IPHONE && SCREEN_HEIGHT == 736) // 6P/6SP/7P/7SP/8P
#define TARGETED_DEVICE_IS_IPHONE_780 (TARGETED_DEVICE_IS_IPHONE && SCREEN_HEIGHT == 780) // 12 mini
#define TARGETED_DEVICE_IS_IPHONE_812 (TARGETED_DEVICE_IS_IPHONE && SCREEN_HEIGHT == 812) // X/XS/11 Pro
#define TARGETED_DEVICE_IS_IPHONE_844 (TARGETED_DEVICE_IS_IPHONE && SCREEN_HEIGHT == 844) // 12/12 Pro
#define TARGETED_DEVICE_IS_IPHONE_896 (TARGETED_DEVICE_IS_IPHONE && SCREEN_HEIGHT == 896) // XR/XS Max/11/11 Pro Max
#define TARGETED_DEVICE_IS_IPHONE_926 (TARGETED_DEVICE_IS_IPHONE && SCREEN_HEIGHT == 926) // 12 Pro Max

// 320 除了 4/4s/5/5s 之外，还会出现在 X/XS/11Pro/12Mini/13Mini/12/12Pro/13/13Pro 等设备的放大模式上
#define TARGETED_DEVICE_IS_IPHONE_WIDTH_320 (TARGETED_DEVICE_IS_IPHONE && SCREEN_WIDTH == 320)

#define TARGETED_DEVICE_IS_ALL_SCREEN \
({BOOL isAllScreen = NO;\
if (@available(iOS 11.0, *)) {\
isAllScreen = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(isAllScreen);})  // 是否是全面屏

#define MARK_DEPRECATED(DESCRIPTION) __attribute__((deprecated(DESCRIPTION)))

#pragma mark -  ============================ Scale ============================
#define kScale_W414 (SCREEN_WIDTH / 414.f)
#define kScale(X) (kScale_W414 * X)
#define kShrink(X) (X * MIN(1, kScale_W414))
#define ScreenScale ([[UIScreen mainScreen] scale])
#define PT_OF_1PX (1.0 / [[UIScreen mainScreen] scale])

#pragma mark -  ============================ Init ============================
#define TMLazyInitObject(_type_, _ivar_) \
- (_type_ *)_ivar_ { \
if (! _##_ivar_) { \
_##_ivar_ = [[_type_ alloc] init]; \
} \
return _##_ivar_; \
}

#pragma mark -  ============================ weakify, strongify ============================
#ifndef weakify
    #if DEBUG
        #if __has_feature(objc_arc)
            #define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
        #else
            #define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
        #endif
    #else
        #if __has_feature(objc_arc)
            #define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
        #else
            #define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
        #endif
    #endif
#endif

#ifndef strongify
    #if DEBUG
        #if __has_feature(objc_arc)
            #define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
        #else
            #define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
        #endif
    #else
        #if __has_feature(objc_arc)
            #define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
        #else
            #define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
        #endif
    #endif
#endif

#pragma mark -  ============================ NOTIFICATION ============================
#define RECEIVE_NOTIFICATION(__sel, __name) \
[[NSNotificationCenter defaultCenter] addObserver:self selector:__sel name:__name object:nil]

#define POST_NOTIFICATION_ON_MAIN( __name, __object, __userInfo) { \
dispatch_async(dispatch_get_main_queue(), ^{ \
[[NSNotificationCenter defaultCenter] postNotificationName:__name object:__object userInfo:__userInfo]; \
}); \
}

#pragma mark -  ============================ safe thread ============================
#ifndef dispatch_main_async_safe
#define dispatch_main_async_safe(block)\
if (strcmp(dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL), dispatch_queue_get_label(dispatch_get_main_queue())) == 0) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}
#endif

//safe thread
#define tm_dispatch_main_sync_safe(block)\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_sync(dispatch_get_main_queue(), block);\
}

#pragma mark -  ============================ Lock ============================
#define SEMAPHORELOCK(_lock,...) dispatch_semaphore_wait(_lock, DISPATCH_TIME_FOREVER); \
__VA_ARGS__; \
dispatch_semaphore_signal(_lock);

#pragma mark -  ============================ 字符串判空 ============================
#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || ([str isKindOfClass:[NSString class]] && [str length] < 1) ? YES : NO)

#define kStringIsEmptyByByTrimSpace(str) (str == nil || [str isKindOfClass:[NSNull class]] || ([str isKindOfClass:[NSString class]] && str.tm_isEmptyStringByTrimingSpace))
/// 字符串如果为 nil 的话，使用空字符串
#define STRING_OR_EMPTY(A)  ({ __typeof__(A) __a = (A); __a ? __a : @""; })
/// 判断对象是否为 nil 或 NUNull
#define IsNilOrNull(_ref)   (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]))

#define kDicIsEmpty(dic) (dic == nil || ![dic isKindOfClass:[NSDictionary class]] || [dic count] < 1 ? YES : NO)

/** @brief Returns YES if both arguments are `nil` or equal, NO otherwise. */
NS_INLINE BOOL tmBothNilOrEqual(id first, id second) {
    return (first == nil && second == nil) || ([first isEqual:second]);
}

#pragma mark -  ============================ typedef ============================
typedef void (^TMVoidBlock)(void);

typedef void (^TMBoolBlock)(BOOL boolen);

typedef void(^oc_defer_block_t)(void);
NS_INLINE void nob_deferFunc(__strong oc_defer_block_t *blockRef) {
    oc_defer_block_t actualBlock = *blockRef;
    actualBlock();
}

#define _oc_macro_concat(a, b) a##b
#define oc_macro_concat(a, b) _oc_macro_concat(a, b)

#define oc_defer(deferBlock) \
__strong oc_defer_block_t oc_macro_concat(__oc_stack_defer_block_, __LINE__) __attribute__((cleanup(nob_deferFunc), unused)) = deferBlock

NS_INLINE NSException * tryBlock(void(^ tryBlock)(void)) {
    @try {
        tryBlock();
    }
    @catch (NSException *exception) {
        return exception;
    }
    return nil;
}

#define NSDICT(firstKey, ...) NSDictionaryWithKeysAndValues(firstKey, __VA_ARGS__)

static __attribute__ ((sentinel, unused)) NSDictionary * NSDictionaryWithKeysAndValues(id firstKey, ...) {
    va_list kvl;
    va_start(kvl, firstKey);
    
    size_t dyn_capacity;
    size_t dyn_count;
    __unsafe_unretained id * dyn_keys;
    __unsafe_unretained id * dyn_values;
    id key, value;
    
    
    // Do up to 16 using static allocation
    {
        NSUInteger static_capacity = 16;
        __unsafe_unretained id keys[static_capacity];
        __unsafe_unretained id values[static_capacity];
        NSUInteger count = 0;
        
        key = firstKey;
        value = va_arg(kvl, id);
        
        do {
            if (value) {
                keys[count] = key;
                values[count] = value;
                count++;
            }
            
            key = va_arg(kvl, id);
            if (!key) {
                va_end(kvl);
                return [NSDictionary dictionaryWithObjects:values forKeys:keys count:count];
            }
            value = va_arg(kvl, id);
            
            
            if (count == static_capacity) {
                dyn_capacity = static_capacity * 2;
                dyn_count  = static_capacity;
                dyn_keys   = (__unsafe_unretained id *)malloc(dyn_capacity * sizeof(id));
                dyn_values = (__unsafe_unretained id *)malloc(dyn_capacity * sizeof(id));
                
                memcpy(dyn_keys, keys, static_capacity * sizeof(id));
                memcpy(dyn_values, values, static_capacity * sizeof(id));
                break;
            }
            
        } while (1);
    }
    
    
    // For > 16 entries
    do {
        if (value) {
            dyn_keys[dyn_count] = key;
            dyn_values[dyn_count] = value;
            dyn_count++;
            if (dyn_count == dyn_capacity) {
                dyn_capacity += 16;
                dyn_keys = (__unsafe_unretained id *)realloc(dyn_keys, dyn_capacity * sizeof(id));
                dyn_values = (__unsafe_unretained id *)realloc(dyn_values, dyn_capacity * sizeof(id));
            }
        }
        
        key = va_arg(kvl, id);
        if (!key) break;
        value = va_arg(kvl, id);
    } while (1);
    
    va_end(kvl);
    
    NSDictionary * dict = [NSDictionary dictionaryWithObjects:dyn_values forKeys:dyn_keys count:dyn_count];
    free(dyn_keys);
    free(dyn_values);
    return dict;
}

#pragma mark -  ============================ CG ============================
/**
 *  某些地方可能会将 CGFLOAT_MIN 作为一个数值参与计算（但其实 CGFLOAT_MIN 更应该被视为一个标志位而不是数值），可能导致一些精度问题，所以提供这个方法快速将 CGFLOAT_MIN 转换为 0
 *  issue: https://github.com/Tencent/QMUI_iOS/issues/203
 */
CG_INLINE CGFloat
removeFloatMin(CGFloat floatValue) {
    return floatValue == CGFLOAT_MIN ? 0 : floatValue;
}

/**
 *  基于指定的倍数，对传进来的 floatValue 进行像素取整。若指定倍数为0，则表示以当前设备的屏幕倍数为准。
 *
 *  例如传进来 “2.1”，在 2x 倍数下会返回 2.5（0.5pt 对应 1px），在 3x 倍数下会返回 2.333（0.333pt 对应 1px）。
 */
CG_INLINE CGFloat
flatSpecificScale(CGFloat floatValue, CGFloat scale) {
    floatValue = removeFloatMin(floatValue);
    scale = scale ?: ScreenScale;
    CGFloat flattedValue = ceil(floatValue * scale) / scale;
    return flattedValue;
}

/**
 *  基于当前设备的屏幕倍数，对传进来的 floatValue 进行像素取整。
 *
 *  注意如果在 Core Graphic 绘图里使用时，要注意当前画布的倍数是否和设备屏幕倍数一致，若不一致，不可使用 flat() 函数，而应该用 flatSpecificScale
 */
CG_INLINE CGFloat
flat(CGFloat floatValue) {
    return flatSpecificScale(floatValue, 0);
}

/**
 *  类似flat()，只不过 flat 是向上取整，而 floorInPixel 是向下取整
 */
CG_INLINE CGFloat
floorInPixel(CGFloat floatValue) {
    floatValue = removeFloatMin(floatValue);
    CGFloat resultValue = floor(floatValue * ScreenScale) / ScreenScale;
    return resultValue;
}

CG_INLINE BOOL
between(CGFloat minimumValue, CGFloat value, CGFloat maximumValue) {
    return minimumValue < value && value < maximumValue;
}

CG_INLINE BOOL
betweenOrEqual(CGFloat minimumValue, CGFloat value, CGFloat maximumValue) {
    return minimumValue <= value && value <= maximumValue;
}

/**
 *  调整给定的某个 CGFloat 值的小数点精度，超过精度的部分按四舍五入处理。
 *
 *  例如 CGFloatToFixed(0.3333, 2) 会返回 0.33，而 CGFloatToFixed(0.6666, 2) 会返回 0.67
 *
 *  @warning 参数类型为 CGFloat，也即意味着不管传进来的是 float 还是 double 最终都会被强制转换成 CGFloat 再做计算
 *  @warning 该方法无法解决浮点数精度运算的问题，如需做浮点数的 == 判断，可用下方的 CGFloatEqualToFloat()
 */
CG_INLINE CGFloat
CGFloatToFixed(CGFloat value, NSUInteger precision) {
    NSString *formatString = [NSString stringWithFormat:@"%%.%@f", @(precision)];
    NSString *toString = [NSString stringWithFormat:formatString, value];
    #if CGFLOAT_IS_DOUBLE
    CGFloat result = [toString doubleValue];
    #else
    CGFloat result = [toString floatValue];
    #endif
    return result;
}

/**
 用于两个 CGFloat 值之间的比较运算，支持 ==、>、<、>=、<= 5种，内部会将浮点数转成整型，从而避免浮点数精度导致的判断错误。
 
 CGFloatEqualToFloatWithPrecision()
 CGFloatEqualToFloat()
 CGFloatMoreThanFloatWithPrecision()
 CGFloatMoreThanFloat()
 CGFloatMoreThanOrEqualToFloatWithPrecision()
 CGFloatMoreThanOrEqualToFloat()
 CGFloatLessThanFloatWithPrecision()
 CGFloatLessThanFloat()
 CGFloatLessThanOrEqualToFloatWithPrecision()
 CGFloatLessThanOrEqualToFloat()
 
 可通过参数 precision 指定要考虑的小数点后的精度，精度的定义是保证指定的那一位小数点不会因为浮点问题导致计算错误，例如当我们要获取一个 1.0 的浮点数时，有时候会得到 0.99999999，有时候会得到 1.000000001，所以需要对指定的那一位小数点的后一位数进行四舍五入操作。
 @code
 precision = 0，也即对小数点后0+1位四舍五入
    0.999 -> 0.9 -> round(0.9) -> 1
    1.011 -> 1.0 -> round(1.0) -> 1
    1.033 -> 1.0 -> round(1.0) -> 1
    1.099 -> 1.0 -> round(1.0) -> 1
 precision = 1，也即对小数点后1+1位四舍五入
    0.999 -> 9.9 -> round(9.9)   -> 10 -> 1.0
    1.011 -> 10.1 -> round(10.1) -> 10 -> 1.0
    1.033 -> 10.3 -> round(10.3) -> 10 -> 1.0
    1.099 -> 10.9 -> round(10.9) -> 11 -> 1.1
 precision = 2，也即对小数点后2+1位四舍五入
    0.999 -> 99.9 -> round(99.9)   -> 100 -> 1.00
    1.011 -> 101.1 -> round(101.1) -> 101 -> 1.01
    1.033 -> 103.3 -> round(103.3) -> 103 -> 1.03
    1.099 -> 109.9 -> round(109.9) -> 110 -> 1.1
 @endcode
*/
CG_INLINE NSInteger _RoundedIntegerFromCGFloat(CGFloat value, NSUInteger precision) {
    return (NSInteger)(round(value * pow(10, precision)));
}

#define _CGFloatCalcGenerator(_operatorName, _operator) CG_INLINE BOOL CGFloat##_operatorName##FloatWithPrecision(CGFloat value1, CGFloat value2, NSUInteger precision) {\
    NSInteger a = _RoundedIntegerFromCGFloat(value1, precision);\
    NSInteger b = _RoundedIntegerFromCGFloat(value2, precision);\
    return a _operator b;\
}\
CG_INLINE BOOL CGFloat##_operatorName##Float(CGFloat value1, CGFloat value2) {\
    return CGFloat##_operatorName##FloatWithPrecision(value1, value2, 0);\
}

_CGFloatCalcGenerator(EqualTo, ==)
_CGFloatCalcGenerator(LessThan, <)
_CGFloatCalcGenerator(LessThanOrEqualTo, <=)
_CGFloatCalcGenerator(MoreThan, >)
_CGFloatCalcGenerator(MoreThanOrEqualTo, >=)

/// 用于居中运算
CG_INLINE CGFloat
CGFloatGetCenter(CGFloat parent, CGFloat child) {
    return flat((parent - child) / 2.0);
}

/// 检测某个数值如果为 NaN 则将其转换为 0，避免布局中出现 crash
CG_INLINE CGFloat
CGFloatSafeValue(CGFloat value) {
    return isnan(value) ? 0 : value;
}

#pragma mark - CGPoint

/// 两个point相加
CG_INLINE CGPoint
CGPointUnion(CGPoint point1, CGPoint point2) {
    return CGPointMake(flat(point1.x + point2.x), flat(point1.y + point2.y));
}

/// 获取rect的center，包括rect本身的x/y偏移
CG_INLINE CGPoint
CGPointGetCenterWithRect(CGRect rect) {
    return CGPointMake(flat(CGRectGetMidX(rect)), flat(CGRectGetMidY(rect)));
}

CG_INLINE CGPoint
CGPointGetCenterWithSize(CGSize size) {
    return CGPointMake(flat(size.width / 2.0), flat(size.height / 2.0));
}

CG_INLINE CGPoint
CGPointToFixed(CGPoint point, NSUInteger precision) {
    CGPoint result = CGPointMake(CGFloatToFixed(point.x, precision), CGFloatToFixed(point.y, precision));
    return result;
}

CG_INLINE CGPoint
CGPointRemoveFloatMin(CGPoint point) {
    CGPoint result = CGPointMake(removeFloatMin(point.x), removeFloatMin(point.y));
    return result;
}

#pragma mark - UIEdgeInsets

/// 获取UIEdgeInsets在水平方向上的值
CG_INLINE CGFloat
UIEdgeInsetsGetHorizontalValue(UIEdgeInsets insets) {
    return insets.left + insets.right;
}

/// 获取UIEdgeInsets在垂直方向上的值
CG_INLINE CGFloat
UIEdgeInsetsGetVerticalValue(UIEdgeInsets insets) {
    return insets.top + insets.bottom;
}

/// 将两个UIEdgeInsets合并为一个
CG_INLINE UIEdgeInsets
UIEdgeInsetsConcat(UIEdgeInsets insets1, UIEdgeInsets insets2) {
    insets1.top += insets2.top;
    insets1.left += insets2.left;
    insets1.bottom += insets2.bottom;
    insets1.right += insets2.right;
    return insets1;
}

CG_INLINE UIEdgeInsets
UIEdgeInsetsSetTop(UIEdgeInsets insets, CGFloat top) {
    insets.top = flat(top);
    return insets;
}

CG_INLINE UIEdgeInsets
UIEdgeInsetsSetLeft(UIEdgeInsets insets, CGFloat left) {
    insets.left = flat(left);
    return insets;
}
CG_INLINE UIEdgeInsets
UIEdgeInsetsSetBottom(UIEdgeInsets insets, CGFloat bottom) {
    insets.bottom = flat(bottom);
    return insets;
}

CG_INLINE UIEdgeInsets
UIEdgeInsetsSetRight(UIEdgeInsets insets, CGFloat right) {
    insets.right = flat(right);
    return insets;
}

CG_INLINE UIEdgeInsets
UIEdgeInsetsToFixed(UIEdgeInsets insets, NSUInteger precision) {
    UIEdgeInsets result = UIEdgeInsetsMake(CGFloatToFixed(insets.top, precision), CGFloatToFixed(insets.left, precision), CGFloatToFixed(insets.bottom, precision), CGFloatToFixed(insets.right, precision));
    return result;
}

CG_INLINE UIEdgeInsets
UIEdgeInsetsRemoveFloatMin(UIEdgeInsets insets) {
    UIEdgeInsets result = UIEdgeInsetsMake(removeFloatMin(insets.top), removeFloatMin(insets.left), removeFloatMin(insets.bottom), removeFloatMin(insets.right));
    return result;
}

#pragma mark - CGSize

/// 判断一个 CGSize 是否存在 NaN
CG_INLINE BOOL
CGSizeIsNaN(CGSize size) {
    return isnan(size.width) || isnan(size.height);
}

/// 判断一个 CGSize 是否存在 infinite
CG_INLINE BOOL
CGSizeIsInf(CGSize size) {
    return isinf(size.width) || isinf(size.height);
}

/// 判断一个 CGSize 是否为空（宽或高为0）
CG_INLINE BOOL
CGSizeIsEmpty(CGSize size) {
    return size.width <= 0 || size.height <= 0;
}

/// 判断一个 CGSize 是否合法（例如不带无穷大的值、不带非法数字）
CG_INLINE BOOL
CGSizeIsValidated(CGSize size) {
    return !CGSizeIsEmpty(size) && !CGSizeIsInf(size) && !CGSizeIsNaN(size);
}

/// 将一个 CGSize 像素对齐
CG_INLINE CGSize
CGSizeFlatted(CGSize size) {
    return CGSizeMake(flat(size.width), flat(size.height));
}

/// 将一个 CGSize 以 pt 为单位向上取整
CG_INLINE CGSize
CGSizeCeil(CGSize size) {
    return CGSizeMake(ceil(size.width), ceil(size.height));
}

/// 将一个 CGSize 以 pt 为单位向下取整
CG_INLINE CGSize
CGSizeFloor(CGSize size) {
    return CGSizeMake(floor(size.width), floor(size.height));
}

CG_INLINE CGSize
CGSizeToFixed(CGSize size, NSUInteger precision) {
    CGSize result = CGSizeMake(CGFloatToFixed(size.width, precision), CGFloatToFixed(size.height, precision));
    return result;
}

CG_INLINE CGSize
CGSizeRemoveFloatMin(CGSize size) {
    CGSize result = CGSizeMake(removeFloatMin(size.width), removeFloatMin(size.height));
    return result;
}

#pragma mark - CGRect

/// 判断一个 CGRect 是否存在 NaN
CG_INLINE BOOL
CGRectIsNaN(CGRect rect) {
    return isnan(rect.origin.x) || isnan(rect.origin.y) || isnan(rect.size.width) || isnan(rect.size.height);
}

/// 系统提供的 CGRectIsInfinite 接口只能判断 CGRectInfinite 的情况，而该接口可以用于判断 INFINITY 的值
CG_INLINE BOOL
CGRectIsInf(CGRect rect) {
    return isinf(rect.origin.x) || isinf(rect.origin.y) || isinf(rect.size.width) || isinf(rect.size.height);
}

/// 判断一个 CGRect 是否合法（例如不带无穷大的值、不带非法数字）
CG_INLINE BOOL
CGRectIsValidated(CGRect rect) {
    return !CGRectIsNull(rect) && !CGRectIsInfinite(rect) && !CGRectIsNaN(rect) && !CGRectIsInf(rect);
}

/// 检测某个 CGRect 如果存在数值为 NaN 的则将其转换为 0，避免布局中出现 crash
CG_INLINE CGRect
CGRectSafeValue(CGRect rect) {
    return CGRectMake(CGFloatSafeValue(CGRectGetMinX(rect)), CGFloatSafeValue(CGRectGetMinY(rect)), CGFloatSafeValue(CGRectGetWidth(rect)), CGFloatSafeValue(CGRectGetHeight(rect)));
}

/// 创建一个像素对齐的CGRect
CG_INLINE CGRect
CGRectFlatMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height) {
    return CGRectMake(flat(x), flat(y), flat(width), flat(height));
}

/// 对CGRect的x/y、width/height都调用一次flat，以保证像素对齐
CG_INLINE CGRect
CGRectFlatted(CGRect rect) {
    return CGRectMake(flat(rect.origin.x), flat(rect.origin.y), flat(rect.size.width), flat(rect.size.height));
}

/// 计算目标点 targetPoint 围绕坐标点 coordinatePoint 通过 transform 之后此点的坐标
CG_INLINE CGPoint
CGPointApplyAffineTransformWithCoordinatePoint(CGPoint coordinatePoint, CGPoint targetPoint, CGAffineTransform t) {
    CGPoint p;
    p.x = (targetPoint.x - coordinatePoint.x) * t.a + (targetPoint.y - coordinatePoint.y) * t.c + coordinatePoint.x;
    p.y = (targetPoint.x - coordinatePoint.x) * t.b + (targetPoint.y - coordinatePoint.y) * t.d + coordinatePoint.y;
    p.x += t.tx;
    p.y += t.ty;
    return p;
}

/// 系统的 CGRectApplyAffineTransform 只会按照 anchorPoint 为 (0, 0) 的方式去计算，但通常情况下我们面对的是 UIView/CALayer，它们默认的 anchorPoint 为 (.5, .5)，所以增加这个函数，在计算 transform 时可以考虑上 anchorPoint 的影响
CG_INLINE CGRect
CGRectApplyAffineTransformWithAnchorPoint(CGRect rect, CGAffineTransform t, CGPoint anchorPoint) {
    CGFloat width = CGRectGetWidth(rect);
    CGFloat height = CGRectGetHeight(rect);
    CGPoint oPoint = CGPointMake(rect.origin.x + width * anchorPoint.x, rect.origin.y + height * anchorPoint.y);
    CGPoint top_left = CGPointApplyAffineTransformWithCoordinatePoint(oPoint, CGPointMake(rect.origin.x, rect.origin.y), t);
    CGPoint bottom_left = CGPointApplyAffineTransformWithCoordinatePoint(oPoint, CGPointMake(rect.origin.x, rect.origin.y + height), t);
    CGPoint top_right = CGPointApplyAffineTransformWithCoordinatePoint(oPoint, CGPointMake(rect.origin.x + width, rect.origin.y), t);
    CGPoint bottom_right = CGPointApplyAffineTransformWithCoordinatePoint(oPoint, CGPointMake(rect.origin.x + width, rect.origin.y + height), t);
    CGFloat minX = MIN(MIN(MIN(top_left.x, bottom_left.x), top_right.x), bottom_right.x);
    CGFloat maxX = MAX(MAX(MAX(top_left.x, bottom_left.x), top_right.x), bottom_right.x);
    CGFloat minY = MIN(MIN(MIN(top_left.y, bottom_left.y), top_right.y), bottom_right.y);
    CGFloat maxY = MAX(MAX(MAX(top_left.y, bottom_left.y), top_right.y), bottom_right.y);
    CGFloat newWidth = maxX - minX;
    CGFloat newHeight = maxY - minY;
    CGRect result = CGRectMake(minX, minY, newWidth, newHeight);
    return result;
}

/// 为一个CGRect叠加scale计算
CG_INLINE CGRect
CGRectApplyScale(CGRect rect, CGFloat scale) {
    return CGRectFlatted(CGRectMake(CGRectGetMinX(rect) * scale, CGRectGetMinY(rect) * scale, CGRectGetWidth(rect) * scale, CGRectGetHeight(rect) * scale));
}

/// 计算view的水平居中，传入父view和子view的frame，返回子view在水平居中时的x值
CG_INLINE CGFloat
CGRectGetMinXHorizontallyCenterInParentRect(CGRect parentRect, CGRect childRect) {
    return flat((CGRectGetWidth(parentRect) - CGRectGetWidth(childRect)) / 2.0);
}

/// 计算view的垂直居中，传入父view和子view的frame，返回子view在垂直居中时的y值
CG_INLINE CGFloat
CGRectGetMinYVerticallyCenterInParentRect(CGRect parentRect, CGRect childRect) {
    return flat((CGRectGetHeight(parentRect) - CGRectGetHeight(childRect)) / 2.0);
}

/// 返回值：同一个坐标系内，想要layoutingRect和已布局完成的referenceRect保持垂直居中时，layoutingRect的originY
CG_INLINE CGFloat
CGRectGetMinYVerticallyCenter(CGRect referenceRect, CGRect layoutingRect) {
    return CGRectGetMinY(referenceRect) + CGRectGetMinYVerticallyCenterInParentRect(referenceRect, layoutingRect);
}

/// 返回值：同一个坐标系内，想要layoutingRect和已布局完成的referenceRect保持水平居中时，layoutingRect的originX
CG_INLINE CGFloat
CGRectGetMinXHorizontallyCenter(CGRect referenceRect, CGRect layoutingRect) {
    return CGRectGetMinX(referenceRect) + CGRectGetMinXHorizontallyCenterInParentRect(referenceRect, layoutingRect);
}

/// 为给定的rect往内部缩小insets的大小（系统那个方法的命名太难联想了，所以定义了一个新函数）
CG_INLINE CGRect
CGRectInsetEdges(CGRect rect, UIEdgeInsets insets) {
    return UIEdgeInsetsInsetRect(rect, insets);
}

/// 传入size，返回一个x/y为0的CGRect
CG_INLINE CGRect
CGRectMakeWithSize(CGSize size) {
    return CGRectMake(0, 0, size.width, size.height);
}

CG_INLINE CGRect
CGRectFloatTop(CGRect rect, CGFloat top) {
    rect.origin.y = top;
    return rect;
}

CG_INLINE CGRect
CGRectFloatBottom(CGRect rect, CGFloat bottom) {
    rect.origin.y = bottom - CGRectGetHeight(rect);
    return rect;
}

CG_INLINE CGRect
CGRectFloatRight(CGRect rect, CGFloat right) {
    rect.origin.x = right - CGRectGetWidth(rect);
    return rect;
}

CG_INLINE CGRect
CGRectFloatLeft(CGRect rect, CGFloat left) {
    rect.origin.x = left;
    return rect;
}

/// 保持rect的左边缘不变，改变其宽度，使右边缘靠在right上
CG_INLINE CGRect
CGRectLimitRight(CGRect rect, CGFloat rightLimit) {
    rect.size.width = rightLimit - rect.origin.x;
    return rect;
}

/// 保持rect右边缘不变，改变其宽度和origin.x，使其左边缘靠在left上。只适合那种右边缘不动的view
/// 先改变origin.x，让其靠在offset上
/// 再改变size.width，减少同样的宽度，以抵消改变origin.x带来的view移动，从而保证view的右边缘是不动的
CG_INLINE CGRect
CGRectLimitLeft(CGRect rect, CGFloat leftLimit) {
    CGFloat subOffset = leftLimit - rect.origin.x;
    rect.origin.x = leftLimit;
    rect.size.width = rect.size.width - subOffset;
    return rect;
}

/// 限制rect的宽度，超过最大宽度则截断，否则保持rect的宽度不变
CG_INLINE CGRect
CGRectLimitMaxWidth(CGRect rect, CGFloat maxWidth) {
    CGFloat width = CGRectGetWidth(rect);
    rect.size.width = width > maxWidth ? maxWidth : width;
    return rect;
}

CG_INLINE CGRect
CGRectSetX(CGRect rect, CGFloat x) {
    rect.origin.x = flat(x);
    return rect;
}

CG_INLINE CGRect
CGRectSetY(CGRect rect, CGFloat y) {
    rect.origin.y = flat(y);
    return rect;
}

CG_INLINE CGRect
CGRectSetXY(CGRect rect, CGFloat x, CGFloat y) {
    rect.origin.x = flat(x);
    rect.origin.y = flat(y);
    return rect;
}

CG_INLINE CGRect
CGRectSetWidth(CGRect rect, CGFloat width) {
    if (width < 0) {
        return rect;
    }
    rect.size.width = flat(width);
    return rect;
}

CG_INLINE CGRect
CGRectSetHeight(CGRect rect, CGFloat height) {
    if (height < 0) {
        return rect;
    }
    rect.size.height = flat(height);
    return rect;
}

CG_INLINE CGRect
CGRectSetSize(CGRect rect, CGSize size) {
    rect.size = CGSizeFlatted(size);
    return rect;
}

CG_INLINE CGRect
CGRectToFixed(CGRect rect, NSUInteger precision) {
    CGRect result = CGRectMake(CGFloatToFixed(CGRectGetMinX(rect), precision),
                               CGFloatToFixed(CGRectGetMinY(rect), precision),
                               CGFloatToFixed(CGRectGetWidth(rect), precision),
                               CGFloatToFixed(CGRectGetHeight(rect), precision));
    return result;
}

CG_INLINE CGRect
CGRectRemoveFloatMin(CGRect rect) {
    CGRect result = CGRectMake(removeFloatMin(CGRectGetMinX(rect)),
                               removeFloatMin(CGRectGetMinY(rect)),
                               removeFloatMin(CGRectGetWidth(rect)),
                               removeFloatMin(CGRectGetHeight(rect)));
    return result;
}

/// outerRange 是否包含了 innerRange
CG_INLINE BOOL
NSContainingRanges(NSRange outerRange, NSRange innerRange) {
    if (innerRange.location >= outerRange.location && outerRange.location + outerRange.length >= innerRange.location + innerRange.length) {
        return YES;
    }
    return NO;
}

CG_INLINE CGRect
CGRectMakeScreenCenter(CGFloat width, CGFloat height) {
    return CGRectMake((SCREEN_WIDTH-width)/2, (SCREEN_HEIGHT-height)/2, width, height);
}
