//
//  TMModelTest.m
//  TMKit_Tests
//
//  Created by Frank Du on 2022/7/14.
//  Copyright © 2022 frank-du. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "TMDetailCol.h"

@interface TMModelTest : XCTestCase

@end

@implementation TMModelTest

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testExample {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    
    NSString *jsonString = @"{\"identifier\":\"100001\",\"type\":\"ALBUM\",\"desc\":\"Jay Chou is back with a self-directed music video for his title track \\\"Greatest Works Of Art\\\", featuring Chinese pianist Lang Lang.\",\"artists\":[{\"identifier\":10002,\"name\":\"Jay Chou\"}],\"name\":\"GREATEST WORKS OF ART\"}";
    
    TMDetailCol *c = [TMDetailCol tm_modelWithJSON:jsonString];

    NSString *resultString = [c tm_modelToJSONString];
    NSLog(@"Origin: %@", jsonString);
    NSLog(@"Result: %@", resultString);

    XCTAssertEqualObjects(jsonString, resultString);
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
