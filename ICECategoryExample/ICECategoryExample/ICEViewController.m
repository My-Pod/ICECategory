//
//  ICEViewController.m
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import "ICEViewController.h"
#import "UIBarButtonItem+ICEAdd.h"
#import "ICENextViewController.h"



@interface ICEViewController ()

@property (nonatomic, strong) UIBarButtonItem *rightItem;

@end

@implementation ICEViewController



- (void)viewDidLoad{

    [super viewDidLoad];
    
    UIBarButtonItem *rightItem = [[UIBarButtonItem alloc] init];
    rightItem.actionBlock = ^ (id sender){
       
        ICENextViewController *nextVC = [[ICENextViewController alloc] init];
        [self.navigationController pushViewController:nextVC animated:YES];
    };
    
    rightItem.title = @"push";
    self.navigationItem.rightBarButtonItem = rightItem;
    self.rightItem = rightItem;
}

@end
