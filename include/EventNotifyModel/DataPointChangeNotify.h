//
//  DataPointChangeNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/16.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 设备数据端点变化发送的通知
 */
@interface DataPointChangeNotify : NSObject

/**
 变化数据端点的index
 */
@property (assign, nonatomic) NSUInteger index;
/**
 变化数据端点的数据
 */
@property (copy, nonatomic) NSNumber *value;

/**
 管理台设置的报警内容
 */
@property (copy, nonatomic) NSString *alarmMessage;

@end
