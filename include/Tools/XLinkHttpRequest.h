//
//  XLinkHttpRequest.h
//  XLinkHttpRequest
//
//  Created by xtmac on 29/10/15.
//  Copyright (c) 2015年 xtmac. All rights reserved.
//

#import <Foundation/Foundation.h>

#define RequestTypeGet  @"GET"
#define RequestTypePUT  @"PUT"
#define RequestTypePOST @"POST"
#define RequestTypeDelete @"DELETE"

typedef void (^RequestCompleteBlock) (id result, NSError *err);

typedef NS_ENUM(NSUInteger,ThirdAccountSource) {
    ThirdAccountSourceWeChat = 4,
    ThirdAccountSourceQQ = 5,
    ThirdAccountSourceWeibo = 6,
    ThirdAccountSourceOther = 10
} ;

@interface DeviceObject : NSObject

@property (copy, nonatomic) NSString *product_id;
@property (copy, nonatomic) NSString *mac;
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSNumber *access_key;
@property (copy, nonatomic) NSString *mcu_mod;
@property (copy, nonatomic) NSString *mcu_version;
@property (copy, nonatomic) NSString *firmware_mod;
@property (copy, nonatomic) NSString *firmware_version;

- (instancetype)initWithProductID:(NSString *)product_id withMac:(NSString *)mac withAccessKey:(NSNumber *)accessKey;

@end

@interface XLinkHttpRequest : NSObject


#pragma mark
#pragma mark 错误信息

/**
 *  获取错误信息
 *
 *  @param errCode 错误码
 *
 *  @return 错误信息
 */
+ (NSString *)getErrorInfoWithErrorCode:(NSInteger)errCode;


#pragma mark - 用户操作

/**
 *  用户请求发送验证码（邮箱方式不需要获取验证码）
 *
 *  @param phone   手机号码
 *  @param captcha 图片验证码
 *  @param block   完成后的回调
 */
+ (void)getVerifyCodeWithPhone:(NSString *)phone withCaptcha:(NSString *)captcha didLoadData:(RequestCompleteBlock)block;

/**
 *  请求或刷新发送注册短信的图片验证码
 *  当请求发送注册手机验证码达到一定的次数后，需要进行图片验证码进行验证，本接口用于获取图片验证码。
 *
 *  @param phone 手机号
 *  @param block 完成后的回调
 */
+ (void)getCaptchaWithPhone:(NSString *)phone didLoadData:(RequestCompleteBlock)block;

/**
 *  注册账号
 *
 *  @param account    账号：手机号码/邮箱地址
 *  @param nickname   昵称
 *  @param verifyCode 验证码（邮箱注册不需要验证码）
 *  @param pwd        密码
 *  @param block      完成后的回调
 */
+ (void)registerWithAccount:(NSString *)account withNickname:(NSString *)nickname withVerifyCode:(NSString *)verifyCode withPassword:(NSString *)pwd didLoadData:(RequestCompleteBlock)block;

/**
 注册邮箱

 @param eamil 邮箱
 @param nickname 昵称
 @param pwd 认证密码
 @param localLan 本地语言代码
 @param block 完成后的回调
 */
+ (void)registerWithEmail:(NSString *)eamil withNickname:(NSString *)nickname withPassword:(NSString *)pwd withLocalLang:(NSString *)localLan didLoadData:(RequestCompleteBlock)block;

/**
 *  用户认证(登录)
 *
 *  @param account 账号 : 手机号码/邮箱地址
 *  @param pwd     密码
 *  @param block   完成后的回调
 */
+ (void)authWithAccount:(NSString *)account withPassword:(NSString *)pwd didLoadData:(RequestCompleteBlock)block;


/**
 刷新凭证

 @param refreshToken 刷新凭证
 @param block 完成后的回调
 */
+ (void)refreshAccessTokenWithRefreshToken:(NSString *)refreshToken didLoadData:(RequestCompleteBlock)block;

/**
 *  修改账号昵称
 *
 *  @param nickname    要修改的昵称
 *  @param userID      用户ID
 *  @param accessToken 调用凭证
 */
