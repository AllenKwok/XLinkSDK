//
//  XLinkSetDataPointTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkSendPolicyTask.h"
#import "XDevice.h"

@class XLinkDataPoint;
@interface XLinkSetDataPointTask : XLinkSendPolicyTask

/**
 要设置的设备
 */
@property (weak, nonatomic) XDevice *device;

/**
 新建设置数据端点任务
 
 @param device 要设置数据端点的设备
 @param timeOut 设置超时时间，单位秒，建议10秒
 @param completeBlock 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)setDataPointWithDevice:(XDevice *)device
                        withDataPoints:(NSArray <XLinkDataPoint *>*)DataPoints
                           withTimeOut:(NSUInteger)timeOut
                     withCompleteBlock:(OnTaskCompleteBlock)completeBlock;

@end
