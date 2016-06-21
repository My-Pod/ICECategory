//
//  ICENextViewController.m
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import "ICENextViewController.h"
#import "UIControl+ICEAdd.h"


@implementation ICENextViewController


- (void)viewDidLoad{

    [super viewDidLoad];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button addBlockForControlEvents:UIControlEventTouchUpInside block:^(id sender) {
        self.view.backgroundColor = [UIColor redColor];
    }];
    
    
    
}

@end
