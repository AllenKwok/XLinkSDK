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

NS_ASSUME_NONNULL_BEGIN

@interface XLinkSetDataPointTask : XLinkSendPolicyTask

/**
 要设置的设备
 */
@property(weak, nonatomic) XDevice *device;

/**
 新建设置数据端点任务
 
 @param device 要设置数据端点的设备
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completionHandler 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)setDataPointTaskWithDevice:(XDevice *)device
                                dataPoints:(NSArray <XLinkDataPoint *> *)dataPoints
                                   timeout:(NSUInteger)timeout
                             completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkSetDataPointTask (XLinkDeprecated)

/**
 新建设置数据端点任务
 
 @param device 要设置数据端点的设备
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completeBlock 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)setDataPointWithDevice:(XDevice *)device
                        withDataPoints:(NSArray <XLinkDataPoint *> *)DataPoints
                           withTimeOut:(NSUInteger)timeout
                     withCompleteBlock:(OnTaskCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，使用+setDataPointTaskWithDevice:dataPoints:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end

NS_ASSUME_NONNULL_END
