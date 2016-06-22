//
//  UIColor+ICEAdd.h
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  通过red green blue 设置颜色值
 *  return UIColor
 */
#define UIColorWithRGBA(r,g,b,a) [UIColor colorWithRed:(r)/ 255.0f green:(g) / 255.0f blue:(b) / 255.0f alpha:(a)]
#define UIColorWithRGB(r,g,b) UIColorWithRGBA(r,g,b,1.0)
/**
 *  通过16 进制设置颜色值
 *  return UIColor
 */
#define UIColorWithHexA(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 \
alpha:(a)]
#define UIColorWithHex(rgbValue)    UIColorWithHexA(rgbValue, 1.0)


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
