//
//  UIButton+ICEAdd.h
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIButton (ICEAdd)

- (void)handleControlEvent:(UIControlEvents)controlEvent withBlock:(void (^) (UIButton *sender))action;

@end
