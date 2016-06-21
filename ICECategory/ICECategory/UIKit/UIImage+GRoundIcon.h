//
//  UIImage+GRoundIcon.h
//  WLYDoctor_iPad
//
//  Created by WLY on 16/3/3.
//  Copyright © 2016年 WLY. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (GRoundIcon)
/**
 *  @param icon   头像图片名称
 *  @param border 边框大小
 *  @param color  边框的颜色
 *
 *  @return 圆形的头像图片
 */
+ (instancetype)imageWithIconName:(NSString *)icon border:(int)border borderColor:(UIColor *)color;

/**
 *  获取圆角图片
 */
- (UIImage *)circleImage;


@end