+ (void)modifyAccountNickname:(NSString *)nickname withUserID:(NSNumber *)userID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  重置密码
 *
 *  @param oldPwd      旧密码
 *  @param newPwd      新密码
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)resetPasswordWithOldPassword:(NSString *)oldPwd withNewPassword:(NSString *)newPwd withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  忘记密码(获取重置密码的验证码)
 *
 *  @param account     忘记密码的账号
 *  @param captcha     图形验证码，非必填
 *  @param block       完成后的回调
 */
+ (void)forgotPasswordWithAccount:(NSString *)account withCaptcha:(NSString *)captcha didLoadData:(RequestCompleteBlock)block;


/**
 忘记密码

 @param email 邮箱
 @param captcha 图形验证码，非必填
 @param localLang 邮件语言选择
 @param block 完成后的回调
 */
+ (void)forgotPasswordWithEmail:(NSString *)email withCaptcha:(NSString *)captcha withLocalLang:(NSString *)localLang didLoadData:(RequestCompleteBlock)block;

/**
 *  找回密码(根据获取到的验证码设置新密码)
 *
 *  @param account     要找回密码的账号
 *  @param verifyCode  验证码
 *  @param pwd         要设置的新密码
 *  @param block       完成后的回调
 */
+ (void)foundBackPasswordWithAccount:(NSString *)account withVerifyCode:(NSString *)verifyCode withNewPassword:(NSString *)pwd didLoadData:(RequestCompleteBlock)block;

/**
 14、设置用户扩展属性
 
 @param dic 扩展属性
 @param userID 用户ID
 @param accessToken 调用凭证
 @param block 完成后回调
 */
+ (void)setUserPropertyDictionary:(NSDictionary *)dic withUserID:(NSNumber *)userID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  15、获取用户扩展属性
 *
 *  @param userID      用户ID
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)getUserPropertyWithUserID:(NSNumber *)userID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  16、修改用户扩展属性
 *
 *  @param dic         扩展属性字典
 *  @param userID      用户ID
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)modifyUserPropertyDictionary:(NSDictionary *)dic withUserID:(NSNumber *)userID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  17、获取用户单个扩展属性
 *
 *  @param userID      用户ID
 *  @param key         属性Key值
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)getUserSinglePropertyWithUserID:(NSNumber *)userID withPropertyKey:(NSString *)key withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  18、删除用户扩展属性
 *
 *  @param userID      用户ID
 *  @param key         属性Key值
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)delUserPropertyWithUserID:(NSNumber *)userID withPropertyKey:(NSString *)key withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;


/**
 *  请求发送验证码
 *
 *  @param accessToken 调用凭证
 *  @param userId      用户id
 *  @param account     手机号码
 *  @param block       完成后回调
 */
+ (void)requestSendVerifyCodeWithAccessToken:(NSString *)accessToken WithUserId:(NSNumber *)userId withAccount:(NSString *)account didLoadData:(RequestCompleteBlock)block;


/**
 请求或刷新请求密码找回所需的图片验证码
 
 @param phone 手机号码
 @param block 完成后回调
 */
+ (void)getForgotPasswordCaptchaWithPhone:(NSString *)phone didLoadData:(RequestCompleteBlock)block;

/**
 *  通过验证码修改 修改邮箱/手机号码
 *
 *  @param accessToken 调用凭证
 *  @param userId      用户id
 *  @param account     邮箱/手机号码
 *  @param verifycode  验证码
 *  @param block       完成后回调
 */
+ (void)modifyAccountWithAccessToken:(NSString *)accessToken WithUserId:(NSNumber *)userId withAccount:(NSString *)account withPassword:(NSString *)password withVerifyCode:(NSString *)verifycode didLoadData:(RequestCompleteBlock)block;

/**
 *  获取用户详细信息
 *
 *  @param userID      用户id
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)getUserInfoWithUserID:(NSNumber *)userID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  获取用户公开信息
 *
 *  @param userID      用户id
 *  @param block       完成后的回调
 */
