//
//  XLinkSyncDeviceListTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/4/28.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

//将当前用户的设备设备从云端同步到本地。要求设备和当前用户之间有订阅关系。任务完成后默认自动发起本地连接和云端连接。

#import "XLinkTask.h"
#import "XDevice.h"

typedef void (^OnSyncDeviceListCompleteBlock) (NSArray <XDevice *>*devices,XLinkErrorCode code);

@interface XLinkSyncDeviceListTask : XLinkTask

/**
 设备列表版本号，默认为0
 */
@property (assign, nonatomic) int version;

@property (copy, nonatomic) OnSyncDeviceListCompleteBlock syncCompleteBlock;

/**
 同步设备列表

 @param version 版本号
 @param timeout 超时时间
 @param connectLocal 是否自动进行本地连接，默认 true
 @param syncCompleteBlock 完成后的回调
 @return task
 */
+(instancetype)syncDeviceListTaskWithVersion:(int)version
                                 withTimeout:(NSUInteger)timeout
                            withConnectLocal:(BOOL)connectLocal
                           withCompleteBlock:(OnSyncDeviceListCompleteBlock)syncCompleteBlock;

@end
