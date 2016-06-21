//
//  NSObject+ICEAdd.m
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import "NSObject+ICEAdd.h"
#import <UIKit/UIKit.h>
#import <objc/runtime.h>



@implementation NSObject (ICEAdd)

#pragma mark - Associate 关联

- (void)setAssociateValue:(id)value withKey:(void *)key {
    objc_setAssociatedObject(self, key, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)setAssociateWeakValue:(id)value withKey:(void *)key {
    objc_setAssociatedObject(self, key, value, OBJC_ASSOCIATION_ASSIGN);
}

- (void)removeAssociatedValues {
    objc_removeAssociatedObjects(self);
}

- (id)getAssociatedValueForKey:(void *)key {
    return objc_getAssociatedObject(self, key);
}


#pragma mark - className
+ (NSString *)className {
    return NSStringFromClass(self);
}

- (NSString *)className {
    return [NSString stringWithUTF8String:class_getName([self class])];
}


+ (void)dismissKeyBoard{
    [[[UIApplication sharedApplication] keyWindow] endEditing:YES];
}


+ (NSArray *)instantiationNibSource:(NSString *)nibName{
    return [[NSBundle mainBundle] loadNibNamed:nibName owner:nil options:nil];
}

+ (id)instantiationWithNibName:(NSString *)nibName atIndex:(NSInteger)index{
    return  [[self instantiationNibSource:nibName] objectAtIndex:index];
}
+ (id)instantiationWithNibName:(NSString *)nibName{

    return  [[self instantiationNibSource:nibName] firstObject];
}

+ (id)instantiationNibFirstObj{
    return [self instantiationNibSource:[self className]].firstObject;
}

+ (id)instantiationNibLastObj{
    return [self instantiationNibSource:[self className]].lastObject;
}



@end
