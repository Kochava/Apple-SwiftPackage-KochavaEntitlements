//
//  KochavaEntitlements.h
//  KochavaEntitlements
//
//  Created by John Bushnell on 6/15/20.
//  Copyright © 2020 - 2022 Kochava, Inc.  All rights reserved.
//



#ifndef KochavaEntitlements_h
#define KochavaEntitlements_h



#pragma mark - DEFINE



#define KOCHAVA_FRAMEWORK



#pragma mark - IMPORT



#pragma mark System
#import <Foundation/Foundation.h>

#pragma mark KochavaCore
@import KochavaCore;

#pragma mark KochavaEntitlements
#import <KochavaEntitlements/KVAReceipt.h>
#import <KochavaEntitlements/KVAEntitlements.h>
#import <KochavaEntitlements/KVAEntitlementsProduct.h>



#pragma mark - EXPORT



//! Project version number for KochavaEntitlements.
FOUNDATION_EXPORT double KochavaEntitlementsVersionNumber;

//! Project version string for KochavaEntitlements.
FOUNDATION_EXPORT const unsigned char KochavaEntitlementsVersionString[];



#endif



