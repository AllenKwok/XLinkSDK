//
//  XLinkAddDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/13.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"


@class XDevice;

typedef void (^OnPairingResultBlock) (uint16_t paringID,NSData *pairingSignature);

@interface XLinkAddDeviceTask : XLinkTask

/**
 要添加的设备
 */
@property (strong, nonatomic) XDevice *device;

/**
 新建添加设备任务

 @param device 要添加的设备
 @param pinCode 安全码，一般为设备会显示出来，需要设备支持。没有的时候传nil即可
 @param timeOut 设置超时，单位秒，默认90秒
 @param completeBlock 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)addDeviceTaskWithDevice:(XDevice *)device
                            withPinCode:(NSData *)pinCode
                            withTimeOut:(NSUInteger)timeOut
                      withCompleteBlock:(OnTaskCompleteBlock)completeBlock;


/**
 新建添加设备任务

 @param qrcodeString 扫描的二维码
 @param timeOut 设置超时，单位秒，默认90秒
 @param completeBlock 任务完成后回调
 @return 任务
 */
+ (instancetype)addDeviceTaskWithQrcodeString:(NSString *)qrcodeString
                                  withTimeOut:(NSUInteger)timeOut
                            withCompleteBlock:(OnTaskCompleteBlock)completeBlock;

@end
