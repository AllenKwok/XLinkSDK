//
//  DeviceShareNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/16.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 设备管理员推送的分享消息
 */
typedef NS_ENUM(NSUInteger,DeviceShareState){
    DeviceShareStateShareRequest = 0,//分享请求
    DeviceShareStateAcceptShare = 1,//接受分享
    DeviceShareStateDenyShare = 2,//拒绝分享
    DeviceShareStateShareCancel = 3,//分享被取消
} ;

@interface DeviceShareNotify : NSObject

/**
 要分享的设备id
 */
@property (copy, nonatomic) NSNumber *deviceId;

/**
 要分享的设备码
 */
@property (copy, nonatomic) NSNumber *inviteCode;

/**
 分享的状态
 */
@property (assign, nonatomic) DeviceShareState shareState;

@end
