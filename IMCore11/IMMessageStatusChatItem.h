//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Jun  9 2015 22:53:21).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <IMCore/IMTranscriptChatItem.h>

@class NSDate, NSString;

@interface IMMessageStatusChatItem : IMTranscriptChatItem
{
    long long _statusType;
    NSDate *_time;
    long long _expireStatusType;
    NSDate *_timeAdded;
    NSDate *_timeStale;
    unsigned long long _count;
}

@property(readonly, nonatomic) unsigned long long count; // @synthesize count=_count;
@property(readonly, nonatomic) long long expireStatusType; // @synthesize expireStatusType=_expireStatusType;
@property(readonly, nonatomic) NSDate *time; // @synthesize time=_time;
@property(readonly, nonatomic) long long statusType; // @synthesize statusType=_statusType;
- (void).cxx_destruct;
- (id)_initWithItem:(id)arg1 statusType:(long long)arg2 time:(id)arg3 count:(unsigned long long)arg4 expireStatusType:(long long)arg5;
- (id)_initWithItem:(id)arg1 expireStatusType:(long long)arg2 count:(unsigned long long)arg3;
- (id)_initWithItem:(id)arg1 statusType:(long long)arg2 time:(id)arg3 count:(unsigned long long)arg4;
@property(readonly, nonatomic) long long messageStatusType;
@property(readonly, nonatomic) NSString *errorText;
@property(readonly, nonatomic) BOOL isFromMe;
- (void)_setTimeAdded:(id)arg1;
- (id)_timeAdded;
- (id)_timeStale;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)description;

@end
