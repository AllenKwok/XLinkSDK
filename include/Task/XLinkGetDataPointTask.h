//
//  XLinkGetDataPointTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"
#import "XDevice.h"
@class XLinkDataPoint;
@class XLinkGetDataPointTask;

typedef void (^OnGetDataPointTaskCompleteBlock) (NSArray <XLinkDataPoint *>*result,XLinkErrorCode errCode);

@interface XLinkGetDataPointTask : XLinkTask

/**
 要获取数据端点的设备
 */
@property (strong, nonatomic) XDevice *device;

/**
 任务完成后回调
 */
@property (copy, nonatomic) OnGetDataPointTaskCompleteBlock getDataPointTaskCompleteBlock;

/**
 新建获取数据端点的任务

 @param device 设备
 @param timeOut 设置超时时间，单位秒，建议10秒
 @param completeBlock 完成后的回调
 @return 任务
 */
+ (instancetype)getDataPointTaskWithDevice:(XDevice *)device
                               withTimeOut:(NSUInteger)timeOut
         withGetDataPointTaskCompleteBlock:(OnGetDataPointTaskCompleteBlock)completeBlock;

@end
