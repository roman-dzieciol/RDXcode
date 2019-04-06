//
//  IDESchemeAction.h
//  RDIDEFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDIDEFoundation/RDIDEFoundationDecls.h>

NS_ASSUME_NONNULL_BEGIN

@interface IDESchemeAction : NSObject<DVTXMLUnarchiving,DVTInvalidation> {
    char _hasAwoken;
    NSMutableArray * _prePhaseExecutionActions;
    NSMutableArray * _postPhaseExecutionActions;
    NSObject<DVTInvalidation> * _buildSettingsDidChangeNotificationObservingToken;
    DVTObservingToken * _activeRunDestinationObservingToken;
    int _internalDebuggerToolchainSelectionMode;
    int _toolchainState;
    IDEScheme * _runContext;
    IDERunnable * _runnable;
    IDESchemeBuildableReference * _buildableReferenceToUseForMacroExpansion;
    NSString * _buildConfiguration;
    IDEFileReference * _notificationPayloadFile;
    NSString * _selectedInternalDebuggerToolchainIdentifier;
    DVTToolchain * _lldbToolchain;
    DVTToolchain * _llvmProfdataToolchain;
    NSString * _intentQueryString;
}
@property (readonly) NSMutableArray * _prePhaseExecutionActionsProxies;
@property (readonly) NSMutableArray * _postPhaseExecutionActionsProxies;
@property (retain) DVTToolchain * lldbToolchain;
@property (readonly) char hasAwoken;
@property (readonly) IDEScheme * runContext;
@property (retain,nonatomic) IDERunnable * runnable;
@property (readonly) NSString * name;
@property (readonly) NSString * subtitle;
@property (readonly) char doesNonActionWork;
@property (readonly,nonatomic) char debugAppExtensions;
@property (copy) NSString * buildConfiguration;
@property (retain) IDEFileReference * notificationPayloadFile;
@property (copy) NSMutableArray * prePhaseExecutionActions;
@property (readonly) NSMutableArray * mutablePrePhaseExecutionActions;
@property (copy) NSMutableArray * postPhaseExecutionActions;
@property (readonly) NSMutableArray * mutablePostPhaseExecutionActions;
@property (retain) IDESchemeBuildableReference * buildableReferenceToUseForMacroExpansion;
@property (nonatomic) int internalDebuggerToolchainSelectionMode;
@property (retain) NSString * selectedInternalDebuggerToolchainIdentifier;
@property int toolchainState;
@property (readonly) DVTToolchain * llvmProfdataToolchain;
@property (retain) NSString * intentQueryString;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
@property (readonly,nonatomic,getter=isValid) char valid;
@property (readonly) DVTStackBacktrace * invalidationBacktrace;
@property (retain) DVTStackBacktrace * creationBacktrace;
+ (void)initialize;
+ (void)forceAddressSanitizerEnabledTo:(char)v1;
+ (void)forceThreadSanitizerEnabledTo:(char)v1;
+ (bool)schemeActionIsSupportedForDevice:(id)v1 schemeCommand:(id)v2 outError:(id *)v3;
+ (void)forceUBSanitizerEnabledTo:(char)v1;
+ (char)runDestinationSupportsSwiftDevelopmentRuntime:(id)v1 outError:(id *)v2;
+ (char)shouldAllowCustomPhaseActions;
+ (id)keyPathsForValuesAffectingRunnable;
+ (char)_addSanitizer:(unsigned long long)v1 environmentVariables:(id)v2 buildParameters:(id)v3 buildable:(id)v4 debugAppExtensions:(char)v5 debugging:(char)v6 testingSpecifier:(id)v7 error:(id *)v8;
+ (char)addAddressSanitizerEnvironmentVariables:(id)v1 buildParameters:(id)v2 buildable:(id)v3 debugAppExtensions:(char)v4 debugging:(char)v5 testingSpecifier:(id)v6 error:(id *)v7;
+ (char)addThreadSanitizerEnvironmentVariables:(id)v1 buildParameters:(id)v2 buildable:(id)v3 debugAppExtensions:(char)v4 debugging:(char)v5 testingSpecifier:(id)v6 error:(id *)v7;
+ (char)addUBSanitizerEnvironmentVariables:(id)v1 buildParameters:(id)v2 buildable:(id)v3 debugAppExtensions:(char)v4 debugging:(char)v5 testingSpecifier:(id)v6 error:(id *)v7;
+ (void)setupMainThreadCheckerInEnvironmentVariables:(id)v1 dylibPath:(id)v2;
+ (id)bundleIdentifierFromBuildableProduct:(id)v1 withBuildParameters:(id)v2;
+ (void)updateSearchPathSettingsInEnvironment:(id)v1 withBuildProducts:(id)v2 runDestination:(id)v3;
+ (id)commandLineArgumentsForLanguage:(id)v1 andRegion:(id)v2;
- (id)init;
- (id)initFromXMLUnarchiver:(id)v1 archiveVersion:(float)v2;
- (void)setupObservers;
- (void)setRunContext:(id)v1;
- (void)_resetToolchainStatusHard:(char)v1;
- (void)updateBuildableForChangeInRunnable;
- (id)extensionInfosForExtensions:(id)v1;
- (id)extensionInfosForExtensionBuildables:(id)v1 schemeCommand:(id)v2;
- (id)filePathsForContainersAndExtensionsForBuildParameters:(id)v1 runnableProductType:(id)v2 schemeCommand:(id)v3;
- (void)updateExtensionInfosOfLaunchParmeters:(id)v1;
- (id)realAppNameForRunnablePath:(id)v1;
- (id)setUpActionDependenciesForCorePhaseOperation:(id)v1 shouldRunPostActionsBlock:(void (^ /* unknown block signature */)(void))v2 prePhaseEnvironmentPopulationBlock:(void (^ /* unknown block signature */)(void))v3 postPhaseEnvironmentPopulationBlock:(void (^ /* unknown block signature */)(void))v4 buildParameters:(id)v5 schemeActionResultOperation:(id)v6 error:(id *)v7;
- (id)_sanitizerSchemeActionForSchemeCommand:(id)v1;
- (char)addressSanitizerEnabledForSchemeCommand:(id)v1;
- (char)threadSanitizerEnabledForSchemeCommand:(id)v1 runDestination:(id)v2;
- (char)UBSanitizerEnabledForSchemeCommand:(id)v1 runDestination:(id)v2;
- (char)mainThreadCheckerEnabledForSchemeCommand:(id)v1 runDestination:(id)v2;
- (char)_runDestinationIsX86_64:(id)v1;
- (char)_runDestinationIsArm64:(id)v1;
- (char)threadSanitizerAllowedForRunDestination:(id)v1;
- (char)UBSanitizerAllowedForRunnable;
- (char)mallocStackLightAllowedForRunDestination:(id)v1;
- (id)adjustedBuildParametersForMacroExpansionBuildableWithBaselineParamters:(id)v1;
- (id)stringListForBuildSettings:(id)v1 forSchemeCommand:(id)v2 buildable:(id)v3;
- (id)stringListForBuildSettings:(id)v1 forSchemeCommand:(id)v2;
- (id)expandMacrosInString:(id)v1 forSchemeCommand:(id)v2;
- (id)expandMacrosInString:(id)v1 forSchemeCommand:(id)v2 buildParameters:(id)v3;
- (id)absolutePathOfBuildSetting:(id)v1 forSchemeCommand:(id)v2;
- (id)bundleIdentifierWithRunnablePath:(id)v1;
- (void)primitiveInvalidate;
- (void)insertObject:(id)v1 inPrePhaseExecutionActionsAtIndex:(unsigned long long)v2;
- (void)removeObjectFromPrePhaseExecutionActionsAtIndex:(unsigned long long)v1;
- (void)insertPrePhaseExecutionActions:(id)v1 atIndexes:(id)v2;
- (void)removePrePhaseExecutionActionsAtIndexes:(id)v1;
- (void)replaceObjectInPrePhaseExecutionActionsAtIndex:(unsigned long long)v1 withObject:(id)v2;
- (void)replacePrePhaseExecutionActionsAtIndexes:(id)v1 withObjects:(id)v2;
- (void)insertObject:(id)v1 inPostPhaseExecutionActionsAtIndex:(unsigned long long)v2;
- (void)removeObjectFromPostPhaseExecutionActionsAtIndex:(unsigned long long)v1;
- (void)insertPostPhaseExecutionActions:(id)v1 atIndexes:(id)v2;
- (void)removePostPhaseExecutionActionsAtIndexes:(id)v1;
- (void)replaceObjectInPostPhaseExecutionActionsAtIndex:(unsigned long long)v1 withObject:(id)v2;
- (void)replacePostPhaseExecutionActionsAtIndexes:(id)v1 withPostPhaseExecutionActions:(id)v2;
- (void)schemeObjectGraphSetupComplete;
- (void)_addIDEDisabledOSActivityDTMode:(id)v1;
- (void)modifyEnvironmentForLogging:(id)v1 buildParameters:(id)v2;
- (void)dvt_awakeFromXMLUnarchiver:(id)v1;
- (void)dvt_encodeAttributesWithXMLArchiver:(id)v1 version:(id)v2;
- (void)dvt_encodeRelationshipsWithXMLArchiver:(id)v1 version:(id)v2;
- (void)setNotificationPayloadFileFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)addPreActions:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addPostActions:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addRemoteRunnable:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addPathRunnable:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addBuildableProductRunnable:(id)v1 fromXMLUnarchiver:(id)v2;
- (char)isDeprecatedOption:(id)v1;
- (id)_resolvedRunnableBuildableForToolchainDetection;
- (id)_buildProductToolchainIdentifiersForSchemeCommand:(id)v1;
- (char)runnableUsesInternalSDK;
- (char)useInternalDebuggerToolchainSelectionLogic;
- (id)lldbToolchainNameForSchemeCommand:(id)v1 buildable:(id)v2 performanceMetric:(id)v3;
- (id)buildProductToolchainForSchemeCommand:(id)v1;
- (id)bestLLDBToolchainForSchemeCommand:(id)v1 preferBuildProductToolchain:(char)v2;
- (id)llvmProfdataToolchainForSchemeCommand:(id)v1;
- (id)swiftVersionOfRunnableForSchemeCommand:(id)v1;
//- (void).cxx_destruct;
@end

NS_ASSUME_NONNULL_END
