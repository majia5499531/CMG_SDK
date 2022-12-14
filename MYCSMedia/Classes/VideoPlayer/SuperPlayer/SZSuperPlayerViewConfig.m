//
//  SZSuperPlayerViewConfig.m
//  SuperPlayer
//
//  Created by annidyfeng on 2018/10/18.
//

#import "SZSuperPlayerViewConfig.h"
#import "SZSuperPlayer.h"

@implementation SZSuperPlayerViewConfig

- (instancetype)init {
    self = [super init];
    self.hwAcceleration = 1;
    self.playRate = 1;
    self.renderMode = RENDER_MODE_FILL_SCREEN;
    self.maxCacheItem = 5;
    self.playShiftDomain = @"playtimeshift.live.myqcloud.com";
    self.enableLog = NO;
    self.loop=NO;
    return self;
}

- (BOOL)hwAcceleration
{
#if TARGET_OS_SIMULATOR
    return NO;
#else
    return _hwAcceleration;
#endif
}


@end
