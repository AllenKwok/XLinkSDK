//
//  SubscriptionChangeNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/16.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, SubscriptionChangeType) {
    SubscriptionChangeTypeCancel = 0,//订阅关系取消
    SubscriptionChangeTypeEstablish = 1//订阅关系建立
};

@interface SubscriptionChangeNotify : NSObject

/**
 设备id
 */
@property (copy, nonatomic) NSNumber *deviceId;

/**
 订阅关系变化类型
 */
@property (assign, nonatomic) SubscriptionChangeType changeType;

@end
