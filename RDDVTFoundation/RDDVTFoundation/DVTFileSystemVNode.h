//
//  RD\DVTFileSystemVNode.h
//  DVTFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDDVTFoundation/RDDVTFoundationDecls.h>
#import <os/lock.h>

NS_ASSUME_NONNULL_BEGIN

@interface DVTFileSystemVNode : NSObject {
    NSMutableDictionary * _derivedInfoDict;
    NSPointerArray * _filePaths;
    DVTFilePath * _filePath;
    struct os_unfair_lock_s _derivedInfoDictLock;
    unsigned long long _inodeNumber;
    long long _fileSize;
    unsigned long long _statFlags;
    long long _posixModificationTime;
    unsigned int _statUid;
    unsigned int _statGid;
    int _deviceNumber;
    unsigned short _statMode;
}
@property (readonly) DVTMountedFileSystem * fileSystem;
@property (readonly) int deviceNumber;
@property (readonly) unsigned long long inodeNumber;
@property (readonly) unsigned short statMode;
@property (readonly) unsigned int statUid;
@property (readonly) unsigned int statGid;
@property (readonly) unsigned long long statFlags;
@property (readonly) long long fileSize;
@property (readonly) long long posixModificationTime;
+ (id)lookupVNodeForDeviceNumber:(int)v1 inodeNumber:(unsigned long long)v2;
- (id)initWithStatInfo:(struct stat *)v1;
- (id)filePaths;
- (id)filePath;
- (void)addFilePath:(id)v1;
- (void)removeFilePath:(id)v1;
- (id)cachedValueForKey:(id)v1;
- (void)addCachedEntriesFromDictionary:(id)v1;
- (void)discardCaches;
- (void)recordStatInfo:(struct stat *)v1;
- (id)description;
//- (void).cxx_destruct;
@end

NS_ASSUME_NONNULL_END
