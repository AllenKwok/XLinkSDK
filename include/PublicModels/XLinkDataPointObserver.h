//
//  XLinkDataPointObserver.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
@class XDevice;
@class XLinkDataPoint;

typedef void (^DataPointUpdateBlock)(XDevice *device,NSArray <XLinkDataPoint *>*dataPoints);

@interface XLinkDataPointObserver : NSObject

/**
 要监听的设备
 */
@property (strong, nonatomic,readonly) XDevice *device;
/**
 要监听的dataPoint的index数组，不传或者传空数组默认监听所有的dataPoint
 */
@property (strong, nonatomic,readonly)NSArray *indexArray;
/**
 监听到dataPoint变化的回调
 */
@property (strong, nonatomic,readonly)DataPointUpdateBlock block;


/**
 新建一个设备dataPoint变化的监听
 
 @param device 要监听的设备
 @param indexArray 要监听的dataPoint的index数组，不传或者传空数组默认监听所有的dataPoint
 @param block 监听到dataPoint变化的回调
 @return 该监听的对象
 */
+ (instancetype)dataPointObserverWithDevice:(XDevice *)device IndexArray:(NSArray *)indexArray withDataPointUpdateBlock:(DataPointUpdateBlock)block;

@end