+ (void)getUserOpenInfoWithUserID:(NSNumber *)userID didLoadData:(RequestCompleteBlock)block;

/**
 *  上传用户头像
 *
 *  @param accessToken 调用凭证
 *  @param imageData   头像图片的二进制数据
 *  @param block       完成后的回调
 */
+ (void)uploadAvatarWithAccessToken:(NSString *)accessToken withImageData:(NSData *)imageData didLoadData:(RequestCompleteBlock)block;

#pragma mark - 第三方账号

/**
 初始化密码并且绑定手机号码
 
 @param accessToken 刷新凭证
 @param userId 用户id
 @param phone 手机号码
 @param zone 手机时区        可选
 @param verifycode 验证码
 @param password 密码
 @param nickname 昵称       可选
 @param block 完成后的回调
 */
+ (void)initPasswordAndBindPhoneWithAccessToken:(NSString *)accessToken withUserId:(NSNumber *)userId withPhone:(NSString *)phone withPhone_Zone:(NSString *)zone withVerifyCode:(NSString *)verifycode withPassword:(NSString *)password withNickname:(NSString *)nickname didLoadData:(RequestCompleteBlock)block;

/**
 *  第三方用户登录云智易接口
 *
 *  @param type    用户来源
 *  @param open_id 	第三方用户开放ID
 *  @param token   第三方用户Token
 *  @param name    第三方用户昵称，可选
 *  @param block   完成后的回调
 */
+ (void)authFromThirdWithSource:(NSNumber *)type open_id:(NSString *)open_id token:(NSString *)token name:(NSString *)name didLoadData:(RequestCompleteBlock)block;

/**
 *  第三方用户初始化登录密码
 *
 *  @param userId      用户id
 *  @param password    密码
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+(void)thirdSourceAccountInitPasswordWithUserid:(NSNumber *)userId withPassword:(NSString *)password withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  绑定第三方账号
 用户在登录的情况下，通过授权绑定第三方账户，绑定成功后，该用户账号可用第三方帐号登录。
 第三方平台一般指：QQ、微信、微博以及满足XLINK平台第三方帐号认证规范的平台。
 *
 *  @param userId           用户id
 *  @param accessToken      调用凭证
 *  @param openId           第三方帐号OpenID
 *  @param thirdAccessToken 第三方平台返回凭证
 *  @param source           第三方来源
 *  @param block            完成后的回调
 */
+ (void)bindThirdAccountWithUserId:(NSNumber *)userId withAccessToken:(NSString *)accessToken withOpenId:(NSString *)openId withThirdAccountAccessToken:(NSString *)thirdAccessToken withSource:(ThirdAccountSource)source didLoadData:(RequestCompleteBlock)block;


/**
 *  解绑第三方账号
 *
 *  @param userId      用户id
 *  @param accessToken 调用凭证
 *  @param source      第三方来源
 *  @param block       完成后的回调
 */
+ (void)unbindThirdAccountWithUserId:(NSNumber *)userId withAccessToken:(NSString *)accessToken withSource:(ThirdAccountSource)source didLoadData:(RequestCompleteBlock)block;

#pragma mark-第三方登录（用于海外的平台，Facebook和Twitter）
/**
 第三方登录
 
 @param content 请求内容
 @param block 完成后的回调
 */
+(void)authFromThirdForeignWithContent:(NSMutableDictionary *)content didLoadData:(RequestCompleteBlock)block;

/**
 绑定国外的第三方帐号
 
 @param userId 用户id
 @param accessToken 调用凭证
 @param content 请求内容
 @param block 完成后的回调
 */
+ (void)bindThirdAccountWithUserId:(NSNumber *)userId withAccessToken:(NSString *)accessToken withContent:(NSMutableDictionary *)content didLoadData:(RequestCompleteBlock)block;

#pragma mark - 设备操作

/**
 *  删除设备（取消订阅）
 *
 *  @param userID      用户ID
 *  @param accessToken 调用凭证
 *  @param deviceID    设备ID
 *  @param block       完成后的回调
 */
