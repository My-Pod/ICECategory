//
//  UIColor+ICEAdd.h
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  RGB 颜色值
 */
static inline UIColor* ICEUIColorWithRGBA(float r, float g, float b, float a) {
 return [UIColor colorWithRed:(r)/ 255.0f green:(g) / 255.0f blue:(b) / 255.0f alpha:(a)];
}

/**
 *  RGB 颜色值
 */
static inline UIColor* ICEUIColorWithRGB(float r, float g, float b) {
    return ICEUIColorWithRGBA(r, g, b, 1);
}

/**
 *  通过16 进制设置颜色值
 *  return UIColor
 */
#define UIColorWithHexA(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 \
alpha:(a)]
#define UIColorWithHex(rgbValue)    UIColorWithHexA(rgbValue, 1.0)


@interface UIColor (ICEAdd)

/**
 *  随机色
 */
+ (UIColor * )ramdomColor;


@end
