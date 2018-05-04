//
//   XDeviceStateObserver.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XDevice.h"


typedef void (^DeviceStateChangedBlock)(XDevice *device, XDeviceConnectionState state);

@interface XDeviceStateObserver : NSObject

/**
 要监听状态变化的设备
 */
@property(strong, nonatomic) XDevice *device;

/**
 监听到设备状态变化的回调
 */
@property(copy, nonatomic) DeviceStateChangedBlock block;

/**
 新建设备状态变化的监听类
 
 @param device 要监听状态变化的设备
 @param block 监听到设备状态变化的回调
 @return 设备状态变化的监听类
 */
+ (instancetype)deviceStateChangedObserverWithDevice:(XDevice *)device withDataPointUpdateBlock:(DeviceStateChangedBlock)block;

@end
