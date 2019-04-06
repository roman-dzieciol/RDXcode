//
//  IDECodeCoverageTargetProviding.h
//  RDIDEFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDIDEFoundation/RDIDEFoundationDecls.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IDECodeCoverageTargetProviding
@property (nonatomic) char codeCoverageEnabled;
@property (nonatomic) char onlyGenerateCoverageForSpecifiedTargets;
@property (readonly,nonatomic) NSArray * codeCoverageTargets;
- (void)addCodeCoverageTarget:(id)v1;
- (void)removeCodeCoverageTarget:(id)v1;
- (id)coverageBuildableInfosForBuildParameters:(id)v1;
- (char)codeCoverageEnabled;
- (void)setCodeCoverageEnabled:(char)v1;
- (char)onlyGenerateCoverageForSpecifiedTargets;
- (void)setOnlyGenerateCoverageForSpecifiedTargets:(char)v1;
- (id)codeCoverageTargets;
@end

NS_ASSUME_NONNULL_END
