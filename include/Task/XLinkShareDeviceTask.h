//
//  XLinkShareDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/6/19.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"
#import "XLinkThirdPartyAuthorizeTask.h"
#import "XDevice.h"

//分享的方式
typedef NS_ENUM(NSUInteger, XLinkShareDeviceMode) {
    XLinkShareDeviceModeApp,//通过账号分享
    XLinkShareDeviceModeQrcode,//通过二维码分享
    XLinkShareDeviceModeEmail,//通过发送邮件分享
};

//分享完成后的回调
typedef void (^OnShareDeviceTaskCompleteBlock) (NSDictionary *result,XLinkErrorCode code);

@interface XLinkShareDeviceTask : XLinkTask

/**
 设备
 */
@property (strong, nonatomic) XDevice *device;

/**
 对方账号（邮箱或者手机号）
 */
@property (copy, nonatomic) NSString *account;

/**
 用户来源，第三方来源用户需要填
 */
@property (assign, nonatomic) XLinkUserSourceType sourceType;

/**
 分享的方式
 */
@property (assign, nonatomic) XLinkShareDeviceMode shareDeviceMode;

/**
 过期时间（单位秒）
 */
@property (copy, nonatomic) NSString * expired;

/**
 对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 */
@property (copy, nonatomic) NSString *authority;

@property (copy, nonatomic) OnShareDeviceTaskCompleteBlock shareCompleteBlock;

/**
 创建一个分享设备task
 
 @param device 设备
 @param account 对方账号（邮箱或者手机号）
 @param expired 分享有效期时间（单位秒）
 @param shareDeviceMode 分享的方式
 @param authority 对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 @param timeout task超时时间
 @param shareCompleteBlock 完成后的回调
 @return task
 */
+ (instancetype)shareDeviceTaskWithDevice:(XDevice *)device
                              withAccount:(NSString *)account
                              withExpired:(NSString *)expired
                            withShareMode:(XLinkShareDeviceMode)shareDeviceMode
                            withAuthority:(NSString *)authority
                              withTimeOut:(NSUInteger)timeout
         withShareDeviceTaskCompleteBlock:(OnShareDeviceTaskCompleteBlock)shareCompleteBlock;

/**
 创建一个分享设备task
 
 @param device 设备
 @param openId 对方openId
 @param sourceType 账号来源
 @param expired 分享有效期时间（单位秒）
 @param shareDeviceMode 分享的方式
 @param authority 对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 @param timeout task超时时间
 @param shareCompleteBlock 完成后的回调
 @return task
 */
+ (instancetype)shareDeviceTaskWithDevice:(XDevice *)device
                               withOpenId:(NSString *)openId
                           withSourceType:(XLinkUserSourceType)sourceType
                              withExpired:(NSString *)expired
                            withShareMode:(XLinkShareDeviceMode)shareDeviceMode
                            withAuthority:(NSString *)authority
                              withTimeOut:(NSUInteger)timeout
         withShareDeviceTaskCompleteBlock:(OnShareDeviceTaskCompleteBlock)shareCompleteBlock;

@end
