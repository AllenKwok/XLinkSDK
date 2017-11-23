//
//  XDevice.h
//  XLinkSdkLib
//
//  Created by AllenKwok on 2017/2/5.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

//设备连接状态
typedef NS_ENUM(uint8_t,XDeviceConnectionState) {
    XDeviceConnectionStateDetached = 0,//XDevice的状态未知
    XDeviceConnectionStateOffline = 1,//SDK设备与设备失去连接
    XDeviceConnectionStateConnecting = 2,//SDK正在连接设备
    XDeviceConnectionStateOnline = 3,//SDK设备保持连接
} ;


@interface XDevice : NSObject
/**
 企业ID
 */
@property (nonatomic, copy) NSString  *productID;
/**
 MAC地址
 */
@property (nonatomic, copy) NSData    *macAddress;
/**
 设备名称
 */
@property (nonatomic, copy) NSString  *deviceName;
/**
 权限
 */
@property (nonatomic, strong) NSNumber  *role;
/**
 来源
 */
@property (nonatomic, strong) NSNumber  *source;
/**
 设备ID
 */
@property (nonatomic, assign) UInt32    deviceID;
/**
 内网配对id
 */
@property (assign, nonatomic) uint16_t pairingID;
/**
 内网配对秘钥
 */
@property (copy, nonatomic) NSData *pairingSignature;
/**
 内网配对凭证
 */
@property (copy, nonatomic) NSData *ticket;
/**
 IP地址
 */
@property (nonatomic, copy) NSString  *ipAddress;
/**
 监听端口
 */
@property (nonatomic, assign) UInt16    listenPort;
/**
 协议版本
 */
@property (nonatomic, assign) UInt8     protocolVersion;

/**
 固件版本号
 */
@property (nonatomic, assign) UInt16     firmwareVersion;
/**
 mcu软件版本号
 */
@property (nonatomic, assign) UInt16    mcuVersion;
/**
 上次登录的时间，格式2017-10-17T17:43:35.881Z
 */
@property (copy, nonatomic) NSString *lastLoginDate;
/**
 订阅设备的时间
 */
@property (copy, nonatomic) NSString *subscribeDate;
/**
 设备类型
 */
@property (nonatomic, assign) UInt16    deviceType;
/**
 设备是否被绑定过
 */
@property (assign, nonatomic) BOOL isBinded;
/**
 云端是否在线
 */
@property (assign, nonatomic) BOOL isCloudOnline;
/**
 返回DETACHED时，表示SDK尚未尝试过内网或者外网连接。
 返回OFFLINE时，表示SDK与设备无内外网连接
 返回ONLINE时，表示SDK与设备内外网连接或者内网连接。
 返回CONNECTING时，表示SDK与设备无内外网连接，但正在尝试进行内网或者外网连接。
 */
@property (assign, nonatomic) XDeviceConnectionState connectionState;
/**
 内网连接状态
 返回DETACHED时，表示SDK尚未尝试过内网连接。
 返回OFFLINE时，表示SDK与设备无内网连接
 返回ONLINE时，表示SDK与设备内网连接。
 返回CONNECTING时，正在尝试进行内网连接。
 */
@property (assign, nonatomic) XDeviceConnectionState localConnectionState;
/**
 外网连接状态
 返回DETACHED时，表示SDK尚未尝试过外网连接。
 返回OFFLINE时，表示SDK与设备无外网连接
 返回ONLINE时，表示SDK与设备外网连接。
 返回CONNECTING时，正在尝试进行外网连接。
 */
@property (assign, nonatomic) XDeviceConnectionState cloudConnectionState;

/**
 *  通过字典还原成设备实体
 *
 *  @param dic 设备字典；字典支持protocol 1格式的字典
 *
 *  @return 设备实体
 */
- (instancetype)initWithDictionary:(NSDictionary *)dic;

/**
 *  将设备属性格式化成字典
 *
 *  @return 设备属性字典
 */
- (NSDictionary *)getDictionaryFormat;

/**
 *  获得Mac地址的字符串形式，
 *
 *  @return 格式：00:00:11:aa:bb:cc
 */
- (NSString *)getMacAddressString;

/**
 *  获得Mac地址的字符串形式
 *
 *  @return 格式：000011AABBCC
 */
- (NSString *)getMacAddressSimple;

@end
