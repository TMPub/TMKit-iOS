//
//  TMAppDelegate.m
//  TMKit
//
//  Created by TMKit on 06/17/2022.
//

#import "TMAppDelegate.h"
#import "TMIndexVC.h"
@import TMKit;

@interface TMAppDelegate () <TMImpressRecorderDelegate>

@end

@implementation TMAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NSLog(@"carrierName: %@", TMDeviceUtil.shareUtil.carrierName);
    NSLog(@"mcc: %@", TMDeviceUtil.shareUtil.mcc);
    NSLog(@"mnc: %@", TMDeviceUtil.shareUtil.mnc);
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    
    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:[[TMIndexVC alloc] init]];
    self.window.rootViewController = navController;
    [self.window makeKeyAndVisible];
        
    NSURL *url = [NSURL URLWithString:@"https://www.boomplay.com/#/live?a=b"];
    NSLog(@"url======= path: %@ fragment: %@ query:%@", url.path, url.fragment, url.query);
    
    NSURL *url2 = [NSURL URLWithString:@"https://www.boomplay.com/?a=b#/live"];
    NSLog(@"url2======= path: %@ fragment: %@ query:%@", url2.path, url2.fragment, url2.query);
    
    NSURL *url3 = [NSURL URLWithString:@"https://www.boomplay.com/GameCentre/?bp_wvt=1&bp_noc=1&visitSource=#/game/4500"];
    NSLog(@"url3 firstPath: %@", url3.tm_firstPathComponent);
    
    NSURL *url4 = [NSURL URLWithString:@"bpmain://GameCentre/123?colType=2&srModel=COPYLINK&srList=ANDROID"];
    if ([url4.scheme isEqualToString:@"bpmain"]) {
        NSLog(@"url4 firstPath: %@", url4.host);
    }
           
    TMImpressRecorder.shared.delegate = self;
    
    return YES;
}

#pragma mark - TMImpressRecorderDelegate
- (void)impressDidRecord:(TMImpressTrackModel *)model {
    NSLog(@"impressDidRecord: %@", model);
}

@end
