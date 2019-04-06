//
//  IDELaunchTestSchemeAction.h
//  RDIDEFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDIDEFoundation/IDECodeCoverageTargetProviding.h>
#import <RDIDEFoundation/RDIDEFoundationDecls.h>
#import <RDIDEFoundation/IDESchemeAction.h>

NS_ASSUME_NONNULL_BEGIN

@interface IDELaunchTestSchemeAction : IDESchemeAction<IDECodeCoverageTargetProviding> {
    NSMutableArray * _commandLineArgumentEntries;
    NSMutableArray * _environmentVariableEntries;
    char _mallocStackLoggingSelected;
    char _codeCoverageEnabled;
    char _onlyGenerateCoverageForSpecifiedTargets;
    char _enableAddressSanitizer;
    char _enableASanStackUseAfterReturn;
    char _enableThreadSanitizer;
    char _enableUBSanitizer;
    char _enableMainThreadChecker;
    unsigned int _debugProcessAsUID;
    NSString * _selectedDebuggerIdentifier;
    NSString * _selectedLauncherIdentifier;
    NSString * _selectedMallocStackLoggingType;
    NSDictionary * _additionalOptionEntriesDict;
    NSString * _language;
    NSString * _region;
    long long _systemAttachmentLifetime;
    long long _userAttachmentLifetime;
    NSString * _selectedMallocStackLoggingTypeTooltip;
    NSString * _debugAsWhichUser;
    NSMutableArray * _mutableCodeCoverageTargets;
}
@property (copy) NSString * debugAsWhichUser;
@property (retain) NSMutableArray * mutableCodeCoverageTargets;
@property (copy) NSString * selectedDebuggerIdentifier;
@property (copy) NSString * selectedLauncherIdentifier;
@property (nonatomic) unsigned int debugProcessAsUID;
@property (copy) NSMutableArray * commandLineArgumentEntries;
@property (readonly) NSMutableArray * mutableCommandLineArgumentEntries;
@property (copy) NSMutableArray * environmentVariableEntries;
@property (readonly) NSMutableArray * mutableEnvironmentVariableEntries;
@property (readonly) NSDictionary * additionalOptionEntriesDict;
@property char enableAddressSanitizer;
@property char enableASanStackUseAfterReturn;
@property char enableThreadSanitizer;
@property char enableUBSanitizer;
@property char enableMainThreadChecker;
@property (copy,nonatomic) NSString * language;
@property (copy,nonatomic) NSString * region;
@property long long systemAttachmentLifetime;
@property long long userAttachmentLifetime;
@property (readonly) NSArray * availableMallocStackLoggingTypes;
@property (copy) NSString * selectedMallocStackLoggingType;
@property char mallocStackLoggingSelected;
@property (copy) NSString * selectedMallocStackLoggingTypeTooltip;
@property (nonatomic) char codeCoverageEnabled;
@property (nonatomic) char onlyGenerateCoverageForSpecifiedTargets;
@property (readonly,nonatomic) NSArray * codeCoverageTargets;
+ (void)initialize;
+ (id)keyPathsForValuesAffectingDebugProcessAsUID;
- (void)_dvt_commonInit;
- (id)init;
- (id)initFromXMLUnarchiver:(id)v1 archiveVersion:(float)v2;
- (void)setRunContext:(id)v1;
- (id)createAdditionalDiagnosticsDict;
- (id)expandMacrosInString:(id)v1 forBuildParameters:(id)v2;
- (id)additionalOptions;
- (id)additionalOptionArchivingEntries;
- (void)modifyEnvironmentForMallocStackLogging:(id)v1;
- (void)_modifyEnvironmentForSQLLite:(id)v1;
- (id)environmentVariablesForBuildParameters:(id)v1;
- (char)_detectSwiftnessForTheRunnableWithSelector:(SEL)v1 expectedValue:(char)v2;
- (char)UBSanitizerAllowedForRunnable;
- (char)containSwiftForTheRunnable;
- (void)_setSelectedMallocStackLoggingType:(id)v1;
- (void)_updateSelectedMallocStackTooltip:(id)v1;
- (void)dvt_awakeFromXMLUnarchiver:(id)v1;
- (void)dvt_encodeRelationshipsWithXMLArchiver:(id)v1 version:(id)v2;
- (void)dvt_encodeAttributesWithXMLArchiver:(id)v1 version:(id)v2;
- (void)addCommandLineArguments:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addEnvironmentVariables:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addAdditionalOptions:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addCodeCoverageTargets:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)setEnableAddressSanitizerFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)setEnableASanStackUseAfterReturnFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)setEnableThreadSanitizerFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)setEnableUBSanitizerFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)setDisableMainThreadCheckerFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)setLanguageFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)setRegionFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)setSystemAttachmentLifetimeFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)setUserAttachmentLifetimeFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)setCodeCoverageEnabledFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)setOnlyGenerateCoverageForSpecifiedTargetsFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)addCodeCoverageTarget:(id)v1;
- (void)removeCodeCoverageTarget:(id)v1;
- (id)coverageBuildableInfosForBuildParameters:(id)v1;
//- (void).cxx_destruct;
@end

NS_ASSUME_NONNULL_END
