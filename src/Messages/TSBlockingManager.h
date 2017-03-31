//
//  Copyright (c) 2017 Open Whisper Systems. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@class TSStorageManager;
@class OWSMessageSender;

extern NSString * const kNSNotificationName_BlockedPhoneNumbersDidChange;

// This class can be safely accessed and used from any thread.
@interface TSBlockingManager : NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)sharedManager;

- (void)addBlockedPhoneNumber:(NSString *)phoneNumber;

- (void)removeBlockedPhoneNumber:(NSString *)phoneNumber;

// When updating the block list from a sync message, we don't
// want to fire a sync message.
- (void)setBlockedPhoneNumbers:(NSArray<NSString *> *)blockedPhoneNumbers sendSyncMessage:(BOOL)sendSyncMessage;

- (NSArray<NSString *> *)blockedPhoneNumbers;

@end

NS_ASSUME_NONNULL_END
