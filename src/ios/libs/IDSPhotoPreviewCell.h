//
//  TZPhotoPreviewCell.h
//  TZImagePickerController
//
//  Created by 谭真 on 15/12/24.
//  Copyright © 2015年 谭真. All rights reserved.
//

#import <UIKit/UIKit.h>

@class IDSAssetModel;
@interface IDSAssetPreviewCell : UICollectionViewCell
@property (nonatomic, strong) IDSAssetModel *model;
@property (nonatomic, copy) void (^singleTapGestureBlock)(void);
- (void)configSubviews;
- (void)photoPreviewCollectionViewDidScroll;
@end


@class IDSAssetModel,IDSProgressView,IDSPhotoPreviewView;
@interface IDSPhotoPreviewCell : IDSAssetPreviewCell

@property (nonatomic, copy) void (^imageProgressUpdateBlock)(double progress);

@property (nonatomic, strong) IDSPhotoPreviewView *previewView;

@property (nonatomic, assign) BOOL allowCrop;
@property (nonatomic, assign) CGRect cropRect;

- (void)recoverSubviews;

@end


@interface IDSPhotoPreviewView : UIView
@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) UIView *imageContainerView;
@property (nonatomic, strong) IDSProgressView *progressView;

@property (nonatomic, assign) BOOL allowCrop;
@property (nonatomic, assign) CGRect cropRect;

@property (nonatomic, strong) IDSAssetModel *model;
@property (nonatomic, strong) id asset;
@property (nonatomic, copy) void (^singleTapGestureBlock)(void);
@property (nonatomic, copy) void (^imageProgressUpdateBlock)(double progress);

@property (nonatomic, assign) int32_t imageRequestID;

- (void)recoverSubviews;
@end


@class AVPlayer, AVPlayerLayer;
@interface IDSVideoPreviewCell : IDSAssetPreviewCell
@property (strong, nonatomic) AVPlayer *player;
@property (strong, nonatomic) AVPlayerLayer *playerLayer;
@property (strong, nonatomic) UIButton *playButton;
@property (strong, nonatomic) UIImage *cover;
- (void)pausePlayerAndShowNaviBar;
@end


@interface IDSGifPreviewCell : IDSAssetPreviewCell
@property (strong, nonatomic) IDSPhotoPreviewView *previewView;
@end
