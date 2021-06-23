//
//  KVAReceipt.h
//  KochavaEntitlements
//
//  Created by John Bushnell on 12/11/19.
//  Copyright © 2020 - 2021 Kochava, Inc. All rights reserved.
//



#ifndef KVAReceipt_h
#define KVAReceipt_h



#pragma mark - IMPORT



#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - CLASS



@class KVAReceipt;



#pragma mark - PROTOCOL



@protocol KVAEntitlementsReceiptReporter <NSObject>



/*!
 @method - reportReceipt:
 
 @brief Reports a receipt.
 */
- (void)reportReceipt:(nonnull KVAReceipt *)receipt NS_SWIFT_NAME(reportReceipt(_:));



@end



@protocol KVAEntitlementsReceiptReporterProvider <NSObject>

@property (strong, nonatomic, nonnull, readonly) id<KVAEntitlementsReceiptReporter> reporting;

@end



#pragma mark - INTERFACE



/*!
 @class KVAReceipt
 
 @brief A push notifications token.
 
 @author John Bushnell
 
 @copyright 2017 - 2021 Kochava, Inc.
 */
@interface KVAReceipt : NSObject <KVAAsForContextObjectProtocol, KVAFromObjectProtocol>



#pragma mark - CLASS GENERAL



/*!
 @method + report
 
 @brief A method which reports the current receipt.
 */
+ (void)report NS_SWIFT_NAME(report());



/*!
 @method + reportWithPriceDecimalNumber:currencyString:

 @brief A method which reports a receipt, along with an associated transaction's details.
 
 @param priceDecimalNumber The price of an associated transaction.  Optional.
 
 @param currencyString The currency code of an associated transaction.  Optional.
 */
+ (void)reportWithPriceDecimalNumber:(nullable NSDecimalNumber *)priceDecimalNumber currencyString:(nullable NSString *)currencyString NS_SWIFT_NAME(report(withPriceDecimalNumber:currencyString:));



@end



#endif



