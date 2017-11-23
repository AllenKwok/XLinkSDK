//
//  XTaskQueueManager.h
//  TestOp
//
//  Created by AllenKwok on 2017/2/10.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "XLinkTask.h"

@interface XLinkTaskQueueManager : NSObject

/**
 单例对象
 */
+ (instancetype)shareManager;

- (void)submitTask:(XLinkTask *)task;

- (NSThread *)getDelayThread;

- (NSThread *)getDataParseThread;

- (void)stop;

- (void)start;

@end
