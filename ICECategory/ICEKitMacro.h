//
//  ICEKitMacro.h
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
/////多为从YYKT处借鉴学习...

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <pthread.h>


#ifndef ICEKitMacro_h
#define ICEKitMacro_h





//---------------------- Log -----------------------------------

#pragma mark - debug log

#ifdef DEBUG
#   define DLog(...) NSLog((@"%s [Line %d] %@"), __PRETTY_FUNCTION__, __LINE__, [NSString stringWithFormat:__VA_ARGS__])
#   define SLog(...) NSLog(__VA_ARGS__)
#else
#   define DLog(...)
#   define SLog(...)
#endif


//----------------------断言(NSAssert)-----------------------------------

/**
 *  断言(NSAssert)
 *  防御式编程手段: 主要用于开发阶段调试程序,在真机中将会自动忽略.通过为NSAssert()传递条件表达式来判断是否属于bug, 满足条件返回真,程序继续运行,如果为假,则抛出异常.并且可以自定义异常描述.
 *  The second is the difference between C and Objective-C assertions: NSAssert should only be used in an Objective-C context (i.e. method implementations), whereas NSCAssert should only be used in a C context (i.e. functions).
 */
#define ICEAssertNil(condition, description, ...) NSAssert(!(condition), (description), ##__VA_ARGS__)
#define ICECAssertNil(condition, description, ...) NSCAssert(!(condition), (description), ##__VA_ARGS__)

#define ICEAssertNotNil(condition, description, ...) NSAssert((condition), (description), ##__VA_ARGS__)
#define ICECAssertNotNil(condition, description, ...) NSCAssert((condition), (description), ##__VA_ARGS__)

#define ICEAssertMainThread() NSAssert([NSThread isMainThread], @"This method must be called on the main thread")
#define ICECAssertMainThread() NSCAssert([NSThread isMainThread], @"This method must be called on the main thread")



//----------------------block 强弱引用-----------------------------------
/**
 Synthsize a weak or strong reference.
 
 Example:
 @weakify(self)
 [self doSomething^{
 @strongify(self)
 if (!self) return;
 ...
 }];
 
 */
#ifndef weakify
#if DEBUG
#if __has_feature(objc_arc)
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#else
#if __has_feature(objc_arc)
#define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif
#endif
#endif

#ifndef strongify
#if DEBUG
#if __has_feature(objc_arc)
#define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif
#else
#if __has_feature(objc_arc)
#define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif
#endif
#endif


//--------------为  Cagtegory  动态的添加属性---------------------------

/**
 Synthsize a dynamic object property in @implementation scope.
 It allows us to add custom properties to existing classes in categories.
 
 @param association  ASSIGN / RETAIN / COPY / RETAIN_NONATOMIC / COPY_NONATOMIC
 @warning #import <objc/runtime.h>
 *******************************************************************************
 Example:
 @interface NSObject (MyAdd)
 @property (nonatomic, retain) UIColor *myColor;
 @end
 
 #import <objc/runtime.h>
 @implementation NSObject (MyAdd)
 ICESYNTH_DYNAMIC_PROPERTY_OBJECT(myColor, setMyColor, RETAIN, UIColor *)
 @end
 */
