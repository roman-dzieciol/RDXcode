//
//  IDEScheme.h
//  RDIDEFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDIDEFoundation/RDIDEFoundationDecls.h>
#import <RDDVTFoundation/RDDVTFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IDEScheme : NSObject<DVTInvalidation> {
    IDEBuildSchemeAction * _buildSchemeAction;
    IDETestSchemeAction * _testSchemeAction;
    IDELaunchSchemeAction * _launchSchemeAction;
    IDEArchiveSchemeAction * _archiveSchemeAction;
    IDEProfileSchemeAction * _profileSchemeAction;
    IDEAnalyzeSchemeAction * _analyzeSchemeAction;
    IDEInstallSchemeAction * _installSchemeAction;
    IDEIntegrateSchemeAction * _integrateSchemeAction;
    NSString * _lastUpgradeVersion;
    NSString * _cachedLastUpgradeVersion;
    char _hasRunUpgradeCheck;
    char _wasUpgraded;
    IDERunnable * _oldFormatArchivedRunnable;
    IDERunContextManager * _runContextManager;
    IDEContainer<IDECustomDataStoring> * _customDataStoreContainer;
    DVTCustomDataSpecifier * _customDataSpecifier;
    IDERunDestination * _lastChosenRunDestination;
    NSArray * _availableRunDestinations;
    char _didResortToFallbackRunDestination;
    char _isShown;
    unsigned long long _orderHint;
    char _dataStoreClosed;
    char _deferredSaveScheduled;
    char _registeredForIsBuildableNotifications;
    NSNumber * _isArchivable;
    id _isArchivableNotificationToken;
    NSNumber * _isInstallable;
    id _isInstallableNotificationToken;
    id _buildablesToken;
    char _hasUnsupportedArchiveData;
    DVTDelayedInvocation * _runDestinationInvalidationScheduler;
    char _transient;
    char _persisted;
    char _wasCreatedForAppExtension;
    char _schemeRunnableRunsDirectlyOnPairedProxyDevice;
    char _runDestinationInvalidationSuspended;
    char _runDestinationInvalidationPending;
    IDEEntityIdentifier * _schemeIdentifier;
    NSError * _loadError;
    DVTObservingToken * _workspaceReferenceContainersObservingToken;
    IDESchemeOrderedWorkspaceNotificationManager * _orderedWorkspaceNotificationManager;
}
@property (retain) IDERunContextManager * runContextManager;
@property (retain) NSError * loadError;
@property (retain) IDEBuildSchemeAction * buildSchemeAction;
@property (retain) IDETestSchemeAction * testSchemeAction;
@property (retain) IDELaunchSchemeAction * launchSchemeAction;
@property (retain) IDEArchiveSchemeAction * archiveSchemeAction;
@property (retain) IDEProfileSchemeAction * profileSchemeAction;
@property (retain) IDEAnalyzeSchemeAction * analyzeSchemeAction;
@property (retain) IDEIntegrateSchemeAction * integrateSchemeAction;
@property (retain) IDEInstallSchemeAction * installSchemeAction;
@property (copy,nonatomic) IDEEntityIdentifier * schemeIdentifier;
@property (retain) DVTObservingToken * workspaceReferenceContainersObservingToken;
@property (nonatomic,getter=isRunDestinationInvalidationSuspended) char runDestinationInvalidationSuspended;
@property (getter=isRunDestinationInvalidationPending) char runDestinationInvalidationPending;
@property (getter=isTransient) char transient;
@property (nonatomic,getter=isPersisted) char persisted;
@property (retain) IDESchemeOrderedWorkspaceNotificationManager * orderedWorkspaceNotificationManager;
@property (retain) IDERunDestination * lastChosenRunDestination;
@property (retain) NSArray * availableRunDestinations;
@property (retain,nonatomic) IDEContainer<IDECustomDataStoring> * customDataStoreContainer;
@property (readonly) DVTCustomDataSpecifier * customDataSpecifier;
@property (copy) NSString * name;
@property (readonly) NSString * disambiguatedName;
@property char isShared;
@property char isShown;
@property (copy) NSString * lastUpgradeVersion;
@property (copy) NSString * cachedLastUpgradeVersion;
@property char hasRunUpgradeCheck;
@property char wasUpgraded;
@property (readonly) char isClosed;
@property char wasCreatedForAppExtension;
@property (readonly) char schemeRunnableRequiresPairedProxyDevice;
@property (readonly) char schemeRunnableRunsDirectlyOnPairedProxyDevice;
@property unsigned long long orderHint;
@property (readonly,getter=isBuildable) char buildable;
@property (readonly,getter=isRunnable) char runnable;
@property (readonly,getter=isProfilable) char profilable;
@property (readonly,getter=isAnalyzable) char analyzable;
@property (readonly,getter=isArchivable) char archivable;
@property (readonly,getter=isTestable) char testable;
@property (readonly,getter=isInstallable) char installable;
@property (readonly,getter=isIntegratable) char integratable;
@property (readonly) NSArray * nonFaultingAvailableRunDestinations;
@property (readonly) char didResortToFallbackRunDestination;
@property (readonly) NSData * xmlData;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
@property (readonly,nonatomic,getter=isValid) char valid;
@property (readonly) DVTStackBacktrace * invalidationBacktrace;
@property (retain) DVTStackBacktrace * creationBacktrace;
+ (void)initialize;
+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)v1;
+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
+ (id)schemeWithRunContextManager:(id)v1 customDataStoreContainer:(id)v2 customDataSpecifier:(id)v3;
+ (id)schemeFromXMLData:(id)v1 withRunContextManager:(id)v2 customDataStoreContainer:(id)v3 customDataSpecifier:(id)v4 isShown:(char)v5 orderHint:(unsigned long long)v6 error:(id *)v7;
+ (id)keyPathsForValuesAffectingRunnable;
+ (id)keyPathsForValuesAffectingProfilable;
+ (id)keyPathsForValuesAffectingAnalyzable;
+ (id)keyPathsForValuesAffectingTestable;
+ (id)keyPathsForValuesAffectingIntegratable;
+ (char)automaticallyNotifiesObserversOfCustomDataStoreContainer;
+ (id)keyPathsForValuesAffectingDisambiguatedName;
+ (char)automaticallyNotifiesObserversOfIsShown;
+ (char)automaticallyNotifiesObserversOfOrderHint;
+ (id)_buildParametersForPurpose:(long long)v1 schemeCommand:(id)v2 configurationName:(id)v3 workspaceArena:(id)v4 overridingProperties:(id)v5 activeRunDestination:(id)v6 activeArchitecture:(id)v7 collectBuildTimeStatistics:(char)v8 collectTimelineMetrics:(char)v9;
- (char)ideIndex_containsBlueprint:(id)v1;
- (id)buildDirectoriesForBuildParameters:(id)v1;
- (void)_createDefaultSchemeActions;
- (id)initFromUnarchiver:(char)v1 runContextManager:(id)v2 customDataStoreContainer:(id)v3 customDataSpecifier:(id)v4 isShown:(char)v5 orderHint:(unsigned long long)v6;
- (void)resolveBuildablesFromImport;
- (void)markSchemeDirtyFromUserChange;
- (void)markSchemeDirtyFromAutomaticChange;
- (void)performDelayedSave:(id)v1;
- (void)customDataStoreContainerClosing:(id)v1;
- (void)primitiveInvalidate;
- (char)hasRunnableForBuildableProduct:(id)v1;
- (id)schemeActionForSchemeCommand:(id)v1;
- (id)_runnableSchemeActionForSchemeCommand:(id)v1;
- (id)runnablePathForSchemeCommand:(id)v1 destination:(id)v2;
- (id)primaryBuildablesForSchemeCommand:(id)v1;
- (id)buildablesForSchemeCommand:(id)v1;
- (id)buildablesIncludingDependenciesForSchemeCommand:(id)v1;
- (id)buildConfigurationForSchemeCommand:(id)v1;
- (id)buildParametersForLaunchSchemeCommandAndBuildable:(id)v1;
- (id)buildParametersForSchemeCommand:(id)v1;
- (id)buildParametersForSchemeCommand:(id)v1 buildable:(id)v2;
- (id)buildParametersForSchemeCommand:(id)v1 destination:(id)v2;
- (void)buildConfigurationDidChange:(id)v1;
- (char)schemeRunnableRunsOnPairedProxyDevice;
- (void)immediatelyInvalidateAvailableRunDestinations;
- (void)_invalidateAvailableRunDestinations;
- (void)_actuallyInvalidateAvailableRunDestinations;
- (void)_updateCustomDataStoreContainer:(id)v1 andSpecifier:(id)v2;
- (void)_primitiveSetCustomDataStoreContainer:(id)v1;
- (void)_updateIsShown:(char)v1;
- (void)_updateOrderHint:(unsigned long long)v1;
- (id)_addActionRecordToInvocationRecord:(id)v1 shouldBuild:(char)v2 onlyBuild:(char)v3 schemeCommand:(id)v4 runDestination:(id)v5 title:(id)v6;
- (void)_reportExecutionOperationForParameters:(id)v1 shouldBuild:(char)v2 onlyBuild:(char)v3;
- (id)_cleanOperationWithExecutionContext:(id)v1 destination:(id)v2 overridingProperties:(id)v3 schemeCommand:(id)v4 invocationRecord:(id)v5 error:(id *)v6;
- (id)computeNameForCommand:(id)v1 task:(long long)v2;
- (id)schemeOperationForSchemeOperationParameters:(id)v1 buildLog:(id)v2 overridingProperties:(id)v3 overridingBuildConfiguration:(id)v4 dontActuallyRunCommands:(char)v5 restorePersistedBuildResults:(char)v6 deviceAvailableChecker:(void (^ /* unknown block signature */)(void))v7 error:(id *)v8 completionBlock:(void (^ /* unknown block signature */)(void))v9;
- (id)schemeOperationForSchemeOperationParameters:(id)v1 buildLog:(id)v2 overridingProperties:(id)v3 overridingBuildConfiguration:(id)v4 dontActuallyRunCommands:(char)v5 restorePersistedBuildResults:(char)v6 error:(id *)v7 completionBlock:(void (^ /* unknown block signature */)(void))v8;
- (id)startedOperationForSchemeOperationParameters:(id)v1 deviceAvailableChecker:(void (^ /* unknown block signature */)(void))v2 error:(id *)v3 completionBlock:(void (^ /* unknown block signature */)(void))v4;
- (id)overridingBuildSettingsForSchemeCommand:(id)v1 runDestination:(id)v2;
- (id)buildParametersForTask:(long long)v1 executionEnvironment:(id)v2 buildPurpose:(long long)v3 schemeCommand:(id)v4 destination:(id)v5 overridingProperties:(id)v6 overridingBuildConfiguration:(id)v7 overridingTestingSpecifiers:(id)v8 collectBuildTimeStatistics:(char)v9 collectTimelineMetrics:(char)v10;
- (id)_executionOperationForSchemeOperationParameters:(id)v1 build:(char)v2 onlyBuild:(char)v3 buildParameters:(id)v4 title:(id)v5 buildLog:(id)v6 dontActuallyRunCommands:(char)v7 restorePersistedBuildResults:(char)v8 deviceAvailableChecker:(void (^ /* unknown block signature */)(void))v9 error:(id *)v10 actionCallbackBlock:(void (^ /* unknown block signature */)(void))v11;
- (char)_shouldRunPostBuildActionsForBuildResult:(long long)v1;
- (void (^ /* unknown block signature */)(void))postActionEnvironmentPopulatorForBuildOperation:(id)v1;
- (id)_cleanOperationGroupForExecutionEnvironment:(id)v1 orderedBuildables:(id)v2 buildConfiguration:(id)v3 buildLog:(id)v4 overridingProperties:(id)v5 activeRunDestination:(id)v6 schemeActionRecord:(id)v7 error:(id *)v8;
- (id)_buildOperationGroupForSchemeOperationParameters:(id)v1 buildParameters:(id)v2 buildLog:(id)v3 dontActuallyRunCommands:(char)v4 restorePersistedBuildResults:(char)v5 schemeActionRecord:(id)v6 error:(id *)v7;
- (id)_groupAndImposeDependenciesForOrderedOperations:(id)v1;
- (void)dvt_awakeFromXMLUnarchiver:(id)v1;
- (char)_executionActionsNeedCurrentArchiveVersion;
- (void)dvt_encodeAttributesWithXMLArchiver:(id)v1 version:(id)v2;
- (void)dvt_encodeRelationshipsWithXMLArchiver:(id)v1 version:(id)v2;
- (void)setLastUpgradeVersionFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)setWasCreatedForAppExtensionFromUTF8String:(char *)v1 fromXMLUnarchiver:(id)v2;
- (void)addBuildAction:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addTestAction:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addLaunchAction:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addProfileAction:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addAnalyzeAction:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addIntegrateAction:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addInstallAction:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addArchiveAction:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addBuildPhase:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addTestPhase:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addLaunchPhase:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addPathRunnable:(id)v1 fromXMLUnarchiver:(id)v2;
- (void)addBuildableProductRunnable:(id)v1 fromXMLUnarchiver:(id)v2;

@end


NS_ASSUME_NONNULL_END
