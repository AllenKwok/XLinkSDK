//
//  BackoffTask.h
//  TestTaskQueue
//
//  Created by AllenKwok on 2017/4/21.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "MaxRetryTask.h"

@interface BackoffTask : MaxRetryTask

//task重试间隔值,默认1s
@property (assign, nonatomic) NSUInteger initInterval;

@end
