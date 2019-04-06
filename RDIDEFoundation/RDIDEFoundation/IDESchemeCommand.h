//
//  IDESchemeCommand.h
//  IDEFoundation
//
//  Created by Roman Dzieciol on 4/5/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDIDEFoundation/RDIDEFoundationDecls.h>

NS_ASSUME_NONNULL_BEGIN

/*
 UserDefaults
 NoCodeCoverageArena: Bool

 */

@interface IDESchemeCommand : NSObject {
    char _appleInternalOnly;
    char _shouldLaunch;
    char _shouldTest;
    char _shouldProfile;
    char _shouldArchive;
    char _shouldInstall;
    char _shouldBuildThinnedResources;
    char _shouldGenerateOptimizationProfile;
    char _supportsCodeCoverage;
    char _supportsSingleFileProcessing;
    char _supportsCompilerSanitizers;
    NSString * _commandName;
    NSString * _commandNameGerund;
}
@property (readonly,copy,nonatomic) NSString * commandName;
@property (readonly,copy,nonatomic) NSString * commandNameGerund;
@property (readonly,nonatomic,getter=isAppleInternalOnly) char appleInternalOnly;
@property (readonly,nonatomic) char shouldLaunch;
@property (readonly,nonatomic) char shouldTest;
@property (readonly,nonatomic) char shouldProfile;
@property (readonly,nonatomic) char shouldArchive;
@property (readonly,nonatomic) char shouldInstall;
@property (readonly,nonatomic) char shouldBuildThinnedResources;
@property (readonly,nonatomic) char shouldGenerateOptimizationProfile;
@property (readonly,nonatomic) char supportsCodeCoverage;
@property (readonly,nonatomic) char supportsSingleFileProcessing;
@property (readonly,nonatomic) char supportsCompilerSanitizers;
+ (void)initialize;
+ (id)launchSchemeCommand;
+ (id)testSchemeCommand;
+ (id)profileSchemeCommand;
+ (id)archiveSchemeCommand;
+ (id)analyzeSchemeCommand;
+ (id)launchForPGOSchemeCommand;
+ (id)testForPGOSchemeCommand;
+ (id)installSchemeCommand;
+ (id)allSchemeCommands;
+ (id)allNonAppleInternalSchemeCommands;
+ (id)availableSchemeCommands;
+ (id)allPrimitiveSchemeCommands;
+ (id)allNonAppleInternalPrimitiveSchemeCommands;
+ (id)availablePrimitiveSchemeCommands;
- (id)init;
- (id)initWithCommandName:(id)v1 gerund:(id)v2 appleInternalOnly:(char)v3;
- (id)description;
//- (void).cxx_destruct;
@end

NS_ASSUME_NONNULL_END
