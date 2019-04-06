//
//  IDERunContextManager.h
//  IDEFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDIDEFoundation/RDIDEFoundationDecls.h>

NS_ASSUME_NONNULL_BEGIN

@interface IDERunContextManager : NSObject<DVTInvalidation>  {
    IDEWorkspace * _workspace;
    NSMutableSet * _customDataStores;
    NSMapTable * _storeToSpecifierMap;
    NSMapTable * _storeToUserDataMap;
    NSMutableArray * _runContexts;
    IDEScheme * _activeRunContext;
    IDERunDestination * _activeRunDestination;
    NSMutableArray * _ignoredChangesDevices;
    NSCountedSet * _schemeNameCounts;
    NSEvent * _schemeForcedSwitchEvent;
    char _bulkChangingBlueprints;
    char _blueprintChangedDuringBulkChanges;
    char _suppressingAutocreation;
    DVTObservingToken * _customDataStoresObserver;
    DVTObservingToken * _availableDevicesObserver;
    NSObject<DVTInvalidation> * _blueprintDidChangeObserver;
}
@property (readonly) NSCountedSet * schemeNameCounts;
@property (readonly) IDEWorkspace * workspace;
@property (readonly) NSMutableArray * runContexts;
@property (retain,nonatomic) IDEScheme * activeRunContext;
@property (retain,nonatomic) IDERunDestination * activeRunDestination;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
@property (readonly,nonatomic,getter=isValid) char valid;
@property (readonly) DVTStackBacktrace * invalidationBacktrace;
@property (retain) DVTStackBacktrace * creationBacktrace;
+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
+ (void)initialize;
+ (char)automaticallyNotifiesObserversOfActiveRunContext;
+ (char)automaticallyNotifiesObserversOfActiveRunDestination;
+ (id)observeAllBlueprintChangesOnQueue:(id)v1 withBlock:(void (^ /* unknown block signature */)(void))v2;
+ (id)observeAllBlueprintChangesOnQueue:(id)v1 withTarget:(id)v2 selector:(SEL)v3;
+ (void)postBlueprintsDidChange:(id)v1;
- (id)init;
- (id)initWithWorkspace:(id)v1;
- (void)primitiveInvalidate;
- (void)_addScheme:(id)v1;
- (void)_updateMap:(id)v1 contextForCustomDataStore:(id)v2 specifier:(id)v3;
- (void)_restoreActiveRunContextIfPossible;
- (void)_restoreActiveRunDestinationIfPossibleForScheme:(id)v1;
- (void)_ensureActiveRunContext;
- (void)_startUpdatingRunContexts;
- (void)_finishUpdatingRunContexts;
- (void)_customDataStoresDidUpdate;
- (id)_schemesInvolvingBuildables:(id)v1 excludingContexts:(id)v2;
- (void)suppressAutocreationForBuildables:(id)v1;
- (void)allowAutocreationForBuildables:(id)v1;
- (void)_setAutocreationSuppressed:(char)v1 forBuildables:(id)v2;
- (void)_setAutocreationSuppressed:(char)v1 forBuildables:(id)v2 returningStoresNeedingSave:(id *)v3;
- (id)_uniqueSpecifierForSpecifier:(id)v1 inMap:(id)v2;
- (void)_addContext:(id)v1 specifierToRunContextMap:(id)v2;
- (id)_newSchemeWithCustomDataStore:(id)v1 customDataSpecifier:(id)v2 orderHint:(unsigned long long)v3 schemeCreationBlock:(void (^ /* unknown block signature */)(void))v4;
- (id)newSchemeWithCustomDataStore:(id)v1 customDataSpecifier:(id)v2 orderHint:(unsigned long long)v3;
- (id)newTransientSchemeWithCustomDataStore:(id)v1 customDataSpecifier:(id)v2 orderHint:(unsigned long long)v3;
- (id)duplicateRunContext:(id)v1 withCustomDataSpecifier:(id)v2 completionQueue:(id)v3 completionBlock:(void (^ /* unknown block signature */)(void))v4;
- (id)importRunContextAtURL:(id)v1 withCustomDataStore:(id)v2 customDataSpecifier:(id)v3 orderHint:(unsigned long long)v4 completionQueue:(id)v5 completionBlock:(void (^ /* unknown block signature */)(void))v6;
- (void)deleteRunContexts:(id)v1 completionQueue:(id)v2 completionBlock:(void (^ /* unknown block signature */)(void))v3;
- (void)moveRunContext:(id)v1 toCustomDataStore:(id)v2 customDataSpecifier:(id)v3 completionQueue:(id)v4 completionBlock:(void (^ /* unknown block signature */)(void))v5;
- (id)_contextUserStateKeyForSpecifier:(id)v1;
- (id)_contextUserStateDictForCustomDataStore:(id)v1 createIfNeeded:(char)v2;
- (id)_contextUserStateForCustomDataStore:(id)v1 specifier:(id)v2 createIfNeeded:(char)v3;
- (void)_lookupIsShown:(char *)v1 orderHint:(unsigned long long *)v2 forCustomDataStore:(id)v3 specifier:(id)v4;
- (void)saveRunContextManagementDictionaryForStore:(id)v1;
- (id)runContextManagementDictionaryForStore:(id)v1;
- (void)_updateIsShown:(char)v1 forRunContext:(id)v2;
- (void)_updateOrderHint:(unsigned long long)v1 forRunContext:(id)v2;
- (void)shouldIgnoreDeviceChangesWillBegin:(id)v1;
- (void)shouldIgnoreDeviceChangesDidEnd:(id)v1;
- (void)_invalidateActiveRunDestination;
- (void)_invalidateActiveRunDestinationDueToDeviceAvailable:(id)v1;
- (void)_invalidateAvailableRunDestinationsForSchemes:(id)v1;
- (void)_invalidateAvailableRunDestinations;
- (id)_preferredDestinationForRunDestination:(id)v1 inDestinations:(id)v2;
- (void)deviceUsabilityDidChange:(id)v1;
- (void)blueprintsDidChange:(id)v1;
- (void)blueprintsWillBulkChange:(id)v1;
- (void)blueprintsDidBulkChange:(id)v1;
- (void)setActiveRunContext:(id)v1 andRunDestination:(id)v2;
//- (void).cxx_destruct;

@end

NS_ASSUME_NONNULL_END
