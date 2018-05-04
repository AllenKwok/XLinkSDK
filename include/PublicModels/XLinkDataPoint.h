//
//  XLinkDataPoint.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 数据端点值数据类型
 */
typedef NS_ENUM(uint8_t, XLinkDataType) {
    XLinkDataTypeBool = 1,//布尔类型
    XLinkDataTypeByte = 2,//单字节(无符号)
    XLinkDataTypeShort = 3,//16位短整型（有符号）
    XLinkDataTypeInt = 4,//32位整型（有符号）
    XLinkDataTypeFloat = 5,//浮点
    XLinkDataTypeString = 6,//字符串
    XLinkDataTypeByteArray = 7,//字节数组
    XLinkDataTypeUnsignedShort = 8,//16位短整型（无符号）
    XLinkDataTypeUnsignedInt = 9,//32位整型（无符号)
};

@interface XLinkDataPoint : NSObject

/**
 数据端点值数据类型
 */
@property(assign, nonatomic) XLinkDataType type;

/**
 数据端点index
 */
@property(assign, nonatomic) uint8_t index;

/**
 数据端点的值
 如果type是XLinkDataTypeBool、XLinkDataTypeByte、XLinkDataTypeShort、XLinkDataTypeInt、XLinkDataTypeFloat、XLinkDataTypeUnsignedShort、XLinkDataTypeUnsignedInt，那么value应该是NSNumber类型；
 如果type是XLinkDataTypeString，那么value应该是NSString类型；
 如果type是XLinkDataTypeByteArray，那么value应该是NSData类型；
 */
@property(strong, nonatomic) id value;

/**
 数据端点的长度
 */
@property(assign, nonatomic) uint16_t len;

/**
 数据端点最大值
 */
@property(assign, nonatomic) long long maxValue;

/**
 数据端点最小值
 */
@property(assign, nonatomic) long long minValue;

/**
 数据端点名称
 */
@property(copy, nonatomic) NSString *name;


@end
