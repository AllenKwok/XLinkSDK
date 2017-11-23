//
//  XLinkConfig.h
//  XLinkSdkLib
//
//  Created by AllenKwok on 2017/2/5.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkUserModel.h"
/**
 * 数据发送策略。默认为AUTO
 */
typedef NS_ENUM(NSUInteger,XLinkSendDataPolicy) {
    XLinkSendDataPolicyAuto,    /** 自动选择发送数据的通道（内/外网）。选择的依据是当前通道的RTT(Round-Trip Time，往返时延） RTT低的通道会被选中。*/
    XLinkSendDataPolicyLocalOnly,//只尝试从内网发送。
    XLinkSendDataPolicyCloudOnly, //只尝试从外网发送。
    XLinkSendDataPolicyLocalFirst,//尝试从内网发送，失败则尝试外网发送。
    XLinkSendDataPolicyCloudFirst //尝试从外网发送，失败则尝试内网发送。
} ;


@interface XLinkConfig : NSObject

#pragma mark - 服务器信息
/**
 http API服务器地址，默认值为https://api2.xlink.cn:443
 */
@property (copy, nonatomic) NSString *apiServer;

/**
 云端服务器地址 默认值为mqtt.xlink.cn
 */
@property (copy, nonatomic) NSString *cloudServer;

/**
 云端服务器端口 默认值为1883
 */
@property (copy, nonatomic) NSString *cloudServerPort;

/**
 云端keepAlive时间，默认为60秒,最小值为20秒。
 */
@property (assign, nonatomic)NSUInteger keepAliveInterval;

/**
 开启HTTP隧道，默认值为NO
 */
@property (assign, nonatomic) BOOL enableHTTPTunnel;

#pragma mark - 发送数据配置

/**
 发送数据策略，默认为XLinkSendDataPolicyAuto
 */
@property (assign, nonatomic) XLinkSendDataPolicy sendDataPolicy;

#pragma mark - 用户账号信息
/**
 企业ID，默认值为nil。
 */
@property (copy, nonatomic) NSString *corpId;

/**
 用户model，用于重新登录时候，传入之前保存的用户信息进行登录操作。
 */
@property (strong, nonatomic) XLinkUserModel *userModel;


#pragma mark - SSL设置
/**
 是否使用SSL，默认值为NO
 */
@property (assign, nonatomic) BOOL enableSSL;

/**
 设置SSL证书路径，默认值为nil。
 */
@property (copy, nonatomic) NSString *SSLCertificateFilePath;
/**
 设置SSL证书密码，默认值为nil。
 */
@property (copy, nonatomic) NSString *SSLCertificateFilePassphrase;

#pragma mark - log
/**
 是否打印sdk内部日志，默认值Debug模式下为YES，Release模式下为NO。
 */
@property (assign, nonatomic) BOOL debug;

/**
 在SDK进入后台之后，是否需要建立一个BackgroundTask，以维持短暂的运行时间。这个运行时间取决于系统分配的时间，会在10分钟以内。
 */
@property (assign, nonatomic) BOOL shouldBeginBackgroundTask;

/**
 默认配置
 
 @return xlink 配置
 */
+(instancetype)defaultConfig;


@end
