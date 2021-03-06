//
//  VLTOperation.m
//  VelocitySDK
//
//
//  Copyright © 2017 VLCTY, Inc. All rights reserved.
//

#import "VLTOperation.h"
#import "VLTMacros.h"
#import "Velocity.pbobjc.h"

@interface VLTOperation ()

@property (atomic, assign, getter=isOperationExecuting) BOOL operationExecuting;
@property (atomic, assign, getter=isOperationFinished) BOOL operationFinished;

@end

@implementation VLTOperation

- (void)markAsExecuting
{
    [self willChangeValueForKey:NSStringFromSelector(@selector(isExecuting))];
    self.operationExecuting = YES;
    [self didChangeValueForKey:NSStringFromSelector(@selector(isExecuting))];
}

- (void)markAsFinished
{
    [self willChangeValueForKey:NSStringFromSelector(@selector(isExecuting))];
    [self willChangeValueForKey:NSStringFromSelector(@selector(isFinished))];
    self.operationExecuting = NO;
    self.operationFinished  = YES;
    [self didChangeValueForKey:NSStringFromSelector(@selector(isExecuting))];
    [self didChangeValueForKey:NSStringFromSelector(@selector(isFinished))];
}

- (BOOL)isExecuting
{
    return self.isOperationExecuting;
}

- (BOOL)isFinished
{
    return self.isOperationFinished;
}

@end
