//
//  KVAEntitlements.h
//  KochavaEntitlements
//
//  Created by John Bushnell on 12/11/19.
//  Copyright © 2020 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAEntitlements_h
#define KVAEntitlements_h



#pragma mark - IMPORT



#pragma mark System
#if TARGET_OS_TV
#import <JavaScriptCore/JavaScriptCore.h>
#endif

#pragma mark KochavaCore
#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAConfigureWithObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#import "KVASharedPropertyProvider.h"
#endif

#pragma mark KochavaEntitlements
#ifdef KOCHAVA_FRAMEWORK
#import <KochavaEntitlements/KochavaEntitlements.h>
#else
#import "KVAReceipt.h"  // for KVAEntitlementsReceiptReporterProvider.
#endif



#pragma mark - DEFINE



#if KVA_REVEAL_TARGET == 1
#define KOCHAVA_DEPRECATED(MSG) /*__attribute__((deprecated(MSG)))*/
#else
#define KOCHAVA_DEPRECATED(MSG) __attribute__((deprecated(MSG)))
#endif



#pragma mark - public class KVAEntitlements



/*!
 @class KVAEntitlements
 
 @brief The class KVAEntitlements provides an interface between a host application and Kochava’s Attribution and Analytics Servers.  A entitlements manages the exchange of data between these two entities, along with the associated tasks and network transactions.

 @discussion The class KVAEntitlements is the main interface for the KochavaEntitlements SDK.  If you have not already integrated a KochavaEntitlements SDK into your project, refer to our KochavaEntitlements iOS SDK support documentation.
 
 You do not create instances of the KVAEntitlements class.  Instead, you start a provided shared instance using the designated configuration instance method start(withParametersDictionary:delegate:).
 
 From there, the entitlements instance proceeds to initialize immediately and perform its various tasks.  This is typically done during the earliest phases of the host’s life-cycle, so that installation attribution can be quickly established and post-install events may immediately begin to be queued.
 
 @author Kochava, Inc.
 
 @copyright 2020 - 2021 Kochava, Inc.
 */
@interface KVAEntitlements : NSObject



@end



#pragma mark - feature General



#if TARGET_OS_TV
@protocol KVAEntitlementsGeneralJSExport <JSExport>
@property (class, readonly, strong, nonnull) KVAEntitlements *shared;
@property (readonly) BOOL startedBool;
- (void)registerIdentityWithNameString:
    (nonnull NSString *)nameString
    valueString: (nonnull NSString *)valueString
    NS_SWIFT_NAME(registerIdentity(withNameString:valueString:));
- (void)unregisterIdentityWithNameString:(nonnull NSString *)nameString
    NS_SWIFT_NAME(unregisterIdentity(withNameString:));
- (void)start;
- (void)invalidate;
@end
#endif



#if TARGET_OS_TV
@interface KVAEntitlements (General_Public) <KVAAsForContextObjectProtocol, KVAConfigureWithObjectProtocol, KVAFromObjectProtocol, KVASharedPropertyProvider, KVAEntitlementsGeneralJSExport>
#else
@interface KVAEntitlements (General_Public) <KVAAsForContextObjectProtocol, KVAConfigureWithObjectProtocol, KVAFromObjectProtocol, KVASharedPropertyProvider>
#endif



/*!
 @property shared
 
 @brief A shared instance, for convenience.
 
 @discussion This is the preferred way of using a entitlements.  To complete the integration you must call func start.
 */
@property (class, readonly, strong, nonnull) KVAEntitlements *shared;



/*!
 @property startedBool

 @brief A boolean indicating if the instance has been started.
 */
@property (readonly) BOOL startedBool;



/*!
 @method - registerIdentity(withNameString:valueString:)
 
 @brief Registers an identity.
 
 @param nameString The name of the type of identifier.
 
 @param valueString The id value.
 */
- (void)registerIdentityWithNameString:
    (nonnull NSString *)nameString
    valueString: (nonnull NSString *)valueString
    NS_SWIFT_NAME(registerIdentity(withNameString:valueString:));



/*!
 @method - unregisterIdentity(withNameString:)

 @brief Unregisters a previously registered identity.

 @discussion It is safe to use this method with a nameString which may ultimately not be registered.  No warning will be generated.
 
 @param nameString The name of the type of identifier.
 */
- (void)unregisterIdentityWithNameString:(nonnull NSString *)nameString
    NS_SWIFT_NAME(unregisterIdentity(withNameString:));



/*!
 @method - start
 
 @brief The main start method for use with the shared instance.  This method starts the entitlements.
 
 @discussion  By calling the KVAEntitlements start method, you have completed the basic integration with the KochavaEntitlements SDK.  The call to the configuration method should be located in the logic of your application where things first start up, such as your App Delegate's application:didFinishLaunchingWithOptions: method.

 Swift example:
 @code
 KVAEntitlements.shared.start()
 @endcode
 */
- (void)start;



/*!
 @method - invalidate
 
 @brief Invalidates an instance of class KVAEntitlements.
 
 @discussion This is similar to allowing an instance of entitlements deallocate, but it can also be used on the shared instance.  It will additionally signal certain sub-systems to invalidate themselves, which can result in a more assured and immediate halt.  The scope of this invalidation is not absolute.  Certain sub-systems will continue to run for a period of time until they may gracefully complete.  When using this method with the shared instance, you are guaranteed to be re-defaulted a new instance the next time it is referenced, and you may immediately move forward to re-configure it.
 */
- (void)invalidate;



/*!
 @method - configureWith:context:
 
 @brief Configures (updates) the instance from another object.
 
 @param withObject An object from which to update the instance.  This is expected to be a JSON dictionary, or alternatively a native instance.
 
 @param context The context.
 
 @discussion This method can be used to make special configurations to the instance.  This method is equivalent to the support provided by KVAConfigureWithObjectProtocol;  however, it is formalized with a dispatch to the Kochava SDK's globalSerial queue and a log message.
 */
- (void)configureWith:
    (nullable id)withObject
    context: (nullable KVAContext *)context
    NS_SWIFT_NAME(configure(with:context:));



@end



#pragma mark - feature Reporting



@protocol KVAEntitlementsReceiptReporterProvider;



#if TARGET_OS_TV
@interface KVAEntitlements (Reporting_Public) <KVAEntitlementsReceiptReporterProvider>
#else
@interface KVAEntitlements (Reporting_Public) <KVAEntitlementsReceiptReporterProvider>
#endif



/*!
 @property reporting
 
 @brief An instance of class KVAEntitlementsReporting which conforms to protocol KVAEntitlementsReceiptReporterProvider.
 */
@property (strong, nonatomic, nonnull, readonly) NSObject<KVAEntitlementsReceiptReporter> *reporting;



@end



#endif



