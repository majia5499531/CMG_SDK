//
//  SZNetWatcher.h
//  TXLiteAVDemo
//
//  Created by annidyfeng on 2018/7/31.
//  Copyright © 2018年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SZSuperPlayerModel.h"

@interface SZNetWatcher : NSObject

@property (copy) void (^notifyTipsBlock)(NSString *);

@property (nonatomic) SZSuperPlayerModel *playerModel;

- (void)startWatch;
- (void)stopWatch;

- (void)loadingEvent;
- (void)loadingEndEvent;

@property NSString *adviseDefinition;

@end
