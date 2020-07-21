@protocol LaetusWidgetProtocol <NSObject>

@required
// Setup your content view and set the frame. (Note this could change via setFrame on the content view).
-(void) setupWithFrame:(CGRect) frame;
// Return the contentview (Return NULL if not setup).
-(UIView*) contentView;
// Destroy the contentview. Make sure after this that the above function returns NULL.
-(void) destroyContentView;

@optional
// When a touch is detected, it will be passed to this function and provided via 'point'.
-(void) receiveTouchAtPoint:(CGPoint) point;
// Called when the keyplane changes. Can either be: @"Letters" or @"Numbers" or @"Emoji".
-(void) keyPlaneDidChange:(NSString*) keyPlaneName;
// Called when the keyplane changes. This is the raw value used by iOS internally, so may give more information.
-(void) rawKeyPlaneDidChange:(NSString*) keyPlaneName;
// Called when the language changes. Language is provided directly from the keyboard APIs and appears to always conform to the ISO language standard (e.g. en_GB). - More information here (https://en.wikipedia.org/wiki/Language_localisation), note that hyphens will be returned as underscores. 
-(void) updateCurrentLanguage:(NSString*) language;
// Called when the dictation view shows.
-(void) dictationViewWillShow;
// Called when the dication view hides.
-(void) dictationViewWillHide;
@end