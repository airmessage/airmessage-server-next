//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Jun  9 2015 22:53:21).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <objc/NSObject.h>

@interface IMMessageAcknowledgmentStringHelper : NSObject
{
}

+ (id)generateBackwardCompatibilityStringForMessageAcknowledgmentType:(long long)arg1 messageSummaryInfo:(id)arg2;
+ (id)generateBackwardCompatibilityStringForMessageAcknowledgmentType:(long long)arg1 messageSummaryInfo:(id)arg2 isGroupMessage:(BOOL)arg3;
+ (id)generateBackwardCompatibilityFormatStringForMessageAcknowledgmentType:(long long)arg1 messageSummaryInfo:(id)arg2 format:(long long *)arg3;
+ (id)generatePreviewStringForMessageAcknowledgmentType:(long long)arg1 acknowledgmentSenderAddress:(id)arg2 messageSummaryInfo:(id)arg3;
+ (id)generatePreviewStringForMessageAcknowledgmentType:(long long)arg1 acknowledgmentSenderAddress:(id)arg2 messageSummaryInfo:(id)arg3 isGroupMessage:(BOOL)arg4;
+ (id)generateFormatStringForMessageAcknowledgmentType:(long long)arg1 acknowledgmentSenderAddress:(id)arg2 messageSummaryInfo:(id)arg3 format:(long long *)arg4;
+ (id)displayNameForAddress:(id)arg1;
+ (BOOL)isLoginAddress:(id)arg1;
+ (id)handleForAddress:(id)arg1;
+ (id)bestAccountForAddress:(id)arg1;
+ (id)longContentTypeStringForContentType:(id)arg1;
+ (id)longContentTypeStringForPluginBundleID:(id)arg1 pluginDisplayName:(id)arg2;
+ (BOOL)shouldQuoteContentString:(id)arg1;
+ (id)messageAcknowledgmentString:(long long)arg1 lowercase:(BOOL)arg2;

@end