+ (void)delDeviceWithUserID:(NSNumber *)userID withAccessToken:(NSString *)accessToken withDeviceID:(NSNumber *)deviceID didLoadData:(RequestCompleteBlock)block;

/**
 *  9、取消订阅
 *
 *  @param userID      用户ID
 *  @param accessToken 调用凭证
 *  @param deviceID    设备ID
 *  @param block       完成后的回调
 */
+ (void)unsubscribeDeviceWithUserID:(NSNumber *)userID withAccessToken:(NSString *)accessToken withDeviceID:(NSNumber *)deviceID didLoadData:(RequestCompleteBlock)block;


/**
 *  7、设置设备扩展属性
 *
 *  @param dic         属性字典
 *  @param deviceID    设备ID
 *  @param productID   设备的产品ID
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)setDevicePropertyDictionary:(NSDictionary *)dic withDeviceID:(NSNumber *)deviceID withProductID:(NSString *)productID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  8、获取设备扩展属性
 *
 *  @param deviceID    设备ID
 *  @param productID   设备的产品ID
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)getDevicePropertyWithDeviceID:(NSNumber *)deviceID withProductID:(NSString *)productID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  9、修改设备扩展属性
 *
 *  @param dic         属性字典
 *  @param deviceID    设备ID
 *  @param productID   设备的产品ID
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)modifyDevicePropertyDictionary:(NSDictionary *)dic withDeviceID:(NSNumber *)deviceID withProductID:(NSString *)productID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  修改设备
 *
 *  @param deviceName  设备名称
 *  @param deviceID    设备ID
 *  @param productID   设备的产品ID
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)modifyDeviceNameWithName:(NSString *)deviceName withDeviceID:(NSNumber *)deviceID withProductID:(NSString *)productID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;


/**
 *  注册设备
 *
 *  @param userID       用户ID
 *  @param accessToken  调用凭证
 *  @param deviceObject 要注册的设备
 *  @param block        完成后的回调
 */
+ (void)registerDeviceWithUserID:(NSNumber *)userID withAccessToken:(NSString *)accessToken withDevice:(DeviceObject *)deviceObject didLoadData:(RequestCompleteBlock)block;


/**
 通过二维码订阅设备

 @param user_id 用户id
 @param access_token 调用凭证
 @param qr_code 二维码字符串
 @param block 完成后的回调
 */
+ (void)subscribeDeviceWithUserID:(NSNumber *)user_id accessToken:(NSString *)access_token QRCode:(NSString *)qr_code didLoadData:(RequestCompleteBlock)block;

/**
 *  获取单个设备详细信息
 *
 *  @param productID  设备的产品ID
 *  @param deviceID    设备ID
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)getDeviceInfoWithDeviceID:(NSNumber *)deviceID withProductID:(NSString *)productID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;


/**
 *  获取设备列表
 *
 *  @param userID      用户ID
 *  @param accessToken 调用凭证
 */
+ (void)getDeviceListWithUserID:(NSNumber *)userID withVersion:(uint16_t)version withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;


/**
 获取设备列表

 @param userID 用户ID
 @param version 版本号
 @param filter 过滤字段，以逗号分隔
 @param accessToken 调用凭证
 @param block 完成后回调
 */
+ (void)getDeviceListWithUserID:(NSNumber *)userID withVersion:(uint16_t)version withFilter:(NSString *)filter withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  获取设备列表
 *
 *  @param userID      用户ID
 *  @param accessToken 调用凭证
 *  @param version     当前列表的版本号，根据当前版本号判定列表有无更改。
 *  @param block       完成后的回调
 */
+ (void)getDeviceListWithUserID:(NSNumber *)userID withAccessToken:(NSString *)accessToken withVersion:(NSNumber *)version didLoadData:(RequestCompleteBlock)block;


