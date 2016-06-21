//
//  UIButton+ICEAdd.m
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import "UIButton+ICEAdd.h"
#import "UIControl+ICEAdd.h"


@implementation UIButton (ICEAdd)


- (void)handleControlEvent:(UIControlEvents)controlEvent withBlock:(void (^)(UIButton *))action{
    [self addBlockForControlEvents:controlEvent block:action];
}

@end
