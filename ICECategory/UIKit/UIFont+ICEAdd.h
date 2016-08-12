//
//  UIFont+ICEAdd.h
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ICEFontFitCategory.h"


static inline UIFont * UIFontWithSize(CGFloat size){
    return  [UIFont systemFontOfSize:[UIFont getFontSizeScale] * size];
}

/**
 *  计算文本size
 */
static inline CGSize ICESizeWithString(NSString *string,  CGFloat max_w,CGFloat max_h, UIFont *font) {
    
    return [string boundingRectWithSize:CGSizeMake(max_w, max_h) options:NSStringDrawingUsesFontLeading | NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName : font} context:nil].size;
}

/**
 *  计算文本 宽度, (不限定最大宽度)
 */
static inline CGFloat ICEWidthWithString(NSString *string, CGFloat max_h, UIFont *font) {
    
    return ICESizeWithString(string,MAXFLOAT,max_h,font).width;
}

/**
 *  计算文本 高度,  (不限定最大高度)
 */
static inline CGFloat ICEHeightWithString(NSString *string, CGFloat max_w, UIFont *font) {
    return ICESizeWithString(string,max_w,MAXFLOAT,font).height;
}






@interface UIFont (ICEAdd)


/**
 *  打印并显示所有字体
 */
+(void)showAllFonts;



@end
