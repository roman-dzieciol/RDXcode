//
//  DVTInvalidation.h
//  RDDVTFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RDDVTFoundation/RDDVTFoundationDecls.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DVTInvalidation<NSObject>
@property (readonly,nonatomic,getter=isValid) char valid;
@property (readonly) DVTStackBacktrace * invalidationBacktrace;
@property (retain) DVTStackBacktrace * creationBacktrace;
- (void)primitiveInvalidate;

@optional
+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)v1;
+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
+ (char)supportsInvalidationPrevention;
- (void)invalidate;
- (char)isValid;
- (id)invalidationBacktrace;
- (DVTStackBacktrace*)creationBacktrace;
- (void)setCreationBacktrace:(DVTStackBacktrace*)v1;
@end

NS_ASSUME_NONNULL_END
