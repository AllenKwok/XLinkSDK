//
//  XLinkConnectDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/13.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"

typedef NS_ENUM(NSUInteger,XDeviceConnectionPolicy){
    XDeviceConnectionPolicyAuto,//自动连接策略
    XDeviceConnectionPolicyLocalOnly,//只进行本地连接
    XDeviceConnectionPolicyLocalFirst,//优先本地连接
    XDeviceConnectionPolicyCloudOnly,//只进行云端连接
    XDeviceConnectionPolicyCloudFirst,//优先云端连接
} ;

@class XDevice;


@interface XLinkConnectDeviceTask : XLinkTask
/**
 要连接的设备
 */
@property (strong, nonatomic)XDevice *device;

/**
 连接的策略
 */
@property (assign, nonatomic)  XDeviceConnectionPolicy connectionPolicy;


/**
 新建连接设备任务
 
 @param device 要连接的设备
 @param timeOut 设置超时，单位毫秒，默认10秒
 @param completeBlock 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)connectDeviceTaskWithDevice:(XDevice *)device
                                withTimeOut:(NSUInteger)timeOut
                          withCompleteBlock:(OnTaskCompleteBlock)completeBlock;

@end
