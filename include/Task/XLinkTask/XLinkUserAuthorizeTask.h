//
//  XLinkUserAuthorizeTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/6/2.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^XLinkUserAuthorizeTaskCompletionHandler)(id result, NSError *err);

@interface XLinkUserAuthorizeTask : XLinkTask

/**
 企业ID，默认值为nil。
 */
@property(copy, nonatomic) NSString *corpId;

/**
 账号（email或者手机号码），默认值为nil。
 */
@property(copy, nonatomic) NSString *account;

/**
 密码，默认值为nil。
 */
@property(copy, nonatomic) NSString *password;



/**
 新建用户使用账号密码登陆任务
 
 @param account 账号
 @param password 密码
 @param cropId 企业id
 @param timeout 设置超时时间，单位秒，建议15秒
 @param completionHandler 完成后的回调
 @return task
 */
+ (instancetype)userAuthorizeTaskWithAccount:(NSString *)account
                                    password:(NSString *)password
                                      cropId:(NSString *)cropId
                                     timeout:(NSUInteger)timeout
                               completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkUserAuthorizeTask (XLinkDeprecated)

/**
 新建用户使用账号密码登陆任务
 
 @param account 账号
 @param password 密码
 @param cropId 企业id
 @param timeout 设置超时时间，单位秒，建议15秒
 @param completeBlock 完成后的回调
 @return task
 */
+ (instancetype)userAuthorizeTaskWithAccount:(NSString *)account
                                withPassword:(NSString *)password
                                  withCropId:(NSString *)cropId
                                 withTimeout:(NSUInteger)timeout
                           withCompleteBlock:(XLinkUserAuthorizeTaskCompletionHandler)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，使用+userAuthorizeTaskWithAccount:password:cropId:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end

NS_ASSUME_NONNULL_END
