//
//  ICLDatePickerTransition.h
//  iOSCoreLibrary
//
//  Created by Iain McManus on 17/06/2014.
//  Copyright (c) 2014 Iain McManus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ICLDatePickerTransition : NSObject<UIViewControllerAnimatedTransitioning>

@property (assign, nonatomic) BOOL isPresenting;

@end
