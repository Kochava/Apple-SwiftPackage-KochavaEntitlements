//
//  KVAEntitlementsProduct.h
//  KochavaEntitlements
//
//  Created by John Bushnell on 12/11/19.
//  Copyright © 2019 - 2022 Kochava, Inc.  All rights reserved.
//



#ifndef KVAEntitlementsProduct_h
#define KVAEntitlementsProduct_h



#pragma mark - IMPORT



#pragma mark KochavaCore
@import KochavaCore;



#pragma mark - INTERFACE



/*!
 @class KVAEntitlementsProduct
 
 @brief A class which defines a entitlements product.
 
 @discussion A product in this context generally refers to the result of a build.
 */
@interface KVAEntitlementsProduct : NSObject



#pragma mark - 1️⃣ Getting the Shared Entitlements Product



/*!
 @property shared
 
 @brief The singleton shared instance.
 */
@property (class, readonly, strong, nonnull) KVAProduct *shared;



@end



#pragma mark - INTERFACE EXTENSION (KVASharedPropertyProtocol)



@interface KVAEntitlementsProduct (KVASharedPropertyProtocol) <KVASharedPropertyProvider>

@end



#endif



