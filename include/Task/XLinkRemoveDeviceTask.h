//
//  XLinkRemoveDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/13.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "RetryUntilTimeoutTask.h"
#import "XDevice.h"

@interface XLinkRemoveDeviceTask : RetryUntilTimeoutTask

/**
 要添加的设备
 */
@property (strong, nonatomic) XDevice *device;


/**
 新建删除设备任务
 
 @param device 要添加的设备
 @param timeOut 设置超时，单位秒，默认90秒
 @param completeBlock 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)removeDeviceTaskWithDevice:(XDevice *)device
                               withTimeOut:(NSUInteger)timeOut
                         withCompleteBlock:(OnTaskCompleteBlock)completeBlock;

@end
