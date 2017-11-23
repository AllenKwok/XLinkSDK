//
//  XDeviceManager.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XDeviceStateObserver.h"
#import "XDevice.h"
#import "XLinkConnectDeviceTask.h"

@interface XDeviceManager : NSObject

/**
 单例对象
 */
+ (instancetype)shareManager;


/**
 停止SDK内部的自动重连,清除缓存
 */
- (void)stopDeviceManage;


/**
 重新连接设备，内部在网络变化的时候调用，外部一般不要调用
 */
- (void)reconnectDevices;

/**
 连接设备
 
 @param device 设备
 */
- (void)connectDevice:(XDevice *)device;

/**
 连接设备

 @param device 设备
 @param connectionPolicy 连接策略
 */
- (void)connectDevice:(XDevice *)device withConnectionPolicy:(XDeviceConnectionPolicy)connectionPolicy;

/**
 断开连接设备
 
 @param device 设备
 */
- (void)disconnectDevice:(XDevice *)device;

/**
 断开连接设备本地连接
 
 @param device 设备
 */
- (void)disconnectLocalWithDevice:(XDevice *)device;

/**
 添加一个设备状态变化的更新监听
 
 @param observer 设备状态变化的更新监听
 */
- (void)addDeviceStateObserver:(XDeviceStateObserver *)observer;

/**
 删除一个设备状态变化的更新监听
 
 @param observer 设备状态变化的更新监听
 */
- (void)removeDeviceStateObserver:(XDeviceStateObserver *)observer;

/**
 获取SDK管理的设备实体
 
 @param macData 设备实体的mac地址
 @return 设备实体
 */
- (XDevice *)getDeviceWithMacAddressData:(NSData *)macData withProductId:(NSString *)productId;

/**
 获取SDK管理的设备实体
 
 @param macAddressString 设备实体的mac地址字符串
 @return 设备实体
 */
- (XDevice *)getDeviceWithMacAddressString:(NSString *)macAddressString withProductId:(NSString *)productId;

/**
 获取SDK管理的设备实体
 
 @param deviceId 设备id
 @return 设备实体
 */
- (XDevice *)getDeviceWithDeviceId:(NSUInteger)deviceId;



@end
