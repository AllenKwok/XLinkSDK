//
//  XLinkErrorDesc.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/3/22.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XLinkErrorDesc : NSObject

@property (copy, nonatomic) NSString *errorName;
@property (copy, nonatomic) NSString *errorDescString;

+ (instancetype)errorDescWithErrorName:(NSString *)errorName errorDescString:(NSString *)errorDescString;

@end
