//
//  DVTFileSystemRepresentationProviding.h
//  DVTFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#ifndef DVTFileSystemRepresentationProviding_h
#define DVTFileSystemRepresentationProviding_h
#import <RDDVTFoundation/RDDVTFoundationDecls.h>

@protocol DVTFileSystemRepresentationProviding
- (void)dvt_provideFileSystemRepresentationToBlock:(void (^ /* unknown block signature */)(void))v1;
@end


#endif /* DVTFileSystemRepresentationProviding_h */