#ifndef ICESYNTH_DYNAMIC_PROPERTY_OBJECT
#define ICESYNTH_DYNAMIC_PROPERTY_OBJECT(_getter_, _setter_, _association_, _type_) \
- (void)_setter_ : (_type_)object { \
[self willChangeValueForKey:@#_getter_]; \
objc_setAssociatedObject(self, _cmd, object, OBJC_ASSOCIATION_ ## _association_); \
[self didChangeValueForKey:@#_getter_]; \
} \
- (_type_)_getter_ { \
return objc_getAssociatedObject(self, @selector(_setter_:)); \
}
#endif




//----------------------inline 内联函数-----------------------------------
/**
 *  作用: 代替宏, 用来建议编译器对一些特殊函数进行内联扩展（有时称作在线扩展）；也就是说建议编译器将指定的函数体插入并取代每一处调用该函数的地方（上下文），从而节省了每次调用函数带来的额外时间开支。但在选择使用内联函数时，必须在程序占用空间和程序执行效率之间进行权衡，因为过多的比较复杂的函数进行内联扩展将带来很大的存储资源开支。另外还需要非常注意的是对递归函数的内联扩展可能带来部分编译器的无穷编译。来自
 *  为什么用 inline 取代宏: 为什么inline能取代宏？
    优点相比于函数:
 
        1) inline函数避免了普通函数的,在汇编时必须调用call的缺点:取消了函数的参数压栈，减少了调用的开销,提高效率.所以执行速度确比一般函数的执行速度要快.
 
        2)集成了宏的优点,使用时直接用代码替换(像宏一样);
 
    优点相比于宏:
 
        1)避免了宏的缺点:需要预编译.因为inline内联函数也是函数,不需要预编译.
 
        2)编译器在调用一个内联函数时，会首先检查它的参数的类型，保证调用正确。然后进行一系列的相关检查，就像对待任何一个真正的函数一样。这样就消除了它的隐患和局限性。
 
        3)可以使用所在类的保护成员及私有成员。
 

 *  inline 内联函数的说明
        1.内联函数只是我们向编译器提供的申请,编译器不一定采取inline形式调用函数.
        2.内联函数不能承载大量的代码.如果内联函数的函数体过大,编译器会自动放弃内联.
        3.内联函数内不允许使用循环语句或开关语句.
        4.内联函数的定义须在调用之前.
 
 */


/**
 *  计算文本size
 */
static inline CGSize ICESizeWithString(NSString *string,  CGFloat max_w,CGFloat max_h, UIFont *font) {

    return [string boundingRectWithSize:CGSizeMake(max_w, max_h) options:NSStringDrawingUsesFontLeading | NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName : font} context:nil].size;
}

/**
 *  计算文本 宽度, (不限定最大宽度)
 */
static inline CGFloat ICEWidthWithString(NSString *string, CGFloat max_h, UIFont *font) {

    return ICESizeWithString(string,MAXFLOAT,max_h,font).width;
}

/**
 *  计算文本 高度,  (不限定最大高度)
 */
static inline CGFloat ICEHeightWithString(NSString *string, CGFloat max_w, UIFont *font) {
    return ICESizeWithString(string,max_w,MAXFLOAT,font).height;
}



/**
 Get compile timestamp.
 @return A new date object set to the compile date and time.
 */
static inline NSDate *ICECompileTime() {
    NSString *timeStr = [NSString stringWithFormat:@"%s %s",__DATE__, __TIME__];
    NSLocale *locale = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US"];
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"MMM dd yyyy HH:mm:ss"];
    [formatter setLocale:locale];
    return [formatter dateFromString:timeStr];
}

/**
 Returns a dispatch_time delay from now.
 */
static inline dispatch_time_t dispatch_time_delay(NSTimeInterval second) {
    return dispatch_time(DISPATCH_TIME_NOW, (int64_t)(second * NSEC_PER_SEC));
}

/**
 Returns a dispatch_wall_time delay from now.
 */
static inline dispatch_time_t dispatch_walltime_delay(NSTimeInterval second) {
    return dispatch_walltime(DISPATCH_TIME_NOW, (int64_t)(second * NSEC_PER_SEC));
}

/**
 Returns a dispatch_wall_time from NSDate.
 */
static inline dispatch_time_t dispatch_walltime_date(NSDate *date) {
    NSTimeInterval interval;
    double second, subsecond;
    struct timespec time;
    dispatch_time_t milestone;
    
    interval = [date timeIntervalSince1970];
    subsecond = modf(interval, &second);
    time.tv_sec = second;
    time.tv_nsec = subsecond * NSEC_PER_SEC;
    milestone = dispatch_walltime(&time, 0);
    return milestone;
}


/**
 Whether in main queue/thread.
 */
static inline bool dispatch_is_main_queue() {
    return pthread_main_np() != 0;
}

/**
 Submits a block for asynchronous execution on a main queue and returns immediately.
 */
static inline void dispatch_async_on_main_queue(void (^block)()) {
    if (pthread_main_np()) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}

/**
 Submits a block for execution on a main queue and waits until the block completes.
 */
static inline void dispatch_sync_on_main_queue(void (^block)()) {
    if (pthread_main_np()) {
        block();
    } else {
        dispatch_sync(dispatch_get_main_queue(), block);
    }
}





#endif /* ICEKitMacro_h */
