//
//  TMEVLEvent.h
//  TMEVL
//
//  Created by TMKit on 2022/6/15.
//

#import <Foundation/Foundation.h>
#import "TMEVLEventProtocol.h"
#import "TMModelBase.h"
#import "TMReachabilityManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TMEVLEvent : TMModelBase <TMEVLEventProtocol>

/// 点位通道：绿色/红色。默认为红色
/// 非接口字段，用于客户端标识打点通道，不会存到Storage。
@property (nonatomic, assign) TMEVLChannel channel;

/// 点位仅有网时有效，默认为无网有效
/// 非接口字段，用于客户端点位配置，不会存到Storage。
@property (nonatomic, assign) BOOL onlyForReachable;

/// 点位上传状态。
/// 非接口字段，用户客户端标识上传状态。
@property (nonatomic, assign) TMEVLEventPostState postState;

/// 点位唯一标识。
/// 接口字段，用于服务端去重。
/// 初始化自动生成。
@property (nonatomic, copy) NSString *idf;

/// 点位业务ID。
/// 接口字段。业务字段。
@property (nonatomic, copy) NSString *evtId;

/// 点位生成时间（毫秒）。
/// 接口字段。业务字段。
/// 初始化自动生成。
@property (nonatomic, assign) uint64_t genTs;

/// 点位生成时网络状态。
/// 接口字段。业务字段。
@property (nonatomic, assign) TMReachabilityStatus networkStatus;

/// 一级分类。使用 NSString 类型，具体枚举定义交给外部
/// 接口字段，用于服务端分类。
@property (nonatomic, copy) NSString *cat;

/// 二级分类。使用 NSString 类型，具体枚举定义交给外部
/// 接口字段，用于服务端分类。
@property (nonatomic, copy) NSString *subCat;

/// 特殊参数存放，以JSONString形式存储 (value 为空字符串的会被排除)
@property (nonatomic, copy, nullable) NSDictionary *data;

@end

NS_ASSUME_NONNULL_END
