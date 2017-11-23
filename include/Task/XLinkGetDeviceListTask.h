//
//  XLinkGetDeviceListTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/13.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"
#import "XDevice.h"

typedef void (^OnGetDeviceListCompleteBlock) (NSArray <XDevice *>*devices,XLinkErrorCode code);

@interface XLinkGetDeviceListTask : XLinkTask

/**
 任务完成后的回调
 */
@property (copy, nonatomic) OnGetDeviceListCompleteBlock getDeviceListCompleteBlock;

/**
 获取设备列表

 @param userId 用户id
 @param version 版本号，默认值为0
 @param timeOut 超时时间
 @param completeBlock 完成后回调
 @return 任务
 */
+(instancetype)getDeviceListTaskWithUserId:(NSNumber *)userId
                               withVersion:(int)version
                               withTimeOut:(NSUInteger)timeOut withCompleteBlock:(OnGetDeviceListCompleteBlock)completeBlock;

@end
