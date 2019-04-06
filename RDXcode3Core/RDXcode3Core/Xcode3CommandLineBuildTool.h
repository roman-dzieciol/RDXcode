//
//  Xcode3CommandLineBuildTool.h
//  Xcode3Core
//
//  Created by Roman Dzieciol on 4/5/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDDVTFoundation/RDDVTFoundation.h>
#import <RDIDEFoundation/RDIDEFoundation.h>

#import <RDXcode3Core/RDXcode3CoreDecls.h>

NS_ASSUME_NONNULL_BEGIN

@interface Xcode3CommandLineBuildTool : NSObject
{
    id _containerDidOpenContainerNotificationObserver;
    DVTCommandLineParser * _parser;
    char _shouldExit;
    char _allTargets;
    char _skipUnsupportedDestinations;
    char _parallelizeTargets;
    char _hideShellScriptEnvironment;
    char _dontActuallyRunCommands;
    char _skipUnavailableActions;
    char _quieterOutput;
    char _runSkippedTestsOnly;
    char _disableConcurrentTesting;
    char _disableAutomaticPackageResolution;
    char _usePackageSupportBuiltinSCM;
    char _collectBuildTimeStatistics;
    char _outputAsJSON;
    char _readSourceControlBlueprint;
    char _enableSourceControlKeychainAccess;
    char _disableSourceControlKeychainAccess;
    char _allowProvisioningUpdates;
    char _allowProvisioningDeviceRegistration;
    int _toolCommand;
    NSString * _name;
    NSArray * _arguments;
    NSDictionary * _environment;
    NSFileHandle * _standardInput;
    NSFileHandle * _standardOutput;
    NSFileHandle * _standardError;
    long long _exitStatus;
    NSString * _projectName;
    NSArray * _targetNames;
    NSString * _workspaceName;
    NSString * _schemeName;
    NSString * _xcconfigPathFromOption;
    NSString * _xcconfigPathFromEnvVar;
    NSString * _actionResultsBundlePathWithBaselineOverridesFromOption;
    NSString * _automaticBaselineDescription;
    NSString * _nameOfFileToFind;
    NSString * _archivePath;
    NSString * _exportOptionsPlist;
    NSString * _exportDestinationPath;
    NSArray * _buildActions;
    NSArray * _potentialBuildActions;
    NSArray * _buildSettingAssignmentStrings;
    Xcode3Project * _project;
    NSMutableArray * _targets;
    IDEWorkspace * _workspace;
    NSMutableDictionary * _perActionRunDestinations;
    NSString * _configurationName;
    NSArray * _architectures;
    NSString * _baseSdkName;
    NSArray * _toolchainNames;
    NSArray * _destinationSpecifications;
    NSNumber * _destinationTimeout;
    NSNumber * _enableBuildTimeline;
    NSNumber * _maxConcurrency;
    NSNumber * _maxDeviceTestConcurrency;
    NSNumber * _maxSimulatorTestConcurrency;
    NSNumber * _parallelTestingEnabledOverride;
    NSNumber * _parallelTestingWorkerCountOverride;
    NSNumber * _parallelTestingMaximumWorkerCount;
    NSString * _localizationPath;
    NSArray * _exportLanguages;
    NSString * _codeCoverageEnabled;
    NSString * _localizableStringsDataEnabled;
    NSString * _addressSanitizerEnabled;
    NSString * _threadSanitizerEnabled;
    NSString * _UBSanitizerEnabled;
    NSString * _testRunSpecificationPathString;
    NSArray * _skipTestIdentifiers;
    NSArray * _onlyTestIdentifiers;
    NSMutableDictionary * _testApplicationMappingOverrides;
    NSString * _testWithLanguage;
    NSString * _testWithRegion;
    NSString * _templateOutputPath;
    NSString * _templateTeamID;
    NSString * _templateName;
    NSString * _templatePlatform;
    NSString * _templateOptions;
    NSDictionary * _templateNonPermutedOptionValues;
    NSArray * _templateRequiredOptions;
    NSString * _clonedSourcePackagesDirPath;
    DVTMacroDefinitionTable * _synthesizedMacros;
    DVTMacroDefinitionTable * _macrosFromCommandLine;
    DVTMacroDefinitionTable * _macrosFromXcconfigOption;
    DVTMacroDefinitionTable * _macrosFromXcconfigEnvVar;
    NSMutableDictionary * _userDefaults;
    NSMutableDictionary * _environmentUserDefaults;
    NSOperationQueue * _buildToolQueue;
    NSString * _resultBundlePath;
    NSString * _baseResultBundlePath;
    NSString * _sparseResultBundlePath;
    NSString * _extractOnlyTestIdentifier;
    NSString * _sourceControlSSHKeyPath;
    DVTSourceControlWorkspaceBlueprint * _sourceControlBlueprint;
    _TtC13IDEFoundation31IDEActivityLogEventStreamWriter * _activityLogStreamWriter;
    IDEXBSBuildParameters * _xbsBuildParameters;
    NSObject<IDEXBSXcodebuildSupportProvider> * _xbsXcodebuildSupportProvider;
    IDEScheme * _scheme;
}
@property int toolCommand;
@property (nonatomic) char shouldExit;
@property long long exitStatus;
@property (copy) NSString * projectName;
@property (retain) NSArray * targetNames;
@property (copy) NSString * workspaceName;
@property (copy) NSString * schemeName;
@property (copy) NSString * xcconfigPathFromOption;
@property (copy) NSString * xcconfigPathFromEnvVar;
@property (copy) NSString * actionResultsBundlePathWithBaselineOverridesFromOption;
@property (copy) NSString * automaticBaselineDescription;
@property (copy) NSString * nameOfFileToFind;
@property (copy) NSString * archivePath;
@property (copy) NSString * exportOptionsPlist;
@property (copy) NSString * exportDestinationPath;
@property (retain) NSArray * buildActions;
@property (retain) NSArray * potentialBuildActions;
@property (retain) NSArray * buildSettingAssignmentStrings;
@property (retain) Xcode3Project * project;
@property (retain) NSMutableArray * targets;
@property char allTargets;
@property (retain) IDEWorkspace * workspace;
@property (retain) NSMutableDictionary * perActionRunDestinations;
@property (copy) NSString * configurationName;
@property (retain) NSArray * architectures;
@property (copy) NSString * baseSdkName;
@property (retain) NSArray * toolchainNames;
@property (copy) NSArray * destinationSpecifications;
@property char skipUnsupportedDestinations;
@property (copy) NSNumber * destinationTimeout;
@property char parallelizeTargets;
@property (retain) NSNumber * enableBuildTimeline;
@property char hideShellScriptEnvironment;
@property (copy) NSNumber * maxConcurrency;
@property (copy) NSNumber * maxDeviceTestConcurrency;
@property (copy) NSNumber * maxSimulatorTestConcurrency;
@property (retain) NSNumber * parallelTestingEnabledOverride;
@property (retain) NSNumber * parallelTestingWorkerCountOverride;
@property (retain) NSNumber * parallelTestingMaximumWorkerCount;
@property char dontActuallyRunCommands;
@property char skipUnavailableActions;
@property char quieterOutput;
@property (retain) NSString * localizationPath;
@property (retain) NSArray * exportLanguages;
@property (retain) NSString * codeCoverageEnabled;
@property (retain) NSString * localizableStringsDataEnabled;
@property (retain) NSString * addressSanitizerEnabled;
@property (retain) NSString * threadSanitizerEnabled;
@property (retain) NSString * UBSanitizerEnabled;
@property (retain) NSString * testRunSpecificationPathString;
@property (retain) NSArray * skipTestIdentifiers;
@property (retain) NSArray * onlyTestIdentifiers;
@property char runSkippedTestsOnly;
@property char disableConcurrentTesting;
@property (retain) NSMutableDictionary * testApplicationMappingOverrides;
@property (retain) NSString * testWithLanguage;
@property (retain) NSString * testWithRegion;
@property (retain) NSString * templateOutputPath;
@property (retain) NSString * templateTeamID;
@property (retain) NSString * templateName;
@property (retain) NSString * templatePlatform;
@property (retain) NSString * templateOptions;
@property (retain) NSDictionary * templateNonPermutedOptionValues;
@property (retain) NSArray * templateRequiredOptions;
@property (retain) NSString * clonedSourcePackagesDirPath;
@property char disableAutomaticPackageResolution;
@property char usePackageSupportBuiltinSCM;
@property char collectBuildTimeStatistics;
@property (retain) DVTMacroDefinitionTable * synthesizedMacros;
@property (retain) DVTMacroDefinitionTable * macrosFromCommandLine;
@property (retain) DVTMacroDefinitionTable * macrosFromXcconfigOption;
@property (retain) DVTMacroDefinitionTable * macrosFromXcconfigEnvVar;
@property (retain) NSMutableDictionary * userDefaults;
@property (retain) NSMutableDictionary * environmentUserDefaults;
@property (retain) NSOperationQueue * buildToolQueue;
@property (retain) NSString * resultBundlePath;
@property (copy) NSString * baseResultBundlePath;
@property (copy) NSString * sparseResultBundlePath;
@property (copy) NSString * extractOnlyTestIdentifier;
@property char outputAsJSON;
@property char readSourceControlBlueprint;
@property (retain) NSString * sourceControlSSHKeyPath;
@property (retain) DVTSourceControlWorkspaceBlueprint * sourceControlBlueprint;
@property char enableSourceControlKeychainAccess;
@property char disableSourceControlKeychainAccess;
@property (retain) _TtC13IDEFoundation31IDEActivityLogEventStreamWriter * activityLogStreamWriter;
@property (retain) IDEXBSBuildParameters * xbsBuildParameters;
@property (retain) NSObject<IDEXBSXcodebuildSupportProvider> * xbsXcodebuildSupportProvider;
@property char allowProvisioningUpdates;
@property char allowProvisioningDeviceRegistration;
@property (retain) IDEScheme * scheme;
@property (copy) NSString * name;
@property (copy) NSArray * arguments;
@property (copy) NSDictionary * environment;
@property (retain) NSFileHandle * standardInput;
@property (retain) NSFileHandle * standardOutput;
@property (retain) NSFileHandle * standardError;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
+ (char)useArchiveActionForInstall;
+ (char)enableInstallLocAction;
+ (id)timingLogAspect;
+ (id)xcodebuildDebugLogAspect;
+ (id)knownWorkspaceWrapperExtensions;
+ (id)swiftPackageFileDataType;
+ (id)filesInDirectory:(id)v1 withExtensions:(id)v2 errorString:(id _Nullable *_Nullable)v3;
+ (id)sharedCommandLineBuildTool;
- (id)init;
- (id)overridingProperties;
- (unsigned long long)_schemeLoadingTimeout;
- (unsigned long long)_projectLoadingTimeout;
- (void)_printWarningString:(id)v1;
- (void)_printErrorString:(id)v1 andFailWithCode:(long long)v2;
- (id)_supportedBuildActions;
- (id)_legacyBuildActionMapping;
- (IDESchemeCommand *)_schemeCommandForBuildAction:(NSString *)v1 outSchemeTask:(NSInteger *)v2;
- (id)_actionStringForBuildAction:(id)v1;
- (void)_parseOptions;
- (id)_stringByResolvingSymlinksInPath:(id)v1;
- (id)_resolveSdk:(id)v1;
- (void)_resolveBaseSdk;
- (void)_resolveRunDestinationsForBuildAction:(id)v1;
- (id)_remainingUnavailableRunDestinationsAfterWaitingForDestinationsToBecomeAvailable:(id)v1;
- (id)_unavailableRunDestinationsInDestinations:(id)v1;
- (id)_availableDestinationsDescriptionForDestinations:(id)v1 scheme:(id)v2;
- (char)waitForRemoteSourcePackagesToFinishLoading;
- (void)_resolveInputOptionsWithTimingSection:(id)v1;
- (void)_workspace:(id)v1 failedToResolveContainerForProjectFile:(id)v2;
- (void)unableToOpenProjectAtPath:(id)v1 reason:(id)v2;
- (char)_shouldTestConcurrentlyForRunDestinations:(id)v1;
- (id)_concurrentTestOperations:(id)v1 schemeTask:(long long)v2 schemeCommand:(id)v3 executionEnvironment:(id)v4 invocationRecord:(id)v5 buildLog:(id)v6 restorePersistedBuildResults:(char)v7 deviceOperationLimit:(long long)v8 simulatorOperationLimit:(long long)v9 contextString:(id)v10 outError:(id _Nullable *_Nullable)v11;
- (void)_printIssueSummariesGroupedByTargetFromInvocationRecord:(id)v1 issueSummariesKeyPath:(id)v2 messageKeyPath:(id)v3;
- (void)_printTestingSummariesFromInvocationRecord:(id)v1;
- (char)writeSourcePackageIndexFileToPath:(id)v1 error:(id _Nullable *_Nullable)v2;
- (void)_buildWithTimingSection:(id)v1;
- (void)_showBuildSettings;
- (void)_printVersionInfoAndExit;
- (id)schemeNamesInWorkspace:(id)v1;
- (void)_printContainerInformationAndExit;
- (id)_sdkForUseWithFind;
- (void)_printPathToExecutableAndExit;
- (void)_printPathToLibraryAndExit;
- (void)_enumerateAllPlatformsAlphabeticallyWithBlock:(void (^ /* unknown block signature */)(void))v1;
- (void)_writeJSONObjectTo:(id)v1 jsonObject:(id)v2;
- (id)_getJSONDataForSDK:(id)v1 platform:(id)v2;
- (char)_writeSDKListAsJSONTo:(id)v1;
- (void)_printShortSDKListAndExit;
- (void)_printDestinationListAndExit;
- (void)_printVerboseInfoForSDK:(id)v1 keysToEmit:(id)v2;
- (void)_printVerboseSDKListAndExit;
- (id)_availableExportArchiveOptionsSection;
- (void)_exportNotarizedAppAndExit;
- (void)_distributeArchiveAndExit;
- (void)_exportLocalizationsAndExit;
- (void)_importLocalizationsAndExit;
- (void)_resolvePackageDependenciesAndExit;
- (void)_saveProject;
- (void)_permuteTemplatesAndExit;
- (void)_createNewProjectAndExit;
- (void)_extractSparseResultBundle;
- (char)_shouldUseBuildMetricsFeature;
- (void)run;
- (long long)_buildLogVerbosity;
//- (void).cxx_destruct;

@end

NS_ASSUME_NONNULL_END
