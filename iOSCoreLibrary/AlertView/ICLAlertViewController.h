//
//  ICLAlertViewController.h
//  iOSCoreLibrary
//
//  Created by Iain McManus on 4/05/2014.
//  Copyright (c) 2014 Iain McManus. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ICLAlertViewControllerDelegate;

@interface ICLAlertViewController : UIViewController

@property (weak, nonatomic) id <ICLAlertViewControllerDelegate> delegate;

@property (weak, nonatomic) IBOutlet UINavigationBar *titleBar;
@property (weak, nonatomic) IBOutlet UINavigationItem *titleItem;
@property (weak, nonatomic) IBOutlet UIView *optionContainerView;

@property (weak, nonatomic) IBOutlet UIView *option1View;
@property (weak, nonatomic) IBOutlet UILabel *option1Title;
@property (weak, nonatomic) IBOutlet UITextView *option1Description;
@property (weak, nonatomic) IBOutlet UIButton *option1Button;

@property (weak, nonatomic) IBOutlet UIView *option2View;
@property (weak, nonatomic) IBOutlet UILabel *option2Title;
@property (weak, nonatomic) IBOutlet UITextView *option2Description;
@property (weak, nonatomic) IBOutlet UIButton *option2Button;

@property (weak, nonatomic) IBOutlet UIView *option3View;
@property (weak, nonatomic) IBOutlet UILabel *option3Title;
@property (weak, nonatomic) IBOutlet UITextView *option3Description;
@property (weak, nonatomic) IBOutlet UIButton *option3Button;

@property (strong, nonatomic) NSDictionary* appearanceOptions;
@property (strong, nonatomic) NSArray* optionNames;
@property (strong, nonatomic) NSArray* optionDescriptions;

- (IBAction)selectedOption1:(id)sender;
- (IBAction)selectedOption2:(id)sender;
- (IBAction)selectedOption3:(id)sender;

+ (id) create:(NSString*) title optionNames:(NSArray*) optionNames optionDescriptions:(NSArray*) optionDescriptions appearanceOptions:(NSDictionary*) appearanceOptions;
- (void) show;

@end

@protocol ICLAlertViewControllerDelegate <NSObject>

@required

- (void) alertViewControllerDidFinish:(ICLAlertViewController*) alertView selectedOption:(NSUInteger) option;

@end;