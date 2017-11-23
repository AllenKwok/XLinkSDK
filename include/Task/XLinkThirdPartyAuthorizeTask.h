//
//  XLinkThirdPartyAuthorizeTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/6/5.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"

typedef NS_ENUM(NSUInteger,XLinkUserSourceType){
    XLinkUserSourceTypeWeb         = 1, //web
    XLinkUserSourceTypeAndroid     = 2, //Android客户端
    XLinkUserSourceTypeIOS         = 3, //IOS客户端
    XLinkUserSourceTypeWechat      = 4, //微信用户
    XLinkUserSourceTypeQQ          = 5, //QQ用户
    XLinkUserSourceTypeWeibo       = 6, //微博用户
    XLinkUserSourceTypeFacebook    = 7, //facebook用户
    XLinkUserSourceTypeTwitter     = 8, //twitter用户
    XLinkUserSourceTypeOthers      = 10,//其它遵循xlink统一身份认证规范的用户来源
} ;

typedef void (^OnUserAuthorizeTaskCompleteBlock) (id result, NSError *err);

@interface XLinkThirdPartyAuthorizeTask : XLinkTask


/**
 企业ID，默认值为nil。
 */
@property (copy, nonatomic) NSString *corpId;

/**
 用户来源，默认值为0。如果使用第三方账号登陆，参照XLinkUserSourceType填入对应的类型。
 */
@property (assign, nonatomic) XLinkUserSourceType sourceType;

/**
 第三方账号openid。
 */
@property (copy, nonatomic) NSString *openId;

/**
 第三方账号授权凭证。
 */
@property (copy, nonatomic) NSString *accessToken;

/**
 第三方账号昵称。
 */
@property (copy, nonatomic) NSString *nickNmae;

/**
 完成回调
 */
@property (copy, nonatomic) OnUserAuthorizeTaskCompleteBlock userAuthorizeTaskCompleteBlock;


/**
 第三方用户认证task

 @param userSourceType 用户来源
 @param openid 第三方账号openid
 @param accessToken 第三方账号授权凭证
 @param nickName 第三方账号昵称
 @param cropId 企业ID
 @param completeBlock 完成回调
 @return task
 */
+ (instancetype)thirdPartyUserAuthorizeTaskWithSource:(XLinkUserSourceType)userSourceType withOpenId:(NSString *)openid  withAccessToken:(NSString *)accessToken withNickName:(NSString *)nickName withCropId:(NSString *)cropId withTimeout:(NSUInteger)timeout withCompleteBlock:(OnUserAuthorizeTaskCompleteBlock)completeBlock;



@end
