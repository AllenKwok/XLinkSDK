//
//  XLinkDataPointManager.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkDataPointObserver.h"
#import "XDevice.h"

@interface XLinkDataPointManager : NSObject

/**
 单例对象
 
 @return 单例对象
 */
+ (instancetype)shareManager;

/**
 停止管理，清除所有缓存
 */
- (void)stopManage;

/**
 所有的监听类对象
 */
@property(strong, nonatomic, readonly) NSMutableArray <XLinkDataPointObserver *> *observerArray;

/**
 添加一个dataPoint的监听
 
 @param dataPointObserver dataPoint的监听
 */
- (void)addDataPointObserver:(XLinkDataPointObserver *)dataPointObserver;

/**
 移除一个dataPoint的监听
 
 @param dataPointObserver dataPoint的监听
 */
- (void)removeDataPointObserver:(XLinkDataPointObserver *)dataPointObserver;

/**
 获取设备的dataPoint的模板
 
 @param device 设备
 @param block 完成后的回调
 */
- (void)getDataPointSourceWithDevice:(XDevice *)device withFinishBlock:(void (^)(NSArray <XLinkDataPoint *> *))block;

@end
