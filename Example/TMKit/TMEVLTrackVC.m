//
//  TMEVLTrackVC.m
//  TMKit_Example
//
//  Created by TMKit on 2022/6/18.
//

#import "TMEVLTrackVC.h"
@import TMKit;

@interface TMEVLTrackVC ()

@end

@implementation TMEVLTrackVC

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIButton *redButton = [[UIButton alloc] initWithFrame:CGRectMake(88, 88, 200, 100)];
    redButton.backgroundColor = [UIColor redColor];
    [redButton configImpressId:@"1" impressData:@{@"a": @"b"}];
    [self.view addSubview:redButton];
}

@end
