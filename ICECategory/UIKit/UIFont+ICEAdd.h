//
//  UIFont+ICEAdd.h
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import <UIKit/UIKit.h>

static inline UIFont * UIFontWithSize(CGFloat size){
    return  [UIFont systemFontOfSize:size];
}


@interface UIFont (ICEAdd)


/**
 *  打印并显示所有字体
 */
+(void)showAllFonts;



@end
