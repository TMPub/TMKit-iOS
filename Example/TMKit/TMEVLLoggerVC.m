//
//  TMEVLLoggerVC.m
//  TMKit_Example
//
//  Created by TMKit on 2022/6/18.
//

#import "TMEVLLoggerVC.h"
@import TMKit.TMEVLLogger;
@import TMKit.TMEVLLoggerImps;

typedef NS_ENUM(NSUInteger, TMEVLEventCat) {
    TMEVLEventCatNone = 0,
    TMEVLEventCatClick = 1,
    TMEVLEventCatImpress = 2
    // ...
};

typedef NS_ENUM(NSUInteger, TMEVLEventSubCat) {
    TMEVLEventSubCatNone = 0,
    TMEVLEventSubCatClick = 1,
    TMEVLEventSubCatImpress = 2
    // ...
};

@interface TMEVLLoggerVC ()

@end

@implementation TMEVLLoggerVC

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 初始化配置，通常放在AppDelegate里
    if (!TMEVLLogger.shared.hasSetup) {
        [self setupEVLLogger];
    }
    
    UIButton *btnGreen = [UIButton buttonWithType:UIButtonTypeSystem];
    btnGreen.frame = CGRectMake(100.0, 200.0, 120.0, 30.0);
    [btnGreen setTitle:@"Log in GREEN" forState:UIControlStateNormal];
    [btnGreen addTarget:self action:@selector(btnLogGreen:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btnGreen];
    
    UIButton *btnRed = [UIButton buttonWithType:UIButtonTypeSystem];
    btnRed.frame = CGRectMake(100.0, 250.0, 120.0, 30.0);
    [btnRed setTitle:@"Log in RED" forState:UIControlStateNormal];
    [btnRed addTarget:self action:@selector(btnLogRed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btnRed];
}

- (void)setupEVLLogger {
    TMEVLGreenChannelConfig *gConfig = [[TMEVLGreenChannelConfig alloc] init];
    TMEVLRedChannelConfig *rConfig = [[TMEVLRedChannelConfig alloc] init];
    TMEVLConfig *config = [[TMEVLConfig alloc] initWithGreenChannelConfig:gConfig redChannelConfig:rConfig];
    TMEVLUploader *uploader = [[TMEVLUploader alloc] init];
    
    NSString *docPath = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject;
    NSString *dirPath = [docPath stringByAppendingPathComponent:@"evl"];
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    BOOL isDir = NO;
    if (![fileManager fileExistsAtPath:dirPath isDirectory:&isDir] || !isDir) {
        [fileManager createDirectoryAtPath:dirPath withIntermediateDirectories:YES attributes:nil error:nil];
    }
    
    NSString *gPath = [dirPath stringByAppendingPathComponent:@"g.storage"];
    NSString *rPath = [dirPath stringByAppendingPathComponent:@"r.storage"];
    TMEVLStorageSQLite *greenStorage = [[TMEVLStorageSQLite alloc] initWithPath:gPath inChannel:TMEVLChannelGreen];
    TMEVLStorageSQLite *redStorage = [[TMEVLStorageSQLite alloc] initWithPath:rPath inChannel:TMEVLChannelRed];
    
    [TMEVLLogger.shared setupWithConfig:config uploader:uploader greenStorage:greenStorage redStorage:redStorage];
    
#ifdef DEBUG
    TMEVLLogger.shared.isDebugMode = YES;
#endif
}

- (void)btnLogGreen:(id)sender {
    TMEVLEvent *event = [[TMEVLEvent alloc] init];
    event.channel = TMEVLChannelGreen;
    event.evtId = @"AD_CLIENT_RESPONSE";
    event.cat = [NSString stringWithFormat:@"%@", @(TMEVLEventCatClick)];
    event.subCat = [NSString stringWithFormat:@"%@", @(TMEVLEventSubCatClick)];
    event.data = @{@"ad_loadtime":@(4)};
    
    [TMEVLLogger.shared logEvent:event];
}

- (void)btnLogRed:(id)sender {
    TMEVLEvent *event = [[TMEVLEvent alloc] init];
    event.channel = TMEVLChannelRed;
    event.evtId = @"ButtonClick";
    event.cat = [NSString stringWithFormat:@"%@", @(TMEVLEventCatClick)];
    event.subCat = [NSString stringWithFormat:@"%@", @(TMEVLEventSubCatClick)]; ;
    
    [TMEVLLogger.shared logEvent:event];
}

@end
