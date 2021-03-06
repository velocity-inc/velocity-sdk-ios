//
//  VLTWsApiClient.h
//  VelocitySDK iOS
//
//
//  Copyright © 2017 VLCTY, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class VLTPBHandshakeResponse;
@class VLTPBRequest;
@class VLTPBResponse;

typedef void (^VLTWsApiHandshakeSuccess)(VLTPBHandshakeResponse *_Nonnull response);
typedef void (^VLTWsApiRequestSuccess)(VLTPBResponse *_Nonnull response);
typedef void (^VLTWsApiSuccess)(NSData *_Nonnull data);
typedef void (^VLTWsApiFailure)(NSError *_Nonnull error);

typedef void (^VLTWsApiOnOpen)(void);
typedef void (^VLTWsApiOnClose)(NSInteger code, NSString *_Nonnull reason);
typedef void (^VLTWsApiOnPong)(NSData *_Nullable pongPayload);
typedef void (^VLTWsApiOnError)(NSError *_Nonnull error);

@interface VLTWsApiClient : NSObject

@property (copy, readonly, nullable) NSString *authToken;

@property (atomic, copy, nullable) VLTWsApiOnOpen onOpen;
@property (atomic, copy, nullable) VLTWsApiOnPong onPong;
@property (atomic, copy, nullable) VLTWsApiOnError onError;

@property (nonatomic, assign, readonly, getter=isOpen) BOOL open;

- (nonnull instancetype)initWithQueueSize:(NSUInteger)queueSize;

- (void)openWithAuthToken:(nonnull NSString *)authToken;
- (void)close;

- (NSUInteger)handshakeWithSuccess:(nonnull VLTWsApiHandshakeSuccess)success failure:(nonnull VLTWsApiFailure)failure;

- (NSUInteger)motionDetect:(nonnull VLTPBRequest *)request
                   success:(nonnull VLTWsApiRequestSuccess)success
                   failure:(nonnull VLTWsApiFailure)failure;

- (NSUInteger)captureUpload:(nonnull VLTPBRequest *)request
                    success:(nonnull VLTWsApiRequestSuccess)success
                    failure:(nonnull VLTWsApiFailure)failure;

@end
