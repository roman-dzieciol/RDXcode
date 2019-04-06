//
//  DVTFilePath.h
//  DVTFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDDVTFoundation/RDDVTFoundationDecls.h>
#import <RDDVTFoundation/DVTFileSystemRepresentationProviding.h>
#import <os/lock.h>


NS_ASSUME_NONNULL_BEGIN

@interface DVTFilePath : NSObject<NSCopying,DVTFileSystemRepresentationProviding,NSSecureCoding> {
    DVTFilePath * _parentPath;
    struct fastsimplearray * _childfsaPaths;
    DVTFileSystemVNode * _vnode;
    DVTFileDataType * _presumedType;
    unsigned long long _numAssociates;
    unsigned long long _numObservers;
    id _associates;
    NSString * _pathString;
    NSURL * _fileURL;
    char _hasResolvedVnode;
    char _cleanRemoveFromParent;
    id _validationState;
    unsigned short _fsrepLength;
    struct os_unfair_lock_s _childPathsLock;
    struct os_unfair_lock_s _associatesLock;
    char _fsrep[0];
}
@property (readonly) DVTFilePath * parentFilePath;
@property (readonly) DVTFilePath * volumeFilePath;
@property (readonly) NSString * pathString;
@property (readonly) NSArray * pathComponents;
@property (readonly) NSURL * fileURL;
@property (readonly) NSString * fileName;
@property (readonly) NSString * pathExtension;
@property (readonly) char existsInFileSystem;
@property (readonly) char isReadable;
@property (readonly) char isWritable;
@property (readonly) char isDeletable;
@property (readonly) char isExecutable;
@property (readonly) char isSymbolicLink;
@property (readonly) char isExcludedFromBackup;
@property (readonly) NSString * fileTypeAttribute;
@property (readonly) NSDate * modificationDate;
@property (readonly) NSArray * directoryContents;
@property (readonly) NSArray * sortedDirectoryContents;
@property (readonly) char isDirectory;
@property (readonly) NSDictionary * fileAttributes;
@property (readonly) NSDictionary * fileSystemAttributes;
@property (readonly) NSURL * fileReferenceURL;
@property (readonly) DVTFilePath * symbolicLinkDestinationFilePath;
@property (readonly) DVTFileDataType * fileDataTypeFromFileContent;
@property (readonly) DVTFileDataType * fileDataTypePresumed;
@property (readonly) NSNumber * recursiveFileSize;
+ (void)initialize;
+ (id)rootFilePath;
+ (id)_lookupOrCreateFilePathWithParentPath:(id)v1 fileSystemRepresentation:(const  char *)v2 length:(unsigned long long)v3 allowCreation:(char)v4;
+ (BOOL)supportsSecureCoding;
+ (id)_filePathForParent:(id)v1 fileSystemRepresentation:(const  char *)v2 length:(unsigned long long)v3 allowCreation:(char)v4;
+ (id)_filePathForParent:(id)v1 pathString:(id)v2;
+ (id)filePathForFileSystemRepresentation:(const  char *)v1 length:(unsigned long long)v2;
+ (id)filePathForFileSystemRepresentation:(const  char *)v1;
+ (id)filePathForPathString:(id)v1;
+ (id)filePathForFileURL:(id)v1;
+ (void)registerCachedInfoDerivationFunction:(void * *)v1 forKey:(id)v2;
+ (void * *)_cachedInfoDerivationFunctionForKey:(id)v1 derivationLock:(id *)v2;
+ (void)_registerStandardCachedFileInfoDerivationFunctionsIfNeeded;
- (void)dealloc;
- (void)_invokeWithLockedChildPaths:(void (^ /* unknown block signature */)(void))v1;
- (void)_invokeWithLockedAssociates:(void (^ /* unknown block signature */)(void))v1;
- (id)init;
//- (id)copyWithZone:(struct _NSZone *)v1;
- (nullable instancetype)initWithCoder:(nonnull NSCoder *)aDecoder;
- (void)encodeWithCoder:(id)v1;
- (char)isAncestorOfFilePath:(id)v1;
- (id)filePathForRelativeFileSystemRepresentation:(const  char *)v1 length:(unsigned long long)v2;
- (id)filePathForRelativeFileSystemRepresentation:(const  char *)v1;
- (id)filePathForRelativePathString:(id)v1;
- (id)filePathForUniqueRelativeFileWithPrefix:(id)v1 error:(id *)v2;
- (id)filePathForUniqueRelativeDirectoryWithPrefix:(id)v1 error:(id *)v2;
- (char)_getFSRepIntoBuffer:(char * *)v1 ofLength:(unsigned long long)v2 requiredLength:(unsigned long long)v3 endPtr:(char * *)v4 allowAllocation:(char)v5;
- (char)getFullFileSystemRepresentationIntoBuffer:(char * *)v1 ofLength:(unsigned long long)v2 allowAllocation:(char)v3;
- (char)_fileNameHasSuffix:(const  char *)v1 suffixLength:(long long)v2;
- (const  char *)fileNameFSRepReturningLength:(long long *)v1;
- (void)invokeWithAccessToFileSystemRepresentation:(void (^ /* unknown block signature */)(void))v1;
- (id)relativePathStringFromAncestorFilePath:(id)v1;
- (id)relativePathStringFromFilePath:(id)v1;
- (char)isEqual:(id)v1;
- (char)isSameFileAsFilePath:(id)v1;
- (void)_locked_tentativelyInvalidateChildrenRecursivelyWithChildrenShouldBeTentativelyInvalid:(char)v1;
- (void)_locked_validateTentativelyInvalidatedChildrenRecursively;
- (void)_invalidateChildrenRecursivelyKnownDoesNotExist:(char)v1;
- (void)_invalidateKnownDoesNotExist:(char)v1 explicitlyInvalidateChildren:(char)v2;
- (void)invalidateFilePath;
- (void)_invalidateFilePathAndChildren;
- (void)_invalidateFilePathAndChildrenIncludingEquivalents;
- (id)_locked_vnodeKnownDoesNotExist:(char)v1;
- (id)_locked_vnode;
- (char)_hasResolvedVnode;
- (void)excludeFromBackup;
- (void)performCoordinatedReadRecursively:(char)v1;
- (id)directoryContentsWithError:(id *)v1;
- (id)machOArchitecturesWithError:(id *)v1;
- (id)recursiveFileSizeWithError:(id *)v1;
- (id)cachedValueForKey:(id)v1;
- (char)_addInfoForObserversOfChangedFilePath:(id)v1 toObjects:(id)v2 roles:(id)v3 blocks:(id)v4 dispatchQueues:(id)v5 operationQueues:(id)v6;
- (char)_hasChangeObservers;
- (void)_notifyAssociatesOfChange;
- (void)_addAssociatesWithRole:(id)v1 toArray:(id *)v2;
- (id)associatesWithRole:(id)v1 forAllPathsToSameFile:(char)v2;
- (id)associatesWithRole:(id)v1;
- (void)addAssociate:(id)v1 withRole:(id)v2;
- (void)addAssociate:(id)v1 withRole:(id)v2 observingDidChangeRecursively:(char)v3 onDispatchQueue:(id)v4 block:(void (^ /* unknown block signature */)(void))v5;
- (void)addAssociate:(id)v1 withRole:(id)v2 observingDidChangeRecursively:(char)v3 onOperationQueue:(id)v4 block:(void (^ /* unknown block signature */)(void))v5;
- (void)removeAssociate:(id)v1 withRole:(id)v2;
- (void)removeAssociatesWithRole:(id)v1;
- (void)removeAssociate:(id)v1;
- (void)removeAllAssociates;
- (void)simulateFileSystemNotificationAndNotifyAssociatesForUnitTests;
- (long long)comparePathString:(id)v1;
- (void)dvt_provideFileSystemRepresentationToBlock:(void (^ /* unknown block signature */)(void))v1;
- (id)description;
- (id)_descriptionOfAssociates;
//- (void).cxx_destruct;

@end

NS_ASSUME_NONNULL_END
