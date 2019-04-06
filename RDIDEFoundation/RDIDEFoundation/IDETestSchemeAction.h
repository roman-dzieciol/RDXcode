//
//  IDETestSchemeAction.h
//  RDIDEFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDIDEFoundation/RDIDEFoundationDecls.h>
#import <RDIDEFoundation/IDELaunchTestSchemeAction.h>

NS_ASSUME_NONNULL_BEGIN

@interface IDETestSchemeAction : IDELaunchTestSchemeAction {
    NSMutableArray * _testableReferences;
    NSMutableArray * _loadingTestableReferences;
    char _localizableStringsDataGatheringEnabled;
    DVTObservingToken * _testablesObservingToken;
    DVTObservingToken * _skippedTestsObservingToken;
    DVTObservingToken * _workspaceRunnableProductsToken;
    DVTNotificationToken * _buildablesToken;
    NSArray * _hostBuildableReferences;
    IDESchemeBuildableReference * _testBuildableReferenceToUseForMacroExpansion;
    char _shouldUseLaunchSchemeArgsEnv;
    char _suppressSimulatorApplication;
}
@property (copy) NSMutableArray * testableReferences;
@property (readonly) NSMutableArray * mutableTestableReferences;
@property (readonly) NSArray * testBuildableReferences;
@property (readonly) NSArray * hostBuildableReferences;
@property (readonly,getter=isTestable) char testable;
@property (nonatomic) char shouldUseLaunchSchemeArgsEnv;
@property char localizableStringsDataGatheringEnabled;
@property (nonatomic) char suppressSimulatorApplication;
+ (void)initialize;
+ (void)forceCodeCoverageEnabledTo:(char)v1;
+ (void)forceLocalizableStringsDataEnabledTo:(char)v1;
+ (id)keyPathsForValuesAffectingSubtitle;
+ (id)keyPathsForValuesAffectingDoesNonActionWork;
+ (id)keyPathsForValuesAffectingTestBuildableReferences;
+ (id)keyPathsForValuesAffectingBuildableReferenceToUseForMacroExpansion;
- (id)init;
- (void)_commonInit;
- (id)name;
- (id)subtitle;
- (char)doesNonActionWork;
- (id)runnable;
- (char)codeCoverageEnabled;
- (id)effectiveBlueprintForOptimizationProfileGenerationForSchemeCommand:(id)v1;
- (id)workingDirectoryForBuildParameters:(id)v1;
- (id)testOperationWithSchemeOperationParameters:(id)v1 testManager:(id)v2 withBuildOperation:(id)v3 buildParameters:(id)v4 schemeCommand:(id)v5 actionRecord:(id)v6 testRunSpecifications:(id)v7 coverageBuildableInfos:(id)v8 deviceAvailableChecker:(void (^ /* unknown block signature */)(void))v9 outError:(id *)v10 actionCallbackBlock:(void (^ /* unknown block signature */)(void))v11;
- (id)_finalizeLogOperationWithLog:(id)v1;
- (void)_prepareForMessageTracer:(id)v1;
- (void)testableDidChangeHost:(id)v1;
- (void)setRunContext:(id)v1;
- (void)_updateTestActionBuildableToUseForMacroExpansion;
- (id)commandLineArgumentEntries;
- (id)mutableCommandLineArgumentEntries;
- (id)commandLineArgumentsForBuildParameters:(id)v1;
- (id)environmentVariableEntries;
- (id)mutableEnvironmentVariableEntries;
- (id)additionalOptions;
- (char)shouldDebugXPCServices;
- (char)shouldDebugAppExtensions;
- (id)buildableReferenceToUseForMacroExpansion;
- (void)setBuildableReferenceToUseForMacroExpansion:(id)v1;
- (id)expandMacrosInString:(id)v1 forBuildParameters:(id)v2;
- (void)primitiveInvalidate;
- (id)initFromXMLUnarchiver:(id)v1 archiveVersion:(float)v2;
- (void)dvt_encodeAttributesWithXMLArchiver:(id)v1 version:(id)v2;
- (void)dvt_encodeRelationshipsWithXMLArchiver:(id)v1 version:(id)v2;
- (void)setShouldUseLaunchSchemeArgsEnvFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)setLocalizableStringsDataGatheringEnabledFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)addTestables:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addMacroExpansion:(id)v1 fromXMLUnarchiver:(id)v2;
- (char)needsNewSchemeVersionForAppDataPackages;
- (char)needsNewSchemeVersionForLocationSimulation;
- (char)_isEnabledTest:(id)v1 testableReference:(id)v2;
- (id)_testableReferenceForTestable:(id)v1;
- (char)isTestEnabled:(id)v1;
- (char)isTestableEnabled:(id)v1;
- (char)isTestOrTestableEnabled:(id)v1;
- (void)_postEnabledStateNotification;
- (void)_enableTestOrTestable:(id)v1;
- (void)_disableTestOrTestable:(id)v1;
- (void)disableTestsReferencedByTestableReference:(id)v1;
- (void)setTestOrTestable:(id)v1 enabled:(char)v2;
- (id)testableReferenceForTestable:(id)v1;
- (int)internalDebuggerToolchainSelectionMode;
- (id)selectedInternalDebuggerToolchainIdentifier;
//- (void).cxx_destruct;
@end

NS_ASSUME_NONNULL_END
