//
//  XLinkMaxRetryTask.h
//  XLinkSDKQueue
//
//  Created by AllenKwok on 2017/4/21.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"

@interface XLinkMaxRetryTask : XLinkTask

@property(assign, nonatomic) NSUInteger maxRetryCount;

@end
