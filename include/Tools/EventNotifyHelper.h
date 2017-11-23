//
//  EventNotifyHelper.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/16.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SubscriptionChangeNotify.h"
#import "DataPointChangeNotify.h"
#import "DataPointAlertNotify.h"
#import "DeviceShareNotify.h"
#import "BroadcastNotify.h"
#import "DevicePropChangedNotify.h"
#import "SubscriptionChangeNotify.h"
#import "DeviceOnlineStateAlertNotify.h"
#import "DeviceOnlineStateChangedNotify.h"


@interface EventNotifyHelper : NSObject

/**
 解析EventNotify
 
 @param data 原始的EventNotify数据
 @return EventNotify解析后的NSDictionary
 */
+ (NSDictionary *)parseEventNotifyWithData:(NSData *)data;

/**
 解析设备数据端点变化发送的通知
 
 @param data 原始的EventNotify数据
 @return 设备数据端点变化model
 */
+ (DataPointChangeNotify *)parseDataPointChangeNotifyWithData:(NSData *)data;

/**
 设备数据端点变换引起的报警
 
 @param data 原始的EventNotify数据
 @return 设备数据端点变换引起的报警model
 */
+ (DataPointAlertNotify *)parseDataPointAlertNotifyWithData:(NSData *)data;

/** 设备管理员推送的分享消息*/

/**
 设备管理员推送的分享消息
 
 @param data 原始的EventNotify数据
 @return 设备管理员推送的分享消息Model
 */
+ (DeviceShareNotify *)parseDeviceShareNotifyWithData:(NSData *)data;

/**
 厂商推送的消息广播
 
 @param data 原始的EventNotify数据
 @return 厂商推送的消息广播Model
 */
+ (BroadcastNotify *)parseBroadcastNotifyWithData:(NSData *)data;

/**
 设备属性变化通知
 
 @param data 原始的EventNotify数据
 @return 设备属性变化通知model
 */
+ (DevicePropChangedNotify *)parseDevicePropChangedNotifyWithData:(NSData *)data;

/**
 解析用户和设备订阅关系发生变化通知
 
 @param data 原始的EventNotify数据
 @return 用户和设备订阅关系发生变化通知的model
 */
+ (SubscriptionChangeNotify *)parseSubscriptionChangeNotifyWithData:(NSData *)data;

/**
 设备在线状态变化引发的通知
 
 @param data 原始的EventNotify数据
 @return 设备在线状态变化引发的通知model
 */
+ (DeviceOnlineStateChangedNotify *)parseDeviceOnlineStateChangedNotifyWithData:(NSData *)data;

/**
 设备在线状态变化引发的告警
 
 @param data 原始的EventNotify数据
 @return 设备在线状态变化引发的告警model
 */
+ (DeviceOnlineStateAlertNotify *)parseDeviceOnlineStateAlertNotifyWithData:(NSData *)data;

@end
