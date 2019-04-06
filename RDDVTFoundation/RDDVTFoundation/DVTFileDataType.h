//
//  DVTFileDataType.h
//  DVTFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDDVTFoundation/RDDVTFoundationDecls.h>

NS_ASSUME_NONNULL_BEGIN

@interface DVTFileDataType : NSObject<NSCopying> {
    struct DVTBitSet * _conformanceBitSet;
}
@property (readonly) NSString * identifier;
@property (readonly) NSString * displayName;
+ (id)_makeSynthesizedTypeStringRepresentationFromPrimaryType:(id)v1 secondaryTypes:(id)v2;
+ (void)_splitSynthesizedTypeStringRepresentation:(id)v1 intoPrimaryType:(id *)v2 andSecondaryTypes:(id *)v3;
+ (id)_synthesizedFileTypeWithPrimaryType:(id)v1 secondaryTypes:(id)v2;
+ (id)fileDataTypeFromStringRepresentation:(id)v1;
+ (id)fileDataTypeWithIdentifier:(id)v1;
+ (id)_convertFromLaunchServicesDynamicUTIIfNeeded:(id)v1;
+ (id)_launchServicesUTIForFileAtURL:(id)v1;
+ (id)_launchServicesUTIForFileAtPath:(id)v1 consideringFileContent:(char)v2;
+ (id)_launchServicesUTIForMimeType:(id)v1;
+ (id)_matchingTypeDetectorExtensionsForFilePathExtension:(id)v1;
+ (id)_findMatchingTypeUsingDetectors:(id)v1 givenCurrentMatchingType:(id)v2 filePath:(id)v3 allowCustomDetectors:(char)v4 error:(id *)v5;
+ (id)_fileDataTypeForFileAtPath:(id)v1 consideringFileContent:(char)v2 error:(id *)v3;
+ (id)fileDataTypeForFileContentAtURL:(id)v1 error:(id *)v2;
+ (id)fileDataTypeForFileContentAtPath:(id)v1 error:(id *)v2;
+ (id)fileDataTypeForFileURL:(id)v1 error:(id *)v2;
+ (id)fileDataTypeForFilePath:(id)v1 error:(id *)v2;
+ (id)fileDataTypeForFilename:(id)v1 error:(id *)v2;
+ (id)logAspect;
//- (id)initWithConformanceBitSetNoCopy:(struct DVTBitSet *)v1;
- (id)init;
- (void)dealloc;
- (char)isEqual:(id)v1;
- (id)stringRepresentation;
- (struct DVTBitSet *)conformanceBitSet;
- (nonnull id)copyWithZone:(nullable NSZone *)v1;
- (char)conformsToType:(id)v1;
- (char)conformsTo:(id)v1;
- (char)conformsToAnyIdentifierInSet:(id)v1;
- (char)isGenericFileDataType;
- (id)primaryFileDataType;
- (id)secondaryFileDataTypes;
- (id)fileConversionTypeForFilePath:(id)v1;
- (char)isDeclaredType;
- (char)isDynamicType;
- (char)isUnknownType;
@end

NS_ASSUME_NONNULL_END
