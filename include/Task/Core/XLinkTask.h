//
//  Task.h
//  TestTask
//
//  Created by AllenKwok on 2017/2/9.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkErrorCode.h"
@class XLinkTask;

typedef NS_ENUM(NSUInteger, TaskState) {
    TaskStateStart = 1,//任务启动
    TaskStateExecute,//任务执行
    TaskStateStop,//任务结束
};

typedef void (^OnTaskStartBlock) (void);
typedef void (^OnTaskCompleteBlock) (XLinkErrorCode code);
typedef void (^TimeoutBlock)(void);

@interface XLinkTask : NSObject
/**
 是否已经超时
 */
@property (assign, nonatomic) BOOL isTimeout;
/**
 是否已经完成
 */
@property (assign, nonatomic) BOOL isComplete;
/**
 *  默认0s
 */
@property (assign, nonatomic) NSUInteger timeout;

/**
 当前的重试次数
 */
@property (assign, nonatomic) NSUInteger currentRetryCount;

/**
 任务返回的结果
 */
@property (strong, nonatomic) id result;
@property (strong, nonatomic) NSError *error;


#pragma mark - callback
/**
 task开始的回调
 */
@property (copy, nonatomic) OnTaskStartBlock taskStartBlock;
- (void)setTaskStartBlock:(OnTaskStartBlock)taskStartBlock;

/**
 task完成的回调
 */
@property (copy, nonatomic) OnTaskCompleteBlock taskCompleteBlock;
- (void)setTaskCompleteBlock:(OnTaskCompleteBlock)taskCompleteBlock;

/**
 任务超时之后的回调
 */
@property (copy, nonatomic) TimeoutBlock timeoutBlock;
- (void)setTimeoutBlock:(TimeoutBlock)timeoutBlock;

#pragma mark - 内部函数 以下函数不要重写

/**
 总的运行函数
 */
- (void)main;

/**
 是否重试
 */
- (BOOL)onRetry;

/**
 任务开始
 */
- (void)onStart;

/**
 任务完成
 */
- (void)onComplete;


/**
 任务超时
 */
- (void)onTaskTimeOut;

#pragma mark - 外部函数

/**
 开始
 */
- (void)start;

/**
 取消
 */
- (void)cancel;

/**
 执行所需操作的函数入口
 */
- (void)execute;

@end
