//
//  XLinkSendPolicyTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/8/22.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"

#pragma mark - XLinkRetryUntilTimeoutTaskDataSource

@protocol XLinkSendPolicyTaskDataSource <NSObject>
/**
 通过本地发送数据，需子类重写
 */
- (void)sendDataByLocal;

/**
 通过云端发送数据，需子类重写
 */
- (void)sendDataByCloud;

/**
 本地发送数据失败
 */
- (void)sendDataByLocalDidFail;

/**
 云端发送数据失败
 */
- (void)sendDataByCloudDidFail;

@end

@interface XLinkSendPolicyTask : XLinkTask <XLinkSendPolicyTaskDataSource>


@end
