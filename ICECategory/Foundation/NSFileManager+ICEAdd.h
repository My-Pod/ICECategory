//
//  NSFileManager+ICEAdd.h
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import <Foundation/Foundation.h>




@interface NSFileManager (ICEAdd)


/**
 * 创建文件夹
 */
+ (BOOL)creatFileWithPath:(NSString *)path;

/**
 *  删除文件夹
 */
+ (BOOL)removeFileWithPath:(NSString *)path;



@end
