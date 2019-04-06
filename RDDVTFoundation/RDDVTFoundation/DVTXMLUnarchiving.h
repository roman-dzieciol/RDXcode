//
//  DVTXMLUnarchiving.h
//  RDDVTFoundation
//
//  Created by Roman Dzieciol on 4/6/19.
//  Copyright © 2019 Roman Dzieciol. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DVTXMLUnarchiving<NSObject>
- (id)initFromXMLUnarchiver:(id)v1 archiveVersion:(float)v2;
@end

NS_ASSUME_NONNULL_END
