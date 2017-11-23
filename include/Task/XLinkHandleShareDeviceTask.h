//
//  XLinkHandleShareDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/6/20.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"

typedef NS_ENUM(NSUInteger, XLinkHandleShareDeviceAction) {
    XLinkHandleShareDeviceActionAccept,//接受分享
    XLinkHandleShareDeviceActionDeny,//拒绝分享
    XLinkHandleShareDeviceActionCancel,//取消分享
    XLinkHandleShareDeviceActionDeleteRecord,//删除分享记录
    XLinkHandleShareDeviceActionAcceptQrCode,//接受二维码分享
};

@interface XLinkHandleShareDeviceTask : XLinkTask

/**
 邀请码
 */
@property (copy, nonatomic) NSString *inviteCode;

/**
 处理的动作，接受或者取消
 */
@property (assign, nonatomic) XLinkHandleShareDeviceAction action;

/**
  创建处理分享设备Task

 @param inviteCode 分享邀请码
 @param action 处理的动作，接受或者取消
 @param completeBlock 完成后的回调
 @return 处理分享设备Task
 */
+ (instancetype)handleShareDeviceTaskWithInvitedCode:(NSString *)inviteCode
                               withHandleShareAction:(XLinkHandleShareDeviceAction)action
                                         withTimeOut:(NSUInteger)timeout
                               withTaskCompleteBlock:(OnTaskCompleteBlock)completeBlock;

@end
