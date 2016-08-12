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
static inline UIColor * UIColorWithRGBA(CGFloat R, CGFloat G, CGFloat B, CGFloat alpha){
    return [UIColor colorWithRed:R / 255.0 green:G / 255.0 blue:B / 255.0 alpha:alpha];
}

static inline UIColor * UIColorWithRGB(CGFloat R, CGFloat G, CGFloat B){
    return UIColorWithRGBA(R, G, B, 1.0);
}

/**
 *  return iamge`s color
 */
static inline UIColor * UIColorWithTexture(UIImage * image){
    return [UIColor colorWithPatternImage:image];
}

/**
 return RGA color
 */
static inline UIColor * UIColorWithHexA(uint32_t rgbValue, float a){
    return [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0
                           green:((float)((rgbValue & 0xFF00) >> 8))/255.0
                            blue:((float)(rgbValue & 0xFF))/255.0
                           alpha:(a)];
}

/**
 return RGA color
 */
static inline UIColor * UIColorWithHex(uint32_t rgbValue){
    return UIColorWithHexA(rgbValue, 1.0);
}


@interface UIColor (ICEAdd)

/**
 *  随机色
 */
+ (UIColor * )ramdomColor;


@end
