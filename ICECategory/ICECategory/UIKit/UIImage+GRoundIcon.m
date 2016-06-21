//
//  UIImage+GRoundIcon.m
//  WLYDoctor_iPad
//
//  Created by WLY on 16/3/3.
//  Copyright © 2016年 WLY. All rights reserved.
//

#import "UIImage+GRoundIcon.h"

@implementation UIImage (GRoundIcon)

+ (instancetype)imageWithIconName:(NSString *)icon border:(int)border borderColor:(UIColor *)color
{
    //头像图片
    UIImage * image = [UIImage imageNamed:icon];
    //
    CGSize size = CGSizeMake(image.size.width + border, image.size.height + border);
    //创建图片上下文
    UIGraphicsBeginImageContextWithOptions(size, NO, 0);
    //绘制边框的圆
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextAddEllipseInRect(context, CGRectMake(0, 0, size.width, size.height));
    [color set ];
    CGContextFillPath(context);
    //设置头像frame
    CGFloat iconX = border / 2;
    CGFloat iconY = border / 2;
    CGFloat iconW = size.width;
    CGFloat iconH = size.height;
    //绘制圆形头像范围
    CGContextAddEllipseInRect(context, CGRectMake(iconX, iconY, iconW, iconH));
    //剪切可视范围
    CGContextClip(context);
    //绘制头像
    [image drawInRect:CGRectMake(iconX, iconY, iconW, iconH)];
    //取出整个图片上下文的图片
    UIImage *iconImage = UIGraphicsGetImageFromCurrentImageContext();
    return iconImage;
}



- (UIImage *)circleImage {
    
    // 开始图形上下文
    UIGraphicsBeginImageContextWithOptions(self.size, NO, 0.0);
    
    // 获得图形上下文
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    
    // 设置一个范围
    CGRect rect = CGRectMake(0, 0, self.size.width, self.size.height);
    
    // 根据一个rect创建一个椭圆
    CGContextAddEllipseInRect(ctx, rect);
    
    // 裁剪
    CGContextClip(ctx);
    
    // 将原照片画到图形上下文
    [self drawInRect:rect];
    
    // 从上下文上获取剪裁后的照片
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    
    // 关闭上下文
    UIGraphicsEndImageContext();
    
    return newImage;
}
@end
