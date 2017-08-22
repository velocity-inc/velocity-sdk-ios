//
//  VLTClient.h
//  VelocitySDK
//
//  Created by Vytautas Galaunia on 17/08/2017.
//  Copyright © 2017 Veloctity. All rights reserved.
//

#import <Foundation/Foundation.h>

@class VLTMotionDataOperation;
@class VLTData;

typedef  NSArray<VLTMotionDataOperation *> * _Nonnull (^MotionDataOperationsFactory)(NSArray<VLTData *> * _Nonnull motionData, UInt32 sequenceIndex);

@interface VLTClient : NSObject

@property (atomic, assign, getter=isActive) BOOL active;

@property (atomic, copy, nullable) MotionDataOperationsFactory operationFatoryHandler;


/**  
 * @property errorHandler
 * @brief Block is invoked when error occurs
 * In case of error occurance, active right away is set to false
 **/
@property (atomic, copy, nullable) void(^errorHandler)(NSError * _Nullable);

/**
 * @brief Sends at max last 5min of recorded data with given labels
 * @param labels array of strings with labels for recent motion
 * @param success block, which is invoked if upload succeed
 * @param failure dblock, which is invoked if upload fails
 **/
- (void)pushMotionDataWithLabels:(nonnull NSArray<NSString *> *)labels
                         success:(nullable void(^)())success
                         failure:(nullable void(^)(NSError * _Nullable error))failure;

@end