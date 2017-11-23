//
//  XLinkScanDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/13.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"
@class XLinkScanDeviceTask;
@class XDevice;

typedef void (^OnGotDeviceBlock) (XDevice *device);

@interface XLinkScanDeviceTask : XLinkTask


/**
 要扫描设备的productID数组
 */
@property (copy, nonatomic) NSArray *pidArray;

/**
 扫描到设备后回调
 */
@property (copy, nonatomic) OnGotDeviceBlock gotDeviceBlock;

/**
 新建扫描设备任务

 @param pidArray productID数组
 @param timeOut 设置超时，单位毫秒，默认90秒
 @param gotDeviceBlock 搜索到设备的回调
 @param completeBlock 搜索完成的回调
 @return 设备任务
 */
+ (instancetype)scanDeviceTaskWithProductIds:(NSArray *)pidArray
                                 withTimeOut:(NSUInteger)timeOut
                          withGotDeviceBlock:(OnGotDeviceBlock)gotDeviceBlock
                           withCompleteBlock:(OnTaskCompleteBlock)completeBlock;

@end
