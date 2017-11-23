//
//  XLinkErrorCode.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/4/6.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#pragma once

typedef NS_ENUM(NSUInteger,XLinkErrorCode){
    XLinkErrorCodeNoError = 0,//没有错误
    XLinkErrorCodeTimeOut,//超时
    XLinkErrorCodeParamError,//参数错误
    XLinkErrorCodeTaskError,//任务失败
    XLinkErrorCodeSDKNotStarted,//SDK没有启动，请先启动sdk在完成操作
    XLinkErrorCodeSetAccessKeyFail,//设置AccessKey失败
    XLinkErrorCodeGetSubKeyFail,//获取subkey失败
    XLinkErrorCodeSubscribeDeviceFail,//订阅设备失败
    XLinkErrorCodeNotConfigCropId,//没有配置企业ID
    XLinkErrorCodeNotConfigSSLCertificateFilePath,//没有配置ssl证书
    XLinkErrorCodeCloudSeverLostConnect,//断开服务器连接
    XLinkErrorCodeCloudSeverConnectError,//服务器连接错误
    XLinkErrorCodeCloudSeverProtocolError,//协议错误
    XLinkErrorCodeCloudSeverKickDisconnect=13,//被服务器踢下线
    XLinkErrorCodeCloudSeverNotArrivable,//服务不可用，获取失败

    XLinkErrorCodeCloudSetDataPointNoPermissions,//未授予设置权限
    XLinkErrorCodeCloudSubDeviceInfoError,//订阅设备信息有误
    XLinkErrorCodeCloudSubTicketVerifyError,//订阅Ticket校验失败
    XLinkErrorCodeCloudSubDeviceError,//云端订阅设备失败
    XLinkErrorCodeCloudSubDeviceLimitError,//因设备扫描模式限制订阅失败
    XLinkErrorCodeCloudGetTicketFail,//获取Ticket失败
    
    XLinkErrorCodeLocalDeviceNotReady,//内网设备没有准备好
    XLinkErrorCodeLocalPairingNotFoundDevice,//没有搜索到设备
    XLinkErrorCodeLocalPairingNotInWifiEnvirment,//不在wifi连接的环境下
    XLinkErrorCodeConnectDeviceByCloudError,//云端连接设备不被授权
    XLinkErrorCodeCloudUnKnowError,//云端未知错误
    
    XLinkErrorCodeUnknownCoreErrorCode,//未知错误码
    XLinkErrorCodeUnsupportedProtocolVersion,//不支持协议版本
    
    XLinkErrorCodeLocalGetDeviceInfoFail,//获取设备信息失败
    XLinkErrorCodeLocalDeviceNotBound,//设备没有绑定
    XLinkErrorCodeLocalDeviceNotSet,//设备没有设置
    XLinkErrorCodeLocalPairingInvalidParam,//设备配对参数错误
    XLinkErrorCodeLocalPairingHandshakeFail,//设备配对握手失败
    XLinkErrorCodeLocalPairingFail,//设备配对失败
    XLinkErrorCodeLocalPairingLimitReached,//设备配对配对数已达上限
    XLinkErrorCodeLocalUnpairingFail,//设备取消配对失败
    XLinkErrorCodeLocalOpenSessionFail,//设备内网连接失败
    XLinkErrorCodeLocalCloseSessionFail,//设备内网断开连接失败
    XLinkErrorCodeLocalOpenSessionInvalidParam,//设备内网连接参数不合法
    XLinkErrorCodeLocalSessionDecryptFail,//设备内网数据加密失败
    XLinkErrorCodeLocalSessionEncryptFail,//设备内网数据解密失败
    XLinkErrorCodeLocalScanDeviceEmptyPid,//扫描到设备错误，pid空的
    XLinkErrorCodeLocalGetDataPointFail,//获取内网dataPoint失败
    XLinkErrorCodeLocalGetDataPointFlagError,//flag参数不支持
    XLinkErrorCodeLocalGetDataPointNoPermission,//未授予获取权限
    XLinkErrorCodeLocalSetDataPointFail,//设置内网dataPoint失败
    XLinkErrorCodeLocalSetDataPointNoPermission,//未授予设置权限
    XLinkErrorCodeLocalGetTicketFail,//内网获取ticket失败
    
    XLinkErrorCodeCloudDeviceOpenSessionFail,//设备云端连接失败
    XLinkErrorCodeCloudDeviceCloseSessionFail,//设备云端断开连接失败
    XLinkErrorCodeCloudConnectCloudFail,//设备云端连接失败
    XLinkErrorCodeCloudSubscribeDeviceFail,//设备订阅失败
    XLinkErrorCodeCloudGetDataPointFail,//获取云端dataPoint失败
    XLinkErrorCodeCloudSetDataPointFail,//设置云端dataPoint失败
    
    XLinkErrorCodeCloudLoginFail,//云端登陆失败
    XLinkErrorCodeCloudDisconnectCloudFail,//断开云端连接失败
    
    XLinkErrorCodeAuthCodeNotProvided,//没有提供AuthCode
    XLinkErrorCodeDeviceNotConnectedLocal,//设备本地没有连接
    XLinkErrorCodeDeviceNotConnectedCloud,//设备云端没有连接
    XLinkErrorCodeInviteCodeNotExist,//InviteCode不存在
    XLinkErrorCodeDeviceIdIsZero,//设备id为0
    
    
    /** Restful API*/
    /**
     * 网络Io错误
     */
    XLinkErrorCodeApiParamNetioError = 1001001,
    /**
     * 请求数据字段验证不通过
     */
    XLinkErrorCodeApiParamValidError = 4001001,
    /**
     * 请求数据必须字段不可为空
     */
    XLinkErrorCodeApiParamMustNotNull = 4001002,
    /**
     * 手机验证码不存在
     */
    XLinkErrorCodeApiPhoneVerifyCodeNotExists = 4001003,
    /**
     * 手机验证码错误
     */
    XLinkErrorCodeApiPhoneVerifyCodeError = 4001004,
    /**
     * 注册的手机号已存在
     */
    XLinkErrorCodeApiRegisterPhoneExists = 4001005,
    /**
     * 第三方要绑定手机号已存在
     */
    XLinkErrorCodeApiRegisterThirdpartyPhoneExists = 4001094,
    /**
     * 第三方要绑定邮箱已存在
     */
    XLinkErrorCodeApiRegisterThirdpartyEmailExists = 4001096,
    /**
     * 注册的邮箱已存在
     */
    XLinkErrorCodeApiRegisterEmailExists = 4001006,
    /**
     * 密码错误
     */
    XLinkErrorCodeApiAccountPasswordError = 4001007,
    /**
     * 密码重试次数过多
     */
    XLinkErrorCodeApiAccountPasswordRetryLimit = 4001061,
    /**
     * 帐号不合法
     */
    XLinkErrorCodeApiAccountVaildError = 4001008,
    /**
     * 企业成员状态不合法
     */
    XLinkErrorCodeApiMemberStatusError = 4001009,
    /**
     * 刷新Token不合法
     */
    XLinkErrorCodeApiRefreshTokenError = 4001010,
    /**
     * 未知成员角色类型
     */
    XLinkErrorCodeApiMemberRoleTypeUnkown = 4001011,
    /**
     * 只有管理员才能邀请
     */
    XLinkErrorCodeApiMemberInviteNotAdmin = 4001012,
    /**
     * 不可修改其他成员信息
     */
    XLinkErrorCodeApiCanNotModifyOtherMemberInfo = 4001013,
    /**
     * 不能删除本人
     */
    XLinkErrorCodeApiCanNotDeleteYourself = 4001014,
    /**
     * 未知的产品连接类型
     */
    XLinkErrorCodeApiProductLinkTypeUnkown = 4001015,
    /**
     * 已发布的产品不可删除
     */
    XLinkErrorCodeApiCanNotDeleteReleaseProduct = 4001016,
    /**
     * 固件版本已存在
     */
    XLinkErrorCodeApiFirmwareVersionExists = 4001017,
    /**
     * 数据端点未知数据类型
     */
    XLinkErrorCodeApiDatapointTypeUnkown = 4001018,
    /**
     * 数据端点索引已存在
     */
    XLinkErrorCodeApiDatapointIndexExists = 4001019,
    /**
     * 已发布的数据端点不可删除
     */
    XLinkErrorCodeApiCantNotDeleteReleasedDatapoint = 4001020,
    /**
     * 该产品下设备Mac地址已存在
     */
    XLinkErrorCodeApiDeviceMacAddressExists = 4001021,
    /**
     * 不能删除已激活的设备
     */
    XLinkErrorCodeApiCanNotDeleteActivatedDevice = 4001022,
    /**
     * 扩展属性Key为预留字段
     */
    XLinkErrorCodeApiPropertyKeyProtect = 4001023,
    /**
     * 设备扩展属性超过上限
     */
    XLinkErrorCodeApiPropertyLimit = 4001024,
    /**
     * 新增已存在的扩展属性
     */
    XLinkErrorCodeApiPropertyAddExists = 4001025,
    /**
     * 更新不存在的扩展属性
     */
    XLinkErrorCodeApiPropertyUpdateNotExists = 4001026,
    /**
     * 属性字段名不合法
     */
    XLinkErrorCodeApiPropertyKeyError = 4001027,
    /**
     * 邮件验证码不存在
     */
    XLinkErrorCodeApiEmailVerifyCodeNotExists = 4001028,
    /**
     * 邮件验证码错误
     */
    XLinkErrorCodeApiEmailVerifyCodeError = 4001029,
    /**
     * 用户状态不合法
     */
    XLinkErrorCodeApiUserStatusError = 4001030,
    /**
     * 用户手机尚未认证
     */
    XLinkErrorCodeApiUserPhoneNotVaild = 4001031,
    /**
     * 用户邮箱尚未认证
     */
    XLinkErrorCodeApiUserEmailNotVaild = 4001032,
    /**
     * 用户已经订阅设备
     */
    XLinkErrorCodeApiUserHasSubscribeDevice = 4001033,
    /**
     * 用户没有订阅该设备
     */
    XLinkErrorCodeApiUserHaveNoSubscribeDevice = 4001034,
    /**
     * 自动升级任务名称已存在
     */
    XLinkErrorCodeApiUpgradeTaskNameExists = 4001035,
    /**
     * 升级任务状态未知
     */
    XLinkErrorCodeApiUpgradeTaskStatusUnkown = 4001036,
    /**
     * 已有相同的起始版本升级任务
     */
    XLinkErrorCodeApiUpgradeTaskHaveStartingVersion = 4001037,
    /**
     * 设备激活失败
     */
    XLinkErrorCodeApiDeviceActiveFail = 4001038,
    /**
     * 设备认证失败
     */
    XLinkErrorCodeApiDeviceAuthFail = 4001039,
    /**
     * 订阅设备认证码错误
     */
    XLinkErrorCodeApiSubscribeAuthorizeCodeError = 4001041,
    /**
     * 授权名称已存在
     */
    XLinkErrorCodeApiEmpowerNameExists = 4001042,
    /**
     * 该告警规则名称已存在
     */
    XLinkErrorCodeApiAlarmRuleNameExists = 4001043,
    /**
     * 数据变名称已存在
     */
    XLinkErrorCodeApiDataTableNameExists = 4001045,
    /**
     * 产品固件文件超过大小限制
     */
    XLinkErrorCodeApiProductFirmwareFileSizeLimit = 4001046,
    /**
     * Apn密钥文件超过大小限制
     */
    XLinkErrorCodeApiAppApnLicenseFileSizeLimit = 4001047,
    /**
     * App的Apn功能未启用
     */
    XLinkErrorCodeApiAppApnIsNotEnable = 4001048,
    /**
     * 产品未允许用户注册设备
     */
    XLinkErrorCodeApiProductCanNotRegisterDevice = 4001049,
    /**
     * 禁止访问
     */
    XLinkErrorCodeApiInvalidAccess = 4031001,
    /**
     * 禁止访问，需要Access-Token
     */
    XLinkErrorCodeApiNeedAccessToken = 4031002,
    /**
     * 无效的Access-Token
     */
    XLinkErrorCodeApiAccessTokenInvalid = 4031003,
    /**
     * 需要企业的调用权限
     */
    XLinkErrorCodeApiNeedCorpApi = 4031004,
    /**
     * 需要企业管理员权限
     */
    XLinkErrorCodeApiNeedCorpAdminMember = 4031005,
    /**
     * 需要数据操作权限
     */
    XLinkErrorCodeApiNeedDataPermission = 4031006,
    /**
     * 禁止访问私有数据
     */
    XLinkErrorCodeApiInvalidAccessPrivateData = 4031007,
    /**
     * 分享已经被取消
     */
    XLinkErrorCodeApiShareCanceled = 4031008,
    /**
     * 分享已经接受
     */
    XLinkErrorCodeApiShareAccepted = 4031009,
    /**
     * 分享无效
     */
    XLinkErrorCodeApiShareInvaild = 4031012,
    /**
     * Url找不到
     */
    XLinkErrorCodeApiUrlNotFound = 4041001,
    /**
     * 企业成员帐号不存在
     */
    XLinkErrorCodeApiMemberAccountNoExists = 4041002,
    /**
     * 企业成员不存在
     */
    XLinkErrorCodeApiMemberNotExists = 4041003,
    /**
     * 激活的成员邮箱不存在
     */
    XLinkErrorCodeApiMemberInviteEmailNotExists = 4041004,
    /**
     * 产品信息不存在
     */
    XLinkErrorCodeApiProductNotExists = 4041005,
    /**
     * 产品固件不存在
     */
    XLinkErrorCodeApiFirmwareNotExists = 4041006,
    /**
     * 数据端点不存在
     */
    XLinkErrorCodeApiDatapointNotExists = 4041007,
    /**
     * 设备不存在
     */
    XLinkErrorCodeApiDeviceNotExists = 4041008,
    /**
     * 设备扩展属性不存在
     */
    XLinkErrorCodeApiDevicePropertyNotExists = 4041009,
    /**
     * 企业不存在
     */
    XLinkErrorCodeApiCorpNotExists = 4041010,
    /**
     * 用户不存在
     */
    XLinkErrorCodeApiUserNotExists = 4041011,
    /**
     * 用户扩展属性不存在
     */
    XLinkErrorCodeApiUserPropertyNotExists = 4041012,
    /**
     * 升级任务不存在
     */
    XLinkErrorCodeApiUpgradeTaskNotExists = 4041013,
    /**
     * 第三方身份授权不存在
     */
    XLinkErrorCodeApiEmpowerNotExists = 4041014,
    /**
     * 告警规则不存在
     */
    XLinkErrorCodeApiAlarmRuleNotExists = 4041015,
    /**
     * 数据表不存在
     */
    XLinkErrorCodeApiDataTableNotExists = 4041016,
    /**
     * 数据不存在
     */
    XLinkErrorCodeApiDataNotExists = 4041017,
    /**
     * 分享资源不存在
     */
    XLinkErrorCodeApiShareNotExists = 4041018,
    /**
     * 企业邮箱不存在
     */
    XLinkErrorCodeApiCorpEmailNotExists = 4041019,
    /**
     * App不存在
     */
    XLinkErrorCodeApiAppNotExists = 4041020,
    /**
     * 第三方授权错误
     */
    XLinkErrorCodeApiThirdPartyOpenIdExistOther = 4001125,
    XLinkErrorCodeApiThirdPartyOpenIdExistQq = 4001126,
    XLinkErrorCodeApiThirdPartyOpenIdExistWx = 4001127,
    XLinkErrorCodeApiThirdPartyOpenIdExistWb = 4001128,
    /**
     * 服务端发生异常
     */
    XLinkErrorCodeApiServiceException = 5031001,
    
} ;

 /* XLinkErrorCode_h */
