//
//  NSDate+Extensions.h
//  iOSCoreLibrary
//
//  Created by Iain McManus on 7/01/2014.
//  Copyright (c) 2014 Iain McManus. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (Extensions)

- (BOOL) isBetweenDates:(NSDate*) inStartDate endDate:(NSDate*) inEndDate;

- (NSDate*) dateFloor;
- (NSDate*) dateCeil;

- (NSDate*) startOfWeek;
- (NSDate*) endOfWeek;

- (NSDate*) startOfMonth;
- (NSDate*) endOfMonth;

- (NSDate*) previousWeek;
- (NSDate*) nextWeek;

- (NSDate*) previousMonth;
- (NSDate*) nextMonth;

@end
