//
//  DeviceOnlineStateChangedNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/16.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DeviceOnlineStateAlertNotify.h"

/**
 设备在线状态变化引发的通知
 */


@interface DeviceOnlineStateChangedNotify : NSObject

/**
 设备id
 */
@property (copy, nonatomic) NSNumber *deviceId;

/**
 设备在线状态
 */
@property (assign, nonatomic) DeviceOnlineState state;

@end
