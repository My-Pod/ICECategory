//
//  NSObject+ICEAddForKVO.m
//  ICECategoryExample
//
//  Created by WLY on 16/6/21.
//  Copyright © 2016年 ICE. All rights reserved.
//

#import "NSObject+ICEAddForKVO.h"
#import <objc/objc.h>
#import <objc/runtime.h>



static const int block_key;

@interface _ICEObjectKVOBlockTarget : NSObject

@property (nonatomic, copy ) void (^block)(__weak id obj ,id oldValu , id newVal);

- (id)initWithBlock:(void (^)(__weak id obj , id oldVal, id newVal))block;

@end


@implementation _ICEObjectKVOBlockTarget

- (id)initWithBlock:(void (^)(__weak id, id, id))block{

    self  = [super init];
    if (self) {
        self.block = block;
    }
    return self;
}


- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSString *,id> *)change context:(void *)context{
    if (!self.block) return;
    
    BOOL isPrior = [[change objectForKey:NSKeyValueChangeNotificationIsPriorKey] boolValue];
    if (isPrior) return;
    
    NSKeyValueChange changeKind = [[change objectForKey:NSKeyValueChangeKindKey] integerValue];
    if (changeKind != NSKeyValueChangeSetting) return;
    
    id oldVal = [change objectForKey:NSKeyValueChangeOldKey];
    if (oldVal == [NSNull null]) oldVal = nil;
    
    id newVal = [change objectForKey:NSKeyValueChangeNewKey];
    if (newVal == [NSNull null]) newVal = nil;
    
    self.block(object, oldVal, newVal);
}

@end


@implementation NSObject (ICEAddForKVO)



- (void)addObserverBlockForKeyPath:(NSString *)keyPath block:(void (^)(__weak id, id, id))block{

    if (!keyPath || !block) return;
    _ICEObjectKVOBlockTarget *target = [[_ICEObjectKVOBlockTarget alloc] initWithBlock:block];
    NSMutableDictionary *dic = [self p_ice_allNsobjectObserverBlocks];
    NSMutableArray *arr = dic[keyPath];
    if (!arr) {
        arr = [NSMutableArray array];
        dic[keyPath] = arr;
    }
    [arr addObject:target];
    [self addObserver:target forKeyPath:keyPath options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld context:NULL];
}

- (void)removeObserverBlocksForKeyPath:(NSString *)keyPath {
    if (!keyPath) return;
    NSMutableDictionary *dic = [self p_ice_allNsobjectObserverBlocks];
    NSMutableArray *arr = dic[keyPath];
    [arr enumerateObjectsUsingBlock: ^(id obj, NSUInteger idx, BOOL *stop) {
        [self removeObserver:obj forKeyPath:keyPath];
    }];
}

- (void)removeObserverBlocks {
    NSMutableDictionary *dic = [self p_ice_allNsobjectObserverBlocks];
    [dic enumerateKeysAndObjectsUsingBlock: ^(NSString *key, NSArray *arr, BOOL *stop) {
        [arr enumerateObjectsUsingBlock: ^(id obj, NSUInteger idx, BOOL *stop) {
            [self removeObserver:obj forKeyPath:key];
        }];
    }];
}


- (NSMutableDictionary *)p_ice_allNsobjectObserverBlocks{

    NSMutableDictionary *targets = objc_getAssociatedObject(self, &block_key);
    if (!targets) {
        targets = [NSMutableDictionary dictionary];
        objc_setAssociatedObject(self, &block_key, targets, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    return targets;
}

@end
