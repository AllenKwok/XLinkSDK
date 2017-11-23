//
//  XLinkUserAuthorizeTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/6/2.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"

typedef void (^OnUserAuthorizeTaskCompleteBlock) (id result, NSError *err);

@interface XLinkUserAuthorizeTask : XLinkTask

/**
 企业ID，默认值为nil。
 */
@property (copy, nonatomic) NSString *corpId;

/**
 账号（email或者手机号码），默认值为nil。
 */
@property (copy, nonatomic) NSString *account;

/**
 密码，默认值为nil。
 */
@property (copy, nonatomic) NSString *password;

@property (copy, nonatomic) OnUserAuthorizeTaskCompleteBlock userAuthorizeTaskCompleteBlock;

/**
 用户使用账号密码登陆task
 
 @param account 账号
 @param password 密码
 @param cropId 企业id
 @param timeout 设置超时时间，单位秒，建议15秒
 @param completeBlock 完成后的回调
 @return task
 */
+ (instancetype)userAuthorizeTaskWithAccount:(NSString *)account withPassword:(NSString *)password withCropId:(NSString *)cropId withTimeout:(NSUInteger)timeout withCompleteBlock:(OnUserAuthorizeTaskCompleteBlock)completeBlock;

@end
