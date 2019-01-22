//
//  TZAssetModel.m
//  TZImagePickerController
//
//  Created by 谭真 on 15/12/24.
//  Copyright © 2015年 谭真. All rights reserved.
//

#import "IDSAssetModel.h"
#import "IDSImageManager.h"

@implementation IDSAssetModel

+ (instancetype)modelWithAsset:(id)asset type:(IDSAssetModelMediaType)type{
    IDSAssetModel *model = [[IDSAssetModel alloc] init];
    model.asset = asset;
    model.isSelected = NO;
    model.type = type;
    return model;
}

+ (instancetype)modelWithAsset:(id)asset type:(IDSAssetModelMediaType)type timeLength:(NSString *)timeLength {
    IDSAssetModel *model = [self modelWithAsset:asset type:type];
    model.timeLength = timeLength;
    return model;
}

@end



@implementation IDSAlbumModel

- (void)setResult:(id)result needFetchAssets:(BOOL)needFetchAssets {
    _result = result;
    if (needFetchAssets) {
        [[IDSImageManager manager] getAssetsFromFetchResult:result completion:^(NSArray<IDSAssetModel *> *models) {
            self->_models = models;
            if (self->_selectedModels) {
                [self checkSelectedModels];
            }
        }];
    }
}

- (void)setSelectedModels:(NSArray *)selectedModels {
    _selectedModels = selectedModels;
    if (_models) {
        [self checkSelectedModels];
    }
}

- (void)checkSelectedModels {
    self.selectedCount = 0;
    NSMutableArray *selectedAssets = [NSMutableArray array];
    for (IDSAssetModel *model in _selectedModels) {
        [selectedAssets addObject:model.asset];
    }
    for (IDSAssetModel *model in _models) {
        if ([[IDSImageManager manager] isAssetsArray:selectedAssets containAsset:model.asset]) {
            self.selectedCount ++;
        }
    }
}

- (NSString *)name {
    if (_name) {
        return _name;
    }
    return @"";
}

@end
