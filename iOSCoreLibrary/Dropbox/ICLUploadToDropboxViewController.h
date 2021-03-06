//
//  ICLUploadToDropboxViewController.h
//  iOSCoreLibrary
//
//  Created by Iain McManus on 7/05/2014.
//  Copyright (c) 2014 Iain McManus. All rights reserved.
//

#if TARGET_OS_IPHONE

#import <UIKit/UIKit.h>

#import "BuildFlags.h"
#import "iOSCoreLibraryCommon.h"

#if ICL_Using_Dropbox

extern NSString* const kICLMeterColourForSuccess;
extern NSString* const kICLMeterColour;
extern NSString* const kICLMeterColourForFailure;
extern NSString* const kICLMeterGlow;

@class DBRestClient;

@protocol ICLUploadToDropboxViewControllerDelegate;

@interface ICLUploadToDropboxViewController : UIViewController

@property (weak, nonatomic) id <ICLUploadToDropboxViewControllerDelegate> delegate;

@property (weak, nonatomic) IBOutlet UINavigationBar *navigationBar;
@property (weak, nonatomic) IBOutlet UINavigationItem *titleItem;
@property (weak, nonatomic) IBOutlet UIImageView *progressView;
@property (weak, nonatomic) IBOutlet UIButton *doneButton;

@property (nonatomic, strong) NSString* sourceFile;
@property (nonatomic, strong) NSString* destinationPath;
@property (nonatomic, strong) NSString* filename;
@property (strong, nonatomic) NSDictionary* appearanceOptions;

@property (nonatomic, strong) DBRestClient* restClient;

+ (id) create:(NSString*) sourceFile destinationPath:(NSString*) destinationPath appearanceOptions:(NSDictionary*) appearanceOptions;
- (void) show;

- (void) cancelUpload;

- (IBAction)doneButtonSelected:(id)sender;

@end

@protocol ICLUploadToDropboxViewControllerDelegate <NSObject>

@required

- (void) uploadToDropboxViewDidFinish:(ICLUploadToDropboxViewController*) alertView uploaded:(BOOL) uploaded;

@end;

#endif // ICL_Using_Dropbox

#endif // TARGET_OS_IPHONE