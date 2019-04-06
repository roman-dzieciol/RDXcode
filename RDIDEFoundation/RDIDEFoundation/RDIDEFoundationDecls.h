//
//  RDIDEFoundationDecls.h
//  IDEFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDDVTFoundation/RDDVTFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NSEvent;



@class IDEFileReference;
@class IDESchemeBuildableReference;
@class IDESchemeOrderedWorkspaceNotificationManager;
@class IDEEntityIdentifier;
@class IDERunnable;
@class IDEBuildSchemeAction;
@class IDETestSchemeAction;
@class IDELaunchSchemeAction;
@class IDEArchiveSchemeAction;
@class IDEProfileSchemeAction;
@class IDEAnalyzeSchemeAction;
@class IDEInstallSchemeAction;
@class IDEIntegrateSchemeAction;
@class IDERunDestination;
@class IDEScheme;
@class IDEWorkspace;
@class DVTFilePath;
@class DVTNotificationToken;
@class DVTObservingToken;
@class DVTStackBacktrace;
@class DVTTimeSlicedMainThreadWorkQueue;
@class IDEActivityLogMessage;
@class IDEActivityLogSection;
@class IDEBreakpointManager;
@class IDEConcreteClientTracker;
@class IDEContainer;
@class IDEContainerQuery;
@class IDEDeviceInstallWorkspaceMonitor;
@class IDEDynamicContentRootGroup;
@class IDEExecutionEnvironment;
@class IDEIndex;
@class IDEIssueManager;
@class IDELocalizationManager;
@class IDELogManager;
@class IDEProvisioningManager;
@class IDEProvisioningWorkspaceMonitor;
@class IDERefactoring;
@class IDERunContextManager;
@class IDESourceControlWorkspaceMonitor;
@class IDETestManager;
@class IDETextFragmentIndex;
@class IDEWorkspaceArena;
@class IDEWorkspaceSharedSettings;
@class IDEWorkspaceUpgradeTasksController;
@class IDEWorkspaceUserSettings;
@class _TtC13IDEFoundation30IDEStructureEditingCoordinator;
@class IDEXBSBuildParameters;
@class _TtC13IDEFoundation31IDEActivityLogEventStreamWriter;
@protocol IDEXBSXcodebuildSupportProvider;

@protocol DVTInvalidation;
@protocol IDEActiveRunContextStoring;
@protocol IDEBuildSystemServiceProvider;
@protocol IDECustomDataStoring;
@protocol IDEWorkspaceDelegate;

NS_ASSUME_NONNULL_END
