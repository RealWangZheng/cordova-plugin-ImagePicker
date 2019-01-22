//
//  NSBundle+TZImagePicker.m
//  TZImagePickerController
//
//  Created by 谭真 on 16/08/18.
//  Copyright © 2016年 谭真. All rights reserved.
//

#import "NSBundle+IDSImagePicker.h"
#import "IDSImagePickerController.h"

@implementation NSBundle (IDSImagePicker)

+ (NSBundle *)tz_imagePickerBundle {
    NSBundle *bundle = [NSBundle bundleForClass:[IDSImagePickerController class]];
    NSURL *url = [bundle URLForResource:@"IDSImagePickerController" withExtension:@"bundle"];
    bundle = [NSBundle bundleWithURL:url];
    return bundle;
}

+ (NSString *)tz_localizedStringForKey:(NSString *)key {
    return [self tz_localizedStringForKey:key value:@""];
}

+ (NSString *)tz_localizedStringForKey:(NSString *)key value:(NSString *)value {
    NSBundle *bundle = [IDSImagePickerConfig sharedInstance].languageBundle;
    NSString *value1 = [bundle localizedStringForKey:key value:value table:nil];
    return value1;
}

@end
