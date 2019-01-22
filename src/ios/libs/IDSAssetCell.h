//
//  TZAssetCell.h
//  TZImagePickerController
//
//  Created by 谭真 on 15/12/24.
//  Copyright © 2015年 谭真. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Photos/Photos.h>

typedef enum : NSUInteger {
    IDSAssetCellTypePhoto = 0,
    IDSAssetCellTypeLivePhoto,
    IDSAssetCellTypePhotoGif,
    IDSAssetCellTypeVideo,
    IDSAssetCellTypeAudio,
} IDSAssetCellType;

@class IDSAssetModel;
@interface IDSAssetCell : UICollectionViewCell

@property (weak, nonatomic) UIButton *selectPhotoButton;
@property (weak, nonatomic) UIButton *cannotSelectLayerButton;
@property (nonatomic, strong) IDSAssetModel *model;
@property (assign, nonatomic) NSInteger index;
@property (nonatomic, copy) void (^didSelectPhotoBlock)(BOOL);
@property (nonatomic, assign) IDSAssetCellType type;
@property (nonatomic, assign) BOOL allowPickingGif;
@property (nonatomic, assign) BOOL allowPickingMultipleVideo;
@property (nonatomic, copy) NSString *representedAssetIdentifier;
@property (nonatomic, assign) int32_t imageRequestID;

@property (nonatomic, strong) UIImage *photoSelImage;
@property (nonatomic, strong) UIImage *photoDefImage;

@property (nonatomic, assign) BOOL showSelectBtn;
@property (assign, nonatomic) BOOL allowPreview;
@property (assign, nonatomic) BOOL useCachedImage;
@end


@class IDSAlbumModel;

@interface IDSAlbumCell : UITableViewCell

@property (nonatomic, strong) IDSAlbumModel *model;
@property (weak, nonatomic) UIButton *selectedCountButton;

@end


@interface IDSAssetCameraCell : UICollectionViewCell

@property (nonatomic, strong) UIImageView *imageView;

@end