/**
 *  设置设备扩展属性
 *
 *  @param dic         属性字典
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)setDevicePropertyDictionary:(NSDictionary *)dic withProductID:(NSString *)product_id withDeviceID:(NSNumber *)deviceID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;


/**
 *  删除设备扩展属性
 *
 *  @param key         属性字典
 *  @param product_id  productID
 *  @param deviceID    deviceID
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)delDevicePropertyKey:(NSString *)key withProductID:(NSString *)product_id withDeviceID:(NSNumber *)deviceID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;


/**
 *  获取设备扩展属性
 *
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)getDevicePropertyWithProductID:(NSString *)product_id withDeviceID:(NSNumber *)deviceID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  修改设备扩展属性
 *
 *  @param dic         属性字典
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)modifyDevicePropertyDictionary:(NSDictionary *)dic withProductID:(NSString *)product_id withDeviceID:(NSNumber *)deviceID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  获取设备告警日志列表
 *
 *  @param product_id  产品id
 *  @param deviceID    设备id
 *  @param dic         查询条件
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)getDeviceAlertLogsWithProductID:(NSString *)product_id withDeviceID:(NSNumber *)deviceID withQueryDict:(NSDictionary *)dic withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;


/**
 获取数据端点列表

 @param product_id 产品id
 @param accessToken 调用凭证
 @param block 完成后的回调
 */
+ (void)getDeviceDataPointsWithProductID:(NSString *)product_id  withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  获取设备数据快照
 *
 *  @param product_id  产品id
 *  @param deviceID    设备id
 *  @param dic         查询条件
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)getDeviceSnapShotWithProductID:(NSString *)product_id withDeviceID:(NSNumber *)deviceID withQueryDict:(NSDictionary *)dic withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  分享设备
 *
 *  @param deviceID    被分享的设备的ID
 *  @param accessToken 调用凭证
 *  @param account     被分享的用户的账号
 *  @param mode        app/qrcode/email
 *  @param expire      分享消息的有效时间
 *  @param authority   对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 *  @param extend      扩展信息
 *  @param block       完成后的回调
 */
+ (void)shareDeviceWithDeviceID:(NSNumber *)deviceID withAccessToken:(NSString *)accessToken withShareUserAccount:(NSString *)account withMode:(NSString *)mode withExpire:(NSString *)expire withExtend:(NSString *)extend withAuthority:(NSString *)authority didLoadData:(RequestCompleteBlock)block;


/**
 分享到给用户

 @param deviceID 设备id
 @param accessToken token
 @param account 被分享的用户的账号，可以是手机号，邮箱或者open_id
 @param sourceType 用户身份来源
 @param mode        app/qrcode/email
 @param expire      分享消息的有效时间
 @param authority   对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 @param extend      扩展信息
 @param block       完成后的回调
 */
+ (void)shareDeviceWithDeviceID:(NSNumber *)deviceID withAccessToken:(NSString *)accessToken withShareUserAccount:(NSString *)account withSourceType:(int)sourceType withMode:(NSString *)mode withExpire:(NSString *)expire withExtend:(NSString *)extend withAuthority:(NSString *)authority didLoadData:(RequestCompleteBlock)block;

/**
 *  取消分享
 *
 *  @param accessToken 调用凭证
 *  @param inviteCode  分享码
 *  @param block       完成后的回调
 */
+ (void)cancelShareDeviceWithAccessToken:(NSString *)accessToken withInviteCode:(NSString *)inviteCode didLoadData:(RequestCompleteBlock)block;

/**
 *  接受分享
 *
 *  @param inviteCode  分享码
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)acceptShareWithInviteCode:(NSString *)inviteCode withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  拒绝分享
 *
 *  @param inviteCode  分享码
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)denyShareWithInviteCode:(NSString *)inviteCode withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  获取分享列表
 *
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)getShareListWithAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  管理员或用户删除这条分享记录
 *
 *  @param inviteCode  邀请码inviteCode
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)delShareRecordWithInviteCode:(NSString *)inviteCode WithAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;


/**
 *  设备清除所有订阅用户
 *
 *  @param accessToken 调用凭证
 *  @param product_id  产品id
 *  @param deviceID    设备id
 *  @param block       完成后的回调
 */
