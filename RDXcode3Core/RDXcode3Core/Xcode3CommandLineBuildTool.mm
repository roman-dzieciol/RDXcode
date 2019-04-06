//
//  Xcode3CommandLineBuildTool.m
//  Xcode3Core
//
//  Created by Roman Dzieciol on 4/5/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import "Xcode3CommandLineBuildTool.h"

typedef enum : NSUInteger {
    Xcode3CommandLineBuildToolTask_0,
    Xcode3CommandLineBuildToolTask_1,
    Xcode3CommandLineBuildToolTask_2,
    Xcode3CommandLineBuildToolTask_3,
    Xcode3CommandLineBuildToolTask_4,
    Xcode3CommandLineBuildToolTask_5,

} Xcode3CommandLineBuildToolTask;

@implementation Xcode3CommandLineBuildTool


-(IDESchemeCommand*)_schemeCommandForBuildAction:(NSString *)action outSchemeTask:(NSInteger *)task {

    if ([action isEqualToString:@"clean"]) {
        if (task != nil) {
            *task = Xcode3CommandLineBuildToolTask_5;
        }
    }
    else if ([action isEqualToString:@"build"]) {
        if (task != nil) {
            *task = Xcode3CommandLineBuildToolTask_2;
        }
    }
    else if ([action isEqualToString:@"migrateswift"]) {
        if (task != nil) {
            *task = Xcode3CommandLineBuildToolTask_2;
        }
        id testSchemeAction = [self.workspace.runContextManager.activeRunContext testSchemeAction];
        if ([testSchemeAction isTestable]) {
            return [IDESchemeCommand testSchemeCommand];
        }
    } else {
        if (task != nil) {
            *task = Xcode3CommandLineBuildToolTask_0;
        }

        if ([action isEqualToString:@"analyze"]) {
            return [IDESchemeCommand analyzeSchemeCommand];
        }
        else if ([action isEqualToString:@"test"] ||
                 [action isEqualToString:@"build-for-testing"] ||
                 [action isEqualToString:@"test-without-building"]) {
            return [IDESchemeCommand testSchemeCommand];
        }
        else if ([action isEqualToString:@"archive"]) {
            return [IDESchemeCommand archiveSchemeCommand];
        }
        else if ([action isEqualToString:@"copysrc"] ||
                 [action isEqualToString:@"copyhdrs"] ||
                 [action isEqualToString:@"copyrsrcs"]) {
        }
        else {
            if ([action isEqualToString:@"install"] ||
                [action isEqualToString:@"installdebugonly"] ||
                [action isEqualToString:@"installprofileonly"] ||
                [action isEqualToString:@"installdebugprofileonly"] ||
                [action isEqualToString:@"installsrc"] ||
                [action isEqualToString:@"installhdrs"]) {

            } else if ([action isEqualToString:@"installloc"] && [Xcode3CommandLineBuildTool enableInstallLocAction]) {

            } else if ([action isEqualToString:@"installapi"] ||
                       [action isEqualToString:@"installrsrcs"]) {
            }
            else {
                _DVTAssertionFailureHandler
                (self,
                 _cmd,
                 __PRETTY_FUNCTION__,
                 __FILE__,
                 0x2ce,
                 @"0",
                 @"Unexpected build action '%@'. If this is a supported build action, it should be handled by this method.",
                 action);
            }

            if ([Xcode3CommandLineBuildTool useArchiveActionForInstall]) {
                return [IDESchemeCommand archiveSchemeCommand];
            }
        }
    }
    return [IDESchemeCommand launchSchemeCommand];
}


@end

