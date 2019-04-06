//
//  DVTFilePath.m
//  DVTFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import "DVTFilePath.h"

@implementation DVTFilePath

+ (BOOL)supportsSecureCoding {
    return NO;
}

- (nonnull id)copyWithZone:(nullable NSZone *)zone {
    return nil;
}

- (void)dvt_provideFileSystemRepresentationToBlock:(void (^)(void))v1 {

}

- (void)encodeWithCoder:(nonnull NSCoder *)aCoder {

}

- (nullable instancetype)initWithCoder:(nonnull NSCoder *)aDecoder {
    return nil;
}

@end