+ (void)delAllSubscribeWithAccessToken:(NSString *)accessToken withProductID:(NSString *)product_id withDeviceID:(NSNumber *)deviceID didLoadData:(RequestCompleteBlock)block;


/**
 *  获取某个设备订阅用户的列表。该设备需要是调用这个接口的用户已经订阅过的设备
 *
 *  @param deviceID    需要查询的设备ID
 *  @param userID      用户ID
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)getUserListWithDeviceID:(NSNumber *)deviceID withUserID:(NSNumber *)userID withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  订阅设备
 *
 *  @param userID        用户ID
 *  @param accessToken   调用凭证
 *  @param authorizeCode 设备认证码
 *  @param deviceID      设备ID
 *  @param block         完成后的回调
 */
+ (void)subscribeDeviceWithUserID:(NSNumber *)userID withAccessToken:(NSString *)accessToken withDeviceAuthorizeCode:(NSString *)authorizeCode withDeviceID:(NSNumber *)deviceID didLoadData:(RequestCompleteBlock)block;

#pragma mark - APNS

/**
 *  用户注册APN服务
 *
 *  @param userid      用户id
 *  @param accessToken accessToken
 *  @param AppId       用户在XLINK平台创建APP开发时，获取到的ID
 *  @param devicetoken iOS APP 运行时获取到的device_token
 *  @param block       完成后的回调
 */
+ (void)registerApnSeverWithUserId:(NSNumber *)userid withAccessToken:(NSString *)accessToken withAppId:(NSString *)AppId withDeviceToken:(NSString *)devicetoken didLoadData:(RequestCompleteBlock)block;


/**
 *  用户取消注册APN服务
 *
 *  @param userid      用户id
 *  @param accessToken accessToken
 *  @param AppId       用户在XLINK平台创建APP开发时，获取到的ID
 *  @param block       完成后的回调
 */
+ (void)unregisterApnSeverWithUserId:(NSNumber *)userid withAccessToken:(NSString *)accessToken withAppId:(NSString *)AppId didLoadData:(RequestCompleteBlock)block;


/**
 *  获取设备的固件版本
 *
 *  @param device_id   设备ID
 *  @param product_id  PID
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)getVersionWithDeviceID:(NSString *)device_id withProduct_id:(NSString *)product_id withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;


/**
 *  升级设备的固件版本
 *
 *  @param device_id   设备ID
 *  @param product_id  PID
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)upgradeWithDeviceID:(NSString *)device_id withProduct_id:(NSString *)product_id withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

/**
 *  XFile上传
 *
 *  @param data        文件二进制数据
 *  @param accessToken 调用凭证
 *  @param block       完成后的回调
 */
+ (void)uploadFileWithData:(NSData *)data withAccessToken:(NSString *)accessToken didLoadData:(RequestCompleteBlock)block;

#pragma mark - tools

/**
 验证手机号码格式是否正确
 
 @param phone 手机号码
 @return 是否正确
 */
+ (BOOL)validatePhone:(NSString *)phone;

/**
 验证邮箱格式是否正确
 
 @param email 邮箱
 @return 是否正确
 */
+ (BOOL)validateEmail:(NSString *)email;


/**
 进行网络请求

 @param reType 请求类型
 @param url 请求地址
 @param header 请求头
 @param content 请求内容
 @param block 完成后的回调
 */
+(void)requestWithRequestType:(NSString *)reType withUrl:(NSString *)url withHeader:(NSDictionary *)header withContent:(id)content withDidLoadData:(RequestCompleteBlock)block;


/**
 进行网络请求
 
 @param reType 请求类型
 @param url 请求地址
 @param header 请求头
 @param content 请求内容
 @param timeout 超时时间
 @param block 完成后的回调
 */
+(void)requestWithRequestType:(NSString *)reType withUrl:(NSString *)url withHeader:(NSDictionary *)header withContent:(id)content withTimeout:(NSUInteger)timeout withDidLoadData:(RequestCompleteBlock)block;

@end


