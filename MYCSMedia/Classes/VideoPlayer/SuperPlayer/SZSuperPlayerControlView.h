//
//  SZSuperPlayerControlView.h
//  TXLiteAVDemo
//
//  Created by annidyfeng on 2018/6/25.
//  Copyright © 2018年 Tencent. All rights reserved.
//
#import <UIKit/UIKit.h>

#import "SZPlayerControlViewDelegate.h"
#import "SZSuperPlayerModel.h"
#import "SZPlayerSlider.h"
#import "SZFastView.h"
#import "SZSpinner.h"
#import "SZMoreContentView.h"
#import "SZSuperPlayerModel.h"
#import "SZSuperPlayerViewConfig.h"


@interface SZPlayerVideoPoint : NSObject
@property CGFloat where;
@property NSString *text;
@property CGFloat time;
@end


@interface SZSuperPlayerControlView : UIView
@property (nonatomic, assign,getter=isFullScreen)BOOL fullScreenState;
@property (nonatomic, assign,getter=isLockScreen)BOOL isLockScreen;
@property (assign,nonatomic)BOOL onlyFullscreenMode;
@property (assign, nonatomic) BOOL compact;
@property NSString *title;
@property NSArray<SZPlayerVideoPoint *>  *pointArray;
@property BOOL  isDragging;
@property BOOL  isShowSecondView;
@property (nonatomic, weak) id<SZPlayerControlViewDelegate> delegate;
@property SZSuperPlayerViewConfig *playerConfig;





/**
 * 播放进度
 * @param currentTime 当前播放时长
 * @param totalTime   视频总时长
 * @param progress    value(0.0~1.0)
 * @param playable    value(0.0~1.0)
 */
- (void)setProgressTime:(NSInteger)currentTime totalTime:(NSInteger)totalTime
          progressValue:(CGFloat)progress playableValue:(CGFloat)playable;

/**
 * 播放状态
 * @param isPlay YES播放，NO暂停
 */
- (void)setPlayState:(BOOL)isPlay;



/**
 * 开始新的播放
 *  @param isLive 是否为直播流
 *  @param isTimeShifting 是否在直播时移
 *  @param isAutoPlay 是否自动播放
 */
- (void)playerBegin:(SZSuperPlayerModel *)model
             isLive:(BOOL)isLive
     isTimeShifting:(BOOL)isTimeShifting
         isAutoPlay:(BOOL)isAutoPlay;




- (void)setCompactConstraint;
- (void)setUncompactConstraint;

@end
