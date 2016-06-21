//
//  UIApplication+ICEAdd.h
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import <UIKit/UIKit.h>



@interface UIApplication (ICEAdd)


/// "Documents" folder in this app's sandbox.
@property (nonatomic, readonly) NSURL *documentsURL;
@property (nonatomic, readonly) NSString *documentsPath;

/// "Caches" folder in this app's sandbox.
@property (nonatomic, readonly) NSURL *cachesURL;
@property (nonatomic, readonly) NSString *cachesPath;

/// "Library" folder in this app's sandbox.
@property (nonatomic, readonly) NSURL *libraryURL;
@property (nonatomic, readonly) NSString *libraryPath;

/**
 *  Application's Bundle Name (show in SpringBoard).
 */
@property (nonatomic, readonly) NSString *appBundleName;

/**
 *  Application's Bundle ID.  e.g. "com.ibireme.MyApp"
 */
@property (nonatomic, readonly) NSString *appBundleID;

/**
 *  Application's Version.  e.g. "1.2.0"
 */
@property (nonatomic, readonly) NSString *appVersion;

/**
 *  Application's Build number. e.g. "123"
 */
@property (nonatomic, readonly) NSString *appBuildVersion;


@end
