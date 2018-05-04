//
//  XLinkProbeDataPointTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/12/27.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkSendPolicyTask.h"
#import "XDevice.h"

@class XLinkDataPoint;
@class XLinkGetDataPointTask;

typedef void (^XLinkProbeDataPointTaskCompletionHandler)(NSArray <XLinkDataPoint *> *result, XLinkErrorCode errCode);

@interface XLinkProbeDataPointTask : XLinkSendPolicyTask

/**
 要获取数据端点的设备
 */
@property(strong, nonatomic) XDevice *device;

/**
 要获取数据端点的index列表
 */
@property(copy, nonatomic) NSArray <NSNumber *> *indexArray;

/**
 新建获取数据端点的任务
 
 @param device 设备
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completionHandler 完成后的回调
 @return 任务
 */
+ (instancetype)probeDataPointTaskWithDevice:(XDevice *)device
                                  indexArray:(NSArray <NSNumber *> *)indexArray
                                     timeout:(NSUInteger)timeout
                               completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkProbeDataPointTask (XLinkDeprecated)

/**
 新建获取数据端点的任务
 
 @param device 设备
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completeBlock 完成后的回调
 @return 任务
 */
+ (instancetype)probeDataPointTaskWithDevice:(XDevice *)device
                                  indexArray:(NSArray <NSNumber *> *)indexArray
                                     timeOut:(NSUInteger)timeout
                 probeDataPointCompleteBlock:(XLinkProbeDataPointTaskCompletionHandler)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+probeDataPointTaskWithDevice:indexArray:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end
