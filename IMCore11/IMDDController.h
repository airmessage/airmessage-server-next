//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Jun  9 2015 22:53:21).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <objc/NSObject.h>

@protocol OS_dispatch_queue;

@interface IMDDController : NSObject
{
    NSObject<OS_dispatch_queue> *_scannerQueue;
}

+ (id)sharedInstance;
- (void).cxx_destruct;
- (void)scanMessage:(id)arg1 waitUntilDone:(BOOL)arg2 completionBlock:(id)arg3;
- (BOOL)_scanMessageUsingScanner:(id)arg1 attributedString:(id)arg2;
- (void)scanMessage:(id)arg1 completionBlock:(id)arg2;
- (id)scannerQueue;
- (struct __DDScanner *)sharedScanner;
- (id)init;

@end
