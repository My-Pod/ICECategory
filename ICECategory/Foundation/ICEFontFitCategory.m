//
//  UILabel+ICEFontFitAdd.m
//  ICEAutoFontTest
//
//  Created by WLY on 16/8/11.
//  Copyright © 2016年 WLY. All rights reserved.
//

#import "ICEFontFitCategory.h"
#import <objc/runtime.h>


const NSInteger ICEFontNotFitTag = 2016;


@implementation UIFont (ICEFontFitAdd)



+ (CGFloat)getFontSizeScale{
    
    static dispatch_once_t one;
    static CGFloat oneRato = 1.0;
    dispatch_once(&one, ^{
        if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
            oneRato = 1.0;
        }else{
            CGFloat width = [UIScreen mainScreen].bounds.size.width;
            if (width == 414) {
                oneRato = 1.5;
            }else if (width == 375 || width == 320){
                oneRato = 2.0;
            }else{
                oneRato = width / 320.0;
            }
        }
    });
    return oneRato;
}





@end

@implementation UILabel (ICEFontFitAdd)

+ (void)load{
    Method imp = class_getInstanceMethod([self class], @selector(initWithCoder:));
    Method myImp = class_getInstanceMethod([self class], @selector(myInitWithCoder:));
    method_exchangeImplementations(imp, myImp);
    
}

- (id)myInitWithCoder:(NSCoder*)aDecode{
    [self myInitWithCoder:aDecode];
    if (self) {
        //部分不像改变字体的 把tag值设置成333跳过
        if(self.tag != ICEFontNotFitTag){
            CGFloat fontSize = self.font.pointSize;
            self.font = [UIFont systemFontOfSize:fontSize * [UIFont getFontSizeScale]];
        }
    }
    return self;
}



@end





@implementation UIButton (ICEFontFitAdd)

+ (void)load{
    Method imp = class_getInstanceMethod([self class], @selector(initWithCoder:));
    Method myImp = class_getInstanceMethod([self class], @selector(myInitWithCoder:));
    method_exchangeImplementations(imp, myImp);
}

- (id)myInitWithCoder:(NSCoder*)aDecode{
    [self myInitWithCoder:aDecode];
    if (self) {
        //部分不像改变字体的 把tag值设置成333跳过
        if(self.tag != ICEFontNotFitTag){
            CGFloat fontSize = self.titleLabel.font.pointSize;
            self.titleLabel.font = [UIFont systemFontOfSize:fontSize * [UIFont getFontSizeScale]];
        }
    }
    return self;
}

@end



@implementation UITextField (ICEFontFitAdd)

+ (void)load{
    Method imp = class_getInstanceMethod([self class], @selector(initWithCoder:));
    Method myImp = class_getInstanceMethod([self class], @selector(myInitWithCoder:));
    method_exchangeImplementations(imp, myImp);
}

- (id)myInitWithCoder:(NSCoder*)aDecode{
    [self myInitWithCoder:aDecode];
    if (self) {
        //部分不像改变字体的 把tag值设置成333跳过
        if(self.tag != ICEFontNotFitTag){
            CGFloat fontSize = self.font.pointSize;
            self.font = [UIFont systemFontOfSize:fontSize * [UIFont getFontSizeScale]];
        }
    }
    return self;
}


@end


@implementation UITextView (ICEFontFitAdd)

+ (void)load{
    Method imp = class_getInstanceMethod([self class], @selector(initWithCoder:));
    Method myImp = class_getInstanceMethod([self class], @selector(myInitWithCoder:));
    method_exchangeImplementations(imp, myImp);
}

- (id)myInitWithCoder:(NSCoder*)aDecode{
    [self myInitWithCoder:aDecode];
    if (self) {
        //部分不像改变字体的 把tag值设置成333跳过
        if(self.tag != ICEFontNotFitTag){
            CGFloat fontSize = self.font.pointSize;
            self.font = [UIFont systemFontOfSize:fontSize * [UIFont getFontSizeScale]];
        }
    }
    return self;
}

@end