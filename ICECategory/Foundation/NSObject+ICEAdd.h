//
//  NSObject+ICEAdd.h
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (ICEAdd)


#pragma mark - Associate 关联
/**
 Associate one object to `self`, as if it was a strong property (strong, nonatomic).
 
 @param value   The object to associate.
 @param key     The pointer to get value from `self`.
 */
- (void)setAssociateValue:(id)value withKey:(void *)key;

/**
 Associate one object to `self`, as if it was a weak property (week, nonatomic).
 
 @param value  The object to associate.
 @param key    The pointer to get value from `self`.
 */
- (void)setAssociateWeakValue:(id)value withKey:(void *)key;

/**
 Get the associated value from `self`.
 
 @param key The pointer to get value from `self`.
 */
- (id)getAssociatedValueForKey:(void *)key;

/**
 Remove all associated values.
 */
- (void)removeAssociatedValues;

#pragma mark - className

/**
 Returns the class name in NSString.
 */
+ (NSString *)className;

/**
 Returns the class name in NSString.
 
 @discussion Apple has implemented this method in NSObject(NSLayoutConstraintCallsThis),
 but did not make it public.
 */
- (NSString *)className;

/**
 *  隐藏键盘
 */
+ (void)dismissKeyBoard;


/**
 *  获取 nib 文件中的视图对象数组
 */
+ (NSArray *)instantiationNibSource:(NSString *)nibName;

/**
 *  实例化 nib 文件中指定下标的对象
 *
 *  @param NibName 文件名
 *  @param index   下标, 不可超出
 */
+ (id)instantiationWithNibName:(NSString *)nibName
                       atIndex:(NSInteger)index;

/**
 *  实例化 nib 对象
 */
+ (id)instantiationWithNibName:(NSString *)nibName;

/**
 *  实例化以当前类名 命名的 nib 文件中的第一个对象
 */
+ (id)instantiationNibFirstObj;

/**
 *  实例化以当前类名 命名的 nib 文件中的最后一个对象
 */

+ (id)instantiationNibLastObj;



@end
