//
//  RetryUntilTimeoutTask.h
//  TestTaskQueue
//
//  Created by AllenKwok on 2017/4/28.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "BackoffTask.h"

@interface RetryUntilTimeoutTask : BackoffTask

/**
 task总的超时时间
 */
@property (assign, nonatomic) NSUInteger totalTimeout;

- (void)onTotalTimeOut;

@end
