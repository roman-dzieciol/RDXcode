//
//  DVTMountedFileSystem.h
//  DVTFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDDVTFoundation/RDDVTFoundationDecls.h>

NS_ASSUME_NONNULL_BEGIN

@interface DVTMountedFileSystem : NSObject {
    int _deviceNumber;
    NSString * _mountPath;
    NSMapTable * _inodesToVNodes;
}
@property (readonly) int deviceNumber;
@property (readonly) NSString * mountPath;
+ (id)mountedFileSystemWithDeviceNumber:(int)v1;
- (id)initWithDeviceNumber:(int)v1 statfsInfo:(struct statfs *)v2;
- (id)vnodeForInodeNumber:(unsigned long long)v1;
- (void)noteFileSystemWasUnmounted;
- (void)addVNode:(id)v1;
- (void)removeVNode:(id)v1;
- (id)description;
//- (void).cxx_destruct;
@end

NS_ASSUME_NONNULL_END
